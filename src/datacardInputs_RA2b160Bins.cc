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

  gROOT->ProcessLine(".L ~/tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");
  
  skimSamples skims;

  plot SRplot(*fillRA2b160Bins,"RA2b160Bins_SR","i^{th} Analysis Bin",160,0.5,160.5);
  plot METPlot(*fillMET,"MET","E_{T}^{miss} [GeV]",17,300.,2000.);
  plot HTPlot(*fillHT,"HT","H_{T} [GeV]",27,300.,3000.);
  plot NJetsPlot(*fillNJets,"NJets","n_{j}",10,2.5,12.5);
  plot BTagsPlot(*fillBTags,"BTags","n_{b}",5,-0.5,4.5);
  plot DeltaPhi1Plot(*fillDeltaPhi1,"DeltaPhi1","#Delta#Phi_{1}",20,0.,3.1415);
  plot DeltaPhi2Plot(*fillDeltaPhi2,"DeltaPhi2","#Delta#Phi_{2}",20,0.,3.1415);
  plot DeltaPhi3Plot(*fillDeltaPhi3,"DeltaPhi3","#Delta#Phi_{3}",20,0.,3.1415);
  plot DeltaPhi4Plot(*fillDeltaPhi4,"DeltaPhi4","#Delta#Phi_{4}",20,0.,3.1415);

  vector<plot> plots;
  plots.push_back(SRplot);
  plots.push_back(METPlot);
  plots.push_back(HTPlot);
  plots.push_back(NJetsPlot);
  plots.push_back(BTagsPlot);
  plots.push_back(DeltaPhi1Plot);
  plots.push_back(DeltaPhi2Plot);
  plots.push_back(DeltaPhi3Plot);
  plots.push_back(DeltaPhi4Plot);
  
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
      if(! RA2bBaselineCut(ntuple) ) continue;
      for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
	plots[iPlot].fill(ntuple);
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
      if(!RA2bBaselineCut(ntuple) ) continue;
      if(ntuple->nGenHiggsBoson!=2) continue;
      for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
	plots[iPlot].fillSignal(ntuple);
      }
    }
  }

  TFile* outputFile = new TFile("RA2b160Bins/datacardInputs.root","RECREATE");
  plots[0].Write();
  outputFile->Close();

  TCanvas* can = new TCanvas("can","can",500,500);
  for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
    plots[iPlot].buildSum();
    plots[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"RA2b160Bins");
  }

}
