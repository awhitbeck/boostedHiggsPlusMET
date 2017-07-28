#include "CMS_lumi.cc"
#include "computeRatio.h"

TH1F* include_overflow(TH1F* h);
void computeIntegratedRatio(TH1F* num, TH1F* denom, int start_bin=1, int end_bin=4,bool verbose=false);
void computeScaleFactor(TH1F* hdata,TH1F* hmc, bool verbose=false);
void setStyle(TGraphAsymmErrors& graph, TString ylabel="Data/MC");
void setStyle(TH1F& hist, TString ylabel="Data/MC");
TH1F* makeRatio(TH1F* num , TH1F* denom, TString ylabel="Data/MC");
TLine* makeRatioLine(TH1F* num , TH1F* denom, double lower, double upper=900.);

void checkScaleFactors(TString tag = "_singleMu", bool doubletag = true, TString baseDir="./",TString histTag="MET",int integrate_from=1,int integrate_to=4){

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    TFile* f = new TFile(baseDir+"ALPHABEThistos"+tag+".root","READ");
    TH1F* hdata,*hmc;

    // ---------------------------------------------
    TH1F* doubletagSRdata = (TH1F*) f->Get(histTag+"_doubletagSR_data");
    assert(doubletagSRdata);
    doubletagSRdata = include_overflow(doubletagSRdata);
    doubletagSRdata->SetLineColor(1);
    doubletagSRdata->SetLineWidth(3);
    doubletagSRdata->SetMarkerColor(1);
    doubletagSRdata->SetMarkerStyle(8);
    doubletagSRdata->GetXaxis()->SetTitle("MET [GeV]");
    doubletagSRdata->GetYaxis()->SetTitle("Events");
    TH1F* doubletagSRmc = (TH1F*) f->Get(histTag+"_doubletagSR_sum");
    assert(doubletagSRmc);
    doubletagSRmc = include_overflow(doubletagSRmc);
    doubletagSRmc->SetLineColor(2);
    doubletagSRmc->SetLineWidth(3);
    doubletagSRmc->SetFillColor(2);
    doubletagSRmc->SetFillStyle(3490);
    doubletagSRmc->GetXaxis()->SetTitle("MET [GeV]");
    doubletagSRmc->GetYaxis()->SetTitle("Events");
    computeScaleFactor(doubletagSRdata,doubletagSRmc);

    TH1F* doubletagSBdata = (TH1F*) f->Get(histTag+"_doubletagSB_data");
    assert(doubletagSBdata);
    doubletagSBdata = include_overflow(doubletagSBdata);
    doubletagSBdata->SetNameTitle("doubletagSBdata","doubletagSBdata");
    doubletagSBdata->SetLineColor(1);
    doubletagSBdata->SetLineWidth(3);
    doubletagSBdata->SetMarkerColor(1);
    doubletagSBdata->SetMarkerStyle(8);
    doubletagSBdata->GetXaxis()->SetTitle("MET [GeV]");
    doubletagSBdata->GetYaxis()->SetTitle("Events");
    TH1F* doubletagSBmc = (TH1F*) f->Get(histTag+"_doubletagSB_sum");
    assert(doubletagSBmc);
    doubletagSBmc = include_overflow(doubletagSBmc);
    doubletagSBmc->SetNameTitle("doubletagSBmc","doubletagSBmc");
    doubletagSBmc->SetLineColor(2);
    doubletagSBmc->SetLineWidth(3);
    doubletagSBmc->SetFillColor(2);
    doubletagSBmc->SetFillStyle(3490);
    doubletagSBmc->GetXaxis()->SetTitle("MET [GeV]");
    doubletagSBmc->GetYaxis()->SetTitle("Events");
    computeScaleFactor(doubletagSBdata,doubletagSBmc);

    TH1F* tagSRdata = (TH1F*) f->Get(histTag+"_tagSR_data");
    assert(tagSRdata);
    tagSRdata = include_overflow(tagSRdata);
    tagSRdata->SetLineColor(1);
    tagSRdata->SetLineWidth(3);
    tagSRdata->SetMarkerColor(1);
    tagSRdata->SetMarkerStyle(8);
    tagSRdata->GetXaxis()->SetTitle("MET [GeV]");
    tagSRdata->GetYaxis()->SetTitle("Events");
    TH1F* tagSRmc = (TH1F*) f->Get(histTag+"_tagSR_sum");
    assert(tagSRmc);
    tagSRmc = include_overflow(tagSRmc);
    tagSRmc->SetLineColor(2);
    tagSRmc->SetLineWidth(3);
    tagSRmc->SetFillColor(2);
    tagSRmc->SetFillStyle(3490);
    tagSRmc->GetXaxis()->SetTitle("MET [GeV]");
    tagSRmc->GetYaxis()->SetTitle("Events");
    computeScaleFactor(tagSRdata,tagSRmc);

    TH1F* tagSBdata = (TH1F*) f->Get(histTag+"_tagSB_data");
    assert(tagSBdata);
    tagSBdata = include_overflow(tagSBdata);
    tagSBdata->SetNameTitle("tagSBdata","tagSBdata");
    tagSBdata->SetLineColor(1);
    tagSBdata->SetLineWidth(3);
    tagSBdata->SetMarkerColor(1);
    tagSBdata->SetMarkerStyle(8);
    tagSBdata->GetXaxis()->SetTitle("MET [GeV]");
    tagSBdata->GetYaxis()->SetTitle("Events");
    TH1F* tagSBmc = (TH1F*) f->Get(histTag+"_tagSB_sum");
    assert(tagSBmc);
    tagSBmc = include_overflow(tagSBmc);
    tagSBmc->SetNameTitle("tagSBmc","tagSBmc");
    tagSBmc->SetLineColor(2);
    tagSBmc->SetLineWidth(3);
    tagSBmc->SetFillColor(2);
    tagSBmc->SetFillStyle(3490);
    tagSBmc->GetXaxis()->SetTitle("MET [GeV]");
    tagSBmc->GetYaxis()->SetTitle("Events");
    computeScaleFactor(tagSBdata,tagSBmc);

    TH1F* antitagSRdata = (TH1F*) f->Get(histTag+"_antitagSR_data");
    assert(antitagSRdata);
    antitagSRdata = include_overflow(antitagSRdata);
    antitagSRdata->SetNameTitle("antitagSRdata","antitagSRdata");
    antitagSRdata->SetLineColor(1);
    antitagSRdata->SetLineWidth(3);
    antitagSRdata->SetMarkerColor(1);
    antitagSRdata->SetMarkerStyle(8);
    antitagSRdata->GetXaxis()->SetTitle("MET [GeV]");
    antitagSRdata->GetYaxis()->SetTitle("Events");
    TH1F* antitagSRmc = (TH1F*) f->Get(histTag+"_antitagSR_sum");
    assert(antitagSRmc);
    antitagSRmc = include_overflow(antitagSRmc);
    antitagSRmc->SetNameTitle("antitagSRmc","antitagSRmc");
    antitagSRmc->SetLineColor(2);
    antitagSRmc->SetLineWidth(3);
    antitagSRmc->SetFillColor(2);
    antitagSRmc->SetFillStyle(3490);
    antitagSRmc->GetXaxis()->SetTitle("MET [GeV]");
    antitagSRmc->GetYaxis()->SetTitle("Events");
    computeScaleFactor(antitagSRdata,antitagSRmc);

    TH1F* antitagSBdata = (TH1F*) f->Get(histTag+"_antitagSB_data");
    assert(antitagSBdata);
    antitagSBdata = include_overflow(antitagSBdata);
    antitagSBdata->SetLineColor(1);
    antitagSBdata->SetLineWidth(3);
    antitagSBdata->SetMarkerColor(1);
    antitagSBdata->SetMarkerStyle(8);
    antitagSBdata->GetXaxis()->SetTitle("MET [GeV]");
    antitagSBdata->GetYaxis()->SetTitle("Events");
    TH1F* antitagSBmc = (TH1F*) f->Get(histTag+"_antitagSB_sum");
    assert(antitagSBmc);
    antitagSBmc = include_overflow(antitagSBmc);
    antitagSBmc->SetNameTitle("antitagSBmc","antitagSBmc");
    antitagSBmc->SetLineColor(2);
    antitagSBmc->SetLineWidth(3);
    antitagSBmc->SetFillColor(2);
    antitagSBmc->SetFillStyle(3490);
    antitagSBmc->GetXaxis()->SetTitle("MET [GeV]");
    antitagSBmc->GetYaxis()->SetTitle("Events");
    computeScaleFactor(antitagSBdata,antitagSBmc);

    TH1F* allRegionsdata = new TH1F(*antitagSBdata);
    allRegionsdata->SetNameTitle("allRegionsdata","allRegionsdata");
    allRegionsdata->Add(antitagSRdata);
    allRegionsdata->Add(tagSBdata);
    allRegionsdata->Add(tagSRdata);
    allRegionsdata->Add(doubletagSBdata);
    allRegionsdata->Add(doubletagSRdata);
    allRegionsdata->SetLineColor(2);
    allRegionsdata->SetLineWidth(3);
    allRegionsdata->SetMarkerColor(1);
    allRegionsdata->SetMarkerStyle(8);
    allRegionsdata->GetXaxis()->SetTitle("MET [GeV]");
    allRegionsdata->GetYaxis()->SetTitle("Events");
    TH1F* allRegionsmc = new TH1F(*antitagSBmc);
    allRegionsmc->SetNameTitle("allRegionsmc","allRegionsmc");
    allRegionsmc->Add(antitagSRmc);
    allRegionsmc->Add(tagSBmc);
    allRegionsmc->Add(tagSRmc);
    allRegionsmc->Add(doubletagSBmc);
    allRegionsmc->Add(doubletagSRmc);
    allRegionsmc->SetLineColor(2);
    allRegionsmc->SetLineWidth(3);
    allRegionsmc->SetFillColor(2);
    allRegionsmc->SetFillStyle(3490);
    allRegionsmc->GetXaxis()->SetTitle("MET [GeV]");
    allRegionsmc->GetYaxis()->SetTitle("Events");
    computeScaleFactor(allRegionsdata,allRegionsmc);
    // ---------------------------------------------
    // ---------------------------------------------
    TH1F* prediction = new TH1F(*doubletagSRdata);
    assert(prediction);
    prediction->SetNameTitle("prediction","prediction");
    prediction->SetMarkerColor(4);
    prediction->SetLineColor(4);

    for( int i = 1 ; i <= doubletagSRmc->GetNbinsX() ; i++ ){        
        if( antitagSBdata->GetBinContent(i) > 0. ) 
            prediction->SetBinContent(i,doubletagSBdata->GetBinContent(i)/antitagSBdata->GetBinContent(i)*antitagSRdata->GetBinContent(i));
        else 
            prediction->SetBinContent(i,0.);
    }    
    // ---------------------------------------------
    // ---------------------------------------------
    TH1F* prediction_single = new TH1F(*tagSRdata);
    assert(prediction_single);
    prediction_single->SetNameTitle("prediction_single","prediction_single");
    prediction_single->SetMarkerColor(4);
    prediction_single->SetLineColor(4);

    for( int i = 1 ; i <= tagSRmc->GetNbinsX() ; i++ ){        
        if( antitagSBdata->GetBinContent(i) > 0. ) 
            prediction_single->SetBinContent(i,tagSBdata->GetBinContent(i)/antitagSBdata->GetBinContent(i)*antitagSRdata->GetBinContent(i));
        else 
            prediction_single->SetBinContent(i,0.);
    }    
    // ---------------------------------------------

    TCanvas* can = new TCanvas("can","can",800,800);
    TPad* topPad = new TPad("topPad","topPad",0.,0.4,.99,.99);
    TPad* botPad = new TPad("botPad","botPad",0.,0.01,.99,.39);
    botPad->SetBottomMargin(0.25);
    botPad->SetTopMargin(0.02);
    topPad->SetTopMargin(0.06);
    topPad->SetBottomMargin(0.17);
    topPad->Draw();
    botPad->Draw();
    topPad->cd();
    
    writeExtraText=true;
    extraText="Preliminary";
    lumi_13TeV="35.9 fb^{-1}";

    gStyle->SetErrorX(0.5);

    doubletagSRdata->GetYaxis()->SetRangeUser(0.,max(doubletagSRdata->GetMaximum(),max(doubletagSRmc->GetMaximum(),prediction->GetMaximum()))*1.3);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        doubletagSRdata->GetXaxis()->SetRangeUser(300.,900.);
    doubletagSRdata->Draw("p,e1");
    doubletagSRmc->Draw("SAME,e2");

    TString legLabel;
    legLabel = "double-tag";
    
    TLegend* leg = new TLegend(.6,.7,.9,.9,legLabel+" SR");
    leg->SetFillColor(0);
    leg->SetBorderSize(0);
    leg->AddEntry(doubletagSRdata,"data","pl");
    leg->AddEntry(doubletagSRmc,"MC pred.","pf");
    leg->Draw();

    CMS_lumi(can,4,0);
    can->Update();
    can->RedrawAxis();
    can->GetFrame()->Draw();
    
    botPad->cd();

    TGraphAsymmErrors MCRatio;
    cout << "doubletagSR:" << endl;
    SetRatioErr(doubletagSRdata,doubletagSRmc,MCRatio,true);
    setStyle(MCRatio);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        MCRatio.GetXaxis()->SetLimits(300.,900.);
    else if( histTag == "METfine" )
        MCRatio.GetXaxis()->SetLimits(101.,799.);
    MCRatio.Draw("A,p");

    TLine* scaleFactor = makeRatioLine(doubletagSRdata,doubletagSRmc,(tag=="_lowDphi"||tag == "_looseCuts_lowDphi"?300.:100.));
    scaleFactor->Draw();

    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_"+legLabel+"SR"+tag+".png");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_"+legLabel+"SR"+tag+".eps");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_"+legLabel+"SR"+tag+".pdf");
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    topPad->cd();

    doubletagSRdata->Draw("p,e1");
    prediction->Draw("SAME,p,e1");

    leg = new TLegend(.6,.7,.9,.9,legLabel+" SR");
    leg->SetFillColor(0);
    leg->SetBorderSize(0);
    leg->AddEntry(doubletagSRdata,"data","pl");
    leg->AddEntry(prediction,"ABCD pred.","pl");
    leg->Draw();

    CMS_lumi(can,4,0);
    can->Update();
    can->RedrawAxis();
    can->GetFrame()->Draw();
    
    botPad->cd();

    TGraphAsymmErrors predictionRatio;
    SetRatioErr(doubletagSRdata,prediction,predictionRatio);
    setStyle(predictionRatio);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        predictionRatio.GetXaxis()->SetLimits(300.,900.);
    else if( histTag == "METfine" )
        predictionRatio.GetXaxis()->SetLimits(101.,799.);
    predictionRatio.GetYaxis()->SetTitle("#kappa");
    predictionRatio.Draw("A,p");

    scaleFactor = makeRatioLine(doubletagSRdata,prediction,(tag=="_lowDphi"||tag == "_looseCuts_lowDphi"?300.:100.));
    scaleFactor->Draw();

    can->SaveAs("../plots/ABCDscaleFactors/dataClosure_"+histTag+"_double-tagSR"+tag+".png");
    can->SaveAs("../plots/ABCDscaleFactors/dataClosure_"+histTag+"_double-tagSR"+tag+".eps");
    can->SaveAs("../plots/ABCDscaleFactors/dataClosure_"+histTag+"_double-tagSR"+tag+".pdf");


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    topPad->cd();
    legLabel="single-tag";
    tagSRdata->Draw("p,e1");
    prediction_single->Draw("SAME,p,e1");

    leg = new TLegend(.6,.7,.9,.9,legLabel+" SR");
    leg->SetFillColor(0);
    leg->SetBorderSize(0);
    leg->AddEntry(tagSRdata,"data","pl");
    leg->AddEntry(prediction_single,"ABCD pred.","pl");
    leg->Draw();

    CMS_lumi(can,4,0);
    can->Update();
    can->RedrawAxis();
    can->GetFrame()->Draw();
    
    botPad->cd();

    SetRatioErr(tagSRdata,prediction_single,predictionRatio);
    setStyle(predictionRatio);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        predictionRatio.GetXaxis()->SetLimits(300.,900.);
    else if( histTag == "METfine" )
        predictionRatio.GetXaxis()->SetLimits(101.,799.);
    predictionRatio.GetYaxis()->SetTitle("#kappa");
    predictionRatio.Draw("A,p");

    scaleFactor = makeRatioLine(tagSRdata,prediction_single,(tag=="_lowDphi"||tag == "_looseCuts_lowDphi"?300.:100.));
    scaleFactor->Draw();

    can->SaveAs("../plots/ABCDscaleFactors/dataClosure_"+histTag+"_single-tagSR"+tag+".png");
    can->SaveAs("../plots/ABCDscaleFactors/dataClosure_"+histTag+"_single-tagSR"+tag+".eps");
    can->SaveAs("../plots/ABCDscaleFactors/dataClosure_"+histTag+"_single-tagSR"+tag+".pdf");

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    topPad->cd();
    legLabel="double-tag";
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        doubletagSBdata->GetXaxis()->SetRangeUser(300.,900.);
    doubletagSBdata->Draw("p,e1");
    doubletagSBmc->Draw("e2,SAME");
    leg = new TLegend(.6,.7,.9,.9,legLabel+" SB");
    leg->SetFillColor(0);
    leg->SetBorderSize(0);
    leg->AddEntry(doubletagSBdata,"data","pl");
    leg->AddEntry(doubletagSBmc,"MC pred.","pf");
    leg->Draw();
    CMS_lumi(can,4,0);
    can->Update();
    can->RedrawAxis();
    can->GetFrame()->Draw();

    botPad->cd();
    
    if( doubletag )
        cout << "doubletagSB: " << endl;
    else
        cout << "tagSB: " << endl;
    SetRatioErr(doubletagSBdata,doubletagSBmc,MCRatio,true);
    setStyle(MCRatio);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        MCRatio.GetXaxis()->SetLimits(300.,900.);
    else if( histTag == "METfine" )
        MCRatio.GetXaxis()->SetLimits(101.,799.);
    MCRatio.Draw("A,p");

    scaleFactor = makeRatioLine(doubletagSBdata,doubletagSBmc,(tag=="_lowDphi"||tag == "_looseCuts_lowDphi"?300.:100.));
    scaleFactor->Draw();

    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_"+legLabel+"SB"+tag+".png");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_"+legLabel+"SB"+tag+".eps");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_"+legLabel+"SB"+tag+".pdf");

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    topPad->cd();

    antitagSRdata->GetYaxis()->SetRangeUser(0.,max(antitagSRdata->GetMaximum(),antitagSRmc->GetMaximum())*1.3);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        antitagSRdata->GetXaxis()->SetRangeUser(300.,900.);
    antitagSRdata->Draw("p,e1");
    antitagSRmc->Draw("e2,SAME");
    leg = new TLegend(.6,.7,.9,.9,"anti-tag SR");
    leg->SetFillColor(0);
    leg->SetBorderSize(0);
    leg->AddEntry(antitagSRdata,"data","pl");
    leg->AddEntry(antitagSRmc,"MC pred.","pf");
    leg->Draw();
    CMS_lumi(can,4,0);
    can->Update();
    can->RedrawAxis();
    can->GetFrame()->Draw();

    botPad->cd();

    cout << "antitagSR:" << endl;
    SetRatioErr(antitagSRdata,antitagSRmc,MCRatio,true);
    setStyle(MCRatio);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        MCRatio.GetXaxis()->SetLimits(300.,900.);
    else if( histTag == "METfine" )
        MCRatio.GetXaxis()->SetLimits(101.,799.);
    MCRatio.Draw("A,p");

    scaleFactor = makeRatioLine(antitagSRdata,antitagSRmc,(tag=="_lowDphi"||tag == "_looseCuts_lowDphi"?300.:100.));
    scaleFactor->Draw();

    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_antitagSR"+tag+".png");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_antitagSR"+tag+".eps");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_antitagSR"+tag+".pdf");

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    topPad->cd();

    tagSRdata->GetYaxis()->SetRangeUser(0.,max(tagSRdata->GetMaximum(),tagSRmc->GetMaximum())*1.3);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        tagSRdata->GetXaxis()->SetRangeUser(300.,900.);
    tagSRdata->Draw("p,e1");
    tagSRmc->Draw("e2,SAME");
    leg = new TLegend(.6,.7,.9,.9,"anti-tag SR");
    leg->SetFillColor(0);
    leg->SetBorderSize(0);
    leg->AddEntry(tagSRdata,"data","pl");
    leg->AddEntry(tagSRmc,"MC pred.","pf");
    leg->Draw();
    CMS_lumi(can,4,0);
    can->Update();
    can->RedrawAxis();
    can->GetFrame()->Draw();

    botPad->cd();

    cout << "tagSR:" << endl;
    SetRatioErr(tagSRdata,tagSRmc,MCRatio,true);
    setStyle(MCRatio);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        MCRatio.GetXaxis()->SetLimits(300.,900.);
    else if( histTag == "METfine" )
        MCRatio.GetXaxis()->SetLimits(101.,799.);
    MCRatio.Draw("A,p");

    scaleFactor = makeRatioLine(tagSRdata,tagSRmc,(tag=="_lowDphi"||tag == "_looseCuts_lowDphi"?300.:100.));
    scaleFactor->Draw();

    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_tagSR"+tag+".png");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_tagSR"+tag+".eps");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_tagSR"+tag+".pdf");

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    topPad->cd();

    tagSBdata->GetYaxis()->SetRangeUser(0.,max(tagSBdata->GetMaximum(),tagSBmc->GetMaximum())*1.3);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        tagSBdata->GetXaxis()->SetRangeUser(300.,900.);
    tagSBdata->Draw("p,e1");
    tagSBmc->Draw("e2,SAME");
    leg = new TLegend(.6,.7,.9,.9,"anti-tag SB");
    leg->SetFillColor(0);
    leg->SetBorderSize(0);
    leg->AddEntry(tagSBdata,"data","pl");
    leg->AddEntry(tagSBmc,"MC pred.","pf");
    leg->Draw();
    CMS_lumi(can,4,0);
    can->Update();
    can->RedrawAxis();
    can->GetFrame()->Draw();

    botPad->cd();

    cout << "tagSB:" << endl;
    SetRatioErr(tagSBdata,tagSBmc,MCRatio,true);
    setStyle(MCRatio);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        MCRatio.GetXaxis()->SetLimits(300.,900.);
    else if( histTag == "METfine" )
        MCRatio.GetXaxis()->SetLimits(101.,799.);
    MCRatio.Draw("A,p");

    scaleFactor = makeRatioLine(tagSBdata,tagSBmc,(tag=="_lowDphi"||tag == "_looseCuts_lowDphi"?300.:100.));
    scaleFactor->Draw();

    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_tagSB"+tag+".png");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_tagSB"+tag+".eps");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_tagSB"+tag+".pdf");

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    topPad->cd();
        
    antitagSBdata->GetYaxis()->SetRangeUser(0.,max(antitagSBdata->GetMaximum(),antitagSBmc->GetMaximum())*1.3);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        antitagSBdata->GetXaxis()->SetRangeUser(300.,900.);
    antitagSBdata->Draw("p,e1");
    antitagSBmc->Draw("e2,SAME");
    leg = new TLegend(.6,.7,.9,.9,"anti-tag SB");
    leg->SetFillColor(0);
    leg->SetBorderSize(0);
    leg->AddEntry(antitagSBdata,"data","pl");
    leg->AddEntry(antitagSBmc,"MC pred.","pf");
    leg->Draw();
    CMS_lumi(can,4,0);
    can->Update();
    can->RedrawAxis();
    can->GetFrame()->Draw();

    botPad->cd();

    cout << "antitagSB: " << endl;
    SetRatioErr(antitagSBdata,antitagSBmc,MCRatio,true);
    setStyle(MCRatio);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        MCRatio.GetXaxis()->SetLimits(300.,900.);
    else if( histTag == "METfine" )
        MCRatio.GetXaxis()->SetLimits(101.,799.);
    MCRatio.Draw("A,p");

    scaleFactor = makeRatioLine(antitagSBdata,antitagSBmc,(tag=="_lowDphi"||tag == "_looseCuts_lowDphi"?300.:100.));
    scaleFactor->Draw();

    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_antitagSB"+tag+".png");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_antitagSB"+tag+".eps");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_antitagSB"+tag+".pdf");

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    topPad->cd();
        
    allRegionsdata->GetYaxis()->SetRangeUser(0.,max(allRegionsdata->GetMaximum(),allRegionsmc->GetMaximum())*1.3);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        allRegionsdata->GetXaxis()->SetRangeUser(300.,900.);
    allRegionsdata->Draw("p,e1");
    allRegionsmc->Draw("e2,SAME");
    leg = new TLegend(.6,.7,.9,.9,"all regions");
    leg->SetFillColor(0);
    leg->SetBorderSize(0);
    leg->AddEntry(allRegionsdata,"data","pl");
    leg->AddEntry(allRegionsmc,"MC pred.","pf");
    leg->Draw();
    CMS_lumi(can,4,0);
    can->Update();
    can->RedrawAxis();
    can->GetFrame()->Draw();

    botPad->cd();

    cout << "all regions: " << endl;
    SetRatioErr(allRegionsdata,allRegionsmc,MCRatio,true);
    setStyle(MCRatio);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        MCRatio.GetXaxis()->SetLimits(300.,900.);
    else if( histTag == "METfine" )
        MCRatio.GetXaxis()->SetLimits(101.,799.);
    MCRatio.Draw("A,p");

    scaleFactor = makeRatioLine(allRegionsdata,allRegionsmc,(tag=="_lowDphi"||tag == "_looseCuts_lowDphi"?300.:100.));
    scaleFactor->Draw();

    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_allregions"+tag+".png");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_allregions"+tag+".eps");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+histTag+"_allregions"+tag+".pdf");

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    cout << "// - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "// Integrated stats " << endl;
    cout << "// - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "antitag SR: " << endl;
    computeIntegratedRatio(antitagSRdata,antitagSRmc,integrate_from,integrate_to,true);
    cout << "antitag SB: " << endl;
    computeIntegratedRatio(antitagSBdata,antitagSBmc,integrate_from,integrate_to,true);
    cout << "doubletag SR: " << endl;
    computeIntegratedRatio(doubletagSRdata,doubletagSRmc,integrate_from,integrate_to,true);
    cout << "doubletag SB: " << endl;
    computeIntegratedRatio(doubletagSBdata,doubletagSBmc,integrate_from,integrate_to,true);
    cout << "tag SR: " << endl;
    computeIntegratedRatio(tagSRdata,tagSRmc,integrate_from,integrate_to,true);
    cout << "tag SB: " << endl;
    computeIntegratedRatio(tagSBdata,tagSBmc,integrate_from,integrate_to,true);
    cout << "all regions:" << endl;
    computeIntegratedRatio(allRegionsdata,allRegionsmc,integrate_from,integrate_to,true);

    cout << "closure 2H: " << endl;
    computeIntegratedRatio(doubletagSRdata,prediction,integrate_from,integrate_to,true);
    cout << "closure 1H: " << endl;
    computeIntegratedRatio(tagSRdata,prediction_single,integrate_from,integrate_to,true);

}

TH1F* include_overflow(TH1F* h){
    TString name = h->GetName();
    name+="_withOverflow";
    const int nBins=h->GetNbinsX();
    double bins[nBins+2];
    for( int i = 1 ; i <= nBins ; i++ ){
        bins[i-1] = h->GetBinLowEdge(i);
    }
    bins[nBins] = h->GetBinLowEdge(nBins)+h->GetBinWidth(nBins);
    bins[nBins+1] = h->GetBinLowEdge(nBins)+2*h->GetBinWidth(nBins);
    TH1F* result = new TH1F(name,name,nBins+1,bins);
    for( int i = 1 ; i < h->GetNbinsX()+2 ; i++ ){
        result->SetBinContent(i,h->GetBinContent(i));
        result->SetBinError(i,h->GetBinError(i));
    }
    return result;
}

void computeIntegratedRatio(TH1F* num, TH1F* denom, int start_bin=1, int end_bin=4,bool verbose=false){
    
    TH1F* num_int = new TH1F("num_int","num_int",1,100,900);
    TH1F* denom_int = new TH1F("denom_int","denom_int",1,100,900);
    double error;

    num_int->SetBinContent(1,num->IntegralAndError(start_bin,end_bin,error));
    num_int->SetBinError(1,error);

    denom_int->SetBinContent(1,denom->IntegralAndError(start_bin,end_bin,error));
    denom_int->SetBinError(1,error);

    TGraphAsymmErrors graph;
    SetRatioErr(num_int,denom_int,graph,verbose);

    delete num_int;
    delete denom_int;
}

void computeScaleFactor(TH1F* hdata,TH1F* hmc, bool verbose=false){
    double yieldmc,yeilddata,errmc,errdata;

    yieldmc = hmc->IntegralAndError(1,hmc->GetNbinsX(),errmc) ; 
    yielddata = hdata->IntegralAndError(1,hdata->GetNbinsX(),errdata) ;
    if( verbose ){
        if( yielddata == 0. )
            cout << " 0. +/- " <<  sqrt(errmc*errmc+1.67*1.67);
        else 
            cout << yielddata/yieldmc << " +/- " << sqrt(errmc*errmc/yieldmc/yieldmc+errdata*errdata/yielddata/yielddata)*yielddata/yieldmc;
    }
}

void setStyle(TGraphAsymmErrors& graph, TString ylabel="Data/MC"){
    graph.GetXaxis()->SetLimits(100.,900.);
    double maximum = TMath::MaxElement(graph.GetN(),graph.GetY());
    graph.GetYaxis()->SetRangeUser(0.,max(maximum*1.2,2.0));
    graph.GetYaxis()->SetTitle(ylabel);
    graph.GetXaxis()->SetTitle("MET [GeV]");
    graph.GetYaxis()->SetNdivisions(503);

    graph.GetYaxis()->SetLabelFont(43);
    graph.GetYaxis()->SetLabelSize(23);
    graph.GetYaxis()->SetTitleFont(43);
    graph.GetYaxis()->SetTitleSize(27);
    graph.GetYaxis()->SetTitleOffset(2.0);
    
    graph.GetXaxis()->SetLabelFont(43);
    graph.GetXaxis()->SetLabelSize(23);
    graph.GetXaxis()->SetTitleFont(43);
    graph.GetXaxis()->SetTitleSize(27);
    graph.GetXaxis()->SetTitleOffset(2.3);
    
    graph.SetLineColor(1);
    graph.SetMarkerColor(1);
    graph.SetMarkerStyle(8);
}

void setStyle(TH1F& hist, TString ylabel="Data/MC"){
    hist.GetXaxis()->SetLimits(100.,900.);
    double maximum = hist.GetMaximum();
    hist.GetYaxis()->SetRangeUser(0.,max(maximum*1.2,2.0));
    hist.GetYaxis()->SetTitle(ylabel);
    hist.GetXaxis()->SetTitle("MET [GeV]");
    hist.GetYaxis()->SetNdivisions(503);

    hist.GetYaxis()->SetLabelFont(43);
    hist.GetYaxis()->SetLabelSize(23);
    hist.GetYaxis()->SetTitleFont(43);
    hist.GetYaxis()->SetTitleSize(27);
    hist.GetYaxis()->SetTitleOffset(2.0);
    
    hist.GetXaxis()->SetLabelFont(43);
    hist.GetXaxis()->SetLabelSize(23);
    hist.GetXaxis()->SetTitleFont(43);
    hist.GetXaxis()->SetTitleSize(27);
    hist.GetXaxis()->SetTitleOffset(2.3);
    
    hist.SetLineColor(1);
    hist.SetMarkerColor(1);
    hist.SetMarkerStyle(8);
}

TH1F* makeRatio(TH1F* num , TH1F* denom, TString ylabel="Data/MC"){

    TH1F* Ratio = new TH1F(*num);
    Ratio->SetNameTitle("MCRatio","MCRatio");
    Ratio->GetYaxis()->SetRangeUser(0.,2.);
    Ratio->GetYaxis()->SetTitle(ylabel);
    Ratio->GetYaxis()->SetNdivisions(503);

    Ratio->GetYaxis()->SetLabelFont(43);
    Ratio->GetYaxis()->SetLabelSize(23);
    Ratio->GetYaxis()->SetTitleFont(43);
    Ratio->GetYaxis()->SetTitleSize(27);
    Ratio->GetYaxis()->SetTitleOffset(2.0);
    
    Ratio->GetXaxis()->SetLabelFont(43);
    Ratio->GetXaxis()->SetLabelSize(23);
    Ratio->GetXaxis()->SetTitleFont(43);
    Ratio->GetXaxis()->SetTitleSize(27);
    Ratio->GetXaxis()->SetTitleOffset(2.3);
    
    Ratio->SetFillColor(2);
    Ratio->SetLineColor(0);
    Ratio->SetFillStyle(3490);
    Ratio->Divide(denom);

    return Ratio;

}

TLine* makeRatioLine(TH1F* num , TH1F* denom, double lower, double upper=900.){
    TLine* line = new TLine(lower,num->Integral()/denom->Integral(),900.,num->Integral()/denom->Integral());
    line->SetLineStyle(2);
    line->SetLineWidth(2);
    return line;
}

