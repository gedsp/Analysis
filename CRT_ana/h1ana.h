//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Sep  5 17:02:30 2019 by ROOT version 6.18/00
// from TTree midas_data/midas_data
// found on file: /eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001998_reprocessed.root
//////////////////////////////////////////////////////////

#ifndef h1ana_h
#define h1ana_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector


class h1ana : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Int_t> TimeStamp = {fReader, "TimeStamp"};
   TTreeReaderValue<Int_t> TriggerTimeTag = {fReader, "TriggerTimeTag"};
   TTreeReaderArray<Int_t> PCTimeTag = {fReader, "PCTimeTag"};
   TTreeReaderValue<Int_t> event = {fReader, "event"};
   TTreeReaderValue<Int_t> nchannels = {fReader, "nchannels"};
   TTreeReaderValue<Int_t> nsamples = {fReader, "nsamples"};
   TTreeReaderValue<Int_t> TimeSample = {fReader, "TimeSample"};
   TTreeReaderArray<Int_t> channel_nsat = {fReader, "channel_nsat"};
   TTreeReaderArray<Float_t> channel_pedestal = {fReader, "channel_pedestal"};
   TTreeReaderArray<Float_t> channel_charge = {fReader, "channel_charge"};
   TTreeReaderValue<Int_t> crt_daq_match = {fReader, "crt_daq_match"};
   TTreeReaderValue<Int_t> crt_reco = {fReader, "crt_reco"};
   TTreeReaderValue<Int_t> crt_reco_sat = {fReader, "crt_reco_sat"};
   TTreeReaderArray<Int_t> crt_SE_time = {fReader, "crt_SE_time"};
   TTreeReaderArray<Int_t> crt_TS_time = {fReader, "crt_TS_time"};
   TTreeReaderValue<Int_t> crt_nHitAllTot = {fReader, "crt_nHitAllTot"};
   TTreeReaderValue<Int_t> crt_nHitTot = {fReader, "crt_nHitTot"};
   TTreeReaderValue<Int_t> crt_nHitSatTot = {fReader, "crt_nHitSatTot"};
   TTreeReaderValue<Float_t> crt_charge = {fReader, "crt_charge"};
   TTreeReaderValue<Float_t> crt_ToF = {fReader, "crt_ToF"};
   TTreeReaderArray<Int_t> crt_track_hits_id = {fReader, "crt_track_hits_id"};
   TTreeReaderArray<Float_t> crt_track_param = {fReader, "crt_track_param"};
   TTreeReaderArray<Float_t> crt_track_param_p = {fReader, "crt_track_param_p"};
   TTreeReaderArray<Float_t> crt_track_param_m = {fReader, "crt_track_param_m"};
   TTreeReaderArray<Float_t> crt_track_door = {fReader, "crt_track_door"};
   TTreeReaderArray<Float_t> crt_track_door_p = {fReader, "crt_track_door_p"};
   TTreeReaderArray<Float_t> crt_track_door_m = {fReader, "crt_track_door_m"};
   TTreeReaderArray<Float_t> crt_track_wall = {fReader, "crt_track_wall"};
   TTreeReaderArray<Float_t> crt_track_wall_p = {fReader, "crt_track_wall_p"};
   TTreeReaderArray<Float_t> crt_track_wall_m = {fReader, "crt_track_wall_m"};
   TTreeReaderArray<Float_t> crt_pmt_dist = {fReader, "crt_pmt_dist"};
   TTreeReaderArray<Float_t> crt_pmt_dist_p = {fReader, "crt_pmt_dist_p"};
   TTreeReaderArray<Float_t> crt_pmt_dist_m = {fReader, "crt_pmt_dist_m"};
   TTreeReaderArray<Int_t> crt_isclosestpoint = {fReader, "crt_isclosestpoint"};
   TTreeReaderArray<Float_t> crt_drift_len = {fReader, "crt_drift_len"};
   TTreeReaderArray<Float_t> crt_drift_len_p = {fReader, "crt_drift_len_p"};
   TTreeReaderArray<Float_t> crt_drift_len_m = {fReader, "crt_drift_len_m"};
   TTreeReaderValue<Int_t> crt_isFV = {fReader, "crt_isFV"};
   TTreeReaderArray<Float_t> crt_point_door_fv = {fReader, "crt_point_door_fv"};
   TTreeReaderArray<Float_t> crt_point_door_fv_p = {fReader, "crt_point_door_fv_p"};
   TTreeReaderArray<Float_t> crt_point_door_fv_m = {fReader, "crt_point_door_fv_m"};
   TTreeReaderArray<Float_t> crt_point_wall_fv = {fReader, "crt_point_wall_fv"};
   TTreeReaderArray<Float_t> crt_point_wall_fv_p = {fReader, "crt_point_wall_fv_p"};
   TTreeReaderArray<Float_t> crt_point_wall_fv_m = {fReader, "crt_point_wall_fv_m"};
   TTreeReaderValue<Int_t> crt_isFC = {fReader, "crt_isFC"};
   TTreeReaderArray<Float_t> crt_point_door_fc = {fReader, "crt_point_door_fc"};
   TTreeReaderArray<Float_t> crt_point_door_fc_p = {fReader, "crt_point_door_fc_p"};
   TTreeReaderArray<Float_t> crt_point_door_fc_m = {fReader, "crt_point_door_fc_m"};
   TTreeReaderArray<Float_t> crt_point_wall_fc = {fReader, "crt_point_wall_fc"};
   TTreeReaderArray<Float_t> crt_point_wall_fc_p = {fReader, "crt_point_wall_fc_p"};
   TTreeReaderArray<Float_t> crt_point_wall_fc_m = {fReader, "crt_point_wall_fc_m"};
   TTreeReaderArray<Short_t> adc_value_0 = {fReader, "adc_value_0"};
   TTreeReaderArray<Short_t> adc_value_1 = {fReader, "adc_value_1"};
   TTreeReaderArray<Short_t> adc_value_2 = {fReader, "adc_value_2"};
   TTreeReaderArray<Short_t> adc_value_3 = {fReader, "adc_value_3"};
   TTreeReaderArray<Short_t> adc_value_4 = {fReader, "adc_value_4"};


   h1ana(TTree * /*tree*/ =0) { }
   virtual ~h1ana() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(h1ana,0);

};

#endif

#ifdef h1ana_cxx
void h1ana::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t h1ana::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef h1ana_cxx
