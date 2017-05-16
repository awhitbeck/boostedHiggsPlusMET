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
#include "heppySkimTree.h"

using namespace std;

int main(int argc, char** argv){

  gROOT->ProcessLine(".L tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");
  
  skimSamples skims;

  plot tagSRMETplot(*fillMET,"MET_tagSR","E_{T}^{miss} [GeV]",17,300.,2000.);
  plot tagSBMETplot(*fillMET,"MET_tagSB","E_{T}^{miss} [GeV]",17,300.,2000.);
  plot antiTagSRMETplot(*fillMET,"MET_antitagSR","E_{T}^{miss} [GeV]",17,300.,2000.);
  plot antiTagSBMETplot(*fillMET,"MET_antitagSB","E_{T}^{miss} [GeV]",17,300.,2000.);

  vector<plot> plots;
  plots.push_back(tagSRMETplot);
  plots.push_back(tagSBMETplot);
  plots.push_back(antiTagSRMETplot);
  plots.push_back(antiTagSBMETplot);

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
      if( int(fillNJets(ntuple)) < 4. ) continue; 
      if( taggingCut(ntuple) ){
	double jetMass = fillLeadingBBtagJetMass(ntuple);
	if( jetMass > 85 && jetMass < 135 ){ 
	  plots[0].fill(ntuple);
	}else if( jetMass > 50 && jetMass < 200){
	  plots[1].fill(ntuple);
	}
      }
      if( antiTaggingCut(ntuple) ){
	double jetMass = fillLeadingBBtagJetMass(ntuple);
	if( jetMass > 85 && jetMass < 135 ){
	  plots[2].fill(ntuple);
	}else if( jetMass > 50 && jetMass < 200){
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
      if( int(fillNJets(ntuple)) < 4. )continue;
      if(ntuple->nGenHiggsBoson!=2) continue;
      if( taggingCut(ntuple) ){
	double jetMass = fillLeadingBBtagJetMass(ntuple);
	if( jetMass > 85 && jetMass < 135 ){ 
	  plots[0].fillSignal(ntuple);
	}else if( jetMass > 50 && jetMass < 200){
	  plots[1].fillSignal(ntuple);
	}
      }
      if( antiTaggingCut(ntuple) ){
	double jetMass = fillLeadingBBtagJetMass(ntuple);
	if( jetMass > 85 && jetMass < 135 ){
	  plots[2].fillSignal(ntuple);
	}else if( jetMass > 50 && jetMass < 200){
	  plots[3].fillSignal(ntuple);
	}
      }
    }
  }

  TFile* outputFile = new TFile("NJets4_METonlyBinning/datacardInputs.root","RECREATE");
  TCanvas* can = new TCanvas("can","can",500,500);
  for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
    plots[iPlot].buildSum();
    plots[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"NJets4_METonlyBinning");
    outputFile->cd();
    plots[iPlot].Write();
  }
  outputFile->Close();
}
