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

  TFile* inputFile = new TFile("test.root","read");

  vector<plotParam> plots;
  plots.push_back(plotParam("histoMHT_SR","H_{T}^{miss} [GeV]",5,kUpperRight));
  plots.push_back(plotParam("histoHT_SR","H_{T} [GeV]",4,kUpperRight));
  plots.push_back(plotParam("histoNJets_SR","N_{j}",1,kUpperRight));
  plots.push_back(plotParam("histoDeltaPhi1_SR","#Delta#Phi_{j1,MHT}",2,kUpperRight));
  plots.push_back(plotParam("histoDeltaPhi2_SR","#Delta#Phi_{j2,MHT}",2,kUpperRight));
  plots.push_back(plotParam("histoDeltaPhi3_SR","#Delta#Phi_{j3,MHT}",2,kUpperRight));
  plots.push_back(plotParam("histoDeltaPhi4_SR","#Delta#Phi_{j4,MHT}",2,kUpperRight));
  plots.push_back(plotParam("histoLeadingPrunedMass","leading m_{J} [GeV]",2,kUpperRight));
  plots.push_back(plotParam("histoSubleadingPrunedMass","subleading m_{J} [GeV]",2,kUpperRight));
  plots.push_back(plotParam("histoLeadingTau21","leading #tau_{2/1}",2,kUpperLeft));
  plots.push_back(plotParam("histoSubleadingTau21","subleading #tau_{2/1}",2,kUpperLeft));
  plots.push_back(plotParam("histoLeadingBbDisc","leading bb-disc.",2,kUpperRight));
  plots.push_back(plotParam("histoSubleadingBbDisc","subleading bb-disc.",2,kUpperRight));
  plots.push_back(plotParam("histoLeadingPt","leading p_{T} [GeV]",4,kUpperRight));
  plots.push_back(plotParam("histoSubleadingPt","subleading p_{T} [GeV]",4,kUpperRight));

  plots.push_back(plotParam("histoLeadingPt_1Higgs","leading p_{T} [GeV]",4,kUpperRight));
  plots.push_back(plotParam("histoSubleadingPt_1Higgs","subleading p_{T} [GeV]",4,kUpperRight));
  plots.push_back(plotParam("histoLeadingPrunedMass_1Higgs","leading m_{J} [GeV]",2,kUpperRight));
  plots.push_back(plotParam("histoSubleadingPrunedMass_1Higgs","subleading m_{J} [GeV]",2,kUpperRight));
  plots.push_back(plotParam("histoLeadingTau21_1Higgs","leading #tau_{2/1}",2,kUpperLeft));
  plots.push_back(plotParam("histoSubleadingTau21_1Higgs","subleading #tau_{2/1}",2,kUpperLeft));
  plots.push_back(plotParam("histoLeadingBbDisc_1Higgs","leading bb-disc.",2,kUpperRight));
  plots.push_back(plotParam("histoSubleadingBbDisc_1Higgs","subleading bb-disc.",2,kUpperRight));
  plots.push_back(plotParam("histoMHT_SR_1Higgs","H_{T}^{miss} [GeV]",5,kUpperRight));
  plots.push_back(plotParam("histoHT_SR_1Higgs","H_{T} [GeV]",4,kUpperRight));
  plots.push_back(plotParam("histoNJets_SR_1Higgs","N_{j}",1,kUpperRight));
  plots.push_back(plotParam("histoDeltaPhi1_SR_1Higgs","#Delta#Phi_{j1,MHT}",2,kUpperRight));
  plots.push_back(plotParam("histoDeltaPhi2_SR_1Higgs","#Delta#Phi_{j2,MHT}",2,kUpperRight));
  plots.push_back(plotParam("histoDeltaPhi3_SR_1Higgs","#Delta#Phi_{j3,MHT}",2,kUpperRight));
  plots.push_back(plotParam("histoDeltaPhi4_SR_1Higgs","#Delta#Phi_{j4,MHT}",2,kUpperRight));

  plots.push_back(plotParam("histoLeadingPt_2Higgs","leading p_{T} [GeV]",4,kUpperRight));
  plots.push_back(plotParam("histoSubleadingPt_2Higgs","subleading p_{T} [GeV]",4,kUpperRight));
  plots.push_back(plotParam("histoLeadingPrunedMass_2Higgs","leading m_{J} [GeV]",2,kUpperRight));
  plots.push_back(plotParam("histoSubleadingPrunedMass_2Higgs","subleading m_{J} [GeV]",2,kUpperRight));
  plots.push_back(plotParam("histoLeadingTau21_2Higgs","leading #tau_{2/1}",2,kUpperLeft));
  plots.push_back(plotParam("histoSubleadingTau21_2Higgs","subleading #tau_{2/1}",2,kUpperLeft));
  plots.push_back(plotParam("histoLeadingBbDisc_2Higgs","leading bb-disc.",2,kUpperRight));
  plots.push_back(plotParam("histoSubleadingBbDisc_2Higgs","subleading bb-disc.",2,kUpperRight));
  plots.push_back(plotParam("histoMHT_SR_2Higgs","H_{T}^{miss} [GeV]",5,kUpperRight));
  plots.push_back(plotParam("histoHT_SR_2Higgs","H_{T} [GeV]",4,kUpperRight));
  plots.push_back(plotParam("histoNJets_SR_2Higgs","N_{j}",1,kUpperRight));
  plots.push_back(plotParam("histoDeltaPhi1_SR_2Higgs","#Delta#Phi_{j1,MHT}",2,kUpperRight));
  plots.push_back(plotParam("histoDeltaPhi2_SR_2Higgs","#Delta#Phi_{j2,MHT}",2,kUpperRight));
  plots.push_back(plotParam("histoDeltaPhi3_SR_2Higgs","#Delta#Phi_{j3,MHT}",2,kUpperRight));
  plots.push_back(plotParam("histoDeltaPhi4_SR_2Higgs","#Delta#Phi_{j4,MHT}",2,kUpperRight));

  vector<TString> samples;
  samples.push_back("QCD");
  samples.push_back("WJetsToLNu");
  samples.push_back("ZJetsToNuNu");
  samples.push_back("TTJets");
  samples.push_back("Other");
  samples.push_back("Diboson");

  vector<TString> legEntries;
  legEntries.push_back("QCD");
  legEntries.push_back("W(l#nu)");
  legEntries.push_back("Z(#nu#nu)");
  legEntries.push_back("t#bar{t}");
  legEntries.push_back("Other");
  legEntries.push_back("VV");

  vector<int> sampleColors;
  sampleColors.push_back(kGray);
  sampleColors.push_back(kGreen);
  sampleColors.push_back(kBlue);
  sampleColors.push_back(kCyan);
  sampleColors.push_back(kMagenta);
  sampleColors.push_back(kRed+1);

  gROOT->ProcessLine(".L tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");

  TCanvas* can = new TCanvas("can","can",500,500);
  can->SetTopMargin(.1);

  TFile* signalFile = new TFile("signalRegionValidation_Gluino1600.root");

  for( int iVar = 0 ; iVar < plots.size() ; iVar++ ){

    cout << "iVar: " << iVar << endl;

    vector<TH1F*> histos;

    THStack* stack = new THStack("stack","stack");
    float backgroundSum = 0.;

    TLegend* leg;
    if( plots[iVar].legLoc == kUpperLeft ){
      leg = new TLegend(0.2,.68,.35,.88);
    }else{
      leg = new TLegend(0.75,.68,.9,.88);      
    }

      leg->SetBorderSize(0);
      leg->SetFillColor(0);
    
    for( int iSam = 0 ; iSam < samples.size() ; iSam++ ){
      
      histos.push_back((TH1F*)inputFile->Get(plots[iVar].var+"_"+samples[iSam]));

      if( histos.back() == NULL ) assert(0);

      histos.back()->Scale(10000.);
      backgroundSum+=histos.back()->Integral();
      histos.back()->Rebin(plots[iVar].rebinValue);
      histos.back()->SetLineColor(1);
      histos.back()->SetLineWidth(1);
      histos.back()->SetFillColor(sampleColors[iSam]);

      leg->AddEntry(histos.back(),legEntries[iSam],"f");
      stack->Add(histos.back());

    }

    TH1F* sigHisto = (TH1F*) inputFile->Get(plots[iVar].var+"_Gluino1600");
    sigHisto->Scale(10000.);
    sigHisto->Rebin(plots[iVar].rebinValue);
    sigHisto->SetLineColor(2);
    sigHisto->SetLineWidth(4);

    if( stack->GetMaximum() > sigHisto->GetMaximum() ){
      stack->Draw("hist");
      stack->GetXaxis()->SetTitle(plots[iVar].axisLabel);
      stack->GetXaxis()->SetNdivisions(505);
      stack->GetYaxis()->SetTitle("Events");
      sigHisto->Draw("HIST,SAME");
    }else{
      sigHisto->Draw("HIST");
      stack->Draw("HIST,SAME");
      stack->GetXaxis()->SetTitle(plots[iVar].axisLabel);
      stack->GetXaxis()->SetNdivisions(505);
      stack->GetYaxis()->SetTitle("Events");
      sigHisto->Draw("HIST,SAME");
    }
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

    gPad->SetLogy(false);
    can->SaveAs(plots[iVar].var+".png");
    gPad->SetLogy();
    can->SaveAs(plots[iVar].var+"_LogY.png");
  }

  return 0;
}


