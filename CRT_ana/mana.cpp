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

  Long64_t nentries = M.fChain->GetEntriesFast();

  Long64_t nbytes = 0, nb = 0;

  for (Long64_t jentry=0; jentry<nentries;jentry++) {
 
    Long64_t ientry = M.LoadTree(jentry);
 
    if (ientry < 0) break;
  
    nb = M.fChain->GetEntry(jentry);   nbytes += nb;
  // if (Cut(ientry) < 0) continue;

    
    
  }
  
TCanvas * c =new TCanvas();
c->Divide(2,2);
c->cd(1);
  md->Draw("crt_charge");
c->cd(2);
md->Draw("crt_nHitAllTot");
c->cd(3);
md->Draw("crt_nHitTot");
c->cd(4);
md->Draw("crt_nHitSatTot");

  c->Print("Crt_CH_Histtot.pdf");
  
 // for (int i=0; i<4; i++) {
    TCanvas * c2 = new TCanvas();
   // c2->Divide(8,4);
 //   TH1F * h
 // }

  md->Draw("crt_adc");







}
