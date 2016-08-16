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

  plot METplot(*fillMET,"MET_singleHiggsTag","MET [GeV]",15,300.,1800.);
  plot HTplot(*fillHT,"HT_singleHiggsTag","H_{T} [GeV]",15,300,2800.);
  plot Binsplot(*fillAnalysisBins,"AnalysisBins_singleHiggsTag","i^th Bin",8,0.5,8.5);
  plot JMplot(*fillSingleJetMass,"J1M_singleHiggsTag","m_{J} [GeV]",20,50.,200.);
  plot JBBplot(*fillSingleBBtag,"J1BB_singleHiggsTag","bb-tag",20,-1.,1.);
  plot JTau21plot(*fillSingleTau21,"J1Tau21_singleHiggsTag","#tau_{21}",20,0.,1.);
  plot JPtplot(*fillSinglePt,"J1Pt_singleHiggsTag","p_{T,J} [GeV]",40,300.,2300.);

  vector<plot> plots;
  plots.push_back(METplot);
  plots.push_back(HTplot);
  plots.push_back(Binsplot);
  plots.push_back(JMplot);
  plots.push_back(JBBplot);
  plots.push_back(JTau21plot);
  plots.push_back(JPtplot);

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
      if(! singleHiggsTagCut(ntuple) ) continue;
      for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++ ){
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
      if(! singleHiggsTagCut(ntuple) ) continue;
      if(ntuple->nGenHiggsBoson!=2) continue;
      for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
	plots[iPlot].fillSignal(ntuple);
      }
    }
  }

  // Data tree
  for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
    plots[iPlot].addDataNtuple(skims.dataNtuple,"data");
  }

  int numEvents = skims.dataNtuple->fChain->GetEntries();
  for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
    skims.dataNtuple->GetEntry(iEvt);
    if(! singleHiggsTagCut(skims.dataNtuple) ) continue;
    if(skims.dataNtuple->HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v==0) continue;
    if( iEvt % 1000000 == 0 ) cout << "DATA: " << iEvt << "/" << numEvents << endl;
    //if( iEvt > 100000 ) break ;
    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
      plots[iPlot].fillData(skims.dataNtuple);
    }
  }

  TCanvas* can = new TCanvas("can","can",500,500);
  for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
    plots[iPlot].Draw(can,skims.ntuples,skims.signalNtuples);
  }
}
