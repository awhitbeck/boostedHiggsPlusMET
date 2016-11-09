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
  typedef plot<RA2bTree> plot;

  plot METplot(*fillMET<RA2bTree>,"MET_doubleHiggsTag","MET [GeV]",15,300.,1800.);
  plot HTplot(*fillHT<RA2bTree>,"HT_doubleHiggsTag","H_{T} [GeV]",15,300,2800.);
  plot Binsplot(*fillAnalysisBins<RA2bTree>,"AnalysisBins_doubleHiggsTag","i^th Bin",8,0.5,8.5);
  plot J1Mplot(*fillLeadingJetMass<RA2bTree>,"J1M_doubleHiggsTag","leading m_{J} [GeV]",20,50.,200.);
  plot J1BBplot(*fillLeadingBBtag<RA2bTree>,"J1BB_doubleHiggsTag","leading bb-tag",20,-1.,1.);
  plot J1Tau21plot(*fillLeadingTau21<RA2bTree>,"J1Tau21_doubleHiggsTag","leading #tau_{21}",20,0.,1.);
  plot J1Ptplot(*fillLeadingJetPt<RA2bTree>,"J1Pt_doubleHiggsTag","leading p_{T,J} [GeV]",40,300.,2300.);
  plot J2Mplot(*fillSubLeadingJetMass<RA2bTree>,"J2M_doubleHiggsTag","subleading m_{J} [GeV]",20,50.,200.);
  plot J2BBplot(*fillSubLeadingBBtag<RA2bTree>,"J2BB_doubleHiggsTag","subleading bb-tag",20,-1.,1.);
  plot J2Tau21plot(*fillSubLeadingTau21<RA2bTree>,"J2Tau21_doubleHiggsTag","subleading #tau_{21}",20,0.,1.);
  plot J2Ptplot(*fillSubLeadingJetPt<RA2bTree>,"J2Pt_doubleHiggsTag","subleading p_{T,J} [GeV]",40,300.,2300.);

  vector<plot> plots;
  plots.push_back(METplot);
  plots.push_back(HTplot);
  plots.push_back(Binsplot);
  plots.push_back(J1Mplot);
  plots.push_back(J1BBplot);
  plots.push_back(J1Tau21plot);
  plots.push_back(J1Ptplot);
  plots.push_back(J2Mplot);
  plots.push_back(J2BBplot);
  plots.push_back(J2Tau21plot);
  plots.push_back(J2Ptplot);

  // background MC samples
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
      if( iEvt % 100000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      //if( iEvt > 100000 ) break;
      if(! baselineCut(ntuple) ) continue;
      if(! doubleHiggsTagCut(ntuple) ) continue;
      for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++ ){
	plots[iPlot].fill(ntuple);
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
      if( iEvt % 100000 == 0 ) cout << skims.signalSampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      if(! baselineCut(ntuple) ) continue;
      if(! doubleHiggsTagCut(ntuple) ) continue;
      //if(ntuple->nGenHiggsBoson!=2) continue;
      for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
          if( skims.signalSampleName[iSample].Index("mHiggsino900") != -1 ){
              //cout << "mHiggsino900: " << ntuple->Weight*40000./59508. << endl;
              plots[iPlot].fillSignal(ntuple,ntuple->Weight*40000./59508.);
          }else if( skims.signalSampleName[iSample].Index("mHiggsino1000") != -1 ){
              //cout << "mHiggsino1000: " << ntuple->Weight*40000./62968. << endl;
              plots[iPlot].fillSignal(ntuple,ntuple->Weight*40000./62968.);
          }else
              plots[iPlot].fillSignal(ntuple);
      }
    }
  }

  // Data tree
  for( int iPlot = 0 ; iPlot < 0 /*plots.size()*/ ; iPlot++){
    plots[iPlot].addDataNtuple(skims.dataNtuple,"data");
  }

  int numEvents = skims.dataNtuple->fChain->GetEntries();
  ntupleBranchStatus<RA2bTree>(skims.dataNtuple);
  for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
      skims.dataNtuple->GetEntry(iEvt);
      if(! doubleHiggsTagCut(skims.dataNtuple) ) continue;
      //if(skims.dataNtuple->HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v==0) continue;
      if( iEvt % 1000000 == 0 ) cout << "DATA: " << iEvt << "/" << numEvents << endl;
      //if( iEvt > 100000 ) break ;
      for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
          plots[iPlot].fillSignal(skims.dataNtuple);
      }
  }

  TCanvas* can = new TCanvas("can","can",500,500);
  for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
    plots[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"plotObs_doubleHiggsTag_plots");
  }
}
