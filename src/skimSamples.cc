#include "TChain.h"
#include "RA2bTree.cc"
#include "TString.h"

#include <vector>

class skimSamples{

public : 

  TChain *WJets, *ZJets, *QCD, *TT; 
  TChain *mGluino1300, *mGluino1400, *mGluino1500, *mGluino1600, *mGluino1700;
  TChain *mHiggsino1000,*mHiggsino900,*mHiggsino800,*mHiggsino700,*mHiggsino600,*mHiggsino500,*mHiggsino400,*mHiggsino300;
    TChain *data;
  std::vector<RA2bTree*> ntuples,signalNtuples;
  RA2bTree* dataNtuple;
  std::vector<TString> sampleName, signalSampleName;
  std::vector<TString> dataSampleName; 
  std::vector<int> fillColor, lineColor;
  
  skimSamples(TString skimType="root://cmseos.fnal.gov//store/user/awhitbe1/RA2bSkims_V10_v0/RA2bSkim"){
    ZJets = new TChain("PreSelection");
    ZJets->Add(skimType+"_ZJets.root");
    ntuples.push_back(new RA2bTree(ZJets));
    sampleName.push_back("ZJets");
    fillColor.push_back(kGreen);
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
    QCD = new TChain("PreSelection");
    QCD->Add(skimType+"_QCD.root");
    ntuples.push_back(new RA2bTree(QCD));
    sampleName.push_back("QCD");
    fillColor.push_back(kGray);

    mGluino1300 = new TChain("PreSelection");
    mGluino1300->Add(skimType+"_T5HH_mGluino1300_0.root");
    signalNtuples.push_back(new RA2bTree(mGluino1300));
    signalSampleName.push_back("mGluino1300");
    lineColor.push_back(kRed-1);

    mGluino1400 = new TChain("PreSelection");
    mGluino1400->Add(skimType+"_T5HH_mGluino1400_0.root");
    signalNtuples.push_back(new RA2bTree(mGluino1400));
    signalSampleName.push_back("mGluino1400");
    lineColor.push_back(kRed);

    mGluino1500 = new TChain("PreSelection");
    mGluino1500->Add(skimType+"_T5HH_mGluino1500_0.root");
    signalNtuples.push_back(new RA2bTree(mGluino1500));
    signalSampleName.push_back("mGluino1500");
    lineColor.push_back(kRed+1);

    mGluino1600 = new TChain("PreSelection");
    mGluino1600->Add(skimType+"_T5HH_mGluino1600_0.root");
    signalNtuples.push_back(new RA2bTree(mGluino1600));
    signalSampleName.push_back("mGluino1600");
    lineColor.push_back(kOrange);

    mGluino1700 = new TChain("PreSelection");
    mGluino1700->Add(skimType+"_T5HH_mGluino1700_0.root");
    signalNtuples.push_back(new RA2bTree(mGluino1700));
    signalSampleName.push_back("mGluino1700");        
    lineColor.push_back(kOrange+1);

    /*
    mHiggsino1000 = new TChain("tree");
    mHiggsino1000->Add("root://cmseos.fnal.gov///store/user/rgp230/SUSY/T5qqqqVV/T5HH_1000_1.root");
    signalNtuples.push_back(new RA2bTree(mHiggsino1000));
    signalSampleName.push_back("mHiggsino1000");        
    lineColor.push_back(kOrange);
    
    mHiggsino900 = new TChain("tree");
    mHiggsino900->Add("root://cmseos.fnal.gov///store/user/rgp230/SUSY/T5qqqqVV/T5HH_900_1.root");
    signalNtuples.push_back(new RA2bTree(mHiggsino900));
    signalSampleName.push_back("mHiggsino900");        
    lineColor.push_back(kRed);

    mHiggsino800 = new TChain("tree");
    mHiggsino800->Add("root://cmseos.fnal.gov///store/user/rgp230/SUSY/T5qqqqVV/T5HH_800_1.root");
    signalNtuples.push_back(new RA2bTree(mHiggsino800));
    signalSampleName.push_back("mHiggsino800");        
    lineColor.push_back(kRed);

    mHiggsino700 = new TChain("tree");
    mHiggsino700->Add("root://cmseos.fnal.gov///store/user/rgp230/SUSY/T5qqqqVV/T5HH_700_1.root");
    signalNtuples.push_back(new RA2bTree(mHiggsino700));
    signalSampleName.push_back("mHiggsino700");        
    lineColor.push_back(kRed);

    mHiggsino600 = new TChain("tree");
    mHiggsino600->Add("root://cmseos.fnal.gov///store/user/rgp230/SUSY/T5qqqqVV/T5HH_600_1.root");
    signalNtuples.push_back(new RA2bTree(mHiggsino600));
    signalSampleName.push_back("mHiggsino600");        
    lineColor.push_back(kRed);

    mHiggsino500 = new TChain("tree");
    mHiggsino500->Add("root://cmseos.fnal.gov///store/user/rgp230/SUSY/T5qqqqVV/T5HH_500_1.root");
    signalNtuples.push_back(new RA2bTree(mHiggsino500));
    signalSampleName.push_back("mHiggsino500");        
    lineColor.push_back(kRed);

    mHiggsino400 = new TChain("tree");
    mHiggsino400->Add("root://cmseos.fnal.gov///store/user/rgp230/SUSY/T5qqqqVV/T5HH_400_1.root");
    signalNtuples.push_back(new RA2bTree(mHiggsino400));
    signalSampleName.push_back("mHiggsino400");        
    lineColor.push_back(kRed);

    mHiggsino300 = new TChain("tree");
    mHiggsino300->Add("root://cmseos.fnal.gov///store/user/rgp230/SUSY/T5qqqqVV/T5HH_300_1.root");
    signalNtuples.push_back(new RA2bTree(mHiggsino300));
    signalSampleName.push_back("mHiggsino300");        
    lineColor.push_back(kRed);
    */
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
