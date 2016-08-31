#include "heppyTree.cc"
#include "analyzer.cc"
#include "selectBaseline.cc"
#include "TString.h"
#include "TChain.h"
#include "TFile.h"
#include "sampleParser.cc"

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv){

  fileMap fmap = parseInputs("../data/heppyInputs.txt");
  sampleMap smap = invertFileMap(fmap);
  xsecMap xsmap = parseXsec("../data/heppyInputs.txt");

  TChain* t = new TChain("tree");
  char inputFile[200];
  sprintf(inputFile,"%s/%s","root://cmseos.fnal.gov/",argv[1]);
  t->Add(inputFile);
  float xsec = xsmap[fmap[argv[1]]]; 
  std::cout << "xsec: " << xsec << std::endl;
  float weight = 1.;
  std::cout << "norm(a): " << argv[3] << std::endl; 
  float norm = atof(argv[3]);
  std::cout << "norm(f): " << norm << std::endl; 

  heppyTree *ntuple = new heppyTree(t);
  int numEvents = t->GetEntries();

  selectBaseline<heppyTree> *selectBase = new selectBaseline<heppyTree>(ntuple,"singleElectron",0,0,1,1);

  ntuple->fChain->SetBranchStatus("*",0);
  ntuple->fChain->SetBranchStatus("run",1);
  ntuple->fChain->SetBranchStatus("lumi",1)           ;
  ntuple->fChain->SetBranchStatus("evt",1)            ;
  ntuple->fChain->SetBranchStatus("xsec",1)           ;
  ntuple->fChain->SetBranchStatus("puWeight",1)       ;
  ntuple->fChain->SetBranchStatus("nTrueInt",1)       ;
  ntuple->fChain->SetBranchStatus("genWeight",1)      ;
  ntuple->fChain->SetBranchStatus("nPU0",1)           ;
  ntuple->fChain->SetBranchStatus("nPVs",1)           ;
  ntuple->fChain->SetBranchStatus("rho",1)            ;
  ntuple->fChain->SetBranchStatus("Flag_HBHENoiseIsoFilter",1);
  ntuple->fChain->SetBranchStatus("Flag_EcalDeadCellTriggerPrimitiveFilter",1);
  ntuple->fChain->SetBranchStatus("Flag_trkPOG_manystripclus53X",1);
  ntuple->fChain->SetBranchStatus("Flag_ecalLaserCorrFilter",1);
  ntuple->fChain->SetBranchStatus("Flag_trkPOG_toomanystripclus53X",1);
  ntuple->fChain->SetBranchStatus("Flag_hcalLaserEventFilter",1);
  ntuple->fChain->SetBranchStatus("Flag_muonBadTrackFilter",1);
  ntuple->fChain->SetBranchStatus("Flag_trkPOG_logErrorTooManyClusters",1);
  ntuple->fChain->SetBranchStatus("Flag_trkPOGFilters",1);
  ntuple->fChain->SetBranchStatus("Flag_trackingFailureFilter",1);
  ntuple->fChain->SetBranchStatus("Flag_CSCTightHaloFilter",1);
  ntuple->fChain->SetBranchStatus("Flag_HBHENoiseFilter",1);
  ntuple->fChain->SetBranchStatus("Flag_chargedHadronTrackResolutionFilter",1);
  ntuple->fChain->SetBranchStatus("Flag_goodVertices",1);
  ntuple->fChain->SetBranchStatus("Flag_METFilters",1);
  ntuple->fChain->SetBranchStatus("Flag_CSCTightHalo2015Filter",1);
  ntuple->fChain->SetBranchStatus("Flag_eeBadScFilter",1);
  ntuple->fChain->SetBranchStatus("HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v",1);
  ntuple->fChain->SetBranchStatus("HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v",1);
  ntuple->fChain->SetBranchStatus("HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v",1);
  ntuple->fChain->SetBranchStatus("HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v",1);
  ntuple->fChain->SetBranchStatus("HLT_BIT_HLT_PFMET170_NoiseCleaned_v",1);
  ntuple->fChain->SetBranchStatus("HLT_BIT_HLT_PFHT350_PFMET100_v",1);
  ntuple->fChain->SetBranchStatus("HLT_BIT_HLT_PFHT800_v",1) ;
  ntuple->fChain->SetBranchStatus("met_pt",1) ;
  ntuple->fChain->SetBranchStatus("met_phi",1) ;
  ntuple->fChain->SetBranchStatus("nGenHiggsBoson",1) ;
  ntuple->fChain->SetBranchStatus("GenHiggsBoson_pdgId",1);
  ntuple->fChain->SetBranchStatus("GenHiggsBoson_pt",1);
  ntuple->fChain->SetBranchStatus("GenHiggsBoson_eta",1);
  ntuple->fChain->SetBranchStatus("GenHiggsBoson_phi",1);
  ntuple->fChain->SetBranchStatus("GenHiggsBoson_mass",1);
  ntuple->fChain->SetBranchStatus("GenHiggsBoson_charge",1);
  ntuple->fChain->SetBranchStatus("GenHiggsBoson_status",1);
  ntuple->fChain->SetBranchStatus("naLeptons",1)      ;
  ntuple->fChain->SetBranchStatus("vLeptons_charge",1);
  ntuple->fChain->SetBranchStatus("vLeptons_tightId",1);
  ntuple->fChain->SetBranchStatus("vLeptons_pdgId",1) ;
  ntuple->fChain->SetBranchStatus("vLeptons_pt",1)    ;
  ntuple->fChain->SetBranchStatus("vLeptons_eta",1)   ;
  ntuple->fChain->SetBranchStatus("vLeptons_phi",1)   ;
  ntuple->fChain->SetBranchStatus("vLeptons_mass",1)  ;
  ntuple->fChain->SetBranchStatus("naLeptons",1);
  ntuple->fChain->SetBranchStatus("aLeptons_pt",1);
  ntuple->fChain->SetBranchStatus("aLeptons_eta",1);
  ntuple->fChain->SetBranchStatus("aLeptons_phi",1);
  ntuple->fChain->SetBranchStatus("aLeptons_mass",1);
  ntuple->fChain->SetBranchStatus("aLeptons_isPFMuon",1);
  ntuple->fChain->SetBranchStatus("aLeptons_isGlobalMuon",1);
  ntuple->fChain->SetBranchStatus("aLeptons_isTrackerMuon",1);
  ntuple->fChain->SetBranchStatus("aLeptons_miniRelIso",1);
  ntuple->fChain->SetBranchStatus("aLeptons_mediumMuonId",1);
  ntuple->fChain->SetBranchStatus("aLeptons_etaSc",1);
  ntuple->fChain->SetBranchStatus("aLeptons_relIso03",1);
  ntuple->fChain->SetBranchStatus("aLeptons_relIso04",1);
  ntuple->fChain->SetBranchStatus("aLeptons_relIsoAn04",1);
  ntuple->fChain->SetBranchStatus("aLeptons_eleSieie",1);
  ntuple->fChain->SetBranchStatus("aLeptons_eleDEta",1);
  ntuple->fChain->SetBranchStatus("aLeptons_eleDPhi",1);
  ntuple->fChain->SetBranchStatus("aLeptons_eleHoE",1);
  ntuple->fChain->SetBranchStatus("aLeptons_eleExpMissingInnerHits",1);
  ntuple->fChain->SetBranchStatus("aLeptons_eleooEmooP",1);
  ntuple->fChain->SetBranchStatus("nJet",1)           ;
  ntuple->fChain->SetBranchStatus("Jet_btagCSV",1)    ;
  ntuple->fChain->SetBranchStatus("Jet_btagCMVA",1)   ;
  ntuple->fChain->SetBranchStatus("Jet_partonFlavour",1);
  ntuple->fChain->SetBranchStatus("Jet_hadronFlavour",1);
  ntuple->fChain->SetBranchStatus("Jet_mcMatchId",1)  ;
  ntuple->fChain->SetBranchStatus("Jet_pt",1)         ;
  ntuple->fChain->SetBranchStatus("Jet_eta",1)        ;
  ntuple->fChain->SetBranchStatus("Jet_phi",1)        ;
  ntuple->fChain->SetBranchStatus("Jet_mass",1)       ;
  ntuple->fChain->SetBranchStatus("Jet_btagBDT",1)    ;
  ntuple->fChain->SetBranchStatus("Jet_btagCSVV0",1)  ;
  ntuple->fChain->SetBranchStatus("Jet_btagCMVAV2",1) ;
  ntuple->fChain->SetBranchStatus("nFatjetAK08ungroomed",1);
  ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_pt",1);
  ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_eta",1);
  ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_phi",1);
  ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_mass",1);
  ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_tau1",1);
  ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_tau2",1);
  ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_mpruned",1);
  ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_mprunedcorr",1);
  ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_bbtag",1);
  ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_chargedHadronEnergyFraction",1);
  ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_chargedMultiplicity",1);
  ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_Flavour",1);
  ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_BhadronFlavour",1);
  ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_ChadronFlavour",1);
  ntuple->fChain->SetBranchStatus("*SubjetAK08softdrop*",1);

  TTree* outputTree = ntuple->fChain->CloneTree(0);
  outputTree->Branch("weight",&weight,"weight/F");

  for( int i = 0 ; i < numEvents ; i++ ){
    if( i%10000 == 0 ) std::cout << "Event " << i << "/" << numEvents << endl;
    t->GetEntry(i);
    xsec = xsmap[fmap[argv[1]]];
    weight = xsec/norm;
    if( selectBase->process() ){
      outputTree->Fill();
    }
  }

  // for output file name
  int pos = find(smap[fmap[argv[1]]]->begin(), 
		 smap[fmap[argv[1]]]->end(),
		 argv[1])-smap[fmap[argv[1]]]->begin();

  char outputFileName[200];
  sprintf(outputFileName,"singleEleCR_%s_%i.root",fmap[argv[1]].Data(),pos);
    std::cout << "outputFile: " << outputFileName << std::endl;
  TFile* outputFile = new TFile(outputFileName,"RECREATE");
  cout << "save tree" << endl;
  selectBase->histo->Write("singleEleCRYields");
  outputTree->Write();
  outputFile->Close();

  delete ntuple;
  delete selectBase;

  std::cout << "done..." << std::endl;
}  
