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

  gROOT->ProcessLine(".L tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");
  
  skimSamples skims(skimSamples::kSLe);
  typedef plot<RA2bTree> plot;

  plot METplot(*fillMET<RA2bTree>,"MET_singleEleCR_baseline","MET [GeV]",21,100.,800.);
  plot HTplot(*fillHT<RA2bTree>,"HT_singleEleCR_baseline","H_{T} [GeV]",17,300,2000.);
  plot NJetsplot(*fillNJets<RA2bTree>,"NJets_singleEleCR_baseline","n_{j}",14,1.5,15.5);
  plot BTagsplot(*fillBTags<RA2bTree>,"BTags_singleEleCR_baseline","n_{b}",6,-0.5,5.5);
  plot Binsplot(*fillAnalysisBins<RA2bTree>,"AnalysisBins_singleEleCR_baseline","i^th Bin",8,0.5,8.5);

  plot J1dR_Massplot(*leadJetMuondR_mass<RA2bTree>,"J1dR_Mass_singleEleCR_baseline","m_{J} [GeV]",20,50.,250.);
  plot J2dR_Massplot(*subleadJetMuondR_mass<RA2bTree>,"J2dR_Mass_singleEleCR_baseline","m_{J} [GeV]",20,50.,250.);
  plot J1dR_BBplot(*leadJetMuondR_bbdisc<RA2bTree>,"J1dR_BBdisc_singleEleCR_baseline","bb-disc",20,-1.,1.);
  plot J2dR_BBplot(*subleadJetMuondR_bbdisc<RA2bTree>,"J2dR_BBdisc_singleEleCR_baseline","bb-disc",20,-1.,1.);

  plot J1pt_dRplot(*muonLeadJetdR<RA2bTree>,"J1pt_dRleptonJet_singleEleCR_baseline","#DeltaR ",40,0.,2*3.1415);
  plot J2pt_dRplot(*muonSubleadJetdR<RA2bTree>,"J2pt_dRleptonJet_singleEleCR_baseline","#DeltaR ",40,0.,2*3.1415);

  plot J1pt_Massplot(*fillLeadingJetMass<RA2bTree>,"J1pt_Mass_singleEleCR_baseline","m_{J} [GeV]",20,50.,200.);
  plot J2pt_Massplot(*fillSubLeadingJetMass<RA2bTree>,"J2pt_Mass_singleEleCR_baseline","m_{J} [GeV]",20,50.,200.);
  plot J1bbtag_Massplot(*fillLeadingBBtagJetMass<RA2bTree>,"J1bbtag_Mass_singleEleCR_baseline","m_{J} [GeV]",20,50.,200.);
  plot J2bbtag_Massplot(*fillSubLeadingBBtagJetMass<RA2bTree>,"J2bbtag_Mass_singleEleCR_baseline","m_{J} [GeV]",20,50.,200.);

  plot J1pt_BBplot(*fillLeadingBBtag<RA2bTree>,"J1pt_BBtag_singleEleCR_baseline","bb-disc",20,-1.,1.);
  plot J2pt_BBplot(*fillSubLeadingBBtag<RA2bTree>,"J2pt_BBtag_singleEleCR_baseline","bb-disc",20,-1.,1.);
  plot J1bbtag_BBplot(*fillLeadingBBtagJetBBtag<RA2bTree>,"J1bbtag_BBtag_singleEleCR_baseline","bb-disc",20,-1.,1.);
  plot J2bbtag_BBplot(*fillSubLeadingBBtagJetBBtag<RA2bTree>,"J2bbtag_BBtag_singleEleCR_baseline","bb-disc",20,-1.,1.);

  plot J1pt_Tau21plot(*fillLeadingTau21<RA2bTree>,"J1pt_Tau21_singleEleCR_baseline","#tau_{21}",20,0.,1.);
  plot J2pt_Tau21plot(*fillSubLeadingTau21<RA2bTree>,"J2pt_Tau21_singleEleCR_baseline","#tau_{21}",20,0.,1.);
  plot J1bbtag_Tau21plot(*fillLeadingBBtagJetTau21<RA2bTree>,"J1bbtag_Tau21_singleEleCR_baseline","#tau_{21}",20,0.,1.);
  plot J2bbtag_Tau21plot(*fillSubLeadingBBtagJetTau21<RA2bTree>,"J2bbtag_Tau21_singleEleCR_baseline","#tau_{21}",20,0.,1.);

  plot J1pt_Ptplot(*fillLeadingJetPt<RA2bTree>,"J1pt_Pt_singleEleCR_baseline","p_{T,J} [GeV]",50,100.,1300.);
  plot J2pt_Ptplot(*fillSubLeadingJetPt<RA2bTree>,"J2pt_Pt_singleEleCR_baseline","p_{T,J} [GeV]",50,100.,900.);
  plot J1bbtag_Ptplot(*fillLeadingBBtagJetPt<RA2bTree>,"J1bbtag_Pt_singleEleCR_baseline","p_{T,J} [GeV]",50,100.,1300.);
  plot J2bbtag_Ptplot(*fillSubLeadingBBtagJetPt<RA2bTree>,"J2bbtag_Pt_singleEleCR_baseline","p_{T,J} [GeV]",50,100.,1300.);

  plot J1pt_JetFlavorPlot(*fillLeadingJetFlavor<RA2bTree>,"J1pt_JetFlavorPlot","Jet Flavor",22,0.5,21.5);
  plot J2pt_JetFlavorPlot(*fillSubLeadingJetFlavor<RA2bTree>,"J2pt_JetFlavorPlot","Jet Flavor",22,0.5,21.5);

  plot leptonPtPlot(*fillLepPt<RA2bTree>,"leptonPtPlot","lepton p_{T} [GeV]",40,0.,200.);
  plot leptonEtaPlot(*fillLepEta<RA2bTree>,"leptonEtaPlot","lepton #eta",20,-5.,5.);

  vector<plot> plots;
  plots.push_back(METplot);
  plots.push_back(HTplot);
  plots.push_back(NJetsplot);
  plots.push_back(BTagsplot);
  plots.push_back(Binsplot);
  plots.push_back(J1dR_Massplot);
  plots.push_back(J2dR_Massplot);
  plots.push_back(J1dR_BBplot);
  plots.push_back(J2dR_BBplot);
  plots.push_back(J1pt_dRplot);
  plots.push_back(J2pt_dRplot);
  plots.push_back(J1pt_Massplot);
  plots.push_back(J2pt_Massplot);
  plots.push_back(J1bbtag_Massplot);
  plots.push_back(J2bbtag_Massplot);
  plots.push_back(J1pt_BBplot);
  plots.push_back(J2pt_BBplot);
  plots.push_back(J1bbtag_BBplot);
  plots.push_back(J2bbtag_BBplot);
  plots.push_back(J1pt_Tau21plot);
  plots.push_back(J2pt_Tau21plot);
  plots.push_back(J1bbtag_Tau21plot);
  plots.push_back(J2bbtag_Tau21plot);
  plots.push_back(J1pt_Ptplot);
  plots.push_back(J2pt_Ptplot);
  plots.push_back(J1bbtag_Ptplot);
  plots.push_back(J2bbtag_Ptplot);
  plots.push_back(J1pt_JetFlavorPlot);
  plots.push_back(J2pt_JetFlavorPlot);
  plots.push_back(leptonPtPlot);
  plots.push_back(leptonEtaPlot);

  // background MC samples
  for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

    RA2bTree* ntuple = skims.ntuples[iSample];

    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
      plots[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
      plots[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
      plots[iPlot].setLineColor(ntuple,skims.lineColor[iSample]);
    }

    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    double weight=0.;
    TString filename;
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 1000000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      
filename = ntuple->fChain->GetFile()->GetName();
      if( ( filename.Contains("SingleLept") || filename.Contains("DiLept") ) && ntuple->madHT>600. )continue;

      if(! singleEleBaselineCut(ntuple) ) continue;
      weight = ntuple->Weight*lumi*customPUweights(ntuple)*singleElectronTrigWeights(ntuple);
      if( skims.sampleName[iSample] == "TT" )
          weight *= ISRweights(ntuple);
      if( skims.sampleName[iSample] == "WJets" ){
          weight *= WJetsNLOWeights(ntuple);
          //cout << "WJets NLO weight: " << WJetsNLOWeights(ntuple) << endl;
      }
      for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++ ){
          plots[iPlot].fill(ntuple,weight);
      }
    }
  }

  /*
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
      if(! singleMuBaselineCut(ntuple) ) continue;
      for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
	plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*ntuple->puWeight);
      }
    }
  }
  */

  // Data samples
  RA2bTree* ntuple = skims.dataNtuple;
  for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
    plots[iPlot].addDataNtuple(ntuple,"data");
  }

  int numEvents = ntuple->fChain->GetEntries();
  ntupleBranchStatus<RA2bTree>(ntuple);
  for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 1000000 == 0 ) cout << "data: " << iEvt << "/" << numEvents << endl;
      if(! singleEleBaselineCut(ntuple) ) continue;
      if( singleEleTriggerCut(ntuple) ){
          for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
              plots[iPlot].fillData(ntuple);
          }
      }
  }
  
  for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
      TCanvas* can = new TCanvas("can","can",500,500);
      can->SetTopMargin(0.05);
      plots[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_singleEleCR_baseline_plots",0.1,2.0,true);
  }
}
