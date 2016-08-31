//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Aug 30 09:19:03 2016 by ROOT version 6.02/05
// from TTree tree/PhysicsTools.Heppy.analyzers.core.AutoFillTreeProducer.AutoFillTreeProducer_1
// found on file: singleMuCR_TT_TuneCUETP8M1_13TeV-powheg-pythia8_4631.root
//////////////////////////////////////////////////////////

#ifndef heppySkimTree_h
#define heppySkimTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class heppySkimTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          run;
   UInt_t          lumi;
   ULong64_t       evt;
   Float_t         xsec;
   Float_t         puWeight;
   Float_t         nTrueInt;
   Float_t         genWeight;
   Float_t         nPU0;
   Float_t         nPVs;
   Float_t         rho;
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
   Int_t           HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMET170_NoiseCleaned_v;
   Int_t           HLT_BIT_HLT_PFHT350_PFMET100_v;
   Int_t           HLT_BIT_HLT_PFHT800_v;
   Float_t         met_pt;
   Float_t         met_phi;
   Int_t           nSubjetAK08softdrop;
   Float_t         SubjetAK08softdrop_pt[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_eta[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_phi[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_mass[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_btag[10];   //[nSubjetAK08softdrop]
   Int_t           nvLeptons;
   Int_t           vLeptons_charge[2];   //[nvLeptons]
   Int_t           vLeptons_tightId[2];   //[nvLeptons]
   Int_t           vLeptons_pdgId[2];   //[nvLeptons]
   Float_t         vLeptons_pt[2];   //[nvLeptons]
   Float_t         vLeptons_eta[2];   //[nvLeptons]
   Float_t         vLeptons_phi[2];   //[nvLeptons]
   Float_t         vLeptons_mass[2];   //[nvLeptons]
   Int_t           nGenHiggsBoson;
   Int_t           GenHiggsBoson_pdgId[1];   //[nGenHiggsBoson]
   Float_t         GenHiggsBoson_pt[1];   //[nGenHiggsBoson]
   Float_t         GenHiggsBoson_eta[1];   //[nGenHiggsBoson]
   Float_t         GenHiggsBoson_phi[1];   //[nGenHiggsBoson]
   Float_t         GenHiggsBoson_mass[1];   //[nGenHiggsBoson]
   Float_t         GenHiggsBoson_charge[1];   //[nGenHiggsBoson]
   Int_t           GenHiggsBoson_status[1];   //[nGenHiggsBoson]
   Int_t           naLeptons;
   Float_t         aLeptons_relIso03[8];   //[naLeptons]
   Float_t         aLeptons_relIso04[8];   //[naLeptons]
   Float_t         aLeptons_miniRelIso[8];   //[naLeptons]
   Float_t         aLeptons_relIsoAn04[8];   //[naLeptons]
   Int_t           aLeptons_mediumMuonId[8];   //[naLeptons]
   Float_t         aLeptons_pt[8];   //[naLeptons]
   Float_t         aLeptons_eta[8];   //[naLeptons]
   Float_t         aLeptons_phi[8];   //[naLeptons]
   Float_t         aLeptons_mass[8];   //[naLeptons]
   Float_t         aLeptons_eleSieie[8];   //[naLeptons]
   Float_t         aLeptons_eleDEta[8];   //[naLeptons]
   Float_t         aLeptons_eleDPhi[8];   //[naLeptons]
   Float_t         aLeptons_eleHoE[8];   //[naLeptons]
   Float_t         aLeptons_isPFMuon[8];   //[naLeptons]
   Float_t         aLeptons_isGlobalMuon[8];   //[naLeptons]
   Float_t         aLeptons_isTrackerMuon[8];   //[naLeptons]
   Float_t         aLeptons_etaSc[8];   //[naLeptons]
   Float_t         aLeptons_eleExpMissingInnerHits[8];   //[naLeptons]
   Float_t         aLeptons_eleooEmooP[8];   //[naLeptons]
   Int_t           nFatjetAK08ungroomed;
   Float_t         FatjetAK08ungroomed_pt[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_eta[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_phi[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_mass[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau1[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau2[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_mpruned[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_mprunedcorr[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_bbtag[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_chargedHadronEnergyFraction[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_chargedMultiplicity[5];   //[nFatjetAK08ungroomed]
   Int_t           FatjetAK08ungroomed_Flavour[5];   //[nFatjetAK08ungroomed]
   Int_t           FatjetAK08ungroomed_BhadronFlavour[5];   //[nFatjetAK08ungroomed]
   Int_t           FatjetAK08ungroomed_ChadronFlavour[5];   //[nFatjetAK08ungroomed]
   Int_t           nJet;
   Float_t         Jet_btagCSV[22];   //[nJet]
   Float_t         Jet_btagCMVA[22];   //[nJet]
   Int_t           Jet_partonFlavour[22];   //[nJet]
   Int_t           Jet_hadronFlavour[22];   //[nJet]
   Int_t           Jet_mcMatchId[22];   //[nJet]
   Float_t         Jet_pt[22];   //[nJet]
   Float_t         Jet_eta[22];   //[nJet]
   Float_t         Jet_phi[22];   //[nJet]
   Float_t         Jet_mass[22];   //[nJet]
   Float_t         Jet_btagBDT[22];   //[nJet]
   Float_t         Jet_btagCSVV0[22];   //[nJet]
   Float_t         Jet_btagCMVAV2[22];   //[nJet]

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_xsec;   //!
   TBranch        *b_puWeight;   //!
   TBranch        *b_nTrueInt;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_nPU0;   //!
   TBranch        *b_nPVs;   //!
   TBranch        *b_rho;   //!
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
   TBranch        *b_HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET170_NoiseCleaned_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT350_PFMET100_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT800_v;   //!
   TBranch        *b_met_pt;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_nSubjetAK08softdrop;   //!
   TBranch        *b_SubjetAK08softdrop_pt;   //!
   TBranch        *b_SubjetAK08softdrop_eta;   //!
   TBranch        *b_SubjetAK08softdrop_phi;   //!
   TBranch        *b_SubjetAK08softdrop_mass;   //!
   TBranch        *b_SubjetAK08softdrop_btag;   //!
   TBranch        *b_nvLeptons;   //!
   TBranch        *b_vLeptons_charge;   //!
   TBranch        *b_vLeptons_tightId;   //!
   TBranch        *b_vLeptons_pdgId;   //!
   TBranch        *b_vLeptons_pt;   //!
   TBranch        *b_vLeptons_eta;   //!
   TBranch        *b_vLeptons_phi;   //!
   TBranch        *b_vLeptons_mass;   //!
   TBranch        *b_nGenHiggsBoson;   //!
   TBranch        *b_GenHiggsBoson_pdgId;   //!
   TBranch        *b_GenHiggsBoson_pt;   //!
   TBranch        *b_GenHiggsBoson_eta;   //!
   TBranch        *b_GenHiggsBoson_phi;   //!
   TBranch        *b_GenHiggsBoson_mass;   //!
   TBranch        *b_GenHiggsBoson_charge;   //!
   TBranch        *b_GenHiggsBoson_status;   //!
   TBranch        *b_naLeptons;   //!
   TBranch        *b_aLeptons_relIso03;   //!
   TBranch        *b_aLeptons_relIso04;   //!
   TBranch        *b_aLeptons_miniRelIso;   //!
   TBranch        *b_aLeptons_relIsoAn04;   //!
   TBranch        *b_aLeptons_mediumMuonId;   //!
   TBranch        *b_aLeptons_pt;   //!
   TBranch        *b_aLeptons_eta;   //!
   TBranch        *b_aLeptons_phi;   //!
   TBranch        *b_aLeptons_mass;   //!
   TBranch        *b_aLeptons_eleSieie;   //!
   TBranch        *b_aLeptons_eleDEta;   //!
   TBranch        *b_aLeptons_eleDPhi;   //!
   TBranch        *b_aLeptons_eleHoE;   //!
   TBranch        *b_aLeptons_isPFMuon;   //!
   TBranch        *b_aLeptons_isGlobalMuon;   //!
   TBranch        *b_aLeptons_isTrackerMuon;   //!
   TBranch        *b_aLeptons_etaSc;   //!
   TBranch        *b_aLeptons_eleExpMissingInnerHits;   //!
   TBranch        *b_aLeptons_eleooEmooP;   //!
   TBranch        *b_nFatjetAK08ungroomed;   //!
   TBranch        *b_FatjetAK08ungroomed_pt;   //!
   TBranch        *b_FatjetAK08ungroomed_eta;   //!
   TBranch        *b_FatjetAK08ungroomed_phi;   //!
   TBranch        *b_FatjetAK08ungroomed_mass;   //!
   TBranch        *b_FatjetAK08ungroomed_tau1;   //!
   TBranch        *b_FatjetAK08ungroomed_tau2;   //!
   TBranch        *b_FatjetAK08ungroomed_mpruned;   //!
   TBranch        *b_FatjetAK08ungroomed_mprunedcorr;   //!
   TBranch        *b_FatjetAK08ungroomed_bbtag;   //!
   TBranch        *b_FatjetAK08ungroomed_chargedHadronEnergyFraction;   //!
   TBranch        *b_FatjetAK08ungroomed_chargedMultiplicity;   //!
   TBranch        *b_FatjetAK08ungroomed_Flavour;   //!
   TBranch        *b_FatjetAK08ungroomed_BhadronFlavour;   //!
   TBranch        *b_FatjetAK08ungroomed_ChadronFlavour;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_Jet_btagCSV;   //!
   TBranch        *b_Jet_btagCMVA;   //!
   TBranch        *b_Jet_partonFlavour;   //!
   TBranch        *b_Jet_hadronFlavour;   //!
   TBranch        *b_Jet_mcMatchId;   //!
   TBranch        *b_Jet_pt;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_mass;   //!
   TBranch        *b_Jet_btagBDT;   //!
   TBranch        *b_Jet_btagCSVV0;   //!
   TBranch        *b_Jet_btagCMVAV2;   //!

   heppySkimTree(TTree *tree=0);
   virtual ~heppySkimTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef heppySkimTree_cxx
heppySkimTree::heppySkimTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("singleMuCR_TT_TuneCUETP8M1_13TeV-powheg-pythia8_4631.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("singleMuCR_TT_TuneCUETP8M1_13TeV-powheg-pythia8_4631.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

heppySkimTree::~heppySkimTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t heppySkimTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t heppySkimTree::LoadTree(Long64_t entry)
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

void heppySkimTree::Init(TTree *tree)
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
   fChain->SetBranchAddress("xsec", &xsec, &b_xsec);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);
   fChain->SetBranchAddress("nTrueInt", &nTrueInt, &b_nTrueInt);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("nPU0", &nPU0, &b_nPU0);
   fChain->SetBranchAddress("nPVs", &nPVs, &b_nPVs);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
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
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v", &HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v, &b_HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v", &HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v, &b_HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v", &HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v, &b_HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v", &HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v, &b_HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET170_NoiseCleaned_v", &HLT_BIT_HLT_PFMET170_NoiseCleaned_v, &b_HLT_BIT_HLT_PFMET170_NoiseCleaned_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT350_PFMET100_v", &HLT_BIT_HLT_PFHT350_PFMET100_v, &b_HLT_BIT_HLT_PFHT350_PFMET100_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT800_v", &HLT_BIT_HLT_PFHT800_v, &b_HLT_BIT_HLT_PFHT800_v);
   fChain->SetBranchAddress("met_pt", &met_pt, &b_met_pt);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("nSubjetAK08softdrop", &nSubjetAK08softdrop, &b_nSubjetAK08softdrop);
   fChain->SetBranchAddress("SubjetAK08softdrop_pt", SubjetAK08softdrop_pt, &b_SubjetAK08softdrop_pt);
   fChain->SetBranchAddress("SubjetAK08softdrop_eta", SubjetAK08softdrop_eta, &b_SubjetAK08softdrop_eta);
   fChain->SetBranchAddress("SubjetAK08softdrop_phi", SubjetAK08softdrop_phi, &b_SubjetAK08softdrop_phi);
   fChain->SetBranchAddress("SubjetAK08softdrop_mass", SubjetAK08softdrop_mass, &b_SubjetAK08softdrop_mass);
   fChain->SetBranchAddress("SubjetAK08softdrop_btag", SubjetAK08softdrop_btag, &b_SubjetAK08softdrop_btag);
   fChain->SetBranchAddress("nvLeptons", &nvLeptons, &b_nvLeptons);
   fChain->SetBranchAddress("vLeptons_charge", vLeptons_charge, &b_vLeptons_charge);
   fChain->SetBranchAddress("vLeptons_tightId", vLeptons_tightId, &b_vLeptons_tightId);
   fChain->SetBranchAddress("vLeptons_pdgId", vLeptons_pdgId, &b_vLeptons_pdgId);
   fChain->SetBranchAddress("vLeptons_pt", vLeptons_pt, &b_vLeptons_pt);
   fChain->SetBranchAddress("vLeptons_eta", vLeptons_eta, &b_vLeptons_eta);
   fChain->SetBranchAddress("vLeptons_phi", vLeptons_phi, &b_vLeptons_phi);
   fChain->SetBranchAddress("vLeptons_mass", vLeptons_mass, &b_vLeptons_mass);
   fChain->SetBranchAddress("nGenHiggsBoson", &nGenHiggsBoson, &b_nGenHiggsBoson);
   fChain->SetBranchAddress("GenHiggsBoson_pdgId", &GenHiggsBoson_pdgId, &b_GenHiggsBoson_pdgId);
   fChain->SetBranchAddress("GenHiggsBoson_pt", &GenHiggsBoson_pt, &b_GenHiggsBoson_pt);
   fChain->SetBranchAddress("GenHiggsBoson_eta", &GenHiggsBoson_eta, &b_GenHiggsBoson_eta);
   fChain->SetBranchAddress("GenHiggsBoson_phi", &GenHiggsBoson_phi, &b_GenHiggsBoson_phi);
   fChain->SetBranchAddress("GenHiggsBoson_mass", &GenHiggsBoson_mass, &b_GenHiggsBoson_mass);
   fChain->SetBranchAddress("GenHiggsBoson_charge", &GenHiggsBoson_charge, &b_GenHiggsBoson_charge);
   fChain->SetBranchAddress("GenHiggsBoson_status", &GenHiggsBoson_status, &b_GenHiggsBoson_status);
   fChain->SetBranchAddress("naLeptons", &naLeptons, &b_naLeptons);
   fChain->SetBranchAddress("aLeptons_relIso03", aLeptons_relIso03, &b_aLeptons_relIso03);
   fChain->SetBranchAddress("aLeptons_relIso04", aLeptons_relIso04, &b_aLeptons_relIso04);
   fChain->SetBranchAddress("aLeptons_miniRelIso", aLeptons_miniRelIso, &b_aLeptons_miniRelIso);
   fChain->SetBranchAddress("aLeptons_relIsoAn04", aLeptons_relIsoAn04, &b_aLeptons_relIsoAn04);
   fChain->SetBranchAddress("aLeptons_mediumMuonId", aLeptons_mediumMuonId, &b_aLeptons_mediumMuonId);
   fChain->SetBranchAddress("aLeptons_pt", aLeptons_pt, &b_aLeptons_pt);
   fChain->SetBranchAddress("aLeptons_eta", aLeptons_eta, &b_aLeptons_eta);
   fChain->SetBranchAddress("aLeptons_phi", aLeptons_phi, &b_aLeptons_phi);
   fChain->SetBranchAddress("aLeptons_mass", aLeptons_mass, &b_aLeptons_mass);
   fChain->SetBranchAddress("aLeptons_eleSieie", aLeptons_eleSieie, &b_aLeptons_eleSieie);
   fChain->SetBranchAddress("aLeptons_eleDEta", aLeptons_eleDEta, &b_aLeptons_eleDEta);
   fChain->SetBranchAddress("aLeptons_eleDPhi", aLeptons_eleDPhi, &b_aLeptons_eleDPhi);
   fChain->SetBranchAddress("aLeptons_eleHoE", aLeptons_eleHoE, &b_aLeptons_eleHoE);
   fChain->SetBranchAddress("aLeptons_isPFMuon", aLeptons_isPFMuon, &b_aLeptons_isPFMuon);
   fChain->SetBranchAddress("aLeptons_isGlobalMuon", aLeptons_isGlobalMuon, &b_aLeptons_isGlobalMuon);
   fChain->SetBranchAddress("aLeptons_isTrackerMuon", aLeptons_isTrackerMuon, &b_aLeptons_isTrackerMuon);
   fChain->SetBranchAddress("aLeptons_etaSc", aLeptons_etaSc, &b_aLeptons_etaSc);
   fChain->SetBranchAddress("aLeptons_eleExpMissingInnerHits", aLeptons_eleExpMissingInnerHits, &b_aLeptons_eleExpMissingInnerHits);
   fChain->SetBranchAddress("aLeptons_eleooEmooP", aLeptons_eleooEmooP, &b_aLeptons_eleooEmooP);
   fChain->SetBranchAddress("nFatjetAK08ungroomed", &nFatjetAK08ungroomed, &b_nFatjetAK08ungroomed);
   fChain->SetBranchAddress("FatjetAK08ungroomed_pt", FatjetAK08ungroomed_pt, &b_FatjetAK08ungroomed_pt);
   fChain->SetBranchAddress("FatjetAK08ungroomed_eta", FatjetAK08ungroomed_eta, &b_FatjetAK08ungroomed_eta);
   fChain->SetBranchAddress("FatjetAK08ungroomed_phi", FatjetAK08ungroomed_phi, &b_FatjetAK08ungroomed_phi);
   fChain->SetBranchAddress("FatjetAK08ungroomed_mass", FatjetAK08ungroomed_mass, &b_FatjetAK08ungroomed_mass);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau1", FatjetAK08ungroomed_tau1, &b_FatjetAK08ungroomed_tau1);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau2", FatjetAK08ungroomed_tau2, &b_FatjetAK08ungroomed_tau2);
   fChain->SetBranchAddress("FatjetAK08ungroomed_mpruned", FatjetAK08ungroomed_mpruned, &b_FatjetAK08ungroomed_mpruned);
   fChain->SetBranchAddress("FatjetAK08ungroomed_mprunedcorr", FatjetAK08ungroomed_mprunedcorr, &b_FatjetAK08ungroomed_mprunedcorr);
   fChain->SetBranchAddress("FatjetAK08ungroomed_bbtag", FatjetAK08ungroomed_bbtag, &b_FatjetAK08ungroomed_bbtag);
   fChain->SetBranchAddress("FatjetAK08ungroomed_chargedHadronEnergyFraction", FatjetAK08ungroomed_chargedHadronEnergyFraction, &b_FatjetAK08ungroomed_chargedHadronEnergyFraction);
   fChain->SetBranchAddress("FatjetAK08ungroomed_chargedMultiplicity", FatjetAK08ungroomed_chargedMultiplicity, &b_FatjetAK08ungroomed_chargedMultiplicity);
   fChain->SetBranchAddress("FatjetAK08ungroomed_Flavour", FatjetAK08ungroomed_Flavour, &b_FatjetAK08ungroomed_Flavour);
   fChain->SetBranchAddress("FatjetAK08ungroomed_BhadronFlavour", FatjetAK08ungroomed_BhadronFlavour, &b_FatjetAK08ungroomed_BhadronFlavour);
   fChain->SetBranchAddress("FatjetAK08ungroomed_ChadronFlavour", FatjetAK08ungroomed_ChadronFlavour, &b_FatjetAK08ungroomed_ChadronFlavour);
   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("Jet_btagCSV", Jet_btagCSV, &b_Jet_btagCSV);
   fChain->SetBranchAddress("Jet_btagCMVA", Jet_btagCMVA, &b_Jet_btagCMVA);
   fChain->SetBranchAddress("Jet_partonFlavour", Jet_partonFlavour, &b_Jet_partonFlavour);
   fChain->SetBranchAddress("Jet_hadronFlavour", Jet_hadronFlavour, &b_Jet_hadronFlavour);
   fChain->SetBranchAddress("Jet_mcMatchId", Jet_mcMatchId, &b_Jet_mcMatchId);
   fChain->SetBranchAddress("Jet_pt", Jet_pt, &b_Jet_pt);
   fChain->SetBranchAddress("Jet_eta", Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_phi", Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_mass", Jet_mass, &b_Jet_mass);
   fChain->SetBranchAddress("Jet_btagBDT", Jet_btagBDT, &b_Jet_btagBDT);
   fChain->SetBranchAddress("Jet_btagCSVV0", Jet_btagCSVV0, &b_Jet_btagCSVV0);
   fChain->SetBranchAddress("Jet_btagCMVAV2", Jet_btagCMVAV2, &b_Jet_btagCMVAV2);
   Notify();
}

Bool_t heppySkimTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void heppySkimTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t heppySkimTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef heppySkimTree_cxx
