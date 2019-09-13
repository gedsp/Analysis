//
//  mana.cpp
//  
//
//  Created by Glória on 05/09/2019.
//

#include <stdio.h>




void mana(){

  TChain * md = new TChain("midas_data");
 // md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/*_reprocessed.root");
  
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001399_reprocessed.root");
 // md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001670_reprocessed.root");
  //md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001671_reprocessed.root");
  //md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001672_reprocessed.root");

  
  

//  hnseg = new TH1F("hnseg","Number of segments for selected tracks",4096,0,8192);
  if (md == 0) return;
  
  
  
  Long64_t nentries = md->GetEntries();

    Int_t           crt_adc[4][32];
     TBranch        *b_crt_adc;
  
  Long64_t nbytes = 0, nb = 0;
  
  TH1F* plano0 = new TH1F("plano0", "plano0", 10000,0.1,4500);
  TH1F* plano1 = new TH1F("plano1", "plano1", 10000,0.1,4500);
  TH1F* plano2 = new TH1F("plano2", "plano2", 10000,0.1,4500);
  TH1F* plano3 = new TH1F("plano3", "plano3", 10000,0.1,4500);
  
  TH2F* plano01 = new TH2F("plano01", "plano01",10000,0.1,4500);
  TH2F* plano23 = new TH2F("plano23", "plano23",10000,0.1,4500);
  plano01->SetTitle("Coincidencias Planos 0 e 1; Plano 0; Plano 1");
  plano23->SetTitle("Coincidencias Planos 2 e 3; Plano 2; Plano 3");

  
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
 
   md->SetBranchAddress("crt_adc", crt_adc, &b_crt_adc);

    
 //   if (ientry < 0) break;
  
    nb = md->GetEntry(jentry);   nbytes += nb;

    
      for (int j=0; j<32; j++) {
        
       
        plano0->Fill(crt_adc[0][j]);
        plano1->Fill(crt_adc[1][j]);
        plano2->Fill(crt_adc[2][j]);
        plano3->Fill(crt_adc[3][j]);
        
        
        if (crt_adc[0][j]>4098){
          
          cout << "value " << crt_adc[0][j] << endl;
        }
          
        
        /*******************************************************/
        
        if (j % 2 == 0){
          
          double p0 =crt_adc[0][j]+crt_adc[0][j+1];
          double p1 =crt_adc[1][j]+crt_adc[1][j+1];
          double p2 =crt_adc[2][j]+crt_adc[2][j+1];
          double p3 =crt_adc[3][j]+crt_adc[3][j+1];

          plano01->Fill(p0,p1);
          plano23->Fill(p2,p3);
        }
        
      }
    
    
  }
  
 
 
  TCanvas * c2 = new TCanvas();
  c2->Divide(2,2);
  c2->cd(1);
  plano0->Draw("hist");
  c2->cd(2);
  plano1->Draw("hist");
  c2->cd(3);
  plano2->Draw("hist");
  c2->cd(4);
  plano3->Draw("hist");
    
  c2->Print("Crt_adc_.pdf");
  
  TCanvas * c3 = new TCanvas();
  c2->Divide(1,2);
  c2->cd(1);
  plano01->Draw("COLZ");
  c2->cd(2);
  plano23->Draw("COLZ");

  c3->Print("Crt_adc_coincidencias.pdf");
  
  

  //md->Draw("crt_adc");







}
