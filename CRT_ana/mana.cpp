//
//  mana.cpp
//  
//
//  Created by Glória on 05/09/2019.
//

#include <stdio.h>
#include <algorithm>

void mana(){

  TChain * md = new TChain("midas_data");
 // md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/*_reprocessed.root");
  
 //// md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001399_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001670_reprocessed.root");
 md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001671_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001672_reprocessed.root");

//  md->Add("/Users/gloria/wa105/WA105_mine/DATA/output00001399_reprocessed.root");
  md->Add("/Users/gloria/wa105/WA105_mine/DATA/output00001672_reprocessed.root");

  
  
  if (md == 0) return;
  
  
  
  Long64_t nentries = md->GetEntries();

    Int_t           crt_adc[4][32];
     TBranch        *b_crt_adc;
  
  Long64_t nbytes = 0, nb = 0;
  
 /* TH1F * plano[4];
  plano[0] = new TH1F("plano0", "plano0", 10000,0.1,4500);
  plano[1] = new TH1F("plano1", "plano1", 10000,0.1,4500);
  plano[2] = new TH1F("plano2", "plano2", 10000,0.1,4500);
  plano[3] = new TH1F("plano3", "plano3", 10000,0.1,4500);*/
  
  vector<TH1F*> V_plano;
  
  TH1F * p0 = new TH1F("plano0", "plano0", 10000,0.1,4500);
  TH1F * p1 = new TH1F("plano1", "plano1",  10000,0.1,4500);
  TH1F * p2 = new TH1F("plano2", "plano2", 10000,0.1,4500);
  TH1F * p3 = new TH1F("plano3", "plano3",  10000,0.1,4500);
  p0->SetTitle("Plane 0; ADC Signal; # events");
  p1->SetTitle("Plane 1; ADC Signal; # events");
  p2->SetTitle("Plane 2; ADC Signal; # events");
  p3->SetTitle("Plane 3; ADC Signal; # events");
  
  
  V_plano.push_back(p0);
  V_plano.push_back(p1);
  V_plano.push_back(p2);
  V_plano.push_back(p3);
  
  
  //signal diff
  
  vector<TH1F*> V_hist;
  
  TH1F * p0dif = new TH1F("plano0", "plano0", 100000,-1000,1000);
  TH1F * p1dif = new TH1F("plano1", "plano1", 100000,-1000,1000);
  TH1F * p2dif = new TH1F("plano2", "plano2", 10000,-1000,1000);
  TH1F * p3dif = new TH1F("plano3", "plano3", 10000,-1000,1000);
  p0dif->SetTitle("Plane 0; S1-S2; # events");
  p1dif->SetTitle("Plane 1; S1-S2; # events");
  p2dif->SetTitle("Plane 2; S1-S2; # events");
  p3dif->SetTitle("Plane 3; S1-S2; # events");
  
  
  V_hist.push_back(p0dif);
  V_hist.push_back(p1dif);
  V_hist.push_back(p2dif);
  V_hist.push_back(p3dif);
  
  // planes occupancy
  
  TH2F* plano01 = new TH2F("plano01", "plano01", 16,0.0,16,16,0.0,16);
  TH2F* plano23 = new TH2F("plano23", "plano23",16,0.0,16,16,0.0,16);
  plano01->SetTitle("Coincidencias Planos 0 e 1; Plano 0; Plano 1");
  plano23->SetTitle("Coincidencias Planos 2 e 3; Plano 2; Plano 3");


  // planes occupancy weighted
  TH1F* plano0W = new TH1F("plano01W", "plano01W", 16,0.0,16);
  TH1F* plano2W = new TH1F("plano23W", "plano23W",16,0.0,16);
  plano0W->SetTitle("Plane 0; Plano 0; Signal Max");
  plano2W->SetTitle("Plane 2; Plano 2; Signal Max");
  TH1F* plano1W = new TH1F("plano1W", "plano1W", 16,0.0,16);
  TH1F* plano3W = new TH1F("plano3W", "plano3W",16,0.0,16);
  plano1W->SetTitle("Plane 1; Plano 1; Signal Max");
  plano3W->SetTitle("Plane 3; Plano 3; Signal Max");
  
  ofstream myfile;
  myfile.open ("DADOS.txt");
  int g=0;
  
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
 
   md->SetBranchAddress("crt_adc", crt_adc, &b_crt_adc);
  
    
    int zeros,overflow;
    int barID[4];
  
    nb = md->GetEntry(jentry);   nbytes += nb;
    
    
    // plane signal
    double PlaneSignalTot[4][16];
    double PlaneSignalDif[4][16];
    double PlaneMax[4],PlaneMin[4];
    
    for ( int k =0; k<4; k++) {   // loop on planes
    
      for (int j=0; j<32; j++) { //loop on SiPM
        
       
        V_plano[k]->Fill(crt_adc[k][j]);
      
        
        /*******************************************************/
        
        // computing scint bar signal
        
        if (j % 2 == 0){
          
           int b=j/2;
          
          if(crt_adc[k][j]==4089||crt_adc[k][j+1]==4089){
            
            overflow++;
          //  cout << overflow << endl;
            
          }
          else {
            PlaneSignalTot[k][b]=crt_adc[k][j]+crt_adc[k][j+1];
           PlaneSignalDif[k][b]=crt_adc[k][j]-crt_adc[k][j+1];
          }
         
          // Studying signal diff
          if (abs(crt_adc[k][j])<0.1||abs(crt_adc[k][j+1])<0.1||PlaneSignalDif[k][b]==0){
            
            zeros++;
            
          }
          else{
            
            V_hist[k]->Fill(PlaneSignalDif[k][b]);
            
          }

        }
    
        
        
        
      }
      
     // cout << "PlaneSignalDif " << k << " zeros = " << zeros << endl;
         // Get Max/Min signal per plane
      
        double * pmin  =  min_element(begin(PlaneSignalTot[k]), end(PlaneSignalTot[k]));

        double * pmax =  max_element(begin(PlaneSignalTot[k]), end(PlaneSignalTot[k]));
        
        PlaneMax[k]=*pmax;
        PlaneMin[k]=*pmin;
        
        
        barID[k]= distance(PlaneSignalTot[k], pmax);
     
      
      if (PlaneMax[k]>0.01){
        
        g=1;
        myfile << "\n____________Entry____________" << jentry << "___________________going to fill the histo_________________\n";
        myfile << "plane id " << k << "\tbarID " << barID[k] << "\t MAX " << PlaneMax[k] << endl;

     
      }

    }
  
    myfile << "\n________________Entry___________" << jentry << "____________________________________________\n";
    myfile << "plane id 0" << "\tbarID " << barID[0] << "\t MAX " << PlaneMax[0] << endl;
    myfile << "plane id 1" << "\tbarID " << barID[1] << "\t MAX " << PlaneMax[1] << endl;
    myfile << "plane id 2" << "\tbarID " << barID[2] << "\t MAX " << PlaneMax[2] << endl;
    myfile << "plane id 3" << "\tbarID " << barID[3] << "\t MAX " << PlaneMax[3] << endl;
    
    if (g==1) {
      plano01->Fill(barID[0],barID[1]);
      plano23->Fill(barID[2],barID[3]);
      if (jentry==1){
      plano0W->Fill(barID[0], PlaneMax[0]);
      plano2W->Fill(barID[2] , PlaneMax[1]);
      plano1W->Fill(barID[1], PlaneMax[2]);
        plano3W->Fill(barID[3], PlaneMax[3]);
        
      }
    }
    
    g=0;
   
    
   
  }
  
  

 
  TCanvas * c2 = new TCanvas();
  gStyle->SetOptStat(111111);
  c2->Divide(2,2);
  
  
  c2->cd(1);
//  gPad->SetLogy();
  TF1 *g1 = new TF1("m1","gaus",-10,20);
  TF1 * g2 = new TF1("m2","gaus",-400,400);
  
  g1->SetLineColor(kRed+1);
  g2->SetLineColor(kRed+3);
  g1->SetLineWidth(2);
  g2->SetLineWidth(2);
 
  V_hist[0]->Fit(g1,"R");
  V_hist[0]->Fit(g2,"R+");
// V_hist[0]->Draw("hist");
 
  
  c2->cd(2);
 
  TF1 *g3 = new TF1("m1","gaus",-10,20);
  TF1 * g4 = new TF1("m2","gaus",-400,400);
  
  g3->SetLineColor(kRed+1);
  g4->SetLineColor(kRed+3);
  g3->SetLineWidth(2);
  g4->SetLineWidth(2);
  
  V_hist[1]->Fit(g3,"R");
  V_hist[1]->Fit(g4,"R+");
  
  c2->cd(3);
 
  
  TF1 *g5 = new TF1("m1","gaus",-10,20);
  TF1 * g6 = new TF1("m2","gaus",-400,400);
  
  g5->SetLineColor(kRed+1);
  g6->SetLineColor(kRed+3);
  g5->SetLineWidth(2);
  g6->SetLineWidth(2);
  
  V_hist[2]->Fit(g5,"R");
  V_hist[2]->Fit(g6,"R+");
  
  
  c2->cd(4);
 
  
  TF1 *g7 = new TF1("m1","gaus",-10,20);
  TF1 * g8 = new TF1("m2","gaus",-400,400);
  
  g7->SetLineColor(kRed+1);
  g8->SetLineColor(kRed+3);
  g7->SetLineWidth(2);
  g8->SetLineWidth(2);
  
  V_hist[1]->Fit(g7,"R");
  V_hist[1]->Fit(g8,"R+");
    
  c2->Print("Crt_adc_diff.pdf");
 
 /**************************************************/
  
  TCanvas * c3 = new TCanvas();

  gStyle->SetOptStat(0);  
c3->Divide(1,2);
  c3->cd(1);
  plano01->Draw("COLZ");
  c3->cd(2);
  plano23->Draw("COLZ");

  c3->Print("Crt_coincidencias_barras.pdf");


  /**************************************************/

  TCanvas * c31 = new TCanvas();

  gStyle->SetOptStat(0);
 c31->Divide(2,2);
  c31->cd(1);
  plano0W->Draw("hist");
  c31->cd(2);
  plano1W->Draw("hist");
  c31->cd(3);
  plano2W->Draw("hist");
  c31->cd(4);
  plano3W->Draw("hist");
  c3->Print("Crt_barras_weighted.pdf");
  
  double int0 = plano0W->Integral(0,16);
  double int1 = plano1W->Integral(0,16);
  double int2 = plano2W->Integral(0,16);
  double int3 = plano3W->Integral(0,16);
  
  cout << "----\tIntegrals \n ";
  cout << "Plane 0 " << int0  << "\nPlane 1 " << int1 << "\nPlane 2 " << int2 << "\nPlane 3 " << int3 << endl;

  //md->Draw("crt_adc");
  



  /**************************************************/
  
  TCanvas * c4 = new TCanvas();
  
  gStyle->SetOptStat(0);
  c4->Divide(2,2);
  c4->cd(1);
  V_plano[0]->Draw("hist");
  c4->cd(2);
  V_plano[1]->Draw("hist");
  c4->cd(3);
  V_plano[2]->Draw("hist");
  c4->cd(4);
  V_plano[3]->Draw("hist");
  c4->Print("Crt_adc_readout.pdf");

  //md->Draw("crt_adc");
  
  




}
