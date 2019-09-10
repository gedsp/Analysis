void plotVar(float min, float max, int nbins, TTree* dpd, string var){
  TCanvas *c1 = new TCanvas("c1"," ",1400,1000);
  TH1D* h = new TH1D("needs title","",nbins,min,max);
  dpd->Draw((var+">>h").c_str());
  delete h;

  c1->SaveAs(("plots/"+var+".pdf").c_str());
}

void plotCenas(){
//  TFile *file = TFile::Open("dpd_goodRunList_v4_1097_20190419.root","READ");
//  TTree *dpd = static_cast<TTree*>(file->Get("dpd"));

  
  TChain * md = new TChain("midas_data");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001951_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00002050_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00002177_reprocessed.root");
  
  
  
  float min = -500;
  float max = 1600;
  int nbins = 150;

  plotVar(min,max,nbins,dpd,"crt_daq_match");
  plotVar(min,max,nbins,dpd,"crt_reco");
  plotVar(min,max,nbins,dpd,"crt_reco_sat");
  plotVar(min,max,nbins,dpd,"crt_matchreco");
  plotVar(min,max,nbins,dpd,"crt_isFC");
  plotVar(min,max,nbins,dpd,"crt_isFV");
  plotVar(min,max,nbins,dpd,"crt_isclosestpoint");
  plotVar(min,max,nbins,dpd,"crt_ToF");
  plotVar(min,max,nbins,dpd,"crt_pmt_dist");
  plotVar(min,max,nbins,dpd,"crt_track_param");
  plotVar(min,max,nbins,dpd,"crt_drift_len");
  plotVar(min,max,nbins,dpd,"crt_closest_coord");
  plotVar(min,max,nbins,dpd,"crt_track_door");
  plotVar(min,max,nbins,dpd,"crt_track_wall");
  plotVar(min,max,nbins,dpd,"crt_point_door_fc");
  plotVar(min,max,nbins,dpd,"crt_point_wall_fc");
  plotVar(min,max,nbins,dpd,"crt_point_door_fv");
  plotVar(min,max,nbins,dpd,"crt_point_wall_fv");
  plotVar(min,max,nbins,dpd,"crt_fit_yx_m");
  plotVar(min,max,nbins,dpd,"crt_fit_yx_n");
  plotVar(min,max,nbins,dpd,"crt_fit_zx_m");
  plotVar(min,max,nbins,dpd,"crt_fit_zx_n");
}
