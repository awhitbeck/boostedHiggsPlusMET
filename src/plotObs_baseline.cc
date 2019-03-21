#include "TString.h"
#include "TChain.h"
#include "TH1F.h"
#include "TROOT.h"
#include "THStack.h"
#include "TPad.h"

#include <vector>
#include <map>
#include <iostream>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <cassert>
#include "plotterUtils.cc"
#include "skimSamples.cc"
#include "definitions.h"
#include "RA2bTree.cc"
#include "TriggerEfficiencySextet.cc"

using namespace std;

int MAX_EVENTS = 99999999;

void process(string selection_label,
	     string backgroundSample,
	     string signalSample,
	     string dataSample){

  // set up selectors
  bool (*selectionFunc)(RA2bTree*);
  if( selection_label == "ZNoSelection"){
    selectionFunc = baselineCutNoVBF;
  }else if( selection_label == "baselineVBF" ){
    selectionFunc = baselineCut;
  }else if( selection_label == "ZSRNoVBF"){
    selectionFunc = ZSignalRegionCutNoVBF;
  }else if( selection_label == "ZSRVBF"){
    selectionFunc = ZSignalRegionCut;
  }else if( selection_label == "ZSRHPNoVBF_SigBkg"){
    selectionFunc = ZSignalRegionHPCutNoVBF;
  }else if( selection_label == "ZSRHPVBF"){
    selectionFunc = ZSignalRegionHPCut;
  }else if( selection_label == "ZSRHPVBF-TightMjjdEta"){
    selectionFunc = ZSignalRegionHPCut;
  }else if( selection_label == "ZSRHPVBFEta"){
    selectionFunc = ZHPEtaCut;
  }else if( selection_label == "ZSRLPNoVBF"){
    selectionFunc = ZSignalRegionLPCutNoVBF;
  }else if( selection_label == "ZSRLPVBF"){
    selectionFunc = ZSignalRegionLPCut;
  }else if( selection_label == "ZSBNoVBF" ){
    selectionFunc = ZSidebandnoVBFCut;
  }else if( selection_label == "ZSBVBF" ){
    selectionFunc = ZSidebandCut;
  }else if( selection_label == "ZSBHPNoVBF" ){
    selectionFunc = ZSidebandHPCutnoVBF;
  }else if( selection_label == "ZSBHPVBF" ){
    selectionFunc = ZSidebandHPCut;
  }else if( selection_label == "ZSBLPNoVBF"){
    selectionFunc = ZSidebandLPCutnoVBF;
  }else if( selection_label == "ZSBLPVBF"){
    selectionFunc = ZSidebandLPCut;
  }else{
    assert(0);
  }

  // set up background samples
  vector<TString> backgroundSamples;
  if( backgroundSample != "" ){
    backgroundSamples.push_back(TString(backgroundSample));
  }

  // setup signal samples
  vector<TString> signalSamples;
  if( signalSample != "" ){
    signalSamples.push_back(TString(signalSample));
  }

  // setup data samples
  vector<TString> dataSamples;
  if( dataSample != "" ){
    dataSamples.push_back(TString(dataSample));
  }

  skimSamples skims(skimSamples::kSignal,backgroundSamples,signalSamples,dataSamples);
  

  // begin plotting sutff

  gROOT->ProcessLine(".L tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");
  
  typedef plot<RA2bTree> plot;

  plot NVtxplot(*fillNVtx<RA2bTree>,"NVtx_"+selection_label,"NVtx",80,0.5,80.5);//1 bin
  plot METplot(*fillMET<RA2bTree>,"MET_"+selection_label,"MET [GeV]",70,200.,3000.);//40 GeV bin
  plot MET1plot(*fillMET<RA2bTree>,"MET1_"+selection_label,"MET [GeV]",25,200.,1200.);//40 GeV bin
  plot HTplot(*fillHT<RA2bTree>,"HT_"+selection_label,"H_{T} [GeV]",75,300,3300.); // 100 GeV bin
  plot madHT(*fillMadHT<RA2bTree>,"madHT_"+selection_label,"Madgraph HT",19,100,2000);  
  plot J1pt_Ptplot(*fillLeadingJetPt<RA2bTree>,"AK8L1J_Pt_"+selection_label,"p_{T,J} [GeV]",70,200.,3000.); //40 GeV bi n;
  plot J1pt_Pt1plot(*fillLeadingJetPt<RA2bTree>,"AK8L1J_Pt1_"+selection_label,"p_{T,J} [GeV]",35,200.,1600.); //40 GeV bin;
    
  vector<plot> plots;
  plots.push_back(NVtxplot);
  plots.push_back(METplot);
  plots.push_back(MET1plot);
  plots.push_back(HTplot);
  plots.push_back(madHT);
  plots.push_back(J1pt_Ptplot);
  plots.push_back(J1pt_Pt1plot);

  // background MC samples
  for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

    RA2bTree* ntuple = skims.ntuples[iSample];
    TFile* outputFile = new TFile("plotObs_"+selection_label+"_baseline_"+skims.sampleName[iSample]+".root","RECREATE");
    
    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
      plots[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
    }

    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    TString filename;
    double weight = 0.;
    for( int iEvt = 0 ; iEvt < min(MAX_EVENTS,numEvents) ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 100000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;

      filename = ntuple->fChain->GetFile()->GetName();
      if( ( filename.Contains("SingleLept") || filename.Contains("DiLept") ) && ntuple->madHT>600. )continue;
      if(! selectionFunc(ntuple) ) continue;

      weight = ntuple->Weight*lumi;
      // ------------ end weights -------------
      //cout << "event passed all selections" << endl;
      for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++ ){
	plots[iPlot].fill(ntuple,weight);
      }
    }

    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
      plots[iPlot].Write(ntuple);
    }
    outputFile->Close();
  }// end loop over samples
    
  // Signal samples
  vector<RA2bTree*> sigSamples;
  for( int iSample = 0 ; iSample < skims.signalNtuples.size() ; iSample++){
    RA2bTree* ntuple = skims.signalNtuples[iSample];
    TFile* outputFile = new TFile("plotObs_"+selection_label+"_baseline_"+skims.signalSampleName[iSample]+".root","RECREATE");

    sigSamples.push_back(ntuple);
    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
      plots[iPlot].addSignalNtuple(ntuple,skims.signalSampleName[iSample]);
    }

    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    for( int iEvt = 0 ; iEvt < min(MAX_EVENTS,numEvents) ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 100000 == 0 ) cout << skims.signalSampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      if(! selectionFunc(ntuple) ) continue;
      for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
	if (skims.signalSampleName[iSample]=="VBFG1000") 
	  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi);
      }
    }

    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
      plots[iPlot].Write(ntuple);
    }
    
    outputFile->Close();
  }// end loop over samples


  // Data samples
  for( int iSample = 0 ; iSample < skims.dataNtuple.size() ; iSample++){
    RA2bTree* ntuple = skims.dataNtuple[iSample];
    TFile* outputFile = new TFile("plotObs_"+selection_label+"_baseline_"+skims.dataSampleName[iSample]+".root","RECREATE");
	  
    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
      plots[iPlot].addDataNtuple(ntuple,skims.dataSampleName[iSample]);
    }
    
    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    cout << "data MET: " << numEvents << endl;
    for( int iEvt = 0 ; iEvt < min(MAX_EVENTS,numEvents) ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 100000 == 0 ) cout << "data_MET: " << iEvt << "/" << min(MAX_EVENTS,numEvents) << endl;
      if(! selectionFunc(ntuple) ) continue;
      if( !signalTriggerCut(ntuple) ) continue;
      
      for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
	plots[iPlot].fillData(ntuple);
      }
    }

    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
      plots[iPlot].Write();
    }// end loop over plots
    
    outputFile->Close();
  }// end loop over samples

}// end process


int main(int argc, char** argv){

  string signal_label,background_label,data_label;
  string selection_label;
  if( argc > 5 )
    MAX_EVENTS = atoi(argv[5]);
  else
    MAX_EVENTS = 99999999;
  if( argc > 4 )
    data_label = argv[4];
  else
    data_label="";
  if( argc > 3 )
    signal_label = argv[3];
  else
    signal_label = "";
  if( argc > 2 )
    background_label = argv[2];
  else
    background_label = "ZJets_400to600";
  if( argc > 1 )
    selection_label = argv[1];
  else
    selection_label = "ZSBNoVBF";

  process(selection_label,
	  background_label,
	  signal_label,
	  data_label);
  
}
