#include "TChain.h"
#include "RA2bTree.cc"
#include "TString.h"

#include <vector>

class skimSamples{

public : 

  TChain *WJets, *ZJets, *QCD, *TT, *mGluino1300, *mGluino1400, *mGluino1500, *mGluino1600, *mGluino1700, *data;
  std::vector<RA2bTree*> ntuples,signalNtuples;
  RA2bTree* dataNtuple;
  std::vector<TString> sampleName, signalSampleName;
  std::vector<int> fillColor, lineColor;
  
  skimSamples(TString skimType="root://cmseos.fnal.gov//store/user/awhitbe1/RA2bSkims_V10_v0/RA2bSkim"){
    ZJets = new TChain("PreSelection");
    ZJets->Add(skimType+"_ZJets.root");
    ntuples.push_back(new RA2bTree(ZJets));
    sampleName.push_back("ZJets");
    fillColor.push_back(kGreen);
    QCD = new TChain("PreSelection");
    QCD->Add(skimType+"_QCD.root");
    ntuples.push_back(new RA2bTree(QCD));
    sampleName.push_back("QCD");
    fillColor.push_back(kGray);
    WJets = new TChain("PreSelection");
    WJets->Add(skimType+"_WJets.root");
    ntuples.push_back(new RA2bTree(WJets));
    sampleName.push_back("WJets");
    fillColor.push_back(kBlue);
    TT = new TChain("PreSelection");
    TT->Add(skimType+"_TTJets.root");
    ntuples.push_back(new RA2bTree(TT));
    sampleName.push_back("TT");
    fillColor.push_back(kCyan);

    mGluino1300 = new TChain("PreSelection");
    mGluino1300->Add(skimType+"_T5GH_mGluino_1300_mNLSP_1250.root");
    signalNtuples.push_back(new RA2bTree(mGluino1300));
    signalSampleName.push_back("mGluino1300");
    lineColor.push_back(kRed-1);
    mGluino1400 = new TChain("PreSelection");
    mGluino1400->Add(skimType+"_T5GH_mGluino_1400_mNLSP_1350.root");
    signalNtuples.push_back(new RA2bTree(mGluino1400));
    signalSampleName.push_back("mGluino1400");
    lineColor.push_back(kRed);
    mGluino1500 = new TChain("PreSelection");
    mGluino1500->Add(skimType+"_T5GH_mGluino_1500_mNLSP_1450.root");
    signalNtuples.push_back(new RA2bTree(mGluino1500));
    signalSampleName.push_back("mGluino1500");
    lineColor.push_back(kRed+1);
    mGluino1600 = new TChain("PreSelection");
    mGluino1600->Add(skimType+"_T5GH_mGluino_1600_mNLSP_1550.root");
    signalNtuples.push_back(new RA2bTree(mGluino1600));
    signalSampleName.push_back("mGluino1600");
    lineColor.push_back(kOrange);
    mGluino1700 = new TChain("PreSelection");
    mGluino1700->Add(skimType+"_T5GH_mGluino_1700_mNLSP_1650.root");
    signalNtuples.push_back(new RA2bTree(mGluino1700));
    signalSampleName.push_back("mGluino1700");        
    lineColor.push_back(kOrange+1);
    
    data = new TChain("PreSelection");
    data->Add(skimType+"_HTMHT.root");
    dataNtuple = new RA2bTree(data);

  };

  RA2bTree* findNtuple(TString name){
    for( int iSam = 0 ; iSam < sampleName.size() ; iSam++ ){
      if( sampleName[iSam] == name )
	return ntuples[iSam] ;
    }
    for( int iSam = 0 ; iSam < signalSampleName.size() ; iSam++ ){
      if( signalSampleName[iSam] == name )
	return signalNtuples[iSam] ;
    }
    return NULL;
  };

};
