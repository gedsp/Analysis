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
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001670_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001671_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001672_reprocessed.root");

  
  

//  hnseg = new TH1F("hnseg","Number of segments for selected tracks",4096,0,8192);
  if (md == 0) return;
  
  
  
  Long64_t nentries = md->GetEntries();

    Int_t           crt_adc[4][32];
     TBranch        *b_crt_adc;
  
  Long64_t nbytes = 0, nb = 0;
  
  TH1F* plano0 = new TH1F("plano0", "plano0", 10000,1,4500);
  TH1F* plano1 = new TH1F("plano1", "plano1", 10000,1,4500);
  TH1F* plano2 = new TH1F("plano2", "plano2", 10000,1,4500);
  TH1F* plano3 = new TH1F("plano3", "plano3", 10000,1,4500);
  
  
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
 
   md->SetBranchAddress("crt_adc", crt_adc, &b_crt_adc);

    
 //   if (ientry < 0) break;
  
    nb = md->GetEntry(jentry);   nbytes += nb;

    
      for (int j=0; j<32; j++) {
        
        
        plano0->Fill(crt_adc[0][j]);
        plano1->Fill(crt_adc[1][j]);
        plano2->Fill(crt_adc[2][j]);
        plano3->Fill(crt_adc[3][j]);
        
        
        if (crt_adc[0][j]>3500){
          
          cout << "value " << crt_adc[0][j] << endl;
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
  

  //md->Draw("crt_adc");







}
