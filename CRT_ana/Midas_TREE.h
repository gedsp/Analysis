//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Sep  5 17:02:53 2019 by ROOT version 6.18/00
// from TTree Midas_TREE/Midas_TREE
// found on file: /eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001998_reprocessed.root
//////////////////////////////////////////////////////////

#ifndef Midas_TREE_h
#define Midas_TREE_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class Midas_TREE {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           TimeStamp;
   Int_t           TriggerTimeTag;
   Int_t           PCTimeTag[3];
   Int_t           event;
   Int_t           nchannels;
   Int_t           nsamples;
   Int_t           TimeSample;
   Int_t           channel_nsat[8];
   Float_t         channel_pedestal[8];
   Float_t         channel_charge[8];
   Int_t           crt_daq_match;
   Int_t           crt_reco;
   Int_t           crt_reco_sat;
   Int_t           crt_adc[4][32];
   Int_t           crt_SE_time[2];
   Int_t           crt_TS_time[2];
   Int_t           crt_nHitAllTot;
   Int_t           crt_nHitTot;
   Int_t           crt_nHitSatTot;
   Float_t         crt_charge;
   Float_t         crt_ToF;
   Int_t           crt_track_hits_id[4];
   Float_t         crt_track_param[5];
   Float_t         crt_track_param_p[5];
   Float_t         crt_track_param_m[5];
   Float_t         crt_track_door[3];
   Float_t         crt_track_door_p[3];
   Float_t         crt_track_door_m[3];
   Float_t         crt_track_wall[3];
   Float_t         crt_track_wall_p[3];
   Float_t         crt_track_wall_m[3];
   Float_t         crt_pmt_dist[5];
   Float_t         crt_pmt_dist_p[5];
   Float_t         crt_pmt_dist_m[5];
   Float_t         crt_closest_coord[5][3];
   Int_t           crt_isclosestpoint[5];
   Float_t         crt_drift_len[5];
   Float_t         crt_drift_len_p[5];
   Float_t         crt_drift_len_m[5];
   Int_t           crt_isFV;
   Float_t         crt_point_door_fv[3];
   Float_t         crt_point_door_fv_p[3];
   Float_t         crt_point_door_fv_m[3];
   Float_t         crt_point_wall_fv[3];
   Float_t         crt_point_wall_fv_p[3];
   Float_t         crt_point_wall_fv_m[3];
   Int_t           crt_isFC;
   Float_t         crt_point_door_fc[3];
   Float_t         crt_point_door_fc_p[3];
   Float_t         crt_point_door_fc_m[3];
   Float_t         crt_point_wall_fc[3];
   Float_t         crt_point_wall_fc_p[3];
   Float_t         crt_point_wall_fc_m[3];
   Short_t         adc_value_0[1000];
   Short_t         adc_value_1[1000];
   Short_t         adc_value_2[1000];
   Short_t         adc_value_3[1000];
   Short_t         adc_value_4[1000];

   // List of branches
   TBranch        *b_TimeStamp;   //!
   TBranch        *b_TriggerTimeTag;   //!
   TBranch        *b_PCTimeTag;   //!
   TBranch        *b_event;   //!
   TBranch        *b_nchannels;   //!
   TBranch        *b_nsamples;   //!
   TBranch        *b_TimeSample;   //!
   TBranch        *b_channel_nsat;   //!
   TBranch        *b_channel_pedestal;   //!
   TBranch        *b_channel_charge;   //!
   TBranch        *b_crt_daq_match;   //!
   TBranch        *b_crt_reco;   //!
   TBranch        *b_crt_reco_sat;   //!
   TBranch        *b_crt_adc;   //!
   TBranch        *b_crt_SE_time;   //!
   TBranch        *b_crt_TS_time;   //!
   TBranch        *b_crt_nHitAllTot;   //!
   TBranch        *b_crt_nHitTot;   //!
   TBranch        *b_crt_nHitSatTot;   //!
   TBranch        *b_crt_charge;   //!
   TBranch        *b_crt_ToF;   //!
   TBranch        *b_crt_track_hits_id;   //!
   TBranch        *b_crt_track_param;   //!
   TBranch        *b_crt_track_param_p;   //!
   TBranch        *b_crt_track_param_m;   //!
   TBranch        *b_crt_track_door;   //!
   TBranch        *b_crt_track_door_p;   //!
   TBranch        *b_crt_track_door_m;   //!
   TBranch        *b_crt_track_wall;   //!
   TBranch        *b_crt_track_wall_p;   //!
   TBranch        *b_crt_track_wall_m;   //!
   TBranch        *b_crt_pmt_dist;   //!
   TBranch        *b_crt_pmt_dist_p;   //!
   TBranch        *b_crt_pmt_dist_m;   //!
   TBranch        *b_crt_cloosest_coord;   //!
   TBranch        *b_crt_isclosestpoint;   //!
   TBranch        *b_crt_drift_len;   //!
   TBranch        *b_crt_drift_len_p;   //!
   TBranch        *b_crt_drift_len_m;   //!
   TBranch        *b_crt_isFV;   //!
   TBranch        *b_crt_point_door_fv;   //!
   TBranch        *b_crt_point_door_fv_p;   //!
   TBranch        *b_crt_point_door_fv_m;   //!
   TBranch        *b_crt_point_wall_fv;   //!
   TBranch        *b_crt_point_wall_fv_p;   //!
   TBranch        *b_crt_point_wall_fv_m;   //!
   TBranch        *b_crt_isFC;   //!
   TBranch        *b_crt_point_door_fc;   //!
   TBranch        *b_crt_point_door_fc_p;   //!
   TBranch        *b_crt_point_door_fc_m;   //!
   TBranch        *b_crt_point_wall_fc;   //!
   TBranch        *b_crt_point_wall_fc_p;   //!
   TBranch        *b_crt_point_wall_fc_m;   //!
   TBranch        *b_adc_value_0;   //!
   TBranch        *b_adc_value_1;   //!
   TBranch        *b_adc_value_2;   //!
   TBranch        *b_adc_value_3;   //!
   TBranch        *b_adc_value_4;   //!

   Midas_TREE(TTree *tree=0);
   virtual ~Midas_TREE();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Midas_TREE_cxx
Midas_TREE::Midas_TREE(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001998_reprocessed.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001998_reprocessed.root");
      }
      f->GetObject("Midas_TREE",tree);

   }
   Init(tree);
}

Midas_TREE::~Midas_TREE()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Midas_TREE::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Midas_TREE::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Midas_TREE::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("TimeStamp", &TimeStamp, &b_TimeStamp);
   fChain->SetBranchAddress("TriggerTimeTag", &TriggerTimeTag, &b_TriggerTimeTag);
   fChain->SetBranchAddress("PCTimeTag", PCTimeTag, &b_PCTimeTag);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("nchannels", &nchannels, &b_nchannels);
   fChain->SetBranchAddress("nsamples", &nsamples, &b_nsamples);
   fChain->SetBranchAddress("TimeSample", &TimeSample, &b_TimeSample);
   fChain->SetBranchAddress("channel_nsat", channel_nsat, &b_channel_nsat);
   fChain->SetBranchAddress("channel_pedestal", channel_pedestal, &b_channel_pedestal);
   fChain->SetBranchAddress("channel_charge", channel_charge, &b_channel_charge);
   fChain->SetBranchAddress("crt_daq_match", &crt_daq_match, &b_crt_daq_match);
   fChain->SetBranchAddress("crt_reco", &crt_reco, &b_crt_reco);
   fChain->SetBranchAddress("crt_reco_sat", &crt_reco_sat, &b_crt_reco_sat);
   fChain->SetBranchAddress("crt_adc", crt_adc, &b_crt_adc);
   fChain->SetBranchAddress("crt_SE_time", crt_SE_time, &b_crt_SE_time);
   fChain->SetBranchAddress("crt_TS_time", crt_TS_time, &b_crt_TS_time);
   fChain->SetBranchAddress("crt_nHitAllTot", &crt_nHitAllTot, &b_crt_nHitAllTot);
   fChain->SetBranchAddress("crt_nHitTot", &crt_nHitTot, &b_crt_nHitTot);
   fChain->SetBranchAddress("crt_nHitSatTot", &crt_nHitSatTot, &b_crt_nHitSatTot);
   fChain->SetBranchAddress("crt_charge", &crt_charge, &b_crt_charge);
   fChain->SetBranchAddress("crt_ToF", &crt_ToF, &b_crt_ToF);
   fChain->SetBranchAddress("crt_track_hits_id", crt_track_hits_id, &b_crt_track_hits_id);
   fChain->SetBranchAddress("crt_track_param", crt_track_param, &b_crt_track_param);
   fChain->SetBranchAddress("crt_track_param_p", crt_track_param_p, &b_crt_track_param_p);
   fChain->SetBranchAddress("crt_track_param_m", crt_track_param_m, &b_crt_track_param_m);
   fChain->SetBranchAddress("crt_track_door", crt_track_door, &b_crt_track_door);
   fChain->SetBranchAddress("crt_track_door_p", crt_track_door_p, &b_crt_track_door_p);
   fChain->SetBranchAddress("crt_track_door_m", crt_track_door_m, &b_crt_track_door_m);
   fChain->SetBranchAddress("crt_track_wall", crt_track_wall, &b_crt_track_wall);
   fChain->SetBranchAddress("crt_track_wall_p", crt_track_wall_p, &b_crt_track_wall_p);
   fChain->SetBranchAddress("crt_track_wall_m", crt_track_wall_m, &b_crt_track_wall_m);
   fChain->SetBranchAddress("crt_pmt_dist", crt_pmt_dist, &b_crt_pmt_dist);
   fChain->SetBranchAddress("crt_pmt_dist_p", crt_pmt_dist_p, &b_crt_pmt_dist_p);
   fChain->SetBranchAddress("crt_pmt_dist_m", crt_pmt_dist_m, &b_crt_pmt_dist_m);
   fChain->SetBranchAddress("crt_closest_coord", crt_closest_coord, &b_crt_cloosest_coord);
   fChain->SetBranchAddress("crt_isclosestpoint", crt_isclosestpoint, &b_crt_isclosestpoint);
   fChain->SetBranchAddress("crt_drift_len", crt_drift_len, &b_crt_drift_len);
   fChain->SetBranchAddress("crt_drift_len_p", crt_drift_len_p, &b_crt_drift_len_p);
   fChain->SetBranchAddress("crt_drift_len_m", crt_drift_len_m, &b_crt_drift_len_m);
   fChain->SetBranchAddress("crt_isFV", &crt_isFV, &b_crt_isFV);
   fChain->SetBranchAddress("crt_point_door_fv", crt_point_door_fv, &b_crt_point_door_fv);
   fChain->SetBranchAddress("crt_point_door_fv_p", crt_point_door_fv_p, &b_crt_point_door_fv_p);
   fChain->SetBranchAddress("crt_point_door_fv_m", crt_point_door_fv_m, &b_crt_point_door_fv_m);
   fChain->SetBranchAddress("crt_point_wall_fv", crt_point_wall_fv, &b_crt_point_wall_fv);
   fChain->SetBranchAddress("crt_point_wall_fv_p", crt_point_wall_fv_p, &b_crt_point_wall_fv_p);
   fChain->SetBranchAddress("crt_point_wall_fv_m", crt_point_wall_fv_m, &b_crt_point_wall_fv_m);
   fChain->SetBranchAddress("crt_isFC", &crt_isFC, &b_crt_isFC);
   fChain->SetBranchAddress("crt_point_door_fc", crt_point_door_fc, &b_crt_point_door_fc);
   fChain->SetBranchAddress("crt_point_door_fc_p", crt_point_door_fc_p, &b_crt_point_door_fc_p);
   fChain->SetBranchAddress("crt_point_door_fc_m", crt_point_door_fc_m, &b_crt_point_door_fc_m);
   fChain->SetBranchAddress("crt_point_wall_fc", crt_point_wall_fc, &b_crt_point_wall_fc);
   fChain->SetBranchAddress("crt_point_wall_fc_p", crt_point_wall_fc_p, &b_crt_point_wall_fc_p);
   fChain->SetBranchAddress("crt_point_wall_fc_m", crt_point_wall_fc_m, &b_crt_point_wall_fc_m);
//   fChain->SetBranchAddress("adc_value_0", adc_value_0, &b_adc_value_0);
//   fChain->SetBranchAddress("adc_value_1", adc_value_1, &b_adc_value_1);
//  fChain->SetBranchAddress("adc_value_2", adc_value_2, &b_adc_value_2);
//   fChain->SetBranchAddress("adc_value_3", adc_value_3, &b_adc_value_3);
//   fChain->SetBranchAddress("adc_value_4", adc_value_4, &b_adc_value_4);
   Notify();
}

Bool_t Midas_TREE::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Midas_TREE::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Midas_TREE::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Midas_TREE_cxx
