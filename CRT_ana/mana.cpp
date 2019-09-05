//
//  mana.cpp
//  
//
//  Created by Glória on 05/09/2019.
//

#include <stdio.h>




void mana(){

  TChain * md = new TChain("midas_data");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001951_reprocessed.root");
  
  midas_data M(md);

  if (M.fChain == 0) return;

  Long64_t nentries = M.fChain->GetEntriesFast();

  Long64_t nbytes = 0, nb = 0;

  for (Long64_t jentry=0; jentry<nentries;jentry++) {
 
    Long64_t ientry = M.LoadTree(jentry);
 
    if (ientry < 0) break;
  
    nb = M.fChain->GetEntry(jentry);   nbytes += nb;
  // if (Cut(ientry) < 0) continue;

  }



}
