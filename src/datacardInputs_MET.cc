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

  TFile* outputFile = new TFile("datacardInputs_MET.root","RECREATE");
  TCanvas* can = new TCanvas("can","can",500,500);
  for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
    plots[iPlot].buildSum();
    plots[iPlot].Draw(can,skims.ntuples,skims.signalNtuples);
    outputFile->cd();
    plots[iPlot].Write();
  }
  outputFile->Close();

  TCanvas* canClosure = new TCanvas("canClosure","canClosure",800,400);
  canClosure->Divide(2,1);
  canClosure->cd(1);
  TH1F* prediction = new TH1F(*(plots[1].sum));
  prediction->SetNameTitle("prediction","prediction");
  prediction->Multiply(plots[2].sum);
  for( int iBin = 1 ; iBin < prediction->GetNbinsX() ; iBin++ ){
    if( plots[3].sum->GetBinContent(iBin) == 0 )
      prediction->SetBinContent(iBin,prediction->GetBinContent(iBin)/0.00001);
    else
      prediction->SetBinContent(iBin,prediction->GetBinContent(iBin)/plots[3].sum->GetBinContent(iBin));
  }
  prediction->Draw("histo,e1");
  plots[0].sum->Draw("e3,SAME");
  canClosure->cd(2);
  TH1F* closure = new TH1F(*prediction);
  closure->SetNameTitle("closure","closure");
  for( int iBin = 1 ; iBin < prediction->GetNbinsX() ; iBin++ ){
    if( plots[0].sum->GetBinContent(iBin) == 0 )
      closure->SetBinContent(iBin,closure->GetBinContent(iBin)/0.00001);
    else
      closure->SetBinContent(iBin,closure->GetBinContent(iBin)/plots[0].sum->GetBinContent(iBin));
  }
  closure->Draw("e1");
  canClosure->SaveAs("METbinning_closure.png");

}
