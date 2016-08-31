//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Aug 30 20:47:34 2016 by ROOT version 6.02/05
// from TTree tree/PhysicsTools.Heppy.analyzers.core.AutoFillTreeProducer.AutoFillTreeProducer_1
// found on file: /eos/uscms/store/user/lpchbb/HeppyNtuples/V23/TT_TuneCUETP8M1_13TeV-powheg-pythia8/VHBB_HEPPY_V23_TT_TuneCUETP8M1_13TeV-powheg-Py8__spr16MAv2-puspr16_80r2as_2016_MAv2_v0_ext4-v1/160717_083956/0003/tree_3919.root
//////////////////////////////////////////////////////////

#ifndef heppyTree_h
#define heppyTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class heppyTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          run;
   UInt_t          lumi;
   ULong64_t       evt;
   Int_t           isData;
   Float_t         xsec;
   Float_t         puWeight;
   Float_t         nTrueInt;
   Float_t         genWeight;
   Float_t         puWeightUp;
   Float_t         puWeightDown;
   Float_t         json;
   Float_t         json_silver;
   Float_t         nPU0;
   Float_t         nPVs;
   Float_t         Vtype;
   Float_t         VtypeSim;
   Float_t         VMt;
   Float_t         HVdPhi;
   Float_t         fakeMET_sumet;
   Int_t           bx;
   Float_t         caloMetPt;
   Float_t         caloMetPhi;
   Float_t         rho;
   Float_t         rhoN;
   Float_t         rhoCHPU;
   Float_t         rhoCentral;
   Float_t         deltaR_jj;
   Float_t         lheNj;
   Float_t         lheNb;
   Float_t         lheNc;
   Float_t         lheNg;
   Float_t         lheNl;
   Float_t         lheV_pt;
   Float_t         lheHT;
   Int_t           genTTHtoTauTauDecayMode;
   Float_t         ttCls;
   Float_t         heavyFlavourCategory;
   Float_t         mhtJet30;
   Float_t         mhtPhiJet30;
   Float_t         htJet30;
   Float_t         met_sig;
   Float_t         met_rawpt;
   Float_t         metPuppi_pt;
   Float_t         metPuppi_phi;
   Float_t         metPuppi_rawpt;
   Float_t         metType1p2_pt;
   Float_t         tkMet_pt;
   Float_t         tkMet_phi;
   Float_t         tkMetPVchs_pt;
   Float_t         tkMetPVchs_phi;
   Float_t         isrJetVH;
   Float_t         Flag_hbheIsoFilter;
   Float_t         Flag_hbheFilterNew;
   Float_t         simPrimaryVertex_z;
   Float_t         genHiggsDecayMode;
   Float_t         btagWeightCSV_down_cferr1;
   Float_t         btagWeightCMVAV2_down_hfstats1;
   Float_t         btagWeightCMVAV2_down_hfstats2;
   Float_t         btagWeightCSV_down_cferr2;
   Float_t         btagWeightCSV_down_jes;
   Float_t         btagWeightCSV_down_lf;
   Float_t         btagWeightCSV_up_lf;
   Float_t         btagWeightCSV_down_lfstats2;
   Float_t         btagWeightCSV_down_lfstats1;
   Float_t         btagWeightCSV_down_hf;
   Float_t         btagWeightCSV_up_lfstats1;
   Float_t         btagWeightCMVAV2_down_lf;
   Float_t         btagWeightCSV_up_lfstats2;
   Float_t         btagWeightCSV;
   Float_t         btagWeightCSV_up_cferr2;
   Float_t         btagWeightCSV_up_cferr1;
   Float_t         btagWeightCSV_up_hf;
   Float_t         btagWeightCMVAV2_down_hf;
   Float_t         btagWeightCMVAV2_up_lfstats2;
   Float_t         btagWeightCMVAV2_up_hfstats2;
   Float_t         btagWeightCMVAV2_up_hfstats1;
   Float_t         btagWeightCMVAV2;
   Float_t         btagWeightCMVAV2_up_lfstats1;
   Float_t         btagWeightCMVAV2_down_cferr2;
   Float_t         btagWeightCMVAV2_up_hf;
   Float_t         btagWeightCMVAV2_down_cferr1;
   Float_t         btagWeightCSV_up_jes;
   Float_t         btagWeightCMVAV2_up_jes;
   Float_t         btagWeightCMVAV2_up_lf;
   Float_t         btagWeightCSV_down_hfstats2;
   Float_t         btagWeightCSV_down_hfstats1;
   Float_t         btagWeightCMVAV2_up_cferr1;
   Float_t         btagWeightCMVAV2_up_cferr2;
   Float_t         btagWeightCMVAV2_down_lfstats1;
   Float_t         btagWeightCMVAV2_down_lfstats2;
   Float_t         btagWeightCSV_up_hfstats1;
   Float_t         btagWeightCMVAV2_down_jes;
   Float_t         btagWeightCSV_up_hfstats2;
   Int_t           Flag_HBHENoiseIsoFilter;
   Int_t           Flag_EcalDeadCellTriggerPrimitiveFilter;
   Int_t           Flag_trkPOG_manystripclus53X;
   Int_t           Flag_ecalLaserCorrFilter;
   Int_t           Flag_trkPOG_toomanystripclus53X;
   Int_t           Flag_hcalLaserEventFilter;
   Int_t           Flag_muonBadTrackFilter;
   Int_t           Flag_trkPOG_logErrorTooManyClusters;
   Int_t           Flag_trkPOGFilters;
   Int_t           Flag_trackingFailureFilter;
   Int_t           Flag_CSCTightHaloFilter;
   Int_t           Flag_HBHENoiseFilter;
   Int_t           Flag_chargedHadronTrackResolutionFilter;
   Int_t           Flag_goodVertices;
   Int_t           Flag_METFilters;
   Int_t           Flag_CSCTightHalo2015Filter;
   Int_t           Flag_eeBadScFilter;
   Int_t           HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_BTagCSV_p067_v;
   Int_t           HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMET170_NoiseCleaned_v;
   Int_t           HLT_BIT_HLT_DiCentralPFJet55_PFMET110_v;
   Int_t           HLT_BIT_HLT_PFHT350_PFMET100_v;
   Int_t           HLT_ZnnHbbAll;
   Int_t           HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq200_v;
   Int_t           HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq460_v;
   Int_t           HLT_VBFHbbLowLumi;
   Int_t           HLT_BIT_HLT_PFHT750_4JetPt50_v;
   Int_t           HLT_BIT_HLT_PFHT800_v;
   Int_t           HLT_BIT_HLT_PFJet40_v;
   Int_t           HLT_BIT_HLT_PFJet60_v;
   Int_t           HLT_BIT_HLT_PFJet80_v;
   Int_t           HLT_BIT_HLT_PFJet140_v;
   Int_t           HLT_BIT_HLT_PFJet200_v;
   Int_t           HLT_BIT_HLT_PFJet260_v;
   Int_t           HLT_BIT_HLT_PFJet320_v;
   Int_t           HLT_BIT_HLT_PFJet400_v;
   Int_t           HLT_BIT_HLT_PFJet450_v;
   Int_t           HLT_BIT_HLT_DiPFJetAve40_v;
   Int_t           HLT_BIT_HLT_DiPFJetAve60_v;
   Int_t           HLT_BIT_HLT_DiPFJetAve80_v;
   Int_t           HLT_BIT_HLT_DiPFJetAve140_v;
   Int_t           HLT_BIT_HLT_DiPFJetAve200_v;
   Int_t           HLT_BIT_HLT_DiPFJetAve260_v;
   Int_t           HLT_BIT_HLT_DiPFJetAve320_v;
   Int_t           HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p026_DoublePFJetsC160_v;
   Int_t           HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p014_DoublePFJetsC100MaxDeta1p6_v;
   Int_t           HLT_hadronic;
   Int_t           HLT_BIT_HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v;
   Int_t           HLT_BIT_HLT_PFHT450_SixJet40_BTagCSV_p056_v;
   Int_t           HLT_ttHhardonicLowLumi;
   Int_t           HLT_BIT_HLT_QuadJet45_TripleBTagCSV_p087_v;
   Int_t           HLT_BIT_HLT_QuadJet45_DoubleBTagCSV_p087_v;
   Int_t           HLT_BIT_HLT_DoubleJet90_Double30_TripleBTagCSV_p087_v;
   Int_t           HLT_BIT_HLT_DoubleJet90_Double30_DoubleBTagCSV_p087_v;
   Int_t           HLT_BIT_HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v;
   Int_t           HLT_BIT_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v;
   Int_t           HLT_BIT_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v;
   Int_t           HLT_BIT_HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v;
   Int_t           HLT_BIT_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v;
   Int_t           HLT_BIT_HLT_AK8PFJet360_TrimMass30_v;
   Int_t           HLT_HH4bAll;
   Int_t           HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET80_v;
   Int_t           HLT_WtaunHbbLowLumi;
   Int_t           HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;
   Int_t           HLT_BIT_HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v;
   Int_t           HLT_ZeeHbbHighLumi;
   Int_t           HLT_HH4bHighLumi;
   Int_t           HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq240_v;
   Int_t           HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq500_v;
   Int_t           HLT_BIT_HLT_QuadPFJet_VBF_v;
   Int_t           HLT_BIT_HLT_L1_TripleJet_VBF_v;
   Int_t           HLT_BIT_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v;
   Int_t           HLT_BIT_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v;
   Int_t           HLT_VBFHbbAll;
   Int_t           HLT_BIT_HLT_Ele27_eta2p1_WPTight_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_HT200_v;
   Int_t           HLT_WenHbbLowLumi;
   Int_t           HLT_BIT_HLT_Ele32_eta2p1_WPTight_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele105_CaloIdVT_GsfTrkIdT_v;
   Int_t           HLT_BIT_HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v;
   Int_t           HLT_BIT_HLT_Ele27_WPLoose_Gsf_WHbbBoost_v;
   Int_t           HLT_BIT_HLT_Ele22_eta2p1_WPLoose_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele23_WPLoose_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele27_WPLoose_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele23_WPLoose_Gsf_WHbbBoost_v;
   Int_t           HLT_BIT_HLT_Ele25_WPTight_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v;
   Int_t           HLT_WenHbbAll;
   Int_t           HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;
   Int_t           HLT_ZeeHbbLowLumi;
   Int_t           HLT_BIT_HLT_Mu24_eta2p1_v;
   Int_t           HLT_BIT_HLT_TkMu24_eta2p1_v;
   Int_t           HLT_BIT_HLT_IsoMu27_v;
   Int_t           HLT_BIT_HLT_IsoTkMu27_v;
   Int_t           HLT_BIT_HLT_TkMu27_v;
   Int_t           HLT_BIT_HLT_Mu27_v;
   Int_t           HLT_BIT_HLT_IsoMu20_v;
   Int_t           HLT_BIT_HLT_Mu20_v;
   Int_t           HLT_BIT_HLT_TkMu20_v;
   Int_t           HLT_BIT_HLT_IsoTkMu20_v;
   Int_t           HLT_BIT_HLT_IsoMu18_v;
   Int_t           HLT_BIT_HLT_IsoTkMu18_v;
   Int_t           HLT_BIT_HLT_Mu40_eta2p1_PFJet200_PFJet50_v;
   Int_t           HLT_BIT_HLT_IsoMu16_eta2p1_MET30_v;
   Int_t           HLT_BIT_HLT_Mu16_eta2p1_MET30_v;
   Int_t           HLT_BIT_HLT_PFMET120_Mu5_v;
   Int_t           HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_v;
   Int_t           HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v;
   Int_t           HLT_WmnHbbAll;
   Int_t           HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v;
   Int_t           HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_v;
   Int_t           HLT_WtaunHbbAll;
   Int_t           HLT_BIT_HLT_PFHT450_SixJet40_v;
   Int_t           HLT_BIT_HLT_PFHT400_SixJet30_v;
   Int_t           HLT_BIT_HLT_PFHT350_v;
   Int_t           HLT_ttHhardonicAll;
   Int_t           HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v;
   Int_t           HLT_BIT_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v;
   Int_t           HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v;
   Int_t           HLT_BIT_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v;
   Int_t           HLT_BIT_HLT_Ele30WP60_Ele8_Mass55_v;
   Int_t           HLT_ZeeHbbAll;
   Int_t           HLT_WmnHbbLowLumi;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v;
   Int_t           HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v;
   Int_t           HLT_ttHleptonic;
   Int_t           HLT_VBFHbbHighLumi;
   Int_t           HLT_ZnnHbb;
   Int_t           HLT_ZmmHbbLowLumi;
   Int_t           HLT_BIT_HLT_IsoMu24_v;
   Int_t           HLT_WmnHbbHighLumi;
   Int_t           HLT_BIT_HLT_Mu17_TkMu8_DZ_v;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v;
   Int_t           HLT_BIT_HLT_DoubleIsoMu17_eta2p1_v;
   Int_t           HLT_ZmmHbbAll;
   Int_t           HLT_WenHbbHighLumi;
   Int_t           HLT_HH4bLowLumi;
   Int_t           HLT_ZmmHbbHighLumi;
   Int_t           HLT_ttHhardonicHighLumi;
   Int_t           HLT_WtaunHbbHighLumi;
   Float_t         H_reg_corrJECUp_pt;
   Float_t         H_reg_corrJECUp_eta;
   Float_t         H_reg_corrJECUp_phi;
   Float_t         H_reg_corrJECUp_mass;
   Float_t         HaddJetsdR08_pt;
   Float_t         HaddJetsdR08_eta;
   Float_t         HaddJetsdR08_phi;
   Float_t         HaddJetsdR08_mass;
   Float_t         H_pt;
   Float_t         H_eta;
   Float_t         H_phi;
   Float_t         H_mass;
   Int_t           softActivityVH_njets2;
   Int_t           softActivityVH_njets5;
   Int_t           softActivityVH_njets10;
   Float_t         softActivityVH_HT;
   Float_t         met_shifted_JetResUp_pt;
   Float_t         met_shifted_JetResUp_phi;
   Float_t         met_shifted_JetResUp_sumEt;
   Float_t         met_pt;
   Float_t         met_eta;
   Float_t         met_phi;
   Float_t         met_mass;
   Float_t         met_sumEt;
   Float_t         met_rawPt;
   Float_t         met_rawPhi;
   Float_t         met_rawSumEt;
   Float_t         met_genPt;
   Float_t         met_genPhi;
   Float_t         met_genEta;
   Float_t         H_reg_pt;
   Float_t         H_reg_eta;
   Float_t         H_reg_phi;
   Float_t         H_reg_mass;
   Float_t         HCSV_reg_corrJERDown_pt;
   Float_t         HCSV_reg_corrJERDown_eta;
   Float_t         HCSV_reg_corrJERDown_phi;
   Float_t         HCSV_reg_corrJERDown_mass;
   Float_t         HCSV_pt;
   Float_t         HCSV_eta;
   Float_t         HCSV_phi;
   Float_t         HCSV_mass;
   Float_t         met_shifted_MuonEnDown_pt;
   Float_t         met_shifted_MuonEnDown_phi;
   Float_t         met_shifted_MuonEnDown_sumEt;
   Float_t         met_shifted_ElectronEnUp_pt;
   Float_t         met_shifted_ElectronEnUp_phi;
   Float_t         met_shifted_ElectronEnUp_sumEt;
   Float_t         met_shifted_ElectronEnDown_pt;
   Float_t         met_shifted_ElectronEnDown_phi;
   Float_t         met_shifted_ElectronEnDown_sumEt;
   Float_t         fakeMET_pt;
   Float_t         fakeMET_eta;
   Float_t         fakeMET_phi;
   Float_t         fakeMET_mass;
   Float_t         met_shifted_TauEnDown_pt;
   Float_t         met_shifted_TauEnDown_phi;
   Float_t         met_shifted_TauEnDown_sumEt;
   Float_t         V_pt;
   Float_t         V_eta;
   Float_t         V_phi;
   Float_t         V_mass;
   Float_t         HCSV_reg_corrJERUp_pt;
   Float_t         HCSV_reg_corrJERUp_eta;
   Float_t         HCSV_reg_corrJERUp_phi;
   Float_t         HCSV_reg_corrJERUp_mass;
   Float_t         met_shifted_TauEnUp_pt;
   Float_t         met_shifted_TauEnUp_phi;
   Float_t         met_shifted_TauEnUp_sumEt;
   Float_t         HCSV_reg_corrJECUp_pt;
   Float_t         HCSV_reg_corrJECUp_eta;
   Float_t         HCSV_reg_corrJECUp_phi;
   Float_t         HCSV_reg_corrJECUp_mass;
   Float_t         met_shifted_UnclusteredEnUp_pt;
   Float_t         met_shifted_UnclusteredEnUp_phi;
   Float_t         met_shifted_UnclusteredEnUp_sumEt;
   Float_t         met_shifted_UnclusteredEnDown_pt;
   Float_t         met_shifted_UnclusteredEnDown_phi;
   Float_t         met_shifted_UnclusteredEnDown_sumEt;
   Float_t         met_shifted_JetEnUp_pt;
   Float_t         met_shifted_JetEnUp_phi;
   Float_t         met_shifted_JetEnUp_sumEt;
   Float_t         H_reg_corrJERDown_pt;
   Float_t         H_reg_corrJERDown_eta;
   Float_t         H_reg_corrJERDown_phi;
   Float_t         H_reg_corrJERDown_mass;
   Float_t         HCSV_reg_pt;
   Float_t         HCSV_reg_eta;
   Float_t         HCSV_reg_phi;
   Float_t         HCSV_reg_mass;
   Float_t         met_shifted_JetEnDown_pt;
   Float_t         met_shifted_JetEnDown_phi;
   Float_t         met_shifted_JetEnDown_sumEt;
   Float_t         met_shifted_JetResDown_pt;
   Float_t         met_shifted_JetResDown_phi;
   Float_t         met_shifted_JetResDown_sumEt;
   Int_t           softActivity_njets2;
   Int_t           softActivity_njets5;
   Int_t           softActivity_njets10;
   Float_t         softActivity_HT;
   Float_t         met_shifted_MuonEnUp_pt;
   Float_t         met_shifted_MuonEnUp_phi;
   Float_t         met_shifted_MuonEnUp_sumEt;
   Float_t         HCSV_reg_corrJECDown_pt;
   Float_t         HCSV_reg_corrJECDown_eta;
   Float_t         HCSV_reg_corrJECDown_phi;
   Float_t         HCSV_reg_corrJECDown_mass;
   Float_t         H_reg_corrJERUp_pt;
   Float_t         H_reg_corrJERUp_eta;
   Float_t         H_reg_corrJERUp_phi;
   Float_t         H_reg_corrJERUp_mass;
   Float_t         H_reg_corrJECDown_pt;
   Float_t         H_reg_corrJECDown_eta;
   Float_t         H_reg_corrJECDown_phi;
   Float_t         H_reg_corrJECDown_mass;
   Int_t           nGenBQuarkFromHafterISR;
   Int_t           GenBQuarkFromHafterISR_pdgId[1];   //[nGenBQuarkFromHafterISR]
   Float_t         GenBQuarkFromHafterISR_pt[1];   //[nGenBQuarkFromHafterISR]
   Float_t         GenBQuarkFromHafterISR_eta[1];   //[nGenBQuarkFromHafterISR]
   Float_t         GenBQuarkFromHafterISR_phi[1];   //[nGenBQuarkFromHafterISR]
   Float_t         GenBQuarkFromHafterISR_mass[1];   //[nGenBQuarkFromHafterISR]
   Float_t         GenBQuarkFromHafterISR_charge[1];   //[nGenBQuarkFromHafterISR]
   Int_t           GenBQuarkFromHafterISR_status[1];   //[nGenBQuarkFromHafterISR]
   Int_t           GenBQuarkFromHafterISR_isPromptHard[1];   //[nGenBQuarkFromHafterISR]
   Int_t           npileUpVertex_ptHat;
   Float_t         pileUpVertex_ptHat[5];   //[npileUpVertex_ptHat]
   Int_t           ntrgObjects_hltMET70;
   Int_t           ntrgObjects_hltL1sTripleJetVBFIorHTTIorDoubleJetCIorSingleJet;
   Int_t           ntrgObjects_hltBTagPFCSVp11DoubleWithMatching;
   Int_t           nGenLepFromTop;
   Int_t           GenLepFromTop_pdgId[2];   //[nGenLepFromTop]
   Float_t         GenLepFromTop_pt[2];   //[nGenLepFromTop]
   Float_t         GenLepFromTop_eta[2];   //[nGenLepFromTop]
   Float_t         GenLepFromTop_phi[2];   //[nGenLepFromTop]
   Float_t         GenLepFromTop_mass[2];   //[nGenLepFromTop]
   Float_t         GenLepFromTop_charge[2];   //[nGenLepFromTop]
   Int_t           GenLepFromTop_status[2];   //[nGenLepFromTop]
   Int_t           GenLepFromTop_isPromptHard[2];   //[nGenLepFromTop]
   Int_t           najidxaddJetsdR08;
   Int_t           ajidxaddJetsdR08[8];   //[najidxaddJetsdR08]
   Int_t           nSubjetCA15softdrop;
   Float_t         SubjetCA15softdrop_pt[10];   //[nSubjetCA15softdrop]
   Float_t         SubjetCA15softdrop_eta[10];   //[nSubjetCA15softdrop]
   Float_t         SubjetCA15softdrop_phi[10];   //[nSubjetCA15softdrop]
   Float_t         SubjetCA15softdrop_mass[10];   //[nSubjetCA15softdrop]
   Float_t         SubjetCA15softdrop_btag[10];   //[nSubjetCA15softdrop]
   Float_t         SubjetCA15softdrop_jetID[10];   //[nSubjetCA15softdrop]
   Float_t         SubjetCA15softdrop_fromFJ[10];   //[nSubjetCA15softdrop]
   Int_t           ntrgObjects_hltIsoMu20;
   Float_t         trgObjects_hltIsoMu20_pt[1];   //[ntrgObjects_hltIsoMu20]
   Float_t         trgObjects_hltIsoMu20_eta[1];   //[ntrgObjects_hltIsoMu20]
   Float_t         trgObjects_hltIsoMu20_phi[1];   //[ntrgObjects_hltIsoMu20]
   Float_t         trgObjects_hltIsoMu20_mass[1];   //[ntrgObjects_hltIsoMu20]
   Int_t           ntrgObjects_hltQuadCentralJet30;
   Int_t           nGenVbosonsRecovered;
   Int_t           GenVbosonsRecovered_pdgId[1];   //[nGenVbosonsRecovered]
   Float_t         GenVbosonsRecovered_pt[1];   //[nGenVbosonsRecovered]
   Float_t         GenVbosonsRecovered_eta[1];   //[nGenVbosonsRecovered]
   Float_t         GenVbosonsRecovered_phi[1];   //[nGenVbosonsRecovered]
   Float_t         GenVbosonsRecovered_mass[1];   //[nGenVbosonsRecovered]
   Float_t         GenVbosonsRecovered_charge[1];   //[nGenVbosonsRecovered]
   Int_t           GenVbosonsRecovered_status[1];   //[nGenVbosonsRecovered]
   Int_t           GenVbosonsRecovered_isPromptHard[1];   //[nGenVbosonsRecovered]
   Int_t           nhJidx_sortcsv;
   Int_t           hJidx_sortcsv[2];   //[nhJidx_sortcsv]
   Int_t           ntrgObjects_hltL1sQuadJetCIorTripleJetVBFIorHTT;
   Int_t           nGenTausRecovered;
   Int_t           GenTausRecovered_pdgId[1];   //[nGenTausRecovered]
   Float_t         GenTausRecovered_pt[1];   //[nGenTausRecovered]
   Float_t         GenTausRecovered_eta[1];   //[nGenTausRecovered]
   Float_t         GenTausRecovered_phi[1];   //[nGenTausRecovered]
   Float_t         GenTausRecovered_mass[1];   //[nGenTausRecovered]
   Float_t         GenTausRecovered_charge[1];   //[nGenTausRecovered]
   Int_t           GenTausRecovered_status[1];   //[nGenTausRecovered]
   Int_t           GenTausRecovered_isPromptHard[1];   //[nGenTausRecovered]
   Int_t           nSubjetCA15softdropz2b1;
   Float_t         SubjetCA15softdropz2b1_pt[10];   //[nSubjetCA15softdropz2b1]
   Float_t         SubjetCA15softdropz2b1_eta[10];   //[nSubjetCA15softdropz2b1]
   Float_t         SubjetCA15softdropz2b1_phi[10];   //[nSubjetCA15softdropz2b1]
   Float_t         SubjetCA15softdropz2b1_mass[10];   //[nSubjetCA15softdropz2b1]
   Float_t         SubjetCA15softdropz2b1_btag[10];   //[nSubjetCA15softdropz2b1]
   Float_t         SubjetCA15softdropz2b1_jetID[10];   //[nSubjetCA15softdropz2b1]
   Float_t         SubjetCA15softdropz2b1_fromFJ[10];   //[nSubjetCA15softdropz2b1]
   Int_t           nhJCidx;
   Int_t           hJCidx[2];   //[nhJCidx]
   Int_t           nGenTop;
   Float_t         GenTop_charge[2];   //[nGenTop]
   Int_t           GenTop_status[2];   //[nGenTop]
   Int_t           GenTop_isPromptHard[2];   //[nGenTop]
   Int_t           GenTop_pdgId[2];   //[nGenTop]
   Float_t         GenTop_pt[2];   //[nGenTop]
   Float_t         GenTop_eta[2];   //[nGenTop]
   Float_t         GenTop_phi[2];   //[nGenTop]
   Float_t         GenTop_mass[2];   //[nGenTop]
   Int_t           GenTop_decayMode[2];   //[nGenTop]
   Int_t           naJidx;
   Int_t           aJidx[8];   //[naJidx]
   Int_t           nGenLepFromTau;
   Int_t           GenLepFromTau_pdgId[1];   //[nGenLepFromTau]
   Float_t         GenLepFromTau_pt[1];   //[nGenLepFromTau]
   Float_t         GenLepFromTau_eta[1];   //[nGenLepFromTau]
   Float_t         GenLepFromTau_phi[1];   //[nGenLepFromTau]
   Float_t         GenLepFromTau_mass[1];   //[nGenLepFromTau]
   Float_t         GenLepFromTau_charge[1];   //[nGenLepFromTau]
   Int_t           GenLepFromTau_status[1];   //[nGenLepFromTau]
   Int_t           GenLepFromTau_isPromptHard[1];   //[nGenLepFromTau]
   Int_t           nGenNuFromTop;
   Int_t           GenNuFromTop_pdgId[2];   //[nGenNuFromTop]
   Float_t         GenNuFromTop_pt[2];   //[nGenNuFromTop]
   Float_t         GenNuFromTop_eta[2];   //[nGenNuFromTop]
   Float_t         GenNuFromTop_phi[2];   //[nGenNuFromTop]
   Float_t         GenNuFromTop_mass[2];   //[nGenNuFromTop]
   Float_t         GenNuFromTop_charge[2];   //[nGenNuFromTop]
   Int_t           GenNuFromTop_status[2];   //[nGenNuFromTop]
   Int_t           GenNuFromTop_isPromptHard[2];   //[nGenNuFromTop]
   Int_t           ntrgObjects_hltPFDoubleJetLooseID76;
   Int_t           ntrgObjects_hltBTagPFCSVp016SingleWithMatching;
   Int_t           nGenVbosons;
   Int_t           GenVbosons_pdgId[2];   //[nGenVbosons]
   Float_t         GenVbosons_pt[2];   //[nGenVbosons]
   Float_t         GenVbosons_eta[2];   //[nGenVbosons]
   Float_t         GenVbosons_phi[2];   //[nGenVbosons]
   Float_t         GenVbosons_mass[2];   //[nGenVbosons]
   Float_t         GenVbosons_charge[2];   //[nGenVbosons]
   Int_t           GenVbosons_status[2];   //[nGenVbosons]
   Int_t           GenVbosons_isPromptHard[2];   //[nGenVbosons]
   Int_t           nsoftActivityVHJets;
   Float_t         softActivityVHJets_pt[5];   //[nsoftActivityVHJets]
   Float_t         softActivityVHJets_eta[5];   //[nsoftActivityVHJets]
   Float_t         softActivityVHJets_phi[5];   //[nsoftActivityVHJets]
   Float_t         softActivityVHJets_mass[5];   //[nsoftActivityVHJets]
   Int_t           ntrgObjects_hltQuadPFCentralJetLooseID30;
   Int_t           ntrgObjects_caloMhtNoPU;
   Float_t         trgObjects_caloMhtNoPU_pt[1];   //[ntrgObjects_caloMhtNoPU]
   Int_t           ntrgObjects_hltEle25eta2p1WPLoose;
   Float_t         trgObjects_hltEle25eta2p1WPLoose_pt[1];   //[ntrgObjects_hltEle25eta2p1WPLoose]
   Float_t         trgObjects_hltEle25eta2p1WPLoose_eta[1];   //[ntrgObjects_hltEle25eta2p1WPLoose]
   Float_t         trgObjects_hltEle25eta2p1WPLoose_phi[1];   //[ntrgObjects_hltEle25eta2p1WPLoose]
   Float_t         trgObjects_hltEle25eta2p1WPLoose_mass[1];   //[ntrgObjects_hltEle25eta2p1WPLoose]
   Int_t           nSubjetAK08softdrop;
   Float_t         SubjetAK08softdrop_pt[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_eta[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_phi[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_mass[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_btag[10];   //[nSubjetAK08softdrop]
   Int_t           ntrgObjects_hltDoublePFCentralJetLooseID90;
   Int_t           nGenLep;
   Int_t           GenLep_pdgId[2];   //[nGenLep]
   Float_t         GenLep_pt[2];   //[nGenLep]
   Float_t         GenLep_eta[2];   //[nGenLep]
   Float_t         GenLep_phi[2];   //[nGenLep]
   Float_t         GenLep_mass[2];   //[nGenLep]
   Float_t         GenLep_charge[2];   //[nGenLep]
   Int_t           GenLep_status[2];   //[nGenLep]
   Int_t           GenLep_isPromptHard[2];   //[nGenLep]
   Int_t           ntrgObjects_caloJets;
   Float_t         trgObjects_caloJets_pt[5];   //[ntrgObjects_caloJets]
   Int_t           ntrgObjects_hltPFSingleJetLooseID92;
   Int_t           nGenHadTaus;
   Float_t         GenHadTaus_charge[4];   //[nGenHadTaus]
   Int_t           GenHadTaus_status[4];   //[nGenHadTaus]
   Int_t           GenHadTaus_isPromptHard[4];   //[nGenHadTaus]
   Int_t           GenHadTaus_pdgId[4];   //[nGenHadTaus]
   Float_t         GenHadTaus_pt[4];   //[nGenHadTaus]
   Float_t         GenHadTaus_eta[4];   //[nGenHadTaus]
   Float_t         GenHadTaus_phi[4];   //[nGenHadTaus]
   Float_t         GenHadTaus_mass[4];   //[nGenHadTaus]
   Int_t           GenHadTaus_decayMode[4];   //[nGenHadTaus]
   Int_t           ntrgObjects_hltL1sETM50ToETM100IorETM60Jet60dPhiMin0p4IorDoubleJetC60ETM60;
   Int_t           ntrgObjects_hltEle25WPTight;
   Float_t         trgObjects_hltEle25WPTight_pt[1];   //[ntrgObjects_hltEle25WPTight]
   Float_t         trgObjects_hltEle25WPTight_eta[1];   //[ntrgObjects_hltEle25WPTight]
   Float_t         trgObjects_hltEle25WPTight_phi[1];   //[ntrgObjects_hltEle25WPTight]
   Float_t         trgObjects_hltEle25WPTight_mass[1];   //[ntrgObjects_hltEle25WPTight]
   Int_t           ntrgObjects_pfJets;
   Float_t         trgObjects_pfJets_pt[5];   //[ntrgObjects_pfJets]
   Int_t           nSubjetCA15subjetfiltered;
   Float_t         SubjetCA15subjetfiltered_pt[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_eta[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_phi[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_mass[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_btag[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_jetID[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_fromFJ[30];   //[nSubjetCA15subjetfiltered]
   Int_t           nvLeptons;
   Int_t           vLeptons_charge[2];   //[nvLeptons]
   Int_t           vLeptons_tightId[2];   //[nvLeptons]
   Int_t           vLeptons_eleCutIdCSA14_25ns_v1[2];   //[nvLeptons]
   Int_t           vLeptons_eleCutIdCSA14_50ns_v1[2];   //[nvLeptons]
   Int_t           vLeptons_eleCutIdSpring15_25ns_v1[2];   //[nvLeptons]
   Float_t         vLeptons_dxy[2];   //[nvLeptons]
   Float_t         vLeptons_dz[2];   //[nvLeptons]
   Float_t         vLeptons_edxy[2];   //[nvLeptons]
   Float_t         vLeptons_edz[2];   //[nvLeptons]
   Float_t         vLeptons_ip3d[2];   //[nvLeptons]
   Float_t         vLeptons_sip3d[2];   //[nvLeptons]
   Int_t           vLeptons_convVeto[2];   //[nvLeptons]
   Int_t           vLeptons_lostHits[2];   //[nvLeptons]
   Float_t         vLeptons_relIso03[2];   //[nvLeptons]
   Float_t         vLeptons_relIso04[2];   //[nvLeptons]
   Float_t         vLeptons_miniRelIso[2];   //[nvLeptons]
   Float_t         vLeptons_relIsoAn04[2];   //[nvLeptons]
   Int_t           vLeptons_tightCharge[2];   //[nvLeptons]
   Int_t           vLeptons_mcMatchId[2];   //[nvLeptons]
   Int_t           vLeptons_mcMatchAny[2];   //[nvLeptons]
   Int_t           vLeptons_mcMatchTau[2];   //[nvLeptons]
   Float_t         vLeptons_mcPt[2];   //[nvLeptons]
   Int_t           vLeptons_mediumMuonId[2];   //[nvLeptons]
   Int_t           vLeptons_pdgId[2];   //[nvLeptons]
   Float_t         vLeptons_pt[2];   //[nvLeptons]
   Float_t         vLeptons_eta[2];   //[nvLeptons]
   Float_t         vLeptons_phi[2];   //[nvLeptons]
   Float_t         vLeptons_mass[2];   //[nvLeptons]
   Int_t           vLeptons_looseIdSusy[2];   //[nvLeptons]
   Int_t           vLeptons_looseIdPOG[2];   //[nvLeptons]
   Float_t         vLeptons_chargedHadRelIso03[2];   //[nvLeptons]
   Float_t         vLeptons_chargedHadRelIso04[2];   //[nvLeptons]
   Float_t         vLeptons_eleSieie[2];   //[nvLeptons]
   Float_t         vLeptons_eleDEta[2];   //[nvLeptons]
   Float_t         vLeptons_eleDPhi[2];   //[nvLeptons]
   Float_t         vLeptons_eleHoE[2];   //[nvLeptons]
   Float_t         vLeptons_eleMissingHits[2];   //[nvLeptons]
   Float_t         vLeptons_eleChi2[2];   //[nvLeptons]
   Int_t           vLeptons_convVetoFull[2];   //[nvLeptons]
   Float_t         vLeptons_eleMVArawSpring15Trig[2];   //[nvLeptons]
   Int_t           vLeptons_eleMVAIdSpring15Trig[2];   //[nvLeptons]
   Float_t         vLeptons_eleMVArawSpring15NonTrig[2];   //[nvLeptons]
   Int_t           vLeptons_eleMVAIdSpring15NonTrig[2];   //[nvLeptons]
   Float_t         vLeptons_nStations[2];   //[nvLeptons]
   Float_t         vLeptons_trkKink[2];   //[nvLeptons]
   Float_t         vLeptons_segmentCompatibility[2];   //[nvLeptons]
   Float_t         vLeptons_caloCompatibility[2];   //[nvLeptons]
   Float_t         vLeptons_globalTrackChi2[2];   //[nvLeptons]
   Float_t         vLeptons_nChamberHits[2];   //[nvLeptons]
   Float_t         vLeptons_isPFMuon[2];   //[nvLeptons]
   Float_t         vLeptons_isGlobalMuon[2];   //[nvLeptons]
   Float_t         vLeptons_isTrackerMuon[2];   //[nvLeptons]
   Float_t         vLeptons_pixelHits[2];   //[nvLeptons]
   Int_t           vLeptons_trackerLayers[2];   //[nvLeptons]
   Int_t           vLeptons_pixelLayers[2];   //[nvLeptons]
   Float_t         vLeptons_mvaTTH[2];   //[nvLeptons]
   Int_t           vLeptons_jetOverlapIdx[2];   //[nvLeptons]
   Float_t         vLeptons_jetPtRatio[2];   //[nvLeptons]
   Float_t         vLeptons_jetBTagCSV[2];   //[nvLeptons]
   Float_t         vLeptons_jetDR[2];   //[nvLeptons]
   Float_t         vLeptons_mvaTTHjetPtRatio[2];   //[nvLeptons]
   Float_t         vLeptons_mvaTTHjetBTagCSV[2];   //[nvLeptons]
   Float_t         vLeptons_mvaTTHjetDR[2];   //[nvLeptons]
   Float_t         vLeptons_pfRelIso03[2];   //[nvLeptons]
   Float_t         vLeptons_pfRelIso04[2];   //[nvLeptons]
   Float_t         vLeptons_etaSc[2];   //[nvLeptons]
   Float_t         vLeptons_eleExpMissingInnerHits[2];   //[nvLeptons]
   Float_t         vLeptons_eleooEmooP[2];   //[nvLeptons]
   Float_t         vLeptons_dr03TkSumPt[2];   //[nvLeptons]
   Float_t         vLeptons_eleEcalClusterIso[2];   //[nvLeptons]
   Float_t         vLeptons_eleHcalClusterIso[2];   //[nvLeptons]
   Float_t         vLeptons_miniIsoCharged[2];   //[nvLeptons]
   Float_t         vLeptons_miniIsoNeutral[2];   //[nvLeptons]
   Float_t         vLeptons_mvaTTHjetPtRel[2];   //[nvLeptons]
   Float_t         vLeptons_mvaTTHjetNDauChargedMVASel[2];   //[nvLeptons]
   Float_t         vLeptons_uncalibratedPt[2];   //[nvLeptons]
   Float_t         vLeptons_SF_IsoLoose[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_IsoLoose[2];   //[nvLeptons]
   Float_t         vLeptons_SF_IsoTight[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_IsoTight[2];   //[nvLeptons]
   Float_t         vLeptons_SF_IdCutLoose[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_IdCutLoose[2];   //[nvLeptons]
   Float_t         vLeptons_SF_IdCutTight[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_IdCutTight[2];   //[nvLeptons]
   Float_t         vLeptons_SF_IdMVALoose[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_IdMVALoose[2];   //[nvLeptons]
   Float_t         vLeptons_SF_IdMVATight[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_IdMVATight[2];   //[nvLeptons]
   Float_t         vLeptons_SF_HLT_RunD4p3[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_HLT_RunD4p3[2];   //[nvLeptons]
   Float_t         vLeptons_SF_HLT_RunD4p2[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_HLT_RunD4p2[2];   //[nvLeptons]
   Float_t         vLeptons_SF_HLT_RunC[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_HLT_RunC[2];   //[nvLeptons]
   Float_t         vLeptons_Eff_HLT_RunD4p3[2];   //[nvLeptons]
   Float_t         vLeptons_Efferr_HLT_RunD4p3[2];   //[nvLeptons]
   Float_t         vLeptons_Eff_HLT_RunD4p2[2];   //[nvLeptons]
   Float_t         vLeptons_Efferr_HLT_RunD4p2[2];   //[nvLeptons]
   Float_t         vLeptons_Eff_HLT_RunC[2];   //[nvLeptons]
   Float_t         vLeptons_Efferr_HLT_RunC[2];   //[nvLeptons]
   Int_t           ntrgObjects_hltBTagCaloCSVp014DoubleWithMatching;
   Float_t         trgObjects_hltBTagCaloCSVp014DoubleWithMatching_pt[1];   //[ntrgObjects_hltBTagCaloCSVp014DoubleWithMatching]
   Float_t         trgObjects_hltBTagCaloCSVp014DoubleWithMatching_eta[1];   //[ntrgObjects_hltBTagCaloCSVp014DoubleWithMatching]
   Float_t         trgObjects_hltBTagCaloCSVp014DoubleWithMatching_phi[1];   //[ntrgObjects_hltBTagCaloCSVp014DoubleWithMatching]
   Float_t         trgObjects_hltBTagCaloCSVp014DoubleWithMatching_mass[1];   //[ntrgObjects_hltBTagCaloCSVp014DoubleWithMatching]
   Int_t           npileUpVertex_z;
   Float_t         pileUpVertex_z[5];   //[npileUpVertex_z]
   Int_t           ntrgObjects_pfMht;
   Float_t         trgObjects_pfMht_pt[1];   //[ntrgObjects_pfMht]
   Int_t           nGenBQuarkFromTop;
   Int_t           GenBQuarkFromTop_pdgId[2];   //[nGenBQuarkFromTop]
   Float_t         GenBQuarkFromTop_pt[2];   //[nGenBQuarkFromTop]
   Float_t         GenBQuarkFromTop_eta[2];   //[nGenBQuarkFromTop]
   Float_t         GenBQuarkFromTop_phi[2];   //[nGenBQuarkFromTop]
   Float_t         GenBQuarkFromTop_mass[2];   //[nGenBQuarkFromTop]
   Float_t         GenBQuarkFromTop_charge[2];   //[nGenBQuarkFromTop]
   Int_t           GenBQuarkFromTop_status[2];   //[nGenBQuarkFromTop]
   Int_t           GenBQuarkFromTop_isPromptHard[2];   //[nGenBQuarkFromTop]
   Int_t           nGenHiggsBoson;
   Int_t           GenHiggsBoson_pdgId[1];   //[nGenHiggsBoson]
   Float_t         GenHiggsBoson_pt[1];   //[nGenHiggsBoson]
   Float_t         GenHiggsBoson_eta[1];   //[nGenHiggsBoson]
   Float_t         GenHiggsBoson_phi[1];   //[nGenHiggsBoson]
   Float_t         GenHiggsBoson_mass[1];   //[nGenHiggsBoson]
   Float_t         GenHiggsBoson_charge[1];   //[nGenHiggsBoson]
   Int_t           GenHiggsBoson_status[1];   //[nGenHiggsBoson]
   Int_t           GenHiggsBoson_isPromptHard[1];   //[nGenHiggsBoson]
   Int_t           nLHE_weights_scale;
   Int_t           LHE_weights_scale_id[6];   //[nLHE_weights_scale]
   Float_t         LHE_weights_scale_wgt[6];   //[nLHE_weights_scale]
   Int_t           nGenLepFromTauRecovered;
   Int_t           GenLepFromTauRecovered_pdgId[1];   //[nGenLepFromTauRecovered]
   Float_t         GenLepFromTauRecovered_pt[1];   //[nGenLepFromTauRecovered]
   Float_t         GenLepFromTauRecovered_eta[1];   //[nGenLepFromTauRecovered]
   Float_t         GenLepFromTauRecovered_phi[1];   //[nGenLepFromTauRecovered]
   Float_t         GenLepFromTauRecovered_mass[1];   //[nGenLepFromTauRecovered]
   Float_t         GenLepFromTauRecovered_charge[1];   //[nGenLepFromTauRecovered]
   Int_t           GenLepFromTauRecovered_status[1];   //[nGenLepFromTauRecovered]
   Int_t           GenLepFromTauRecovered_isPromptHard[1];   //[nGenLepFromTauRecovered]
   Int_t           nFatjetCA15pruned;
   Float_t         FatjetCA15pruned_pt[5];   //[nFatjetCA15pruned]
   Float_t         FatjetCA15pruned_eta[5];   //[nFatjetCA15pruned]
   Float_t         FatjetCA15pruned_phi[5];   //[nFatjetCA15pruned]
   Float_t         FatjetCA15pruned_mass[5];   //[nFatjetCA15pruned]
   Int_t           ntrgObjects_hltVBFCaloJetEtaSortedMqq150Deta1p5;
   Int_t           ntrgObjects_caloMht;
   Float_t         trgObjects_caloMht_pt[1];   //[ntrgObjects_caloMht]
   Int_t           ntrgObjects_hltDoubleCentralJet90;
   Int_t           nGenJet;
   Float_t         GenJet_charge[15];   //[nGenJet]
   Int_t           GenJet_status[15];   //[nGenJet]
   Int_t           GenJet_isPromptHard[15];   //[nGenJet]
   Int_t           GenJet_pdgId[15];   //[nGenJet]
   Float_t         GenJet_pt[15];   //[nGenJet]
   Float_t         GenJet_eta[15];   //[nGenJet]
   Float_t         GenJet_phi[15];   //[nGenJet]
   Float_t         GenJet_mass[15];   //[nGenJet]
   Int_t           GenJet_numBHadrons[15];   //[nGenJet]
   Int_t           GenJet_numCHadrons[15];   //[nGenJet]
   Int_t           GenJet_numBHadronsFromTop[15];   //[nGenJet]
   Int_t           GenJet_numCHadronsFromTop[15];   //[nGenJet]
   Int_t           GenJet_numBHadronsAfterTop[15];   //[nGenJet]
   Int_t           GenJet_numCHadronsAfterTop[15];   //[nGenJet]
   Float_t         GenJet_wNuPt[15];   //[nGenJet]
   Float_t         GenJet_wNuEta[15];   //[nGenJet]
   Float_t         GenJet_wNuPhi[15];   //[nGenJet]
   Float_t         GenJet_wNuM[15];   //[nGenJet]
   Int_t           ntrgObjects_hltDoublePFJetsC100;
   Float_t         trgObjects_hltDoublePFJetsC100_pt[1];   //[ntrgObjects_hltDoublePFJetsC100]
   Float_t         trgObjects_hltDoublePFJetsC100_eta[1];   //[ntrgObjects_hltDoublePFJetsC100]
   Float_t         trgObjects_hltDoublePFJetsC100_phi[1];   //[ntrgObjects_hltDoublePFJetsC100]
   Float_t         trgObjects_hltDoublePFJetsC100_mass[1];   //[ntrgObjects_hltDoublePFJetsC100]
   Int_t           nSubjetCA15pruned;
   Float_t         SubjetCA15pruned_pt[10];   //[nSubjetCA15pruned]
   Float_t         SubjetCA15pruned_eta[10];   //[nSubjetCA15pruned]
   Float_t         SubjetCA15pruned_phi[10];   //[nSubjetCA15pruned]
   Float_t         SubjetCA15pruned_mass[10];   //[nSubjetCA15pruned]
   Float_t         SubjetCA15pruned_btag[10];   //[nSubjetCA15pruned]
   Float_t         SubjetCA15pruned_jetID[10];   //[nSubjetCA15pruned]
   Float_t         SubjetCA15pruned_fromFJ[10];   //[nSubjetCA15pruned]
   Int_t           ntrgObjects_caloMet;
   Float_t         trgObjects_caloMet_pt[1];   //[ntrgObjects_caloMet]
   Int_t           nFatjetCA15ungroomed;
   Float_t         FatjetCA15ungroomed_pt[5];   //[nFatjetCA15ungroomed]
   Float_t         FatjetCA15ungroomed_eta[5];   //[nFatjetCA15ungroomed]
   Float_t         FatjetCA15ungroomed_phi[5];   //[nFatjetCA15ungroomed]
   Float_t         FatjetCA15ungroomed_mass[5];   //[nFatjetCA15ungroomed]
   Float_t         FatjetCA15ungroomed_tau1[5];   //[nFatjetCA15ungroomed]
   Float_t         FatjetCA15ungroomed_tau2[5];   //[nFatjetCA15ungroomed]
   Float_t         FatjetCA15ungroomed_tau3[5];   //[nFatjetCA15ungroomed]
   Float_t         FatjetCA15ungroomed_bbtag[5];   //[nFatjetCA15ungroomed]
   Int_t           ntrgObjects_pfMet;
   Float_t         trgObjects_pfMet_pt[1];   //[ntrgObjects_pfMet]
   Int_t           ntrgObjects_pfHt;
   Float_t         trgObjects_pfHt_pt[1];   //[ntrgObjects_pfHt]
   Int_t           ndRaddJetsdR08;
   Float_t         dRaddJetsdR08[5];   //[ndRaddJetsdR08]
   Int_t           nGenBQuarkFromH;
   Int_t           GenBQuarkFromH_pdgId[1];   //[nGenBQuarkFromH]
   Float_t         GenBQuarkFromH_pt[1];   //[nGenBQuarkFromH]
   Float_t         GenBQuarkFromH_eta[1];   //[nGenBQuarkFromH]
   Float_t         GenBQuarkFromH_phi[1];   //[nGenBQuarkFromH]
   Float_t         GenBQuarkFromH_mass[1];   //[nGenBQuarkFromH]
   Float_t         GenBQuarkFromH_charge[1];   //[nGenBQuarkFromH]
   Int_t           GenBQuarkFromH_status[1];   //[nGenBQuarkFromH]
   Int_t           GenBQuarkFromH_isPromptHard[1];   //[nGenBQuarkFromH]
   Int_t           ntrgObjects_hltDoubleJet65;
   Int_t           nFatjetCA15trimmed;
   Float_t         FatjetCA15trimmed_pt[5];   //[nFatjetCA15trimmed]
   Float_t         FatjetCA15trimmed_eta[5];   //[nFatjetCA15trimmed]
   Float_t         FatjetCA15trimmed_phi[5];   //[nFatjetCA15trimmed]
   Float_t         FatjetCA15trimmed_mass[5];   //[nFatjetCA15trimmed]
   Int_t           nGenHiggsSisters;
   Int_t           GenHiggsSisters_pdgId[1];   //[nGenHiggsSisters]
   Float_t         GenHiggsSisters_pt[1];   //[nGenHiggsSisters]
   Float_t         GenHiggsSisters_eta[1];   //[nGenHiggsSisters]
   Float_t         GenHiggsSisters_phi[1];   //[nGenHiggsSisters]
   Float_t         GenHiggsSisters_mass[1];   //[nGenHiggsSisters]
   Float_t         GenHiggsSisters_charge[1];   //[nGenHiggsSisters]
   Int_t           GenHiggsSisters_status[1];   //[nGenHiggsSisters]
   Int_t           GenHiggsSisters_isPromptHard[1];   //[nGenHiggsSisters]
   Int_t           ntrgObjects_hltBTagCaloCSVp026DoubleWithMatching;
   Float_t         trgObjects_hltBTagCaloCSVp026DoubleWithMatching_pt[1];   //[ntrgObjects_hltBTagCaloCSVp026DoubleWithMatching]
   Float_t         trgObjects_hltBTagCaloCSVp026DoubleWithMatching_eta[1];   //[ntrgObjects_hltBTagCaloCSVp026DoubleWithMatching]
   Float_t         trgObjects_hltBTagCaloCSVp026DoubleWithMatching_phi[1];   //[ntrgObjects_hltBTagCaloCSVp026DoubleWithMatching]
   Float_t         trgObjects_hltBTagCaloCSVp026DoubleWithMatching_mass[1];   //[ntrgObjects_hltBTagCaloCSVp026DoubleWithMatching]
   Int_t           naLeptons;
   Int_t           aLeptons_charge[8];   //[naLeptons]
   Int_t           aLeptons_tightId[8];   //[naLeptons]
   Int_t           aLeptons_eleCutIdCSA14_25ns_v1[8];   //[naLeptons]
   Int_t           aLeptons_eleCutIdCSA14_50ns_v1[8];   //[naLeptons]
   Int_t           aLeptons_eleCutIdSpring15_25ns_v1[8];   //[naLeptons]
   Float_t         aLeptons_dxy[8];   //[naLeptons]
   Float_t         aLeptons_dz[8];   //[naLeptons]
   Float_t         aLeptons_edxy[8];   //[naLeptons]
   Float_t         aLeptons_edz[8];   //[naLeptons]
   Float_t         aLeptons_ip3d[8];   //[naLeptons]
   Float_t         aLeptons_sip3d[8];   //[naLeptons]
   Int_t           aLeptons_convVeto[8];   //[naLeptons]
   Int_t           aLeptons_lostHits[8];   //[naLeptons]
   Float_t         aLeptons_relIso03[8];   //[naLeptons]
   Float_t         aLeptons_relIso04[8];   //[naLeptons]
   Float_t         aLeptons_miniRelIso[8];   //[naLeptons]
   Float_t         aLeptons_relIsoAn04[8];   //[naLeptons]
   Int_t           aLeptons_tightCharge[8];   //[naLeptons]
   Int_t           aLeptons_mcMatchId[8];   //[naLeptons]
   Int_t           aLeptons_mcMatchAny[8];   //[naLeptons]
   Int_t           aLeptons_mcMatchTau[8];   //[naLeptons]
   Float_t         aLeptons_mcPt[8];   //[naLeptons]
   Int_t           aLeptons_mediumMuonId[8];   //[naLeptons]
   Int_t           aLeptons_pdgId[8];   //[naLeptons]
   Float_t         aLeptons_pt[8];   //[naLeptons]
   Float_t         aLeptons_eta[8];   //[naLeptons]
   Float_t         aLeptons_phi[8];   //[naLeptons]
   Float_t         aLeptons_mass[8];   //[naLeptons]
   Int_t           aLeptons_looseIdSusy[8];   //[naLeptons]
   Int_t           aLeptons_looseIdPOG[8];   //[naLeptons]
   Float_t         aLeptons_chargedHadRelIso03[8];   //[naLeptons]
   Float_t         aLeptons_chargedHadRelIso04[8];   //[naLeptons]
   Float_t         aLeptons_eleSieie[8];   //[naLeptons]
   Float_t         aLeptons_eleDEta[8];   //[naLeptons]
   Float_t         aLeptons_eleDPhi[8];   //[naLeptons]
   Float_t         aLeptons_eleHoE[8];   //[naLeptons]
   Float_t         aLeptons_eleMissingHits[8];   //[naLeptons]
   Float_t         aLeptons_eleChi2[8];   //[naLeptons]
   Int_t           aLeptons_convVetoFull[8];   //[naLeptons]
   Float_t         aLeptons_eleMVArawSpring15Trig[8];   //[naLeptons]
   Int_t           aLeptons_eleMVAIdSpring15Trig[8];   //[naLeptons]
   Float_t         aLeptons_eleMVArawSpring15NonTrig[8];   //[naLeptons]
   Int_t           aLeptons_eleMVAIdSpring15NonTrig[8];   //[naLeptons]
   Float_t         aLeptons_nStations[8];   //[naLeptons]
   Float_t         aLeptons_trkKink[8];   //[naLeptons]
   Float_t         aLeptons_segmentCompatibility[8];   //[naLeptons]
   Float_t         aLeptons_caloCompatibility[8];   //[naLeptons]
   Float_t         aLeptons_globalTrackChi2[8];   //[naLeptons]
   Float_t         aLeptons_nChamberHits[8];   //[naLeptons]
   Float_t         aLeptons_isPFMuon[8];   //[naLeptons]
   Float_t         aLeptons_isGlobalMuon[8];   //[naLeptons]
   Float_t         aLeptons_isTrackerMuon[8];   //[naLeptons]
   Float_t         aLeptons_pixelHits[8];   //[naLeptons]
   Int_t           aLeptons_trackerLayers[8];   //[naLeptons]
   Int_t           aLeptons_pixelLayers[8];   //[naLeptons]
   Float_t         aLeptons_mvaTTH[8];   //[naLeptons]
   Int_t           aLeptons_jetOverlapIdx[8];   //[naLeptons]
   Float_t         aLeptons_jetPtRatio[8];   //[naLeptons]
   Float_t         aLeptons_jetBTagCSV[8];   //[naLeptons]
   Float_t         aLeptons_jetDR[8];   //[naLeptons]
   Float_t         aLeptons_mvaTTHjetPtRatio[8];   //[naLeptons]
   Float_t         aLeptons_mvaTTHjetBTagCSV[8];   //[naLeptons]
   Float_t         aLeptons_mvaTTHjetDR[8];   //[naLeptons]
   Float_t         aLeptons_pfRelIso03[8];   //[naLeptons]
   Float_t         aLeptons_pfRelIso04[8];   //[naLeptons]
   Float_t         aLeptons_etaSc[8];   //[naLeptons]
   Float_t         aLeptons_eleExpMissingInnerHits[8];   //[naLeptons]
   Float_t         aLeptons_eleooEmooP[8];   //[naLeptons]
   Float_t         aLeptons_dr03TkSumPt[8];   //[naLeptons]
   Float_t         aLeptons_eleEcalClusterIso[8];   //[naLeptons]
   Float_t         aLeptons_eleHcalClusterIso[8];   //[naLeptons]
   Float_t         aLeptons_miniIsoCharged[8];   //[naLeptons]
   Float_t         aLeptons_miniIsoNeutral[8];   //[naLeptons]
   Float_t         aLeptons_mvaTTHjetPtRel[8];   //[naLeptons]
   Float_t         aLeptons_mvaTTHjetNDauChargedMVASel[8];   //[naLeptons]
   Float_t         aLeptons_uncalibratedPt[8];   //[naLeptons]
   Float_t         aLeptons_SF_IsoLoose[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_IsoLoose[8];   //[naLeptons]
   Float_t         aLeptons_SF_IsoTight[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_IsoTight[8];   //[naLeptons]
   Float_t         aLeptons_SF_IdCutLoose[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_IdCutLoose[8];   //[naLeptons]
   Float_t         aLeptons_SF_IdCutTight[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_IdCutTight[8];   //[naLeptons]
   Float_t         aLeptons_SF_IdMVALoose[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_IdMVALoose[8];   //[naLeptons]
   Float_t         aLeptons_SF_IdMVATight[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_IdMVATight[8];   //[naLeptons]
   Float_t         aLeptons_SF_HLT_RunD4p3[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_HLT_RunD4p3[8];   //[naLeptons]
   Float_t         aLeptons_SF_HLT_RunD4p2[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_HLT_RunD4p2[8];   //[naLeptons]
   Float_t         aLeptons_SF_HLT_RunC[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_HLT_RunC[8];   //[naLeptons]
   Float_t         aLeptons_Eff_HLT_RunD4p3[8];   //[naLeptons]
   Float_t         aLeptons_Efferr_HLT_RunD4p3[8];   //[naLeptons]
   Float_t         aLeptons_Eff_HLT_RunD4p2[8];   //[naLeptons]
   Float_t         aLeptons_Efferr_HLT_RunD4p2[8];   //[naLeptons]
   Float_t         aLeptons_Eff_HLT_RunC[8];   //[naLeptons]
   Float_t         aLeptons_Efferr_HLT_RunC[8];   //[naLeptons]
   Int_t           ntrgObjects_hltPFQuadJetLooseID15;
   Int_t           ntrgObjects_hltQuadPFCentralJetLooseID45;
   Int_t           ntrgObjects_hltBTagCaloCSVp067Single;
   Int_t           ntrgObjects_hltVBFPFJetCSVSortedMqq200Detaqq1p2;
   Int_t           nhjidxaddJetsdR08;
   Int_t           hjidxaddJetsdR08[5];   //[nhjidxaddJetsdR08]
   Int_t           ntrgObjects_hltMHTNoPU90;
   Int_t           nFatjetAK08ungroomed;
   Float_t         FatjetAK08ungroomed_pt[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_eta[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_phi[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_mass[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau1[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau2[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau3[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_msoftdrop[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_mpruned[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_mprunedcorr[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_JEC_L2L3[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_JEC_L1L2L3[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_JEC_L2L3Unc[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_JEC_L1L2L3Unc[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_bbtag[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_id_Tight[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_numberOfDaughters[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_neutralEmEnergyFraction[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_neutralHadronEnergyFraction[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_muonEnergyFraction[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_chargedEmEnergyFraction[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_chargedHadronEnergyFraction[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_chargedMultiplicity[5];   //[nFatjetAK08ungroomed]
   Int_t           FatjetAK08ungroomed_Flavour[5];   //[nFatjetAK08ungroomed]
   Int_t           FatjetAK08ungroomed_BhadronFlavour[5];   //[nFatjetAK08ungroomed]
   Int_t           FatjetAK08ungroomed_ChadronFlavour[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_GenPt[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_PFLepton_ptrel[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_z_ratio[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_PFLepton_IP2D[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_nSL[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau1_trackEtaRel_0[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau1_trackEtaRel_1[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau1_trackEtaRel_2[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau0_trackEtaRel_0[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau0_trackEtaRel_1[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau0_trackEtaRel_2[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau_vertexMass_0[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau_vertexEnergyRatio_0[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau_vertexDeltaR_0[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau_flightDistance2dSig_0[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau_vertexMass_1[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau_vertexEnergyRatio_1[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau_flightDistance2dSig_1[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_nSV[5];   //[nFatjetAK08ungroomed]
   Int_t           ntrgObjects_hltPFMHTTightID90;
   Int_t           ntrgObjects_hltQuadCentralJet45;
   Int_t           ntrgObjects_hltBTagCaloCSVp022Single;
   Int_t           naJCidx;
   Int_t           aJCidx[8];   //[naJCidx]
   Int_t           nselLeptons;
   Int_t           selLeptons_charge[3];   //[nselLeptons]
   Int_t           selLeptons_tightId[3];   //[nselLeptons]
   Int_t           selLeptons_eleCutIdCSA14_25ns_v1[3];   //[nselLeptons]
   Int_t           selLeptons_eleCutIdCSA14_50ns_v1[3];   //[nselLeptons]
   Int_t           selLeptons_eleCutIdSpring15_25ns_v1[3];   //[nselLeptons]
   Float_t         selLeptons_dxy[3];   //[nselLeptons]
   Float_t         selLeptons_dz[3];   //[nselLeptons]
   Float_t         selLeptons_edxy[3];   //[nselLeptons]
   Float_t         selLeptons_edz[3];   //[nselLeptons]
   Float_t         selLeptons_ip3d[3];   //[nselLeptons]
   Float_t         selLeptons_sip3d[3];   //[nselLeptons]
   Int_t           selLeptons_convVeto[3];   //[nselLeptons]
   Int_t           selLeptons_lostHits[3];   //[nselLeptons]
   Float_t         selLeptons_relIso03[3];   //[nselLeptons]
   Float_t         selLeptons_relIso04[3];   //[nselLeptons]
   Float_t         selLeptons_miniRelIso[3];   //[nselLeptons]
   Float_t         selLeptons_relIsoAn04[3];   //[nselLeptons]
   Int_t           selLeptons_tightCharge[3];   //[nselLeptons]
   Int_t           selLeptons_mcMatchId[3];   //[nselLeptons]
   Int_t           selLeptons_mcMatchAny[3];   //[nselLeptons]
   Int_t           selLeptons_mcMatchTau[3];   //[nselLeptons]
   Float_t         selLeptons_mcPt[3];   //[nselLeptons]
   Int_t           selLeptons_mediumMuonId[3];   //[nselLeptons]
   Int_t           selLeptons_pdgId[3];   //[nselLeptons]
   Float_t         selLeptons_pt[3];   //[nselLeptons]
   Float_t         selLeptons_eta[3];   //[nselLeptons]
   Float_t         selLeptons_phi[3];   //[nselLeptons]
   Float_t         selLeptons_mass[3];   //[nselLeptons]
   Int_t           selLeptons_looseIdSusy[3];   //[nselLeptons]
   Int_t           selLeptons_looseIdPOG[3];   //[nselLeptons]
   Float_t         selLeptons_chargedHadRelIso03[3];   //[nselLeptons]
   Float_t         selLeptons_chargedHadRelIso04[3];   //[nselLeptons]
   Float_t         selLeptons_eleSieie[3];   //[nselLeptons]
   Float_t         selLeptons_eleDEta[3];   //[nselLeptons]
   Float_t         selLeptons_eleDPhi[3];   //[nselLeptons]
   Float_t         selLeptons_eleHoE[3];   //[nselLeptons]
   Float_t         selLeptons_eleMissingHits[3];   //[nselLeptons]
   Float_t         selLeptons_eleChi2[3];   //[nselLeptons]
   Int_t           selLeptons_convVetoFull[3];   //[nselLeptons]
   Float_t         selLeptons_eleMVArawSpring15Trig[3];   //[nselLeptons]
   Int_t           selLeptons_eleMVAIdSpring15Trig[3];   //[nselLeptons]
   Float_t         selLeptons_eleMVArawSpring15NonTrig[3];   //[nselLeptons]
   Int_t           selLeptons_eleMVAIdSpring15NonTrig[3];   //[nselLeptons]
   Float_t         selLeptons_nStations[3];   //[nselLeptons]
   Float_t         selLeptons_trkKink[3];   //[nselLeptons]
   Float_t         selLeptons_segmentCompatibility[3];   //[nselLeptons]
   Float_t         selLeptons_caloCompatibility[3];   //[nselLeptons]
   Float_t         selLeptons_globalTrackChi2[3];   //[nselLeptons]
   Float_t         selLeptons_nChamberHits[3];   //[nselLeptons]
   Float_t         selLeptons_isPFMuon[3];   //[nselLeptons]
   Float_t         selLeptons_isGlobalMuon[3];   //[nselLeptons]
   Float_t         selLeptons_isTrackerMuon[3];   //[nselLeptons]
   Float_t         selLeptons_pixelHits[3];   //[nselLeptons]
   Int_t           selLeptons_trackerLayers[3];   //[nselLeptons]
   Int_t           selLeptons_pixelLayers[3];   //[nselLeptons]
   Float_t         selLeptons_mvaTTH[3];   //[nselLeptons]
   Int_t           selLeptons_jetOverlapIdx[3];   //[nselLeptons]
   Float_t         selLeptons_jetPtRatio[3];   //[nselLeptons]
   Float_t         selLeptons_jetBTagCSV[3];   //[nselLeptons]
   Float_t         selLeptons_jetDR[3];   //[nselLeptons]
   Float_t         selLeptons_mvaTTHjetPtRatio[3];   //[nselLeptons]
   Float_t         selLeptons_mvaTTHjetBTagCSV[3];   //[nselLeptons]
   Float_t         selLeptons_mvaTTHjetDR[3];   //[nselLeptons]
   Float_t         selLeptons_pfRelIso03[3];   //[nselLeptons]
   Float_t         selLeptons_pfRelIso04[3];   //[nselLeptons]
   Float_t         selLeptons_etaSc[3];   //[nselLeptons]
   Float_t         selLeptons_eleExpMissingInnerHits[3];   //[nselLeptons]
   Float_t         selLeptons_eleooEmooP[3];   //[nselLeptons]
   Float_t         selLeptons_dr03TkSumPt[3];   //[nselLeptons]
   Float_t         selLeptons_eleEcalClusterIso[3];   //[nselLeptons]
   Float_t         selLeptons_eleHcalClusterIso[3];   //[nselLeptons]
   Float_t         selLeptons_miniIsoCharged[3];   //[nselLeptons]
   Float_t         selLeptons_miniIsoNeutral[3];   //[nselLeptons]
   Float_t         selLeptons_mvaTTHjetPtRel[3];   //[nselLeptons]
   Float_t         selLeptons_mvaTTHjetNDauChargedMVASel[3];   //[nselLeptons]
   Float_t         selLeptons_uncalibratedPt[3];   //[nselLeptons]
   Float_t         selLeptons_SF_IsoLoose[3];   //[nselLeptons]
   Float_t         selLeptons_SFerr_IsoLoose[3];   //[nselLeptons]
   Float_t         selLeptons_SF_IsoTight[3];   //[nselLeptons]
   Float_t         selLeptons_SFerr_IsoTight[3];   //[nselLeptons]
   Float_t         selLeptons_SF_IdCutLoose[3];   //[nselLeptons]
   Float_t         selLeptons_SFerr_IdCutLoose[3];   //[nselLeptons]
   Float_t         selLeptons_SF_IdCutTight[3];   //[nselLeptons]
   Float_t         selLeptons_SFerr_IdCutTight[3];   //[nselLeptons]
   Float_t         selLeptons_SF_IdMVALoose[3];   //[nselLeptons]
   Float_t         selLeptons_SFerr_IdMVALoose[3];   //[nselLeptons]
   Float_t         selLeptons_SF_IdMVATight[3];   //[nselLeptons]
   Float_t         selLeptons_SFerr_IdMVATight[3];   //[nselLeptons]
   Float_t         selLeptons_SF_HLT_RunD4p3[3];   //[nselLeptons]
   Float_t         selLeptons_SFerr_HLT_RunD4p3[3];   //[nselLeptons]
   Float_t         selLeptons_SF_HLT_RunD4p2[3];   //[nselLeptons]
   Float_t         selLeptons_SFerr_HLT_RunD4p2[3];   //[nselLeptons]
   Float_t         selLeptons_SF_HLT_RunC[3];   //[nselLeptons]
   Float_t         selLeptons_SFerr_HLT_RunC[3];   //[nselLeptons]
   Float_t         selLeptons_Eff_HLT_RunD4p3[3];   //[nselLeptons]
   Float_t         selLeptons_Efferr_HLT_RunD4p3[3];   //[nselLeptons]
   Float_t         selLeptons_Eff_HLT_RunD4p2[3];   //[nselLeptons]
   Float_t         selLeptons_Efferr_HLT_RunD4p2[3];   //[nselLeptons]
   Float_t         selLeptons_Eff_HLT_RunC[3];   //[nselLeptons]
   Float_t         selLeptons_Efferr_HLT_RunC[3];   //[nselLeptons]
   Int_t           ntrgObjects_hltPFMET90;
   Int_t           ntrgObjects_hltQuadJet15;
   Int_t           nTauGood;
   Int_t           TauGood_charge[13];   //[nTauGood]
   Int_t           TauGood_decayMode[13];   //[nTauGood]
   Int_t           TauGood_idDecayMode[13];   //[nTauGood]
   Int_t           TauGood_idDecayModeNewDMs[13];   //[nTauGood]
   Float_t         TauGood_dxy[13];   //[nTauGood]
   Float_t         TauGood_dz[13];   //[nTauGood]
   Int_t           TauGood_idMVArun2[13];   //[nTauGood]
   Float_t         TauGood_rawMVArun2[13];   //[nTauGood]
   Int_t           TauGood_idMVArun2dR03[13];   //[nTauGood]
   Float_t         TauGood_rawMVArun2dR03[13];   //[nTauGood]
   Int_t           TauGood_idMVArun2NewDM[13];   //[nTauGood]
   Float_t         TauGood_rawMVArun2NewDM[13];   //[nTauGood]
   Int_t           TauGood_idCI3hit[13];   //[nTauGood]
   Int_t           TauGood_idAntiMu[13];   //[nTauGood]
   Int_t           TauGood_idAntiErun2[13];   //[nTauGood]
   Float_t         TauGood_isoCI3hit[13];   //[nTauGood]
   Float_t         TauGood_photonOutsideSigCone[13];   //[nTauGood]
   Int_t           TauGood_mcMatchId[13];   //[nTauGood]
   Int_t           TauGood_pdgId[13];   //[nTauGood]
   Float_t         TauGood_pt[13];   //[nTauGood]
   Float_t         TauGood_eta[13];   //[nTauGood]
   Float_t         TauGood_phi[13];   //[nTauGood]
   Float_t         TauGood_mass[13];   //[nTauGood]
   Int_t           TauGood_idxJetMatch[13];   //[nTauGood]
   Int_t           TauGood_genMatchType[13];   //[nTauGood]
   Int_t           nhJidx;
   Int_t           hJidx[2];   //[nhJidx]
   Int_t           nGenLepRecovered;
   Int_t           GenLepRecovered_pdgId[1];   //[nGenLepRecovered]
   Float_t         GenLepRecovered_pt[1];   //[nGenLepRecovered]
   Float_t         GenLepRecovered_eta[1];   //[nGenLepRecovered]
   Float_t         GenLepRecovered_phi[1];   //[nGenLepRecovered]
   Float_t         GenLepRecovered_mass[1];   //[nGenLepRecovered]
   Float_t         GenLepRecovered_charge[1];   //[nGenLepRecovered]
   Int_t           GenLepRecovered_status[1];   //[nGenLepRecovered]
   Int_t           GenLepRecovered_isPromptHard[1];   //[nGenLepRecovered]
   Int_t           nFatjetCA15softdropz2b1;
   Float_t         FatjetCA15softdropz2b1_pt[5];   //[nFatjetCA15softdropz2b1]
   Float_t         FatjetCA15softdropz2b1_eta[5];   //[nFatjetCA15softdropz2b1]
   Float_t         FatjetCA15softdropz2b1_phi[5];   //[nFatjetCA15softdropz2b1]
   Float_t         FatjetCA15softdropz2b1_mass[5];   //[nFatjetCA15softdropz2b1]
   Float_t         FatjetCA15softdropz2b1_tau1[5];   //[nFatjetCA15softdropz2b1]
   Float_t         FatjetCA15softdropz2b1_tau2[5];   //[nFatjetCA15softdropz2b1]
   Float_t         FatjetCA15softdropz2b1_tau3[5];   //[nFatjetCA15softdropz2b1]
   Int_t           nGenStatus2bHad;
   Int_t           GenStatus2bHad_pdgId[14];   //[nGenStatus2bHad]
   Float_t         GenStatus2bHad_pt[14];   //[nGenStatus2bHad]
   Float_t         GenStatus2bHad_eta[14];   //[nGenStatus2bHad]
   Float_t         GenStatus2bHad_phi[14];   //[nGenStatus2bHad]
   Float_t         GenStatus2bHad_mass[14];   //[nGenStatus2bHad]
   Float_t         GenStatus2bHad_charge[14];   //[nGenStatus2bHad]
   Int_t           GenStatus2bHad_status[14];   //[nGenStatus2bHad]
   Int_t           GenStatus2bHad_isPromptHard[14];   //[nGenStatus2bHad]
   Int_t           ntrgObjects_hltTripleJet50;
   Int_t           ntrgObjects_hltVBFPFJetCSVSortedMqq460Detaqq4p1;
   Int_t           nhttCandidates;
   Float_t         httCandidates_pt[5];   //[nhttCandidates]
   Float_t         httCandidates_eta[5];   //[nhttCandidates]
   Float_t         httCandidates_phi[5];   //[nhttCandidates]
   Float_t         httCandidates_mass[5];   //[nhttCandidates]
   Float_t         httCandidates_ptcal[5];   //[nhttCandidates]
   Float_t         httCandidates_etacal[5];   //[nhttCandidates]
   Float_t         httCandidates_phical[5];   //[nhttCandidates]
   Float_t         httCandidates_masscal[5];   //[nhttCandidates]
   Float_t         httCandidates_fRec[5];   //[nhttCandidates]
   Float_t         httCandidates_Ropt[5];   //[nhttCandidates]
   Float_t         httCandidates_RoptCalc[5];   //[nhttCandidates]
   Float_t         httCandidates_ptForRoptCalc[5];   //[nhttCandidates]
   Float_t         httCandidates_subjetIDPassed[5];   //[nhttCandidates]
   Float_t         httCandidates_sjW1ptcal[5];   //[nhttCandidates]
   Float_t         httCandidates_sjW1pt[5];   //[nhttCandidates]
   Float_t         httCandidates_sjW1eta[5];   //[nhttCandidates]
   Float_t         httCandidates_sjW1phi[5];   //[nhttCandidates]
   Float_t         httCandidates_sjW1masscal[5];   //[nhttCandidates]
   Float_t         httCandidates_sjW1mass[5];   //[nhttCandidates]
   Float_t         httCandidates_sjW1btag[5];   //[nhttCandidates]
   Float_t         httCandidates_sjW2ptcal[5];   //[nhttCandidates]
   Float_t         httCandidates_sjW2pt[5];   //[nhttCandidates]
   Float_t         httCandidates_sjW2eta[5];   //[nhttCandidates]
   Float_t         httCandidates_sjW2phi[5];   //[nhttCandidates]
   Float_t         httCandidates_sjW2masscal[5];   //[nhttCandidates]
   Float_t         httCandidates_sjW2mass[5];   //[nhttCandidates]
   Float_t         httCandidates_sjW2btag[5];   //[nhttCandidates]
   Float_t         httCandidates_sjNonWptcal[5];   //[nhttCandidates]
   Float_t         httCandidates_sjNonWpt[5];   //[nhttCandidates]
   Float_t         httCandidates_sjNonWeta[5];   //[nhttCandidates]
   Float_t         httCandidates_sjNonWphi[5];   //[nhttCandidates]
   Float_t         httCandidates_sjNonWmasscal[5];   //[nhttCandidates]
   Float_t         httCandidates_sjNonWmass[5];   //[nhttCandidates]
   Float_t         httCandidates_sjNonWbtag[5];   //[nhttCandidates]
   Int_t           ntrgObjects_hltBTagCaloCSVp087Triple;
   Int_t           nGenTaus;
   Int_t           GenTaus_pdgId[1];   //[nGenTaus]
   Float_t         GenTaus_pt[1];   //[nGenTaus]
   Float_t         GenTaus_eta[1];   //[nGenTaus]
   Float_t         GenTaus_phi[1];   //[nGenTaus]
   Float_t         GenTaus_mass[1];   //[nGenTaus]
   Float_t         GenTaus_charge[1];   //[nGenTaus]
   Int_t           GenTaus_status[1];   //[nGenTaus]
   Int_t           GenTaus_isPromptHard[1];   //[nGenTaus]
   Int_t           ntrgObjects_hltMHT70;
   Int_t           nJet;
   Int_t           Jet_id[22];   //[nJet]
   Int_t           Jet_puId[22];   //[nJet]
   Float_t         Jet_btagCSV[22];   //[nJet]
   Float_t         Jet_btagCMVA[22];   //[nJet]
   Float_t         Jet_rawPt[22];   //[nJet]
   Float_t         Jet_mcPt[22];   //[nJet]
   Int_t           Jet_mcFlavour[22];   //[nJet]
   Int_t           Jet_partonFlavour[22];   //[nJet]
   Int_t           Jet_hadronFlavour[22];   //[nJet]
   Int_t           Jet_mcMatchId[22];   //[nJet]
   Float_t         Jet_corr_JECUp[22];   //[nJet]
   Float_t         Jet_corr_JECDown[22];   //[nJet]
   Float_t         Jet_corr[22];   //[nJet]
   Float_t         Jet_corr_JERUp[22];   //[nJet]
   Float_t         Jet_corr_JERDown[22];   //[nJet]
   Float_t         Jet_corr_JER[22];   //[nJet]
   Float_t         Jet_pt[22];   //[nJet]
   Float_t         Jet_eta[22];   //[nJet]
   Float_t         Jet_phi[22];   //[nJet]
   Float_t         Jet_mass[22];   //[nJet]
   Float_t         Jet_rawPtAfterSmearing[22];   //[nJet]
   Int_t           Jet_idxFirstTauMatch[22];   //[nJet]
   Int_t           Jet_heppyFlavour[22];   //[nJet]
   Float_t         Jet_ctagVsL[22];   //[nJet]
   Float_t         Jet_ctagVsB[22];   //[nJet]
   Float_t         Jet_btagBDT[22];   //[nJet]
   Float_t         Jet_btagProb[22];   //[nJet]
   Float_t         Jet_btagBProb[22];   //[nJet]
   Float_t         Jet_btagSoftEl[22];   //[nJet]
   Float_t         Jet_btagSoftMu[22];   //[nJet]
   Float_t         Jet_btagnew[22];   //[nJet]
   Float_t         Jet_btagCSVV0[22];   //[nJet]
   Float_t         Jet_btagCMVAV2[22];   //[nJet]
   Float_t         Jet_chHEF[22];   //[nJet]
   Float_t         Jet_neHEF[22];   //[nJet]
   Float_t         Jet_chEmEF[22];   //[nJet]
   Float_t         Jet_neEmEF[22];   //[nJet]
   Float_t         Jet_muEF[22];   //[nJet]
   Int_t           Jet_chMult[22];   //[nJet]
   Int_t           Jet_nhMult[22];   //[nJet]
   Float_t         Jet_leadTrackPt[22];   //[nJet]
   Float_t         Jet_mcEta[22];   //[nJet]
   Float_t         Jet_mcPhi[22];   //[nJet]
   Float_t         Jet_mcM[22];   //[nJet]
   Float_t         Jet_leptonPdgId[22];   //[nJet]
   Float_t         Jet_leptonPt[22];   //[nJet]
   Float_t         Jet_leptonPtRel[22];   //[nJet]
   Float_t         Jet_leptonPtRelInv[22];   //[nJet]
   Float_t         Jet_leptonDeltaR[22];   //[nJet]
   Float_t         Jet_leptonDeltaPhi[22];   //[nJet]
   Float_t         Jet_leptonDeltaEta[22];   //[nJet]
   Float_t         Jet_vtxMass[22];   //[nJet]
   Float_t         Jet_vtxNtracks[22];   //[nJet]
   Float_t         Jet_vtxPt[22];   //[nJet]
   Float_t         Jet_vtx3DSig[22];   //[nJet]
   Float_t         Jet_vtx3DVal[22];   //[nJet]
   Float_t         Jet_vtxPosX[22];   //[nJet]
   Float_t         Jet_vtxPosY[22];   //[nJet]
   Float_t         Jet_vtxPosZ[22];   //[nJet]
   Float_t         Jet_pullVectorPhi[22];   //[nJet]
   Float_t         Jet_pullVectorMag[22];   //[nJet]
   Float_t         Jet_qgl[22];   //[nJet]
   Float_t         Jet_ptd[22];   //[nJet]
   Float_t         Jet_axis2[22];   //[nJet]
   Int_t           Jet_mult[22];   //[nJet]
   Int_t           Jet_numberOfDaughters[22];   //[nJet]
   Int_t           Jet_btagIdx[22];   //[nJet]
   Int_t           Jet_mcIdx[22];   //[nJet]
   Float_t         Jet_blike_VBF[22];   //[nJet]
   Float_t         Jet_pt_reg[22];   //[nJet]
   Float_t         Jet_pt_regVBF[22];   //[nJet]
   Float_t         Jet_pt_reg_corrJECUp[22];   //[nJet]
   Float_t         Jet_pt_regVBF_corrJECUp[22];   //[nJet]
   Float_t         Jet_pt_reg_corrJECDown[22];   //[nJet]
   Float_t         Jet_pt_regVBF_corrJECDown[22];   //[nJet]
   Float_t         Jet_pt_reg_corrJERUp[22];   //[nJet]
   Float_t         Jet_pt_regVBF_corrJERUp[22];   //[nJet]
   Float_t         Jet_pt_reg_corrJERDown[22];   //[nJet]
   Float_t         Jet_pt_regVBF_corrJERDown[22];   //[nJet]
   Float_t         Jet_btagCSVL_SF[22];   //[nJet]
   Float_t         Jet_btagCSVL_SF_up[22];   //[nJet]
   Float_t         Jet_btagCSVL_SF_down[22];   //[nJet]
   Float_t         Jet_btagCSVM_SF[22];   //[nJet]
   Float_t         Jet_btagCSVM_SF_up[22];   //[nJet]
   Float_t         Jet_btagCSVM_SF_down[22];   //[nJet]
   Float_t         Jet_btagCSVT_SF[22];   //[nJet]
   Float_t         Jet_btagCSVT_SF_up[22];   //[nJet]
   Float_t         Jet_btagCSVT_SF_down[22];   //[nJet]
   Float_t         Jet_btagWeightCSV[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_up_jes[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_down_jes[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_up_lf[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_down_lf[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_up_hf[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_down_hf[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_up_hfstats1[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_down_hfstats1[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_up_hfstats2[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_down_hfstats2[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_up_lfstats1[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_down_lfstats1[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_up_lfstats2[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_down_lfstats2[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_up_cferr1[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_down_cferr1[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_up_cferr2[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_down_cferr2[22];   //[nJet]
   Float_t         Jet_btagCMVAV2L_SF[22];   //[nJet]
   Float_t         Jet_btagCMVAV2L_SF_up[22];   //[nJet]
   Float_t         Jet_btagCMVAV2L_SF_down[22];   //[nJet]
   Float_t         Jet_btagCMVAV2M_SF[22];   //[nJet]
   Float_t         Jet_btagCMVAV2M_SF_up[22];   //[nJet]
   Float_t         Jet_btagCMVAV2M_SF_down[22];   //[nJet]
   Float_t         Jet_btagCMVAV2T_SF[22];   //[nJet]
   Float_t         Jet_btagCMVAV2T_SF_up[22];   //[nJet]
   Float_t         Jet_btagCMVAV2T_SF_down[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_up_jes[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_down_jes[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_up_lf[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_down_lf[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_up_hf[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_down_hf[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_up_hfstats1[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_down_hfstats1[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_up_hfstats2[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_down_hfstats2[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_up_lfstats1[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_down_lfstats1[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_up_lfstats2[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_down_lfstats2[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_up_cferr1[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_down_cferr1[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_up_cferr2[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_down_cferr2[22];   //[nJet]
   Int_t           nFatjetCA15softdrop;
   Float_t         FatjetCA15softdrop_pt[5];   //[nFatjetCA15softdrop]
   Float_t         FatjetCA15softdrop_eta[5];   //[nFatjetCA15softdrop]
   Float_t         FatjetCA15softdrop_phi[5];   //[nFatjetCA15softdrop]
   Float_t         FatjetCA15softdrop_mass[5];   //[nFatjetCA15softdrop]
   Int_t           ntrgObjects_hltPFTripleJetLooseID64;
   Int_t           nLHE_weights_pdf;
   Int_t           LHE_weights_pdf_id[102];   //[nLHE_weights_pdf]
   Float_t         LHE_weights_pdf_wgt[102];   //[nLHE_weights_pdf]
   Int_t           nprimaryVertices;
   Float_t         primaryVertices_x[4];   //[nprimaryVertices]
   Float_t         primaryVertices_y[4];   //[nprimaryVertices]
   Float_t         primaryVertices_z[4];   //[nprimaryVertices]
   Float_t         primaryVertices_isFake[4];   //[nprimaryVertices]
   Float_t         primaryVertices_ndof[4];   //[nprimaryVertices]
   Float_t         primaryVertices_Rho[4];   //[nprimaryVertices]
   Float_t         primaryVertices_score[4];   //[nprimaryVertices]
   Int_t           nsoftActivityJets;
   Float_t         softActivityJets_pt[5];   //[nsoftActivityJets]
   Float_t         softActivityJets_eta[5];   //[nsoftActivityJets]
   Float_t         softActivityJets_phi[5];   //[nsoftActivityJets]
   Float_t         softActivityJets_mass[5];   //[nsoftActivityJets]
   Int_t           nFatjetCA15subjetfiltered;
   Float_t         FatjetCA15subjetfiltered_pt[5];   //[nFatjetCA15subjetfiltered]
   Float_t         FatjetCA15subjetfiltered_eta[5];   //[nFatjetCA15subjetfiltered]
   Float_t         FatjetCA15subjetfiltered_phi[5];   //[nFatjetCA15subjetfiltered]
   Float_t         FatjetCA15subjetfiltered_mass[5];   //[nFatjetCA15subjetfiltered]
   Int_t           nGenWZQuark;
   Int_t           GenWZQuark_pdgId[4];   //[nGenWZQuark]
   Float_t         GenWZQuark_pt[4];   //[nGenWZQuark]
   Float_t         GenWZQuark_eta[4];   //[nGenWZQuark]
   Float_t         GenWZQuark_phi[4];   //[nGenWZQuark]
   Float_t         GenWZQuark_mass[4];   //[nGenWZQuark]
   Float_t         GenWZQuark_charge[4];   //[nGenWZQuark]
   Int_t           GenWZQuark_status[4];   //[nGenWZQuark]
   Int_t           GenWZQuark_isPromptHard[4];   //[nGenWZQuark]
   Int_t           ntrgObjects_hltSingleJet80;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_isData;   //!
   TBranch        *b_xsec;   //!
   TBranch        *b_puWeight;   //!
   TBranch        *b_nTrueInt;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_puWeightUp;   //!
   TBranch        *b_puWeightDown;   //!
   TBranch        *b_json;   //!
   TBranch        *b_json_silver;   //!
   TBranch        *b_nPU0;   //!
   TBranch        *b_nPVs;   //!
   TBranch        *b_Vtype;   //!
   TBranch        *b_VtypeSim;   //!
   TBranch        *b_VMt;   //!
   TBranch        *b_HVdPhi;   //!
   TBranch        *b_fakeMET_sumet;   //!
   TBranch        *b_bx;   //!
   TBranch        *b_caloMetPt;   //!
   TBranch        *b_caloMetPhi;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_rhoN;   //!
   TBranch        *b_rhoCHPU;   //!
   TBranch        *b_rhoCentral;   //!
   TBranch        *b_deltaR_jj;   //!
   TBranch        *b_lheNj;   //!
   TBranch        *b_lheNb;   //!
   TBranch        *b_lheNc;   //!
   TBranch        *b_lheNg;   //!
   TBranch        *b_lheNl;   //!
   TBranch        *b_lheV_pt;   //!
   TBranch        *b_lheHT;   //!
   TBranch        *b_genTTHtoTauTauDecayMode;   //!
   TBranch        *b_ttCls;   //!
   TBranch        *b_heavyFlavourCategory;   //!
   TBranch        *b_mhtJet30;   //!
   TBranch        *b_mhtPhiJet30;   //!
   TBranch        *b_htJet30;   //!
   TBranch        *b_met_sig;   //!
   TBranch        *b_met_rawpt;   //!
   TBranch        *b_metPuppi_pt;   //!
   TBranch        *b_metPuppi_phi;   //!
   TBranch        *b_metPuppi_rawpt;   //!
   TBranch        *b_metType1p2_pt;   //!
   TBranch        *b_tkMet_pt;   //!
   TBranch        *b_tkMet_phi;   //!
   TBranch        *b_tkMetPVchs_pt;   //!
   TBranch        *b_tkMetPVchs_phi;   //!
   TBranch        *b_isrJetVH;   //!
   TBranch        *b_Flag_hbheIsoFilter;   //!
   TBranch        *b_Flag_hbheFilterNew;   //!
   TBranch        *b_simPrimaryVertex_z;   //!
   TBranch        *b_genHiggsDecayMode;   //!
   TBranch        *b_btagWeightCSV_down_cferr1;   //!
   TBranch        *b_btagWeightCMVAV2_down_hfstats1;   //!
   TBranch        *b_btagWeightCMVAV2_down_hfstats2;   //!
   TBranch        *b_btagWeightCSV_down_cferr2;   //!
   TBranch        *b_btagWeightCSV_down_jes;   //!
   TBranch        *b_btagWeightCSV_down_lf;   //!
   TBranch        *b_btagWeightCSV_up_lf;   //!
   TBranch        *b_btagWeightCSV_down_lfstats2;   //!
   TBranch        *b_btagWeightCSV_down_lfstats1;   //!
   TBranch        *b_btagWeightCSV_down_hf;   //!
   TBranch        *b_btagWeightCSV_up_lfstats1;   //!
   TBranch        *b_btagWeightCMVAV2_down_lf;   //!
   TBranch        *b_btagWeightCSV_up_lfstats2;   //!
   TBranch        *b_btagWeightCSV;   //!
   TBranch        *b_btagWeightCSV_up_cferr2;   //!
   TBranch        *b_btagWeightCSV_up_cferr1;   //!
   TBranch        *b_btagWeightCSV_up_hf;   //!
   TBranch        *b_btagWeightCMVAV2_down_hf;   //!
   TBranch        *b_btagWeightCMVAV2_up_lfstats2;   //!
   TBranch        *b_btagWeightCMVAV2_up_hfstats2;   //!
   TBranch        *b_btagWeightCMVAV2_up_hfstats1;   //!
   TBranch        *b_btagWeightCMVAV2;   //!
   TBranch        *b_btagWeightCMVAV2_up_lfstats1;   //!
   TBranch        *b_btagWeightCMVAV2_down_cferr2;   //!
   TBranch        *b_btagWeightCMVAV2_up_hf;   //!
   TBranch        *b_btagWeightCMVAV2_down_cferr1;   //!
   TBranch        *b_btagWeightCSV_up_jes;   //!
   TBranch        *b_btagWeightCMVAV2_up_jes;   //!
   TBranch        *b_btagWeightCMVAV2_up_lf;   //!
   TBranch        *b_btagWeightCSV_down_hfstats2;   //!
   TBranch        *b_btagWeightCSV_down_hfstats1;   //!
   TBranch        *b_btagWeightCMVAV2_up_cferr1;   //!
   TBranch        *b_btagWeightCMVAV2_up_cferr2;   //!
   TBranch        *b_btagWeightCMVAV2_down_lfstats1;   //!
   TBranch        *b_btagWeightCMVAV2_down_lfstats2;   //!
   TBranch        *b_btagWeightCSV_up_hfstats1;   //!
   TBranch        *b_btagWeightCMVAV2_down_jes;   //!
   TBranch        *b_btagWeightCSV_up_hfstats2;   //!
   TBranch        *b_Flag_HBHENoiseIsoFilter;   //!
   TBranch        *b_Flag_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_Flag_trkPOG_manystripclus53X;   //!
   TBranch        *b_Flag_ecalLaserCorrFilter;   //!
   TBranch        *b_Flag_trkPOG_toomanystripclus53X;   //!
   TBranch        *b_Flag_hcalLaserEventFilter;   //!
   TBranch        *b_Flag_muonBadTrackFilter;   //!
   TBranch        *b_Flag_trkPOG_logErrorTooManyClusters;   //!
   TBranch        *b_Flag_trkPOGFilters;   //!
   TBranch        *b_Flag_trackingFailureFilter;   //!
   TBranch        *b_Flag_CSCTightHaloFilter;   //!
   TBranch        *b_Flag_HBHENoiseFilter;   //!
   TBranch        *b_Flag_chargedHadronTrackResolutionFilter;   //!
   TBranch        *b_Flag_goodVertices;   //!
   TBranch        *b_Flag_METFilters;   //!
   TBranch        *b_Flag_CSCTightHalo2015Filter;   //!
   TBranch        *b_Flag_eeBadScFilter;   //!
   TBranch        *b_HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_BTagCSV_p067_v;   //!
   TBranch        *b_HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET170_NoiseCleaned_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiCentralPFJet55_PFMET110_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT350_PFMET100_v;   //!
   TBranch        *b_HLT_ZnnHbbAll;   //!
   TBranch        *b_HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq200_v;   //!
   TBranch        *b_HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq460_v;   //!
   TBranch        *b_HLT_VBFHbbLowLumi;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT750_4JetPt50_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT800_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFJet40_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFJet60_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFJet80_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFJet140_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFJet200_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFJet260_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFJet320_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFJet400_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFJet450_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiPFJetAve40_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiPFJetAve60_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiPFJetAve80_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiPFJetAve140_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiPFJetAve200_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiPFJetAve260_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiPFJetAve320_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p026_DoublePFJetsC160_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p014_DoublePFJetsC100MaxDeta1p6_v;   //!
   TBranch        *b_HLT_hadronic;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT450_SixJet40_BTagCSV_p056_v;   //!
   TBranch        *b_HLT_ttHhardonicLowLumi;   //!
   TBranch        *b_HLT_BIT_HLT_QuadJet45_TripleBTagCSV_p087_v;   //!
   TBranch        *b_HLT_BIT_HLT_QuadJet45_DoubleBTagCSV_p087_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleJet90_Double30_TripleBTagCSV_p087_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleJet90_Double30_DoubleBTagCSV_p087_v;   //!
   TBranch        *b_HLT_BIT_HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v;   //!
   TBranch        *b_HLT_BIT_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v;   //!
   TBranch        *b_HLT_BIT_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v;   //!
   TBranch        *b_HLT_BIT_HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v;   //!
   TBranch        *b_HLT_BIT_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v;   //!
   TBranch        *b_HLT_BIT_HLT_AK8PFJet360_TrimMass30_v;   //!
   TBranch        *b_HLT_HH4bAll;   //!
   TBranch        *b_HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET80_v;   //!
   TBranch        *b_HLT_WtaunHbbLowLumi;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_ZeeHbbHighLumi;   //!
   TBranch        *b_HLT_HH4bHighLumi;   //!
   TBranch        *b_HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq240_v;   //!
   TBranch        *b_HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq500_v;   //!
   TBranch        *b_HLT_BIT_HLT_QuadPFJet_VBF_v;   //!
   TBranch        *b_HLT_BIT_HLT_L1_TripleJet_VBF_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v;   //!
   TBranch        *b_HLT_VBFHbbAll;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_eta2p1_WPTight_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_HT200_v;   //!
   TBranch        *b_HLT_WenHbbLowLumi;   //!
   TBranch        *b_HLT_BIT_HLT_Ele32_eta2p1_WPTight_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele105_CaloIdVT_GsfTrkIdT_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_WPLoose_Gsf_WHbbBoost_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele22_eta2p1_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_WPLoose_Gsf_WHbbBoost_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele25_WPTight_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_WenHbbAll;   //!
   TBranch        *b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;   //!
   TBranch        *b_HLT_ZeeHbbLowLumi;   //!
   TBranch        *b_HLT_BIT_HLT_Mu24_eta2p1_v;   //!
   TBranch        *b_HLT_BIT_HLT_TkMu24_eta2p1_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu27_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu27_v;   //!
   TBranch        *b_HLT_BIT_HLT_TkMu27_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu27_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu20_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu20_v;   //!
   TBranch        *b_HLT_BIT_HLT_TkMu20_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu20_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu18_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu18_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu40_eta2p1_PFJet200_PFJet50_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu16_eta2p1_MET30_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu16_eta2p1_MET30_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET120_Mu5_v;   //!
   TBranch        *b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v;   //!
   TBranch        *b_HLT_WmnHbbAll;   //!
   TBranch        *b_HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v;   //!
   TBranch        *b_HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_v;   //!
   TBranch        *b_HLT_WtaunHbbAll;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT450_SixJet40_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT400_SixJet30_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT350_v;   //!
   TBranch        *b_HLT_ttHhardonicAll;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele30WP60_Ele8_Mass55_v;   //!
   TBranch        *b_HLT_ZeeHbbAll;   //!
   TBranch        *b_HLT_WmnHbbLowLumi;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v;   //!
   TBranch        *b_HLT_ttHleptonic;   //!
   TBranch        *b_HLT_VBFHbbHighLumi;   //!
   TBranch        *b_HLT_ZnnHbb;   //!
   TBranch        *b_HLT_ZmmHbbLowLumi;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu24_v;   //!
   TBranch        *b_HLT_WmnHbbHighLumi;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TkMu8_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleIsoMu17_eta2p1_v;   //!
   TBranch        *b_HLT_ZmmHbbAll;   //!
   TBranch        *b_HLT_WenHbbHighLumi;   //!
   TBranch        *b_HLT_HH4bLowLumi;   //!
   TBranch        *b_HLT_ZmmHbbHighLumi;   //!
   TBranch        *b_HLT_ttHhardonicHighLumi;   //!
   TBranch        *b_HLT_WtaunHbbHighLumi;   //!
   TBranch        *b_H_reg_corrJECUp_pt;   //!
   TBranch        *b_H_reg_corrJECUp_eta;   //!
   TBranch        *b_H_reg_corrJECUp_phi;   //!
   TBranch        *b_H_reg_corrJECUp_mass;   //!
   TBranch        *b_HaddJetsdR08_pt;   //!
   TBranch        *b_HaddJetsdR08_eta;   //!
   TBranch        *b_HaddJetsdR08_phi;   //!
   TBranch        *b_HaddJetsdR08_mass;   //!
   TBranch        *b_H_pt;   //!
   TBranch        *b_H_eta;   //!
   TBranch        *b_H_phi;   //!
   TBranch        *b_H_mass;   //!
   TBranch        *b_softActivityVH_njets2;   //!
   TBranch        *b_softActivityVH_njets5;   //!
   TBranch        *b_softActivityVH_njets10;   //!
   TBranch        *b_softActivityVH_HT;   //!
   TBranch        *b_met_shifted_JetResUp_pt;   //!
   TBranch        *b_met_shifted_JetResUp_phi;   //!
   TBranch        *b_met_shifted_JetResUp_sumEt;   //!
   TBranch        *b_met_pt;   //!
   TBranch        *b_met_eta;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_met_mass;   //!
   TBranch        *b_met_sumEt;   //!
   TBranch        *b_met_rawPt;   //!
   TBranch        *b_met_rawPhi;   //!
   TBranch        *b_met_rawSumEt;   //!
   TBranch        *b_met_genPt;   //!
   TBranch        *b_met_genPhi;   //!
   TBranch        *b_met_genEta;   //!
   TBranch        *b_H_reg_pt;   //!
   TBranch        *b_H_reg_eta;   //!
   TBranch        *b_H_reg_phi;   //!
   TBranch        *b_H_reg_mass;   //!
   TBranch        *b_HCSV_reg_corrJERDown_pt;   //!
   TBranch        *b_HCSV_reg_corrJERDown_eta;   //!
   TBranch        *b_HCSV_reg_corrJERDown_phi;   //!
   TBranch        *b_HCSV_reg_corrJERDown_mass;   //!
   TBranch        *b_HCSV_pt;   //!
   TBranch        *b_HCSV_eta;   //!
   TBranch        *b_HCSV_phi;   //!
   TBranch        *b_HCSV_mass;   //!
   TBranch        *b_met_shifted_MuonEnDown_pt;   //!
   TBranch        *b_met_shifted_MuonEnDown_phi;   //!
   TBranch        *b_met_shifted_MuonEnDown_sumEt;   //!
   TBranch        *b_met_shifted_ElectronEnUp_pt;   //!
   TBranch        *b_met_shifted_ElectronEnUp_phi;   //!
   TBranch        *b_met_shifted_ElectronEnUp_sumEt;   //!
   TBranch        *b_met_shifted_ElectronEnDown_pt;   //!
   TBranch        *b_met_shifted_ElectronEnDown_phi;   //!
   TBranch        *b_met_shifted_ElectronEnDown_sumEt;   //!
   TBranch        *b_fakeMET_pt;   //!
   TBranch        *b_fakeMET_eta;   //!
   TBranch        *b_fakeMET_phi;   //!
   TBranch        *b_fakeMET_mass;   //!
   TBranch        *b_met_shifted_TauEnDown_pt;   //!
   TBranch        *b_met_shifted_TauEnDown_phi;   //!
   TBranch        *b_met_shifted_TauEnDown_sumEt;   //!
   TBranch        *b_V_pt;   //!
   TBranch        *b_V_eta;   //!
   TBranch        *b_V_phi;   //!
   TBranch        *b_V_mass;   //!
   TBranch        *b_HCSV_reg_corrJERUp_pt;   //!
   TBranch        *b_HCSV_reg_corrJERUp_eta;   //!
   TBranch        *b_HCSV_reg_corrJERUp_phi;   //!
   TBranch        *b_HCSV_reg_corrJERUp_mass;   //!
   TBranch        *b_met_shifted_TauEnUp_pt;   //!
   TBranch        *b_met_shifted_TauEnUp_phi;   //!
   TBranch        *b_met_shifted_TauEnUp_sumEt;   //!
   TBranch        *b_HCSV_reg_corrJECUp_pt;   //!
   TBranch        *b_HCSV_reg_corrJECUp_eta;   //!
   TBranch        *b_HCSV_reg_corrJECUp_phi;   //!
   TBranch        *b_HCSV_reg_corrJECUp_mass;   //!
   TBranch        *b_met_shifted_UnclusteredEnUp_pt;   //!
   TBranch        *b_met_shifted_UnclusteredEnUp_phi;   //!
   TBranch        *b_met_shifted_UnclusteredEnUp_sumEt;   //!
   TBranch        *b_met_shifted_UnclusteredEnDown_pt;   //!
   TBranch        *b_met_shifted_UnclusteredEnDown_phi;   //!
   TBranch        *b_met_shifted_UnclusteredEnDown_sumEt;   //!
   TBranch        *b_met_shifted_JetEnUp_pt;   //!
   TBranch        *b_met_shifted_JetEnUp_phi;   //!
   TBranch        *b_met_shifted_JetEnUp_sumEt;   //!
   TBranch        *b_H_reg_corrJERDown_pt;   //!
   TBranch        *b_H_reg_corrJERDown_eta;   //!
   TBranch        *b_H_reg_corrJERDown_phi;   //!
   TBranch        *b_H_reg_corrJERDown_mass;   //!
   TBranch        *b_HCSV_reg_pt;   //!
   TBranch        *b_HCSV_reg_eta;   //!
   TBranch        *b_HCSV_reg_phi;   //!
   TBranch        *b_HCSV_reg_mass;   //!
   TBranch        *b_met_shifted_JetEnDown_pt;   //!
   TBranch        *b_met_shifted_JetEnDown_phi;   //!
   TBranch        *b_met_shifted_JetEnDown_sumEt;   //!
   TBranch        *b_met_shifted_JetResDown_pt;   //!
   TBranch        *b_met_shifted_JetResDown_phi;   //!
   TBranch        *b_met_shifted_JetResDown_sumEt;   //!
   TBranch        *b_softActivity_njets2;   //!
   TBranch        *b_softActivity_njets5;   //!
   TBranch        *b_softActivity_njets10;   //!
   TBranch        *b_softActivity_HT;   //!
   TBranch        *b_met_shifted_MuonEnUp_pt;   //!
   TBranch        *b_met_shifted_MuonEnUp_phi;   //!
   TBranch        *b_met_shifted_MuonEnUp_sumEt;   //!
   TBranch        *b_HCSV_reg_corrJECDown_pt;   //!
   TBranch        *b_HCSV_reg_corrJECDown_eta;   //!
   TBranch        *b_HCSV_reg_corrJECDown_phi;   //!
   TBranch        *b_HCSV_reg_corrJECDown_mass;   //!
   TBranch        *b_H_reg_corrJERUp_pt;   //!
   TBranch        *b_H_reg_corrJERUp_eta;   //!
   TBranch        *b_H_reg_corrJERUp_phi;   //!
   TBranch        *b_H_reg_corrJERUp_mass;   //!
   TBranch        *b_H_reg_corrJECDown_pt;   //!
   TBranch        *b_H_reg_corrJECDown_eta;   //!
   TBranch        *b_H_reg_corrJECDown_phi;   //!
   TBranch        *b_H_reg_corrJECDown_mass;   //!
   TBranch        *b_nGenBQuarkFromHafterISR;   //!
   TBranch        *b_GenBQuarkFromHafterISR_pdgId;   //!
   TBranch        *b_GenBQuarkFromHafterISR_pt;   //!
   TBranch        *b_GenBQuarkFromHafterISR_eta;   //!
   TBranch        *b_GenBQuarkFromHafterISR_phi;   //!
   TBranch        *b_GenBQuarkFromHafterISR_mass;   //!
   TBranch        *b_GenBQuarkFromHafterISR_charge;   //!
   TBranch        *b_GenBQuarkFromHafterISR_status;   //!
   TBranch        *b_GenBQuarkFromHafterISR_isPromptHard;   //!
   TBranch        *b_npileUpVertex_ptHat;   //!
   TBranch        *b_pileUpVertex_ptHat;   //!
   TBranch        *b_ntrgObjects_hltMET70;   //!
   TBranch        *b_ntrgObjects_hltL1sTripleJetVBFIorHTTIorDoubleJetCIorSingleJet;   //!
   TBranch        *b_ntrgObjects_hltBTagPFCSVp11DoubleWithMatching;   //!
   TBranch        *b_nGenLepFromTop;   //!
   TBranch        *b_GenLepFromTop_pdgId;   //!
   TBranch        *b_GenLepFromTop_pt;   //!
   TBranch        *b_GenLepFromTop_eta;   //!
   TBranch        *b_GenLepFromTop_phi;   //!
   TBranch        *b_GenLepFromTop_mass;   //!
   TBranch        *b_GenLepFromTop_charge;   //!
   TBranch        *b_GenLepFromTop_status;   //!
   TBranch        *b_GenLepFromTop_isPromptHard;   //!
   TBranch        *b_najidxaddJetsdR08;   //!
   TBranch        *b_ajidxaddJetsdR08;   //!
   TBranch        *b_nSubjetCA15softdrop;   //!
   TBranch        *b_SubjetCA15softdrop_pt;   //!
   TBranch        *b_SubjetCA15softdrop_eta;   //!
   TBranch        *b_SubjetCA15softdrop_phi;   //!
   TBranch        *b_SubjetCA15softdrop_mass;   //!
   TBranch        *b_SubjetCA15softdrop_btag;   //!
   TBranch        *b_SubjetCA15softdrop_jetID;   //!
   TBranch        *b_SubjetCA15softdrop_fromFJ;   //!
   TBranch        *b_ntrgObjects_hltIsoMu20;   //!
   TBranch        *b_trgObjects_hltIsoMu20_pt;   //!
   TBranch        *b_trgObjects_hltIsoMu20_eta;   //!
   TBranch        *b_trgObjects_hltIsoMu20_phi;   //!
   TBranch        *b_trgObjects_hltIsoMu20_mass;   //!
   TBranch        *b_ntrgObjects_hltQuadCentralJet30;   //!
   TBranch        *b_nGenVbosonsRecovered;   //!
   TBranch        *b_GenVbosonsRecovered_pdgId;   //!
   TBranch        *b_GenVbosonsRecovered_pt;   //!
   TBranch        *b_GenVbosonsRecovered_eta;   //!
   TBranch        *b_GenVbosonsRecovered_phi;   //!
   TBranch        *b_GenVbosonsRecovered_mass;   //!
   TBranch        *b_GenVbosonsRecovered_charge;   //!
   TBranch        *b_GenVbosonsRecovered_status;   //!
   TBranch        *b_GenVbosonsRecovered_isPromptHard;   //!
   TBranch        *b_nhJidx_sortcsv;   //!
   TBranch        *b_hJidx_sortcsv;   //!
   TBranch        *b_ntrgObjects_hltL1sQuadJetCIorTripleJetVBFIorHTT;   //!
   TBranch        *b_nGenTausRecovered;   //!
   TBranch        *b_GenTausRecovered_pdgId;   //!
   TBranch        *b_GenTausRecovered_pt;   //!
   TBranch        *b_GenTausRecovered_eta;   //!
   TBranch        *b_GenTausRecovered_phi;   //!
   TBranch        *b_GenTausRecovered_mass;   //!
   TBranch        *b_GenTausRecovered_charge;   //!
   TBranch        *b_GenTausRecovered_status;   //!
   TBranch        *b_GenTausRecovered_isPromptHard;   //!
   TBranch        *b_nSubjetCA15softdropz2b1;   //!
   TBranch        *b_SubjetCA15softdropz2b1_pt;   //!
   TBranch        *b_SubjetCA15softdropz2b1_eta;   //!
   TBranch        *b_SubjetCA15softdropz2b1_phi;   //!
   TBranch        *b_SubjetCA15softdropz2b1_mass;   //!
   TBranch        *b_SubjetCA15softdropz2b1_btag;   //!
   TBranch        *b_SubjetCA15softdropz2b1_jetID;   //!
   TBranch        *b_SubjetCA15softdropz2b1_fromFJ;   //!
   TBranch        *b_nhJCidx;   //!
   TBranch        *b_hJCidx;   //!
   TBranch        *b_nGenTop;   //!
   TBranch        *b_GenTop_charge;   //!
   TBranch        *b_GenTop_status;   //!
   TBranch        *b_GenTop_isPromptHard;   //!
   TBranch        *b_GenTop_pdgId;   //!
   TBranch        *b_GenTop_pt;   //!
   TBranch        *b_GenTop_eta;   //!
   TBranch        *b_GenTop_phi;   //!
   TBranch        *b_GenTop_mass;   //!
   TBranch        *b_GenTop_decayMode;   //!
   TBranch        *b_naJidx;   //!
   TBranch        *b_aJidx;   //!
   TBranch        *b_nGenLepFromTau;   //!
   TBranch        *b_GenLepFromTau_pdgId;   //!
   TBranch        *b_GenLepFromTau_pt;   //!
   TBranch        *b_GenLepFromTau_eta;   //!
   TBranch        *b_GenLepFromTau_phi;   //!
   TBranch        *b_GenLepFromTau_mass;   //!
   TBranch        *b_GenLepFromTau_charge;   //!
   TBranch        *b_GenLepFromTau_status;   //!
   TBranch        *b_GenLepFromTau_isPromptHard;   //!
   TBranch        *b_nGenNuFromTop;   //!
   TBranch        *b_GenNuFromTop_pdgId;   //!
   TBranch        *b_GenNuFromTop_pt;   //!
   TBranch        *b_GenNuFromTop_eta;   //!
   TBranch        *b_GenNuFromTop_phi;   //!
   TBranch        *b_GenNuFromTop_mass;   //!
   TBranch        *b_GenNuFromTop_charge;   //!
   TBranch        *b_GenNuFromTop_status;   //!
   TBranch        *b_GenNuFromTop_isPromptHard;   //!
   TBranch        *b_ntrgObjects_hltPFDoubleJetLooseID76;   //!
   TBranch        *b_ntrgObjects_hltBTagPFCSVp016SingleWithMatching;   //!
   TBranch        *b_nGenVbosons;   //!
   TBranch        *b_GenVbosons_pdgId;   //!
   TBranch        *b_GenVbosons_pt;   //!
   TBranch        *b_GenVbosons_eta;   //!
   TBranch        *b_GenVbosons_phi;   //!
   TBranch        *b_GenVbosons_mass;   //!
   TBranch        *b_GenVbosons_charge;   //!
   TBranch        *b_GenVbosons_status;   //!
   TBranch        *b_GenVbosons_isPromptHard;   //!
   TBranch        *b_nsoftActivityVHJets;   //!
   TBranch        *b_softActivityVHJets_pt;   //!
   TBranch        *b_softActivityVHJets_eta;   //!
   TBranch        *b_softActivityVHJets_phi;   //!
   TBranch        *b_softActivityVHJets_mass;   //!
   TBranch        *b_ntrgObjects_hltQuadPFCentralJetLooseID30;   //!
   TBranch        *b_ntrgObjects_caloMhtNoPU;   //!
   TBranch        *b_trgObjects_caloMhtNoPU_pt;   //!
   TBranch        *b_ntrgObjects_hltEle25eta2p1WPLoose;   //!
   TBranch        *b_trgObjects_hltEle25eta2p1WPLoose_pt;   //!
   TBranch        *b_trgObjects_hltEle25eta2p1WPLoose_eta;   //!
   TBranch        *b_trgObjects_hltEle25eta2p1WPLoose_phi;   //!
   TBranch        *b_trgObjects_hltEle25eta2p1WPLoose_mass;   //!
   TBranch        *b_nSubjetAK08softdrop;   //!
   TBranch        *b_SubjetAK08softdrop_pt;   //!
   TBranch        *b_SubjetAK08softdrop_eta;   //!
   TBranch        *b_SubjetAK08softdrop_phi;   //!
   TBranch        *b_SubjetAK08softdrop_mass;   //!
   TBranch        *b_SubjetAK08softdrop_btag;   //!
   TBranch        *b_ntrgObjects_hltDoublePFCentralJetLooseID90;   //!
   TBranch        *b_nGenLep;   //!
   TBranch        *b_GenLep_pdgId;   //!
   TBranch        *b_GenLep_pt;   //!
   TBranch        *b_GenLep_eta;   //!
   TBranch        *b_GenLep_phi;   //!
   TBranch        *b_GenLep_mass;   //!
   TBranch        *b_GenLep_charge;   //!
   TBranch        *b_GenLep_status;   //!
   TBranch        *b_GenLep_isPromptHard;   //!
   TBranch        *b_ntrgObjects_caloJets;   //!
   TBranch        *b_trgObjects_caloJets_pt;   //!
   TBranch        *b_ntrgObjects_hltPFSingleJetLooseID92;   //!
   TBranch        *b_nGenHadTaus;   //!
   TBranch        *b_GenHadTaus_charge;   //!
   TBranch        *b_GenHadTaus_status;   //!
   TBranch        *b_GenHadTaus_isPromptHard;   //!
   TBranch        *b_GenHadTaus_pdgId;   //!
   TBranch        *b_GenHadTaus_pt;   //!
   TBranch        *b_GenHadTaus_eta;   //!
   TBranch        *b_GenHadTaus_phi;   //!
   TBranch        *b_GenHadTaus_mass;   //!
   TBranch        *b_GenHadTaus_decayMode;   //!
   TBranch        *b_ntrgObjects_hltL1sETM50ToETM100IorETM60Jet60dPhiMin0p4IorDoubleJetC60ETM60;   //!
   TBranch        *b_ntrgObjects_hltEle25WPTight;   //!
   TBranch        *b_trgObjects_hltEle25WPTight_pt;   //!
   TBranch        *b_trgObjects_hltEle25WPTight_eta;   //!
   TBranch        *b_trgObjects_hltEle25WPTight_phi;   //!
   TBranch        *b_trgObjects_hltEle25WPTight_mass;   //!
   TBranch        *b_ntrgObjects_pfJets;   //!
   TBranch        *b_trgObjects_pfJets_pt;   //!
   TBranch        *b_nSubjetCA15subjetfiltered;   //!
   TBranch        *b_SubjetCA15subjetfiltered_pt;   //!
   TBranch        *b_SubjetCA15subjetfiltered_eta;   //!
   TBranch        *b_SubjetCA15subjetfiltered_phi;   //!
   TBranch        *b_SubjetCA15subjetfiltered_mass;   //!
   TBranch        *b_SubjetCA15subjetfiltered_btag;   //!
   TBranch        *b_SubjetCA15subjetfiltered_jetID;   //!
   TBranch        *b_SubjetCA15subjetfiltered_fromFJ;   //!
   TBranch        *b_nvLeptons;   //!
   TBranch        *b_vLeptons_charge;   //!
   TBranch        *b_vLeptons_tightId;   //!
   TBranch        *b_vLeptons_eleCutIdCSA14_25ns_v1;   //!
   TBranch        *b_vLeptons_eleCutIdCSA14_50ns_v1;   //!
   TBranch        *b_vLeptons_eleCutIdSpring15_25ns_v1;   //!
   TBranch        *b_vLeptons_dxy;   //!
   TBranch        *b_vLeptons_dz;   //!
   TBranch        *b_vLeptons_edxy;   //!
   TBranch        *b_vLeptons_edz;   //!
   TBranch        *b_vLeptons_ip3d;   //!
   TBranch        *b_vLeptons_sip3d;   //!
   TBranch        *b_vLeptons_convVeto;   //!
   TBranch        *b_vLeptons_lostHits;   //!
   TBranch        *b_vLeptons_relIso03;   //!
   TBranch        *b_vLeptons_relIso04;   //!
   TBranch        *b_vLeptons_miniRelIso;   //!
   TBranch        *b_vLeptons_relIsoAn04;   //!
   TBranch        *b_vLeptons_tightCharge;   //!
   TBranch        *b_vLeptons_mcMatchId;   //!
   TBranch        *b_vLeptons_mcMatchAny;   //!
   TBranch        *b_vLeptons_mcMatchTau;   //!
   TBranch        *b_vLeptons_mcPt;   //!
   TBranch        *b_vLeptons_mediumMuonId;   //!
   TBranch        *b_vLeptons_pdgId;   //!
   TBranch        *b_vLeptons_pt;   //!
   TBranch        *b_vLeptons_eta;   //!
   TBranch        *b_vLeptons_phi;   //!
   TBranch        *b_vLeptons_mass;   //!
   TBranch        *b_vLeptons_looseIdSusy;   //!
   TBranch        *b_vLeptons_looseIdPOG;   //!
   TBranch        *b_vLeptons_chargedHadRelIso03;   //!
   TBranch        *b_vLeptons_chargedHadRelIso04;   //!
   TBranch        *b_vLeptons_eleSieie;   //!
   TBranch        *b_vLeptons_eleDEta;   //!
   TBranch        *b_vLeptons_eleDPhi;   //!
   TBranch        *b_vLeptons_eleHoE;   //!
   TBranch        *b_vLeptons_eleMissingHits;   //!
   TBranch        *b_vLeptons_eleChi2;   //!
   TBranch        *b_vLeptons_convVetoFull;   //!
   TBranch        *b_vLeptons_eleMVArawSpring15Trig;   //!
   TBranch        *b_vLeptons_eleMVAIdSpring15Trig;   //!
   TBranch        *b_vLeptons_eleMVArawSpring15NonTrig;   //!
   TBranch        *b_vLeptons_eleMVAIdSpring15NonTrig;   //!
   TBranch        *b_vLeptons_nStations;   //!
   TBranch        *b_vLeptons_trkKink;   //!
   TBranch        *b_vLeptons_segmentCompatibility;   //!
   TBranch        *b_vLeptons_caloCompatibility;   //!
   TBranch        *b_vLeptons_globalTrackChi2;   //!
   TBranch        *b_vLeptons_nChamberHits;   //!
   TBranch        *b_vLeptons_isPFMuon;   //!
   TBranch        *b_vLeptons_isGlobalMuon;   //!
   TBranch        *b_vLeptons_isTrackerMuon;   //!
   TBranch        *b_vLeptons_pixelHits;   //!
   TBranch        *b_vLeptons_trackerLayers;   //!
   TBranch        *b_vLeptons_pixelLayers;   //!
   TBranch        *b_vLeptons_mvaTTH;   //!
   TBranch        *b_vLeptons_jetOverlapIdx;   //!
   TBranch        *b_vLeptons_jetPtRatio;   //!
   TBranch        *b_vLeptons_jetBTagCSV;   //!
   TBranch        *b_vLeptons_jetDR;   //!
   TBranch        *b_vLeptons_mvaTTHjetPtRatio;   //!
   TBranch        *b_vLeptons_mvaTTHjetBTagCSV;   //!
   TBranch        *b_vLeptons_mvaTTHjetDR;   //!
   TBranch        *b_vLeptons_pfRelIso03;   //!
   TBranch        *b_vLeptons_pfRelIso04;   //!
   TBranch        *b_vLeptons_etaSc;   //!
   TBranch        *b_vLeptons_eleExpMissingInnerHits;   //!
   TBranch        *b_vLeptons_eleooEmooP;   //!
   TBranch        *b_vLeptons_dr03TkSumPt;   //!
   TBranch        *b_vLeptons_eleEcalClusterIso;   //!
   TBranch        *b_vLeptons_eleHcalClusterIso;   //!
   TBranch        *b_vLeptons_miniIsoCharged;   //!
   TBranch        *b_vLeptons_miniIsoNeutral;   //!
   TBranch        *b_vLeptons_mvaTTHjetPtRel;   //!
   TBranch        *b_vLeptons_mvaTTHjetNDauChargedMVASel;   //!
   TBranch        *b_vLeptons_uncalibratedPt;   //!
   TBranch        *b_vLeptons_SF_IsoLoose;   //!
   TBranch        *b_vLeptons_SFerr_IsoLoose;   //!
   TBranch        *b_vLeptons_SF_IsoTight;   //!
   TBranch        *b_vLeptons_SFerr_IsoTight;   //!
   TBranch        *b_vLeptons_SF_IdCutLoose;   //!
   TBranch        *b_vLeptons_SFerr_IdCutLoose;   //!
   TBranch        *b_vLeptons_SF_IdCutTight;   //!
   TBranch        *b_vLeptons_SFerr_IdCutTight;   //!
   TBranch        *b_vLeptons_SF_IdMVALoose;   //!
   TBranch        *b_vLeptons_SFerr_IdMVALoose;   //!
   TBranch        *b_vLeptons_SF_IdMVATight;   //!
   TBranch        *b_vLeptons_SFerr_IdMVATight;   //!
   TBranch        *b_vLeptons_SF_HLT_RunD4p3;   //!
   TBranch        *b_vLeptons_SFerr_HLT_RunD4p3;   //!
   TBranch        *b_vLeptons_SF_HLT_RunD4p2;   //!
   TBranch        *b_vLeptons_SFerr_HLT_RunD4p2;   //!
   TBranch        *b_vLeptons_SF_HLT_RunC;   //!
   TBranch        *b_vLeptons_SFerr_HLT_RunC;   //!
   TBranch        *b_vLeptons_Eff_HLT_RunD4p3;   //!
   TBranch        *b_vLeptons_Efferr_HLT_RunD4p3;   //!
   TBranch        *b_vLeptons_Eff_HLT_RunD4p2;   //!
   TBranch        *b_vLeptons_Efferr_HLT_RunD4p2;   //!
   TBranch        *b_vLeptons_Eff_HLT_RunC;   //!
   TBranch        *b_vLeptons_Efferr_HLT_RunC;   //!
   TBranch        *b_ntrgObjects_hltBTagCaloCSVp014DoubleWithMatching;   //!
   TBranch        *b_trgObjects_hltBTagCaloCSVp014DoubleWithMatching_pt;   //!
   TBranch        *b_trgObjects_hltBTagCaloCSVp014DoubleWithMatching_eta;   //!
   TBranch        *b_trgObjects_hltBTagCaloCSVp014DoubleWithMatching_phi;   //!
   TBranch        *b_trgObjects_hltBTagCaloCSVp014DoubleWithMatching_mass;   //!
   TBranch        *b_npileUpVertex_z;   //!
   TBranch        *b_pileUpVertex_z;   //!
   TBranch        *b_ntrgObjects_pfMht;   //!
   TBranch        *b_trgObjects_pfMht_pt;   //!
   TBranch        *b_nGenBQuarkFromTop;   //!
   TBranch        *b_GenBQuarkFromTop_pdgId;   //!
   TBranch        *b_GenBQuarkFromTop_pt;   //!
   TBranch        *b_GenBQuarkFromTop_eta;   //!
   TBranch        *b_GenBQuarkFromTop_phi;   //!
   TBranch        *b_GenBQuarkFromTop_mass;   //!
   TBranch        *b_GenBQuarkFromTop_charge;   //!
   TBranch        *b_GenBQuarkFromTop_status;   //!
   TBranch        *b_GenBQuarkFromTop_isPromptHard;   //!
   TBranch        *b_nGenHiggsBoson;   //!
   TBranch        *b_GenHiggsBoson_pdgId;   //!
   TBranch        *b_GenHiggsBoson_pt;   //!
   TBranch        *b_GenHiggsBoson_eta;   //!
   TBranch        *b_GenHiggsBoson_phi;   //!
   TBranch        *b_GenHiggsBoson_mass;   //!
   TBranch        *b_GenHiggsBoson_charge;   //!
   TBranch        *b_GenHiggsBoson_status;   //!
   TBranch        *b_GenHiggsBoson_isPromptHard;   //!
   TBranch        *b_nLHE_weights_scale;   //!
   TBranch        *b_LHE_weights_scale_id;   //!
   TBranch        *b_LHE_weights_scale_wgt;   //!
   TBranch        *b_nGenLepFromTauRecovered;   //!
   TBranch        *b_GenLepFromTauRecovered_pdgId;   //!
   TBranch        *b_GenLepFromTauRecovered_pt;   //!
   TBranch        *b_GenLepFromTauRecovered_eta;   //!
   TBranch        *b_GenLepFromTauRecovered_phi;   //!
   TBranch        *b_GenLepFromTauRecovered_mass;   //!
   TBranch        *b_GenLepFromTauRecovered_charge;   //!
   TBranch        *b_GenLepFromTauRecovered_status;   //!
   TBranch        *b_GenLepFromTauRecovered_isPromptHard;   //!
   TBranch        *b_nFatjetCA15pruned;   //!
   TBranch        *b_FatjetCA15pruned_pt;   //!
   TBranch        *b_FatjetCA15pruned_eta;   //!
   TBranch        *b_FatjetCA15pruned_phi;   //!
   TBranch        *b_FatjetCA15pruned_mass;   //!
   TBranch        *b_ntrgObjects_hltVBFCaloJetEtaSortedMqq150Deta1p5;   //!
   TBranch        *b_ntrgObjects_caloMht;   //!
   TBranch        *b_trgObjects_caloMht_pt;   //!
   TBranch        *b_ntrgObjects_hltDoubleCentralJet90;   //!
   TBranch        *b_nGenJet;   //!
   TBranch        *b_GenJet_charge;   //!
   TBranch        *b_GenJet_status;   //!
   TBranch        *b_GenJet_isPromptHard;   //!
   TBranch        *b_GenJet_pdgId;   //!
   TBranch        *b_GenJet_pt;   //!
   TBranch        *b_GenJet_eta;   //!
   TBranch        *b_GenJet_phi;   //!
   TBranch        *b_GenJet_mass;   //!
   TBranch        *b_GenJet_numBHadrons;   //!
   TBranch        *b_GenJet_numCHadrons;   //!
   TBranch        *b_GenJet_numBHadronsFromTop;   //!
   TBranch        *b_GenJet_numCHadronsFromTop;   //!
   TBranch        *b_GenJet_numBHadronsAfterTop;   //!
   TBranch        *b_GenJet_numCHadronsAfterTop;   //!
   TBranch        *b_GenJet_wNuPt;   //!
   TBranch        *b_GenJet_wNuEta;   //!
   TBranch        *b_GenJet_wNuPhi;   //!
   TBranch        *b_GenJet_wNuM;   //!
   TBranch        *b_ntrgObjects_hltDoublePFJetsC100;   //!
   TBranch        *b_trgObjects_hltDoublePFJetsC100_pt;   //!
   TBranch        *b_trgObjects_hltDoublePFJetsC100_eta;   //!
   TBranch        *b_trgObjects_hltDoublePFJetsC100_phi;   //!
   TBranch        *b_trgObjects_hltDoublePFJetsC100_mass;   //!
   TBranch        *b_nSubjetCA15pruned;   //!
   TBranch        *b_SubjetCA15pruned_pt;   //!
   TBranch        *b_SubjetCA15pruned_eta;   //!
   TBranch        *b_SubjetCA15pruned_phi;   //!
   TBranch        *b_SubjetCA15pruned_mass;   //!
   TBranch        *b_SubjetCA15pruned_btag;   //!
   TBranch        *b_SubjetCA15pruned_jetID;   //!
   TBranch        *b_SubjetCA15pruned_fromFJ;   //!
   TBranch        *b_ntrgObjects_caloMet;   //!
   TBranch        *b_trgObjects_caloMet_pt;   //!
   TBranch        *b_nFatjetCA15ungroomed;   //!
   TBranch        *b_FatjetCA15ungroomed_pt;   //!
   TBranch        *b_FatjetCA15ungroomed_eta;   //!
   TBranch        *b_FatjetCA15ungroomed_phi;   //!
   TBranch        *b_FatjetCA15ungroomed_mass;   //!
   TBranch        *b_FatjetCA15ungroomed_tau1;   //!
   TBranch        *b_FatjetCA15ungroomed_tau2;   //!
   TBranch        *b_FatjetCA15ungroomed_tau3;   //!
   TBranch        *b_FatjetCA15ungroomed_bbtag;   //!
   TBranch        *b_ntrgObjects_pfMet;   //!
   TBranch        *b_trgObjects_pfMet_pt;   //!
   TBranch        *b_ntrgObjects_pfHt;   //!
   TBranch        *b_trgObjects_pfHt_pt;   //!
   TBranch        *b_ndRaddJetsdR08;   //!
   TBranch        *b_dRaddJetsdR08;   //!
   TBranch        *b_nGenBQuarkFromH;   //!
   TBranch        *b_GenBQuarkFromH_pdgId;   //!
   TBranch        *b_GenBQuarkFromH_pt;   //!
   TBranch        *b_GenBQuarkFromH_eta;   //!
   TBranch        *b_GenBQuarkFromH_phi;   //!
   TBranch        *b_GenBQuarkFromH_mass;   //!
   TBranch        *b_GenBQuarkFromH_charge;   //!
   TBranch        *b_GenBQuarkFromH_status;   //!
   TBranch        *b_GenBQuarkFromH_isPromptHard;   //!
   TBranch        *b_ntrgObjects_hltDoubleJet65;   //!
   TBranch        *b_nFatjetCA15trimmed;   //!
   TBranch        *b_FatjetCA15trimmed_pt;   //!
   TBranch        *b_FatjetCA15trimmed_eta;   //!
   TBranch        *b_FatjetCA15trimmed_phi;   //!
   TBranch        *b_FatjetCA15trimmed_mass;   //!
   TBranch        *b_nGenHiggsSisters;   //!
   TBranch        *b_GenHiggsSisters_pdgId;   //!
   TBranch        *b_GenHiggsSisters_pt;   //!
   TBranch        *b_GenHiggsSisters_eta;   //!
   TBranch        *b_GenHiggsSisters_phi;   //!
   TBranch        *b_GenHiggsSisters_mass;   //!
   TBranch        *b_GenHiggsSisters_charge;   //!
   TBranch        *b_GenHiggsSisters_status;   //!
   TBranch        *b_GenHiggsSisters_isPromptHard;   //!
   TBranch        *b_ntrgObjects_hltBTagCaloCSVp026DoubleWithMatching;   //!
   TBranch        *b_trgObjects_hltBTagCaloCSVp026DoubleWithMatching_pt;   //!
   TBranch        *b_trgObjects_hltBTagCaloCSVp026DoubleWithMatching_eta;   //!
   TBranch        *b_trgObjects_hltBTagCaloCSVp026DoubleWithMatching_phi;   //!
   TBranch        *b_trgObjects_hltBTagCaloCSVp026DoubleWithMatching_mass;   //!
   TBranch        *b_naLeptons;   //!
   TBranch        *b_aLeptons_charge;   //!
   TBranch        *b_aLeptons_tightId;   //!
   TBranch        *b_aLeptons_eleCutIdCSA14_25ns_v1;   //!
   TBranch        *b_aLeptons_eleCutIdCSA14_50ns_v1;   //!
   TBranch        *b_aLeptons_eleCutIdSpring15_25ns_v1;   //!
   TBranch        *b_aLeptons_dxy;   //!
   TBranch        *b_aLeptons_dz;   //!
   TBranch        *b_aLeptons_edxy;   //!
   TBranch        *b_aLeptons_edz;   //!
   TBranch        *b_aLeptons_ip3d;   //!
   TBranch        *b_aLeptons_sip3d;   //!
   TBranch        *b_aLeptons_convVeto;   //!
   TBranch        *b_aLeptons_lostHits;   //!
   TBranch        *b_aLeptons_relIso03;   //!
   TBranch        *b_aLeptons_relIso04;   //!
   TBranch        *b_aLeptons_miniRelIso;   //!
   TBranch        *b_aLeptons_relIsoAn04;   //!
   TBranch        *b_aLeptons_tightCharge;   //!
   TBranch        *b_aLeptons_mcMatchId;   //!
   TBranch        *b_aLeptons_mcMatchAny;   //!
   TBranch        *b_aLeptons_mcMatchTau;   //!
   TBranch        *b_aLeptons_mcPt;   //!
   TBranch        *b_aLeptons_mediumMuonId;   //!
   TBranch        *b_aLeptons_pdgId;   //!
   TBranch        *b_aLeptons_pt;   //!
   TBranch        *b_aLeptons_eta;   //!
   TBranch        *b_aLeptons_phi;   //!
   TBranch        *b_aLeptons_mass;   //!
   TBranch        *b_aLeptons_looseIdSusy;   //!
   TBranch        *b_aLeptons_looseIdPOG;   //!
   TBranch        *b_aLeptons_chargedHadRelIso03;   //!
   TBranch        *b_aLeptons_chargedHadRelIso04;   //!
   TBranch        *b_aLeptons_eleSieie;   //!
   TBranch        *b_aLeptons_eleDEta;   //!
   TBranch        *b_aLeptons_eleDPhi;   //!
   TBranch        *b_aLeptons_eleHoE;   //!
   TBranch        *b_aLeptons_eleMissingHits;   //!
   TBranch        *b_aLeptons_eleChi2;   //!
   TBranch        *b_aLeptons_convVetoFull;   //!
   TBranch        *b_aLeptons_eleMVArawSpring15Trig;   //!
   TBranch        *b_aLeptons_eleMVAIdSpring15Trig;   //!
   TBranch        *b_aLeptons_eleMVArawSpring15NonTrig;   //!
   TBranch        *b_aLeptons_eleMVAIdSpring15NonTrig;   //!
   TBranch        *b_aLeptons_nStations;   //!
   TBranch        *b_aLeptons_trkKink;   //!
   TBranch        *b_aLeptons_segmentCompatibility;   //!
   TBranch        *b_aLeptons_caloCompatibility;   //!
   TBranch        *b_aLeptons_globalTrackChi2;   //!
   TBranch        *b_aLeptons_nChamberHits;   //!
   TBranch        *b_aLeptons_isPFMuon;   //!
   TBranch        *b_aLeptons_isGlobalMuon;   //!
   TBranch        *b_aLeptons_isTrackerMuon;   //!
   TBranch        *b_aLeptons_pixelHits;   //!
   TBranch        *b_aLeptons_trackerLayers;   //!
   TBranch        *b_aLeptons_pixelLayers;   //!
   TBranch        *b_aLeptons_mvaTTH;   //!
   TBranch        *b_aLeptons_jetOverlapIdx;   //!
   TBranch        *b_aLeptons_jetPtRatio;   //!
   TBranch        *b_aLeptons_jetBTagCSV;   //!
   TBranch        *b_aLeptons_jetDR;   //!
   TBranch        *b_aLeptons_mvaTTHjetPtRatio;   //!
   TBranch        *b_aLeptons_mvaTTHjetBTagCSV;   //!
   TBranch        *b_aLeptons_mvaTTHjetDR;   //!
   TBranch        *b_aLeptons_pfRelIso03;   //!
   TBranch        *b_aLeptons_pfRelIso04;   //!
   TBranch        *b_aLeptons_etaSc;   //!
   TBranch        *b_aLeptons_eleExpMissingInnerHits;   //!
   TBranch        *b_aLeptons_eleooEmooP;   //!
   TBranch        *b_aLeptons_dr03TkSumPt;   //!
   TBranch        *b_aLeptons_eleEcalClusterIso;   //!
   TBranch        *b_aLeptons_eleHcalClusterIso;   //!
   TBranch        *b_aLeptons_miniIsoCharged;   //!
   TBranch        *b_aLeptons_miniIsoNeutral;   //!
   TBranch        *b_aLeptons_mvaTTHjetPtRel;   //!
   TBranch        *b_aLeptons_mvaTTHjetNDauChargedMVASel;   //!
   TBranch        *b_aLeptons_uncalibratedPt;   //!
   TBranch        *b_aLeptons_SF_IsoLoose;   //!
   TBranch        *b_aLeptons_SFerr_IsoLoose;   //!
   TBranch        *b_aLeptons_SF_IsoTight;   //!
   TBranch        *b_aLeptons_SFerr_IsoTight;   //!
   TBranch        *b_aLeptons_SF_IdCutLoose;   //!
   TBranch        *b_aLeptons_SFerr_IdCutLoose;   //!
   TBranch        *b_aLeptons_SF_IdCutTight;   //!
   TBranch        *b_aLeptons_SFerr_IdCutTight;   //!
   TBranch        *b_aLeptons_SF_IdMVALoose;   //!
   TBranch        *b_aLeptons_SFerr_IdMVALoose;   //!
   TBranch        *b_aLeptons_SF_IdMVATight;   //!
   TBranch        *b_aLeptons_SFerr_IdMVATight;   //!
   TBranch        *b_aLeptons_SF_HLT_RunD4p3;   //!
   TBranch        *b_aLeptons_SFerr_HLT_RunD4p3;   //!
   TBranch        *b_aLeptons_SF_HLT_RunD4p2;   //!
   TBranch        *b_aLeptons_SFerr_HLT_RunD4p2;   //!
   TBranch        *b_aLeptons_SF_HLT_RunC;   //!
   TBranch        *b_aLeptons_SFerr_HLT_RunC;   //!
   TBranch        *b_aLeptons_Eff_HLT_RunD4p3;   //!
   TBranch        *b_aLeptons_Efferr_HLT_RunD4p3;   //!
   TBranch        *b_aLeptons_Eff_HLT_RunD4p2;   //!
   TBranch        *b_aLeptons_Efferr_HLT_RunD4p2;   //!
   TBranch        *b_aLeptons_Eff_HLT_RunC;   //!
   TBranch        *b_aLeptons_Efferr_HLT_RunC;   //!
   TBranch        *b_ntrgObjects_hltPFQuadJetLooseID15;   //!
   TBranch        *b_ntrgObjects_hltQuadPFCentralJetLooseID45;   //!
   TBranch        *b_ntrgObjects_hltBTagCaloCSVp067Single;   //!
   TBranch        *b_ntrgObjects_hltVBFPFJetCSVSortedMqq200Detaqq1p2;   //!
   TBranch        *b_nhjidxaddJetsdR08;   //!
   TBranch        *b_hjidxaddJetsdR08;   //!
   TBranch        *b_ntrgObjects_hltMHTNoPU90;   //!
   TBranch        *b_nFatjetAK08ungroomed;   //!
   TBranch        *b_FatjetAK08ungroomed_pt;   //!
   TBranch        *b_FatjetAK08ungroomed_eta;   //!
   TBranch        *b_FatjetAK08ungroomed_phi;   //!
   TBranch        *b_FatjetAK08ungroomed_mass;   //!
   TBranch        *b_FatjetAK08ungroomed_tau1;   //!
   TBranch        *b_FatjetAK08ungroomed_tau2;   //!
   TBranch        *b_FatjetAK08ungroomed_tau3;   //!
   TBranch        *b_FatjetAK08ungroomed_msoftdrop;   //!
   TBranch        *b_FatjetAK08ungroomed_mpruned;   //!
   TBranch        *b_FatjetAK08ungroomed_mprunedcorr;   //!
   TBranch        *b_FatjetAK08ungroomed_JEC_L2L3;   //!
   TBranch        *b_FatjetAK08ungroomed_JEC_L1L2L3;   //!
   TBranch        *b_FatjetAK08ungroomed_JEC_L2L3Unc;   //!
   TBranch        *b_FatjetAK08ungroomed_JEC_L1L2L3Unc;   //!
   TBranch        *b_FatjetAK08ungroomed_bbtag;   //!
   TBranch        *b_FatjetAK08ungroomed_id_Tight;   //!
   TBranch        *b_FatjetAK08ungroomed_numberOfDaughters;   //!
   TBranch        *b_FatjetAK08ungroomed_neutralEmEnergyFraction;   //!
   TBranch        *b_FatjetAK08ungroomed_neutralHadronEnergyFraction;   //!
   TBranch        *b_FatjetAK08ungroomed_muonEnergyFraction;   //!
   TBranch        *b_FatjetAK08ungroomed_chargedEmEnergyFraction;   //!
   TBranch        *b_FatjetAK08ungroomed_chargedHadronEnergyFraction;   //!
   TBranch        *b_FatjetAK08ungroomed_chargedMultiplicity;   //!
   TBranch        *b_FatjetAK08ungroomed_Flavour;   //!
   TBranch        *b_FatjetAK08ungroomed_BhadronFlavour;   //!
   TBranch        *b_FatjetAK08ungroomed_ChadronFlavour;   //!
   TBranch        *b_FatjetAK08ungroomed_GenPt;   //!
   TBranch        *b_FatjetAK08ungroomed_PFLepton_ptrel;   //!
   TBranch        *b_FatjetAK08ungroomed_z_ratio;   //!
   TBranch        *b_FatjetAK08ungroomed_PFLepton_IP2D;   //!
   TBranch        *b_FatjetAK08ungroomed_nSL;   //!
   TBranch        *b_FatjetAK08ungroomed_tau1_trackEtaRel_0;   //!
   TBranch        *b_FatjetAK08ungroomed_tau1_trackEtaRel_1;   //!
   TBranch        *b_FatjetAK08ungroomed_tau1_trackEtaRel_2;   //!
   TBranch        *b_FatjetAK08ungroomed_tau0_trackEtaRel_0;   //!
   TBranch        *b_FatjetAK08ungroomed_tau0_trackEtaRel_1;   //!
   TBranch        *b_FatjetAK08ungroomed_tau0_trackEtaRel_2;   //!
   TBranch        *b_FatjetAK08ungroomed_tau_vertexMass_0;   //!
   TBranch        *b_FatjetAK08ungroomed_tau_vertexEnergyRatio_0;   //!
   TBranch        *b_FatjetAK08ungroomed_tau_vertexDeltaR_0;   //!
   TBranch        *b_FatjetAK08ungroomed_tau_flightDistance2dSig_0;   //!
   TBranch        *b_FatjetAK08ungroomed_tau_vertexMass_1;   //!
   TBranch        *b_FatjetAK08ungroomed_tau_vertexEnergyRatio_1;   //!
   TBranch        *b_FatjetAK08ungroomed_tau_flightDistance2dSig_1;   //!
   TBranch        *b_FatjetAK08ungroomed_nSV;   //!
   TBranch        *b_ntrgObjects_hltPFMHTTightID90;   //!
   TBranch        *b_ntrgObjects_hltQuadCentralJet45;   //!
   TBranch        *b_ntrgObjects_hltBTagCaloCSVp022Single;   //!
   TBranch        *b_naJCidx;   //!
   TBranch        *b_aJCidx;   //!
   TBranch        *b_nselLeptons;   //!
   TBranch        *b_selLeptons_charge;   //!
   TBranch        *b_selLeptons_tightId;   //!
   TBranch        *b_selLeptons_eleCutIdCSA14_25ns_v1;   //!
   TBranch        *b_selLeptons_eleCutIdCSA14_50ns_v1;   //!
   TBranch        *b_selLeptons_eleCutIdSpring15_25ns_v1;   //!
   TBranch        *b_selLeptons_dxy;   //!
   TBranch        *b_selLeptons_dz;   //!
   TBranch        *b_selLeptons_edxy;   //!
   TBranch        *b_selLeptons_edz;   //!
   TBranch        *b_selLeptons_ip3d;   //!
   TBranch        *b_selLeptons_sip3d;   //!
   TBranch        *b_selLeptons_convVeto;   //!
   TBranch        *b_selLeptons_lostHits;   //!
   TBranch        *b_selLeptons_relIso03;   //!
   TBranch        *b_selLeptons_relIso04;   //!
   TBranch        *b_selLeptons_miniRelIso;   //!
   TBranch        *b_selLeptons_relIsoAn04;   //!
   TBranch        *b_selLeptons_tightCharge;   //!
   TBranch        *b_selLeptons_mcMatchId;   //!
   TBranch        *b_selLeptons_mcMatchAny;   //!
   TBranch        *b_selLeptons_mcMatchTau;   //!
   TBranch        *b_selLeptons_mcPt;   //!
   TBranch        *b_selLeptons_mediumMuonId;   //!
   TBranch        *b_selLeptons_pdgId;   //!
   TBranch        *b_selLeptons_pt;   //!
   TBranch        *b_selLeptons_eta;   //!
   TBranch        *b_selLeptons_phi;   //!
   TBranch        *b_selLeptons_mass;   //!
   TBranch        *b_selLeptons_looseIdSusy;   //!
   TBranch        *b_selLeptons_looseIdPOG;   //!
   TBranch        *b_selLeptons_chargedHadRelIso03;   //!
   TBranch        *b_selLeptons_chargedHadRelIso04;   //!
   TBranch        *b_selLeptons_eleSieie;   //!
   TBranch        *b_selLeptons_eleDEta;   //!
   TBranch        *b_selLeptons_eleDPhi;   //!
   TBranch        *b_selLeptons_eleHoE;   //!
   TBranch        *b_selLeptons_eleMissingHits;   //!
   TBranch        *b_selLeptons_eleChi2;   //!
   TBranch        *b_selLeptons_convVetoFull;   //!
   TBranch        *b_selLeptons_eleMVArawSpring15Trig;   //!
   TBranch        *b_selLeptons_eleMVAIdSpring15Trig;   //!
   TBranch        *b_selLeptons_eleMVArawSpring15NonTrig;   //!
   TBranch        *b_selLeptons_eleMVAIdSpring15NonTrig;   //!
   TBranch        *b_selLeptons_nStations;   //!
   TBranch        *b_selLeptons_trkKink;   //!
   TBranch        *b_selLeptons_segmentCompatibility;   //!
   TBranch        *b_selLeptons_caloCompatibility;   //!
   TBranch        *b_selLeptons_globalTrackChi2;   //!
   TBranch        *b_selLeptons_nChamberHits;   //!
   TBranch        *b_selLeptons_isPFMuon;   //!
   TBranch        *b_selLeptons_isGlobalMuon;   //!
   TBranch        *b_selLeptons_isTrackerMuon;   //!
   TBranch        *b_selLeptons_pixelHits;   //!
   TBranch        *b_selLeptons_trackerLayers;   //!
   TBranch        *b_selLeptons_pixelLayers;   //!
   TBranch        *b_selLeptons_mvaTTH;   //!
   TBranch        *b_selLeptons_jetOverlapIdx;   //!
   TBranch        *b_selLeptons_jetPtRatio;   //!
   TBranch        *b_selLeptons_jetBTagCSV;   //!
   TBranch        *b_selLeptons_jetDR;   //!
   TBranch        *b_selLeptons_mvaTTHjetPtRatio;   //!
   TBranch        *b_selLeptons_mvaTTHjetBTagCSV;   //!
   TBranch        *b_selLeptons_mvaTTHjetDR;   //!
   TBranch        *b_selLeptons_pfRelIso03;   //!
   TBranch        *b_selLeptons_pfRelIso04;   //!
   TBranch        *b_selLeptons_etaSc;   //!
   TBranch        *b_selLeptons_eleExpMissingInnerHits;   //!
   TBranch        *b_selLeptons_eleooEmooP;   //!
   TBranch        *b_selLeptons_dr03TkSumPt;   //!
   TBranch        *b_selLeptons_eleEcalClusterIso;   //!
   TBranch        *b_selLeptons_eleHcalClusterIso;   //!
   TBranch        *b_selLeptons_miniIsoCharged;   //!
   TBranch        *b_selLeptons_miniIsoNeutral;   //!
   TBranch        *b_selLeptons_mvaTTHjetPtRel;   //!
   TBranch        *b_selLeptons_mvaTTHjetNDauChargedMVASel;   //!
   TBranch        *b_selLeptons_uncalibratedPt;   //!
   TBranch        *b_selLeptons_SF_IsoLoose;   //!
   TBranch        *b_selLeptons_SFerr_IsoLoose;   //!
   TBranch        *b_selLeptons_SF_IsoTight;   //!
   TBranch        *b_selLeptons_SFerr_IsoTight;   //!
   TBranch        *b_selLeptons_SF_IdCutLoose;   //!
   TBranch        *b_selLeptons_SFerr_IdCutLoose;   //!
   TBranch        *b_selLeptons_SF_IdCutTight;   //!
   TBranch        *b_selLeptons_SFerr_IdCutTight;   //!
   TBranch        *b_selLeptons_SF_IdMVALoose;   //!
   TBranch        *b_selLeptons_SFerr_IdMVALoose;   //!
   TBranch        *b_selLeptons_SF_IdMVATight;   //!
   TBranch        *b_selLeptons_SFerr_IdMVATight;   //!
   TBranch        *b_selLeptons_SF_HLT_RunD4p3;   //!
   TBranch        *b_selLeptons_SFerr_HLT_RunD4p3;   //!
   TBranch        *b_selLeptons_SF_HLT_RunD4p2;   //!
   TBranch        *b_selLeptons_SFerr_HLT_RunD4p2;   //!
   TBranch        *b_selLeptons_SF_HLT_RunC;   //!
   TBranch        *b_selLeptons_SFerr_HLT_RunC;   //!
   TBranch        *b_selLeptons_Eff_HLT_RunD4p3;   //!
   TBranch        *b_selLeptons_Efferr_HLT_RunD4p3;   //!
   TBranch        *b_selLeptons_Eff_HLT_RunD4p2;   //!
   TBranch        *b_selLeptons_Efferr_HLT_RunD4p2;   //!
   TBranch        *b_selLeptons_Eff_HLT_RunC;   //!
   TBranch        *b_selLeptons_Efferr_HLT_RunC;   //!
   TBranch        *b_ntrgObjects_hltPFMET90;   //!
   TBranch        *b_ntrgObjects_hltQuadJet15;   //!
   TBranch        *b_nTauGood;   //!
   TBranch        *b_TauGood_charge;   //!
   TBranch        *b_TauGood_decayMode;   //!
   TBranch        *b_TauGood_idDecayMode;   //!
   TBranch        *b_TauGood_idDecayModeNewDMs;   //!
   TBranch        *b_TauGood_dxy;   //!
   TBranch        *b_TauGood_dz;   //!
   TBranch        *b_TauGood_idMVArun2;   //!
   TBranch        *b_TauGood_rawMVArun2;   //!
   TBranch        *b_TauGood_idMVArun2dR03;   //!
   TBranch        *b_TauGood_rawMVArun2dR03;   //!
   TBranch        *b_TauGood_idMVArun2NewDM;   //!
   TBranch        *b_TauGood_rawMVArun2NewDM;   //!
   TBranch        *b_TauGood_idCI3hit;   //!
   TBranch        *b_TauGood_idAntiMu;   //!
   TBranch        *b_TauGood_idAntiErun2;   //!
   TBranch        *b_TauGood_isoCI3hit;   //!
   TBranch        *b_TauGood_photonOutsideSigCone;   //!
   TBranch        *b_TauGood_mcMatchId;   //!
   TBranch        *b_TauGood_pdgId;   //!
   TBranch        *b_TauGood_pt;   //!
   TBranch        *b_TauGood_eta;   //!
   TBranch        *b_TauGood_phi;   //!
   TBranch        *b_TauGood_mass;   //!
   TBranch        *b_TauGood_idxJetMatch;   //!
   TBranch        *b_TauGood_genMatchType;   //!
   TBranch        *b_nhJidx;   //!
   TBranch        *b_hJidx;   //!
   TBranch        *b_nGenLepRecovered;   //!
   TBranch        *b_GenLepRecovered_pdgId;   //!
   TBranch        *b_GenLepRecovered_pt;   //!
   TBranch        *b_GenLepRecovered_eta;   //!
   TBranch        *b_GenLepRecovered_phi;   //!
   TBranch        *b_GenLepRecovered_mass;   //!
   TBranch        *b_GenLepRecovered_charge;   //!
   TBranch        *b_GenLepRecovered_status;   //!
   TBranch        *b_GenLepRecovered_isPromptHard;   //!
   TBranch        *b_nFatjetCA15softdropz2b1;   //!
   TBranch        *b_FatjetCA15softdropz2b1_pt;   //!
   TBranch        *b_FatjetCA15softdropz2b1_eta;   //!
   TBranch        *b_FatjetCA15softdropz2b1_phi;   //!
   TBranch        *b_FatjetCA15softdropz2b1_mass;   //!
   TBranch        *b_FatjetCA15softdropz2b1_tau1;   //!
   TBranch        *b_FatjetCA15softdropz2b1_tau2;   //!
   TBranch        *b_FatjetCA15softdropz2b1_tau3;   //!
   TBranch        *b_nGenStatus2bHad;   //!
   TBranch        *b_GenStatus2bHad_pdgId;   //!
   TBranch        *b_GenStatus2bHad_pt;   //!
   TBranch        *b_GenStatus2bHad_eta;   //!
   TBranch        *b_GenStatus2bHad_phi;   //!
   TBranch        *b_GenStatus2bHad_mass;   //!
   TBranch        *b_GenStatus2bHad_charge;   //!
   TBranch        *b_GenStatus2bHad_status;   //!
   TBranch        *b_GenStatus2bHad_isPromptHard;   //!
   TBranch        *b_ntrgObjects_hltTripleJet50;   //!
   TBranch        *b_ntrgObjects_hltVBFPFJetCSVSortedMqq460Detaqq4p1;   //!
   TBranch        *b_nhttCandidates;   //!
   TBranch        *b_httCandidates_pt;   //!
   TBranch        *b_httCandidates_eta;   //!
   TBranch        *b_httCandidates_phi;   //!
   TBranch        *b_httCandidates_mass;   //!
   TBranch        *b_httCandidates_ptcal;   //!
   TBranch        *b_httCandidates_etacal;   //!
   TBranch        *b_httCandidates_phical;   //!
   TBranch        *b_httCandidates_masscal;   //!
   TBranch        *b_httCandidates_fRec;   //!
   TBranch        *b_httCandidates_Ropt;   //!
   TBranch        *b_httCandidates_RoptCalc;   //!
   TBranch        *b_httCandidates_ptForRoptCalc;   //!
   TBranch        *b_httCandidates_subjetIDPassed;   //!
   TBranch        *b_httCandidates_sjW1ptcal;   //!
   TBranch        *b_httCandidates_sjW1pt;   //!
   TBranch        *b_httCandidates_sjW1eta;   //!
   TBranch        *b_httCandidates_sjW1phi;   //!
   TBranch        *b_httCandidates_sjW1masscal;   //!
   TBranch        *b_httCandidates_sjW1mass;   //!
   TBranch        *b_httCandidates_sjW1btag;   //!
   TBranch        *b_httCandidates_sjW2ptcal;   //!
   TBranch        *b_httCandidates_sjW2pt;   //!
   TBranch        *b_httCandidates_sjW2eta;   //!
   TBranch        *b_httCandidates_sjW2phi;   //!
   TBranch        *b_httCandidates_sjW2masscal;   //!
   TBranch        *b_httCandidates_sjW2mass;   //!
   TBranch        *b_httCandidates_sjW2btag;   //!
   TBranch        *b_httCandidates_sjNonWptcal;   //!
   TBranch        *b_httCandidates_sjNonWpt;   //!
   TBranch        *b_httCandidates_sjNonWeta;   //!
   TBranch        *b_httCandidates_sjNonWphi;   //!
   TBranch        *b_httCandidates_sjNonWmasscal;   //!
   TBranch        *b_httCandidates_sjNonWmass;   //!
   TBranch        *b_httCandidates_sjNonWbtag;   //!
   TBranch        *b_ntrgObjects_hltBTagCaloCSVp087Triple;   //!
   TBranch        *b_nGenTaus;   //!
   TBranch        *b_GenTaus_pdgId;   //!
   TBranch        *b_GenTaus_pt;   //!
   TBranch        *b_GenTaus_eta;   //!
   TBranch        *b_GenTaus_phi;   //!
   TBranch        *b_GenTaus_mass;   //!
   TBranch        *b_GenTaus_charge;   //!
   TBranch        *b_GenTaus_status;   //!
   TBranch        *b_GenTaus_isPromptHard;   //!
   TBranch        *b_ntrgObjects_hltMHT70;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_Jet_id;   //!
   TBranch        *b_Jet_puId;   //!
   TBranch        *b_Jet_btagCSV;   //!
   TBranch        *b_Jet_btagCMVA;   //!
   TBranch        *b_Jet_rawPt;   //!
   TBranch        *b_Jet_mcPt;   //!
   TBranch        *b_Jet_mcFlavour;   //!
   TBranch        *b_Jet_partonFlavour;   //!
   TBranch        *b_Jet_hadronFlavour;   //!
   TBranch        *b_Jet_mcMatchId;   //!
   TBranch        *b_Jet_corr_JECUp;   //!
   TBranch        *b_Jet_corr_JECDown;   //!
   TBranch        *b_Jet_corr;   //!
   TBranch        *b_Jet_corr_JERUp;   //!
   TBranch        *b_Jet_corr_JERDown;   //!
   TBranch        *b_Jet_corr_JER;   //!
   TBranch        *b_Jet_pt;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_mass;   //!
   TBranch        *b_Jet_rawPtAfterSmearing;   //!
   TBranch        *b_Jet_idxFirstTauMatch;   //!
   TBranch        *b_Jet_heppyFlavour;   //!
   TBranch        *b_Jet_ctagVsL;   //!
   TBranch        *b_Jet_ctagVsB;   //!
   TBranch        *b_Jet_btagBDT;   //!
   TBranch        *b_Jet_btagProb;   //!
   TBranch        *b_Jet_btagBProb;   //!
   TBranch        *b_Jet_btagSoftEl;   //!
   TBranch        *b_Jet_btagSoftMu;   //!
   TBranch        *b_Jet_btagnew;   //!
   TBranch        *b_Jet_btagCSVV0;   //!
   TBranch        *b_Jet_btagCMVAV2;   //!
   TBranch        *b_Jet_chHEF;   //!
   TBranch        *b_Jet_neHEF;   //!
   TBranch        *b_Jet_chEmEF;   //!
   TBranch        *b_Jet_neEmEF;   //!
   TBranch        *b_Jet_muEF;   //!
   TBranch        *b_Jet_chMult;   //!
   TBranch        *b_Jet_nhMult;   //!
   TBranch        *b_Jet_leadTrackPt;   //!
   TBranch        *b_Jet_mcEta;   //!
   TBranch        *b_Jet_mcPhi;   //!
   TBranch        *b_Jet_mcM;   //!
   TBranch        *b_Jet_leptonPdgId;   //!
   TBranch        *b_Jet_leptonPt;   //!
   TBranch        *b_Jet_leptonPtRel;   //!
   TBranch        *b_Jet_leptonPtRelInv;   //!
   TBranch        *b_Jet_leptonDeltaR;   //!
   TBranch        *b_Jet_leptonDeltaPhi;   //!
   TBranch        *b_Jet_leptonDeltaEta;   //!
   TBranch        *b_Jet_vtxMass;   //!
   TBranch        *b_Jet_vtxNtracks;   //!
   TBranch        *b_Jet_vtxPt;   //!
   TBranch        *b_Jet_vtx3DSig;   //!
   TBranch        *b_Jet_vtx3DVal;   //!
   TBranch        *b_Jet_vtxPosX;   //!
   TBranch        *b_Jet_vtxPosY;   //!
   TBranch        *b_Jet_vtxPosZ;   //!
   TBranch        *b_Jet_pullVectorPhi;   //!
   TBranch        *b_Jet_pullVectorMag;   //!
   TBranch        *b_Jet_qgl;   //!
   TBranch        *b_Jet_ptd;   //!
   TBranch        *b_Jet_axis2;   //!
   TBranch        *b_Jet_mult;   //!
   TBranch        *b_Jet_numberOfDaughters;   //!
   TBranch        *b_Jet_btagIdx;   //!
   TBranch        *b_Jet_mcIdx;   //!
   TBranch        *b_Jet_blike_VBF;   //!
   TBranch        *b_Jet_pt_reg;   //!
   TBranch        *b_Jet_pt_regVBF;   //!
   TBranch        *b_Jet_pt_reg_corrJECUp;   //!
   TBranch        *b_Jet_pt_regVBF_corrJECUp;   //!
   TBranch        *b_Jet_pt_reg_corrJECDown;   //!
   TBranch        *b_Jet_pt_regVBF_corrJECDown;   //!
   TBranch        *b_Jet_pt_reg_corrJERUp;   //!
   TBranch        *b_Jet_pt_regVBF_corrJERUp;   //!
   TBranch        *b_Jet_pt_reg_corrJERDown;   //!
   TBranch        *b_Jet_pt_regVBF_corrJERDown;   //!
   TBranch        *b_Jet_btagCSVL_SF;   //!
   TBranch        *b_Jet_btagCSVL_SF_up;   //!
   TBranch        *b_Jet_btagCSVL_SF_down;   //!
   TBranch        *b_Jet_btagCSVM_SF;   //!
   TBranch        *b_Jet_btagCSVM_SF_up;   //!
   TBranch        *b_Jet_btagCSVM_SF_down;   //!
   TBranch        *b_Jet_btagCSVT_SF;   //!
   TBranch        *b_Jet_btagCSVT_SF_up;   //!
   TBranch        *b_Jet_btagCSVT_SF_down;   //!
   TBranch        *b_Jet_btagWeightCSV;   //!
   TBranch        *b_Jet_btagWeightCSV_up_jes;   //!
   TBranch        *b_Jet_btagWeightCSV_down_jes;   //!
   TBranch        *b_Jet_btagWeightCSV_up_lf;   //!
   TBranch        *b_Jet_btagWeightCSV_down_lf;   //!
   TBranch        *b_Jet_btagWeightCSV_up_hf;   //!
   TBranch        *b_Jet_btagWeightCSV_down_hf;   //!
   TBranch        *b_Jet_btagWeightCSV_up_hfstats1;   //!
   TBranch        *b_Jet_btagWeightCSV_down_hfstats1;   //!
   TBranch        *b_Jet_btagWeightCSV_up_hfstats2;   //!
   TBranch        *b_Jet_btagWeightCSV_down_hfstats2;   //!
   TBranch        *b_Jet_btagWeightCSV_up_lfstats1;   //!
   TBranch        *b_Jet_btagWeightCSV_down_lfstats1;   //!
   TBranch        *b_Jet_btagWeightCSV_up_lfstats2;   //!
   TBranch        *b_Jet_btagWeightCSV_down_lfstats2;   //!
   TBranch        *b_Jet_btagWeightCSV_up_cferr1;   //!
   TBranch        *b_Jet_btagWeightCSV_down_cferr1;   //!
   TBranch        *b_Jet_btagWeightCSV_up_cferr2;   //!
   TBranch        *b_Jet_btagWeightCSV_down_cferr2;   //!
   TBranch        *b_Jet_btagCMVAV2L_SF;   //!
   TBranch        *b_Jet_btagCMVAV2L_SF_up;   //!
   TBranch        *b_Jet_btagCMVAV2L_SF_down;   //!
   TBranch        *b_Jet_btagCMVAV2M_SF;   //!
   TBranch        *b_Jet_btagCMVAV2M_SF_up;   //!
   TBranch        *b_Jet_btagCMVAV2M_SF_down;   //!
   TBranch        *b_Jet_btagCMVAV2T_SF;   //!
   TBranch        *b_Jet_btagCMVAV2T_SF_up;   //!
   TBranch        *b_Jet_btagCMVAV2T_SF_down;   //!
   TBranch        *b_Jet_btagWeightCMVAV2;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_up_jes;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_down_jes;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_up_lf;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_down_lf;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_up_hf;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_down_hf;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_up_hfstats1;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_down_hfstats1;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_up_hfstats2;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_down_hfstats2;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_up_lfstats1;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_down_lfstats1;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_up_lfstats2;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_down_lfstats2;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_up_cferr1;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_down_cferr1;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_up_cferr2;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_down_cferr2;   //!
   TBranch        *b_nFatjetCA15softdrop;   //!
   TBranch        *b_FatjetCA15softdrop_pt;   //!
   TBranch        *b_FatjetCA15softdrop_eta;   //!
   TBranch        *b_FatjetCA15softdrop_phi;   //!
   TBranch        *b_FatjetCA15softdrop_mass;   //!
   TBranch        *b_ntrgObjects_hltPFTripleJetLooseID64;   //!
   TBranch        *b_nLHE_weights_pdf;   //!
   TBranch        *b_LHE_weights_pdf_id;   //!
   TBranch        *b_LHE_weights_pdf_wgt;   //!
   TBranch        *b_nprimaryVertices;   //!
   TBranch        *b_primaryVertices_x;   //!
   TBranch        *b_primaryVertices_y;   //!
   TBranch        *b_primaryVertices_z;   //!
   TBranch        *b_primaryVertices_isFake;   //!
   TBranch        *b_primaryVertices_ndof;   //!
   TBranch        *b_primaryVertices_Rho;   //!
   TBranch        *b_primaryVertices_score;   //!
   TBranch        *b_nsoftActivityJets;   //!
   TBranch        *b_softActivityJets_pt;   //!
   TBranch        *b_softActivityJets_eta;   //!
   TBranch        *b_softActivityJets_phi;   //!
   TBranch        *b_softActivityJets_mass;   //!
   TBranch        *b_nFatjetCA15subjetfiltered;   //!
   TBranch        *b_FatjetCA15subjetfiltered_pt;   //!
   TBranch        *b_FatjetCA15subjetfiltered_eta;   //!
   TBranch        *b_FatjetCA15subjetfiltered_phi;   //!
   TBranch        *b_FatjetCA15subjetfiltered_mass;   //!
   TBranch        *b_nGenWZQuark;   //!
   TBranch        *b_GenWZQuark_pdgId;   //!
   TBranch        *b_GenWZQuark_pt;   //!
   TBranch        *b_GenWZQuark_eta;   //!
   TBranch        *b_GenWZQuark_phi;   //!
   TBranch        *b_GenWZQuark_mass;   //!
   TBranch        *b_GenWZQuark_charge;   //!
   TBranch        *b_GenWZQuark_status;   //!
   TBranch        *b_GenWZQuark_isPromptHard;   //!
   TBranch        *b_ntrgObjects_hltSingleJet80;   //!

   heppyTree(TTree *tree=0);
   virtual ~heppyTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef heppyTree_cxx
heppyTree::heppyTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/uscms/store/user/lpchbb/HeppyNtuples/V23/TT_TuneCUETP8M1_13TeV-powheg-pythia8/VHBB_HEPPY_V23_TT_TuneCUETP8M1_13TeV-powheg-Py8__spr16MAv2-puspr16_80r2as_2016_MAv2_v0_ext4-v1/160717_083956/0003/tree_3919.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/eos/uscms/store/user/lpchbb/HeppyNtuples/V23/TT_TuneCUETP8M1_13TeV-powheg-pythia8/VHBB_HEPPY_V23_TT_TuneCUETP8M1_13TeV-powheg-Py8__spr16MAv2-puspr16_80r2as_2016_MAv2_v0_ext4-v1/160717_083956/0003/tree_3919.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

heppyTree::~heppyTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t heppyTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t heppyTree::LoadTree(Long64_t entry)
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

void heppyTree::Init(TTree *tree)
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

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("evt", &evt, &b_evt);
   fChain->SetBranchAddress("isData", &isData, &b_isData);
   fChain->SetBranchAddress("xsec", &xsec, &b_xsec);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);
   fChain->SetBranchAddress("nTrueInt", &nTrueInt, &b_nTrueInt);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("puWeightUp", &puWeightUp, &b_puWeightUp);
   fChain->SetBranchAddress("puWeightDown", &puWeightDown, &b_puWeightDown);
   fChain->SetBranchAddress("json", &json, &b_json);
   fChain->SetBranchAddress("json_silver", &json_silver, &b_json_silver);
   fChain->SetBranchAddress("nPU0", &nPU0, &b_nPU0);
   fChain->SetBranchAddress("nPVs", &nPVs, &b_nPVs);
   fChain->SetBranchAddress("Vtype", &Vtype, &b_Vtype);
   fChain->SetBranchAddress("VtypeSim", &VtypeSim, &b_VtypeSim);
   fChain->SetBranchAddress("VMt", &VMt, &b_VMt);
   fChain->SetBranchAddress("HVdPhi", &HVdPhi, &b_HVdPhi);
   fChain->SetBranchAddress("fakeMET_sumet", &fakeMET_sumet, &b_fakeMET_sumet);
   fChain->SetBranchAddress("bx", &bx, &b_bx);
   fChain->SetBranchAddress("caloMetPt", &caloMetPt, &b_caloMetPt);
   fChain->SetBranchAddress("caloMetPhi", &caloMetPhi, &b_caloMetPhi);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("rhoN", &rhoN, &b_rhoN);
   fChain->SetBranchAddress("rhoCHPU", &rhoCHPU, &b_rhoCHPU);
   fChain->SetBranchAddress("rhoCentral", &rhoCentral, &b_rhoCentral);
   fChain->SetBranchAddress("deltaR_jj", &deltaR_jj, &b_deltaR_jj);
   fChain->SetBranchAddress("lheNj", &lheNj, &b_lheNj);
   fChain->SetBranchAddress("lheNb", &lheNb, &b_lheNb);
   fChain->SetBranchAddress("lheNc", &lheNc, &b_lheNc);
   fChain->SetBranchAddress("lheNg", &lheNg, &b_lheNg);
   fChain->SetBranchAddress("lheNl", &lheNl, &b_lheNl);
   fChain->SetBranchAddress("lheV_pt", &lheV_pt, &b_lheV_pt);
   fChain->SetBranchAddress("lheHT", &lheHT, &b_lheHT);
   fChain->SetBranchAddress("genTTHtoTauTauDecayMode", &genTTHtoTauTauDecayMode, &b_genTTHtoTauTauDecayMode);
   fChain->SetBranchAddress("ttCls", &ttCls, &b_ttCls);
   fChain->SetBranchAddress("heavyFlavourCategory", &heavyFlavourCategory, &b_heavyFlavourCategory);
   fChain->SetBranchAddress("mhtJet30", &mhtJet30, &b_mhtJet30);
   fChain->SetBranchAddress("mhtPhiJet30", &mhtPhiJet30, &b_mhtPhiJet30);
   fChain->SetBranchAddress("htJet30", &htJet30, &b_htJet30);
   fChain->SetBranchAddress("met_sig", &met_sig, &b_met_sig);
   fChain->SetBranchAddress("met_rawpt", &met_rawpt, &b_met_rawpt);
   fChain->SetBranchAddress("metPuppi_pt", &metPuppi_pt, &b_metPuppi_pt);
   fChain->SetBranchAddress("metPuppi_phi", &metPuppi_phi, &b_metPuppi_phi);
   fChain->SetBranchAddress("metPuppi_rawpt", &metPuppi_rawpt, &b_metPuppi_rawpt);
   fChain->SetBranchAddress("metType1p2_pt", &metType1p2_pt, &b_metType1p2_pt);
   fChain->SetBranchAddress("tkMet_pt", &tkMet_pt, &b_tkMet_pt);
   fChain->SetBranchAddress("tkMet_phi", &tkMet_phi, &b_tkMet_phi);
   fChain->SetBranchAddress("tkMetPVchs_pt", &tkMetPVchs_pt, &b_tkMetPVchs_pt);
   fChain->SetBranchAddress("tkMetPVchs_phi", &tkMetPVchs_phi, &b_tkMetPVchs_phi);
   fChain->SetBranchAddress("isrJetVH", &isrJetVH, &b_isrJetVH);
   fChain->SetBranchAddress("Flag_hbheIsoFilter", &Flag_hbheIsoFilter, &b_Flag_hbheIsoFilter);
   fChain->SetBranchAddress("Flag_hbheFilterNew", &Flag_hbheFilterNew, &b_Flag_hbheFilterNew);
   fChain->SetBranchAddress("simPrimaryVertex_z", &simPrimaryVertex_z, &b_simPrimaryVertex_z);
   fChain->SetBranchAddress("genHiggsDecayMode", &genHiggsDecayMode, &b_genHiggsDecayMode);
   fChain->SetBranchAddress("btagWeightCSV_down_cferr1", &btagWeightCSV_down_cferr1, &b_btagWeightCSV_down_cferr1);
   fChain->SetBranchAddress("btagWeightCMVAV2_down_hfstats1", &btagWeightCMVAV2_down_hfstats1, &b_btagWeightCMVAV2_down_hfstats1);
   fChain->SetBranchAddress("btagWeightCMVAV2_down_hfstats2", &btagWeightCMVAV2_down_hfstats2, &b_btagWeightCMVAV2_down_hfstats2);
   fChain->SetBranchAddress("btagWeightCSV_down_cferr2", &btagWeightCSV_down_cferr2, &b_btagWeightCSV_down_cferr2);
   fChain->SetBranchAddress("btagWeightCSV_down_jes", &btagWeightCSV_down_jes, &b_btagWeightCSV_down_jes);
   fChain->SetBranchAddress("btagWeightCSV_down_lf", &btagWeightCSV_down_lf, &b_btagWeightCSV_down_lf);
   fChain->SetBranchAddress("btagWeightCSV_up_lf", &btagWeightCSV_up_lf, &b_btagWeightCSV_up_lf);
   fChain->SetBranchAddress("btagWeightCSV_down_lfstats2", &btagWeightCSV_down_lfstats2, &b_btagWeightCSV_down_lfstats2);
   fChain->SetBranchAddress("btagWeightCSV_down_lfstats1", &btagWeightCSV_down_lfstats1, &b_btagWeightCSV_down_lfstats1);
   fChain->SetBranchAddress("btagWeightCSV_down_hf", &btagWeightCSV_down_hf, &b_btagWeightCSV_down_hf);
   fChain->SetBranchAddress("btagWeightCSV_up_lfstats1", &btagWeightCSV_up_lfstats1, &b_btagWeightCSV_up_lfstats1);
   fChain->SetBranchAddress("btagWeightCMVAV2_down_lf", &btagWeightCMVAV2_down_lf, &b_btagWeightCMVAV2_down_lf);
   fChain->SetBranchAddress("btagWeightCSV_up_lfstats2", &btagWeightCSV_up_lfstats2, &b_btagWeightCSV_up_lfstats2);
   fChain->SetBranchAddress("btagWeightCSV", &btagWeightCSV, &b_btagWeightCSV);
   fChain->SetBranchAddress("btagWeightCSV_up_cferr2", &btagWeightCSV_up_cferr2, &b_btagWeightCSV_up_cferr2);
   fChain->SetBranchAddress("btagWeightCSV_up_cferr1", &btagWeightCSV_up_cferr1, &b_btagWeightCSV_up_cferr1);
   fChain->SetBranchAddress("btagWeightCSV_up_hf", &btagWeightCSV_up_hf, &b_btagWeightCSV_up_hf);
   fChain->SetBranchAddress("btagWeightCMVAV2_down_hf", &btagWeightCMVAV2_down_hf, &b_btagWeightCMVAV2_down_hf);
   fChain->SetBranchAddress("btagWeightCMVAV2_up_lfstats2", &btagWeightCMVAV2_up_lfstats2, &b_btagWeightCMVAV2_up_lfstats2);
   fChain->SetBranchAddress("btagWeightCMVAV2_up_hfstats2", &btagWeightCMVAV2_up_hfstats2, &b_btagWeightCMVAV2_up_hfstats2);
   fChain->SetBranchAddress("btagWeightCMVAV2_up_hfstats1", &btagWeightCMVAV2_up_hfstats1, &b_btagWeightCMVAV2_up_hfstats1);
   fChain->SetBranchAddress("btagWeightCMVAV2", &btagWeightCMVAV2, &b_btagWeightCMVAV2);
   fChain->SetBranchAddress("btagWeightCMVAV2_up_lfstats1", &btagWeightCMVAV2_up_lfstats1, &b_btagWeightCMVAV2_up_lfstats1);
   fChain->SetBranchAddress("btagWeightCMVAV2_down_cferr2", &btagWeightCMVAV2_down_cferr2, &b_btagWeightCMVAV2_down_cferr2);
   fChain->SetBranchAddress("btagWeightCMVAV2_up_hf", &btagWeightCMVAV2_up_hf, &b_btagWeightCMVAV2_up_hf);
   fChain->SetBranchAddress("btagWeightCMVAV2_down_cferr1", &btagWeightCMVAV2_down_cferr1, &b_btagWeightCMVAV2_down_cferr1);
   fChain->SetBranchAddress("btagWeightCSV_up_jes", &btagWeightCSV_up_jes, &b_btagWeightCSV_up_jes);
   fChain->SetBranchAddress("btagWeightCMVAV2_up_jes", &btagWeightCMVAV2_up_jes, &b_btagWeightCMVAV2_up_jes);
   fChain->SetBranchAddress("btagWeightCMVAV2_up_lf", &btagWeightCMVAV2_up_lf, &b_btagWeightCMVAV2_up_lf);
   fChain->SetBranchAddress("btagWeightCSV_down_hfstats2", &btagWeightCSV_down_hfstats2, &b_btagWeightCSV_down_hfstats2);
   fChain->SetBranchAddress("btagWeightCSV_down_hfstats1", &btagWeightCSV_down_hfstats1, &b_btagWeightCSV_down_hfstats1);
   fChain->SetBranchAddress("btagWeightCMVAV2_up_cferr1", &btagWeightCMVAV2_up_cferr1, &b_btagWeightCMVAV2_up_cferr1);
   fChain->SetBranchAddress("btagWeightCMVAV2_up_cferr2", &btagWeightCMVAV2_up_cferr2, &b_btagWeightCMVAV2_up_cferr2);
   fChain->SetBranchAddress("btagWeightCMVAV2_down_lfstats1", &btagWeightCMVAV2_down_lfstats1, &b_btagWeightCMVAV2_down_lfstats1);
   fChain->SetBranchAddress("btagWeightCMVAV2_down_lfstats2", &btagWeightCMVAV2_down_lfstats2, &b_btagWeightCMVAV2_down_lfstats2);
   fChain->SetBranchAddress("btagWeightCSV_up_hfstats1", &btagWeightCSV_up_hfstats1, &b_btagWeightCSV_up_hfstats1);
   fChain->SetBranchAddress("btagWeightCMVAV2_down_jes", &btagWeightCMVAV2_down_jes, &b_btagWeightCMVAV2_down_jes);
   fChain->SetBranchAddress("btagWeightCSV_up_hfstats2", &btagWeightCSV_up_hfstats2, &b_btagWeightCSV_up_hfstats2);
   fChain->SetBranchAddress("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter, &b_Flag_HBHENoiseIsoFilter);
   fChain->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter, &b_Flag_EcalDeadCellTriggerPrimitiveFilter);
   fChain->SetBranchAddress("Flag_trkPOG_manystripclus53X", &Flag_trkPOG_manystripclus53X, &b_Flag_trkPOG_manystripclus53X);
   fChain->SetBranchAddress("Flag_ecalLaserCorrFilter", &Flag_ecalLaserCorrFilter, &b_Flag_ecalLaserCorrFilter);
   fChain->SetBranchAddress("Flag_trkPOG_toomanystripclus53X", &Flag_trkPOG_toomanystripclus53X, &b_Flag_trkPOG_toomanystripclus53X);
   fChain->SetBranchAddress("Flag_hcalLaserEventFilter", &Flag_hcalLaserEventFilter, &b_Flag_hcalLaserEventFilter);
   fChain->SetBranchAddress("Flag_muonBadTrackFilter", &Flag_muonBadTrackFilter, &b_Flag_muonBadTrackFilter);
   fChain->SetBranchAddress("Flag_trkPOG_logErrorTooManyClusters", &Flag_trkPOG_logErrorTooManyClusters, &b_Flag_trkPOG_logErrorTooManyClusters);
   fChain->SetBranchAddress("Flag_trkPOGFilters", &Flag_trkPOGFilters, &b_Flag_trkPOGFilters);
   fChain->SetBranchAddress("Flag_trackingFailureFilter", &Flag_trackingFailureFilter, &b_Flag_trackingFailureFilter);
   fChain->SetBranchAddress("Flag_CSCTightHaloFilter", &Flag_CSCTightHaloFilter, &b_Flag_CSCTightHaloFilter);
   fChain->SetBranchAddress("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter, &b_Flag_HBHENoiseFilter);
   fChain->SetBranchAddress("Flag_chargedHadronTrackResolutionFilter", &Flag_chargedHadronTrackResolutionFilter, &b_Flag_chargedHadronTrackResolutionFilter);
   fChain->SetBranchAddress("Flag_goodVertices", &Flag_goodVertices, &b_Flag_goodVertices);
   fChain->SetBranchAddress("Flag_METFilters", &Flag_METFilters, &b_Flag_METFilters);
   fChain->SetBranchAddress("Flag_CSCTightHalo2015Filter", &Flag_CSCTightHalo2015Filter, &b_Flag_CSCTightHalo2015Filter);
   fChain->SetBranchAddress("Flag_eeBadScFilter", &Flag_eeBadScFilter, &b_Flag_eeBadScFilter);
   fChain->SetBranchAddress("HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_BTagCSV_p067_v", &HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_BTagCSV_p067_v, &b_HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_BTagCSV_p067_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_v", &HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_v, &b_HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v", &HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v, &b_HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v", &HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v, &b_HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v", &HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v, &b_HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v", &HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v, &b_HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET170_NoiseCleaned_v", &HLT_BIT_HLT_PFMET170_NoiseCleaned_v, &b_HLT_BIT_HLT_PFMET170_NoiseCleaned_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiCentralPFJet55_PFMET110_v", &HLT_BIT_HLT_DiCentralPFJet55_PFMET110_v, &b_HLT_BIT_HLT_DiCentralPFJet55_PFMET110_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT350_PFMET100_v", &HLT_BIT_HLT_PFHT350_PFMET100_v, &b_HLT_BIT_HLT_PFHT350_PFMET100_v);
   fChain->SetBranchAddress("HLT_ZnnHbbAll", &HLT_ZnnHbbAll, &b_HLT_ZnnHbbAll);
   fChain->SetBranchAddress("HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq200_v", &HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq200_v, &b_HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq200_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq460_v", &HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq460_v, &b_HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq460_v);
   fChain->SetBranchAddress("HLT_VBFHbbLowLumi", &HLT_VBFHbbLowLumi, &b_HLT_VBFHbbLowLumi);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT750_4JetPt50_v", &HLT_BIT_HLT_PFHT750_4JetPt50_v, &b_HLT_BIT_HLT_PFHT750_4JetPt50_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT800_v", &HLT_BIT_HLT_PFHT800_v, &b_HLT_BIT_HLT_PFHT800_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFJet40_v", &HLT_BIT_HLT_PFJet40_v, &b_HLT_BIT_HLT_PFJet40_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFJet60_v", &HLT_BIT_HLT_PFJet60_v, &b_HLT_BIT_HLT_PFJet60_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFJet80_v", &HLT_BIT_HLT_PFJet80_v, &b_HLT_BIT_HLT_PFJet80_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFJet140_v", &HLT_BIT_HLT_PFJet140_v, &b_HLT_BIT_HLT_PFJet140_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFJet200_v", &HLT_BIT_HLT_PFJet200_v, &b_HLT_BIT_HLT_PFJet200_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFJet260_v", &HLT_BIT_HLT_PFJet260_v, &b_HLT_BIT_HLT_PFJet260_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFJet320_v", &HLT_BIT_HLT_PFJet320_v, &b_HLT_BIT_HLT_PFJet320_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFJet400_v", &HLT_BIT_HLT_PFJet400_v, &b_HLT_BIT_HLT_PFJet400_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFJet450_v", &HLT_BIT_HLT_PFJet450_v, &b_HLT_BIT_HLT_PFJet450_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiPFJetAve40_v", &HLT_BIT_HLT_DiPFJetAve40_v, &b_HLT_BIT_HLT_DiPFJetAve40_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiPFJetAve60_v", &HLT_BIT_HLT_DiPFJetAve60_v, &b_HLT_BIT_HLT_DiPFJetAve60_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiPFJetAve80_v", &HLT_BIT_HLT_DiPFJetAve80_v, &b_HLT_BIT_HLT_DiPFJetAve80_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiPFJetAve140_v", &HLT_BIT_HLT_DiPFJetAve140_v, &b_HLT_BIT_HLT_DiPFJetAve140_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiPFJetAve200_v", &HLT_BIT_HLT_DiPFJetAve200_v, &b_HLT_BIT_HLT_DiPFJetAve200_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiPFJetAve260_v", &HLT_BIT_HLT_DiPFJetAve260_v, &b_HLT_BIT_HLT_DiPFJetAve260_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiPFJetAve320_v", &HLT_BIT_HLT_DiPFJetAve320_v, &b_HLT_BIT_HLT_DiPFJetAve320_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p026_DoublePFJetsC160_v", &HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p026_DoublePFJetsC160_v, &b_HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p026_DoublePFJetsC160_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p014_DoublePFJetsC100MaxDeta1p6_v", &HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p014_DoublePFJetsC100MaxDeta1p6_v, &b_HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p014_DoublePFJetsC100MaxDeta1p6_v);
   fChain->SetBranchAddress("HLT_hadronic", &HLT_hadronic, &b_HLT_hadronic);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v", &HLT_BIT_HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v, &b_HLT_BIT_HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT450_SixJet40_BTagCSV_p056_v", &HLT_BIT_HLT_PFHT450_SixJet40_BTagCSV_p056_v, &b_HLT_BIT_HLT_PFHT450_SixJet40_BTagCSV_p056_v);
   fChain->SetBranchAddress("HLT_ttHhardonicLowLumi", &HLT_ttHhardonicLowLumi, &b_HLT_ttHhardonicLowLumi);
   fChain->SetBranchAddress("HLT_BIT_HLT_QuadJet45_TripleBTagCSV_p087_v", &HLT_BIT_HLT_QuadJet45_TripleBTagCSV_p087_v, &b_HLT_BIT_HLT_QuadJet45_TripleBTagCSV_p087_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_QuadJet45_DoubleBTagCSV_p087_v", &HLT_BIT_HLT_QuadJet45_DoubleBTagCSV_p087_v, &b_HLT_BIT_HLT_QuadJet45_DoubleBTagCSV_p087_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleJet90_Double30_TripleBTagCSV_p087_v", &HLT_BIT_HLT_DoubleJet90_Double30_TripleBTagCSV_p087_v, &b_HLT_BIT_HLT_DoubleJet90_Double30_TripleBTagCSV_p087_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleJet90_Double30_DoubleBTagCSV_p087_v", &HLT_BIT_HLT_DoubleJet90_Double30_DoubleBTagCSV_p087_v, &b_HLT_BIT_HLT_DoubleJet90_Double30_DoubleBTagCSV_p087_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v", &HLT_BIT_HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v, &b_HLT_BIT_HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v", &HLT_BIT_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v, &b_HLT_BIT_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v", &HLT_BIT_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v, &b_HLT_BIT_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v", &HLT_BIT_HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v, &b_HLT_BIT_HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v", &HLT_BIT_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v, &b_HLT_BIT_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_AK8PFJet360_TrimMass30_v", &HLT_BIT_HLT_AK8PFJet360_TrimMass30_v, &b_HLT_BIT_HLT_AK8PFJet360_TrimMass30_v);
   fChain->SetBranchAddress("HLT_HH4bAll", &HLT_HH4bAll, &b_HLT_HH4bAll);
   fChain->SetBranchAddress("HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET80_v", &HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET80_v, &b_HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET80_v);
   fChain->SetBranchAddress("HLT_WtaunHbbLowLumi", &HLT_WtaunHbbLowLumi, &b_HLT_WtaunHbbLowLumi);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", &HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v, &b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v", &HLT_BIT_HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v, &b_HLT_BIT_HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_ZeeHbbHighLumi", &HLT_ZeeHbbHighLumi, &b_HLT_ZeeHbbHighLumi);
   fChain->SetBranchAddress("HLT_HH4bHighLumi", &HLT_HH4bHighLumi, &b_HLT_HH4bHighLumi);
   fChain->SetBranchAddress("HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq240_v", &HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq240_v, &b_HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq240_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq500_v", &HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq500_v, &b_HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq500_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_QuadPFJet_VBF_v", &HLT_BIT_HLT_QuadPFJet_VBF_v, &b_HLT_BIT_HLT_QuadPFJet_VBF_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_L1_TripleJet_VBF_v", &HLT_BIT_HLT_L1_TripleJet_VBF_v, &b_HLT_BIT_HLT_L1_TripleJet_VBF_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v", &HLT_BIT_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v, &b_HLT_BIT_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v", &HLT_BIT_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v, &b_HLT_BIT_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v);
   fChain->SetBranchAddress("HLT_VBFHbbAll", &HLT_VBFHbbAll, &b_HLT_VBFHbbAll);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_eta2p1_WPTight_Gsf_v", &HLT_BIT_HLT_Ele27_eta2p1_WPTight_Gsf_v, &b_HLT_BIT_HLT_Ele27_eta2p1_WPTight_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_HT200_v", &HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_HT200_v, &b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_HT200_v);
   fChain->SetBranchAddress("HLT_WenHbbLowLumi", &HLT_WenHbbLowLumi, &b_HLT_WenHbbLowLumi);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele32_eta2p1_WPTight_Gsf_v", &HLT_BIT_HLT_Ele32_eta2p1_WPTight_Gsf_v, &b_HLT_BIT_HLT_Ele32_eta2p1_WPTight_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele105_CaloIdVT_GsfTrkIdT_v", &HLT_BIT_HLT_Ele105_CaloIdVT_GsfTrkIdT_v, &b_HLT_BIT_HLT_Ele105_CaloIdVT_GsfTrkIdT_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v", &HLT_BIT_HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v, &b_HLT_BIT_HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_WPLoose_Gsf_WHbbBoost_v", &HLT_BIT_HLT_Ele27_WPLoose_Gsf_WHbbBoost_v, &b_HLT_BIT_HLT_Ele27_WPLoose_Gsf_WHbbBoost_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele22_eta2p1_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele22_eta2p1_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele22_eta2p1_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele23_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele23_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele27_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele27_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_WPLoose_Gsf_WHbbBoost_v", &HLT_BIT_HLT_Ele23_WPLoose_Gsf_WHbbBoost_v, &b_HLT_BIT_HLT_Ele23_WPLoose_Gsf_WHbbBoost_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele25_WPTight_Gsf_v", &HLT_BIT_HLT_Ele25_WPTight_Gsf_v, &b_HLT_BIT_HLT_Ele25_WPTight_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_WenHbbAll", &HLT_WenHbbAll, &b_HLT_WenHbbAll);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", &HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v, &b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v);
   fChain->SetBranchAddress("HLT_ZeeHbbLowLumi", &HLT_ZeeHbbLowLumi, &b_HLT_ZeeHbbLowLumi);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu24_eta2p1_v", &HLT_BIT_HLT_Mu24_eta2p1_v, &b_HLT_BIT_HLT_Mu24_eta2p1_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_TkMu24_eta2p1_v", &HLT_BIT_HLT_TkMu24_eta2p1_v, &b_HLT_BIT_HLT_TkMu24_eta2p1_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu27_v", &HLT_BIT_HLT_IsoMu27_v, &b_HLT_BIT_HLT_IsoMu27_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu27_v", &HLT_BIT_HLT_IsoTkMu27_v, &b_HLT_BIT_HLT_IsoTkMu27_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_TkMu27_v", &HLT_BIT_HLT_TkMu27_v, &b_HLT_BIT_HLT_TkMu27_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu27_v", &HLT_BIT_HLT_Mu27_v, &b_HLT_BIT_HLT_Mu27_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu20_v", &HLT_BIT_HLT_IsoMu20_v, &b_HLT_BIT_HLT_IsoMu20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu20_v", &HLT_BIT_HLT_Mu20_v, &b_HLT_BIT_HLT_Mu20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_TkMu20_v", &HLT_BIT_HLT_TkMu20_v, &b_HLT_BIT_HLT_TkMu20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu20_v", &HLT_BIT_HLT_IsoTkMu20_v, &b_HLT_BIT_HLT_IsoTkMu20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu18_v", &HLT_BIT_HLT_IsoMu18_v, &b_HLT_BIT_HLT_IsoMu18_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu18_v", &HLT_BIT_HLT_IsoTkMu18_v, &b_HLT_BIT_HLT_IsoTkMu18_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu40_eta2p1_PFJet200_PFJet50_v", &HLT_BIT_HLT_Mu40_eta2p1_PFJet200_PFJet50_v, &b_HLT_BIT_HLT_Mu40_eta2p1_PFJet200_PFJet50_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu16_eta2p1_MET30_v", &HLT_BIT_HLT_IsoMu16_eta2p1_MET30_v, &b_HLT_BIT_HLT_IsoMu16_eta2p1_MET30_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu16_eta2p1_MET30_v", &HLT_BIT_HLT_Mu16_eta2p1_MET30_v, &b_HLT_BIT_HLT_Mu16_eta2p1_MET30_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET120_Mu5_v", &HLT_BIT_HLT_PFMET120_Mu5_v, &b_HLT_BIT_HLT_PFMET120_Mu5_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_v", &HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_v, &b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90_IDTight_v", &HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90_IDTight_v, &b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v", &HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v, &b_HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v", &HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v, &b_HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v", &HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v, &b_HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v", &HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v, &b_HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v);
   fChain->SetBranchAddress("HLT_WmnHbbAll", &HLT_WmnHbbAll, &b_HLT_WmnHbbAll);
   fChain->SetBranchAddress("HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v", &HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v, &b_HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_v", &HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_v, &b_HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_v);
   fChain->SetBranchAddress("HLT_WtaunHbbAll", &HLT_WtaunHbbAll, &b_HLT_WtaunHbbAll);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT450_SixJet40_v", &HLT_BIT_HLT_PFHT450_SixJet40_v, &b_HLT_BIT_HLT_PFHT450_SixJet40_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT400_SixJet30_v", &HLT_BIT_HLT_PFHT400_SixJet30_v, &b_HLT_BIT_HLT_PFHT400_SixJet30_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT350_v", &HLT_BIT_HLT_PFHT350_v, &b_HLT_BIT_HLT_PFHT350_v);
   fChain->SetBranchAddress("HLT_ttHhardonicAll", &HLT_ttHhardonicAll, &b_HLT_ttHhardonicAll);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele30WP60_Ele8_Mass55_v", &HLT_BIT_HLT_Ele30WP60_Ele8_Mass55_v, &b_HLT_BIT_HLT_Ele30WP60_Ele8_Mass55_v);
   fChain->SetBranchAddress("HLT_ZeeHbbAll", &HLT_ZeeHbbAll, &b_HLT_ZeeHbbAll);
   fChain->SetBranchAddress("HLT_WmnHbbLowLumi", &HLT_WmnHbbLowLumi, &b_HLT_WmnHbbLowLumi);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v);
   fChain->SetBranchAddress("HLT_ttHleptonic", &HLT_ttHleptonic, &b_HLT_ttHleptonic);
   fChain->SetBranchAddress("HLT_VBFHbbHighLumi", &HLT_VBFHbbHighLumi, &b_HLT_VBFHbbHighLumi);
   fChain->SetBranchAddress("HLT_ZnnHbb", &HLT_ZnnHbb, &b_HLT_ZnnHbb);
   fChain->SetBranchAddress("HLT_ZmmHbbLowLumi", &HLT_ZmmHbbLowLumi, &b_HLT_ZmmHbbLowLumi);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu24_v", &HLT_BIT_HLT_IsoMu24_v, &b_HLT_BIT_HLT_IsoMu24_v);
   fChain->SetBranchAddress("HLT_WmnHbbHighLumi", &HLT_WmnHbbHighLumi, &b_HLT_WmnHbbHighLumi);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TkMu8_DZ_v", &HLT_BIT_HLT_Mu17_TkMu8_DZ_v, &b_HLT_BIT_HLT_Mu17_TkMu8_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleIsoMu17_eta2p1_v", &HLT_BIT_HLT_DoubleIsoMu17_eta2p1_v, &b_HLT_BIT_HLT_DoubleIsoMu17_eta2p1_v);
   fChain->SetBranchAddress("HLT_ZmmHbbAll", &HLT_ZmmHbbAll, &b_HLT_ZmmHbbAll);
   fChain->SetBranchAddress("HLT_WenHbbHighLumi", &HLT_WenHbbHighLumi, &b_HLT_WenHbbHighLumi);
   fChain->SetBranchAddress("HLT_HH4bLowLumi", &HLT_HH4bLowLumi, &b_HLT_HH4bLowLumi);
   fChain->SetBranchAddress("HLT_ZmmHbbHighLumi", &HLT_ZmmHbbHighLumi, &b_HLT_ZmmHbbHighLumi);
   fChain->SetBranchAddress("HLT_ttHhardonicHighLumi", &HLT_ttHhardonicHighLumi, &b_HLT_ttHhardonicHighLumi);
   fChain->SetBranchAddress("HLT_WtaunHbbHighLumi", &HLT_WtaunHbbHighLumi, &b_HLT_WtaunHbbHighLumi);
   fChain->SetBranchAddress("H_reg_corrJECUp_pt", &H_reg_corrJECUp_pt, &b_H_reg_corrJECUp_pt);
   fChain->SetBranchAddress("H_reg_corrJECUp_eta", &H_reg_corrJECUp_eta, &b_H_reg_corrJECUp_eta);
   fChain->SetBranchAddress("H_reg_corrJECUp_phi", &H_reg_corrJECUp_phi, &b_H_reg_corrJECUp_phi);
   fChain->SetBranchAddress("H_reg_corrJECUp_mass", &H_reg_corrJECUp_mass, &b_H_reg_corrJECUp_mass);
   fChain->SetBranchAddress("HaddJetsdR08_pt", &HaddJetsdR08_pt, &b_HaddJetsdR08_pt);
   fChain->SetBranchAddress("HaddJetsdR08_eta", &HaddJetsdR08_eta, &b_HaddJetsdR08_eta);
   fChain->SetBranchAddress("HaddJetsdR08_phi", &HaddJetsdR08_phi, &b_HaddJetsdR08_phi);
   fChain->SetBranchAddress("HaddJetsdR08_mass", &HaddJetsdR08_mass, &b_HaddJetsdR08_mass);
   fChain->SetBranchAddress("H_pt", &H_pt, &b_H_pt);
   fChain->SetBranchAddress("H_eta", &H_eta, &b_H_eta);
   fChain->SetBranchAddress("H_phi", &H_phi, &b_H_phi);
   fChain->SetBranchAddress("H_mass", &H_mass, &b_H_mass);
   fChain->SetBranchAddress("softActivityVH_njets2", &softActivityVH_njets2, &b_softActivityVH_njets2);
   fChain->SetBranchAddress("softActivityVH_njets5", &softActivityVH_njets5, &b_softActivityVH_njets5);
   fChain->SetBranchAddress("softActivityVH_njets10", &softActivityVH_njets10, &b_softActivityVH_njets10);
   fChain->SetBranchAddress("softActivityVH_HT", &softActivityVH_HT, &b_softActivityVH_HT);
   fChain->SetBranchAddress("met_shifted_JetResUp_pt", &met_shifted_JetResUp_pt, &b_met_shifted_JetResUp_pt);
   fChain->SetBranchAddress("met_shifted_JetResUp_phi", &met_shifted_JetResUp_phi, &b_met_shifted_JetResUp_phi);
   fChain->SetBranchAddress("met_shifted_JetResUp_sumEt", &met_shifted_JetResUp_sumEt, &b_met_shifted_JetResUp_sumEt);
   fChain->SetBranchAddress("met_pt", &met_pt, &b_met_pt);
   fChain->SetBranchAddress("met_eta", &met_eta, &b_met_eta);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("met_mass", &met_mass, &b_met_mass);
   fChain->SetBranchAddress("met_sumEt", &met_sumEt, &b_met_sumEt);
   fChain->SetBranchAddress("met_rawPt", &met_rawPt, &b_met_rawPt);
   fChain->SetBranchAddress("met_rawPhi", &met_rawPhi, &b_met_rawPhi);
   fChain->SetBranchAddress("met_rawSumEt", &met_rawSumEt, &b_met_rawSumEt);
   fChain->SetBranchAddress("met_genPt", &met_genPt, &b_met_genPt);
   fChain->SetBranchAddress("met_genPhi", &met_genPhi, &b_met_genPhi);
   fChain->SetBranchAddress("met_genEta", &met_genEta, &b_met_genEta);
   fChain->SetBranchAddress("H_reg_pt", &H_reg_pt, &b_H_reg_pt);
   fChain->SetBranchAddress("H_reg_eta", &H_reg_eta, &b_H_reg_eta);
   fChain->SetBranchAddress("H_reg_phi", &H_reg_phi, &b_H_reg_phi);
   fChain->SetBranchAddress("H_reg_mass", &H_reg_mass, &b_H_reg_mass);
   fChain->SetBranchAddress("HCSV_reg_corrJERDown_pt", &HCSV_reg_corrJERDown_pt, &b_HCSV_reg_corrJERDown_pt);
   fChain->SetBranchAddress("HCSV_reg_corrJERDown_eta", &HCSV_reg_corrJERDown_eta, &b_HCSV_reg_corrJERDown_eta);
   fChain->SetBranchAddress("HCSV_reg_corrJERDown_phi", &HCSV_reg_corrJERDown_phi, &b_HCSV_reg_corrJERDown_phi);
   fChain->SetBranchAddress("HCSV_reg_corrJERDown_mass", &HCSV_reg_corrJERDown_mass, &b_HCSV_reg_corrJERDown_mass);
   fChain->SetBranchAddress("HCSV_pt", &HCSV_pt, &b_HCSV_pt);
   fChain->SetBranchAddress("HCSV_eta", &HCSV_eta, &b_HCSV_eta);
   fChain->SetBranchAddress("HCSV_phi", &HCSV_phi, &b_HCSV_phi);
   fChain->SetBranchAddress("HCSV_mass", &HCSV_mass, &b_HCSV_mass);
   fChain->SetBranchAddress("met_shifted_MuonEnDown_pt", &met_shifted_MuonEnDown_pt, &b_met_shifted_MuonEnDown_pt);
   fChain->SetBranchAddress("met_shifted_MuonEnDown_phi", &met_shifted_MuonEnDown_phi, &b_met_shifted_MuonEnDown_phi);
   fChain->SetBranchAddress("met_shifted_MuonEnDown_sumEt", &met_shifted_MuonEnDown_sumEt, &b_met_shifted_MuonEnDown_sumEt);
   fChain->SetBranchAddress("met_shifted_ElectronEnUp_pt", &met_shifted_ElectronEnUp_pt, &b_met_shifted_ElectronEnUp_pt);
   fChain->SetBranchAddress("met_shifted_ElectronEnUp_phi", &met_shifted_ElectronEnUp_phi, &b_met_shifted_ElectronEnUp_phi);
   fChain->SetBranchAddress("met_shifted_ElectronEnUp_sumEt", &met_shifted_ElectronEnUp_sumEt, &b_met_shifted_ElectronEnUp_sumEt);
   fChain->SetBranchAddress("met_shifted_ElectronEnDown_pt", &met_shifted_ElectronEnDown_pt, &b_met_shifted_ElectronEnDown_pt);
   fChain->SetBranchAddress("met_shifted_ElectronEnDown_phi", &met_shifted_ElectronEnDown_phi, &b_met_shifted_ElectronEnDown_phi);
   fChain->SetBranchAddress("met_shifted_ElectronEnDown_sumEt", &met_shifted_ElectronEnDown_sumEt, &b_met_shifted_ElectronEnDown_sumEt);
   fChain->SetBranchAddress("fakeMET_pt", &fakeMET_pt, &b_fakeMET_pt);
   fChain->SetBranchAddress("fakeMET_eta", &fakeMET_eta, &b_fakeMET_eta);
   fChain->SetBranchAddress("fakeMET_phi", &fakeMET_phi, &b_fakeMET_phi);
   fChain->SetBranchAddress("fakeMET_mass", &fakeMET_mass, &b_fakeMET_mass);
   fChain->SetBranchAddress("met_shifted_TauEnDown_pt", &met_shifted_TauEnDown_pt, &b_met_shifted_TauEnDown_pt);
   fChain->SetBranchAddress("met_shifted_TauEnDown_phi", &met_shifted_TauEnDown_phi, &b_met_shifted_TauEnDown_phi);
   fChain->SetBranchAddress("met_shifted_TauEnDown_sumEt", &met_shifted_TauEnDown_sumEt, &b_met_shifted_TauEnDown_sumEt);
   fChain->SetBranchAddress("V_pt", &V_pt, &b_V_pt);
   fChain->SetBranchAddress("V_eta", &V_eta, &b_V_eta);
   fChain->SetBranchAddress("V_phi", &V_phi, &b_V_phi);
   fChain->SetBranchAddress("V_mass", &V_mass, &b_V_mass);
   fChain->SetBranchAddress("HCSV_reg_corrJERUp_pt", &HCSV_reg_corrJERUp_pt, &b_HCSV_reg_corrJERUp_pt);
   fChain->SetBranchAddress("HCSV_reg_corrJERUp_eta", &HCSV_reg_corrJERUp_eta, &b_HCSV_reg_corrJERUp_eta);
   fChain->SetBranchAddress("HCSV_reg_corrJERUp_phi", &HCSV_reg_corrJERUp_phi, &b_HCSV_reg_corrJERUp_phi);
   fChain->SetBranchAddress("HCSV_reg_corrJERUp_mass", &HCSV_reg_corrJERUp_mass, &b_HCSV_reg_corrJERUp_mass);
   fChain->SetBranchAddress("met_shifted_TauEnUp_pt", &met_shifted_TauEnUp_pt, &b_met_shifted_TauEnUp_pt);
   fChain->SetBranchAddress("met_shifted_TauEnUp_phi", &met_shifted_TauEnUp_phi, &b_met_shifted_TauEnUp_phi);
   fChain->SetBranchAddress("met_shifted_TauEnUp_sumEt", &met_shifted_TauEnUp_sumEt, &b_met_shifted_TauEnUp_sumEt);
   fChain->SetBranchAddress("HCSV_reg_corrJECUp_pt", &HCSV_reg_corrJECUp_pt, &b_HCSV_reg_corrJECUp_pt);
   fChain->SetBranchAddress("HCSV_reg_corrJECUp_eta", &HCSV_reg_corrJECUp_eta, &b_HCSV_reg_corrJECUp_eta);
   fChain->SetBranchAddress("HCSV_reg_corrJECUp_phi", &HCSV_reg_corrJECUp_phi, &b_HCSV_reg_corrJECUp_phi);
   fChain->SetBranchAddress("HCSV_reg_corrJECUp_mass", &HCSV_reg_corrJECUp_mass, &b_HCSV_reg_corrJECUp_mass);
   fChain->SetBranchAddress("met_shifted_UnclusteredEnUp_pt", &met_shifted_UnclusteredEnUp_pt, &b_met_shifted_UnclusteredEnUp_pt);
   fChain->SetBranchAddress("met_shifted_UnclusteredEnUp_phi", &met_shifted_UnclusteredEnUp_phi, &b_met_shifted_UnclusteredEnUp_phi);
   fChain->SetBranchAddress("met_shifted_UnclusteredEnUp_sumEt", &met_shifted_UnclusteredEnUp_sumEt, &b_met_shifted_UnclusteredEnUp_sumEt);
   fChain->SetBranchAddress("met_shifted_UnclusteredEnDown_pt", &met_shifted_UnclusteredEnDown_pt, &b_met_shifted_UnclusteredEnDown_pt);
   fChain->SetBranchAddress("met_shifted_UnclusteredEnDown_phi", &met_shifted_UnclusteredEnDown_phi, &b_met_shifted_UnclusteredEnDown_phi);
   fChain->SetBranchAddress("met_shifted_UnclusteredEnDown_sumEt", &met_shifted_UnclusteredEnDown_sumEt, &b_met_shifted_UnclusteredEnDown_sumEt);
   fChain->SetBranchAddress("met_shifted_JetEnUp_pt", &met_shifted_JetEnUp_pt, &b_met_shifted_JetEnUp_pt);
   fChain->SetBranchAddress("met_shifted_JetEnUp_phi", &met_shifted_JetEnUp_phi, &b_met_shifted_JetEnUp_phi);
   fChain->SetBranchAddress("met_shifted_JetEnUp_sumEt", &met_shifted_JetEnUp_sumEt, &b_met_shifted_JetEnUp_sumEt);
   fChain->SetBranchAddress("H_reg_corrJERDown_pt", &H_reg_corrJERDown_pt, &b_H_reg_corrJERDown_pt);
   fChain->SetBranchAddress("H_reg_corrJERDown_eta", &H_reg_corrJERDown_eta, &b_H_reg_corrJERDown_eta);
   fChain->SetBranchAddress("H_reg_corrJERDown_phi", &H_reg_corrJERDown_phi, &b_H_reg_corrJERDown_phi);
   fChain->SetBranchAddress("H_reg_corrJERDown_mass", &H_reg_corrJERDown_mass, &b_H_reg_corrJERDown_mass);
   fChain->SetBranchAddress("HCSV_reg_pt", &HCSV_reg_pt, &b_HCSV_reg_pt);
   fChain->SetBranchAddress("HCSV_reg_eta", &HCSV_reg_eta, &b_HCSV_reg_eta);
   fChain->SetBranchAddress("HCSV_reg_phi", &HCSV_reg_phi, &b_HCSV_reg_phi);
   fChain->SetBranchAddress("HCSV_reg_mass", &HCSV_reg_mass, &b_HCSV_reg_mass);
   fChain->SetBranchAddress("met_shifted_JetEnDown_pt", &met_shifted_JetEnDown_pt, &b_met_shifted_JetEnDown_pt);
   fChain->SetBranchAddress("met_shifted_JetEnDown_phi", &met_shifted_JetEnDown_phi, &b_met_shifted_JetEnDown_phi);
   fChain->SetBranchAddress("met_shifted_JetEnDown_sumEt", &met_shifted_JetEnDown_sumEt, &b_met_shifted_JetEnDown_sumEt);
   fChain->SetBranchAddress("met_shifted_JetResDown_pt", &met_shifted_JetResDown_pt, &b_met_shifted_JetResDown_pt);
   fChain->SetBranchAddress("met_shifted_JetResDown_phi", &met_shifted_JetResDown_phi, &b_met_shifted_JetResDown_phi);
   fChain->SetBranchAddress("met_shifted_JetResDown_sumEt", &met_shifted_JetResDown_sumEt, &b_met_shifted_JetResDown_sumEt);
   fChain->SetBranchAddress("softActivity_njets2", &softActivity_njets2, &b_softActivity_njets2);
   fChain->SetBranchAddress("softActivity_njets5", &softActivity_njets5, &b_softActivity_njets5);
   fChain->SetBranchAddress("softActivity_njets10", &softActivity_njets10, &b_softActivity_njets10);
   fChain->SetBranchAddress("softActivity_HT", &softActivity_HT, &b_softActivity_HT);
   fChain->SetBranchAddress("met_shifted_MuonEnUp_pt", &met_shifted_MuonEnUp_pt, &b_met_shifted_MuonEnUp_pt);
   fChain->SetBranchAddress("met_shifted_MuonEnUp_phi", &met_shifted_MuonEnUp_phi, &b_met_shifted_MuonEnUp_phi);
   fChain->SetBranchAddress("met_shifted_MuonEnUp_sumEt", &met_shifted_MuonEnUp_sumEt, &b_met_shifted_MuonEnUp_sumEt);
   fChain->SetBranchAddress("HCSV_reg_corrJECDown_pt", &HCSV_reg_corrJECDown_pt, &b_HCSV_reg_corrJECDown_pt);
   fChain->SetBranchAddress("HCSV_reg_corrJECDown_eta", &HCSV_reg_corrJECDown_eta, &b_HCSV_reg_corrJECDown_eta);
   fChain->SetBranchAddress("HCSV_reg_corrJECDown_phi", &HCSV_reg_corrJECDown_phi, &b_HCSV_reg_corrJECDown_phi);
   fChain->SetBranchAddress("HCSV_reg_corrJECDown_mass", &HCSV_reg_corrJECDown_mass, &b_HCSV_reg_corrJECDown_mass);
   fChain->SetBranchAddress("H_reg_corrJERUp_pt", &H_reg_corrJERUp_pt, &b_H_reg_corrJERUp_pt);
   fChain->SetBranchAddress("H_reg_corrJERUp_eta", &H_reg_corrJERUp_eta, &b_H_reg_corrJERUp_eta);
   fChain->SetBranchAddress("H_reg_corrJERUp_phi", &H_reg_corrJERUp_phi, &b_H_reg_corrJERUp_phi);
   fChain->SetBranchAddress("H_reg_corrJERUp_mass", &H_reg_corrJERUp_mass, &b_H_reg_corrJERUp_mass);
   fChain->SetBranchAddress("H_reg_corrJECDown_pt", &H_reg_corrJECDown_pt, &b_H_reg_corrJECDown_pt);
   fChain->SetBranchAddress("H_reg_corrJECDown_eta", &H_reg_corrJECDown_eta, &b_H_reg_corrJECDown_eta);
   fChain->SetBranchAddress("H_reg_corrJECDown_phi", &H_reg_corrJECDown_phi, &b_H_reg_corrJECDown_phi);
   fChain->SetBranchAddress("H_reg_corrJECDown_mass", &H_reg_corrJECDown_mass, &b_H_reg_corrJECDown_mass);
   fChain->SetBranchAddress("nGenBQuarkFromHafterISR", &nGenBQuarkFromHafterISR, &b_nGenBQuarkFromHafterISR);
   fChain->SetBranchAddress("GenBQuarkFromHafterISR_pdgId", &GenBQuarkFromHafterISR_pdgId, &b_GenBQuarkFromHafterISR_pdgId);
   fChain->SetBranchAddress("GenBQuarkFromHafterISR_pt", &GenBQuarkFromHafterISR_pt, &b_GenBQuarkFromHafterISR_pt);
   fChain->SetBranchAddress("GenBQuarkFromHafterISR_eta", &GenBQuarkFromHafterISR_eta, &b_GenBQuarkFromHafterISR_eta);
   fChain->SetBranchAddress("GenBQuarkFromHafterISR_phi", &GenBQuarkFromHafterISR_phi, &b_GenBQuarkFromHafterISR_phi);
   fChain->SetBranchAddress("GenBQuarkFromHafterISR_mass", &GenBQuarkFromHafterISR_mass, &b_GenBQuarkFromHafterISR_mass);
   fChain->SetBranchAddress("GenBQuarkFromHafterISR_charge", &GenBQuarkFromHafterISR_charge, &b_GenBQuarkFromHafterISR_charge);
   fChain->SetBranchAddress("GenBQuarkFromHafterISR_status", &GenBQuarkFromHafterISR_status, &b_GenBQuarkFromHafterISR_status);
   fChain->SetBranchAddress("GenBQuarkFromHafterISR_isPromptHard", &GenBQuarkFromHafterISR_isPromptHard, &b_GenBQuarkFromHafterISR_isPromptHard);
   fChain->SetBranchAddress("npileUpVertex_ptHat", &npileUpVertex_ptHat, &b_npileUpVertex_ptHat);
   fChain->SetBranchAddress("pileUpVertex_ptHat", pileUpVertex_ptHat, &b_pileUpVertex_ptHat);
   fChain->SetBranchAddress("ntrgObjects_hltMET70", &ntrgObjects_hltMET70, &b_ntrgObjects_hltMET70);
   fChain->SetBranchAddress("ntrgObjects_hltL1sTripleJetVBFIorHTTIorDoubleJetCIorSingleJet", &ntrgObjects_hltL1sTripleJetVBFIorHTTIorDoubleJetCIorSingleJet, &b_ntrgObjects_hltL1sTripleJetVBFIorHTTIorDoubleJetCIorSingleJet);
   fChain->SetBranchAddress("ntrgObjects_hltBTagPFCSVp11DoubleWithMatching", &ntrgObjects_hltBTagPFCSVp11DoubleWithMatching, &b_ntrgObjects_hltBTagPFCSVp11DoubleWithMatching);
   fChain->SetBranchAddress("nGenLepFromTop", &nGenLepFromTop, &b_nGenLepFromTop);
   fChain->SetBranchAddress("GenLepFromTop_pdgId", GenLepFromTop_pdgId, &b_GenLepFromTop_pdgId);
   fChain->SetBranchAddress("GenLepFromTop_pt", GenLepFromTop_pt, &b_GenLepFromTop_pt);
   fChain->SetBranchAddress("GenLepFromTop_eta", GenLepFromTop_eta, &b_GenLepFromTop_eta);
   fChain->SetBranchAddress("GenLepFromTop_phi", GenLepFromTop_phi, &b_GenLepFromTop_phi);
   fChain->SetBranchAddress("GenLepFromTop_mass", GenLepFromTop_mass, &b_GenLepFromTop_mass);
   fChain->SetBranchAddress("GenLepFromTop_charge", GenLepFromTop_charge, &b_GenLepFromTop_charge);
   fChain->SetBranchAddress("GenLepFromTop_status", GenLepFromTop_status, &b_GenLepFromTop_status);
   fChain->SetBranchAddress("GenLepFromTop_isPromptHard", GenLepFromTop_isPromptHard, &b_GenLepFromTop_isPromptHard);
   fChain->SetBranchAddress("najidxaddJetsdR08", &najidxaddJetsdR08, &b_najidxaddJetsdR08);
   fChain->SetBranchAddress("ajidxaddJetsdR08", ajidxaddJetsdR08, &b_ajidxaddJetsdR08);
   fChain->SetBranchAddress("nSubjetCA15softdrop", &nSubjetCA15softdrop, &b_nSubjetCA15softdrop);
   fChain->SetBranchAddress("SubjetCA15softdrop_pt", SubjetCA15softdrop_pt, &b_SubjetCA15softdrop_pt);
   fChain->SetBranchAddress("SubjetCA15softdrop_eta", SubjetCA15softdrop_eta, &b_SubjetCA15softdrop_eta);
   fChain->SetBranchAddress("SubjetCA15softdrop_phi", SubjetCA15softdrop_phi, &b_SubjetCA15softdrop_phi);
   fChain->SetBranchAddress("SubjetCA15softdrop_mass", SubjetCA15softdrop_mass, &b_SubjetCA15softdrop_mass);
   fChain->SetBranchAddress("SubjetCA15softdrop_btag", SubjetCA15softdrop_btag, &b_SubjetCA15softdrop_btag);
   fChain->SetBranchAddress("SubjetCA15softdrop_jetID", SubjetCA15softdrop_jetID, &b_SubjetCA15softdrop_jetID);
   fChain->SetBranchAddress("SubjetCA15softdrop_fromFJ", SubjetCA15softdrop_fromFJ, &b_SubjetCA15softdrop_fromFJ);
   fChain->SetBranchAddress("ntrgObjects_hltIsoMu20", &ntrgObjects_hltIsoMu20, &b_ntrgObjects_hltIsoMu20);
   fChain->SetBranchAddress("trgObjects_hltIsoMu20_pt", &trgObjects_hltIsoMu20_pt, &b_trgObjects_hltIsoMu20_pt);
   fChain->SetBranchAddress("trgObjects_hltIsoMu20_eta", &trgObjects_hltIsoMu20_eta, &b_trgObjects_hltIsoMu20_eta);
   fChain->SetBranchAddress("trgObjects_hltIsoMu20_phi", &trgObjects_hltIsoMu20_phi, &b_trgObjects_hltIsoMu20_phi);
   fChain->SetBranchAddress("trgObjects_hltIsoMu20_mass", &trgObjects_hltIsoMu20_mass, &b_trgObjects_hltIsoMu20_mass);
   fChain->SetBranchAddress("ntrgObjects_hltQuadCentralJet30", &ntrgObjects_hltQuadCentralJet30, &b_ntrgObjects_hltQuadCentralJet30);
   fChain->SetBranchAddress("nGenVbosonsRecovered", &nGenVbosonsRecovered, &b_nGenVbosonsRecovered);
   fChain->SetBranchAddress("GenVbosonsRecovered_pdgId", &GenVbosonsRecovered_pdgId, &b_GenVbosonsRecovered_pdgId);
   fChain->SetBranchAddress("GenVbosonsRecovered_pt", &GenVbosonsRecovered_pt, &b_GenVbosonsRecovered_pt);
   fChain->SetBranchAddress("GenVbosonsRecovered_eta", &GenVbosonsRecovered_eta, &b_GenVbosonsRecovered_eta);
   fChain->SetBranchAddress("GenVbosonsRecovered_phi", &GenVbosonsRecovered_phi, &b_GenVbosonsRecovered_phi);
   fChain->SetBranchAddress("GenVbosonsRecovered_mass", &GenVbosonsRecovered_mass, &b_GenVbosonsRecovered_mass);
   fChain->SetBranchAddress("GenVbosonsRecovered_charge", &GenVbosonsRecovered_charge, &b_GenVbosonsRecovered_charge);
   fChain->SetBranchAddress("GenVbosonsRecovered_status", &GenVbosonsRecovered_status, &b_GenVbosonsRecovered_status);
   fChain->SetBranchAddress("GenVbosonsRecovered_isPromptHard", &GenVbosonsRecovered_isPromptHard, &b_GenVbosonsRecovered_isPromptHard);
   fChain->SetBranchAddress("nhJidx_sortcsv", &nhJidx_sortcsv, &b_nhJidx_sortcsv);
   fChain->SetBranchAddress("hJidx_sortcsv", hJidx_sortcsv, &b_hJidx_sortcsv);
   fChain->SetBranchAddress("ntrgObjects_hltL1sQuadJetCIorTripleJetVBFIorHTT", &ntrgObjects_hltL1sQuadJetCIorTripleJetVBFIorHTT, &b_ntrgObjects_hltL1sQuadJetCIorTripleJetVBFIorHTT);
   fChain->SetBranchAddress("nGenTausRecovered", &nGenTausRecovered, &b_nGenTausRecovered);
   fChain->SetBranchAddress("GenTausRecovered_pdgId", &GenTausRecovered_pdgId, &b_GenTausRecovered_pdgId);
   fChain->SetBranchAddress("GenTausRecovered_pt", &GenTausRecovered_pt, &b_GenTausRecovered_pt);
   fChain->SetBranchAddress("GenTausRecovered_eta", &GenTausRecovered_eta, &b_GenTausRecovered_eta);
   fChain->SetBranchAddress("GenTausRecovered_phi", &GenTausRecovered_phi, &b_GenTausRecovered_phi);
   fChain->SetBranchAddress("GenTausRecovered_mass", &GenTausRecovered_mass, &b_GenTausRecovered_mass);
   fChain->SetBranchAddress("GenTausRecovered_charge", &GenTausRecovered_charge, &b_GenTausRecovered_charge);
   fChain->SetBranchAddress("GenTausRecovered_status", &GenTausRecovered_status, &b_GenTausRecovered_status);
   fChain->SetBranchAddress("GenTausRecovered_isPromptHard", &GenTausRecovered_isPromptHard, &b_GenTausRecovered_isPromptHard);
   fChain->SetBranchAddress("nSubjetCA15softdropz2b1", &nSubjetCA15softdropz2b1, &b_nSubjetCA15softdropz2b1);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1_pt", SubjetCA15softdropz2b1_pt, &b_SubjetCA15softdropz2b1_pt);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1_eta", SubjetCA15softdropz2b1_eta, &b_SubjetCA15softdropz2b1_eta);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1_phi", SubjetCA15softdropz2b1_phi, &b_SubjetCA15softdropz2b1_phi);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1_mass", SubjetCA15softdropz2b1_mass, &b_SubjetCA15softdropz2b1_mass);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1_btag", SubjetCA15softdropz2b1_btag, &b_SubjetCA15softdropz2b1_btag);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1_jetID", SubjetCA15softdropz2b1_jetID, &b_SubjetCA15softdropz2b1_jetID);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1_fromFJ", SubjetCA15softdropz2b1_fromFJ, &b_SubjetCA15softdropz2b1_fromFJ);
   fChain->SetBranchAddress("nhJCidx", &nhJCidx, &b_nhJCidx);
   fChain->SetBranchAddress("hJCidx", hJCidx, &b_hJCidx);
   fChain->SetBranchAddress("nGenTop", &nGenTop, &b_nGenTop);
   fChain->SetBranchAddress("GenTop_charge", GenTop_charge, &b_GenTop_charge);
   fChain->SetBranchAddress("GenTop_status", GenTop_status, &b_GenTop_status);
   fChain->SetBranchAddress("GenTop_isPromptHard", GenTop_isPromptHard, &b_GenTop_isPromptHard);
   fChain->SetBranchAddress("GenTop_pdgId", GenTop_pdgId, &b_GenTop_pdgId);
   fChain->SetBranchAddress("GenTop_pt", GenTop_pt, &b_GenTop_pt);
   fChain->SetBranchAddress("GenTop_eta", GenTop_eta, &b_GenTop_eta);
   fChain->SetBranchAddress("GenTop_phi", GenTop_phi, &b_GenTop_phi);
   fChain->SetBranchAddress("GenTop_mass", GenTop_mass, &b_GenTop_mass);
   fChain->SetBranchAddress("GenTop_decayMode", GenTop_decayMode, &b_GenTop_decayMode);
   fChain->SetBranchAddress("naJidx", &naJidx, &b_naJidx);
   fChain->SetBranchAddress("aJidx", aJidx, &b_aJidx);
   fChain->SetBranchAddress("nGenLepFromTau", &nGenLepFromTau, &b_nGenLepFromTau);
   fChain->SetBranchAddress("GenLepFromTau_pdgId", &GenLepFromTau_pdgId, &b_GenLepFromTau_pdgId);
   fChain->SetBranchAddress("GenLepFromTau_pt", &GenLepFromTau_pt, &b_GenLepFromTau_pt);
   fChain->SetBranchAddress("GenLepFromTau_eta", &GenLepFromTau_eta, &b_GenLepFromTau_eta);
   fChain->SetBranchAddress("GenLepFromTau_phi", &GenLepFromTau_phi, &b_GenLepFromTau_phi);
   fChain->SetBranchAddress("GenLepFromTau_mass", &GenLepFromTau_mass, &b_GenLepFromTau_mass);
   fChain->SetBranchAddress("GenLepFromTau_charge", &GenLepFromTau_charge, &b_GenLepFromTau_charge);
   fChain->SetBranchAddress("GenLepFromTau_status", &GenLepFromTau_status, &b_GenLepFromTau_status);
   fChain->SetBranchAddress("GenLepFromTau_isPromptHard", &GenLepFromTau_isPromptHard, &b_GenLepFromTau_isPromptHard);
   fChain->SetBranchAddress("nGenNuFromTop", &nGenNuFromTop, &b_nGenNuFromTop);
   fChain->SetBranchAddress("GenNuFromTop_pdgId", GenNuFromTop_pdgId, &b_GenNuFromTop_pdgId);
   fChain->SetBranchAddress("GenNuFromTop_pt", GenNuFromTop_pt, &b_GenNuFromTop_pt);
   fChain->SetBranchAddress("GenNuFromTop_eta", GenNuFromTop_eta, &b_GenNuFromTop_eta);
   fChain->SetBranchAddress("GenNuFromTop_phi", GenNuFromTop_phi, &b_GenNuFromTop_phi);
   fChain->SetBranchAddress("GenNuFromTop_mass", GenNuFromTop_mass, &b_GenNuFromTop_mass);
   fChain->SetBranchAddress("GenNuFromTop_charge", GenNuFromTop_charge, &b_GenNuFromTop_charge);
   fChain->SetBranchAddress("GenNuFromTop_status", GenNuFromTop_status, &b_GenNuFromTop_status);
   fChain->SetBranchAddress("GenNuFromTop_isPromptHard", GenNuFromTop_isPromptHard, &b_GenNuFromTop_isPromptHard);
   fChain->SetBranchAddress("ntrgObjects_hltPFDoubleJetLooseID76", &ntrgObjects_hltPFDoubleJetLooseID76, &b_ntrgObjects_hltPFDoubleJetLooseID76);
   fChain->SetBranchAddress("ntrgObjects_hltBTagPFCSVp016SingleWithMatching", &ntrgObjects_hltBTagPFCSVp016SingleWithMatching, &b_ntrgObjects_hltBTagPFCSVp016SingleWithMatching);
   fChain->SetBranchAddress("nGenVbosons", &nGenVbosons, &b_nGenVbosons);
   fChain->SetBranchAddress("GenVbosons_pdgId", GenVbosons_pdgId, &b_GenVbosons_pdgId);
   fChain->SetBranchAddress("GenVbosons_pt", GenVbosons_pt, &b_GenVbosons_pt);
   fChain->SetBranchAddress("GenVbosons_eta", GenVbosons_eta, &b_GenVbosons_eta);
   fChain->SetBranchAddress("GenVbosons_phi", GenVbosons_phi, &b_GenVbosons_phi);
   fChain->SetBranchAddress("GenVbosons_mass", GenVbosons_mass, &b_GenVbosons_mass);
   fChain->SetBranchAddress("GenVbosons_charge", GenVbosons_charge, &b_GenVbosons_charge);
   fChain->SetBranchAddress("GenVbosons_status", GenVbosons_status, &b_GenVbosons_status);
   fChain->SetBranchAddress("GenVbosons_isPromptHard", GenVbosons_isPromptHard, &b_GenVbosons_isPromptHard);
   fChain->SetBranchAddress("nsoftActivityVHJets", &nsoftActivityVHJets, &b_nsoftActivityVHJets);
   fChain->SetBranchAddress("softActivityVHJets_pt", softActivityVHJets_pt, &b_softActivityVHJets_pt);
   fChain->SetBranchAddress("softActivityVHJets_eta", softActivityVHJets_eta, &b_softActivityVHJets_eta);
   fChain->SetBranchAddress("softActivityVHJets_phi", softActivityVHJets_phi, &b_softActivityVHJets_phi);
   fChain->SetBranchAddress("softActivityVHJets_mass", softActivityVHJets_mass, &b_softActivityVHJets_mass);
   fChain->SetBranchAddress("ntrgObjects_hltQuadPFCentralJetLooseID30", &ntrgObjects_hltQuadPFCentralJetLooseID30, &b_ntrgObjects_hltQuadPFCentralJetLooseID30);
   fChain->SetBranchAddress("ntrgObjects_caloMhtNoPU", &ntrgObjects_caloMhtNoPU, &b_ntrgObjects_caloMhtNoPU);
   fChain->SetBranchAddress("trgObjects_caloMhtNoPU_pt", &trgObjects_caloMhtNoPU_pt, &b_trgObjects_caloMhtNoPU_pt);
   fChain->SetBranchAddress("ntrgObjects_hltEle25eta2p1WPLoose", &ntrgObjects_hltEle25eta2p1WPLoose, &b_ntrgObjects_hltEle25eta2p1WPLoose);
   fChain->SetBranchAddress("trgObjects_hltEle25eta2p1WPLoose_pt", &trgObjects_hltEle25eta2p1WPLoose_pt, &b_trgObjects_hltEle25eta2p1WPLoose_pt);
   fChain->SetBranchAddress("trgObjects_hltEle25eta2p1WPLoose_eta", &trgObjects_hltEle25eta2p1WPLoose_eta, &b_trgObjects_hltEle25eta2p1WPLoose_eta);
   fChain->SetBranchAddress("trgObjects_hltEle25eta2p1WPLoose_phi", &trgObjects_hltEle25eta2p1WPLoose_phi, &b_trgObjects_hltEle25eta2p1WPLoose_phi);
   fChain->SetBranchAddress("trgObjects_hltEle25eta2p1WPLoose_mass", &trgObjects_hltEle25eta2p1WPLoose_mass, &b_trgObjects_hltEle25eta2p1WPLoose_mass);
   fChain->SetBranchAddress("nSubjetAK08softdrop", &nSubjetAK08softdrop, &b_nSubjetAK08softdrop);
   fChain->SetBranchAddress("SubjetAK08softdrop_pt", SubjetAK08softdrop_pt, &b_SubjetAK08softdrop_pt);
   fChain->SetBranchAddress("SubjetAK08softdrop_eta", SubjetAK08softdrop_eta, &b_SubjetAK08softdrop_eta);
   fChain->SetBranchAddress("SubjetAK08softdrop_phi", SubjetAK08softdrop_phi, &b_SubjetAK08softdrop_phi);
   fChain->SetBranchAddress("SubjetAK08softdrop_mass", SubjetAK08softdrop_mass, &b_SubjetAK08softdrop_mass);
   fChain->SetBranchAddress("SubjetAK08softdrop_btag", SubjetAK08softdrop_btag, &b_SubjetAK08softdrop_btag);
   fChain->SetBranchAddress("ntrgObjects_hltDoublePFCentralJetLooseID90", &ntrgObjects_hltDoublePFCentralJetLooseID90, &b_ntrgObjects_hltDoublePFCentralJetLooseID90);
   fChain->SetBranchAddress("nGenLep", &nGenLep, &b_nGenLep);
   fChain->SetBranchAddress("GenLep_pdgId", GenLep_pdgId, &b_GenLep_pdgId);
   fChain->SetBranchAddress("GenLep_pt", GenLep_pt, &b_GenLep_pt);
   fChain->SetBranchAddress("GenLep_eta", GenLep_eta, &b_GenLep_eta);
   fChain->SetBranchAddress("GenLep_phi", GenLep_phi, &b_GenLep_phi);
   fChain->SetBranchAddress("GenLep_mass", GenLep_mass, &b_GenLep_mass);
   fChain->SetBranchAddress("GenLep_charge", GenLep_charge, &b_GenLep_charge);
   fChain->SetBranchAddress("GenLep_status", GenLep_status, &b_GenLep_status);
   fChain->SetBranchAddress("GenLep_isPromptHard", GenLep_isPromptHard, &b_GenLep_isPromptHard);
   fChain->SetBranchAddress("ntrgObjects_caloJets", &ntrgObjects_caloJets, &b_ntrgObjects_caloJets);
   fChain->SetBranchAddress("trgObjects_caloJets_pt", trgObjects_caloJets_pt, &b_trgObjects_caloJets_pt);
   fChain->SetBranchAddress("ntrgObjects_hltPFSingleJetLooseID92", &ntrgObjects_hltPFSingleJetLooseID92, &b_ntrgObjects_hltPFSingleJetLooseID92);
   fChain->SetBranchAddress("nGenHadTaus", &nGenHadTaus, &b_nGenHadTaus);
   fChain->SetBranchAddress("GenHadTaus_charge", GenHadTaus_charge, &b_GenHadTaus_charge);
   fChain->SetBranchAddress("GenHadTaus_status", GenHadTaus_status, &b_GenHadTaus_status);
   fChain->SetBranchAddress("GenHadTaus_isPromptHard", GenHadTaus_isPromptHard, &b_GenHadTaus_isPromptHard);
   fChain->SetBranchAddress("GenHadTaus_pdgId", GenHadTaus_pdgId, &b_GenHadTaus_pdgId);
   fChain->SetBranchAddress("GenHadTaus_pt", GenHadTaus_pt, &b_GenHadTaus_pt);
   fChain->SetBranchAddress("GenHadTaus_eta", GenHadTaus_eta, &b_GenHadTaus_eta);
   fChain->SetBranchAddress("GenHadTaus_phi", GenHadTaus_phi, &b_GenHadTaus_phi);
   fChain->SetBranchAddress("GenHadTaus_mass", GenHadTaus_mass, &b_GenHadTaus_mass);
   fChain->SetBranchAddress("GenHadTaus_decayMode", GenHadTaus_decayMode, &b_GenHadTaus_decayMode);
   fChain->SetBranchAddress("ntrgObjects_hltL1sETM50ToETM100IorETM60Jet60dPhiMin0p4IorDoubleJetC60ETM60", &ntrgObjects_hltL1sETM50ToETM100IorETM60Jet60dPhiMin0p4IorDoubleJetC60ETM60, &b_ntrgObjects_hltL1sETM50ToETM100IorETM60Jet60dPhiMin0p4IorDoubleJetC60ETM60);
   fChain->SetBranchAddress("ntrgObjects_hltEle25WPTight", &ntrgObjects_hltEle25WPTight, &b_ntrgObjects_hltEle25WPTight);
   fChain->SetBranchAddress("trgObjects_hltEle25WPTight_pt", &trgObjects_hltEle25WPTight_pt, &b_trgObjects_hltEle25WPTight_pt);
   fChain->SetBranchAddress("trgObjects_hltEle25WPTight_eta", &trgObjects_hltEle25WPTight_eta, &b_trgObjects_hltEle25WPTight_eta);
   fChain->SetBranchAddress("trgObjects_hltEle25WPTight_phi", &trgObjects_hltEle25WPTight_phi, &b_trgObjects_hltEle25WPTight_phi);
   fChain->SetBranchAddress("trgObjects_hltEle25WPTight_mass", &trgObjects_hltEle25WPTight_mass, &b_trgObjects_hltEle25WPTight_mass);
   fChain->SetBranchAddress("ntrgObjects_pfJets", &ntrgObjects_pfJets, &b_ntrgObjects_pfJets);
   fChain->SetBranchAddress("trgObjects_pfJets_pt", trgObjects_pfJets_pt, &b_trgObjects_pfJets_pt);
   fChain->SetBranchAddress("nSubjetCA15subjetfiltered", &nSubjetCA15subjetfiltered, &b_nSubjetCA15subjetfiltered);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_pt", SubjetCA15subjetfiltered_pt, &b_SubjetCA15subjetfiltered_pt);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_eta", SubjetCA15subjetfiltered_eta, &b_SubjetCA15subjetfiltered_eta);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_phi", SubjetCA15subjetfiltered_phi, &b_SubjetCA15subjetfiltered_phi);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_mass", SubjetCA15subjetfiltered_mass, &b_SubjetCA15subjetfiltered_mass);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_btag", SubjetCA15subjetfiltered_btag, &b_SubjetCA15subjetfiltered_btag);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_jetID", SubjetCA15subjetfiltered_jetID, &b_SubjetCA15subjetfiltered_jetID);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_fromFJ", SubjetCA15subjetfiltered_fromFJ, &b_SubjetCA15subjetfiltered_fromFJ);
   fChain->SetBranchAddress("nvLeptons", &nvLeptons, &b_nvLeptons);
   fChain->SetBranchAddress("vLeptons_charge", vLeptons_charge, &b_vLeptons_charge);
   fChain->SetBranchAddress("vLeptons_tightId", vLeptons_tightId, &b_vLeptons_tightId);
   fChain->SetBranchAddress("vLeptons_eleCutIdCSA14_25ns_v1", vLeptons_eleCutIdCSA14_25ns_v1, &b_vLeptons_eleCutIdCSA14_25ns_v1);
   fChain->SetBranchAddress("vLeptons_eleCutIdCSA14_50ns_v1", vLeptons_eleCutIdCSA14_50ns_v1, &b_vLeptons_eleCutIdCSA14_50ns_v1);
   fChain->SetBranchAddress("vLeptons_eleCutIdSpring15_25ns_v1", vLeptons_eleCutIdSpring15_25ns_v1, &b_vLeptons_eleCutIdSpring15_25ns_v1);
   fChain->SetBranchAddress("vLeptons_dxy", vLeptons_dxy, &b_vLeptons_dxy);
   fChain->SetBranchAddress("vLeptons_dz", vLeptons_dz, &b_vLeptons_dz);
   fChain->SetBranchAddress("vLeptons_edxy", vLeptons_edxy, &b_vLeptons_edxy);
   fChain->SetBranchAddress("vLeptons_edz", vLeptons_edz, &b_vLeptons_edz);
   fChain->SetBranchAddress("vLeptons_ip3d", vLeptons_ip3d, &b_vLeptons_ip3d);
   fChain->SetBranchAddress("vLeptons_sip3d", vLeptons_sip3d, &b_vLeptons_sip3d);
   fChain->SetBranchAddress("vLeptons_convVeto", vLeptons_convVeto, &b_vLeptons_convVeto);
   fChain->SetBranchAddress("vLeptons_lostHits", vLeptons_lostHits, &b_vLeptons_lostHits);
   fChain->SetBranchAddress("vLeptons_relIso03", vLeptons_relIso03, &b_vLeptons_relIso03);
   fChain->SetBranchAddress("vLeptons_relIso04", vLeptons_relIso04, &b_vLeptons_relIso04);
   fChain->SetBranchAddress("vLeptons_miniRelIso", vLeptons_miniRelIso, &b_vLeptons_miniRelIso);
   fChain->SetBranchAddress("vLeptons_relIsoAn04", vLeptons_relIsoAn04, &b_vLeptons_relIsoAn04);
   fChain->SetBranchAddress("vLeptons_tightCharge", vLeptons_tightCharge, &b_vLeptons_tightCharge);
   fChain->SetBranchAddress("vLeptons_mcMatchId", vLeptons_mcMatchId, &b_vLeptons_mcMatchId);
   fChain->SetBranchAddress("vLeptons_mcMatchAny", vLeptons_mcMatchAny, &b_vLeptons_mcMatchAny);
   fChain->SetBranchAddress("vLeptons_mcMatchTau", vLeptons_mcMatchTau, &b_vLeptons_mcMatchTau);
   fChain->SetBranchAddress("vLeptons_mcPt", vLeptons_mcPt, &b_vLeptons_mcPt);
   fChain->SetBranchAddress("vLeptons_mediumMuonId", vLeptons_mediumMuonId, &b_vLeptons_mediumMuonId);
   fChain->SetBranchAddress("vLeptons_pdgId", vLeptons_pdgId, &b_vLeptons_pdgId);
   fChain->SetBranchAddress("vLeptons_pt", vLeptons_pt, &b_vLeptons_pt);
   fChain->SetBranchAddress("vLeptons_eta", vLeptons_eta, &b_vLeptons_eta);
   fChain->SetBranchAddress("vLeptons_phi", vLeptons_phi, &b_vLeptons_phi);
   fChain->SetBranchAddress("vLeptons_mass", vLeptons_mass, &b_vLeptons_mass);
   fChain->SetBranchAddress("vLeptons_looseIdSusy", vLeptons_looseIdSusy, &b_vLeptons_looseIdSusy);
   fChain->SetBranchAddress("vLeptons_looseIdPOG", vLeptons_looseIdPOG, &b_vLeptons_looseIdPOG);
   fChain->SetBranchAddress("vLeptons_chargedHadRelIso03", vLeptons_chargedHadRelIso03, &b_vLeptons_chargedHadRelIso03);
   fChain->SetBranchAddress("vLeptons_chargedHadRelIso04", vLeptons_chargedHadRelIso04, &b_vLeptons_chargedHadRelIso04);
   fChain->SetBranchAddress("vLeptons_eleSieie", vLeptons_eleSieie, &b_vLeptons_eleSieie);
   fChain->SetBranchAddress("vLeptons_eleDEta", vLeptons_eleDEta, &b_vLeptons_eleDEta);
   fChain->SetBranchAddress("vLeptons_eleDPhi", vLeptons_eleDPhi, &b_vLeptons_eleDPhi);
   fChain->SetBranchAddress("vLeptons_eleHoE", vLeptons_eleHoE, &b_vLeptons_eleHoE);
   fChain->SetBranchAddress("vLeptons_eleMissingHits", vLeptons_eleMissingHits, &b_vLeptons_eleMissingHits);
   fChain->SetBranchAddress("vLeptons_eleChi2", vLeptons_eleChi2, &b_vLeptons_eleChi2);
   fChain->SetBranchAddress("vLeptons_convVetoFull", vLeptons_convVetoFull, &b_vLeptons_convVetoFull);
   fChain->SetBranchAddress("vLeptons_eleMVArawSpring15Trig", vLeptons_eleMVArawSpring15Trig, &b_vLeptons_eleMVArawSpring15Trig);
   fChain->SetBranchAddress("vLeptons_eleMVAIdSpring15Trig", vLeptons_eleMVAIdSpring15Trig, &b_vLeptons_eleMVAIdSpring15Trig);
   fChain->SetBranchAddress("vLeptons_eleMVArawSpring15NonTrig", vLeptons_eleMVArawSpring15NonTrig, &b_vLeptons_eleMVArawSpring15NonTrig);
   fChain->SetBranchAddress("vLeptons_eleMVAIdSpring15NonTrig", vLeptons_eleMVAIdSpring15NonTrig, &b_vLeptons_eleMVAIdSpring15NonTrig);
   fChain->SetBranchAddress("vLeptons_nStations", vLeptons_nStations, &b_vLeptons_nStations);
   fChain->SetBranchAddress("vLeptons_trkKink", vLeptons_trkKink, &b_vLeptons_trkKink);
   fChain->SetBranchAddress("vLeptons_segmentCompatibility", vLeptons_segmentCompatibility, &b_vLeptons_segmentCompatibility);
   fChain->SetBranchAddress("vLeptons_caloCompatibility", vLeptons_caloCompatibility, &b_vLeptons_caloCompatibility);
   fChain->SetBranchAddress("vLeptons_globalTrackChi2", vLeptons_globalTrackChi2, &b_vLeptons_globalTrackChi2);
   fChain->SetBranchAddress("vLeptons_nChamberHits", vLeptons_nChamberHits, &b_vLeptons_nChamberHits);
   fChain->SetBranchAddress("vLeptons_isPFMuon", vLeptons_isPFMuon, &b_vLeptons_isPFMuon);
   fChain->SetBranchAddress("vLeptons_isGlobalMuon", vLeptons_isGlobalMuon, &b_vLeptons_isGlobalMuon);
   fChain->SetBranchAddress("vLeptons_isTrackerMuon", vLeptons_isTrackerMuon, &b_vLeptons_isTrackerMuon);
   fChain->SetBranchAddress("vLeptons_pixelHits", vLeptons_pixelHits, &b_vLeptons_pixelHits);
   fChain->SetBranchAddress("vLeptons_trackerLayers", vLeptons_trackerLayers, &b_vLeptons_trackerLayers);
   fChain->SetBranchAddress("vLeptons_pixelLayers", vLeptons_pixelLayers, &b_vLeptons_pixelLayers);
   fChain->SetBranchAddress("vLeptons_mvaTTH", vLeptons_mvaTTH, &b_vLeptons_mvaTTH);
   fChain->SetBranchAddress("vLeptons_jetOverlapIdx", vLeptons_jetOverlapIdx, &b_vLeptons_jetOverlapIdx);
   fChain->SetBranchAddress("vLeptons_jetPtRatio", vLeptons_jetPtRatio, &b_vLeptons_jetPtRatio);
   fChain->SetBranchAddress("vLeptons_jetBTagCSV", vLeptons_jetBTagCSV, &b_vLeptons_jetBTagCSV);
   fChain->SetBranchAddress("vLeptons_jetDR", vLeptons_jetDR, &b_vLeptons_jetDR);
   fChain->SetBranchAddress("vLeptons_mvaTTHjetPtRatio", vLeptons_mvaTTHjetPtRatio, &b_vLeptons_mvaTTHjetPtRatio);
   fChain->SetBranchAddress("vLeptons_mvaTTHjetBTagCSV", vLeptons_mvaTTHjetBTagCSV, &b_vLeptons_mvaTTHjetBTagCSV);
   fChain->SetBranchAddress("vLeptons_mvaTTHjetDR", vLeptons_mvaTTHjetDR, &b_vLeptons_mvaTTHjetDR);
   fChain->SetBranchAddress("vLeptons_pfRelIso03", vLeptons_pfRelIso03, &b_vLeptons_pfRelIso03);
   fChain->SetBranchAddress("vLeptons_pfRelIso04", vLeptons_pfRelIso04, &b_vLeptons_pfRelIso04);
   fChain->SetBranchAddress("vLeptons_etaSc", vLeptons_etaSc, &b_vLeptons_etaSc);
   fChain->SetBranchAddress("vLeptons_eleExpMissingInnerHits", vLeptons_eleExpMissingInnerHits, &b_vLeptons_eleExpMissingInnerHits);
   fChain->SetBranchAddress("vLeptons_eleooEmooP", vLeptons_eleooEmooP, &b_vLeptons_eleooEmooP);
   fChain->SetBranchAddress("vLeptons_dr03TkSumPt", vLeptons_dr03TkSumPt, &b_vLeptons_dr03TkSumPt);
   fChain->SetBranchAddress("vLeptons_eleEcalClusterIso", vLeptons_eleEcalClusterIso, &b_vLeptons_eleEcalClusterIso);
   fChain->SetBranchAddress("vLeptons_eleHcalClusterIso", vLeptons_eleHcalClusterIso, &b_vLeptons_eleHcalClusterIso);
   fChain->SetBranchAddress("vLeptons_miniIsoCharged", vLeptons_miniIsoCharged, &b_vLeptons_miniIsoCharged);
   fChain->SetBranchAddress("vLeptons_miniIsoNeutral", vLeptons_miniIsoNeutral, &b_vLeptons_miniIsoNeutral);
   fChain->SetBranchAddress("vLeptons_mvaTTHjetPtRel", vLeptons_mvaTTHjetPtRel, &b_vLeptons_mvaTTHjetPtRel);
   fChain->SetBranchAddress("vLeptons_mvaTTHjetNDauChargedMVASel", vLeptons_mvaTTHjetNDauChargedMVASel, &b_vLeptons_mvaTTHjetNDauChargedMVASel);
   fChain->SetBranchAddress("vLeptons_uncalibratedPt", vLeptons_uncalibratedPt, &b_vLeptons_uncalibratedPt);
   fChain->SetBranchAddress("vLeptons_SF_IsoLoose", vLeptons_SF_IsoLoose, &b_vLeptons_SF_IsoLoose);
   fChain->SetBranchAddress("vLeptons_SFerr_IsoLoose", vLeptons_SFerr_IsoLoose, &b_vLeptons_SFerr_IsoLoose);
   fChain->SetBranchAddress("vLeptons_SF_IsoTight", vLeptons_SF_IsoTight, &b_vLeptons_SF_IsoTight);
   fChain->SetBranchAddress("vLeptons_SFerr_IsoTight", vLeptons_SFerr_IsoTight, &b_vLeptons_SFerr_IsoTight);
   fChain->SetBranchAddress("vLeptons_SF_IdCutLoose", vLeptons_SF_IdCutLoose, &b_vLeptons_SF_IdCutLoose);
   fChain->SetBranchAddress("vLeptons_SFerr_IdCutLoose", vLeptons_SFerr_IdCutLoose, &b_vLeptons_SFerr_IdCutLoose);
   fChain->SetBranchAddress("vLeptons_SF_IdCutTight", vLeptons_SF_IdCutTight, &b_vLeptons_SF_IdCutTight);
   fChain->SetBranchAddress("vLeptons_SFerr_IdCutTight", vLeptons_SFerr_IdCutTight, &b_vLeptons_SFerr_IdCutTight);
   fChain->SetBranchAddress("vLeptons_SF_IdMVALoose", vLeptons_SF_IdMVALoose, &b_vLeptons_SF_IdMVALoose);
   fChain->SetBranchAddress("vLeptons_SFerr_IdMVALoose", vLeptons_SFerr_IdMVALoose, &b_vLeptons_SFerr_IdMVALoose);
   fChain->SetBranchAddress("vLeptons_SF_IdMVATight", vLeptons_SF_IdMVATight, &b_vLeptons_SF_IdMVATight);
   fChain->SetBranchAddress("vLeptons_SFerr_IdMVATight", vLeptons_SFerr_IdMVATight, &b_vLeptons_SFerr_IdMVATight);
   fChain->SetBranchAddress("vLeptons_SF_HLT_RunD4p3", vLeptons_SF_HLT_RunD4p3, &b_vLeptons_SF_HLT_RunD4p3);
   fChain->SetBranchAddress("vLeptons_SFerr_HLT_RunD4p3", vLeptons_SFerr_HLT_RunD4p3, &b_vLeptons_SFerr_HLT_RunD4p3);
   fChain->SetBranchAddress("vLeptons_SF_HLT_RunD4p2", vLeptons_SF_HLT_RunD4p2, &b_vLeptons_SF_HLT_RunD4p2);
   fChain->SetBranchAddress("vLeptons_SFerr_HLT_RunD4p2", vLeptons_SFerr_HLT_RunD4p2, &b_vLeptons_SFerr_HLT_RunD4p2);
   fChain->SetBranchAddress("vLeptons_SF_HLT_RunC", vLeptons_SF_HLT_RunC, &b_vLeptons_SF_HLT_RunC);
   fChain->SetBranchAddress("vLeptons_SFerr_HLT_RunC", vLeptons_SFerr_HLT_RunC, &b_vLeptons_SFerr_HLT_RunC);
   fChain->SetBranchAddress("vLeptons_Eff_HLT_RunD4p3", vLeptons_Eff_HLT_RunD4p3, &b_vLeptons_Eff_HLT_RunD4p3);
   fChain->SetBranchAddress("vLeptons_Efferr_HLT_RunD4p3", vLeptons_Efferr_HLT_RunD4p3, &b_vLeptons_Efferr_HLT_RunD4p3);
   fChain->SetBranchAddress("vLeptons_Eff_HLT_RunD4p2", vLeptons_Eff_HLT_RunD4p2, &b_vLeptons_Eff_HLT_RunD4p2);
   fChain->SetBranchAddress("vLeptons_Efferr_HLT_RunD4p2", vLeptons_Efferr_HLT_RunD4p2, &b_vLeptons_Efferr_HLT_RunD4p2);
   fChain->SetBranchAddress("vLeptons_Eff_HLT_RunC", vLeptons_Eff_HLT_RunC, &b_vLeptons_Eff_HLT_RunC);
   fChain->SetBranchAddress("vLeptons_Efferr_HLT_RunC", vLeptons_Efferr_HLT_RunC, &b_vLeptons_Efferr_HLT_RunC);
   fChain->SetBranchAddress("ntrgObjects_hltBTagCaloCSVp014DoubleWithMatching", &ntrgObjects_hltBTagCaloCSVp014DoubleWithMatching, &b_ntrgObjects_hltBTagCaloCSVp014DoubleWithMatching);
   fChain->SetBranchAddress("trgObjects_hltBTagCaloCSVp014DoubleWithMatching_pt", &trgObjects_hltBTagCaloCSVp014DoubleWithMatching_pt, &b_trgObjects_hltBTagCaloCSVp014DoubleWithMatching_pt);
   fChain->SetBranchAddress("trgObjects_hltBTagCaloCSVp014DoubleWithMatching_eta", &trgObjects_hltBTagCaloCSVp014DoubleWithMatching_eta, &b_trgObjects_hltBTagCaloCSVp014DoubleWithMatching_eta);
   fChain->SetBranchAddress("trgObjects_hltBTagCaloCSVp014DoubleWithMatching_phi", &trgObjects_hltBTagCaloCSVp014DoubleWithMatching_phi, &b_trgObjects_hltBTagCaloCSVp014DoubleWithMatching_phi);
   fChain->SetBranchAddress("trgObjects_hltBTagCaloCSVp014DoubleWithMatching_mass", &trgObjects_hltBTagCaloCSVp014DoubleWithMatching_mass, &b_trgObjects_hltBTagCaloCSVp014DoubleWithMatching_mass);
   fChain->SetBranchAddress("npileUpVertex_z", &npileUpVertex_z, &b_npileUpVertex_z);
   fChain->SetBranchAddress("pileUpVertex_z", pileUpVertex_z, &b_pileUpVertex_z);
   fChain->SetBranchAddress("ntrgObjects_pfMht", &ntrgObjects_pfMht, &b_ntrgObjects_pfMht);
   fChain->SetBranchAddress("trgObjects_pfMht_pt", &trgObjects_pfMht_pt, &b_trgObjects_pfMht_pt);
   fChain->SetBranchAddress("nGenBQuarkFromTop", &nGenBQuarkFromTop, &b_nGenBQuarkFromTop);
   fChain->SetBranchAddress("GenBQuarkFromTop_pdgId", GenBQuarkFromTop_pdgId, &b_GenBQuarkFromTop_pdgId);
   fChain->SetBranchAddress("GenBQuarkFromTop_pt", GenBQuarkFromTop_pt, &b_GenBQuarkFromTop_pt);
   fChain->SetBranchAddress("GenBQuarkFromTop_eta", GenBQuarkFromTop_eta, &b_GenBQuarkFromTop_eta);
   fChain->SetBranchAddress("GenBQuarkFromTop_phi", GenBQuarkFromTop_phi, &b_GenBQuarkFromTop_phi);
   fChain->SetBranchAddress("GenBQuarkFromTop_mass", GenBQuarkFromTop_mass, &b_GenBQuarkFromTop_mass);
   fChain->SetBranchAddress("GenBQuarkFromTop_charge", GenBQuarkFromTop_charge, &b_GenBQuarkFromTop_charge);
   fChain->SetBranchAddress("GenBQuarkFromTop_status", GenBQuarkFromTop_status, &b_GenBQuarkFromTop_status);
   fChain->SetBranchAddress("GenBQuarkFromTop_isPromptHard", GenBQuarkFromTop_isPromptHard, &b_GenBQuarkFromTop_isPromptHard);
   fChain->SetBranchAddress("nGenHiggsBoson", &nGenHiggsBoson, &b_nGenHiggsBoson);
   fChain->SetBranchAddress("GenHiggsBoson_pdgId", &GenHiggsBoson_pdgId, &b_GenHiggsBoson_pdgId);
   fChain->SetBranchAddress("GenHiggsBoson_pt", &GenHiggsBoson_pt, &b_GenHiggsBoson_pt);
   fChain->SetBranchAddress("GenHiggsBoson_eta", &GenHiggsBoson_eta, &b_GenHiggsBoson_eta);
   fChain->SetBranchAddress("GenHiggsBoson_phi", &GenHiggsBoson_phi, &b_GenHiggsBoson_phi);
   fChain->SetBranchAddress("GenHiggsBoson_mass", &GenHiggsBoson_mass, &b_GenHiggsBoson_mass);
   fChain->SetBranchAddress("GenHiggsBoson_charge", &GenHiggsBoson_charge, &b_GenHiggsBoson_charge);
   fChain->SetBranchAddress("GenHiggsBoson_status", &GenHiggsBoson_status, &b_GenHiggsBoson_status);
   fChain->SetBranchAddress("GenHiggsBoson_isPromptHard", &GenHiggsBoson_isPromptHard, &b_GenHiggsBoson_isPromptHard);
   fChain->SetBranchAddress("nLHE_weights_scale", &nLHE_weights_scale, &b_nLHE_weights_scale);
   fChain->SetBranchAddress("LHE_weights_scale_id", LHE_weights_scale_id, &b_LHE_weights_scale_id);
   fChain->SetBranchAddress("LHE_weights_scale_wgt", LHE_weights_scale_wgt, &b_LHE_weights_scale_wgt);
   fChain->SetBranchAddress("nGenLepFromTauRecovered", &nGenLepFromTauRecovered, &b_nGenLepFromTauRecovered);
   fChain->SetBranchAddress("GenLepFromTauRecovered_pdgId", &GenLepFromTauRecovered_pdgId, &b_GenLepFromTauRecovered_pdgId);
   fChain->SetBranchAddress("GenLepFromTauRecovered_pt", &GenLepFromTauRecovered_pt, &b_GenLepFromTauRecovered_pt);
   fChain->SetBranchAddress("GenLepFromTauRecovered_eta", &GenLepFromTauRecovered_eta, &b_GenLepFromTauRecovered_eta);
   fChain->SetBranchAddress("GenLepFromTauRecovered_phi", &GenLepFromTauRecovered_phi, &b_GenLepFromTauRecovered_phi);
   fChain->SetBranchAddress("GenLepFromTauRecovered_mass", &GenLepFromTauRecovered_mass, &b_GenLepFromTauRecovered_mass);
   fChain->SetBranchAddress("GenLepFromTauRecovered_charge", &GenLepFromTauRecovered_charge, &b_GenLepFromTauRecovered_charge);
   fChain->SetBranchAddress("GenLepFromTauRecovered_status", &GenLepFromTauRecovered_status, &b_GenLepFromTauRecovered_status);
   fChain->SetBranchAddress("GenLepFromTauRecovered_isPromptHard", &GenLepFromTauRecovered_isPromptHard, &b_GenLepFromTauRecovered_isPromptHard);
   fChain->SetBranchAddress("nFatjetCA15pruned", &nFatjetCA15pruned, &b_nFatjetCA15pruned);
   fChain->SetBranchAddress("FatjetCA15pruned_pt", FatjetCA15pruned_pt, &b_FatjetCA15pruned_pt);
   fChain->SetBranchAddress("FatjetCA15pruned_eta", FatjetCA15pruned_eta, &b_FatjetCA15pruned_eta);
   fChain->SetBranchAddress("FatjetCA15pruned_phi", FatjetCA15pruned_phi, &b_FatjetCA15pruned_phi);
   fChain->SetBranchAddress("FatjetCA15pruned_mass", FatjetCA15pruned_mass, &b_FatjetCA15pruned_mass);
   fChain->SetBranchAddress("ntrgObjects_hltVBFCaloJetEtaSortedMqq150Deta1p5", &ntrgObjects_hltVBFCaloJetEtaSortedMqq150Deta1p5, &b_ntrgObjects_hltVBFCaloJetEtaSortedMqq150Deta1p5);
   fChain->SetBranchAddress("ntrgObjects_caloMht", &ntrgObjects_caloMht, &b_ntrgObjects_caloMht);
   fChain->SetBranchAddress("trgObjects_caloMht_pt", &trgObjects_caloMht_pt, &b_trgObjects_caloMht_pt);
   fChain->SetBranchAddress("ntrgObjects_hltDoubleCentralJet90", &ntrgObjects_hltDoubleCentralJet90, &b_ntrgObjects_hltDoubleCentralJet90);
   fChain->SetBranchAddress("nGenJet", &nGenJet, &b_nGenJet);
   fChain->SetBranchAddress("GenJet_charge", GenJet_charge, &b_GenJet_charge);
   fChain->SetBranchAddress("GenJet_status", GenJet_status, &b_GenJet_status);
   fChain->SetBranchAddress("GenJet_isPromptHard", GenJet_isPromptHard, &b_GenJet_isPromptHard);
   fChain->SetBranchAddress("GenJet_pdgId", GenJet_pdgId, &b_GenJet_pdgId);
   fChain->SetBranchAddress("GenJet_pt", GenJet_pt, &b_GenJet_pt);
   fChain->SetBranchAddress("GenJet_eta", GenJet_eta, &b_GenJet_eta);
   fChain->SetBranchAddress("GenJet_phi", GenJet_phi, &b_GenJet_phi);
   fChain->SetBranchAddress("GenJet_mass", GenJet_mass, &b_GenJet_mass);
   fChain->SetBranchAddress("GenJet_numBHadrons", GenJet_numBHadrons, &b_GenJet_numBHadrons);
   fChain->SetBranchAddress("GenJet_numCHadrons", GenJet_numCHadrons, &b_GenJet_numCHadrons);
   fChain->SetBranchAddress("GenJet_numBHadronsFromTop", GenJet_numBHadronsFromTop, &b_GenJet_numBHadronsFromTop);
   fChain->SetBranchAddress("GenJet_numCHadronsFromTop", GenJet_numCHadronsFromTop, &b_GenJet_numCHadronsFromTop);
   fChain->SetBranchAddress("GenJet_numBHadronsAfterTop", GenJet_numBHadronsAfterTop, &b_GenJet_numBHadronsAfterTop);
   fChain->SetBranchAddress("GenJet_numCHadronsAfterTop", GenJet_numCHadronsAfterTop, &b_GenJet_numCHadronsAfterTop);
   fChain->SetBranchAddress("GenJet_wNuPt", GenJet_wNuPt, &b_GenJet_wNuPt);
   fChain->SetBranchAddress("GenJet_wNuEta", GenJet_wNuEta, &b_GenJet_wNuEta);
   fChain->SetBranchAddress("GenJet_wNuPhi", GenJet_wNuPhi, &b_GenJet_wNuPhi);
   fChain->SetBranchAddress("GenJet_wNuM", GenJet_wNuM, &b_GenJet_wNuM);
   fChain->SetBranchAddress("ntrgObjects_hltDoublePFJetsC100", &ntrgObjects_hltDoublePFJetsC100, &b_ntrgObjects_hltDoublePFJetsC100);
   fChain->SetBranchAddress("trgObjects_hltDoublePFJetsC100_pt", &trgObjects_hltDoublePFJetsC100_pt, &b_trgObjects_hltDoublePFJetsC100_pt);
   fChain->SetBranchAddress("trgObjects_hltDoublePFJetsC100_eta", &trgObjects_hltDoublePFJetsC100_eta, &b_trgObjects_hltDoublePFJetsC100_eta);
   fChain->SetBranchAddress("trgObjects_hltDoublePFJetsC100_phi", &trgObjects_hltDoublePFJetsC100_phi, &b_trgObjects_hltDoublePFJetsC100_phi);
   fChain->SetBranchAddress("trgObjects_hltDoublePFJetsC100_mass", &trgObjects_hltDoublePFJetsC100_mass, &b_trgObjects_hltDoublePFJetsC100_mass);
   fChain->SetBranchAddress("nSubjetCA15pruned", &nSubjetCA15pruned, &b_nSubjetCA15pruned);
   fChain->SetBranchAddress("SubjetCA15pruned_pt", SubjetCA15pruned_pt, &b_SubjetCA15pruned_pt);
   fChain->SetBranchAddress("SubjetCA15pruned_eta", SubjetCA15pruned_eta, &b_SubjetCA15pruned_eta);
   fChain->SetBranchAddress("SubjetCA15pruned_phi", SubjetCA15pruned_phi, &b_SubjetCA15pruned_phi);
   fChain->SetBranchAddress("SubjetCA15pruned_mass", SubjetCA15pruned_mass, &b_SubjetCA15pruned_mass);
   fChain->SetBranchAddress("SubjetCA15pruned_btag", SubjetCA15pruned_btag, &b_SubjetCA15pruned_btag);
   fChain->SetBranchAddress("SubjetCA15pruned_jetID", SubjetCA15pruned_jetID, &b_SubjetCA15pruned_jetID);
   fChain->SetBranchAddress("SubjetCA15pruned_fromFJ", SubjetCA15pruned_fromFJ, &b_SubjetCA15pruned_fromFJ);
   fChain->SetBranchAddress("ntrgObjects_caloMet", &ntrgObjects_caloMet, &b_ntrgObjects_caloMet);
   fChain->SetBranchAddress("trgObjects_caloMet_pt", trgObjects_caloMet_pt, &b_trgObjects_caloMet_pt);
   fChain->SetBranchAddress("nFatjetCA15ungroomed", &nFatjetCA15ungroomed, &b_nFatjetCA15ungroomed);
   fChain->SetBranchAddress("FatjetCA15ungroomed_pt", FatjetCA15ungroomed_pt, &b_FatjetCA15ungroomed_pt);
   fChain->SetBranchAddress("FatjetCA15ungroomed_eta", FatjetCA15ungroomed_eta, &b_FatjetCA15ungroomed_eta);
   fChain->SetBranchAddress("FatjetCA15ungroomed_phi", FatjetCA15ungroomed_phi, &b_FatjetCA15ungroomed_phi);
   fChain->SetBranchAddress("FatjetCA15ungroomed_mass", FatjetCA15ungroomed_mass, &b_FatjetCA15ungroomed_mass);
   fChain->SetBranchAddress("FatjetCA15ungroomed_tau1", FatjetCA15ungroomed_tau1, &b_FatjetCA15ungroomed_tau1);
   fChain->SetBranchAddress("FatjetCA15ungroomed_tau2", FatjetCA15ungroomed_tau2, &b_FatjetCA15ungroomed_tau2);
   fChain->SetBranchAddress("FatjetCA15ungroomed_tau3", FatjetCA15ungroomed_tau3, &b_FatjetCA15ungroomed_tau3);
   fChain->SetBranchAddress("FatjetCA15ungroomed_bbtag", FatjetCA15ungroomed_bbtag, &b_FatjetCA15ungroomed_bbtag);
   fChain->SetBranchAddress("ntrgObjects_pfMet", &ntrgObjects_pfMet, &b_ntrgObjects_pfMet);
   fChain->SetBranchAddress("trgObjects_pfMet_pt", trgObjects_pfMet_pt, &b_trgObjects_pfMet_pt);
   fChain->SetBranchAddress("ntrgObjects_pfHt", &ntrgObjects_pfHt, &b_ntrgObjects_pfHt);
   fChain->SetBranchAddress("trgObjects_pfHt_pt", &trgObjects_pfHt_pt, &b_trgObjects_pfHt_pt);
   fChain->SetBranchAddress("ndRaddJetsdR08", &ndRaddJetsdR08, &b_ndRaddJetsdR08);
   fChain->SetBranchAddress("dRaddJetsdR08", dRaddJetsdR08, &b_dRaddJetsdR08);
   fChain->SetBranchAddress("nGenBQuarkFromH", &nGenBQuarkFromH, &b_nGenBQuarkFromH);
   fChain->SetBranchAddress("GenBQuarkFromH_pdgId", &GenBQuarkFromH_pdgId, &b_GenBQuarkFromH_pdgId);
   fChain->SetBranchAddress("GenBQuarkFromH_pt", &GenBQuarkFromH_pt, &b_GenBQuarkFromH_pt);
   fChain->SetBranchAddress("GenBQuarkFromH_eta", &GenBQuarkFromH_eta, &b_GenBQuarkFromH_eta);
   fChain->SetBranchAddress("GenBQuarkFromH_phi", &GenBQuarkFromH_phi, &b_GenBQuarkFromH_phi);
   fChain->SetBranchAddress("GenBQuarkFromH_mass", &GenBQuarkFromH_mass, &b_GenBQuarkFromH_mass);
   fChain->SetBranchAddress("GenBQuarkFromH_charge", &GenBQuarkFromH_charge, &b_GenBQuarkFromH_charge);
   fChain->SetBranchAddress("GenBQuarkFromH_status", &GenBQuarkFromH_status, &b_GenBQuarkFromH_status);
   fChain->SetBranchAddress("GenBQuarkFromH_isPromptHard", &GenBQuarkFromH_isPromptHard, &b_GenBQuarkFromH_isPromptHard);
   fChain->SetBranchAddress("ntrgObjects_hltDoubleJet65", &ntrgObjects_hltDoubleJet65, &b_ntrgObjects_hltDoubleJet65);
   fChain->SetBranchAddress("nFatjetCA15trimmed", &nFatjetCA15trimmed, &b_nFatjetCA15trimmed);
   fChain->SetBranchAddress("FatjetCA15trimmed_pt", FatjetCA15trimmed_pt, &b_FatjetCA15trimmed_pt);
   fChain->SetBranchAddress("FatjetCA15trimmed_eta", FatjetCA15trimmed_eta, &b_FatjetCA15trimmed_eta);
   fChain->SetBranchAddress("FatjetCA15trimmed_phi", FatjetCA15trimmed_phi, &b_FatjetCA15trimmed_phi);
   fChain->SetBranchAddress("FatjetCA15trimmed_mass", FatjetCA15trimmed_mass, &b_FatjetCA15trimmed_mass);
   fChain->SetBranchAddress("nGenHiggsSisters", &nGenHiggsSisters, &b_nGenHiggsSisters);
   fChain->SetBranchAddress("GenHiggsSisters_pdgId", &GenHiggsSisters_pdgId, &b_GenHiggsSisters_pdgId);
   fChain->SetBranchAddress("GenHiggsSisters_pt", &GenHiggsSisters_pt, &b_GenHiggsSisters_pt);
   fChain->SetBranchAddress("GenHiggsSisters_eta", &GenHiggsSisters_eta, &b_GenHiggsSisters_eta);
   fChain->SetBranchAddress("GenHiggsSisters_phi", &GenHiggsSisters_phi, &b_GenHiggsSisters_phi);
   fChain->SetBranchAddress("GenHiggsSisters_mass", &GenHiggsSisters_mass, &b_GenHiggsSisters_mass);
   fChain->SetBranchAddress("GenHiggsSisters_charge", &GenHiggsSisters_charge, &b_GenHiggsSisters_charge);
   fChain->SetBranchAddress("GenHiggsSisters_status", &GenHiggsSisters_status, &b_GenHiggsSisters_status);
   fChain->SetBranchAddress("GenHiggsSisters_isPromptHard", &GenHiggsSisters_isPromptHard, &b_GenHiggsSisters_isPromptHard);
   fChain->SetBranchAddress("ntrgObjects_hltBTagCaloCSVp026DoubleWithMatching", &ntrgObjects_hltBTagCaloCSVp026DoubleWithMatching, &b_ntrgObjects_hltBTagCaloCSVp026DoubleWithMatching);
   fChain->SetBranchAddress("trgObjects_hltBTagCaloCSVp026DoubleWithMatching_pt", &trgObjects_hltBTagCaloCSVp026DoubleWithMatching_pt, &b_trgObjects_hltBTagCaloCSVp026DoubleWithMatching_pt);
   fChain->SetBranchAddress("trgObjects_hltBTagCaloCSVp026DoubleWithMatching_eta", &trgObjects_hltBTagCaloCSVp026DoubleWithMatching_eta, &b_trgObjects_hltBTagCaloCSVp026DoubleWithMatching_eta);
   fChain->SetBranchAddress("trgObjects_hltBTagCaloCSVp026DoubleWithMatching_phi", &trgObjects_hltBTagCaloCSVp026DoubleWithMatching_phi, &b_trgObjects_hltBTagCaloCSVp026DoubleWithMatching_phi);
   fChain->SetBranchAddress("trgObjects_hltBTagCaloCSVp026DoubleWithMatching_mass", &trgObjects_hltBTagCaloCSVp026DoubleWithMatching_mass, &b_trgObjects_hltBTagCaloCSVp026DoubleWithMatching_mass);
   fChain->SetBranchAddress("naLeptons", &naLeptons, &b_naLeptons);
   fChain->SetBranchAddress("aLeptons_charge", aLeptons_charge, &b_aLeptons_charge);
   fChain->SetBranchAddress("aLeptons_tightId", aLeptons_tightId, &b_aLeptons_tightId);
   fChain->SetBranchAddress("aLeptons_eleCutIdCSA14_25ns_v1", aLeptons_eleCutIdCSA14_25ns_v1, &b_aLeptons_eleCutIdCSA14_25ns_v1);
   fChain->SetBranchAddress("aLeptons_eleCutIdCSA14_50ns_v1", aLeptons_eleCutIdCSA14_50ns_v1, &b_aLeptons_eleCutIdCSA14_50ns_v1);
   fChain->SetBranchAddress("aLeptons_eleCutIdSpring15_25ns_v1", aLeptons_eleCutIdSpring15_25ns_v1, &b_aLeptons_eleCutIdSpring15_25ns_v1);
   fChain->SetBranchAddress("aLeptons_dxy", aLeptons_dxy, &b_aLeptons_dxy);
   fChain->SetBranchAddress("aLeptons_dz", aLeptons_dz, &b_aLeptons_dz);
   fChain->SetBranchAddress("aLeptons_edxy", aLeptons_edxy, &b_aLeptons_edxy);
   fChain->SetBranchAddress("aLeptons_edz", aLeptons_edz, &b_aLeptons_edz);
   fChain->SetBranchAddress("aLeptons_ip3d", aLeptons_ip3d, &b_aLeptons_ip3d);
   fChain->SetBranchAddress("aLeptons_sip3d", aLeptons_sip3d, &b_aLeptons_sip3d);
   fChain->SetBranchAddress("aLeptons_convVeto", aLeptons_convVeto, &b_aLeptons_convVeto);
   fChain->SetBranchAddress("aLeptons_lostHits", aLeptons_lostHits, &b_aLeptons_lostHits);
   fChain->SetBranchAddress("aLeptons_relIso03", aLeptons_relIso03, &b_aLeptons_relIso03);
   fChain->SetBranchAddress("aLeptons_relIso04", aLeptons_relIso04, &b_aLeptons_relIso04);
   fChain->SetBranchAddress("aLeptons_miniRelIso", aLeptons_miniRelIso, &b_aLeptons_miniRelIso);
   fChain->SetBranchAddress("aLeptons_relIsoAn04", aLeptons_relIsoAn04, &b_aLeptons_relIsoAn04);
   fChain->SetBranchAddress("aLeptons_tightCharge", aLeptons_tightCharge, &b_aLeptons_tightCharge);
   fChain->SetBranchAddress("aLeptons_mcMatchId", aLeptons_mcMatchId, &b_aLeptons_mcMatchId);
   fChain->SetBranchAddress("aLeptons_mcMatchAny", aLeptons_mcMatchAny, &b_aLeptons_mcMatchAny);
   fChain->SetBranchAddress("aLeptons_mcMatchTau", aLeptons_mcMatchTau, &b_aLeptons_mcMatchTau);
   fChain->SetBranchAddress("aLeptons_mcPt", aLeptons_mcPt, &b_aLeptons_mcPt);
   fChain->SetBranchAddress("aLeptons_mediumMuonId", aLeptons_mediumMuonId, &b_aLeptons_mediumMuonId);
   fChain->SetBranchAddress("aLeptons_pdgId", aLeptons_pdgId, &b_aLeptons_pdgId);
   fChain->SetBranchAddress("aLeptons_pt", aLeptons_pt, &b_aLeptons_pt);
   fChain->SetBranchAddress("aLeptons_eta", aLeptons_eta, &b_aLeptons_eta);
   fChain->SetBranchAddress("aLeptons_phi", aLeptons_phi, &b_aLeptons_phi);
   fChain->SetBranchAddress("aLeptons_mass", aLeptons_mass, &b_aLeptons_mass);
   fChain->SetBranchAddress("aLeptons_looseIdSusy", aLeptons_looseIdSusy, &b_aLeptons_looseIdSusy);
   fChain->SetBranchAddress("aLeptons_looseIdPOG", aLeptons_looseIdPOG, &b_aLeptons_looseIdPOG);
   fChain->SetBranchAddress("aLeptons_chargedHadRelIso03", aLeptons_chargedHadRelIso03, &b_aLeptons_chargedHadRelIso03);
   fChain->SetBranchAddress("aLeptons_chargedHadRelIso04", aLeptons_chargedHadRelIso04, &b_aLeptons_chargedHadRelIso04);
   fChain->SetBranchAddress("aLeptons_eleSieie", aLeptons_eleSieie, &b_aLeptons_eleSieie);
   fChain->SetBranchAddress("aLeptons_eleDEta", aLeptons_eleDEta, &b_aLeptons_eleDEta);
   fChain->SetBranchAddress("aLeptons_eleDPhi", aLeptons_eleDPhi, &b_aLeptons_eleDPhi);
   fChain->SetBranchAddress("aLeptons_eleHoE", aLeptons_eleHoE, &b_aLeptons_eleHoE);
   fChain->SetBranchAddress("aLeptons_eleMissingHits", aLeptons_eleMissingHits, &b_aLeptons_eleMissingHits);
   fChain->SetBranchAddress("aLeptons_eleChi2", aLeptons_eleChi2, &b_aLeptons_eleChi2);
   fChain->SetBranchAddress("aLeptons_convVetoFull", aLeptons_convVetoFull, &b_aLeptons_convVetoFull);
   fChain->SetBranchAddress("aLeptons_eleMVArawSpring15Trig", aLeptons_eleMVArawSpring15Trig, &b_aLeptons_eleMVArawSpring15Trig);
   fChain->SetBranchAddress("aLeptons_eleMVAIdSpring15Trig", aLeptons_eleMVAIdSpring15Trig, &b_aLeptons_eleMVAIdSpring15Trig);
   fChain->SetBranchAddress("aLeptons_eleMVArawSpring15NonTrig", aLeptons_eleMVArawSpring15NonTrig, &b_aLeptons_eleMVArawSpring15NonTrig);
   fChain->SetBranchAddress("aLeptons_eleMVAIdSpring15NonTrig", aLeptons_eleMVAIdSpring15NonTrig, &b_aLeptons_eleMVAIdSpring15NonTrig);
   fChain->SetBranchAddress("aLeptons_nStations", aLeptons_nStations, &b_aLeptons_nStations);
   fChain->SetBranchAddress("aLeptons_trkKink", aLeptons_trkKink, &b_aLeptons_trkKink);
   fChain->SetBranchAddress("aLeptons_segmentCompatibility", aLeptons_segmentCompatibility, &b_aLeptons_segmentCompatibility);
   fChain->SetBranchAddress("aLeptons_caloCompatibility", aLeptons_caloCompatibility, &b_aLeptons_caloCompatibility);
   fChain->SetBranchAddress("aLeptons_globalTrackChi2", aLeptons_globalTrackChi2, &b_aLeptons_globalTrackChi2);
   fChain->SetBranchAddress("aLeptons_nChamberHits", aLeptons_nChamberHits, &b_aLeptons_nChamberHits);
   fChain->SetBranchAddress("aLeptons_isPFMuon", aLeptons_isPFMuon, &b_aLeptons_isPFMuon);
   fChain->SetBranchAddress("aLeptons_isGlobalMuon", aLeptons_isGlobalMuon, &b_aLeptons_isGlobalMuon);
   fChain->SetBranchAddress("aLeptons_isTrackerMuon", aLeptons_isTrackerMuon, &b_aLeptons_isTrackerMuon);
   fChain->SetBranchAddress("aLeptons_pixelHits", aLeptons_pixelHits, &b_aLeptons_pixelHits);
   fChain->SetBranchAddress("aLeptons_trackerLayers", aLeptons_trackerLayers, &b_aLeptons_trackerLayers);
   fChain->SetBranchAddress("aLeptons_pixelLayers", aLeptons_pixelLayers, &b_aLeptons_pixelLayers);
   fChain->SetBranchAddress("aLeptons_mvaTTH", aLeptons_mvaTTH, &b_aLeptons_mvaTTH);
   fChain->SetBranchAddress("aLeptons_jetOverlapIdx", aLeptons_jetOverlapIdx, &b_aLeptons_jetOverlapIdx);
   fChain->SetBranchAddress("aLeptons_jetPtRatio", aLeptons_jetPtRatio, &b_aLeptons_jetPtRatio);
   fChain->SetBranchAddress("aLeptons_jetBTagCSV", aLeptons_jetBTagCSV, &b_aLeptons_jetBTagCSV);
   fChain->SetBranchAddress("aLeptons_jetDR", aLeptons_jetDR, &b_aLeptons_jetDR);
   fChain->SetBranchAddress("aLeptons_mvaTTHjetPtRatio", aLeptons_mvaTTHjetPtRatio, &b_aLeptons_mvaTTHjetPtRatio);
   fChain->SetBranchAddress("aLeptons_mvaTTHjetBTagCSV", aLeptons_mvaTTHjetBTagCSV, &b_aLeptons_mvaTTHjetBTagCSV);
   fChain->SetBranchAddress("aLeptons_mvaTTHjetDR", aLeptons_mvaTTHjetDR, &b_aLeptons_mvaTTHjetDR);
   fChain->SetBranchAddress("aLeptons_pfRelIso03", aLeptons_pfRelIso03, &b_aLeptons_pfRelIso03);
   fChain->SetBranchAddress("aLeptons_pfRelIso04", aLeptons_pfRelIso04, &b_aLeptons_pfRelIso04);
   fChain->SetBranchAddress("aLeptons_etaSc", aLeptons_etaSc, &b_aLeptons_etaSc);
   fChain->SetBranchAddress("aLeptons_eleExpMissingInnerHits", aLeptons_eleExpMissingInnerHits, &b_aLeptons_eleExpMissingInnerHits);
   fChain->SetBranchAddress("aLeptons_eleooEmooP", aLeptons_eleooEmooP, &b_aLeptons_eleooEmooP);
   fChain->SetBranchAddress("aLeptons_dr03TkSumPt", aLeptons_dr03TkSumPt, &b_aLeptons_dr03TkSumPt);
   fChain->SetBranchAddress("aLeptons_eleEcalClusterIso", aLeptons_eleEcalClusterIso, &b_aLeptons_eleEcalClusterIso);
   fChain->SetBranchAddress("aLeptons_eleHcalClusterIso", aLeptons_eleHcalClusterIso, &b_aLeptons_eleHcalClusterIso);
   fChain->SetBranchAddress("aLeptons_miniIsoCharged", aLeptons_miniIsoCharged, &b_aLeptons_miniIsoCharged);
   fChain->SetBranchAddress("aLeptons_miniIsoNeutral", aLeptons_miniIsoNeutral, &b_aLeptons_miniIsoNeutral);
   fChain->SetBranchAddress("aLeptons_mvaTTHjetPtRel", aLeptons_mvaTTHjetPtRel, &b_aLeptons_mvaTTHjetPtRel);
   fChain->SetBranchAddress("aLeptons_mvaTTHjetNDauChargedMVASel", aLeptons_mvaTTHjetNDauChargedMVASel, &b_aLeptons_mvaTTHjetNDauChargedMVASel);
   fChain->SetBranchAddress("aLeptons_uncalibratedPt", aLeptons_uncalibratedPt, &b_aLeptons_uncalibratedPt);
   fChain->SetBranchAddress("aLeptons_SF_IsoLoose", aLeptons_SF_IsoLoose, &b_aLeptons_SF_IsoLoose);
   fChain->SetBranchAddress("aLeptons_SFerr_IsoLoose", aLeptons_SFerr_IsoLoose, &b_aLeptons_SFerr_IsoLoose);
   fChain->SetBranchAddress("aLeptons_SF_IsoTight", aLeptons_SF_IsoTight, &b_aLeptons_SF_IsoTight);
   fChain->SetBranchAddress("aLeptons_SFerr_IsoTight", aLeptons_SFerr_IsoTight, &b_aLeptons_SFerr_IsoTight);
   fChain->SetBranchAddress("aLeptons_SF_IdCutLoose", aLeptons_SF_IdCutLoose, &b_aLeptons_SF_IdCutLoose);
   fChain->SetBranchAddress("aLeptons_SFerr_IdCutLoose", aLeptons_SFerr_IdCutLoose, &b_aLeptons_SFerr_IdCutLoose);
   fChain->SetBranchAddress("aLeptons_SF_IdCutTight", aLeptons_SF_IdCutTight, &b_aLeptons_SF_IdCutTight);
   fChain->SetBranchAddress("aLeptons_SFerr_IdCutTight", aLeptons_SFerr_IdCutTight, &b_aLeptons_SFerr_IdCutTight);
   fChain->SetBranchAddress("aLeptons_SF_IdMVALoose", aLeptons_SF_IdMVALoose, &b_aLeptons_SF_IdMVALoose);
   fChain->SetBranchAddress("aLeptons_SFerr_IdMVALoose", aLeptons_SFerr_IdMVALoose, &b_aLeptons_SFerr_IdMVALoose);
   fChain->SetBranchAddress("aLeptons_SF_IdMVATight", aLeptons_SF_IdMVATight, &b_aLeptons_SF_IdMVATight);
   fChain->SetBranchAddress("aLeptons_SFerr_IdMVATight", aLeptons_SFerr_IdMVATight, &b_aLeptons_SFerr_IdMVATight);
   fChain->SetBranchAddress("aLeptons_SF_HLT_RunD4p3", aLeptons_SF_HLT_RunD4p3, &b_aLeptons_SF_HLT_RunD4p3);
   fChain->SetBranchAddress("aLeptons_SFerr_HLT_RunD4p3", aLeptons_SFerr_HLT_RunD4p3, &b_aLeptons_SFerr_HLT_RunD4p3);
   fChain->SetBranchAddress("aLeptons_SF_HLT_RunD4p2", aLeptons_SF_HLT_RunD4p2, &b_aLeptons_SF_HLT_RunD4p2);
   fChain->SetBranchAddress("aLeptons_SFerr_HLT_RunD4p2", aLeptons_SFerr_HLT_RunD4p2, &b_aLeptons_SFerr_HLT_RunD4p2);
   fChain->SetBranchAddress("aLeptons_SF_HLT_RunC", aLeptons_SF_HLT_RunC, &b_aLeptons_SF_HLT_RunC);
   fChain->SetBranchAddress("aLeptons_SFerr_HLT_RunC", aLeptons_SFerr_HLT_RunC, &b_aLeptons_SFerr_HLT_RunC);
   fChain->SetBranchAddress("aLeptons_Eff_HLT_RunD4p3", aLeptons_Eff_HLT_RunD4p3, &b_aLeptons_Eff_HLT_RunD4p3);
   fChain->SetBranchAddress("aLeptons_Efferr_HLT_RunD4p3", aLeptons_Efferr_HLT_RunD4p3, &b_aLeptons_Efferr_HLT_RunD4p3);
   fChain->SetBranchAddress("aLeptons_Eff_HLT_RunD4p2", aLeptons_Eff_HLT_RunD4p2, &b_aLeptons_Eff_HLT_RunD4p2);
   fChain->SetBranchAddress("aLeptons_Efferr_HLT_RunD4p2", aLeptons_Efferr_HLT_RunD4p2, &b_aLeptons_Efferr_HLT_RunD4p2);
   fChain->SetBranchAddress("aLeptons_Eff_HLT_RunC", aLeptons_Eff_HLT_RunC, &b_aLeptons_Eff_HLT_RunC);
   fChain->SetBranchAddress("aLeptons_Efferr_HLT_RunC", aLeptons_Efferr_HLT_RunC, &b_aLeptons_Efferr_HLT_RunC);
   fChain->SetBranchAddress("ntrgObjects_hltPFQuadJetLooseID15", &ntrgObjects_hltPFQuadJetLooseID15, &b_ntrgObjects_hltPFQuadJetLooseID15);
   fChain->SetBranchAddress("ntrgObjects_hltQuadPFCentralJetLooseID45", &ntrgObjects_hltQuadPFCentralJetLooseID45, &b_ntrgObjects_hltQuadPFCentralJetLooseID45);
   fChain->SetBranchAddress("ntrgObjects_hltBTagCaloCSVp067Single", &ntrgObjects_hltBTagCaloCSVp067Single, &b_ntrgObjects_hltBTagCaloCSVp067Single);
   fChain->SetBranchAddress("ntrgObjects_hltVBFPFJetCSVSortedMqq200Detaqq1p2", &ntrgObjects_hltVBFPFJetCSVSortedMqq200Detaqq1p2, &b_ntrgObjects_hltVBFPFJetCSVSortedMqq200Detaqq1p2);
   fChain->SetBranchAddress("nhjidxaddJetsdR08", &nhjidxaddJetsdR08, &b_nhjidxaddJetsdR08);
   fChain->SetBranchAddress("hjidxaddJetsdR08", hjidxaddJetsdR08, &b_hjidxaddJetsdR08);
   fChain->SetBranchAddress("ntrgObjects_hltMHTNoPU90", &ntrgObjects_hltMHTNoPU90, &b_ntrgObjects_hltMHTNoPU90);
   fChain->SetBranchAddress("nFatjetAK08ungroomed", &nFatjetAK08ungroomed, &b_nFatjetAK08ungroomed);
   fChain->SetBranchAddress("FatjetAK08ungroomed_pt", FatjetAK08ungroomed_pt, &b_FatjetAK08ungroomed_pt);
   fChain->SetBranchAddress("FatjetAK08ungroomed_eta", FatjetAK08ungroomed_eta, &b_FatjetAK08ungroomed_eta);
   fChain->SetBranchAddress("FatjetAK08ungroomed_phi", FatjetAK08ungroomed_phi, &b_FatjetAK08ungroomed_phi);
   fChain->SetBranchAddress("FatjetAK08ungroomed_mass", FatjetAK08ungroomed_mass, &b_FatjetAK08ungroomed_mass);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau1", FatjetAK08ungroomed_tau1, &b_FatjetAK08ungroomed_tau1);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau2", FatjetAK08ungroomed_tau2, &b_FatjetAK08ungroomed_tau2);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau3", FatjetAK08ungroomed_tau3, &b_FatjetAK08ungroomed_tau3);
   fChain->SetBranchAddress("FatjetAK08ungroomed_msoftdrop", FatjetAK08ungroomed_msoftdrop, &b_FatjetAK08ungroomed_msoftdrop);
   fChain->SetBranchAddress("FatjetAK08ungroomed_mpruned", FatjetAK08ungroomed_mpruned, &b_FatjetAK08ungroomed_mpruned);
   fChain->SetBranchAddress("FatjetAK08ungroomed_mprunedcorr", FatjetAK08ungroomed_mprunedcorr, &b_FatjetAK08ungroomed_mprunedcorr);
   fChain->SetBranchAddress("FatjetAK08ungroomed_JEC_L2L3", FatjetAK08ungroomed_JEC_L2L3, &b_FatjetAK08ungroomed_JEC_L2L3);
   fChain->SetBranchAddress("FatjetAK08ungroomed_JEC_L1L2L3", FatjetAK08ungroomed_JEC_L1L2L3, &b_FatjetAK08ungroomed_JEC_L1L2L3);
   fChain->SetBranchAddress("FatjetAK08ungroomed_JEC_L2L3Unc", FatjetAK08ungroomed_JEC_L2L3Unc, &b_FatjetAK08ungroomed_JEC_L2L3Unc);
   fChain->SetBranchAddress("FatjetAK08ungroomed_JEC_L1L2L3Unc", FatjetAK08ungroomed_JEC_L1L2L3Unc, &b_FatjetAK08ungroomed_JEC_L1L2L3Unc);
   fChain->SetBranchAddress("FatjetAK08ungroomed_bbtag", FatjetAK08ungroomed_bbtag, &b_FatjetAK08ungroomed_bbtag);
   fChain->SetBranchAddress("FatjetAK08ungroomed_id_Tight", FatjetAK08ungroomed_id_Tight, &b_FatjetAK08ungroomed_id_Tight);
   fChain->SetBranchAddress("FatjetAK08ungroomed_numberOfDaughters", FatjetAK08ungroomed_numberOfDaughters, &b_FatjetAK08ungroomed_numberOfDaughters);
   fChain->SetBranchAddress("FatjetAK08ungroomed_neutralEmEnergyFraction", FatjetAK08ungroomed_neutralEmEnergyFraction, &b_FatjetAK08ungroomed_neutralEmEnergyFraction);
   fChain->SetBranchAddress("FatjetAK08ungroomed_neutralHadronEnergyFraction", FatjetAK08ungroomed_neutralHadronEnergyFraction, &b_FatjetAK08ungroomed_neutralHadronEnergyFraction);
   fChain->SetBranchAddress("FatjetAK08ungroomed_muonEnergyFraction", FatjetAK08ungroomed_muonEnergyFraction, &b_FatjetAK08ungroomed_muonEnergyFraction);
   fChain->SetBranchAddress("FatjetAK08ungroomed_chargedEmEnergyFraction", FatjetAK08ungroomed_chargedEmEnergyFraction, &b_FatjetAK08ungroomed_chargedEmEnergyFraction);
   fChain->SetBranchAddress("FatjetAK08ungroomed_chargedHadronEnergyFraction", FatjetAK08ungroomed_chargedHadronEnergyFraction, &b_FatjetAK08ungroomed_chargedHadronEnergyFraction);
   fChain->SetBranchAddress("FatjetAK08ungroomed_chargedMultiplicity", FatjetAK08ungroomed_chargedMultiplicity, &b_FatjetAK08ungroomed_chargedMultiplicity);
   fChain->SetBranchAddress("FatjetAK08ungroomed_Flavour", FatjetAK08ungroomed_Flavour, &b_FatjetAK08ungroomed_Flavour);
   fChain->SetBranchAddress("FatjetAK08ungroomed_BhadronFlavour", FatjetAK08ungroomed_BhadronFlavour, &b_FatjetAK08ungroomed_BhadronFlavour);
   fChain->SetBranchAddress("FatjetAK08ungroomed_ChadronFlavour", FatjetAK08ungroomed_ChadronFlavour, &b_FatjetAK08ungroomed_ChadronFlavour);
   fChain->SetBranchAddress("FatjetAK08ungroomed_GenPt", FatjetAK08ungroomed_GenPt, &b_FatjetAK08ungroomed_GenPt);
   fChain->SetBranchAddress("FatjetAK08ungroomed_PFLepton_ptrel", FatjetAK08ungroomed_PFLepton_ptrel, &b_FatjetAK08ungroomed_PFLepton_ptrel);
   fChain->SetBranchAddress("FatjetAK08ungroomed_z_ratio", FatjetAK08ungroomed_z_ratio, &b_FatjetAK08ungroomed_z_ratio);
   fChain->SetBranchAddress("FatjetAK08ungroomed_PFLepton_IP2D", FatjetAK08ungroomed_PFLepton_IP2D, &b_FatjetAK08ungroomed_PFLepton_IP2D);
   fChain->SetBranchAddress("FatjetAK08ungroomed_nSL", FatjetAK08ungroomed_nSL, &b_FatjetAK08ungroomed_nSL);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau1_trackEtaRel_0", FatjetAK08ungroomed_tau1_trackEtaRel_0, &b_FatjetAK08ungroomed_tau1_trackEtaRel_0);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau1_trackEtaRel_1", FatjetAK08ungroomed_tau1_trackEtaRel_1, &b_FatjetAK08ungroomed_tau1_trackEtaRel_1);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau1_trackEtaRel_2", FatjetAK08ungroomed_tau1_trackEtaRel_2, &b_FatjetAK08ungroomed_tau1_trackEtaRel_2);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau0_trackEtaRel_0", FatjetAK08ungroomed_tau0_trackEtaRel_0, &b_FatjetAK08ungroomed_tau0_trackEtaRel_0);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau0_trackEtaRel_1", FatjetAK08ungroomed_tau0_trackEtaRel_1, &b_FatjetAK08ungroomed_tau0_trackEtaRel_1);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau0_trackEtaRel_2", FatjetAK08ungroomed_tau0_trackEtaRel_2, &b_FatjetAK08ungroomed_tau0_trackEtaRel_2);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau_vertexMass_0", FatjetAK08ungroomed_tau_vertexMass_0, &b_FatjetAK08ungroomed_tau_vertexMass_0);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau_vertexEnergyRatio_0", FatjetAK08ungroomed_tau_vertexEnergyRatio_0, &b_FatjetAK08ungroomed_tau_vertexEnergyRatio_0);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau_vertexDeltaR_0", FatjetAK08ungroomed_tau_vertexDeltaR_0, &b_FatjetAK08ungroomed_tau_vertexDeltaR_0);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau_flightDistance2dSig_0", FatjetAK08ungroomed_tau_flightDistance2dSig_0, &b_FatjetAK08ungroomed_tau_flightDistance2dSig_0);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau_vertexMass_1", FatjetAK08ungroomed_tau_vertexMass_1, &b_FatjetAK08ungroomed_tau_vertexMass_1);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau_vertexEnergyRatio_1", FatjetAK08ungroomed_tau_vertexEnergyRatio_1, &b_FatjetAK08ungroomed_tau_vertexEnergyRatio_1);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau_flightDistance2dSig_1", FatjetAK08ungroomed_tau_flightDistance2dSig_1, &b_FatjetAK08ungroomed_tau_flightDistance2dSig_1);
   fChain->SetBranchAddress("FatjetAK08ungroomed_nSV", FatjetAK08ungroomed_nSV, &b_FatjetAK08ungroomed_nSV);
   fChain->SetBranchAddress("ntrgObjects_hltPFMHTTightID90", &ntrgObjects_hltPFMHTTightID90, &b_ntrgObjects_hltPFMHTTightID90);
   fChain->SetBranchAddress("ntrgObjects_hltQuadCentralJet45", &ntrgObjects_hltQuadCentralJet45, &b_ntrgObjects_hltQuadCentralJet45);
   fChain->SetBranchAddress("ntrgObjects_hltBTagCaloCSVp022Single", &ntrgObjects_hltBTagCaloCSVp022Single, &b_ntrgObjects_hltBTagCaloCSVp022Single);
   fChain->SetBranchAddress("naJCidx", &naJCidx, &b_naJCidx);
   fChain->SetBranchAddress("aJCidx", aJCidx, &b_aJCidx);
   fChain->SetBranchAddress("nselLeptons", &nselLeptons, &b_nselLeptons);
   fChain->SetBranchAddress("selLeptons_charge", selLeptons_charge, &b_selLeptons_charge);
   fChain->SetBranchAddress("selLeptons_tightId", selLeptons_tightId, &b_selLeptons_tightId);
   fChain->SetBranchAddress("selLeptons_eleCutIdCSA14_25ns_v1", selLeptons_eleCutIdCSA14_25ns_v1, &b_selLeptons_eleCutIdCSA14_25ns_v1);
   fChain->SetBranchAddress("selLeptons_eleCutIdCSA14_50ns_v1", selLeptons_eleCutIdCSA14_50ns_v1, &b_selLeptons_eleCutIdCSA14_50ns_v1);
   fChain->SetBranchAddress("selLeptons_eleCutIdSpring15_25ns_v1", selLeptons_eleCutIdSpring15_25ns_v1, &b_selLeptons_eleCutIdSpring15_25ns_v1);
   fChain->SetBranchAddress("selLeptons_dxy", selLeptons_dxy, &b_selLeptons_dxy);
   fChain->SetBranchAddress("selLeptons_dz", selLeptons_dz, &b_selLeptons_dz);
   fChain->SetBranchAddress("selLeptons_edxy", selLeptons_edxy, &b_selLeptons_edxy);
   fChain->SetBranchAddress("selLeptons_edz", selLeptons_edz, &b_selLeptons_edz);
   fChain->SetBranchAddress("selLeptons_ip3d", selLeptons_ip3d, &b_selLeptons_ip3d);
   fChain->SetBranchAddress("selLeptons_sip3d", selLeptons_sip3d, &b_selLeptons_sip3d);
   fChain->SetBranchAddress("selLeptons_convVeto", selLeptons_convVeto, &b_selLeptons_convVeto);
   fChain->SetBranchAddress("selLeptons_lostHits", selLeptons_lostHits, &b_selLeptons_lostHits);
   fChain->SetBranchAddress("selLeptons_relIso03", selLeptons_relIso03, &b_selLeptons_relIso03);
   fChain->SetBranchAddress("selLeptons_relIso04", selLeptons_relIso04, &b_selLeptons_relIso04);
   fChain->SetBranchAddress("selLeptons_miniRelIso", selLeptons_miniRelIso, &b_selLeptons_miniRelIso);
   fChain->SetBranchAddress("selLeptons_relIsoAn04", selLeptons_relIsoAn04, &b_selLeptons_relIsoAn04);
   fChain->SetBranchAddress("selLeptons_tightCharge", selLeptons_tightCharge, &b_selLeptons_tightCharge);
   fChain->SetBranchAddress("selLeptons_mcMatchId", selLeptons_mcMatchId, &b_selLeptons_mcMatchId);
   fChain->SetBranchAddress("selLeptons_mcMatchAny", selLeptons_mcMatchAny, &b_selLeptons_mcMatchAny);
   fChain->SetBranchAddress("selLeptons_mcMatchTau", selLeptons_mcMatchTau, &b_selLeptons_mcMatchTau);
   fChain->SetBranchAddress("selLeptons_mcPt", selLeptons_mcPt, &b_selLeptons_mcPt);
   fChain->SetBranchAddress("selLeptons_mediumMuonId", selLeptons_mediumMuonId, &b_selLeptons_mediumMuonId);
   fChain->SetBranchAddress("selLeptons_pdgId", selLeptons_pdgId, &b_selLeptons_pdgId);
   fChain->SetBranchAddress("selLeptons_pt", selLeptons_pt, &b_selLeptons_pt);
   fChain->SetBranchAddress("selLeptons_eta", selLeptons_eta, &b_selLeptons_eta);
   fChain->SetBranchAddress("selLeptons_phi", selLeptons_phi, &b_selLeptons_phi);
   fChain->SetBranchAddress("selLeptons_mass", selLeptons_mass, &b_selLeptons_mass);
   fChain->SetBranchAddress("selLeptons_looseIdSusy", selLeptons_looseIdSusy, &b_selLeptons_looseIdSusy);
   fChain->SetBranchAddress("selLeptons_looseIdPOG", selLeptons_looseIdPOG, &b_selLeptons_looseIdPOG);
   fChain->SetBranchAddress("selLeptons_chargedHadRelIso03", selLeptons_chargedHadRelIso03, &b_selLeptons_chargedHadRelIso03);
   fChain->SetBranchAddress("selLeptons_chargedHadRelIso04", selLeptons_chargedHadRelIso04, &b_selLeptons_chargedHadRelIso04);
   fChain->SetBranchAddress("selLeptons_eleSieie", selLeptons_eleSieie, &b_selLeptons_eleSieie);
   fChain->SetBranchAddress("selLeptons_eleDEta", selLeptons_eleDEta, &b_selLeptons_eleDEta);
   fChain->SetBranchAddress("selLeptons_eleDPhi", selLeptons_eleDPhi, &b_selLeptons_eleDPhi);
   fChain->SetBranchAddress("selLeptons_eleHoE", selLeptons_eleHoE, &b_selLeptons_eleHoE);
   fChain->SetBranchAddress("selLeptons_eleMissingHits", selLeptons_eleMissingHits, &b_selLeptons_eleMissingHits);
   fChain->SetBranchAddress("selLeptons_eleChi2", selLeptons_eleChi2, &b_selLeptons_eleChi2);
   fChain->SetBranchAddress("selLeptons_convVetoFull", selLeptons_convVetoFull, &b_selLeptons_convVetoFull);
   fChain->SetBranchAddress("selLeptons_eleMVArawSpring15Trig", selLeptons_eleMVArawSpring15Trig, &b_selLeptons_eleMVArawSpring15Trig);
   fChain->SetBranchAddress("selLeptons_eleMVAIdSpring15Trig", selLeptons_eleMVAIdSpring15Trig, &b_selLeptons_eleMVAIdSpring15Trig);
   fChain->SetBranchAddress("selLeptons_eleMVArawSpring15NonTrig", selLeptons_eleMVArawSpring15NonTrig, &b_selLeptons_eleMVArawSpring15NonTrig);
   fChain->SetBranchAddress("selLeptons_eleMVAIdSpring15NonTrig", selLeptons_eleMVAIdSpring15NonTrig, &b_selLeptons_eleMVAIdSpring15NonTrig);
   fChain->SetBranchAddress("selLeptons_nStations", selLeptons_nStations, &b_selLeptons_nStations);
   fChain->SetBranchAddress("selLeptons_trkKink", selLeptons_trkKink, &b_selLeptons_trkKink);
   fChain->SetBranchAddress("selLeptons_segmentCompatibility", selLeptons_segmentCompatibility, &b_selLeptons_segmentCompatibility);
   fChain->SetBranchAddress("selLeptons_caloCompatibility", selLeptons_caloCompatibility, &b_selLeptons_caloCompatibility);
   fChain->SetBranchAddress("selLeptons_globalTrackChi2", selLeptons_globalTrackChi2, &b_selLeptons_globalTrackChi2);
   fChain->SetBranchAddress("selLeptons_nChamberHits", selLeptons_nChamberHits, &b_selLeptons_nChamberHits);
   fChain->SetBranchAddress("selLeptons_isPFMuon", selLeptons_isPFMuon, &b_selLeptons_isPFMuon);
   fChain->SetBranchAddress("selLeptons_isGlobalMuon", selLeptons_isGlobalMuon, &b_selLeptons_isGlobalMuon);
   fChain->SetBranchAddress("selLeptons_isTrackerMuon", selLeptons_isTrackerMuon, &b_selLeptons_isTrackerMuon);
   fChain->SetBranchAddress("selLeptons_pixelHits", selLeptons_pixelHits, &b_selLeptons_pixelHits);
   fChain->SetBranchAddress("selLeptons_trackerLayers", selLeptons_trackerLayers, &b_selLeptons_trackerLayers);
   fChain->SetBranchAddress("selLeptons_pixelLayers", selLeptons_pixelLayers, &b_selLeptons_pixelLayers);
   fChain->SetBranchAddress("selLeptons_mvaTTH", selLeptons_mvaTTH, &b_selLeptons_mvaTTH);
   fChain->SetBranchAddress("selLeptons_jetOverlapIdx", selLeptons_jetOverlapIdx, &b_selLeptons_jetOverlapIdx);
   fChain->SetBranchAddress("selLeptons_jetPtRatio", selLeptons_jetPtRatio, &b_selLeptons_jetPtRatio);
   fChain->SetBranchAddress("selLeptons_jetBTagCSV", selLeptons_jetBTagCSV, &b_selLeptons_jetBTagCSV);
   fChain->SetBranchAddress("selLeptons_jetDR", selLeptons_jetDR, &b_selLeptons_jetDR);
   fChain->SetBranchAddress("selLeptons_mvaTTHjetPtRatio", selLeptons_mvaTTHjetPtRatio, &b_selLeptons_mvaTTHjetPtRatio);
   fChain->SetBranchAddress("selLeptons_mvaTTHjetBTagCSV", selLeptons_mvaTTHjetBTagCSV, &b_selLeptons_mvaTTHjetBTagCSV);
   fChain->SetBranchAddress("selLeptons_mvaTTHjetDR", selLeptons_mvaTTHjetDR, &b_selLeptons_mvaTTHjetDR);
   fChain->SetBranchAddress("selLeptons_pfRelIso03", selLeptons_pfRelIso03, &b_selLeptons_pfRelIso03);
   fChain->SetBranchAddress("selLeptons_pfRelIso04", selLeptons_pfRelIso04, &b_selLeptons_pfRelIso04);
   fChain->SetBranchAddress("selLeptons_etaSc", selLeptons_etaSc, &b_selLeptons_etaSc);
   fChain->SetBranchAddress("selLeptons_eleExpMissingInnerHits", selLeptons_eleExpMissingInnerHits, &b_selLeptons_eleExpMissingInnerHits);
   fChain->SetBranchAddress("selLeptons_eleooEmooP", selLeptons_eleooEmooP, &b_selLeptons_eleooEmooP);
   fChain->SetBranchAddress("selLeptons_dr03TkSumPt", selLeptons_dr03TkSumPt, &b_selLeptons_dr03TkSumPt);
   fChain->SetBranchAddress("selLeptons_eleEcalClusterIso", selLeptons_eleEcalClusterIso, &b_selLeptons_eleEcalClusterIso);
   fChain->SetBranchAddress("selLeptons_eleHcalClusterIso", selLeptons_eleHcalClusterIso, &b_selLeptons_eleHcalClusterIso);
   fChain->SetBranchAddress("selLeptons_miniIsoCharged", selLeptons_miniIsoCharged, &b_selLeptons_miniIsoCharged);
   fChain->SetBranchAddress("selLeptons_miniIsoNeutral", selLeptons_miniIsoNeutral, &b_selLeptons_miniIsoNeutral);
   fChain->SetBranchAddress("selLeptons_mvaTTHjetPtRel", selLeptons_mvaTTHjetPtRel, &b_selLeptons_mvaTTHjetPtRel);
   fChain->SetBranchAddress("selLeptons_mvaTTHjetNDauChargedMVASel", selLeptons_mvaTTHjetNDauChargedMVASel, &b_selLeptons_mvaTTHjetNDauChargedMVASel);
   fChain->SetBranchAddress("selLeptons_uncalibratedPt", selLeptons_uncalibratedPt, &b_selLeptons_uncalibratedPt);
   fChain->SetBranchAddress("selLeptons_SF_IsoLoose", selLeptons_SF_IsoLoose, &b_selLeptons_SF_IsoLoose);
   fChain->SetBranchAddress("selLeptons_SFerr_IsoLoose", selLeptons_SFerr_IsoLoose, &b_selLeptons_SFerr_IsoLoose);
   fChain->SetBranchAddress("selLeptons_SF_IsoTight", selLeptons_SF_IsoTight, &b_selLeptons_SF_IsoTight);
   fChain->SetBranchAddress("selLeptons_SFerr_IsoTight", selLeptons_SFerr_IsoTight, &b_selLeptons_SFerr_IsoTight);
   fChain->SetBranchAddress("selLeptons_SF_IdCutLoose", selLeptons_SF_IdCutLoose, &b_selLeptons_SF_IdCutLoose);
   fChain->SetBranchAddress("selLeptons_SFerr_IdCutLoose", selLeptons_SFerr_IdCutLoose, &b_selLeptons_SFerr_IdCutLoose);
   fChain->SetBranchAddress("selLeptons_SF_IdCutTight", selLeptons_SF_IdCutTight, &b_selLeptons_SF_IdCutTight);
   fChain->SetBranchAddress("selLeptons_SFerr_IdCutTight", selLeptons_SFerr_IdCutTight, &b_selLeptons_SFerr_IdCutTight);
   fChain->SetBranchAddress("selLeptons_SF_IdMVALoose", selLeptons_SF_IdMVALoose, &b_selLeptons_SF_IdMVALoose);
   fChain->SetBranchAddress("selLeptons_SFerr_IdMVALoose", selLeptons_SFerr_IdMVALoose, &b_selLeptons_SFerr_IdMVALoose);
   fChain->SetBranchAddress("selLeptons_SF_IdMVATight", selLeptons_SF_IdMVATight, &b_selLeptons_SF_IdMVATight);
   fChain->SetBranchAddress("selLeptons_SFerr_IdMVATight", selLeptons_SFerr_IdMVATight, &b_selLeptons_SFerr_IdMVATight);
   fChain->SetBranchAddress("selLeptons_SF_HLT_RunD4p3", selLeptons_SF_HLT_RunD4p3, &b_selLeptons_SF_HLT_RunD4p3);
   fChain->SetBranchAddress("selLeptons_SFerr_HLT_RunD4p3", selLeptons_SFerr_HLT_RunD4p3, &b_selLeptons_SFerr_HLT_RunD4p3);
   fChain->SetBranchAddress("selLeptons_SF_HLT_RunD4p2", selLeptons_SF_HLT_RunD4p2, &b_selLeptons_SF_HLT_RunD4p2);
   fChain->SetBranchAddress("selLeptons_SFerr_HLT_RunD4p2", selLeptons_SFerr_HLT_RunD4p2, &b_selLeptons_SFerr_HLT_RunD4p2);
   fChain->SetBranchAddress("selLeptons_SF_HLT_RunC", selLeptons_SF_HLT_RunC, &b_selLeptons_SF_HLT_RunC);
   fChain->SetBranchAddress("selLeptons_SFerr_HLT_RunC", selLeptons_SFerr_HLT_RunC, &b_selLeptons_SFerr_HLT_RunC);
   fChain->SetBranchAddress("selLeptons_Eff_HLT_RunD4p3", selLeptons_Eff_HLT_RunD4p3, &b_selLeptons_Eff_HLT_RunD4p3);
   fChain->SetBranchAddress("selLeptons_Efferr_HLT_RunD4p3", selLeptons_Efferr_HLT_RunD4p3, &b_selLeptons_Efferr_HLT_RunD4p3);
   fChain->SetBranchAddress("selLeptons_Eff_HLT_RunD4p2", selLeptons_Eff_HLT_RunD4p2, &b_selLeptons_Eff_HLT_RunD4p2);
   fChain->SetBranchAddress("selLeptons_Efferr_HLT_RunD4p2", selLeptons_Efferr_HLT_RunD4p2, &b_selLeptons_Efferr_HLT_RunD4p2);
   fChain->SetBranchAddress("selLeptons_Eff_HLT_RunC", selLeptons_Eff_HLT_RunC, &b_selLeptons_Eff_HLT_RunC);
   fChain->SetBranchAddress("selLeptons_Efferr_HLT_RunC", selLeptons_Efferr_HLT_RunC, &b_selLeptons_Efferr_HLT_RunC);
   fChain->SetBranchAddress("ntrgObjects_hltPFMET90", &ntrgObjects_hltPFMET90, &b_ntrgObjects_hltPFMET90);
   fChain->SetBranchAddress("ntrgObjects_hltQuadJet15", &ntrgObjects_hltQuadJet15, &b_ntrgObjects_hltQuadJet15);
   fChain->SetBranchAddress("nTauGood", &nTauGood, &b_nTauGood);
   fChain->SetBranchAddress("TauGood_charge", TauGood_charge, &b_TauGood_charge);
   fChain->SetBranchAddress("TauGood_decayMode", TauGood_decayMode, &b_TauGood_decayMode);
   fChain->SetBranchAddress("TauGood_idDecayMode", TauGood_idDecayMode, &b_TauGood_idDecayMode);
   fChain->SetBranchAddress("TauGood_idDecayModeNewDMs", TauGood_idDecayModeNewDMs, &b_TauGood_idDecayModeNewDMs);
   fChain->SetBranchAddress("TauGood_dxy", TauGood_dxy, &b_TauGood_dxy);
   fChain->SetBranchAddress("TauGood_dz", TauGood_dz, &b_TauGood_dz);
   fChain->SetBranchAddress("TauGood_idMVArun2", TauGood_idMVArun2, &b_TauGood_idMVArun2);
   fChain->SetBranchAddress("TauGood_rawMVArun2", TauGood_rawMVArun2, &b_TauGood_rawMVArun2);
   fChain->SetBranchAddress("TauGood_idMVArun2dR03", TauGood_idMVArun2dR03, &b_TauGood_idMVArun2dR03);
   fChain->SetBranchAddress("TauGood_rawMVArun2dR03", TauGood_rawMVArun2dR03, &b_TauGood_rawMVArun2dR03);
   fChain->SetBranchAddress("TauGood_idMVArun2NewDM", TauGood_idMVArun2NewDM, &b_TauGood_idMVArun2NewDM);
   fChain->SetBranchAddress("TauGood_rawMVArun2NewDM", TauGood_rawMVArun2NewDM, &b_TauGood_rawMVArun2NewDM);
   fChain->SetBranchAddress("TauGood_idCI3hit", TauGood_idCI3hit, &b_TauGood_idCI3hit);
   fChain->SetBranchAddress("TauGood_idAntiMu", TauGood_idAntiMu, &b_TauGood_idAntiMu);
   fChain->SetBranchAddress("TauGood_idAntiErun2", TauGood_idAntiErun2, &b_TauGood_idAntiErun2);
   fChain->SetBranchAddress("TauGood_isoCI3hit", TauGood_isoCI3hit, &b_TauGood_isoCI3hit);
   fChain->SetBranchAddress("TauGood_photonOutsideSigCone", TauGood_photonOutsideSigCone, &b_TauGood_photonOutsideSigCone);
   fChain->SetBranchAddress("TauGood_mcMatchId", TauGood_mcMatchId, &b_TauGood_mcMatchId);
   fChain->SetBranchAddress("TauGood_pdgId", TauGood_pdgId, &b_TauGood_pdgId);
   fChain->SetBranchAddress("TauGood_pt", TauGood_pt, &b_TauGood_pt);
   fChain->SetBranchAddress("TauGood_eta", TauGood_eta, &b_TauGood_eta);
   fChain->SetBranchAddress("TauGood_phi", TauGood_phi, &b_TauGood_phi);
   fChain->SetBranchAddress("TauGood_mass", TauGood_mass, &b_TauGood_mass);
   fChain->SetBranchAddress("TauGood_idxJetMatch", TauGood_idxJetMatch, &b_TauGood_idxJetMatch);
   fChain->SetBranchAddress("TauGood_genMatchType", TauGood_genMatchType, &b_TauGood_genMatchType);
   fChain->SetBranchAddress("nhJidx", &nhJidx, &b_nhJidx);
   fChain->SetBranchAddress("hJidx", hJidx, &b_hJidx);
   fChain->SetBranchAddress("nGenLepRecovered", &nGenLepRecovered, &b_nGenLepRecovered);
   fChain->SetBranchAddress("GenLepRecovered_pdgId", &GenLepRecovered_pdgId, &b_GenLepRecovered_pdgId);
   fChain->SetBranchAddress("GenLepRecovered_pt", &GenLepRecovered_pt, &b_GenLepRecovered_pt);
   fChain->SetBranchAddress("GenLepRecovered_eta", &GenLepRecovered_eta, &b_GenLepRecovered_eta);
   fChain->SetBranchAddress("GenLepRecovered_phi", &GenLepRecovered_phi, &b_GenLepRecovered_phi);
   fChain->SetBranchAddress("GenLepRecovered_mass", &GenLepRecovered_mass, &b_GenLepRecovered_mass);
   fChain->SetBranchAddress("GenLepRecovered_charge", &GenLepRecovered_charge, &b_GenLepRecovered_charge);
   fChain->SetBranchAddress("GenLepRecovered_status", &GenLepRecovered_status, &b_GenLepRecovered_status);
   fChain->SetBranchAddress("GenLepRecovered_isPromptHard", &GenLepRecovered_isPromptHard, &b_GenLepRecovered_isPromptHard);
   fChain->SetBranchAddress("nFatjetCA15softdropz2b1", &nFatjetCA15softdropz2b1, &b_nFatjetCA15softdropz2b1);
   fChain->SetBranchAddress("FatjetCA15softdropz2b1_pt", FatjetCA15softdropz2b1_pt, &b_FatjetCA15softdropz2b1_pt);
   fChain->SetBranchAddress("FatjetCA15softdropz2b1_eta", FatjetCA15softdropz2b1_eta, &b_FatjetCA15softdropz2b1_eta);
   fChain->SetBranchAddress("FatjetCA15softdropz2b1_phi", FatjetCA15softdropz2b1_phi, &b_FatjetCA15softdropz2b1_phi);
   fChain->SetBranchAddress("FatjetCA15softdropz2b1_mass", FatjetCA15softdropz2b1_mass, &b_FatjetCA15softdropz2b1_mass);
   fChain->SetBranchAddress("FatjetCA15softdropz2b1_tau1", FatjetCA15softdropz2b1_tau1, &b_FatjetCA15softdropz2b1_tau1);
   fChain->SetBranchAddress("FatjetCA15softdropz2b1_tau2", FatjetCA15softdropz2b1_tau2, &b_FatjetCA15softdropz2b1_tau2);
   fChain->SetBranchAddress("FatjetCA15softdropz2b1_tau3", FatjetCA15softdropz2b1_tau3, &b_FatjetCA15softdropz2b1_tau3);
   fChain->SetBranchAddress("nGenStatus2bHad", &nGenStatus2bHad, &b_nGenStatus2bHad);
   fChain->SetBranchAddress("GenStatus2bHad_pdgId", GenStatus2bHad_pdgId, &b_GenStatus2bHad_pdgId);
   fChain->SetBranchAddress("GenStatus2bHad_pt", GenStatus2bHad_pt, &b_GenStatus2bHad_pt);
   fChain->SetBranchAddress("GenStatus2bHad_eta", GenStatus2bHad_eta, &b_GenStatus2bHad_eta);
   fChain->SetBranchAddress("GenStatus2bHad_phi", GenStatus2bHad_phi, &b_GenStatus2bHad_phi);
   fChain->SetBranchAddress("GenStatus2bHad_mass", GenStatus2bHad_mass, &b_GenStatus2bHad_mass);
   fChain->SetBranchAddress("GenStatus2bHad_charge", GenStatus2bHad_charge, &b_GenStatus2bHad_charge);
   fChain->SetBranchAddress("GenStatus2bHad_status", GenStatus2bHad_status, &b_GenStatus2bHad_status);
   fChain->SetBranchAddress("GenStatus2bHad_isPromptHard", GenStatus2bHad_isPromptHard, &b_GenStatus2bHad_isPromptHard);
   fChain->SetBranchAddress("ntrgObjects_hltTripleJet50", &ntrgObjects_hltTripleJet50, &b_ntrgObjects_hltTripleJet50);
   fChain->SetBranchAddress("ntrgObjects_hltVBFPFJetCSVSortedMqq460Detaqq4p1", &ntrgObjects_hltVBFPFJetCSVSortedMqq460Detaqq4p1, &b_ntrgObjects_hltVBFPFJetCSVSortedMqq460Detaqq4p1);
   fChain->SetBranchAddress("nhttCandidates", &nhttCandidates, &b_nhttCandidates);
   fChain->SetBranchAddress("httCandidates_pt", httCandidates_pt, &b_httCandidates_pt);
   fChain->SetBranchAddress("httCandidates_eta", httCandidates_eta, &b_httCandidates_eta);
   fChain->SetBranchAddress("httCandidates_phi", httCandidates_phi, &b_httCandidates_phi);
   fChain->SetBranchAddress("httCandidates_mass", httCandidates_mass, &b_httCandidates_mass);
   fChain->SetBranchAddress("httCandidates_ptcal", httCandidates_ptcal, &b_httCandidates_ptcal);
   fChain->SetBranchAddress("httCandidates_etacal", httCandidates_etacal, &b_httCandidates_etacal);
   fChain->SetBranchAddress("httCandidates_phical", httCandidates_phical, &b_httCandidates_phical);
   fChain->SetBranchAddress("httCandidates_masscal", httCandidates_masscal, &b_httCandidates_masscal);
   fChain->SetBranchAddress("httCandidates_fRec", httCandidates_fRec, &b_httCandidates_fRec);
   fChain->SetBranchAddress("httCandidates_Ropt", httCandidates_Ropt, &b_httCandidates_Ropt);
   fChain->SetBranchAddress("httCandidates_RoptCalc", httCandidates_RoptCalc, &b_httCandidates_RoptCalc);
   fChain->SetBranchAddress("httCandidates_ptForRoptCalc", httCandidates_ptForRoptCalc, &b_httCandidates_ptForRoptCalc);
   fChain->SetBranchAddress("httCandidates_subjetIDPassed", httCandidates_subjetIDPassed, &b_httCandidates_subjetIDPassed);
   fChain->SetBranchAddress("httCandidates_sjW1ptcal", httCandidates_sjW1ptcal, &b_httCandidates_sjW1ptcal);
   fChain->SetBranchAddress("httCandidates_sjW1pt", httCandidates_sjW1pt, &b_httCandidates_sjW1pt);
   fChain->SetBranchAddress("httCandidates_sjW1eta", httCandidates_sjW1eta, &b_httCandidates_sjW1eta);
   fChain->SetBranchAddress("httCandidates_sjW1phi", httCandidates_sjW1phi, &b_httCandidates_sjW1phi);
   fChain->SetBranchAddress("httCandidates_sjW1masscal", httCandidates_sjW1masscal, &b_httCandidates_sjW1masscal);
   fChain->SetBranchAddress("httCandidates_sjW1mass", httCandidates_sjW1mass, &b_httCandidates_sjW1mass);
   fChain->SetBranchAddress("httCandidates_sjW1btag", httCandidates_sjW1btag, &b_httCandidates_sjW1btag);
   fChain->SetBranchAddress("httCandidates_sjW2ptcal", httCandidates_sjW2ptcal, &b_httCandidates_sjW2ptcal);
   fChain->SetBranchAddress("httCandidates_sjW2pt", httCandidates_sjW2pt, &b_httCandidates_sjW2pt);
   fChain->SetBranchAddress("httCandidates_sjW2eta", httCandidates_sjW2eta, &b_httCandidates_sjW2eta);
   fChain->SetBranchAddress("httCandidates_sjW2phi", httCandidates_sjW2phi, &b_httCandidates_sjW2phi);
   fChain->SetBranchAddress("httCandidates_sjW2masscal", httCandidates_sjW2masscal, &b_httCandidates_sjW2masscal);
   fChain->SetBranchAddress("httCandidates_sjW2mass", httCandidates_sjW2mass, &b_httCandidates_sjW2mass);
   fChain->SetBranchAddress("httCandidates_sjW2btag", httCandidates_sjW2btag, &b_httCandidates_sjW2btag);
   fChain->SetBranchAddress("httCandidates_sjNonWptcal", httCandidates_sjNonWptcal, &b_httCandidates_sjNonWptcal);
   fChain->SetBranchAddress("httCandidates_sjNonWpt", httCandidates_sjNonWpt, &b_httCandidates_sjNonWpt);
   fChain->SetBranchAddress("httCandidates_sjNonWeta", httCandidates_sjNonWeta, &b_httCandidates_sjNonWeta);
   fChain->SetBranchAddress("httCandidates_sjNonWphi", httCandidates_sjNonWphi, &b_httCandidates_sjNonWphi);
   fChain->SetBranchAddress("httCandidates_sjNonWmasscal", httCandidates_sjNonWmasscal, &b_httCandidates_sjNonWmasscal);
   fChain->SetBranchAddress("httCandidates_sjNonWmass", httCandidates_sjNonWmass, &b_httCandidates_sjNonWmass);
   fChain->SetBranchAddress("httCandidates_sjNonWbtag", httCandidates_sjNonWbtag, &b_httCandidates_sjNonWbtag);
   fChain->SetBranchAddress("ntrgObjects_hltBTagCaloCSVp087Triple", &ntrgObjects_hltBTagCaloCSVp087Triple, &b_ntrgObjects_hltBTagCaloCSVp087Triple);
   fChain->SetBranchAddress("nGenTaus", &nGenTaus, &b_nGenTaus);
   fChain->SetBranchAddress("GenTaus_pdgId", &GenTaus_pdgId, &b_GenTaus_pdgId);
   fChain->SetBranchAddress("GenTaus_pt", &GenTaus_pt, &b_GenTaus_pt);
   fChain->SetBranchAddress("GenTaus_eta", &GenTaus_eta, &b_GenTaus_eta);
   fChain->SetBranchAddress("GenTaus_phi", &GenTaus_phi, &b_GenTaus_phi);
   fChain->SetBranchAddress("GenTaus_mass", &GenTaus_mass, &b_GenTaus_mass);
   fChain->SetBranchAddress("GenTaus_charge", &GenTaus_charge, &b_GenTaus_charge);
   fChain->SetBranchAddress("GenTaus_status", &GenTaus_status, &b_GenTaus_status);
   fChain->SetBranchAddress("GenTaus_isPromptHard", &GenTaus_isPromptHard, &b_GenTaus_isPromptHard);
   fChain->SetBranchAddress("ntrgObjects_hltMHT70", &ntrgObjects_hltMHT70, &b_ntrgObjects_hltMHT70);
   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("Jet_id", Jet_id, &b_Jet_id);
   fChain->SetBranchAddress("Jet_puId", Jet_puId, &b_Jet_puId);
   fChain->SetBranchAddress("Jet_btagCSV", Jet_btagCSV, &b_Jet_btagCSV);
   fChain->SetBranchAddress("Jet_btagCMVA", Jet_btagCMVA, &b_Jet_btagCMVA);
   fChain->SetBranchAddress("Jet_rawPt", Jet_rawPt, &b_Jet_rawPt);
   fChain->SetBranchAddress("Jet_mcPt", Jet_mcPt, &b_Jet_mcPt);
   fChain->SetBranchAddress("Jet_mcFlavour", Jet_mcFlavour, &b_Jet_mcFlavour);
   fChain->SetBranchAddress("Jet_partonFlavour", Jet_partonFlavour, &b_Jet_partonFlavour);
   fChain->SetBranchAddress("Jet_hadronFlavour", Jet_hadronFlavour, &b_Jet_hadronFlavour);
   fChain->SetBranchAddress("Jet_mcMatchId", Jet_mcMatchId, &b_Jet_mcMatchId);
   fChain->SetBranchAddress("Jet_corr_JECUp", Jet_corr_JECUp, &b_Jet_corr_JECUp);
   fChain->SetBranchAddress("Jet_corr_JECDown", Jet_corr_JECDown, &b_Jet_corr_JECDown);
   fChain->SetBranchAddress("Jet_corr", Jet_corr, &b_Jet_corr);
   fChain->SetBranchAddress("Jet_corr_JERUp", Jet_corr_JERUp, &b_Jet_corr_JERUp);
   fChain->SetBranchAddress("Jet_corr_JERDown", Jet_corr_JERDown, &b_Jet_corr_JERDown);
   fChain->SetBranchAddress("Jet_corr_JER", Jet_corr_JER, &b_Jet_corr_JER);
   fChain->SetBranchAddress("Jet_pt", Jet_pt, &b_Jet_pt);
   fChain->SetBranchAddress("Jet_eta", Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_phi", Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_mass", Jet_mass, &b_Jet_mass);
   fChain->SetBranchAddress("Jet_rawPtAfterSmearing", Jet_rawPtAfterSmearing, &b_Jet_rawPtAfterSmearing);
   fChain->SetBranchAddress("Jet_idxFirstTauMatch", Jet_idxFirstTauMatch, &b_Jet_idxFirstTauMatch);
   fChain->SetBranchAddress("Jet_heppyFlavour", Jet_heppyFlavour, &b_Jet_heppyFlavour);
   fChain->SetBranchAddress("Jet_ctagVsL", Jet_ctagVsL, &b_Jet_ctagVsL);
   fChain->SetBranchAddress("Jet_ctagVsB", Jet_ctagVsB, &b_Jet_ctagVsB);
   fChain->SetBranchAddress("Jet_btagBDT", Jet_btagBDT, &b_Jet_btagBDT);
   fChain->SetBranchAddress("Jet_btagProb", Jet_btagProb, &b_Jet_btagProb);
   fChain->SetBranchAddress("Jet_btagBProb", Jet_btagBProb, &b_Jet_btagBProb);
   fChain->SetBranchAddress("Jet_btagSoftEl", Jet_btagSoftEl, &b_Jet_btagSoftEl);
   fChain->SetBranchAddress("Jet_btagSoftMu", Jet_btagSoftMu, &b_Jet_btagSoftMu);
   fChain->SetBranchAddress("Jet_btagnew", Jet_btagnew, &b_Jet_btagnew);
   fChain->SetBranchAddress("Jet_btagCSVV0", Jet_btagCSVV0, &b_Jet_btagCSVV0);
   fChain->SetBranchAddress("Jet_btagCMVAV2", Jet_btagCMVAV2, &b_Jet_btagCMVAV2);
   fChain->SetBranchAddress("Jet_chHEF", Jet_chHEF, &b_Jet_chHEF);
   fChain->SetBranchAddress("Jet_neHEF", Jet_neHEF, &b_Jet_neHEF);
   fChain->SetBranchAddress("Jet_chEmEF", Jet_chEmEF, &b_Jet_chEmEF);
   fChain->SetBranchAddress("Jet_neEmEF", Jet_neEmEF, &b_Jet_neEmEF);
   fChain->SetBranchAddress("Jet_muEF", Jet_muEF, &b_Jet_muEF);
   fChain->SetBranchAddress("Jet_chMult", Jet_chMult, &b_Jet_chMult);
   fChain->SetBranchAddress("Jet_nhMult", Jet_nhMult, &b_Jet_nhMult);
   fChain->SetBranchAddress("Jet_leadTrackPt", Jet_leadTrackPt, &b_Jet_leadTrackPt);
   fChain->SetBranchAddress("Jet_mcEta", Jet_mcEta, &b_Jet_mcEta);
   fChain->SetBranchAddress("Jet_mcPhi", Jet_mcPhi, &b_Jet_mcPhi);
   fChain->SetBranchAddress("Jet_mcM", Jet_mcM, &b_Jet_mcM);
   fChain->SetBranchAddress("Jet_leptonPdgId", Jet_leptonPdgId, &b_Jet_leptonPdgId);
   fChain->SetBranchAddress("Jet_leptonPt", Jet_leptonPt, &b_Jet_leptonPt);
   fChain->SetBranchAddress("Jet_leptonPtRel", Jet_leptonPtRel, &b_Jet_leptonPtRel);
   fChain->SetBranchAddress("Jet_leptonPtRelInv", Jet_leptonPtRelInv, &b_Jet_leptonPtRelInv);
   fChain->SetBranchAddress("Jet_leptonDeltaR", Jet_leptonDeltaR, &b_Jet_leptonDeltaR);
   fChain->SetBranchAddress("Jet_leptonDeltaPhi", Jet_leptonDeltaPhi, &b_Jet_leptonDeltaPhi);
   fChain->SetBranchAddress("Jet_leptonDeltaEta", Jet_leptonDeltaEta, &b_Jet_leptonDeltaEta);
   fChain->SetBranchAddress("Jet_vtxMass", Jet_vtxMass, &b_Jet_vtxMass);
   fChain->SetBranchAddress("Jet_vtxNtracks", Jet_vtxNtracks, &b_Jet_vtxNtracks);
   fChain->SetBranchAddress("Jet_vtxPt", Jet_vtxPt, &b_Jet_vtxPt);
   fChain->SetBranchAddress("Jet_vtx3DSig", Jet_vtx3DSig, &b_Jet_vtx3DSig);
   fChain->SetBranchAddress("Jet_vtx3DVal", Jet_vtx3DVal, &b_Jet_vtx3DVal);
   fChain->SetBranchAddress("Jet_vtxPosX", Jet_vtxPosX, &b_Jet_vtxPosX);
   fChain->SetBranchAddress("Jet_vtxPosY", Jet_vtxPosY, &b_Jet_vtxPosY);
   fChain->SetBranchAddress("Jet_vtxPosZ", Jet_vtxPosZ, &b_Jet_vtxPosZ);
   fChain->SetBranchAddress("Jet_pullVectorPhi", Jet_pullVectorPhi, &b_Jet_pullVectorPhi);
   fChain->SetBranchAddress("Jet_pullVectorMag", Jet_pullVectorMag, &b_Jet_pullVectorMag);
   fChain->SetBranchAddress("Jet_qgl", Jet_qgl, &b_Jet_qgl);
   fChain->SetBranchAddress("Jet_ptd", Jet_ptd, &b_Jet_ptd);
   fChain->SetBranchAddress("Jet_axis2", Jet_axis2, &b_Jet_axis2);
   fChain->SetBranchAddress("Jet_mult", Jet_mult, &b_Jet_mult);
   fChain->SetBranchAddress("Jet_numberOfDaughters", Jet_numberOfDaughters, &b_Jet_numberOfDaughters);
   fChain->SetBranchAddress("Jet_btagIdx", Jet_btagIdx, &b_Jet_btagIdx);
   fChain->SetBranchAddress("Jet_mcIdx", Jet_mcIdx, &b_Jet_mcIdx);
   fChain->SetBranchAddress("Jet_blike_VBF", Jet_blike_VBF, &b_Jet_blike_VBF);
   fChain->SetBranchAddress("Jet_pt_reg", Jet_pt_reg, &b_Jet_pt_reg);
   fChain->SetBranchAddress("Jet_pt_regVBF", Jet_pt_regVBF, &b_Jet_pt_regVBF);
   fChain->SetBranchAddress("Jet_pt_reg_corrJECUp", Jet_pt_reg_corrJECUp, &b_Jet_pt_reg_corrJECUp);
   fChain->SetBranchAddress("Jet_pt_regVBF_corrJECUp", Jet_pt_regVBF_corrJECUp, &b_Jet_pt_regVBF_corrJECUp);
   fChain->SetBranchAddress("Jet_pt_reg_corrJECDown", Jet_pt_reg_corrJECDown, &b_Jet_pt_reg_corrJECDown);
   fChain->SetBranchAddress("Jet_pt_regVBF_corrJECDown", Jet_pt_regVBF_corrJECDown, &b_Jet_pt_regVBF_corrJECDown);
   fChain->SetBranchAddress("Jet_pt_reg_corrJERUp", Jet_pt_reg_corrJERUp, &b_Jet_pt_reg_corrJERUp);
   fChain->SetBranchAddress("Jet_pt_regVBF_corrJERUp", Jet_pt_regVBF_corrJERUp, &b_Jet_pt_regVBF_corrJERUp);
   fChain->SetBranchAddress("Jet_pt_reg_corrJERDown", Jet_pt_reg_corrJERDown, &b_Jet_pt_reg_corrJERDown);
   fChain->SetBranchAddress("Jet_pt_regVBF_corrJERDown", Jet_pt_regVBF_corrJERDown, &b_Jet_pt_regVBF_corrJERDown);
   fChain->SetBranchAddress("Jet_btagCSVL_SF", Jet_btagCSVL_SF, &b_Jet_btagCSVL_SF);
   fChain->SetBranchAddress("Jet_btagCSVL_SF_up", Jet_btagCSVL_SF_up, &b_Jet_btagCSVL_SF_up);
   fChain->SetBranchAddress("Jet_btagCSVL_SF_down", Jet_btagCSVL_SF_down, &b_Jet_btagCSVL_SF_down);
   fChain->SetBranchAddress("Jet_btagCSVM_SF", Jet_btagCSVM_SF, &b_Jet_btagCSVM_SF);
   fChain->SetBranchAddress("Jet_btagCSVM_SF_up", Jet_btagCSVM_SF_up, &b_Jet_btagCSVM_SF_up);
   fChain->SetBranchAddress("Jet_btagCSVM_SF_down", Jet_btagCSVM_SF_down, &b_Jet_btagCSVM_SF_down);
   fChain->SetBranchAddress("Jet_btagCSVT_SF", Jet_btagCSVT_SF, &b_Jet_btagCSVT_SF);
   fChain->SetBranchAddress("Jet_btagCSVT_SF_up", Jet_btagCSVT_SF_up, &b_Jet_btagCSVT_SF_up);
   fChain->SetBranchAddress("Jet_btagCSVT_SF_down", Jet_btagCSVT_SF_down, &b_Jet_btagCSVT_SF_down);
   fChain->SetBranchAddress("Jet_btagWeightCSV", Jet_btagWeightCSV, &b_Jet_btagWeightCSV);
   fChain->SetBranchAddress("Jet_btagWeightCSV_up_jes", Jet_btagWeightCSV_up_jes, &b_Jet_btagWeightCSV_up_jes);
   fChain->SetBranchAddress("Jet_btagWeightCSV_down_jes", Jet_btagWeightCSV_down_jes, &b_Jet_btagWeightCSV_down_jes);
   fChain->SetBranchAddress("Jet_btagWeightCSV_up_lf", Jet_btagWeightCSV_up_lf, &b_Jet_btagWeightCSV_up_lf);
   fChain->SetBranchAddress("Jet_btagWeightCSV_down_lf", Jet_btagWeightCSV_down_lf, &b_Jet_btagWeightCSV_down_lf);
   fChain->SetBranchAddress("Jet_btagWeightCSV_up_hf", Jet_btagWeightCSV_up_hf, &b_Jet_btagWeightCSV_up_hf);
   fChain->SetBranchAddress("Jet_btagWeightCSV_down_hf", Jet_btagWeightCSV_down_hf, &b_Jet_btagWeightCSV_down_hf);
   fChain->SetBranchAddress("Jet_btagWeightCSV_up_hfstats1", Jet_btagWeightCSV_up_hfstats1, &b_Jet_btagWeightCSV_up_hfstats1);
   fChain->SetBranchAddress("Jet_btagWeightCSV_down_hfstats1", Jet_btagWeightCSV_down_hfstats1, &b_Jet_btagWeightCSV_down_hfstats1);
   fChain->SetBranchAddress("Jet_btagWeightCSV_up_hfstats2", Jet_btagWeightCSV_up_hfstats2, &b_Jet_btagWeightCSV_up_hfstats2);
   fChain->SetBranchAddress("Jet_btagWeightCSV_down_hfstats2", Jet_btagWeightCSV_down_hfstats2, &b_Jet_btagWeightCSV_down_hfstats2);
   fChain->SetBranchAddress("Jet_btagWeightCSV_up_lfstats1", Jet_btagWeightCSV_up_lfstats1, &b_Jet_btagWeightCSV_up_lfstats1);
   fChain->SetBranchAddress("Jet_btagWeightCSV_down_lfstats1", Jet_btagWeightCSV_down_lfstats1, &b_Jet_btagWeightCSV_down_lfstats1);
   fChain->SetBranchAddress("Jet_btagWeightCSV_up_lfstats2", Jet_btagWeightCSV_up_lfstats2, &b_Jet_btagWeightCSV_up_lfstats2);
   fChain->SetBranchAddress("Jet_btagWeightCSV_down_lfstats2", Jet_btagWeightCSV_down_lfstats2, &b_Jet_btagWeightCSV_down_lfstats2);
   fChain->SetBranchAddress("Jet_btagWeightCSV_up_cferr1", Jet_btagWeightCSV_up_cferr1, &b_Jet_btagWeightCSV_up_cferr1);
   fChain->SetBranchAddress("Jet_btagWeightCSV_down_cferr1", Jet_btagWeightCSV_down_cferr1, &b_Jet_btagWeightCSV_down_cferr1);
   fChain->SetBranchAddress("Jet_btagWeightCSV_up_cferr2", Jet_btagWeightCSV_up_cferr2, &b_Jet_btagWeightCSV_up_cferr2);
   fChain->SetBranchAddress("Jet_btagWeightCSV_down_cferr2", Jet_btagWeightCSV_down_cferr2, &b_Jet_btagWeightCSV_down_cferr2);
   fChain->SetBranchAddress("Jet_btagCMVAV2L_SF", Jet_btagCMVAV2L_SF, &b_Jet_btagCMVAV2L_SF);
   fChain->SetBranchAddress("Jet_btagCMVAV2L_SF_up", Jet_btagCMVAV2L_SF_up, &b_Jet_btagCMVAV2L_SF_up);
   fChain->SetBranchAddress("Jet_btagCMVAV2L_SF_down", Jet_btagCMVAV2L_SF_down, &b_Jet_btagCMVAV2L_SF_down);
   fChain->SetBranchAddress("Jet_btagCMVAV2M_SF", Jet_btagCMVAV2M_SF, &b_Jet_btagCMVAV2M_SF);
   fChain->SetBranchAddress("Jet_btagCMVAV2M_SF_up", Jet_btagCMVAV2M_SF_up, &b_Jet_btagCMVAV2M_SF_up);
   fChain->SetBranchAddress("Jet_btagCMVAV2M_SF_down", Jet_btagCMVAV2M_SF_down, &b_Jet_btagCMVAV2M_SF_down);
   fChain->SetBranchAddress("Jet_btagCMVAV2T_SF", Jet_btagCMVAV2T_SF, &b_Jet_btagCMVAV2T_SF);
   fChain->SetBranchAddress("Jet_btagCMVAV2T_SF_up", Jet_btagCMVAV2T_SF_up, &b_Jet_btagCMVAV2T_SF_up);
   fChain->SetBranchAddress("Jet_btagCMVAV2T_SF_down", Jet_btagCMVAV2T_SF_down, &b_Jet_btagCMVAV2T_SF_down);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2", Jet_btagWeightCMVAV2, &b_Jet_btagWeightCMVAV2);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_up_jes", Jet_btagWeightCMVAV2_up_jes, &b_Jet_btagWeightCMVAV2_up_jes);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_down_jes", Jet_btagWeightCMVAV2_down_jes, &b_Jet_btagWeightCMVAV2_down_jes);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_up_lf", Jet_btagWeightCMVAV2_up_lf, &b_Jet_btagWeightCMVAV2_up_lf);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_down_lf", Jet_btagWeightCMVAV2_down_lf, &b_Jet_btagWeightCMVAV2_down_lf);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_up_hf", Jet_btagWeightCMVAV2_up_hf, &b_Jet_btagWeightCMVAV2_up_hf);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_down_hf", Jet_btagWeightCMVAV2_down_hf, &b_Jet_btagWeightCMVAV2_down_hf);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_up_hfstats1", Jet_btagWeightCMVAV2_up_hfstats1, &b_Jet_btagWeightCMVAV2_up_hfstats1);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_down_hfstats1", Jet_btagWeightCMVAV2_down_hfstats1, &b_Jet_btagWeightCMVAV2_down_hfstats1);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_up_hfstats2", Jet_btagWeightCMVAV2_up_hfstats2, &b_Jet_btagWeightCMVAV2_up_hfstats2);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_down_hfstats2", Jet_btagWeightCMVAV2_down_hfstats2, &b_Jet_btagWeightCMVAV2_down_hfstats2);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_up_lfstats1", Jet_btagWeightCMVAV2_up_lfstats1, &b_Jet_btagWeightCMVAV2_up_lfstats1);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_down_lfstats1", Jet_btagWeightCMVAV2_down_lfstats1, &b_Jet_btagWeightCMVAV2_down_lfstats1);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_up_lfstats2", Jet_btagWeightCMVAV2_up_lfstats2, &b_Jet_btagWeightCMVAV2_up_lfstats2);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_down_lfstats2", Jet_btagWeightCMVAV2_down_lfstats2, &b_Jet_btagWeightCMVAV2_down_lfstats2);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_up_cferr1", Jet_btagWeightCMVAV2_up_cferr1, &b_Jet_btagWeightCMVAV2_up_cferr1);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_down_cferr1", Jet_btagWeightCMVAV2_down_cferr1, &b_Jet_btagWeightCMVAV2_down_cferr1);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_up_cferr2", Jet_btagWeightCMVAV2_up_cferr2, &b_Jet_btagWeightCMVAV2_up_cferr2);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_down_cferr2", Jet_btagWeightCMVAV2_down_cferr2, &b_Jet_btagWeightCMVAV2_down_cferr2);
   fChain->SetBranchAddress("nFatjetCA15softdrop", &nFatjetCA15softdrop, &b_nFatjetCA15softdrop);
   fChain->SetBranchAddress("FatjetCA15softdrop_pt", FatjetCA15softdrop_pt, &b_FatjetCA15softdrop_pt);
   fChain->SetBranchAddress("FatjetCA15softdrop_eta", FatjetCA15softdrop_eta, &b_FatjetCA15softdrop_eta);
   fChain->SetBranchAddress("FatjetCA15softdrop_phi", FatjetCA15softdrop_phi, &b_FatjetCA15softdrop_phi);
   fChain->SetBranchAddress("FatjetCA15softdrop_mass", FatjetCA15softdrop_mass, &b_FatjetCA15softdrop_mass);
   fChain->SetBranchAddress("ntrgObjects_hltPFTripleJetLooseID64", &ntrgObjects_hltPFTripleJetLooseID64, &b_ntrgObjects_hltPFTripleJetLooseID64);
   fChain->SetBranchAddress("nLHE_weights_pdf", &nLHE_weights_pdf, &b_nLHE_weights_pdf);
   fChain->SetBranchAddress("LHE_weights_pdf_id", LHE_weights_pdf_id, &b_LHE_weights_pdf_id);
   fChain->SetBranchAddress("LHE_weights_pdf_wgt", LHE_weights_pdf_wgt, &b_LHE_weights_pdf_wgt);
   fChain->SetBranchAddress("nprimaryVertices", &nprimaryVertices, &b_nprimaryVertices);
   fChain->SetBranchAddress("primaryVertices_x", primaryVertices_x, &b_primaryVertices_x);
   fChain->SetBranchAddress("primaryVertices_y", primaryVertices_y, &b_primaryVertices_y);
   fChain->SetBranchAddress("primaryVertices_z", primaryVertices_z, &b_primaryVertices_z);
   fChain->SetBranchAddress("primaryVertices_isFake", primaryVertices_isFake, &b_primaryVertices_isFake);
   fChain->SetBranchAddress("primaryVertices_ndof", primaryVertices_ndof, &b_primaryVertices_ndof);
   fChain->SetBranchAddress("primaryVertices_Rho", primaryVertices_Rho, &b_primaryVertices_Rho);
   fChain->SetBranchAddress("primaryVertices_score", primaryVertices_score, &b_primaryVertices_score);
   fChain->SetBranchAddress("nsoftActivityJets", &nsoftActivityJets, &b_nsoftActivityJets);
   fChain->SetBranchAddress("softActivityJets_pt", softActivityJets_pt, &b_softActivityJets_pt);
   fChain->SetBranchAddress("softActivityJets_eta", softActivityJets_eta, &b_softActivityJets_eta);
   fChain->SetBranchAddress("softActivityJets_phi", softActivityJets_phi, &b_softActivityJets_phi);
   fChain->SetBranchAddress("softActivityJets_mass", softActivityJets_mass, &b_softActivityJets_mass);
   fChain->SetBranchAddress("nFatjetCA15subjetfiltered", &nFatjetCA15subjetfiltered, &b_nFatjetCA15subjetfiltered);
   fChain->SetBranchAddress("FatjetCA15subjetfiltered_pt", FatjetCA15subjetfiltered_pt, &b_FatjetCA15subjetfiltered_pt);
   fChain->SetBranchAddress("FatjetCA15subjetfiltered_eta", FatjetCA15subjetfiltered_eta, &b_FatjetCA15subjetfiltered_eta);
   fChain->SetBranchAddress("FatjetCA15subjetfiltered_phi", FatjetCA15subjetfiltered_phi, &b_FatjetCA15subjetfiltered_phi);
   fChain->SetBranchAddress("FatjetCA15subjetfiltered_mass", FatjetCA15subjetfiltered_mass, &b_FatjetCA15subjetfiltered_mass);
   fChain->SetBranchAddress("nGenWZQuark", &nGenWZQuark, &b_nGenWZQuark);
   fChain->SetBranchAddress("GenWZQuark_pdgId", GenWZQuark_pdgId, &b_GenWZQuark_pdgId);
   fChain->SetBranchAddress("GenWZQuark_pt", GenWZQuark_pt, &b_GenWZQuark_pt);
   fChain->SetBranchAddress("GenWZQuark_eta", GenWZQuark_eta, &b_GenWZQuark_eta);
   fChain->SetBranchAddress("GenWZQuark_phi", GenWZQuark_phi, &b_GenWZQuark_phi);
   fChain->SetBranchAddress("GenWZQuark_mass", GenWZQuark_mass, &b_GenWZQuark_mass);
   fChain->SetBranchAddress("GenWZQuark_charge", GenWZQuark_charge, &b_GenWZQuark_charge);
   fChain->SetBranchAddress("GenWZQuark_status", GenWZQuark_status, &b_GenWZQuark_status);
   fChain->SetBranchAddress("GenWZQuark_isPromptHard", GenWZQuark_isPromptHard, &b_GenWZQuark_isPromptHard);
   fChain->SetBranchAddress("ntrgObjects_hltSingleJet80", &ntrgObjects_hltSingleJet80, &b_ntrgObjects_hltSingleJet80);
   Notify();
}

Bool_t heppyTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void heppyTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t heppyTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef heppyTree_cxx
