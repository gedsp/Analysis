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
//md->Add("/Users/gloria/wa105/WA105_mine/DATA/output00001672_reprocessed.root");

  
  
  if (md == 0) return;
  
  
  
  Long64_t nentries = md->GetEntries();

    Int_t           crt_adc[4][32];
     TBranch        *b_crt_adc;
  
  Long64_t nbytes = 0, nb = 0;

  vector<TH1F*> V_plano;
  
  TH1F * p0 = new TH1F("plano0", "plano0", 10000,0.1,8500);
  TH1F * p1 = new TH1F("plano1", "plano1",  10000,0.1,8500);
  TH1F * p2 = new TH1F("plano2", "plano2", 10000,0.1,8500);
  TH1F * p3 = new TH1F("plano3", "plano3",  10000,0.1,8500);
  p0->SetTitle("Plane 0; S1+S2; # events");
  p1->SetTitle("Plane 1; S1+S2; # events");
  p2->SetTitle("Plane 2; S1+S2; # events");
  p3->SetTitle("Plane 3; S1+S2; # events");
  
  
  V_plano.push_back(p0);
  V_plano.push_back(p1);
  V_plano.push_back(p2);
  V_plano.push_back(p3);
  
  
  // cut signal
  
 vector < vector<TH1F*> > V_plano_cut;
   
  
  
  TH1F * p0_cut;
  
  for (int i=0; i<13; i++) {
      vector<TH1F*>  plano_cut;
   
    int cut = (i+1)*500;
    
    for (int j =0; j<4; j++) {
      
    
      
      p0_cut = new TH1F(Form("plano_%d_cut_%d",j,i), "plano0", 10000,0.1,8500);
      p0_cut->SetTitle(Form("Plane %d Cut %d; S1+S2; # events",j,cut));
      
      plano_cut.push_back(p0_cut);

    }


    V_plano_cut.push_back(plano_cut);

  }
  

  // tprofile
  vector<TProfile*>  plano_cut_hprof;
  TProfile* hprof;
  for (int j =0; j<4; j++) {
       
       
      hprof =new TProfile(Form("plano_%d",j), "plano0", 3000,0.1,3000,0.,16.);
      hprof->SetTitle(Form("Plane %d; Cut Value; # active bars",j));
       
       plano_cut_hprof.push_back(hprof);

     }
  
  
  //signal diff
  
  vector<TH1F*> V_hist;
  
  TH1F * p0dif = new TH1F("plano0d", "plano0d", 100000,-1000,1000);
  TH1F * p1dif = new TH1F("plano1d", "plano1d", 100000,-1000,1000);
  TH1F * p2dif = new TH1F("plano2d", "plano2d", 10000,-1000,1000);
  TH1F * p3dif = new TH1F("plano3d", "plano3d", 10000,-1000,1000);
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
  TH2F* plano0W = new TH2F("plano01W", "plano01W", 16,0.0,16,20,0.0,8000);
  TH2F* plano2W = new TH2F("plano23W", "plano23W",16,0.0,16,20,0.0,8000);
  plano0W->SetTitle("Plane 0; Plano 0; Signal Max");
  plano2W->SetTitle("Plane 2; Plano 2; Signal Max");
  TH2F* plano1W = new TH2F("plano1W", "plano1W", 16,0.0,16,20,0.0,8000);
  TH2F* plano3W = new TH2F("plano3W", "plano3W",16,0.0,16,20,0.0,8000);
  plano1W->SetTitle("Plane 1; Plano 1; Signal Max");
  plano3W->SetTitle("Plane 3; Plano 3; Signal Max");
  
  // Si+s2 max
  
  vector<TH1F*> V_plano_Max;
  
  TH1F * p0_Max = new TH1F("plano0_Max", "plano0_Max", 10000,0.1,8500);
  TH1F * p1_Max = new TH1F("plano1_Max", "plano1_Max",  10000,0.1,8500);
  TH1F * p2_Max = new TH1F("plano2_Max", "plano2_Max", 10000,0.1,8500);
  TH1F * p3_Max = new TH1F("plano3_Max", "plano3_Max",  10000,0.1,8500);
  p0_Max->SetTitle("Plane 0; SB Max; # events");
  p1_Max->SetTitle("Plane 1; SB Max; # events");
  p2_Max->SetTitle("Plane 2; SB Max; # events");
  p3_Max->SetTitle("Plane 3; SB Max; # events");
  
  
  V_plano_Max.push_back(p0_Max);
  V_plano_Max.push_back(p1_Max);
  V_plano_Max.push_back(p2_Max);
  V_plano_Max.push_back(p3_Max);
  
  
  ofstream cut;
  cut.open ("DADOS_cut.txt");
  
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
            
            
            V_plano[k]->Fill(PlaneSignalTot[k][b]);
            
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
     
      V_plano_Max[k]->Fill(PlaneMax[k]);
      
      if (PlaneMax[k]>500 /*VALUE OF THRESHOLD */){
        
        g=g+1;
        myfile << "\n____________Entry____________" << jentry << "___________________going to fill the histo_________________\n";
        myfile << "plane id " << k << "\tbarID " << barID[k] << "\t MAX " << PlaneMax[k] << endl;

     
      }

    }
  
    myfile << "\n________________Entry___________" << jentry << "____________________________________________\n";
    myfile << "plane id 0" << "\tbarID " << barID[0] << "\t MAX " << PlaneMax[0] << endl;
    myfile << "plane id 1" << "\tbarID " << barID[1] << "\t MAX " << PlaneMax[1] << endl;
    myfile << "plane id 2" << "\tbarID " << barID[2] << "\t MAX " << PlaneMax[2] << endl;
    myfile << "plane id 3" << "\tbarID " << barID[3] << "\t MAX " << PlaneMax[3] << endl;
    
    if (g==3) {
      plano01->Fill(barID[0],barID[1]);
      plano23->Fill(barID[2],barID[3]);
     
      plano0W->Fill(barID[0], PlaneMax[0]);
      plano2W->Fill(barID[2] , PlaneMax[1]);
      plano1W->Fill(barID[1], PlaneMax[2]);
      plano3W->Fill(barID[3], PlaneMax[3]);
      
    }
    
    g=0;
   
   
   int l=0;
   
  //min cut
     int m=0;
    for (int min=50; min<3000; min=min+50) {
     
      for (int k=0; k<4; k++) {
        
        vector<double> CutSignal;
        
         for (int b=0; b<16; b++) {
        

           if ( PlaneSignalTot[k][b]>min) {
             
             //CutSignal.push_back(PlaneSignalTot[k][b]);

      //       cut << "envent ID " << jentry << "\tplane " << k << "\tbar " << b << "\tmin cut threshold " << min << " \tPlaneSignalTot value " << PlaneSignalTot[k][b] << endl;
             //V_plano_cut[m][k]->Fill(PlaneSignalTot[k][b]);
           
             l++;
           }
           
          
         } // loop b
      
       
       plano_cut_hprof[k]->Fill(min,l);
       
        l=0;
        
      } // loop on planes
    
     
      
      
      cut << "--------------    ----------------" << endl;
      m++;
   
    } // loop on min value
  
    //cout << "size " << V_plano_cut.size() << " m " << m << "size[]" << V_plano_cut[0].size() << endl;
  
    cut << "--------------------------------------------------------------------------------------------------" << endl;
  
  } //loop on entries
  
  
   myfile.close();
  cut.close();
  
  
/*
  
  for (int i =0; i<13; i++) {
     
    TCanvas * c = new TCanvas(Form("%d cut value ", i));
         c->Divide(2,2);
         c->cd(1);
         V_plano_cut[i][0]->Draw("hist");
         c->cd(2);
         V_plano_cut[i][1]->Draw("hist");
         c->cd(3);
         V_plano_cut[i][2]->Draw("hist");
         c->cd(4);
         V_plano_cut[i][3]->Draw("hist");

         c->Print(Form("(%d+1)500_cut_value_event.pdf", i));
    
  }
  
  
*/
  
    TCanvas * c1 = new TCanvas();
gStyle->SetGridStyle(3);
  //  gStyle->SetOptStat(0);
  c1->Divide(2,2);
    c1->cd(1);
  gPad->SetGrid();
  plano_cut_hprof[0]->SetLineColor(2);
   plano_cut_hprof[0]->SetLineWidth(2);
  plano_cut_hprof[0]->Draw("E");
    c1->cd(2);
    gPad->SetGrid();
  plano_cut_hprof[1]->SetLineColor(2);
     plano_cut_hprof[1]->SetLineWidth(2);
  plano_cut_hprof[1]->Draw("EP");
  c1->cd(3);
    gPad->SetGrid();
   plano_cut_hprof[2]->SetLineColor(2);
     plano_cut_hprof[2]->SetLineWidth(2);
  plano_cut_hprof[2]->Draw("E");
    c1->cd(4);
    gPad->SetGrid();
   plano_cut_hprof[3]->SetLineColor(2);
     plano_cut_hprof[3]->SetLineWidth(2);
  plano_cut_hprof[3]->Draw("E");

    c1->Print("tprofile.pdf");
  
  
  
  /*
  

 
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
 */
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
  plano0W->Draw("COLZ");
  c31->cd(2);
  plano1W->Draw("COLZ");
  c31->cd(3);
  plano2W->Draw("COLZ");
  c31->cd(4);
  plano3W->Draw("COLZ");
  c3->Print("Crt_barras_weighted.pdf");
  
 /* double int0 = plano0W->Integral(0,16);
  double int1 = plano1W->Integral(0,16);
  double int2 = plano2W->Integral(0,16);
  double int3 = plano3W->Integral(0,16);
  
  cout << "----\tIntegrals \n ";
  cout << "Plane 0 " << int0  << "\nPlane 1 " << int1 << "\nPlane 2 " << int2 << "\nPlane 3 " << int3 << endl;

  //md->Draw("crt_adc");

*/


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
  c4->Print("Crt_adc_readout_with_overflow.pdf");

 
 

  /**************************************************/
 /*
   TCanvas * c5 = new TCanvas();
   
   gStyle->SetOptStat(0);
   c5->Divide(2,2);
   c5->cd(1);
   V_plano_Max[0]->Draw("hist");
   c5->cd(2);
   V_plano_Max[1]->Draw("hist");
   c5->cd(3);
   V_plano_Max[2]->Draw("hist");
   c5->cd(4);
   V_plano_Max[3]->Draw("hist");
   c5->Print("Crt_adc_readout_Max.pdf");

*/

}
