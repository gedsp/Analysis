///////////////////////////////////////////////////////////////////////////////
// Methods implementations of Fit.hh
//
// mailto:andrea.scarpelli@cern.ch
////////////////////////////////////////////////////////////////////////////////
#include "TH1.h"
#include "TF1.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TMath.h"
#include "TMath.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TGraph2D.h"

#include "Fit.hh"

using namespace std;

////////////////////////////////////////////////////////////////////////////////

fitLandau::fitLandau(){}

fitLandau::~fitLandau(){}

void fitLandau::setTitle(string title){ fTitle = title; }

void fitLandau::setName(string name){ fName = name; }

string fitLandau::getName(){return fName;}

string fitLandau::getTitle(){return fTitle;}

void fitLandau::initHist(string name, string title, int bin, double low, double high)
{
  //override
  fName=name;
  fTitle=title;

  for(int view=0; view<2; view++)
  {
    string histname = "h"+fTitle+"View"+to_string(view);
    string histtitle = fTitle;
    dqds[view] = new TH1D(histname.c_str(), histtitle.c_str(), bin, low, high);
  }
}

void fitLandau::fillTH1(int view, double fillin)
{
  dqds[view]->Fill(fillin);
}

TH1D* fitLandau::getHist(int view)
{
  return dqds[view];
}

TF1* fitLandau::getFunction(int view)
{
  return fitf[view];
}

double fitLandau::getFWHM(int view)
{
  //find FWHM from fitted mpv

  double x_max = fitf[view]->GetParameter(1);
  double bin_max = dqds[view]->FindBin(x_max);
  double n_max = dqds[view]->GetBinContent(bin_max);
  double th=0.5*n_max;
  double st=0;
  double end=0;

  for(int bin=0; bin<bin_max; bin++ ){
    if( th < dqds[view]->GetBinContent(bin) ){
      st=dqds[view]->GetBinCenter( bin-1 );
      break;
    }
  }
  for(int bin=bin_max; bin<dqds[view]->GetNbinsX(); bin++ ){
    if( th > dqds[view]->GetBinContent(bin) ){
      end=dqds[view]->GetBinCenter( bin+1 );
      break;
    }
  }

  return abs(end-st);
}

void fitLandau::doFit(int view, double lowlim, double uplim, bool norm)
{
  //Actual function implementing the fit described before

  Double_t fr[2];
  Double_t sv[4], pllo[4], plhi[4], fp[4], fpe[4];
  fr[0]=lowlim*dqds[view]->GetMean();
  fr[1]=uplim*dqds[view]->GetMean();

  cout << fr[0] << endl;
  cout << fr[1] << endl;

  if(norm)
  {
    dqds[view]->Scale(1./dqds[view]->Integral());
  }

  pllo[0]=0.1*dqds[view]->GetStdDev();
  pllo[1]=0.1*dqds[view]->GetMean();
  if(norm){ pllo[2]=0.1; }
  else{ pllo[2]=  pllo[2]=0.1*dqds[view]->Integral(); }
  pllo[3]=0.1*dqds[view]->GetStdDev();

  plhi[0]=10*dqds[view]->GetStdDev();
  plhi[1]=10*dqds[view]->GetMean();
  if(norm){ plhi[2]=10; }
  else{ plhi[2]=10*dqds[view]->Integral(); }
  plhi[3]=10*dqds[view]->GetStdDev();

  sv[0]=dqds[view]->GetStdDev();
  sv[1]=dqds[view]->GetMean();
  if(norm){ sv[2]=1; }
  else{ sv[2]=dqds[view]->Integral(); }
  sv[3]=dqds[view]->GetStdDev();

  Double_t chisqr;
  Int_t    ndf;
  fitf[view] = langaufit(dqds[view],fr,sv,pllo,plhi,fp,fpe,&chisqr,&ndf);
}

////////////////////////////////////////////////////////////////////////////////

makeGraphs::makeGraphs(int nPoints)
{
  //initialize graphs here
  gMPV[0] = new TGraphErrors(nPoints);
  gMPV[1] = new TGraphErrors(nPoints);

  gResolution[0] = new TGraphErrors(nPoints);
  gResolution[1] = new TGraphErrors(nPoints);

  gGain = new TGraphErrors(nPoints);

  gAsymmetry = new TGraphErrors(nPoints);

  gMPV[0]->SetName("gMPV0");
  gMPV[1]->SetName("gMPV1");

  gResolution[0]->SetName("gResolution0");
  gResolution[1]->SetName("gResolution1");

  gGain->SetName("gGain");

  gAsymmetry->SetName("gAsymmetry");
}

makeGraphs::~makeGraphs(){}

void makeGraphs::fillGraphs(int n, double binCenter, double binError)
{
  for(int view=0; view<2; view++)
  {
    gMPV[view]->SetPoint(n, binCenter, mpv[view]);
    gMPV[view]->SetPointError(n, binError, empv[view]);

    gResolution[view]->SetPoint(n, binCenter, resolution[view]);
    gResolution[view]->SetPointError(n, binError, eresolution[view]);
  }

  gGain->SetPoint(n, binCenter, gain);
  gGain->SetPointError(n, binError, egain);

  gAsymmetry->SetPoint(n, binCenter, asymmetry);
  gAsymmetry->SetPointError(n, binError, easymmetry);
}


void makeGraphs::setPointFit(int n, double binCenter, double binError, fitLandau* myHist)
{
    fitf[0] = myHist->getFunction(0);
    fitf[1] = myHist->getFunction(1);

    //take all the paramters and errors from fit
    for(int view=0; view<2; view++)
    {
      mpv[view]=fitf[view]->GetParameter(1);
      empv[view]=fitf[view]->GetParError(1);

      sigma[view]=fitf[view]->GetParameter(3);
      esigma[view]=fitf[view]->GetParError(3);

      width[view]=fitf[view]->GetParameter(2);
      ewidth[view]=fitf[view]->GetParError(2);;

      //resolution[view]=(myHist->getFWHM(view)/2)/mpv[view];
      resolution[view]=sigma[view]/mpv[view];
      cout << "---> " << myHist->getFWHM(view) << " " << resolution[view] << endl;
      eresolution[view] =0.;
    }

    //Error treatment as done here is not correct
    gain = (mpv[1]+mpv[0])/mip;
    double estat = sqrt(pow(empv[0]/mpv[0],2) + pow(empv[1]/mpv[1], 2));
    egain = sqrt( estat*estat + 0.02*0.02 + 0.09*0.09 + 0.04*0.04 )*gain;

    asymmetry= (mpv[1]-mpv[0])/(mpv[1]+mpv[0]);
    easymmetry=0.;

    //fill everything in the graph
    this->fillGraphs(n, binCenter, binError);
}

////////////////////////////////////////////////////////////////////////////////
