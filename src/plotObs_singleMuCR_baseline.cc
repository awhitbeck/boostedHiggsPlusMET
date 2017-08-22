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

///////////////////////////////////////////
// 21 HLT_Mu15_IsoVVVL_PFHT350_PFMET50_v //
// 22 HLT_Mu15_IsoVVVL_PFHT350_v         //
// 23 HLT_Mu15_IsoVVVL_PFHT400_v5        //
// 24 HLT_Mu15_IsoVVVL_PFHT600_v8        //
// 28 HLT_Mu50_IsoVVVL_PFHT400_v5        //
///////////////////////////////////////////

int main(int argc, char** argv){
    
  bool looseCuts(false);
  int MAX_EVENTS(99999999);
  if( argc >= 2 )
      looseCuts = atoi(argv[1]);    
  if( argc >= 3 )
      MAX_EVENTS = atoi(argv[2]);

  gROOT->ProcessLine(".L tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");
  
  typedef bool(*cuts)(RA2bTree*);
  vector<cuts> baselineCuts;

  if( looseCuts ){
      baselineCuts.push_back(*FiltersCut<RA2bTree>);
      baselineCuts.push_back(*singleMuCut<RA2bTree>);
      baselineCuts.push_back(*lowDPhiCuts<RA2bTree>);
      baselineCuts.push_back(*METHTsingleLeptonCut<RA2bTree>);
      //baselineCuts.push_back(*AK8MultCut<RA2bTree>);
      baselineCuts.push_back(*AK8JetLooseMassCut<RA2bTree>);  
  }else{
      baselineCuts.push_back(*singleMuBaselineCut<RA2bTree>);
  }

  cout << "baseline cuts size : " << baselineCuts.size() << endl;

  skimSamples skims(skimSamples::kSLm);
  typedef plot<RA2bTree> plot;

  plot METplot(*fillMET<RA2bTree>,"MET_singleMuCR_baseline","MET [GeV]",21,100.,800.);
  plot HTplot(*fillHT<RA2bTree>,"HT_singleMuCR_baseline","H_{T} [GeV]",17,300,2000.);
  plot MTplot(*computeMuonMT<RA2bTree>,"MT_singleMuCR_baseline","M_{T} [GeV]",30,0,300.);
  plot NJetsplot(*fillNJets<RA2bTree>,"NJets_singleMuCR_baseline","n_{j}",14,1.5,15.5);
  plot BTagsplot(*fillBTags<RA2bTree>,"BTags_singleMuCR_baseline","n_{b}",6,-0.5,5.5);
  plot Binsplot(*fillAnalysisBins<RA2bTree>,"AnalysisBins_singleMuCR_baseline","i^th Bin",8,0.5,8.5);

  plot DeltaPhi1plot(*fillDeltaPhi1<RA2bTree>,"DeltaPhi1_singleMuCR_baseline","#Delta#Phi_{1}",20,0,3.1415);
  plot DeltaPhi2plot(*fillDeltaPhi2<RA2bTree>,"DeltaPhi2_singleMuCR_baseline","#Delta#Phi_{2}",20,0,3.1415);
  plot DeltaPhi3plot(*fillDeltaPhi3<RA2bTree>,"DeltaPhi3_singleMuCR_baseline","#Delta#Phi_{3}",20,0,3.1415);
  plot DeltaPhi4plot(*fillDeltaPhi4<RA2bTree>,"DeltaPhi4_singleMuCR_baseline","#Delta#Phi_{4}",20,0,3.1415);

  plot Ak4JetPt1(*fillJetPt1<RA2bTree>,"Ak4JetPt1_singleMuCR_baseline","p_{T,j1} [GeV]",40,0,600);
  plot Ak4JetPt2(*fillJetPt2<RA2bTree>,"Ak4JetPt2_singleMuCR_baseline","p_{T,j2} [GeV]",40,0,600);
  plot Ak4JetPt3(*fillJetPt3<RA2bTree>,"Ak4JetPt3_singleMuCR_baseline","p_{T,j3} [GeV]",40,0,600);
  plot Ak4JetPt4(*fillJetPt4<RA2bTree>,"Ak4JetPt4_singleMuCR_baseline","p_{T,j4} [GeV]",40,0,600);

  plot J2NbhadronPlot(*fillLeadingNbHadrons<RA2bTree>,"J1pt_numBhadrons_baseline","n_{b-had}",5,-0.5,4.5);
  plot J1NbhadronPlot(*fillSubLeadingNbHadrons<RA2bTree>,"J2pt_numBhadrons_baseline","n_{b-had}",5,-0.5,4.5);

  vector<plot> LeadingBBdiscVersusNbHad;
  TString binLabel;
  for( int i=0; i<5 ; i++){    
      binLabel="";
      binLabel+=i;
      LeadingBBdiscVersusNbHad.push_back(plot(*fillLeadingBBtag<RA2bTree>,"J1pt_BBtag_singleMuCR_NbHad"+binLabel,"bb-disc",20,-1,1));
  }
  vector<plot> SubLeadingBBdiscVersusNbHad;
  for( int i=0; i<5 ; i++){    
      binLabel="";
      binLabel+=i;
      SubLeadingBBdiscVersusNbHad.push_back(plot(*fillSubLeadingBBtag<RA2bTree>,"J2pt_BBtag_singleMuCR_NbHad"+binLabel,"bb-disc",20,-1,1));
  }
  vector<plot> HTversusNJetsplots;
  for( int i=0; i<14 ; i++){
      binLabel="";
      binLabel+=i;
      HTversusNJetsplots.push_back(plot(*fillHT<RA2bTree>,"HT_singleMuCR_HT"+binLabel,"H_{T} [GeV]",15,300,2800.));
  }
  
  plot J1dR_Massplot(*leadJetMuondR_mass<RA2bTree>,"J1dR_Mass_singleMuCR_baseline","m_{J} [GeV]",20,50.,250.);
  plot J2dR_Massplot(*subleadJetMuondR_mass<RA2bTree>,"J2dR_Mass_singleMuCR_baseline","m_{J} [GeV]",20,50.,250.);
  plot J1dR_BBplot(*leadJetMuondR_bbdisc<RA2bTree>,"J1dR_BBdisc_singleMuCR_baseline","bb-disc",20,-1.,1.);
  plot J2dR_BBplot(*subleadJetMuondR_bbdisc<RA2bTree>,"J2dR_BBdisc_singleMuCR_baseline","bb-disc",20,-1.,1.);

  plot J1pt_dRplot(*muonLeadJetdR<RA2bTree>,"J1pt_dRleptonJet_singleMuCR_baseline","#DeltaR ",40,0.,2*3.1415);
  plot J2pt_dRplot(*muonSubleadJetdR<RA2bTree>,"J2pt_dRleptonJet_singleMuCR_baseline","#DeltaR ",40,0.,2*3.1415);

  plot J1pt_Massplot(*fillLeadingJetMass<RA2bTree>,"J1pt_Mass_singleMuCR_baseline","m_{J} [GeV]",20,50.,250.);
  plot J2pt_Massplot(*fillSubLeadingJetMass<RA2bTree>,"J2pt_Mass_singleMuCR_baseline","m_{J} [GeV]",20,50.,250.);
  plot J1pt_MassLooseplot(*fillLeadingJetMass<RA2bTree>,"J1pt_MassLoose_singleMuCR_baseline","m_{J} [GeV]",50,0.,250.);
  plot J2pt_MassLooseplot(*fillSubLeadingJetMass<RA2bTree>,"J2pt_MassLoose_singleMuCR_baseline","m_{J} [GeV]",50,0.,250.);
  plot J1bbtag_Massplot(*fillLeadingBBtagJetMass<RA2bTree>,"J1bbtag_Mass_singleMuCR_baseline","m_{J} [GeV]",20,50.,200.);
  plot J2bbtag_Massplot(*fillSubLeadingBBtagJetMass<RA2bTree>,"J2bbtag_Mass_singleMuCR_baseline","m_{J} [GeV]",20,50.,200.);

  plot J1pt_BBplot(*fillLeadingBBtag<RA2bTree>,"J1pt_BBtag_singleMuCR_baseline","bb-disc",20,-1.,1.);
  plot J2pt_BBplot(*fillSubLeadingBBtag<RA2bTree>,"J2pt_BBtag_singleMuCR_baseline","bb-disc",20,-1.,1.);
  plot J1bbtag_BBplot(*fillLeadingBBtagJetBBtag<RA2bTree>,"J1bbtag_BBtag_singleMuCR_baseline","bb-disc",20,-1.,1.);
  plot J2bbtag_BBplot(*fillSubLeadingBBtagJetBBtag<RA2bTree>,"J2bbtag_BBtag_singleMuCR_baseline","bb-disc",20,-1.,1.);

  plot J1pt_Tau21plot(*fillLeadingTau21<RA2bTree>,"J1pt_Tau21_singleMuCR_baseline","#tau_{21}",20,0.,1.);
  plot J2pt_Tau21plot(*fillSubLeadingTau21<RA2bTree>,"J2pt_Tau21_singleMuCR_baseline","#tau_{21}",20,0.,1.);
  plot J1bbtag_Tau21plot(*fillLeadingBBtagJetTau21<RA2bTree>,"J1bbtag_Tau21_singleMuCR_baseline","#tau_{21}",20,0.,1.);
  plot J2bbtag_Tau21plot(*fillSubLeadingBBtagJetTau21<RA2bTree>,"J2bbtag_Tau21_singleMuCR_baseline","#tau_{21}",20,0.,1.);

  plot J1pt_Ptplot(*fillLeadingJetPt<RA2bTree>,"J1pt_Pt_singleMuCR_baseline","p_{T,J} [GeV]",50,300.,1300.);
  plot J2pt_Ptplot(*fillSubLeadingJetPt<RA2bTree>,"J2pt_Pt_singleMuCR_baseline","p_{T,J} [GeV]",50,300.,1300.);
  plot J1pt_PtLooseplot(*fillLeadingJetPt<RA2bTree>,"J1pt_PtLoose_singleMuCR_baseline","p_{T,J} [GeV]",50,0.,1300.);
  plot J2pt_PtLooseplot(*fillSubLeadingJetPt<RA2bTree>,"J2pt_PtLoose_singleMuCR_baseline","p_{T,J} [GeV]",50,0.,1300.);
  plot J1bbtag_Ptplot(*fillLeadingBBtagJetPt<RA2bTree>,"J1bbtag_Pt_singleMuCR_baseline","p_{T,J} [GeV]",50,0.,1300.);
  plot J2bbtag_Ptplot(*fillSubLeadingBBtagJetPt<RA2bTree>,"J2bbtag_Pt_singleMuCR_baseline","p_{T,J} [GeV]",50,300.,1300.);

  plot J1pt_JetFlavorPlot(*fillLeadingJetFlavor<RA2bTree>,"J1pt_JetFlavorPlot","Jet Flavor",22,0.5,21.5);
  plot J2pt_JetFlavorPlot(*fillSubLeadingJetFlavor<RA2bTree>,"J2pt_JetFlavorPlot","Jet Flavor",22,0.5,21.5);

  plot leptonDRj1Plot(*muonLeadJetdR<RA2bTree>,"muonLeadJetdR","#Delta R(#mu ,j1)",20,0.0,5.0);
  plot leptonDRj2Plot(*muonSubleadJetdR<RA2bTree>,"muonLeadJetdR","#Delta R(#mu ,j1)",20,0.0,5.0);
  plot leptonPtPlot(*fillLepPt<RA2bTree>,"muonPt","p_{T,#mu} [GeV]",40,0.,240.);
  plot leptonEtaPlot(*fillLepEta<RA2bTree>,"muonEta","#eta_{#mu}",20,-3.,3.);

  vector<plot> plots;
  plots.push_back(Ak4JetPt1);
  plots.push_back(Ak4JetPt2);
  plots.push_back(Ak4JetPt3);
  plots.push_back(Ak4JetPt4);
  plots.push_back(J1NbhadronPlot);
  plots.push_back(J2NbhadronPlot);
  plots.push_back(leptonDRj1Plot);
  plots.push_back(leptonDRj2Plot);
  plots.push_back(leptonPtPlot);
  plots.push_back(leptonEtaPlot);
  plots.push_back(METplot);
  plots.push_back(HTplot);
  plots.push_back(MTplot);
  plots.push_back(NJetsplot);
  plots.push_back(BTagsplot);
  plots.push_back(Binsplot);
  plots.push_back(DeltaPhi1plot);
  plots.push_back(DeltaPhi2plot);
  plots.push_back(DeltaPhi3plot);
  plots.push_back(DeltaPhi4plot);
  plots.push_back(J1dR_Massplot);
  plots.push_back(J2dR_Massplot);
  plots.push_back(J1dR_BBplot);
  plots.push_back(J2dR_BBplot);
  plots.push_back(J1pt_dRplot);
  plots.push_back(J2pt_dRplot);
  plots.push_back(J1pt_Massplot);
  plots.push_back(J2pt_Massplot);
  plots.push_back(J1pt_MassLooseplot);
  plots.push_back(J2pt_MassLooseplot);
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
  plots.push_back(J1pt_PtLooseplot);
  plots.push_back(J2pt_PtLooseplot);
  plots.push_back(J1bbtag_Ptplot);
  plots.push_back(J2bbtag_Ptplot);
  plots.push_back(J1pt_JetFlavorPlot);
  plots.push_back(J2pt_JetFlavorPlot);

  // background MC samples
  for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

    RA2bTree* ntuple = skims.ntuples[iSample];

    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
      plots[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
      plots[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
      plots[iPlot].setLineColor(ntuple,skims.lineColor[iSample]);
    }
    for( int iPlot = 0 ; iPlot < HTversusNJetsplots.size() ; iPlot++){
        HTversusNJetsplots[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
        HTversusNJetsplots[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        HTversusNJetsplots[iPlot].setLineColor(ntuple,skims.lineColor[iSample]);
    }
    for( int iPlot = 0 ; iPlot < LeadingBBdiscVersusNbHad.size() ; iPlot++){
        LeadingBBdiscVersusNbHad[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
        LeadingBBdiscVersusNbHad[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        LeadingBBdiscVersusNbHad[iPlot].setLineColor(ntuple,skims.lineColor[iSample]);
    }
    for( int iPlot = 0 ; iPlot < SubLeadingBBdiscVersusNbHad.size() ; iPlot++){
        SubLeadingBBdiscVersusNbHad[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
        SubLeadingBBdiscVersusNbHad[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        SubLeadingBBdiscVersusNbHad[iPlot].setLineColor(ntuple,skims.lineColor[iSample]);
    }

    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    int iBin=0;
    double weight=0.;
    bool passBaseline;
    TString filename;
    for( int iEvt = 0 ; iEvt < min(numEvents,MAX_EVENTS) ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 1000000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      //if( iEvt > 100000 ) break;

      filename = ntuple->fChain->GetFile()->GetName();
      if( ( filename.Contains("SingleLept") || filename.Contains("DiLept") ) && ntuple->madHT>600. )continue;

      passBaseline=true;
      for( int i = 0 ; i < baselineCuts.size() ; i++ ){
          passBaseline&=baselineCuts[i](ntuple);
      }
      if( ! passBaseline ) continue;

      weight = ntuple->Weight*lumi*customPUweights(ntuple)*singleMuonTrigWeights(ntuple);
      //if( skims.sampleName[iSample] == "TT" )
      //    weight *= ISRweights(ntuple);
      for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++ ){
          iBin=plots[iPlot].fill(ntuple,weight);
          if( plots[iPlot].label == "NJets_singleMuCR_baseline" && iBin>0 && iBin <=14 )
              HTversusNJetsplots[iBin-1].fill(ntuple,weight);
          if( plots[iPlot].label == "J1pt_numBhadrons_baseline" && iBin > 0 && iBin <= 5 ){
              LeadingBBdiscVersusNbHad[iBin-1].fill(ntuple,weight);
          }
          if( plots[iPlot].label == "J2pt_numBhadrons_baseline" && iBin > 0 && iBin <= 5 )
              SubLeadingBBdiscVersusNbHad[iBin-1].fill(ntuple,weight);
      }
    }
  }

  /*
  // Signal samples
  for( int iSample = 0 ; iSample < skims.signalNtuples.size() ; iSample++){

    RA2bTree* ntuple = skims.signalNtuples[iSample];
    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
      plots[iPlot].addSignalNtuple(ntuple,skims.signalSampleName[iSample]);
      plots[iPlot].setLineColor(ntuple,skims.sigLineColor[iSample]);
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
  for( int iPlot = 0 ; iPlot < HTversusNJetsplots.size() ; iPlot++){
      HTversusNJetsplots[iPlot].addDataNtuple(ntuple,"data");
  }
  for( int iPlot = 0 ; iPlot < LeadingBBdiscVersusNbHad.size() ; iPlot++){
      LeadingBBdiscVersusNbHad[iPlot].addDataNtuple(ntuple,"data");
  }
  for( int iPlot = 0 ; iPlot < SubLeadingBBdiscVersusNbHad.size() ; iPlot++){
      SubLeadingBBdiscVersusNbHad[iPlot].addDataNtuple(ntuple,"data");
  }
  
  int numEvents = ntuple->fChain->GetEntries();
  ntupleBranchStatus<RA2bTree>(ntuple);
  int iBin = 0 ;
  bool passBaseline;
  for( int iEvt = 0 ; iEvt < min(numEvents,MAX_EVENTS) ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 1000000 == 0 ) cout << "data: " << iEvt << "/" << numEvents << endl;
      
      passBaseline=true;
      for( int i = 0 ; i < baselineCuts.size() ; i++ ){
          passBaseline&=baselineCuts[i](ntuple);
      }
      if( ! passBaseline ) continue;

      if( singleMuTriggerCut(ntuple) ){
          for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
              iBin = plots[iPlot].fillData(ntuple);
              if( plots[iPlot].label == "NJets_singleMuCR_baseline" && iBin>0 && iBin <=14 )
                  HTversusNJetsplots[iBin-1].fillData(ntuple);
              if( plots[iPlot].label == "J1pt_numBhadrons_baseline" && iBin > 0 && iBin <= 5 )
                  LeadingBBdiscVersusNbHad[iBin-1].fillData(ntuple);
              if( plots[iPlot].label == "J2pt_numBhadrons_baseline" && iBin > 0 && iBin <= 5 )
                  SubLeadingBBdiscVersusNbHad[iBin-1].fillData(ntuple);
          }
      }
  }

  TFile* outputFile = new TFile("plotObs_singleMuCR_baseline"+(looseCuts?TString("_looseCuts"):TString(""))+".root","RECREATE");

  for( int iPlot = 0 ; iPlot < HTversusNJetsplots.size() ; iPlot++){
      HTversusNJetsplots[iPlot].buildSum();
      HTversusNJetsplots[iPlot].Write();
      HTversusNJetsplots[iPlot].sum->Write();
      TCanvas* can = new TCanvas("can","can",500,500);
      can->SetTopMargin(0.05);
      HTversusNJetsplots[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_singleMuCR_baseline_"+(looseCuts?TString("looseCuts_"):TString(""))+"plots",0.1,2.0,true);
  }
  for( int iPlot = 0 ; iPlot < LeadingBBdiscVersusNbHad.size() ; iPlot++){
      LeadingBBdiscVersusNbHad[iPlot].buildSum();
      LeadingBBdiscVersusNbHad[iPlot].Write();
      LeadingBBdiscVersusNbHad[iPlot].sum->Write();
      TCanvas* can = new TCanvas("can","can",500,500);
      can->SetTopMargin(0.05);
      LeadingBBdiscVersusNbHad[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_singleMuCR_baseline_"+(looseCuts?TString("looseCuts_"):TString(""))+"plots",0.1,2.0,true);
  }
  for( int iPlot = 0 ; iPlot < SubLeadingBBdiscVersusNbHad.size() ; iPlot++){
      SubLeadingBBdiscVersusNbHad[iPlot].buildSum();
      SubLeadingBBdiscVersusNbHad[iPlot].Write();
      SubLeadingBBdiscVersusNbHad[iPlot].sum->Write();
      TCanvas* can = new TCanvas("can","can",500,500);
      can->SetTopMargin(0.05);
      SubLeadingBBdiscVersusNbHad[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_singleMuCR_baseline_"+(looseCuts?TString("looseCuts_"):TString(""))+"plots",0.1,2.0,true);
  }
  for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
      plots[iPlot].Write();
      TCanvas* can = new TCanvas("can","can",500,500);
      can->SetTopMargin(0.05);
      plots[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_singleMuCR_baseline_"+(looseCuts?TString("looseCuts_"):TString(""))+"plots",0.1,2.0,true);
  }
}
