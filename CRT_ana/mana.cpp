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
  
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001399_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001670_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001671_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001672_reprocessed.root");

 // md->Add("/Users/gloria/wa105/WA105_mine/DATA/output00001399_reprocessed.root");
 // md->Add("/Users/gloria/wa105/WA105_mine/DATA/output00001672_reprocessed.root");

  
  
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
  
  
  //signal diff
  
  TH1F *  plano0DIF = new TH1F("plano0", "plano0", 100000,-3000,3000);
  TH1F * plano1DIF = new TH1F("plano1", "plano1", 100000,-3000,3000);
  TH1F * plano2DIF = new TH1F("plano2", "plano2", 10000,-3000,3000);
  TH1F * plano3DIF = new TH1F("plano3", "plano3", 10000,-3000,3000);
  plano0DIF->SetTitle("Plane 0; S1-S2; # events");
  plano1DIF->SetTitle("Plane 1; S1-S2; # events");
  plano2DIF->SetTitle("Plane 2; S1-S2; # events");
  plano3DIF->SetTitle("Plane 3; S1-S2; # events");
  
  // planes occupancy
  
  TH2F* plano01 = new TH2F("plano01", "plano01", 16,0.0,16,16,0.0,16);
  TH2F* plano23 = new TH2F("plano23", "plano23",16,0.0,16,16,0.0,16);
  plano01->SetTitle("Coincidencias Planos 0 e 1; Plano 0; Plano 1");
  plano23->SetTitle("Coincidencias Planos 2 e 3; Plano 2; Plano 3");


  // planes occupancy weighted
  TH2F* plano01W = new TH2F("plano01W", "plano01W", 16,0.0,16,16,0.0,16);
  TH2F* plano23W = new TH2F("plano23W", "plano23W",16,0.0,16,16,0.0,16);
  plano01W->SetTitle("Coincidencias Planos 0 e 1; Plano 0; Plano 1");
  plano23W->SetTitle("Coincidencias Planos 2 e 3; Plano 2; Plano 3");
  
  
  ofstream myfile;
  myfile.open ("DADOS.txt");
  int g=0;
  
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
 
   md->SetBranchAddress("crt_adc", crt_adc, &b_crt_adc);
  
    double MAX0=-9999999;
    double MAX1=-9999999;
    double MAX2=-9999999;
    double MAX3=-9999999;
    
    int zeros;
    int barID[4];
 //   if (ientry < 0) break;
  
    nb = md->GetEntry(jentry);   nbytes += nb;
    
    
    // plane signal
    double PlaneSignalTot[4][16];
    double PlaneSignalDif[4][16];
    double PlaneMax[4],PlaneMin[4];
    
    for ( int k =0; k<4; k++) {   // loop on planes
    
      for (int j=0; j<32; j++) { //loop on SiPM
        
       
    //    plano[k]->Fill(crt_adc[k][j]);
      
        
        /*******************************************************/
        
        // computing scint bar signal
        
        if (j % 2 == 0){
          
           int b=j/2;
           PlaneSignalTot[k][b]=crt_adc[k][j]+crt_adc[k][j+1];
           PlaneSignalDif[k][b]=crt_adc[k][j]-crt_adc[k][j+1];
        
          // Studying signal diff
          if (abs(PlaneSignalDif[k][b])<0.000000000000000001){
            
            zeros++;
            
          }
          else{
          plano0DIF->Fill(PlaneSignalDif[0][b]);
          plano1DIF->Fill(PlaneSignalDif[1][b]);
          plano2DIF->Fill(PlaneSignalDif[2][b]);
          plano3DIF->Fill(PlaneSignalDif[3][b]);
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
      plano01W->Fill(barID[0],barID[1],PlaneMax[0]+PlaneMax[1]);
      plano23W->Fill(barID[2],barID[3],PlaneMax[2]+PlaneMax[3]);
    }
    
    g=0;
   
    
   
  }
  
  

 
  TCanvas * c2 = new TCanvas();

  gStyle->SetOptStat(0);  
c2->Divide(2,2);
  c2->cd(1);
  gPad->SetLogy();
  plano0DIF->Draw("hist");
  c2->cd(2);
  gPad->SetLogy();
  plano1DIF->Draw("hist");
  c2->cd(3);
  gPad->SetLogy();
  plano2DIF->Draw("hist");
  c2->cd(4);
  gPad->SetLogy();
  plano3DIF->Draw("hist");
    
  c2->Print("Crt_adc_diff_w_o_0_log.pdf");
 
 
  TCanvas * c3 = new TCanvas();

  gStyle->SetOptStat(0);  
c3->Divide(1,2);
  c3->cd(1);
  plano01->Draw("COLZ");
  c3->cd(2);
  plano23->Draw("COLZ");

  c3->Print("Crt_coincidencias_barras.pdf");
  
  TCanvas * c31 = new TCanvas();

  gStyle->SetOptStat(0); 
 c31->Divide(1,2);
  c31->cd(1);
  plano01W->Draw("COLZ");
  c31->cd(2);
  plano23W->Draw("COLZ");
  
  c3->Print("Crt_coincidencias_barras_weighted.pdf");
  
  

  //md->Draw("crt_adc");







}
