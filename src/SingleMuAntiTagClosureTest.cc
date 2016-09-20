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
  skimSamples skimsMu("singleMuCR");
  
  for( int i = 0 ; i < skims.sampleName.size() ; i++ ){
    if( skims.sampleName[i] == "QCD" || skims.sampleName[i] == "ZJets" ){
      skims.ntuples.erase(skims.ntuples.begin()+i);
      skims.sampleName.erase(skims.sampleName.begin()+i);
      skims.fillColor.erase(skims.fillColor.begin()+i);
    }
  }

  for( int i = 0 ; i < skimsMu.sampleName.size() ; i++ ){
    if( skimsMu.sampleName[i] == "QCD" || skimsMu.sampleName[i] == "ZJets" ){
      skimsMu.ntuples.erase(skimsMu.ntuples.begin()+i);
      skimsMu.sampleName.erase(skimsMu.sampleName.begin()+i);
      skimsMu.fillColor.erase(skimsMu.fillColor.begin()+i);
    }
  }

  double (*arbitrationFunc)(heppySkimTree*) = *fillLeadingJetMass<heppySkimTree>; 

  plot<heppySkimTree> tagSR_versusMET(*fillMET<heppySkimTree>,"tagSR_versusMET","E_{T}^{miss} [GeV]",10,300.,1300.);
  plot<heppySkimTree> tagSB_versusMET(*fillMET<heppySkimTree>,"tagSB_versusMET","E_{T}^{miss} [GeV]",10,300.,1300.);
  plot<heppySkimTree> tagSRmu_versusMET(*fillMET<heppySkimTree>,"tagSRmu_versusMET","E_{T}^{miss} [GeV]",10,300.,1300.);
  plot<heppySkimTree> tagSBmu_versusMET(*fillMET<heppySkimTree>,"tagSBmu_versusMET","E_{T}^{miss} [GeV]",10,300.,1300.);

  plot<heppySkimTree> SR_versusMJ(*arbitrationFunc,"SR_versusMJ","m_{J} [GeV]",30,50.,200.);
  plot<heppySkimTree> mu_versusMJ(*arbitrationFunc,"mu_versusMJ","m_{J} [GeV]",30,50.,200.);

  // MC backgrounds -- signal region
  for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

    heppySkimTree* ntuple = skims.ntuples[iSample];
    tagSR_versusMET.addNtuple(ntuple,skims.sampleName[iSample]);
    tagSB_versusMET.addNtuple(ntuple,skims.sampleName[iSample]);
    SR_versusMJ.addNtuple(ntuple,skims.sampleName[iSample]);

    int numEvents = ntuple->fChain->GetEntries();
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 1000000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      if(!baselineCut(ntuple)) continue; 
      if( antiTaggingCut(ntuple) ){
	double testMass = arbitrationFunc(ntuple);
	if( testMass > 85. && testMass < 135. ){ 
	  tagSR_versusMET.fill(ntuple);
	}else if( testMass > 50. && testMass < 200. ){
	  tagSB_versusMET.fill(ntuple);
	}
	SR_versusMJ.fill(ntuple);
      }
    }
  }

  // MC backgrounds -- single mu region
  for( int iSample = 0 ; iSample < skimsMu.ntuples.size() ; iSample++){

    heppySkimTree* ntuple = skimsMu.ntuples[iSample];
    tagSRmu_versusMET.addNtuple(ntuple,skimsMu.sampleName[iSample]);
    tagSBmu_versusMET.addNtuple(ntuple,skimsMu.sampleName[iSample]);
    mu_versusMJ.addNtuple(ntuple,skimsMu.sampleName[iSample]);

    int numEvents = ntuple->fChain->GetEntries();
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 1000000 == 0 ) cout << skimsMu .sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      if(!baselineCut(ntuple)) continue; 
      if( antiTaggingCut(ntuple) ){
	double testMass = arbitrationFunc(ntuple);
	if( testMass > 85. && testMass < 135. ){ 
	  tagSRmu_versusMET.fill(ntuple);//,totalWeight);
	}else if( testMass > 50. && testMass < 200. ){
	  tagSBmu_versusMET.fill(ntuple);//,totalWeight);
	}
	mu_versusMJ.fill(ntuple);
      }
    }
  }
  
  TCanvas* can = new TCanvas("can","can",800,800);
  can->Divide(2,2);
  tagSR_versusMET.buildSum();
  tagSB_versusMET.buildSum();
  tagSRmu_versusMET.buildSum();  
  tagSBmu_versusMET.buildSum();
  SR_versusMJ.buildSum();  
  mu_versusMJ.buildSum();

  can->cd(1);

  for( int i = 1 ; i <= tagSR_versusMET.sum->GetNbinsX() ; i++ ){
    cout << "tagSR: " << tagSR_versusMET.sum->GetBinContent(i) << endl;
    cout << "tagSB: " << tagSB_versusMET.sum->GetBinContent(i) << endl;
    cout << "tagSRmu: " << tagSRmu_versusMET.sum->GetBinContent(i) << endl;
    cout << "tagSBmu: " << tagSBmu_versusMET.sum->GetBinContent(i) << endl;
  }

  TGraphAsymmErrors* RpassFail = new TGraphAsymmErrors();
  RpassFail->SetNameTitle("RpassFail","RpassFail");
  RpassFail->Divide(tagSR_versusMET.sum,tagSB_versusMET.sum,"poiss");
  TGraphAsymmErrors* muRpassFail = new TGraphAsymmErrors();
  muRpassFail->SetNameTitle("muRpassFail","muRpassFail");
  muRpassFail->Divide(tagSRmu_versusMET.sum,tagSBmu_versusMET.sum,"poiss");
  
  RpassFail->SetMarkerStyle(8);
  RpassFail->SetMarkerColor(kGreen);
  muRpassFail->SetMarkerStyle(8);
  muRpassFail->SetMarkerColor(kMagenta);
  RpassFail->GetYaxis()->SetRangeUser(0.,2.);
  RpassFail->GetYaxis()->SetTitle("R_{pass/fail}");
  RpassFail->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  RpassFail->Draw("A,p");
  muRpassFail->Draw("p,SAME");
  
  can->cd(3);
  
  mu_versusMJ.sum->SetLineColor(2);
  mu_versusMJ.sum->SetLineStyle(2);
  mu_versusMJ.sum->SetLineWidth(2);
  SR_versusMJ.sum->SetLineColor(4);
  SR_versusMJ.sum->SetLineStyle(1);
  SR_versusMJ.sum->SetLineWidth(2);
  SR_versusMJ.sum->Draw("histo");
  mu_versusMJ.sum->Draw("SAME,histo");

  can->cd(2);
  tagSR_versusMET.sum->SetMarkerColor(4);
  tagSR_versusMET.sum->SetMarkerStyle(4);
  tagSB_versusMET.sum->SetMarkerColor(2);
  tagSB_versusMET.sum->SetMarkerStyle(8);
  tagSB_versusMET.sum->Draw();
  tagSR_versusMET.sum->Draw("SAME");
  can->cd(4);
  tagSRmu_versusMET.sum->SetMarkerColor(4);
  tagSRmu_versusMET.sum->SetMarkerStyle(4);
  tagSBmu_versusMET.sum->SetMarkerColor(2);
  tagSBmu_versusMET.sum->SetMarkerStyle(8);
  tagSBmu_versusMET.sum->Draw();
  tagSRmu_versusMET.sum->Draw("SAME");
  
  can->SaveAs("SingleMuAntiTagClosureTest_J1ptArbitration/closureTest.png");

}



