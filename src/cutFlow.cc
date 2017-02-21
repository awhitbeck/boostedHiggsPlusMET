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
  typedef bool(*cutFunc)(RA2bTree*);
  vector<cutFunc> cutFlow;
  vector<TString> cutName;
  cutFlow.push_back(*FiltersCut<RA2bTree>);
  cutName.push_back("Filters");
  cutFlow.push_back(*METHTCut<RA2bTree>);
  cutName.push_back("METHT");
  cutFlow.push_back(*DeltaPhi1Cut<RA2bTree>);
  cutName.push_back("DeltaPhi1");
  cutFlow.push_back(*DeltaPhi2Cut<RA2bTree>);
  cutName.push_back("DeltaPhi2");
  cutFlow.push_back(*DeltaPhi3Cut<RA2bTree>);
  cutName.push_back("DeltaPhi3");
  cutFlow.push_back(*DeltaPhi4Cut<RA2bTree>);
  cutName.push_back("DeltaPhi4");
  cutFlow.push_back(*AK8MultCut<RA2bTree>);
  cutName.push_back("AK8Multiplicity");
  cutFlow.push_back(*AK8JetPtCut<RA2bTree>);
  cutName.push_back("JetPt");
  cutFlow.push_back(*AK8JetLooseMassCut<RA2bTree>);
  cutName.push_back("LooseJetMass");
  cutFlow.push_back(*doubleTaggingLooseCut<RA2bTree>);
  cutName.push_back("doubleBBtag");
  cutFlow.push_back(*doubleMassCut<RA2bTree>);
  cutName.push_back("doubleMass");

  //vector<vector<plot> > plots;
  vector<vector<plot> > plots;

  for( int iCut = 0 ; iCut < cutFlow.size() ; iCut++ ){

    vector<plot> tempPlots;
    tempPlots.push_back(plot(*fillMET<RA2bTree>,"MET_"+cutName[iCut],"MET [GeV]",15,300.,1800.));
    tempPlots.push_back(plot(*fillMET<RA2bTree>,"METwide_"+cutName[iCut],"MET [GeV]",18,0.,1800.));
    tempPlots.push_back(plot(*fillHT<RA2bTree>,"HT_"+cutName[iCut],"H_{T} [GeV]",15,300,2800.));
    tempPlots.push_back(plot(*fillLeadingJetMass<RA2bTree>,"J1M_"+cutName[iCut],"leading m_{J} [GeV]",20,50.,200.));
    tempPlots.push_back(plot(*fillLeadingJetMass<RA2bTree>,"J1Mwide_"+cutName[iCut],"leading m_{J} [GeV]",20,0.,200.));
    tempPlots.push_back(plot(*fillLeadingBBtag<RA2bTree>,"J1BB_"+cutName[iCut],"leading bb-tag",20,-1.,1.));
    tempPlots.push_back(plot(*fillLeadingTau21<RA2bTree>,"J1Tau21_"+cutName[iCut],"leading #tau_{21}",20,0.,1.));
    tempPlots.push_back(plot(*fillLeadingJetPt<RA2bTree>,"J1Pt_"+cutName[iCut],"leading p_{T,J} [GeV]",40,300.,2300.));
    tempPlots.push_back(plot(*fillLeadingJetPt<RA2bTree>,"J1PtWide_"+cutName[iCut],"leading p_{T,J} [GeV]",46,0.,2300.));
    tempPlots.push_back(plot(*fillSubLeadingJetMass<RA2bTree>,"J2M_"+cutName[iCut],"subleading m_{J} [GeV]",20,50.,200.));
    tempPlots.push_back(plot(*fillSubLeadingJetMass<RA2bTree>,"J2Mwide_"+cutName[iCut],"subleading m_{J} [GeV]",20,0.,200.));
    tempPlots.push_back(plot(*fillSubLeadingBBtag<RA2bTree>,"J2BB_"+cutName[iCut],"subleading bb-tag",20,-1.,1.));
    tempPlots.push_back(plot(*fillSubLeadingTau21<RA2bTree>,"J2Tau21_"+cutName[iCut],"subleading #tau_{21}",20,0.,1.));
    tempPlots.push_back(plot(*fillSubLeadingJetPt<RA2bTree>,"J2Pt_"+cutName[iCut],"subleading p_{T,J} [GeV]",40,300.,2300.));
    tempPlots.push_back(plot(*fillSubLeadingJetPt<RA2bTree>,"J2PtWide_"+cutName[iCut],"subleading p_{T,J} [GeV]",46,0.,2300.));
    tempPlots.push_back(plot(*fillDeltaPhi1<RA2bTree>,"DeltaPhi1_"+cutName[iCut],"#Delta#Phi_{1}",20,0.,3.1415));
    tempPlots.push_back(plot(*fillDeltaPhi2<RA2bTree>,"DeltaPhi2_"+cutName[iCut],"#Delta#Phi_{2}",20,0.,3.1415));
    tempPlots.push_back(plot(*fillDeltaPhi3<RA2bTree>,"DeltaPhi3_"+cutName[iCut],"#Delta#Phi_{3}",20,0.,3.1415));
    tempPlots.push_back(plot(*fillDeltaPhi4<RA2bTree>,"DeltaPhi4_"+cutName[iCut],"#Delta#Phi_{4}",20,0.,3.1415));

    plots.push_back(tempPlots);
  }

  // background MC samples
  for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

    RA2bTree* ntuple = skims.ntuples[iSample];

    for( int iCut = 0 ; iCut < plots.size() ; iCut++){
      for( int iPlot = 0 ; iPlot < plots[iCut].size() ; iPlot++){
          plots[iCut][iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
          plots[iCut][iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
          plots[iCut][iPlot].dataHist=0;
      }
    }

    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){

        if( skims.sampleName[iSample] != "TT" && iEvt > 1000 ) continue;
      ntuple->GetEntry(iEvt);
      if( iEvt % 100000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      for( int iCut = 0 ; iCut < cutFlow.size() ; iCut++ ){
	if( ! cutFlow[iCut](ntuple) ) break;
	for( int iPlot = 0 ; iPlot < plots[iCut].size() ; iPlot++ ){
        plots[iCut][iPlot].fill(ntuple,1.);
	}
      }
    }
  }

  // Signal samples
  for( int iSample = 0 ; iSample < skims.signalNtuples.size() ; iSample++){

    RA2bTree* ntuple = skims.signalNtuples[iSample];
    for( int iCut = 0 ; iCut < cutFlow.size() ; iCut++){
      for( int iPlot = 0 ; iPlot < plots[iCut].size() ; iPlot++){
	plots[iCut][iPlot].addSignalNtuple(ntuple,skims.signalSampleName[iSample]);
	plots[iCut][iPlot].setLineColor(ntuple,skims.lineColor[iSample]);
      }
    }

    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){


        if( iEvt > 1000 ) continue;

      ntuple->GetEntry(iEvt);
      if( iEvt % 100000 == 0 ) cout << skims.signalSampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      for( int iCut = 0 ; iCut < cutFlow.size() ; iCut++ ){
	if( ! cutFlow[iCut](ntuple) ) break;
	for( int iPlot = 0 ; iPlot < plots[iCut].size() ; iPlot++ ){
        if( skims.signalSampleName[iSample] == "T5HH1300" )
            plots[iCut][iPlot].fillSignal(ntuple,1.0);//lumi*0.0460525/numEvents);
        if( skims.signalSampleName[iSample] == "T5HH1700" )
            plots[iCut][iPlot].fillSignal(ntuple,1.0);//lumi*0.00470323/numEvents);
	}
      }
    }
  }

  /*
  for( int iCut = 0 ; iCut < cutFlow.size() ; iCut++ ){
    for( int iPlot = 0 ; iPlot < plots[iCut].size() ; iPlot++){
      TCanvas* can = new TCanvas("can","can",500,500);
      plots[iCut][iPlot].DrawNoRatio(can,skims.ntuples,skims.signalNtuples,"../plots/cutFlow_plots");
    }
  }
  */

  for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){ 
    cout << " & All Bkg. " << endl;
    RA2bTree* ntuple = skims.ntuples[iSample];
    cout << " & " << skims.sampleName[iSample] ; 
  }
  for( int iSample = 0 ; iSample < skims.signalNtuples.size() ; iSample++){
    RA2bTree* ntuple = skims.signalNtuples[iSample];
    cout << " & " << skims.signalSampleName[iSample] ;
  }
  cout << endl;
  cout << "% ------------------------------------------------------------------" << endl;
  for( int iCut = 0 ; iCut < cutFlow.size() ; iCut++ ){
    plots[iCut][0].buildSum();
    cout << cutName[iCut] << " & " << plots[iCut][0].sum->Integral();
    for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){ 
      RA2bTree* ntuple = skims.ntuples[iSample];
      cout << " & " << plots[iCut][0].histoMap[ntuple]->Integral() ;
    }
    for( int iSample = 0 ; iSample < skims.signalNtuples.size() ; iSample++){
      RA2bTree* ntuple = skims.signalNtuples[iSample];
      cout << " & " << plots[iCut][0].signalHistoMap[ntuple]->Integral() ;
    }
    cout << endl;
  }

}
