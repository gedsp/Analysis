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

 //lxxxpluss

  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001324_reprocessed.root");//
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001333_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001336_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001337_reprocessed.root");//
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001353_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001354_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001402_reprocessed.root");//
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001403_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001404_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001406_reprocessed.root");//
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001601_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001608_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001609_reprocessed.root");//
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001610_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001611_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001612_reprocessed.root");//
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001613_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001614_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001615_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001616_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001617_reprocessed.root");//
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001618_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001666_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001670_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001671_reprocessed.root");
  md->Add("/eos/experiment/wa105/data/311_PMT/data/root/reprocessed_5apr19/output00001672_reprocessed.root");//
 //looocall
  //md->Add("/Users/gloria/wa105/WA105_mine/DATA/output00001672_reprocessed.root");

  double min_threshold_bar = 500;
  double max_threshold_PM= 4089;
  
  
  if (md == 0) return;
  
  
  
  Long64_t nentries = md->GetEntries();

    Int_t           crt_adc[4][32];
     TBranch        *b_crt_adc;
    TBranch        *b_crt_ToF;   //!
     Float_t         crt_ToF;
  Float_t         crt_pmt_dist[5];
  Float_t         crt_pmt_dist_p[5];
  Float_t         crt_pmt_dist_m[5];
  TBranch        *b_crt_pmt_dist;   //!
  TBranch        *b_crt_pmt_dist_p;   //!
  TBranch        *b_crt_pmt_dist_m;   //!
  
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
      p0_cut->SetTitle(Form("Plane %d Cut %d; S_{B}; # events",j,cut));
      
      plano_cut.push_back(p0_cut);

    }


    V_plano_cut.push_back(plano_cut);

  }
  

  
  // cutted && 1st max vs 2nd max
  vector<TH2F*>  V_1maxvs2max;
  vector<TH1F*>  V_plano_tot_cut;
  TH1F* p_tot_cut;
  TH2F* p_1maxvs2max;
  for (int j =0; j<4; j++) {
       
       
    p_tot_cut =new TH1F(Form("plano_%d_cutted",j), "plano0", 60,0.1,8500);
    p_tot_cut->SetTitle(Form("Plane %d; S_{B}; # events",j));
  
    p_1maxvs2max =new TH2F(Form("plano_%d_1maxvs2max",j), "plano0", 8000,0.1,8500,8000,0.1,8500);
    p_1maxvs2max->SetTitle(Form("Plane %d; S_{B} 1st max;  S_{B} 2nd max",j));
       
    V_plano_tot_cut.push_back( p_tot_cut);
    V_1maxvs2max.push_back(p_1maxvs2max);
    
  }
  
  
  
  // tprofile
  vector<TProfile*>  plano_cut_hprof;
  TProfile* hprof;
 
  // # bar w events
   vector<TH1F*>  V_bars;
  TH1F* barwEvents;

 // # bar w events
  vector<TH1F*>  V_bars_cut;
 TH1F* barwEvents_cut;
  
  
  
  // signal diff vs singnal sum
   vector<TH2F*>  V_dif_sum;
  TH2F* dif_sum;
  
  for (int j =0; j<4; j++) {
       
       
    hprof =new TProfile(Form("plano_%d",j), "plano0", 3000,0.1,3000,0.,16.);
    hprof->SetTitle(Form("Plane %d; Cut Value; # active bars",j));
       
    barwEvents_cut = new TH1F(Form("barwEvents_%d_cut",j), " barwEvents_cut", 16,-0.5,15.5);
    
    barwEvents = new TH1F(Form("barwEvents_%d",j), " barwEvents", 16,-0.5,15.5);
    barwEvents->SetTitle("Distribuition # bar with events; # bar with events; # events");
    
   
    dif_sum = new TH2F(Form("_dif%d",j), "dif", 800,-4500,4500,1600,0,8000);
    dif_sum->SetTitle("; S1-S2; S1+S2");
   
    V_bars_cut.push_back(barwEvents_cut);

    V_bars.push_back(barwEvents);
    plano_cut_hprof.push_back(hprof);
    V_dif_sum.push_back(dif_sum);
    
     }
  
  
  //S1+s2 vs coord
  vector<TH2F*>   V_delta_max_2;
  TH2F* sbcoor02 = new TH2F("sbcoor_20", "sbcoor0",  100,0.1,8500,100,0,8000);
  sbcoor02->SetTitle("Plane 0; S_{B} 1st max-S_{B} 2nd max; Signal max");
   V_delta_max_2.push_back(sbcoor02);
  TH2F* sbcoor12 = new TH2F("sbcoor_21", "sbcoor1",  100,0.1,8500,100,0,8000);
  sbcoor12->SetTitle("Plane 1; S_{B} 1st max-S_{B} 2nd max;  Signal max");
   V_delta_max_2.push_back(sbcoor12);
  
  TH2F* sbcoor22 = new TH2F("sbcoor_22", "sbcoor1",  100,0.1,8500,100,0,8000);
  sbcoor22->SetTitle("Plane 2; S_{B} 1st max-S_{B} 2nd max;  Signal max");
   V_delta_max_2.push_back(sbcoor22);
  
  TH2F* sbcoor32 = new TH2F("sbcoor_23", "sbcoor1",  100,0.1,8500,100,0,8000);
   sbcoor32->SetTitle("Plane 3; S_{B} 1st max-S_{B} 2nd max; Signal max");
    V_delta_max_2.push_back(sbcoor32);
 
  //S1+s2 vs coord
  vector<TH1F*>   V_delta_max;
  TH1F* sbcoor0 = new TH1F("sbcoor_0", "sbcoor0",  100,0.1,8500);
  sbcoor0->SetTitle("Plane 0; S_{B} 1st max-S_{B} 2nd max; # events");
   V_delta_max.push_back(sbcoor0);
  TH1F* sbcoor1 = new TH1F("sbcoor_1", "sbcoor1",  100,0.1,8500);
  sbcoor1->SetTitle("Plane 1; S_{B} 1st max-S_{B} 2nd max; # events");
   V_delta_max.push_back(sbcoor1);
  
  TH1F* sbcoor2 = new TH1F("sbcoor_2", "sbcoor1",  100,0.1,8500);
  sbcoor2->SetTitle("Plane 2; S_{B} 1st max-S_{B} 2nd max; # events");
   V_delta_max.push_back(sbcoor2);
  
  TH1F* sbcoor3 = new TH1F("sbcoor_3", "sbcoor1",  100,0.1,8500);
   sbcoor3->SetTitle("Plane 3; S_{B} 1st max-S_{B} 2nd max; # events");
    V_delta_max.push_back(sbcoor3);
  
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
  
  TH2F* plano01 = new TH2F("plano01", "plano01",  16,-0.5,15.5, 16,-0.5,15.5);
  TH2F* plano23 = new TH2F("plano23", "plano23",  16,-0.5,15.5, 16,-0.5,15.5);
  plano01->SetTitle("Coincidences Plane 0 and 1; Plane 0; Plane 1");
  plano23->SetTitle("Coincidences Plane 2 and 3; Plane 3; Plane 2");


  // planes occupancy weighted
  TH2F* plano0W = new TH2F("plano01W", "plano01W", 16,0.0,16,20,0.0,8000);
  TH2F* plano2W = new TH2F("plano23W", "plano23W",16,0.0,16,20,0.0,8000);
  plano0W->SetTitle("Plane 0; bar ID #; Signal Max");
  plano2W->SetTitle("Plane 2; bar ID #; Signal Max");
  TH2F* plano1W = new TH2F("plano1W", "plano1W", 16,0.0,16,20,0.0,8000);
  TH2F* plano3W = new TH2F("plano3W", "plano3W",16,0.0,16,20,0.0,8000);
  plano1W->SetTitle("Plane 1; bar ID #; Signal Max");
  plano3W->SetTitle("Plane 3; bar ID #; Signal Max");
  
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
  
  
  
  
  //tof plot
  
  TH1F * tof = new TH1F("TOF", "TOF",  400,-200,200);
  tof->SetTitle("TOF; TOF (ns); # events");

  //L vs tof
  
  TH2F* LvsTOF = new TH2F("LvsTOF", "LvsTOF" , 100,-50,50.0,100, 740,840.0);
  LvsTOF->SetTitle("L vs TOF; TOF (ns) ; L (cm)");
  
  
  //dispertion
  
  TH2F* disp = new TH2F("plane_max", "plane" , 200, -7000,7000,200,-7000,7000);
  disp->SetTitle("#Delta Signal P1-P0 vs P2-P3; P1-P0; P2-P3");
  TH1F* disp01 = new TH1F("disp01", "disp01", 200, -7000,7000);
  disp01->SetTitle("#Delta Signal P1-P0; P1-P0; # events");
  TH1F* disp23 = new TH1F("dip23", "23a", 200,-7000,7000);
  disp23->SetTitle("#Delta Signal P2-P3;  P2-P3; # events");
  

  //costheta
  
  TH1F* coor_spherical = new TH1F("theta", "theta",  25,60,120);
  coor_spherical->SetTitle("Distribuition #theta; #theta; # events");
  TH1F* coor_costheta = new TH1F("costheta", "TCostheta",  50,-0.6,0.6);
  coor_costheta->SetTitle("Distribuition cos(#theta); cos(#theta); # events");
  TH1F* coor_spherical_tof_m0 = new TH1F("theta2", "theta2",  25,60,120);
  TH1F* coor_costhetatof_m0 = new TH1F("costheta2", "TCostheta2",  50,-0.6,0.6);

  
  
  
  
  TH2F * costhetavsphi = new  TH2F("costhetavsphi", "costhetavsphi" , 10, -1.6,1.6,40,-0.2,0.4);
  costhetavsphi->SetTitle("Distribuition cos(#theta vs #phi); #phi (rad); cos(#theta)");
  
  //PMT
 TH1F* pmt = new TH1F("pmt", "pmt",  250,0,1800);
 pmt->SetTitle("Distance to PMT 3; Distance to PMT 3 (mm) ; # events");
  
  
  
  
  
  
  
  ofstream cut;
  cut.open ("DADOS_cut.txt");
  
  ofstream myfile;
  myfile.open ("DADOS.txt");
  int g=0;
  double  ycor_plane0=-376.2;
  double  ycor_plane1=-376;
  double  ycor_plane2=376.2;
  double  ycor_plane3=376;

  
  

  int Trackij_Z[16][16];
  int Trackij_X[16][16];
  for (int m; m<16; m++) {
    for (int n; n<16; n++) {
      Trackij_Z[m][n]=0;
      Trackij_X[m][n]=0;

    }
  }
  
  double xf12=0,xf23=0,xf14=0,xf34=0;
  double zf12=0,zf23=0,zf14=0,zf34=0;
  int iOkEvent=0,DrawGraph=0,SkipEvent=0;
  
  for (Long64_t jentry=0; jentry<nentries;jentry++) { /* -----------------------------------       loop on events      ---------------------------------  */
 
 
    md->SetBranchAddress("crt_adc", crt_adc, &b_crt_adc);
    md->SetBranchAddress("crt_ToF", &crt_ToF, &b_crt_ToF);
    md->SetBranchAddress("crt_pmt_dist", crt_pmt_dist, &b_crt_pmt_dist);
     md->SetBranchAddress("crt_pmt_dist_p", crt_pmt_dist_p, &b_crt_pmt_dist_p);
     md->SetBranchAddress("crt_pmt_dist_m", crt_pmt_dist_m, &b_crt_pmt_dist_m);
    
   
    
    
    
    int zeros,overflow;
    int barID[4];
  
    nb = md->GetEntry(jentry);   nbytes += nb;
    
    
    // plane signal
    double PlaneSignalTot[4][16];
    double PlaneSignalDif[4][16];
    double PlaneMax[4],PlaneMin[4];
    int f=0;
    
    for ( int k =0; k<4; k++) {   // loop on planes
    
      for (int j=0; j<32; j++) { //loop on SiPM
        
      
        
        /*******************************************************/
        
        // computing scint bar signal
        
        if (j % 2 == 0){
          
           int b=j/2;
          
          
          if(crt_adc[k][j]==max_threshold_PM||crt_adc[k][j+1]==max_threshold_PM){ //upper cut
            
            overflow++;
          //  cout << overflow << endl;
            
          }
          else {
            PlaneSignalTot[k][b]=crt_adc[k][j]+crt_adc[k][j+1];
            PlaneSignalDif[k][b]=crt_adc[k][j]-crt_adc[k][j+1];
            
            
            V_dif_sum[k]->Fill(PlaneSignalDif[k][b], PlaneSignalTot[k][b]);
            
            
            if (PlaneSignalTot[k][b]>min_threshold_bar) //aplicar corte mini
            {
              f++;
               V_plano_tot_cut[k]->Fill(PlaneSignalTot[k][b]);
            }
            
             if (f!=0) {
                          V_bars[k]->Fill(f);
                     
                    
                  }
            
            
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
      
       f=0;
      double * pmin  =  min_element(begin(PlaneSignalTot[k]), end(PlaneSignalTot[k]));
      double * pmax =  max_element(begin(PlaneSignalTot[k]), end(PlaneSignalTot[k]));
     
      PlaneMax[k]=*pmax;
      PlaneMin[k]=*pmin;
       
      barID[k]= distance(PlaneSignalTot[k], pmax);
     
      V_plano_Max[k]->Fill(PlaneMax[k]);
      
      
      if (PlaneMax[k]>min_threshold_bar /*VALUE OF THRESHOLD */){
        
        g=g+1;
        
      }

      
      
      
      // GET 1ST MAX VS 2ND MAX
      
      
      int n = sizeof(PlaneSignalTot[k])/sizeof(PlaneSignalTot[k][0]);
      
      sort(PlaneSignalTot[k], PlaneSignalTot[k]+n);
      
      V_1maxvs2max[k]->Fill(PlaneSignalTot[k][15],PlaneSignalTot[k][14]);
      
      double dif=PlaneSignalTot[k][15]-PlaneSignalTot[k][14];
     
      if (PlaneMax[k]>min_threshold_bar /*VALUE OF THRESHOLD */){
      V_delta_max[k]->Fill(dif);
      V_delta_max_2[k]->Fill(dif,PlaneMax[k]);
      }
      
      
      if(dif<2000.){
        
        SkipEvent++;
      }
    
      
    }
  
    
    f=0;
    if (g==4&&SkipEvent==0) {
      
      
      iOkEvent++;

      if (iOkEvent==1) {
        DrawGraph=1;
      }
      else DrawGraph=0;
      
      plano01->Fill(barID[0],barID[1]);
      plano23->Fill(barID[3],barID[2]);
      

      pmt->Fill(crt_pmt_dist[2]);
      
      double PlaneMax10 = PlaneMax[1]-PlaneMax[0];
      double PlaneMax23 = PlaneMax[2]-PlaneMax[3];

    
    
      
      disp->Fill(PlaneMax10,PlaneMax23);
      disp01->Fill(PlaneMax10);
      disp23->Fill(PlaneMax23);
     // CRT ARE SHIFTED SO NEED TO ADD A SHIFT IN ZZ
      
      double xx0 = barID[0]*10.8+(barID[0]-1)*0.02+5.4-86.55;
      double zz1 = barID[1]*10.8+(barID[1]-1)*0.02+5.4-86.55+15;
      
      double xx3 = barID[3]*10.8+(barID[3]-1)*0.02+5.4-86.55;
      double zz2 = barID[2]*10.8+(barID[2]-1)*0.02+5.4-86.55-90;
      
      
      Trackij_Z[barID[1]][barID[2]]++;
      Trackij_X[barID[0]][barID[3]]++;
      
      
      double phi=atan( (ycor_plane0-ycor_plane3)/(xx0-xx3) );
    
      
      double L=sqrt((xx0-xx3)*(xx0-xx3)+(ycor_plane0-ycor_plane3)*(ycor_plane0-ycor_plane3)+(zz1-zz2)*( zz1-zz2 ));
   
      
      double costheta=(  abs(( zz1-zz2 ))  / L);
      
      costhetavsphi->Fill(phi,costheta);
      
     
      tof->Fill(crt_ToF);
      
      if (crt_ToF>0) {
         coor_spherical->Fill(180*acos(costheta)/M_PI);
         coor_costheta->Fill(costheta);
      }
      else if (crt_ToF<0){
        coor_spherical_tof_m0->Fill(180*acos(-costheta)/M_PI);
        coor_costhetatof_m0->Fill(-costheta);
        
      }
       
      LvsTOF->Fill(crt_ToF,L);

      
      for ( int k =0; k<4; k++) {   // loop on planes
             
               for (int b=0;b<16; b++) { //loop on SiPM
       
                     if (PlaneSignalTot[k][b]>min_threshold_bar) //aplicar corte mini
                               {
                                 f++;
                                 // V_plano_tot_cut[k]->Fill(PlaneSignalTot[k][b]);
                               }
               }
            
            
            if (f!=0) {
                   V_bars_cut[k]->Fill(f);
             
            
            }
        f=0;
          }
      
      
      /*V_sB_coor[0]->Fill(PlaneMax[0],abs(abs(zz1)-110));
      V_sB_coor[1]->Fill(PlaneMax[1],abs(abs(xx0)-115));
      V_sB_coor[2]->Fill(PlaneMax[2],abs(abs(xx3)-115));
      V_sB_coor[3]->Fill(PlaneMax[3],abs(abs(zz2)-205));
      */
  //    cout << "zz plano 3 " << zz2 << " - "  << 205<< endl;
      
      /*
          Track_z_y->SetPoint(0,ycor_plane1,zz1);
          Track_z_y->SetPoint(1,ycor_plane2,zz2);
          Track_x_y->SetPoint(0,ycor_plane0,xx0);
          Track_x_y->SetPoint(1,ycor_plane3,xx3);
      */
      
  /*    if (xx0>0&&xx3>0) {
        xf12=xf12+1;
         Track_x_y->SetLineColor(kBlue);
      }
  */
      if ((xx0<0&&xx3<0)||(xx0>0&&xx3>0)) {
           
                   xf12=xf12+1;
               
        

      }
      
      
      if (xx0>0&&xx3<0) {
       
        xf14=xf14+1;
  

      }
           
      if (xx0<0&&xx3>0) {
          xf23=xf23+1;
  
      }
         
      
      
      
     // if (zz1>15.55&&zz2>-90) {
     //   zf12=zf12+1;
     // }
      
      if (zz1==zz2) {
            zf34=zf34+1;
   
      
      }
      
      
      if (zz1>-3.15) {
             zf14=zf14+1;
      
      }
           
      if (zz1<-37.55&&zz2>-37.55) {
        
        
                 zf23=zf23+1;
      }
      
      
     

      
      plano0W->Fill(barID[0], PlaneMax[0]);
      plano2W->Fill(barID[2] , PlaneMax[1]);
      plano1W->Fill(barID[1], PlaneMax[2]);
      plano3W->Fill(barID[3], PlaneMax[3]);
      
    }
  
  
    // Canvas->cd();
  //Track_z_y->Fit("pol1");
    //Track_z_y->SetMarkerStyle(20);
   // Track_z_y->SetLineColorAlpha(kRed,0.50);
   
  
    
    
    
 g=0,SkipEvent=0;
  
   int l=0;
   
  //min cut
     int m=0;
    for (int min=50; min<3000; min=min+50) {
     
      for (int k=0; k<4; k++) {
        
        vector<double> CutSignal;
        
         for (int b=0; b<16; b++) {
        

           if ( PlaneSignalTot[k][b]>min) {
             
    
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
  
  
  
  TCanvas * Canvas = new TCanvas();
  TCanvas * Canvas2 = new TCanvas();
  
  // Track_z_y->SetLineWidth(1);
     
  int notdrawZ=0,notdrawX=0;
  
  int TijRebin_X[8][8];
  int TijRebin_Z[8][8];
  
  for (int m=0; m<16; m++) {
    for (int n=0; n<16; n++) {
      
      
      if (m<2){
        
        if (n<2) {
            TijRebin_X[m][n]++;
          TijRebin_Z[m][n]++;

        }
        
       
        
      }
      
      if (m<4&&m>=2){
           
        if ((n<4&&n>=2)) {
               TijRebin_X[m][n]++;
                  TijRebin_Z[m][n]++;


             }
          }
      
      if (m<8&&m>=4){
              
        if ((n<8&&n>=4)) {
                    TijRebin_X[m][n]++;
                      TijRebin_Z[m][n]++;


              }
      }
      
      
      if (m<10&&m>=8){
              if ((n<16&&n>=12)) {
                    TijRebin_X[m][n]++;
                     TijRebin_Z[m][n]++;

              }
       }
       
      if (m<12&&m>=10){
                 
        if (n<12&&n>=10) {
                       TijRebin_X[m][n]++;
                         TijRebin_Z[m][n]++;

                  }
           }
     
      
      if (m<14&&m>=12){
                  
        if (n<14&&n>=12) {
                        TijRebin_X[m][n]++;
                         TijRebin_Z[m][n]++;

                  }
           }
      
      if (m<16&&m>=14){
                     
        if (n<16&&n>=14){
                           TijRebin_X[m][n]++;
                            TijRebin_Z[m][n]++;

                     }
              }
      
    }
  }
  
  for (int m=0; m<8; m++) {
    for (int n=0; n<8; n++) {
      
      TGraph* Track_z_y = new TGraph(2);
      TGraph* Track_x_y = new TGraph(2);
     
      double xx0 = (2*m)*10.8+(2*m-1)*0.02+5.4-86.55;
        
      double zz1 = (2*m)*10.8+(2*m-1)*0.02+5.4-86.55+15;
               
      
      double xx3 = (2*n)*10.8+(2*n-1)*0.02+5.4-86.55;
      
      double zz2 = (2*n)*10.8+(2*n-1)*0.02+5.4-86.55-90;
                              
         
          
          if (TijRebin_Z[m][n]>10000000) {
                
                Track_z_y->SetPoint(0,ycor_plane1,zz1);
                Track_z_y->SetPoint(1,ycor_plane2,zz2);
                
                Track_z_y->Fit("pol1");
                
                TF1 *fit = Track_z_y->GetFunction("pol1");
                
                fit->SetLineColor(kBlue+2);
              
                
                }
          
        
          else if (TijRebin_Z[m][n]>1000000&&TijRebin_Z[m][n]<10000000) {
                 
                 Track_z_y->SetPoint(0,ycor_plane1,zz1);
                 Track_z_y->SetPoint(1,ycor_plane2,zz2);
                 
                 Track_z_y->Fit("pol1");
                 
                 TF1 *fit = Track_z_y->GetFunction("pol1");
                 
                 fit->SetLineColor(kBlue+2);
               
                 
                 }
          
      
          
         else  if (TijRebin_Z[m][n]>10000&&TijRebin_Z[m][n]<1000000) {
            
            Track_z_y->SetPoint(0,ycor_plane1,zz1);
            Track_z_y->SetPoint(1,ycor_plane2,zz2);
            
            Track_z_y->Fit("pol1");
            
            TF1 *fit = Track_z_y->GetFunction("pol1");
            
            fit->SetLineColor(kAzure+2);
          
            
            }
        
          else if(TijRebin_Z[m][n]<10000&&TijRebin_Z[m][n]>0) {
         
          Track_z_y->SetPoint(0,ycor_plane1,zz1);
            Track_z_y->SetPoint(1,ycor_plane2,zz2);
            
            Track_z_y->Fit("pol1");
           TF1 *fit = Track_z_y->GetFunction("pol1");
           fit->SetLineColor(kAzure-9);
            
       
          }
         
          else {
            
            notdrawZ=1;
          }
          
        
          
          if (TijRebin_X[m][n]>1000000) {
              
              Track_x_y->SetPoint(0,ycor_plane0,xx0);
              Track_x_y->SetPoint(1,ycor_plane3,xx3);
              Track_x_y->Fit("pol1");
              TF1 *fit = Track_x_y->GetFunction("pol1");
              fit->SetLineColor(kBlue+2);
                   
                   
            }
         
          
            
       else if (TijRebin_X[m][n]>1000000&&TijRebin_X[m][n]<1000000) {
             
             Track_x_y->SetPoint(0,ycor_plane0,xx0);
             Track_x_y->SetPoint(1,ycor_plane3,xx3);
             Track_x_y->Fit("pol1");
             TF1 *fit = Track_x_y->GetFunction("pol1");
             fit->SetLineColor(kBlue+2);
                  
                  
           }
       
          
          
      else  if (TijRebin_X[m][n]>10000&&TijRebin_X[m][n]<100000) {
          
          Track_x_y->SetPoint(0,ycor_plane0,xx0);
          Track_x_y->SetPoint(1,ycor_plane3,xx3);
          Track_x_y->Fit("pol1");
          TF1 *fit = Track_x_y->GetFunction("pol1");
          fit->SetLineColor(kAzure+2);
               
               
        }
       
       
        else if(TijRebin_X[m][n]<10000&&TijRebin_X[m][n]>0) {
        
          Track_x_y->SetPoint(0,ycor_plane0,xx0);
          Track_x_y->SetPoint(1,ycor_plane3,xx3);
          Track_x_y->Fit("pol1");
          TF1 *fit = Track_x_y->GetFunction("pol1");
          fit->SetLineColor(kAzure-9);
          
             
        
        }
        
          else {
            
            notdrawX=1;
          }
          
      
          if (n==0&&m==0) {
           
           Canvas->cd();
            Track_z_y->SetTitle("Reconstructed Track projection  Z Y; y (cm); z (cm)");
            Track_z_y->SetMaximum(100);
            Track_z_y->SetMinimum(-200);
            Track_z_y->GetXaxis()->SetLimits(-377,377);
            Track_z_y->Draw("AP");

            Canvas2->cd();
            
            Track_x_y->SetTitle("Reconstructed Track projection  X Y; y (cm); x (cm)");
            Track_x_y->SetMaximum(87);
            Track_x_y->SetMinimum(-87);
            Track_x_y->GetXaxis()->SetLimits(-377,377);
            Track_x_y->Draw("AP");
          
           
                
        
            }
        
          else {
            Canvas->cd();
            Track_z_y->Draw("Same");
            Canvas2->cd();
            Track_x_y->Draw("Same");
                       
            
            
          }
      
      
      
    }
  }
      
  
  
  Canvas->Print("lxplus/Track_z_ys.pdf");
  Canvas2->Print("lxplus/Track_x_ys.pdf");
  
  
  
  
  
  double xxtot=xf12+xf14+xf23+xf34;
  double zztot=zf14+zf23+zf34;
  
  
  
  cout << "\nProjection X Y \nfraction of tracks 1->2 " << xf12/xxtot << "\nfraction of tracks 2->3 " << xf23/xxtot << "\nfraction of tracks 3->4 " << xf34/xxtot << "\nfraction of tracks 1->4 " << xf14/xxtot << endl;
  
  cout << "\nProjection Z Y\nfraction of tracks 1->2 " << zf34/zztot << "\nfraction of tracks 2->3 " << zf23/zztot << "\nfraction of tracks 3->4 " << zf34/zztot << "\nfraction of tracks 1->4 " << zf14/zztot << endl;
   
  
  
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
 /*
    TCanvas * c1 = new TCanvas();
gStyle->SetGridStyle(3);
  //  gStyle->SetOptStat(0);
  c1->Divide(2,2);
    c1->cd(1);
  gPad->SetGrid();
  plano_cut_hprof[0]->SetLineColor(2);
   plano_cut_hprof[0]->SetLineWidth(3);
  plano_cut_hprof[0]->Draw("E");
    c1->cd(2);
    gPad->SetGrid();
  plano_cut_hprof[1]->SetLineColor(2);
     plano_cut_hprof[1]->SetLineWidth(3);
  plano_cut_hprof[1]->Draw("EP");
  c1->cd(3);
    gPad->SetGrid();
   plano_cut_hprof[2]->SetLineColor(2);
     plano_cut_hprof[2]->SetLineWidth(3);
  plano_cut_hprof[2]->Draw("E");
    c1->cd(4);
    gPad->SetGrid();
   plano_cut_hprof[3]->SetLineColor(2);
     plano_cut_hprof[3]->SetLineWidth(3);
  plano_cut_hprof[3]->Draw("E");

    c1->Print("lxplus/tprofile.pdf");
  
  
*/
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
    
  c2->Print("lxplus/Crt_adc_diff.pdf");
 */
 /**************************************************/
 
  TCanvas * c3 = new TCanvas();

  gStyle->SetOptStat(0);  
  c3->Divide(1,2);
  c3->cd(1);
  plano01->Draw("COLZ");
  c3->cd(2);
  plano23->Draw("COLZ");

  c3->Print("lxplus/Crt_coincidencias_barras.pdf");


  /**************************************************/
  
  
  TCanvas * c7 = new TCanvas();
  tof->Draw("hist");
  c7->Print("lxplus/tof.pdf");
  
   /**************************************************/

  TCanvas * c8 = new TCanvas("c8", "c8", 1800,900);
  c8->Divide(3,1);
  c8->cd(1);
   disp->Draw("COLZ");
  c8->cd(2);
  disp01->Draw("hist");
  c8->cd(3);
  disp23->Draw("hist");
  
   c8->Print("lxplus/disp.pdf");
   
    /**************************************************/
  
  TCanvas * c12 = new TCanvas();
   c12->Divide(2,2);
    c12->cd(1);
    V_bars[0]->Draw("hist");
  V_bars_cut[0]->SetLineColor(kRed);
  V_bars_cut[0]->Draw("same hist");
    c12->cd(2);
    V_bars[1]->Draw("hist");
  V_bars_cut[1]->SetLineColor(kRed);
  V_bars_cut[1]->Draw("same hist");
    c12->cd(3);
    V_bars[2]->Draw("hist");
  V_bars_cut[2]->SetLineColor(kRed);
  V_bars_cut[2]->Draw("same hist");
    c12->cd(4);
    V_bars[3]->Draw("hist");
  V_bars_cut[3]->SetLineColor(kRed);
  V_bars_cut[3]->Draw("same hist");
  auto legend1 = new TLegend(0.50,0.7,0.84,0.9);
   legend1->AddEntry( V_bars[3],"Pre cut","l");
   legend1->AddEntry(V_bars_cut[3],"Cut","l");
   legend1->Draw();
  
   c12->Print("lxplus/barswevents_precut.pdf");
   
    /**************************************************/
  
  
  TCanvas * c13 = new TCanvas();
    c13->Divide(2,2);
     c13->cd(1);
       V_delta_max[0]->Draw("hist");
     c13->cd(2);
       V_delta_max[1]->Draw("hist");
     c13->cd(3);
       V_delta_max[2]->Draw("hist");
     c13->cd(4);
     V_delta_max[3]->Draw("hist");
  
    c13->Print("lxplus/deltaSB.pdf");
    
  /**************************************************/
  
  
  TCanvas * c15 = new TCanvas();
    c15->Divide(2,2);
     c15->cd(1);
       V_delta_max_2[0]->Draw("COLZ");
     c15->cd(2);
       V_delta_max_2[1]->Draw("COLZ");
     c15->cd(3);
       V_delta_max_2[2]->Draw("COLZ");
     c15->cd(4);
     V_delta_max_2[3]->Draw("COLZ");
  
    c15->Print("lxplus/deltaSB_EnMAx.pdf");
  
  
     /**************************************************/
  
  TCanvas * c9 = new TCanvas();
  c9->Divide(2,1);
  c9->cd(1);
  //coor_spherical->SetMarkerStyle(29);
   coor_spherical->Draw("hist");
  coor_spherical_tof_m0->SetLineColor(kRed);
  coor_spherical_tof_m0->Draw("same hist");
  c9->cd(2);
   coor_costheta->SetMarkerStyle(29);
  coor_costheta->Draw("hist");
  coor_costhetatof_m0->SetLineColor(kRed);
 coor_costhetatof_m0->Draw("same hist");
  
  double integralW90TOFM0 = coor_spherical->Integral(65,120);
  double integralW90TOFm0 = coor_spherical_tof_m0->Integral(60,120);
  
  double integralWOUT90TOFm0 = coor_spherical_tof_m0->Integral(92.4,120);
  
  double integralJUST90TOFm0=coor_spherical_tof_m0->Integral(87.6,92.4);
  
  
  
  
  
   auto legend = new TLegend(0.1,0.7,0.48,0.9);
   legend->AddEntry(coor_costhetatof_m0,"TOF<0","l");
    legend->AddEntry(coor_costheta,"TOF>0","l");
    legend->Draw();
   c9->Print("lxplus/costheta.pdf");
   
  cout <<  "integral W 90 TOF M 0 " <<  integralW90TOFM0 << endl;
  cout <<  "integral W 90 TOF m 0 " <<  integralW90TOFm0 << endl;
   cout <<  "integral WOUT 90 TOF m 0 " <<  integralWOUT90TOFm0 << endl;
   cout <<  "integral JUST 90 TOF m 0 " <<  integralJUST90TOFm0 << endl;
  
  cout << " ratio  " << integralWOUT90TOFm0/ (integralJUST90TOFm0+integralW90TOFM0) << endl;
  
   /**************************************************/

   TCanvas * c10 = new TCanvas();
   LvsTOF->Draw("COLZ");
   c10->Print("lxplus/LVSTOF.pdf");
   

  
  
    /**************************************************/

   TCanvas * c11 = new TCanvas();
   costhetavsphi->Draw("COLZ");
   c11->Print("lxplus/costhetavsphi.pdf");
   

  
  
    /**************************************************/
  
   TCanvas * c14 = new TCanvas();
   pmt->Draw("hist");
   c14->Print("lxplus/pmt.pdf");
   

  
  
    /**************************************************/
 /* TCanvas * c31 = new TCanvas();

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
  c31->Print("lxplus/Crt_barras_weighted.pdf");

*/

  /**************************************************/

  TCanvas * c4 = new TCanvas();
  
  gStyle->SetOptStat(0);
 // c4->Divide(2,2);
  //c4->cd(1);
  
 /* TF1 *g5 = new TF1("m1","gaus",200,500);
  g5->SetLineColor(kRed+1);
  g5->SetLineWidth(2);
  
    V_plano[0]->Fit(g5,"R");*/
  

  V_plano_tot_cut[0]->SetLineWidth(2);
    V_plano_tot_cut[0]->Draw("hist");
  //c4->cd(2);
  V_plano_tot_cut[1]->SetLineColor(kGreen+2);
  V_plano_tot_cut[1]->SetLineWidth(2);
  V_plano_tot_cut[1]->Draw("hist same");
  //c4->cd(3);
  V_plano_tot_cut[2]->SetLineColor(kRed);
  V_plano_tot_cut[2]->SetLineWidth(2);
  V_plano_tot_cut[2]->Draw("hist same");
  //c4->cd(4);
  V_plano_tot_cut[3]->SetLineColor(kOrange+1);
  V_plano_tot_cut[3]->SetLineWidth(2);
   V_plano_tot_cut[3]->Draw("hist same");
  auto legend3 = new TLegend(0.60,0.7,0.80,0.9);
    legend3->AddEntry(V_plano_tot_cut[0],"Plane 0","l");
     legend3->AddEntry(V_plano_tot_cut[1],"Plane 1","l");
   legend3->AddEntry(V_plano_tot_cut[2],"Plane 2","l");
  legend3->AddEntry(V_plano_tot_cut[3],"Plane 3","l");
     legend3->Draw();
  
  c4->Print("lxplus/Crt_V_plano_tot_cut[0].pdf");

 
 

  /**************************************************/
 
  TCanvas * c5 = new TCanvas();
   
   gStyle->SetOptStat(0);
   c5->Divide(2,2);
   c5->cd(1);
   V_1maxvs2max[0]->Draw("COLZ");
   c5->cd(2);
    V_1maxvs2max[1]->Draw("COLZ");
   c5->cd(3);
    V_1maxvs2max[2]->Draw("COLZ");
   c5->cd(4);
    V_1maxvs2max[3]->Draw("COLZ");
   c5->Print("lxplus/1stmaxvs2ndmax.pdf");

   /**************************************************/
  
   TCanvas * c18 = new TCanvas();
    
    gStyle->SetOptStat(0);
    c18->Divide(2,2);
    c18->cd(1);
    V_dif_sum[0]->Draw("COLZ");
    c18->cd(2);
     V_dif_sum[1]->Draw("COLZ");
    c18->cd(3);
     V_dif_sum[2]->Draw("COLZ");
    c18->cd(4);
    V_dif_sum[3]->Draw("COLZ");
    c18->Print("lxplus/V_dif_sum.pdf");




}
