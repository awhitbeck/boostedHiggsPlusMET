#include "TGraph.h"
#include "TFile.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TPaveText.h"
#include "TLegend.h"
#include "TROOT.h"
#include <cassert> 
#include <vector>
#include <iostream>

using namespace std;

enum LegendLoc {kUpperLeft,kUpperRight,kLowerLeft,kLowerRight};

class plotParam {

public : 

  TString var,axisLabel;
  int rebinValue,legLoc;

  plotParam(TString var_ , TString axisLabel_ , 
	    int rebinValue_ , int legLoc_ ):
    var(var_),axisLabel(axisLabel_),rebinValue(rebinValue_),legLoc(legLoc_){}

};

int main(int argc, char** argv){

  TFile* inputFile = new TFile("taggingEfficiency.root","read");

  gROOT->ProcessLine(".L ~/tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");

  TCanvas* can = new TCanvas("can","can",500,500);
  can->SetTopMargin(.1);

  vector<TH1F*> histos;
  THStack* stack = new THStack("stack","stack");
  TH1F* sum;

  TLegend* leg;
  leg = new TLegend(0.4,.68,.55,.88);  
  leg->SetBorderSize(0);
  leg->SetFillColor(0);

  //matched_bbtag_1Higgs_DYJetsToLL
  //fake_0bHadrons_bbtag_1Higgs_DYJetsToLL
  //fake_1bHadrons_bbtag_1Higgs_DYJetsToLL
  //fake_2bHadrons_bbtag_1Higgs_DYJetsToLL
    
  TH1F* lightFlavorFake = (TH1F*)inputFile->Get("fake_0bHadrons_bbtag_1Higgs_QCD");
  lightFlavorFake->Add( (TH1F*)inputFile->Get("fake_0bHadrons_bbtag_1Higgs_TTJets"));
  if( lightFlavorFake == NULL ) assert(0);
  lightFlavorFake->Scale(10000.);
  lightFlavorFake->Rebin(2);
  lightFlavorFake->SetLineColor(1);
  lightFlavorFake->SetLineWidth(1);
  lightFlavorFake->SetFillColor(kGray);

  leg->AddEntry(lightFlavorFake,"q","f");
  stack->Add(lightFlavorFake);

  TH1F* heavyFlavorFake = (TH1F*)inputFile->Get("fake_1bHadrons_bbtag_1Higgs_QCD");
  heavyFlavorFake->Add( (TH1F*)inputFile->Get("fake_1bHadrons_bbtag_1Higgs_TTJets"));
  if( heavyFlavorFake == NULL ) assert(0);
  heavyFlavorFake->Scale(10000.);
  heavyFlavorFake->Rebin(2);
  heavyFlavorFake->SetLineColor(1);
  heavyFlavorFake->SetLineWidth(1);
  heavyFlavorFake->SetFillColor(kCyan);

  leg->AddEntry(heavyFlavorFake,"b","f");
  stack->Add(heavyFlavorFake);

  TH1F* gluonFake = (TH1F*)inputFile->Get("fake_2bHadrons_bbtag_1Higgs_QCD");
  gluonFake->Add( (TH1F*)inputFile->Get("fake_2bHadrons_bbtag_1Higgs_TTJets"));
  if( gluonFake == NULL ) assert(0);
  gluonFake->Scale(10000.);
  gluonFake->Rebin(2);
  gluonFake->SetLineColor(1);
  gluonFake->SetLineWidth(1);
  gluonFake->SetFillColor(kMagenta);

  leg->AddEntry(gluonFake,"gluon","f");
  stack->Add(gluonFake);

  TH1F* sigHisto = (TH1F*) inputFile->Get("matched_bbtag_1Higgs_Gluino1600");
  sigHisto->Scale(10000.);
  sigHisto->Rebin(2);
  sigHisto->SetLineColor(2);
  sigHisto->SetLineWidth(4);
  leg->AddEntry(sigHisto,"Higgs","f");
  
  if( stack->GetMaximum() > sigHisto->GetMaximum() ){
    stack->Draw("hist");
    stack->GetXaxis()->SetTitle("bb-disc.");
    stack->GetXaxis()->SetNdivisions(505);
    stack->GetYaxis()->SetTitle("Events");
    sigHisto->Draw("HIST,SAME");
  }else{
    sigHisto->Draw("HIST");
    stack->Draw("HIST,SAME");
    stack->GetXaxis()->SetTitle("bb-disc");
    stack->GetXaxis()->SetNdivisions(505);
    stack->GetYaxis()->SetTitle("Events");
    sigHisto->Draw("HIST,SAME");
  }
  //----
  leg->Draw();
    
  TPaveText *cmsText = new TPaveText(.17,.9,.47,.96,"NDC");
  cmsText->SetFillColor(0);
  cmsText->SetBorderSize(0);
  cmsText->AddText("CMS Simulation");
  cmsText->Draw();
  
  TPaveText *lumiText = new TPaveText(.72,.9,.97,.96,"NDC");
  lumiText->SetFillColor(0);
  lumiText->SetBorderSize(0);
  lumiText->AddText("10 fb^{-1} (13 TeV)");
  lumiText->Draw();
  
  can->SaveAs("taggingDisc.png");

  //ROC
  sum = new TH1F(*lightFlavorFake);
  sum->Add(heavyFlavorFake);
  sum->Add(gluonFake);
  
  const int nBins = sum->GetNbinsX();
  double sigIntegral = sigHisto->Integral(0,nBins+1); 
  double bkgIntegral = sum->Integral(0,nBins+1); 
  double signalEff[nBins],backgroundEff[nBins];
  for( int i = 0 ; i < nBins ; i++ ){
    signalEff[i] = sigHisto->Integral(i,nBins+1)/sigIntegral;
    cout << "signalEff: " << signalEff[i] << endl;
    backgroundEff[i] = sum->Integral(i,nBins+1)/bkgIntegral;
    cout << "backgroundEff: " << backgroundEff[i] << endl;
  }

  TGraph* roc = new TGraph(nBins,signalEff,backgroundEff);
  roc->GetXaxis()->SetTitle("#epsilon_{sig}");
  roc->GetYaxis()->SetTitle("#epsilon_{bkg}");

  TCanvas* rocCan = new TCanvas("rocCan","rocCan",500,500);
  roc->Draw("AC");
  rocCan->SaveAs("higgsTaggingROC.png");

  return 0;
}


