#include "TString.h"
#include "TChain.h"
#include "TH1F.h"
#include "TROOT.h"
#include "THStack.h"
#include "TPad.h"
#include "TLegend.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"

#include <vector>
#include <map>
#include <iostream>
#include <cstdio>

#include "plotterUtils.cc"
#include "skimSamples.cc"
#include "definitions.cc"

using namespace std;

//void plotter(){
int main(int argc, char** argv){

  gROOT->ProcessLine(".L ~/tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");

  skimSamples skims;
  for( int i = 0 ; i < skims.sampleName.size() ; i++ ){
    if( skims.sampleName[i] == "TT" ){
      skims.ntuples.erase(skims.ntuples.begin()+i);
      skims.sampleName.erase(skims.sampleName.begin()+i);
      skims.fillColor.erase(skims.fillColor.begin()+i);
    }
  }

  double (*arbitrationFunc)(heppySkimTree*) = *fillSubLeadingJetMass;

  plot tagSR_versusMET(*fillMET,"tagSR_versusMET","E_{T}^{miss} [GeV]",10,300.,1300.);
  plot tagSB_versusMET(*fillMET,"tagSB_versusMET","E_{T}^{miss} [GeV]",10,300.,1300.);
  plot antitagSR_versusMET(*fillMET,"antitagSR_versusMET","E_{T}^{miss} [GeV]",10,300.,1300.);
  plot antitagSB_versusMET(*fillMET,"antitagSB_versusMET","E_{T}^{miss} [GeV]",10,300.,1300.);

  // MC backgrounds
  for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

    heppySkimTree* ntuple = skims.ntuples[iSample];
    tagSR_versusMET.addNtuple(ntuple,skims.sampleName[iSample]);
    tagSB_versusMET.addNtuple(ntuple,skims.sampleName[iSample]);
    antitagSR_versusMET.addNtuple(ntuple,skims.sampleName[iSample]);
    antitagSB_versusMET.addNtuple(ntuple,skims.sampleName[iSample]);

    int numEvents = ntuple->fChain->GetEntries();
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 1000000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      if(!baselineCut(ntuple)) continue; 
      if( taggingCut(ntuple) ){
	double testMass = arbitrationFunc(ntuple);
	if( testMass > 85. && testMass < 135. ){ 
	  tagSR_versusMET.fill(ntuple);
	}else if( testMass > 50. && testMass < 200. ){
	  tagSB_versusMET.fill(ntuple);
	}
      }
      if( antiTaggingCut(ntuple) ){
	double testMass = arbitrationFunc(ntuple);
	if( testMass > 85. && testMass < 135. ){ 
	  antitagSR_versusMET.fill(ntuple);
	}else if( testMass > 50. && testMass < 200. ){
	  antitagSB_versusMET.fill(ntuple);
	}
      }
    }
  }
  
  TCanvas* can = new TCanvas("can","can",800,800);
  can->Divide(2,2);
  tagSR_versusMET.buildSum();
  tagSB_versusMET.buildSum();
  antitagSR_versusMET.buildSum();  
  antitagSB_versusMET.buildSum();
  TH1F* prediction = new TH1F(*tagSR_versusMET.sum);
  prediction->SetNameTitle("prediction","prediction");

  for( int i = 1 ; i < prediction->GetNbinsX() ; i++ ){
    double pred = tagSB_versusMET.sum->GetBinContent(i);
    pred *= antitagSR_versusMET.sum->GetBinContent(i);
    if( antitagSB_versusMET.sum->GetBinContent(i) != 0. ){
      pred /= antitagSB_versusMET.sum->GetBinContent(i);
    }else{
      pred /= 0.00000001;      
    }
    prediction->SetBinContent(i,pred);
  }
  can->cd(1);
  TGraphAsymmErrors* RpassFail = new TGraphAsymmErrors();
  RpassFail->SetNameTitle("RpassFail","RpassFail");
  RpassFail->Divide(tagSR_versusMET.sum,tagSB_versusMET.sum,"poiss");
  TGraphAsymmErrors* antitagRpassFail = new TGraphAsymmErrors();
  antitagRpassFail->SetNameTitle("antitagRpassFail","antitagRpassFail");
  antitagRpassFail->Divide(antitagSR_versusMET.sum,antitagSB_versusMET.sum,"poiss");
  
  RpassFail->SetMarkerStyle(8);
  RpassFail->SetMarkerColor(kGreen);
  antitagRpassFail->SetMarkerStyle(8);
  antitagRpassFail->SetMarkerColor(kMagenta);
  RpassFail->GetYaxis()->SetRangeUser(0.,2.);
  RpassFail->GetYaxis()->SetTitle("R_{pass/fail}");
  RpassFail->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  RpassFail->Draw("A,p");
  antitagRpassFail->Draw("p,SAME");

  can->cd(2);
  prediction->SetMarkerStyle(8);
  prediction->SetMarkerColor(kRed);
  tagSR_versusMET.sum->SetMarkerStyle(4);
  prediction->GetYaxis()->SetTitle("Events");
  prediction->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  prediction->Draw("e1");
  tagSR_versusMET.sum->Draw("e1,SAME");
  gPad->SetLogy();

  can->cd(4);
  TGraphAsymmErrors* closure = new TGraphAsymmErrors();
  closure->SetNameTitle("closure","closure");
  closure->Divide(prediction,tagSR_versusMET.sum,"poiss");
  closure->SetMarkerStyle(8);
  closure->GetYaxis()->SetTitle("prediction/observation");
  closure->GetYaxis()->SetRangeUser(0.,2.);
  closure->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  closure->Draw("A,p");

  can->SaveAs("ABCDclosureTest_J2ptArbitration/ABCDclosureTest_versusMET.png");

}



