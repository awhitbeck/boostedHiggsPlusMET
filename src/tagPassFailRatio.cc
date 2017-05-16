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

  gROOT->ProcessLine(".L tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");

  skimSamples skims;

  plot JMplot_BBtagSR_pt300_400(*fillLeadingBBtagJetMass,"JMplot_BBtagSR_pt300_400","leading m_{J} [GeV]",15,55.,205.);
  plot JMplot_BBtagSR_pt400_500(*fillLeadingBBtagJetMass,"JMplot_BBtagSR_pt400_500","leading m_{J} [GeV]",15,55.,205.);
  plot JMplot_BBtagSR_pt500_700(*fillLeadingBBtagJetMass,"JMplot_BBtagSR_pt500_700","leading m_{J} [GeV]",15,55.,205.);
  plot JMplot_BBtagSR_pt700_1000(*fillLeadingBBtagJetMass,"JMplot_BBtagSR_pt700_1000","leading m_{J} [GeV]",15,55.,205.);
  plot JMplot_BBtagSR_pt1000(*fillLeadingBBtagJetMass,"JMplot_BBtagSR_pt1000","leading m_{J} [GeV]",15,55.,205.);
  plot JptPlot_SR(*fillLeadingBBtagJetPt,"JptPlot_SR","leading p_{t} [GeV]",7,300.,1000.);

  vector<plot> SRplots;
  SRplots.push_back(JMplot_BBtagSR_pt300_400);
  SRplots.push_back(JMplot_BBtagSR_pt400_500);
  SRplots.push_back(JMplot_BBtagSR_pt500_700);
  SRplots.push_back(JMplot_BBtagSR_pt700_1000);
  SRplots.push_back(JMplot_BBtagSR_pt1000);
  SRplots.push_back(JptPlot_SR);

  // inverted BBtag plots
  plot JMplot_BBtagSB_pt300_400(*fillLeadingBBtagJetMass,"JMplot_BBtagSB_pt300_400","leading m_{J} [GeV]",15,55.,205.);
  plot JMplot_BBtagSB_pt400_500(*fillLeadingBBtagJetMass,"JMplot_BBtagSB_pt400_500","leading m_{J} [GeV]",15,55.,205.);
  plot JMplot_BBtagSB_pt500_700(*fillLeadingBBtagJetMass,"JMplot_BBtagSB_pt500_700","leading m_{J} [GeV]",15,55.,205.);
  plot JMplot_BBtagSB_pt700_1000(*fillLeadingBBtagJetMass,"JMplot_BBtagSB_pt700_1000","leading m_{J} [GeV]",15,55.,205.);
  plot JMplot_BBtagSB_pt1000(*fillLeadingBBtagJetMass,"JMplot_BBtagSB_pt1000","leading m_{J} [GeV]",15,55.,205.);
  plot JptPlot_SB(*fillLeadingBBtagJetPt,"JptPlot_SB","leading p_{t} [GeV]",7,300.,1000.);

  vector<plot> SBplots;
  SBplots.push_back(JMplot_BBtagSB_pt300_400);
  SBplots.push_back(JMplot_BBtagSB_pt400_500);
  SBplots.push_back(JMplot_BBtagSB_pt500_700);
  SBplots.push_back(JMplot_BBtagSB_pt700_1000);
  SBplots.push_back(JMplot_BBtagSB_pt1000);
  SBplots.push_back(JptPlot_SB);

  plot RpassFailNum(*fillOne,"RpassFailNum","A.U.",1,.5,1.5);
  plot RpassFailDenom(*fillOne,"RpassFailNum","p_{T,J} [GeV]",1,.5,1.5);
  plot RpassFailNumData(*fillOne,"RpassFailNumData","p_{T,J} [GeV]",1,.5,1.5);
  plot RpassFailDenomData(*fillOne,"RpassFailNumData","p_{T,J} [GeV]",1,.5,1.5);

  plot SB(*fillOne,"SidebandYield","A.U.",1,.5,1.5);
  plot SR(*fillOne,"SignalRegionYield","A.U.",1,.5,1.5);
  plot SBData(*fillOne,"SidebandYieldData","A.U.",1,.5,1.5);
  plot SRData(*fillOne,"SignalRegionYieldData","A.U.",1,.5,1.5);

  double (*fillerFunc)(heppySkimTree*) = *fillAnalysisBins;

  plot SBVersusAnalysisBin(fillerFunc,"SidebandYieldVersusAnalysisBin","A.U.",8,.5,8.5);
  plot SRVersusAnalysisBin(fillerFunc,"SignalRegionYieldVersusAnalysisBin","A.U.",8,.5,8.5);
  plot SBDataVersusAnalysisBin(fillerFunc,"SidebandYieldDataVersusAnalysisBin","A.U.",8,.5,8.5);
  plot SRDataVersusAnalysisBin(fillerFunc,"SignalRegionYieldDataVersusAnalysisBin","A.U.",8,.5,8.5);

  plot RpassFailNumVersusPt(*fillLooseSinglePt,"RpassFailNumVersusPt","p_{T,J} [GeV]",10,300.,1500.);
  plot RpassFailDenomVersusPt(*fillLooseSinglePt,"RpassFailNumVersusPt","p_{T,J} [GeV]",10,300.,1500.);
  plot RpassFailNumVersusMET(*fillMET,"RpassFailNumVersusMET","E_{T}^{miss} [GeV]",10,300.,1500.);
  plot RpassFailDenomVersusMET(*fillMET,"RpassFailNumVersusMET","E_{T}^{miss} [GeV]",10,300.,1500.);
  plot RpassFailNumVersusHT(*fillHT,"RpassFailNumVersusHT","H_{T} [GeV]",10,600.,2600.);
  plot RpassFailDenomVersusHT(*fillHT,"RpassFailNumVersusHT","H_{T} [GeV]",10,600.,2600.);

  // MC backgrounds
  for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

    heppySkimTree* ntuple = skims.ntuples[iSample];
    for( int iPlot = 0 ; iPlot<SRplots.size() ; iPlot++){
      SRplots[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
      SBplots[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
    }
    RpassFailNum.addNtuple(ntuple,skims.sampleName[iSample]);
    RpassFailDenom.addNtuple(ntuple,skims.sampleName[iSample]);
    RpassFailNumVersusPt.addNtuple(ntuple,skims.sampleName[iSample]);
    RpassFailDenomVersusPt.addNtuple(ntuple,skims.sampleName[iSample]);
    RpassFailNumVersusMET.addNtuple(ntuple,skims.sampleName[iSample]);
    RpassFailDenomVersusMET.addNtuple(ntuple,skims.sampleName[iSample]);
    RpassFailNumVersusHT.addNtuple(ntuple,skims.sampleName[iSample]);
    RpassFailDenomVersusHT.addNtuple(ntuple,skims.sampleName[iSample]);
    SB.addNtuple(ntuple,skims.sampleName[iSample]);
    SR.addNtuple(ntuple,skims.sampleName[iSample]);
    SBVersusAnalysisBin.addNtuple(ntuple,skims.sampleName[iSample]);
    SRVersusAnalysisBin.addNtuple(ntuple,skims.sampleName[iSample]);
    
    int numEvents = ntuple->fChain->GetEntries();
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 1000000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      if(!baselineCut(ntuple)) continue; 
      for( int iPlot = 0 ; iPlot<SRplots.size() ; iPlot++){
	if( taggingCut(ntuple) && ptBinCut(ntuple,iPlot) )
	  SRplots[iPlot].fill(ntuple);
	if( antiTaggingCut(ntuple) && ptBinCut(ntuple,iPlot) )
	  SBplots[iPlot].fill(ntuple);
      }
      if( taggingCut(ntuple) ){
	double testMass = fillLeadingBBtagJetMass(ntuple);
	if( testMass > 85. && testMass < 135. ){ 
	  RpassFailNum.fill(ntuple);
	  RpassFailNumVersusPt.fill(ntuple);
	  RpassFailNumVersusMET.fill(ntuple);
	  RpassFailNumVersusHT.fill(ntuple);
	  SRVersusAnalysisBin.fill(ntuple);
	  SR.fill(ntuple);
	}else if( testMass > 50. && testMass < 200. ){
	  RpassFailDenom.fill(ntuple);
	  RpassFailDenomVersusPt.fill(ntuple);
	  RpassFailDenomVersusMET.fill(ntuple);
	  RpassFailDenomVersusHT.fill(ntuple);
	  SBVersusAnalysisBin.fill(ntuple);
	  SB.fill(ntuple);
      }
      }
    }
  }
  
  // Data -- Only fill SB histos
  for( int iPlot = 0 ; iPlot<SRplots.size() ; iPlot++){
    SRplots[iPlot].addDataNtuple(skims.dataNtuple,"data");
    SBplots[iPlot].addDataNtuple(skims.dataNtuple,"data");
  }
  RpassFailNumData.addDataNtuple(skims.dataNtuple,"data");
  RpassFailDenomData.addDataNtuple(skims.dataNtuple,"data");
  SBData.addDataNtuple(skims.dataNtuple,"data");
  SRData.addDataNtuple(skims.dataNtuple,"data");
  SBDataVersusAnalysisBin.addDataNtuple(skims.dataNtuple,"data");
  SRDataVersusAnalysisBin.addDataNtuple(skims.dataNtuple,"data");

  int numEvents = skims.dataNtuple->fChain->GetEntries();
  for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
    skims.dataNtuple->GetEntry(iEvt);
    if( iEvt % 1000000 == 0 ) cout << "Data: " << iEvt << "/" << numEvents << endl;
    if(!baselineCut(skims.dataNtuple)) continue; 
    for( int iPlot = 0 ; iPlot<SRplots.size() ; iPlot++){
      //if( taggingCut(skims.dataNtuple) && ptBinCut(skims.dataNtuple,iPlot) )
      //  SRplots[iPlot].fillData(skims.dataNtuple);
      if( antiTaggingCut(skims.dataNtuple) && ptBinCut(skims.dataNtuple,iPlot) )
	SBplots[iPlot].fillData(skims.dataNtuple);
    }
    if( antiTaggingCut(skims.dataNtuple) ){
      double testMass = fillLeadingBBtagJetMass(skims.dataNtuple);
      if( testMass > 85. && testMass < 135. ){
	RpassFailNumData.fillData(skims.dataNtuple);
      }else if( testMass > 50. && testMass < 200. ){ 
	RpassFailDenomData.fillData(skims.dataNtuple);      
      }
    }
    if( taggingCut(skims.dataNtuple) ){
      double testMass = fillLeadingBBtagJetMass(skims.dataNtuple);
      if( testMass > 85. && testMass < 135. ){
	SRDataVersusAnalysisBin.fillData(skims.dataNtuple);
	SRData.fillData(skims.dataNtuple);
      }else if( testMass > 50. && testMass < 200. ){ 
	SBDataVersusAnalysisBin.fillData(skims.dataNtuple);
	SBData.fillData(skims.dataNtuple);
      }
    }
  }

  TCanvas* can = new TCanvas("can","can",1200,800);
  can->Divide(3,2);
  for( int iPlot = 0 ; iPlot<SRplots.size()-1 ; iPlot++){
    can->cd(iPlot+1);
    SRplots[iPlot].buildSum();
    SRplots[iPlot].sum->GetXaxis()->SetTitle("m_{J} [GeV]");
    SRplots[iPlot].sum->GetYaxis()->SetTitle("Events (a.u.)");
    SRplots[iPlot].sum->SetLineWidth(2);
    SRplots[iPlot].sum->SetFillColor(kGray);
    SRplots[iPlot].sum->Scale(1./SRplots[iPlot].sum->Integral());
    SBplots[iPlot].buildSum();
    SBplots[iPlot].sum->Scale(1./SBplots[iPlot].sum->Integral());
    SBplots[iPlot].sum->SetLineStyle(2);
    SBplots[iPlot].sum->SetLineWidth(2);
    SBplots[iPlot].sum->SetLineColor(2);
    
    SRplots[iPlot].sum->GetYaxis()->SetRangeUser(0.,.4);
    SRplots[iPlot].sum->Draw("e4");
    SBplots[iPlot].sum->Draw("hist,e1,SAME");

  }

  can->cd(6);
  TLegend* leg = new TLegend(.1,.1,.9,.9);
  leg->SetFillColor(0);
  leg->SetBorderSize(0);
  char legendLabel[256];
  sprintf(legendLabel,"bb-tag>%.1f",bbtagCut);
  leg->AddEntry(SRplots[0].sum,legendLabel,"l");
  sprintf(legendLabel,"bb-tag<%.1f",bbtagCut);
  leg->AddEntry(SBplots[0].sum,legendLabel,"l");
  leg->Draw();
  char saveString[256];

  sprintf(saveString,"tagPassFailRatioVsPt_bbtag_%.1f.png",bbtagCut);
  can->SaveAs(saveString);  

  TCanvas* canPt = new TCanvas("canPt","canPt");
  SRplots.back().buildSum();
  SBplots.back().buildSum();
  SRplots.back().sum->SetLineColor(2);
  SRplots.back().sum->Draw("histo");
  SBplots.back().sum->Draw("e1,SAME");
  canPt->SaveAs("JetPt_SRversusSB.png");

  TCanvas* canRatio = new TCanvas("canRatio","canRatio",800,800);
  TGraphAsymmErrors* RpassFailGraph = new TGraphAsymmErrors();
  RpassFailNum.buildSum();
  RpassFailDenom.buildSum();
  RpassFailGraph->Divide(RpassFailNum.sum,RpassFailDenom.sum,"pois");
  RpassFailGraph->SetMarkerStyle(8);
  RpassFailGraph->GetXaxis()->SetTitle("A.U.");
  RpassFailGraph->GetYaxis()->SetRangeUser(0.,1.);
  RpassFailGraph->GetYaxis()->SetTitle("R_{pass/fail}");

  TGraphAsymmErrors* RpassFailVersusPtGraph = new TGraphAsymmErrors();
  RpassFailNumVersusPt.buildSum();
  RpassFailDenomVersusPt.buildSum();
  RpassFailVersusPtGraph->Divide(RpassFailNumVersusPt.sum,RpassFailDenomVersusPt.sum,"pois");
  RpassFailVersusPtGraph->SetMarkerStyle(8);
  RpassFailVersusPtGraph->GetXaxis()->SetTitle("p_{T,J} [GeV]");
  RpassFailVersusPtGraph->GetYaxis()->SetRangeUser(0.,1.);
  RpassFailVersusPtGraph->GetYaxis()->SetTitle("R_{pass/fail}");

  TGraphAsymmErrors* RpassFailVersusMETGraph = new TGraphAsymmErrors();
  RpassFailNumVersusMET.buildSum();
  RpassFailDenomVersusMET.buildSum();
  RpassFailVersusMETGraph->Divide(RpassFailNumVersusMET.sum,RpassFailDenomVersusMET.sum,"pois");
  RpassFailVersusMETGraph->SetMarkerStyle(8);
  RpassFailVersusMETGraph->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  RpassFailVersusMETGraph->GetYaxis()->SetRangeUser(0.,1.);
  RpassFailVersusMETGraph->GetYaxis()->SetTitle("R_{pass/fail}");

  TGraphAsymmErrors* RpassFailVersusHTGraph = new TGraphAsymmErrors();
  RpassFailNumVersusHT.buildSum();
  RpassFailDenomVersusHT.buildSum();
  RpassFailVersusHTGraph->Divide(RpassFailNumVersusHT.sum,RpassFailDenomVersusHT.sum,"pois");
  RpassFailVersusHTGraph->SetMarkerStyle(8);
  RpassFailVersusHTGraph->GetXaxis()->SetTitle("H_{T} [GeV]");
  RpassFailVersusHTGraph->GetYaxis()->SetRangeUser(0.,1.);
  RpassFailVersusHTGraph->GetYaxis()->SetTitle("R_{pass/fail}");

  TGraphAsymmErrors* RpassFailDataGraph = new TGraphAsymmErrors();
  RpassFailDataGraph->Divide(RpassFailNumData.dataHist,RpassFailDenomData.dataHist,"pois");
  RpassFailDataGraph->SetMarkerStyle(4);
  RpassFailDataGraph->SetMarkerColor(4);
  RpassFailDataGraph->SetLineColor(4);

  canRatio->Divide(2,2);
  canRatio->cd(1);
  RpassFailGraph->Draw("A,P");
  RpassFailDataGraph->Draw("P,SAME");
  canRatio->cd(2);
  RpassFailVersusPtGraph->Draw("A,P");
  canRatio->cd(3);
  RpassFailVersusMETGraph->Draw("A,P");
  canRatio->cd(4);
  RpassFailVersusHTGraph->Draw("A,P");

  canRatio->SaveAs("passFailRatio.png");

  TCanvas* canClosure = new TCanvas("canClosure","canClosure",800,400);
  canClosure->Divide(2,1);
  canClosure->cd(1);
  SR.buildSum();
  SB.buildSum();
  TH1F* closureTestIntegrated = new TH1F(*(SB.sum));
  closureTestIntegrated->SetNameTitle("closureTestIntegrated",";A.U.;Predicted/Observed");
  closureTestIntegrated->Multiply(RpassFailNum.sum);
  closureTestIntegrated->Divide(RpassFailDenom.sum);
  closureTestIntegrated->Divide(SR.sum);
  closureTestIntegrated->SetMarkerStyle(8);
  closureTestIntegrated->GetYaxis()->SetRangeUser(0.,2.);
  closureTestIntegrated->Draw("e1");

  canClosure->cd(2);
  SBVersusAnalysisBin.buildSum();
  SRVersusAnalysisBin.buildSum();
  TH1F* closureTestVersusAnalysisBin = new TH1F(*(SBVersusAnalysisBin.sum));
  closureTestVersusAnalysisBin->SetNameTitle("closureTestVersusAnalysisBin",";A.U.;Predicted/Observed");
  closureTestVersusAnalysisBin->Scale(RpassFailNum.sum->GetBinContent(1)/RpassFailDenom.sum->GetBinContent(1));
  closureTestVersusAnalysisBin->Divide(SRVersusAnalysisBin.sum);
  closureTestVersusAnalysisBin->SetMarkerStyle(8);
  closureTestVersusAnalysisBin->GetYaxis()->SetRangeUser(0.,2.5);
  closureTestVersusAnalysisBin->Draw("e1");
  for( int i = 1 ; i <= closureTestVersusAnalysisBin->GetNbinsX() ; i++ ){
    cout << "bin " << i << " " << closureTestVersusAnalysisBin->GetBinContent(i) << "+/-" << closureTestVersusAnalysisBin->GetBinError(i) << endl;
  }

  canClosure->SaveAs("closureTest.png");

  TCanvas* canPrediction = new TCanvas("canPrediction","canPrediction",800,400);
  canPrediction->Divide(2,1);
  canPrediction->cd(1);
  TH1F* predictionIntegrated = new TH1F(*(SBData.dataHist));
  predictionIntegrated->SetNameTitle("predictionIntegrated",";A.U.;Predicted/Observed");
  predictionIntegrated->Multiply(RpassFailNumData.dataHist);
  predictionIntegrated->Divide(RpassFailDenomData.dataHist);
  predictionIntegrated->Divide(SRData.dataHist);
  predictionIntegrated->SetMarkerStyle(8);
  predictionIntegrated->GetYaxis()->SetRangeUser(0.,2.);
  predictionIntegrated->Draw("e1");

  canPrediction->cd(2);
  TH1F* predictionVersusAnalysisBin = new TH1F(*(SBDataVersusAnalysisBin.dataHist));
  predictionVersusAnalysisBin->SetNameTitle("predictionVersusAnalysisBin",";Analysis Bin;Events");
  predictionVersusAnalysisBin->Scale(RpassFailNumData.dataHist->GetBinContent(1)/RpassFailDenomData.dataHist->GetBinContent(1));
  predictionVersusAnalysisBin->Draw("histo");
  SRDataVersusAnalysisBin.dataHist->SetMarkerStyle(8);
  SRDataVersusAnalysisBin.dataHist->Draw("e1,SAME");

  canPrediction->cd(2);
  //TPad *pad1 = new TPad("pad1","top pad",0,0.35,1,0.99);
  //pad1->Draw();
  //TPad *pad2 = new TPad("pad2","bottom pad",0,0,1,0.3);
  //pad2->Draw();
  //pad1->cd();
  TH1F* ratioVersusAnalysisBin = new TH1F(*predictionVersusAnalysisBin);
  ratioVersusAnalysisBin->SetNameTitle("ratioVersusAnalysisBin",";Analysis Bin;Predicted/Observed");
  ratioVersusAnalysisBin->Divide(SRDataVersusAnalysisBin.dataHist);
  ratioVersusAnalysisBin->SetMarkerStyle(8);
  ratioVersusAnalysisBin->Draw("e1");

  for( int i = 1 ; i <= SRDataVersusAnalysisBin.dataHist->GetNbinsX() ; i++ ){
    cout << "High bb-tag, signal region, bin " << i << ": " << SRDataVersusAnalysisBin.dataHist->GetBinContent(i) << endl;
    cout << "High bb-tag, sideband region, bin " << i << ": " << SBDataVersusAnalysisBin.dataHist->GetBinContent(i) << endl;
    cout << "ratio: " << RpassFailNumData.dataHist->GetBinContent(1)/RpassFailDenomData.dataHist->GetBinContent(1) << endl;
    cout << "prediction bin " << i << ": " << SBDataVersusAnalysisBin.dataHist->GetBinContent(i)*RpassFailNumData.dataHist->GetBinContent(1)/RpassFailDenomData.dataHist->GetBinContent(1) << endl;
    cout << "observation bin " << i << ": " << SRDataVersusAnalysisBin.dataHist->GetBinContent(i) << endl;
  }

  canPrediction->SaveAs("prediction.png");
  
}



