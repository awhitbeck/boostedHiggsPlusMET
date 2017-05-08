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
#include "RA2bTree.h"

using namespace std;

int main(int argc, char** argv){

  gROOT->ProcessLine(".L ~/tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");
  
  skimSamples skims;
  typedef plot<RA2bTree> plot;

  plot BinsSRSingleHiggsPlot(*fillAnalysisBins<RA2bTree>,"AnalysisBins_tagSR","i^th Bin",8,0.5,8.5);
  plot BinsSRAntiTagPlot(*fillAnalysisBins<RA2bTree>,"AnalysisBins_antitagSR","i^th Bin",8,0.5,8.5);
  plot BinsSBSingleHiggsPlot(*fillAnalysisBins<RA2bTree>,"AnalysisBins_tagSB","i^th Bin",8,0.5,8.5);
  plot BinsSBAntiTagPlot(*fillAnalysisBins<RA2bTree>,"AnalysisBins_antitagSB","i^th Bin",8,0.5,8.5);

  vector<plot> plots;
  plots.push_back(BinsSRSingleHiggsPlot);
  plots.push_back(BinsSRAntiTagPlot);
  plots.push_back(BinsSBSingleHiggsPlot);
  plots.push_back(BinsSBAntiTagPlot);

  // background MC samples
  for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

    heppySkimTree* ntuple = skims.ntuples[iSample];

    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
      plots[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
      plots[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
    }

    int numEvents = ntuple->fChain->GetEntries();
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 1000000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      //if( iEvt > 100000 ) break;
      if(! baselineCut(ntuple) ) continue;
      if( taggingCut(ntuple) ){
	double jetMass = fillLeadingBBtagJetMass(ntuple);
	if( jetMass > 85 && jetMass < 135 ){ 
	  plots[0].fill(ntuple);
	}else if( jetMass > 55 && jetMass < 205){
	  plots[2].fill(ntuple);
	}
      }
      if( antiTaggingCut(ntuple) ){
	double jetMass = fillLeadingBBtagJetMass(ntuple);
	if( jetMass > 85 && jetMass < 135 ){
	  plots[1].fill(ntuple);
	}else if( jetMass > 55 && jetMass < 205){
	  plots[3].fill(ntuple);
	}
      }
    }
  }

  // Signal samples
  for( int iSample = 0 ; iSample < skims.signalNtuples.size() ; iSample++){

    heppySkimTree* ntuple = skims.signalNtuples[iSample];
    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
      plots[iPlot].addSignalNtuple(ntuple,skims.signalSampleName[iSample]);
      plots[iPlot].setLineColor(ntuple,skims.lineColor[iSample]);
    }

    int numEvents = ntuple->fChain->GetEntries();
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 1000000 == 0 ) cout << skims.signalSampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      if(!baselineCut(ntuple) ) continue;
      if(ntuple->nGenHiggsBoson!=2) continue;
      if( taggingCut(ntuple) ){
	double jetMass = fillLeadingBBtagJetMass(ntuple);
	if( jetMass > 85 && jetMass < 135 ){ 
	  plots[0].fillSignal(ntuple);
	}else if( jetMass > 55 && jetMass < 205){
	  plots[2].fillSignal(ntuple);
	}
      }
      if( antiTaggingCut(ntuple) ){
	double jetMass = fillLeadingBBtagJetMass(ntuple);
	if( jetMass > 85 && jetMass < 135 ){
	  plots[1].fillSignal(ntuple);
	}else if( jetMass > 55 && jetMass < 205){
	  plots[3].fillSignal(ntuple);
	}
      }
    }
  }

  TFile* outputFile = new TFile("datacardInputs.root","RECREATE");
  TCanvas* can = new TCanvas("can","can",500,500);
  for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
    plots[iPlot].Draw(can,skims.ntuples,skims.signalNtuples);
    outputFile->cd();
    plots[iPlot].Write();
  }
  outputFile->Close();

}
