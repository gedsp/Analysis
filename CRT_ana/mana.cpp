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
//  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00002050_reprocessed.root");
 // md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00002177_reprocessed.root");
  
  
  midas_data M(md);

//  hnseg = new TH1F("hnseg","Number of segments for selected tracks",4096,0,8192);
  if (M.fChain == 0) return;
  M.Init(M.fChain);
  Long64_t nentries = M.fChain->GetEntriesFast();

  
  
  Long64_t nbytes = 0, nb = 0;
  TH1F* plano0 = new TH1F("plano0", "plano0", 10000,1,4100);
  TH1F* plano1 = new TH1F("plano1", "plano1", 10000,1,4100);
  TH1F* plano2 = new TH1F("plano2", "plano2", 10000,1,4100);
  TH1F* plano3 = new TH1F("plano3", "plano3", 10000,1,4100);
  
  
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
 
    Long64_t ientry = M.LoadTree(jentry);
//cout << "jentry" << jentry << endl; 
    if (ientry < 0) break;
  
    nb = M.fChain->GetEntry(jentry);   nbytes += nb;
  // if (Cut(ientry) < 0) continue;
   // hist->Fill(crt_adc);

    
      for (int j=0; j<32; j++) {
        plano0->Fill(crt_adc[0][j]);
        plano1->Fill(crt_adc[1][j]);
        plano2->Fill(crt_adc[2][j]);
        plano3->Fill(crt_adc[3][j]);
      }
    
    
  }
  
 
 
  TCanvas * c2 = new TCanvas();
  c2->Divide(2,2);
    
  plano0->Draw("hist");
  plano1->Draw("hist");
  plano2->Draw("hist");
  plano3->Draw("hist");
    
  c2->Print("Crt_adc_.pdf");
  

  //md->Draw("crt_adc");







}
