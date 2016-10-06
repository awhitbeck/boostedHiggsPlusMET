#include "TString.h"
#include "TChain.h"
#include "TH1F.h"
#include "TROOT.h"
#include "THStack.h"
#include "TPad.h"

#include <vector>
#include <map>
#include <iostream>

#include "plotterUtils.cc"
#include "skimSamples.cc"
#include "definitions.cc"
#include "RA2bTree.cc"

using namespace std;

int main(int argc, char** argv){

  gROOT->ProcessLine(".L ~/tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");
  
  skimSamples skims;
  skimSamples skimsMu("root://cmseos.fnal.gov//store/user/awhitbe1/RA2bSkims_V10_v0/singleMuCR");
  typedef plot<RA2bTree> plot;

  plot tagSRMETplot(*fillMET<RA2bTree>,"MET_tagSR","E_{T}^{miss} [GeV]",7,300.,1000.);
  plot tagSBMETplot(*fillMET<RA2bTree>,"MET_tagSB","E_{T}^{miss} [GeV]",7,300.,1000.);

  plot mutagSRMETplot(*fillMET<RA2bTree>,"MET_mutagSR","E_{T}^{miss} [GeV]",7,300.,1000.);
  plot mutagSBMETplot(*fillMET<RA2bTree>,"MET_mutagSB","E_{T}^{miss} [GeV]",7,300.,1000.);

  plot antiTagSRMETplot(*fillMET<RA2bTree>,"MET_antitagSR","E_{T}^{miss} [GeV]",7,300.,1000.);
  plot antiTagSBMETplot(*fillMET<RA2bTree>,"MET_antitagSB","E_{T}^{miss} [GeV]",7,300.,1000.);

  plot muantiTagSRMETplot(*fillMET<RA2bTree>,"MET_muantitagSR","E_{T}^{miss} [GeV]",7,300.,1000.);
  plot muantiTagSBMETplot(*fillMET<RA2bTree>,"MET_muantitagSB","E_{T}^{miss} [GeV]",7,300.,1000.);

  plot muDoubleTagSRMETplot(*fillMET<RA2bTree>,"MET_muDoubletagSR","E_{T}^{miss} [GeV]",7,300.,1000.);
  plot muDoubleTagSBMETplot(*fillMET<RA2bTree>,"MET_muDoubletagSB","E_{T}^{miss} [GeV]",7,300.,1000.);

  plot doubleTagSRMETplot(*fillMET<RA2bTree>,"MET_doubletagSR","E_{T}^{miss} [GeV]",7,300.,1000.);
  plot doubleTagSBMETplot(*fillMET<RA2bTree>,"MET_doubletagSB","E_{T}^{miss} [GeV]",7,300.,1000.);

  vector<plot> plots;
  plots.push_back(tagSRMETplot);
  plots.push_back(tagSBMETplot);
  plots.push_back(antiTagSRMETplot);
  plots.push_back(antiTagSBMETplot);
  plots.push_back(doubleTagSRMETplot);
  plots.push_back(doubleTagSBMETplot);

  vector<plot> plotsMu;
  plotsMu.push_back(mutagSRMETplot);
  plotsMu.push_back(mutagSBMETplot);
  plotsMu.push_back(muantiTagSRMETplot);
  plotsMu.push_back(muantiTagSBMETplot);
  plotsMu.push_back(muDoubleTagSRMETplot);
  plotsMu.push_back(muDoubleTagSBMETplot);

  // background MC samples - 0 lepton regions
  for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

    RA2bTree* ntuple = skims.ntuples[iSample];

    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
      plots[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
      plots[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
    }

    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 10000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      //if( iEvt > 100000 ) break;
      if(! baselineCut(ntuple) ) continue;
      if( doubleTaggingLooseCut(ntuple) ){
	double jetMass = fillLeadingJetMass(ntuple);
	if( jetMass > 85 && jetMass < 135 ){
	  plots[4].fill(ntuple);
	}else if( jetMass > 50 && jetMass < 200){
	  plots[5].fill(ntuple);
	}
      }else{
	if( singleHiggsTagLooseCut(ntuple) ){
	  double jetMass = fillLeadingJetMass(ntuple);
	  if( jetMass > 85 && jetMass < 135 ){ 
	    plots[0].fill(ntuple);
	  }else if( jetMass > 50 && jetMass < 200){
	    plots[1].fill(ntuple);
	  }
	}
	if( antiTaggingLooseCut(ntuple) ){
	  double jetMass = fillLeadingJetMass(ntuple);
	  if( jetMass > 85 && jetMass < 135 ){
	    plots[2].fill(ntuple);
	  }else if( jetMass > 50 && jetMass < 200){
	    plots[3].fill(ntuple);
	  }
	}
      }
    }
  }

  // background MC samples - 1 lepton regions
  for( int iSample = 0 ; iSample < skimsMu.ntuples.size() ; iSample++){

    RA2bTree* ntuple = skimsMu.ntuples[iSample];

    for( int iPlot = 0 ; iPlot < plotsMu.size() ; iPlot++){
      plotsMu[iPlot].addNtuple(ntuple,skimsMu.sampleName[iSample]);
      plotsMu[iPlot].setFillColor(ntuple,skimsMu.fillColor[iSample]);
    }

    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 1000000 == 0 ) cout << skimsMu.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      //if( iEvt > 100000 ) break;
      if(! baselineCut(ntuple) ) continue;
      if( doubleTaggingLooseCut(ntuple) ){
	double jetMass = fillLeadingJetMass(ntuple);
	if( jetMass > 85 && jetMass < 135 ){
	  plotsMu[4].fill(ntuple);
	}else if( jetMass > 50 && jetMass < 200){
	  plotsMu[5].fill(ntuple);
	}
      }else{
	if( singleHiggsTagLooseCut(ntuple) ){
	  double jetMass = fillLeadingJetMass(ntuple);
	  if( jetMass > 85 && jetMass < 135 ){ 
	    plotsMu[0].fill(ntuple);
	  }else if( jetMass > 50 && jetMass < 200){
	    plotsMu[1].fill(ntuple);
	  }
	}
	if( antiTaggingLooseCut(ntuple) ){
	  double jetMass = fillLeadingJetMass(ntuple);
	  if( jetMass > 85 && jetMass < 135 ){
	    plotsMu[2].fill(ntuple);
	  }else if( jetMass > 50 && jetMass < 200){
	    plotsMu[3].fill(ntuple);
	  }
	}
      }
    }
  }

  // Signal samples
  for( int iSample = 0 ; iSample < skims.signalNtuples.size() ; iSample++){

    RA2bTree* ntuple = skims.signalNtuples[iSample];
    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
      plots[iPlot].addSignalNtuple(ntuple,skims.signalSampleName[iSample]);
      plots[iPlot].setLineColor(ntuple,skims.lineColor[iSample]);
    }

    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 1000000 == 0 ) cout << skims.signalSampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      if(! baselineCut(ntuple) ) continue;
      if( doubleTaggingLooseCut(ntuple) ){
		double jetMass = fillLeadingJetMass(ntuple);
	if( jetMass > 85 && jetMass < 135 ){
	  if( skims.signalSampleName[iSample].Index("mHiggsino900") != -1 )
	    plots[4].fillSignal(ntuple,ntuple->Weight*lumi/104283.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino1000") != -1 )
	    plots[4].fillSignal(ntuple,ntuple->Weight*lumi/101476.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino700") != -1 )
	    plots[4].fillSignal(ntuple,ntuple->Weight*lumi/99027.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino800") != -1 )
            plots[4].fillSignal(ntuple,ntuple->Weight*lumi/101643.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino600") != -1 )
	    plots[4].fillSignal(ntuple,ntuple->Weight*lumi/100218.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino500") != -1 )
            plots[4].fillSignal(ntuple,ntuple->Weight*lumi/94578.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino400") != -1 )
	    plots[4].fillSignal(ntuple,ntuple->Weight*lumi/106716.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino300") != -1 )
            plots[4].fillSignal(ntuple,ntuple->Weight*lumi/92229.);
	  else
	    plots[4].fillSignal(ntuple);
	}else if( jetMass > 50 && jetMass < 200){
	  if( skims.signalSampleName[iSample].Index("mHiggsino900") != -1 )
	    plots[5].fillSignal(ntuple,ntuple->Weight*lumi/104283.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino1000") != -1 )
	    plots[5].fillSignal(ntuple,ntuple->Weight*lumi/101476.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino700") != -1 )
	    plots[5].fillSignal(ntuple,ntuple->Weight*lumi/99027.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino800") != -1 )
            plots[5].fillSignal(ntuple,ntuple->Weight*lumi/101643.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino600") != -1 )
	    plots[5].fillSignal(ntuple,ntuple->Weight*lumi/100218.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino500") != -1 )
            plots[5].fillSignal(ntuple,ntuple->Weight*lumi/94578.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino400") != -1 )
	    plots[5].fillSignal(ntuple,ntuple->Weight*lumi/106716.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino300") != -1 )
            plots[5].fillSignal(ntuple,ntuple->Weight*lumi/92229.);
	  else
	    plots[5].fillSignal(ntuple);
	}
      }else{
	if( singleHiggsTagLooseCut(ntuple) ){
	  double jetMass = fillLeadingJetMass(ntuple);
	  if( jetMass > 85 && jetMass < 135 ){ 
	  if( skims.signalSampleName[iSample].Index("mHiggsino900") != -1 )
	    plots[0].fillSignal(ntuple,ntuple->Weight*lumi/104283.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino1000") != -1 )
	    plots[0].fillSignal(ntuple,ntuple->Weight*lumi/101476.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino700") != -1 )
	    plots[0].fillSignal(ntuple,ntuple->Weight*lumi/99027.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino800") != -1 )
            plots[0].fillSignal(ntuple,ntuple->Weight*lumi/101643.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino400") != -1 )
	    plots[0].fillSignal(ntuple,ntuple->Weight*lumi/106716.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino300") != -1 )
            plots[0].fillSignal(ntuple,ntuple->Weight*lumi/92229.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino600") != -1 )
	    plots[0].fillSignal(ntuple,ntuple->Weight*lumi/100218.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino500") != -1 )
            plots[0].fillSignal(ntuple,ntuple->Weight*lumi/94578.);
	  else
	    plots[0].fillSignal(ntuple);
	  }else if( jetMass > 50 && jetMass < 200){
	  if( skims.signalSampleName[iSample].Index("mHiggsino900") != -1 )
	    plots[1].fillSignal(ntuple,ntuple->Weight*lumi/104283.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino1000") != -1 )
	    plots[1].fillSignal(ntuple,ntuple->Weight*lumi/101476.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino700") != -1 )
	    plots[1].fillSignal(ntuple,ntuple->Weight*lumi/99027.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino800") != -1 )
            plots[1].fillSignal(ntuple,ntuple->Weight*lumi/101643.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino600") != -1 )
	    plots[1].fillSignal(ntuple,ntuple->Weight*lumi/100218.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino500") != -1 )
            plots[1].fillSignal(ntuple,ntuple->Weight*lumi/94578.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino400") != -1 )
	    plots[1].fillSignal(ntuple,ntuple->Weight*lumi/106716.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino300") != -1 )
            plots[1].fillSignal(ntuple,ntuple->Weight*lumi/92229.);
	  else
	    plots[1].fillSignal(ntuple);
	  }
	}
	if( antiTaggingLooseCut(ntuple) ){
	  double jetMass = fillLeadingJetMass(ntuple);
	  if( jetMass > 85 && jetMass < 135 ){
	  if( skims.signalSampleName[iSample].Index("mHiggsino900") != -1 )
	    plots[2].fillSignal(ntuple,ntuple->Weight*lumi/104283.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino1000") != -1 )
	    plots[2].fillSignal(ntuple,ntuple->Weight*lumi/101476.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino700") != -1 )
	    plots[2].fillSignal(ntuple,ntuple->Weight*lumi/99027.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino800") != -1 )
            plots[2].fillSignal(ntuple,ntuple->Weight*lumi/101643.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino600") != -1 )
	    plots[2].fillSignal(ntuple,ntuple->Weight*lumi/100218.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino500") != -1 )
            plots[2].fillSignal(ntuple,ntuple->Weight*lumi/94578.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino400") != -1 )
	    plots[2].fillSignal(ntuple,ntuple->Weight*lumi/106716.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino300") != -1 )
            plots[2].fillSignal(ntuple,ntuple->Weight*lumi/92229.);
	  else
	    plots[2].fillSignal(ntuple);
	  }else if( jetMass > 50 && jetMass < 200){
	  if( skims.signalSampleName[iSample].Index("mHiggsino900") != -1 )
	    plots[3].fillSignal(ntuple,ntuple->Weight*lumi/104283.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino1000") != -1 )
	    plots[3].fillSignal(ntuple,ntuple->Weight*lumi/101476.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino700") != -1 )
	    plots[3].fillSignal(ntuple,ntuple->Weight*lumi/99027.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino800") != -1 )
            plots[3].fillSignal(ntuple,ntuple->Weight*lumi/101643.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino600") != -1 )
	    plots[3].fillSignal(ntuple,ntuple->Weight*lumi/100218.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino500") != -1 )
            plots[3].fillSignal(ntuple,ntuple->Weight*lumi/94578.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino400") != -1 )
	    plots[3].fillSignal(ntuple,ntuple->Weight*lumi/106716.);
	  else if( skims.signalSampleName[iSample].Index("mHiggsino300") != -1 )
            plots[3].fillSignal(ntuple,ntuple->Weight*lumi/92229.);
	  else
	    plots[3].fillSignal(ntuple);
	  }
	}
      }
    }
  }

  TFile* outputFile = new TFile("datacardInputs_MET.root","RECREATE");
  for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
    outputFile->cd();
    plots[iPlot].Write();
  }
  for( int iPlot = 0 ; iPlot < plotsMu.size() ; iPlot++){
    outputFile->cd();
    plotsMu[iPlot].Write();
  }
  outputFile->Close();

}
