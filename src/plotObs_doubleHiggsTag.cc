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
  plot NJetsplot(*fillNJets<RA2bTree>,"NJets_doubleHiggsTag","n_{j}",14,1.5,15.5);
  plot BTagsplot(*fillBTags<RA2bTree>,"BTags_doubleHiggsTag","n_{b}",6,-0.5,5.5);

  plot DeltaPhi1plot(*fillDeltaPhi1<RA2bTree>,"DeltaPhi1_doubleHiggsTag","#Delta#Phi_{1}",20,0,3.1415);
  plot DeltaPhi2plot(*fillDeltaPhi2<RA2bTree>,"DeltaPhi2_doubleHiggsTag","#Delta#Phi_{2}",20,0,3.1415);
  plot DeltaPhi3plot(*fillDeltaPhi3<RA2bTree>,"DeltaPhi3_doubleHiggsTag","#Delta#Phi_{3}",20,0,3.1415);
  plot DeltaPhi4plot(*fillDeltaPhi4<RA2bTree>,"DeltaPhi4_doubleHiggsTag","#Delta#Phi_{4}",20,0,3.1415);


  plot J1Mplot(*fillLeadingJetMass<RA2bTree>,"J1M_doubleHiggsTag","leading m_{J} [GeV]",40,50.,250.);
  plot J1BBplot(*fillLeadingBBtag<RA2bTree>,"J1BB_doubleHiggsTag","leading bb-tag",20,-1.,1.);
  plot J1Tau21plot(*fillLeadingTau21<RA2bTree>,"J1Tau21_doubleHiggsTag","leading #tau_{21}",20,0.,1.);
  plot J1Ptplot(*fillLeadingJetPt<RA2bTree>,"J1Pt_doubleHiggsTag","leading p_{T,J} [GeV]",40,300.,2300.);
  plot J2Mplot(*fillSubLeadingJetMass<RA2bTree>,"J2M_doubleHiggsTag","subleading m_{J} [GeV]",40,50.,250.);
  plot J2BBplot(*fillSubLeadingBBtag<RA2bTree>,"J2BB_doubleHiggsTag","subleading bb-tag",20,-1.,1.);
  plot J2Tau21plot(*fillSubLeadingTau21<RA2bTree>,"J2Tau21_doubleHiggsTag","subleading #tau_{21}",20,0.,1.);
  plot J2Ptplot(*fillSubLeadingJetPt<RA2bTree>,"J2Pt_doubleHiggsTag","subleading p_{T,J} [GeV]",40,300.,2300.);
  plot J1pt_JetFlavorPlot(*fillLeadingJetFlavor<RA2bTree>,"J1pt_JetFlavorPlot_doubleHiggsTag","Jet Flavor",22,0.5,21.5);
  plot J2pt_JetFlavorPlot(*fillSubLeadingJetFlavor<RA2bTree>,"J2pt_JetFlavorPlot_doubleHiggsTag","Jet Flavor",22,0.5,21.5);


  vector<plot> plots;
  plots.push_back(METplot);
  plots.push_back(HTplot);
  plots.push_back(Binsplot);
  plots.push_back(NJetsplot);
  plots.push_back(BTagsplot);
  plots.push_back(DeltaPhi1plot);
  plots.push_back(DeltaPhi2plot);
  plots.push_back(DeltaPhi3plot);
  plots.push_back(DeltaPhi4plot);
  plots.push_back(J1Mplot);
  plots.push_back(J1BBplot);
  plots.push_back(J1Tau21plot);
  plots.push_back(J1Ptplot);
  plots.push_back(J2Mplot);
  plots.push_back(J2BBplot);
  plots.push_back(J2Tau21plot);
  plots.push_back(J2Ptplot);
  plots.push_back(J2pt_JetFlavorPlot);
  plots.push_back(J1pt_JetFlavorPlot);

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
        if(! baselineCut(ntuple) ) continue;
        if(! doubleTaggingLooseCut(ntuple) ) continue;
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
          if(! doubleTaggingLooseCut(ntuple) ) continue;
          if( !genLevelHHcut(ntuple) ) continue;
          for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
              if( skims.signalSampleName[iSample] == "T5HH1300" )
                  plots[iPlot].fillSignal(ntuple,lumi/0.0460525/102482.);
              if( skims.signalSampleName[iSample] == "T5HH1700" )
                  plots[iPlot].fillSignal(ntuple,lumi/0.00470323/103791.);
          }
      }
  }
  
  // Data tree
  RA2bTree* ntuple = skims.dataNtuple;
  for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
    plots[iPlot].addDataNtuple(ntuple,"data");
  }

  int numEvents = ntuple->fChain->GetEntries();
  ntupleBranchStatus<RA2bTree>(ntuple);
  for( int iEvt = 0 ; iEvt < 0/*numEvents*/ ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if(! baselineCut(ntuple) ) continue;
      if(! doubleTaggingLooseCut(ntuple) ) continue;
      if( ntuple->TriggerPass->size() < 44 || ( !ntuple->TriggerPass->at(41) && !ntuple->TriggerPass->at(42) && !ntuple->TriggerPass->at(43) && !ntuple->TriggerPass->at(44)) ) continue;
      if( iEvt % 1000000 == 0 ) cout << "DATA: " << iEvt << "/" << numEvents << endl;
      for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
          plots[iPlot].fillSignal(ntuple);
      }
  }

  for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
      TCanvas* can = new TCanvas("can","can",500,500);
      plots[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_doubleHiggsTag_plots");
  }
}
