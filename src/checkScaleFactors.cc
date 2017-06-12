#include "CMS_lumi.cc"
#include "computeRatio.h"

void computeIntegratedRatio(TH1F* num, TH1F* denom){
    
    TH1F* num_int = new TH1F("num_int","num_int",1,100,900);
    TH1F* denom_int = new TH1F("denom_int","denom_int",1,100,900);
    double error;

    num_int->SetBinContent(1,num->IntegralAndError(1,4,error));
    num_int->SetBinError(1,error);

    denom_int->SetBinContent(1,denom->IntegralAndError(1,4,error));
    denom_int->SetBinError(1,error);

    TGraphAsymmErrors graph;
    SetRatioErr(num_int,denom_int,graph,1,100.,1000.);

    delete num_int;
    delete denom_int;
}

void computeScaleFactor(TH1F* hdata,TH1F* hmc){
    double yieldmc,yeilddata,errmc,errdata;

    //cout << "hdata: " << hdata << endl;
    //cout << "hmc: " << hmc << endl;

    yieldmc = hmc->IntegralAndError(1,3,errmc) ; 
    yielddata = hdata->IntegralAndError(1,3,errdata) ;
    if( yielddata == 0. )
        cout << " 0. +/- " <<  sqrt(errmc*errmc+1.67*1.67);
    else 
        cout << yielddata/yieldmc << " +/- " << sqrt(errmc*errmc/yieldmc/yieldmc+errdata*errdata/yielddata/yielddata)*yielddata/yieldmc;
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

void checkScaleFactors(TString tag = "_singleMu", bool doubletag = true, TString baseDir="./"){

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    TFile* f = new TFile(baseDir+"ALPHABEThistos"+tag+".root","READ");
    TH1F* hdata,*hmc;

    TString tagString;
    if(doubletag)
        tagString = "doubletag" ;
    else 
        tagString = "tag" ;

    TH1F* doubletagSRdata = new TH1F(tagString+"SRdata",tagString+"SRdata",4,100,900);
    doubletagSRdata->SetLineColor(1);
    doubletagSRdata->SetLineWidth(3);
    doubletagSRdata->SetMarkerColor(1);
    doubletagSRdata->SetMarkerStyle(8);
    doubletagSRdata->GetXaxis()->SetTitle("MET [GeV]");
    doubletagSRdata->GetYaxis()->SetTitle("Events");
    //doubletagSRdata->GetXaxis()->SetRangeUser(301,900);
    TH1F* doubletagSBdata = new TH1F(*doubletagSRdata);
    doubletagSBdata->SetNameTitle(tagString+"SBdata",tagString+"SBdata");
    TH1F* antitagSRdata = new TH1F(*doubletagSRdata);
    antitagSRdata->SetNameTitle("antitagSRdata","antitagSRdata");
    TH1F* antitagSBdata = new TH1F(*doubletagSRdata);
    antitagSBdata->SetNameTitle("antitagSBdata","antitagSBdata");

    TH1F* doubletagSRmc = new TH1F(tagString+"SRmc",tagString+"SRmc",4,100,900);
    doubletagSRmc->SetLineColor(2);
    doubletagSRmc->SetLineWidth(3);
    doubletagSRmc->SetFillColor(2);
    doubletagSRmc->SetFillStyle(3490);
    doubletagSRmc->GetXaxis()->SetTitle("MET [GeV]");
    doubletagSRmc->GetYaxis()->SetTitle("Events");
    //doubletagSRmc->GetXaxis()->SetRangeUser(301,900);
    TH1F* doubletagSBmc = new TH1F(*doubletagSRmc);
    doubletagSBmc->SetNameTitle(tagString+"SBmc",tagString+"SBmc");
    TH1F* antitagSRmc = new TH1F(*doubletagSRmc);
    antitagSRmc->SetNameTitle("antitagSRmc","antitagSRmc");
    TH1F* antitagSBmc = new TH1F(*doubletagSRmc);
    antitagSBmc->SetNameTitle("antitagSBmc","antitagSBmc");

    TH1F* prediction = new TH1F(*doubletagSRdata);
    prediction->SetNameTitle("prediction","prediction");
    prediction->SetMarkerColor(4);
    prediction->SetLineColor(4);

    cout << "\\begin{tabular}{|c|c|}" << endl;

    // ---------------------------------------------
    cout << "\\multicolumn{2}{c}{100 $<$ MET $<$ 300} \\\\ \\hline" << endl;
    hdata = (TH1F*) f->Get("mJ_"+tagString+"SR_100_data");
    hmc = (TH1F*) f->Get("mJ_"+tagString+"SR_100_sum");
    cout << std::setprecision(2) << "$\\alpha_{}$ & ";
    computeScaleFactor(hdata,hmc);
    doubletagSRdata->SetBinContent(1,hdata->Integral(1,3));
    doubletagSRmc->SetBinContent(1,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_"+tagString+"SB_100_data");
    hmc = (TH1F*) f->Get("mJ_"+tagString+"SB_100_sum");
    cout << "$\\beta_{}$ &";
    computeScaleFactor(hdata,hmc);
    doubletagSBdata->SetBinContent(1,hdata->Integral(1,3));
    doubletagSBmc->SetBinContent(1,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_antitagSR_100_data");
    hmc = (TH1F*) f->Get("mJ_antitagSR_100_sum");
    cout << "$\\gamma_{}$ & ";
    computeScaleFactor(hdata,hmc);
    antitagSRdata->SetBinContent(1,hdata->Integral(1,3));
    antitagSRmc->SetBinContent(1,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_antitagSB_100_data");
    hmc = (TH1F*) f->Get("mJ_antitagSB_100_sum");
    cout << "$\\delta_{}$ & ";
    computeScaleFactor(hdata,hmc);
    antitagSBdata->SetBinContent(1,hdata->Integral(1,3));
    antitagSBmc->SetBinContent(1,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    // ---------------------------------------------
    cout << "\\multicolumn{2}{c}{300 $<$ MET $<$ 500} \\\\ \\hline" << endl;
    hdata = (TH1F*) f->Get("mJ_"+tagString+"SR_300_data");
    hmc = (TH1F*) f->Get("mJ_"+tagString+"SR_300_sum");
    cout << "$\\alpha_{}$ & ";
    computeScaleFactor(hdata,hmc);
    doubletagSRdata->SetBinContent(2,hdata->Integral(1,3));
    doubletagSRmc->SetBinContent(2,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_"+tagString+"SB_300_data");
    hmc = (TH1F*) f->Get("mJ_"+tagString+"SB_300_sum");
    cout << "$\\beta_{}$ & ";
    computeScaleFactor(hdata,hmc);
    doubletagSBdata->SetBinContent(2,hdata->Integral(1,3));
    doubletagSBmc->SetBinContent(2,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_antitagSR_300_data");
    hmc = (TH1F*) f->Get("mJ_antitagSR_300_sum");
    cout << "$\\gamma_{}$ & ";
    computeScaleFactor(hdata,hmc);
    antitagSRdata->SetBinContent(2,hdata->Integral(1,3));
    antitagSRmc->SetBinContent(2,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_antitagSB_300_data");
    hmc = (TH1F*) f->Get("mJ_antitagSB_300_sum");
    cout << "$\\delta_{}$ & ";
    computeScaleFactor(hdata,hmc);
    antitagSBdata->SetBinContent(2,hdata->Integral(1,3));
    antitagSBmc->SetBinContent(2,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;
    
    // ---------------------------------------------
    cout << "\\multicolumn{2}{c}{500 $<$ MET $<$ 700} \\\\ \\hline" << endl;
    hdata = (TH1F*) f->Get("mJ_"+tagString+"SR_500_data");
    hmc = (TH1F*) f->Get("mJ_"+tagString+"SR_500_sum");
    cout << "$\\alpha_{}$ & ";
    computeScaleFactor(hdata,hmc);
    doubletagSRdata->SetBinContent(3,hdata->Integral(1,3));
    doubletagSRmc->SetBinContent(3,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_"+tagString+"SB_500_data");
    hmc = (TH1F*) f->Get("mJ_"+tagString+"SB_500_sum");
    cout << "$\\beta_{}$ & ";
    computeScaleFactor(hdata,hmc);
    doubletagSBdata->SetBinContent(3,hdata->Integral(1,3));
    doubletagSBmc->SetBinContent(3,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_antitagSR_500_data");
    hmc = (TH1F*) f->Get("mJ_antitagSR_500_sum");
    cout << "$\\gamma_{}$ & ";
    computeScaleFactor(hdata,hmc);
    antitagSRdata->SetBinContent(3,hdata->Integral(1,3));
    antitagSRmc->SetBinContent(3,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_antitagSB_500_data");
    hmc = (TH1F*) f->Get("mJ_antitagSB_500_sum");
    cout << "$\\delta_{}$ & ";
    computeScaleFactor(hdata,hmc);
    antitagSBdata->SetBinContent(3,hdata->Integral(1,3));
    antitagSBmc->SetBinContent(3,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    // ---------------------------------------------
    cout << "\\multicolumn{2}{c}{MET $>$ 700} \\\\ \\hline" << endl;
    hdata = (TH1F*) f->Get("mJ_"+tagString+"SR_700_data");
    hmc = (TH1F*) f->Get("mJ_"+tagString+"SR_700_sum");
    cout << "$\\alpha_{}$ & ";
    computeScaleFactor(hdata,hmc);
    doubletagSRdata->SetBinContent(4,hdata->Integral(1,3));
    doubletagSRmc->SetBinContent(4,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_"+tagString+"SB_700_data");
    hmc = (TH1F*) f->Get("mJ_"+tagString+"SB_700_sum");
    cout << "$\\beta_{}$ & ";
    computeScaleFactor(hdata,hmc);
    doubletagSBdata->SetBinContent(4,hdata->Integral(1,3));
    doubletagSBmc->SetBinContent(4,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_antitagSR_700_data");
    hmc = (TH1F*) f->Get("mJ_antitagSR_700_sum");
    cout << "$\\gamma_{}$ & ";
    computeScaleFactor(hdata,hmc);
    antitagSRdata->SetBinContent(4,hdata->Integral(1,3));
    antitagSRmc->SetBinContent(4,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_antitagSB_700_data");
    hmc = (TH1F*) f->Get("mJ_antitagSB_700_sum");
    cout << "$\\delta_{}$ & ";
    computeScaleFactor(hdata,hmc);
    antitagSBdata->SetBinContent(4,hdata->Integral(1,3));
    antitagSBmc->SetBinContent(4,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;
    // ---------------------------------------------
    cout << "\\multicolumn{2}{c}{All MET} \\\\ \\hline" << endl;
    cout << "$\\alpha_{}$ & ";
    computeScaleFactor(doubletagSRdata,doubletagSRmc);
    cout << " \\\\ \\hline" << endl;

    cout << "$\\beta_{}$ & ";
    computeScaleFactor(doubletagSBdata,doubletagSBmc);
    cout << " \\\\ \\hline" << endl;

    cout << "$\\gamma_{}$ & ";
    computeScaleFactor(antitagSRdata,antitagSRmc);
    cout << " \\\\ \\hline" << endl;
    
    cout << "$\\delta_{}$ & ";
    computeScaleFactor(antitagSBdata,antitagSBmc);
    cout << " \\\\ \\hline" << endl;
    cout << "\\end{tabular}" << endl;
    // ---------------------------------------------
    // ---------------------------------------------
    for( int i = 1 ; i <= doubletagSRmc->GetNbinsX() ; i++ ){        
        if( antitagSBdata->GetBinContent(i) > 0. ) 
            prediction->SetBinContent(i,doubletagSBdata->GetBinContent(i)/antitagSBdata->GetBinContent(i)*antitagSRdata->GetBinContent(i));
        else 
            prediction->SetBinContent(i,0.);
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
    if( doubletag )
        legLabel = "double-tag";
    else
        legLabel = "single-tag";
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
    SetRatioErr(doubletagSRdata,doubletagSRmc,MCRatio);
    setStyle(MCRatio);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        MCRatio.GetXaxis()->SetLimits(300.,900.);
    MCRatio.Draw("A,p");

    TLine* scaleFactor = makeRatioLine(doubletagSRdata,doubletagSRmc,(tag=="_lowDphi"||tag == "_looseCuts_lowDphi"?300.:100.));
    scaleFactor->Draw();

    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+legLabel+"SR"+tag+".png");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+legLabel+"SR"+tag+".eps");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+legLabel+"SR"+tag+".pdf");
    
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
    predictionRatio.Draw("A,p");

    scaleFactor = makeRatioLine(doubletagSRdata,prediction,(tag=="_lowDphi"||tag == "_looseCuts_lowDphi"?300.:100.));
    scaleFactor->Draw();

    can->SaveAs("../plots/ABCDscaleFactors/dataClosure_"+legLabel+"SR"+tag+".png");
    can->SaveAs("../plots/ABCDscaleFactors/dataClosure_"+legLabel+"SR"+tag+".eps");
    can->SaveAs("../plots/ABCDscaleFactors/dataClosure_"+legLabel+"SR"+tag+".pdf");

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    topPad->cd();

    doubletagSBdata->GetYaxis()->SetRangeUser(0.,max(doubletagSBdata->GetMaximum(),doubletagSBmc->GetMaximum())*1.3);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        doubletagSBdata->GetYaxis()->SetRangeUser(300.,900.);
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

    SetRatioErr(doubletagSBdata,doubletagSBmc,MCRatio);
    setStyle(MCRatio);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        MCRatio.GetXaxis()->SetLimits(300.,900.);
    MCRatio.Draw("A,p");

    scaleFactor = makeRatioLine(doubletagSBdata,doubletagSBmc,(tag=="_lowDphi"||tag == "_looseCuts_lowDphi"?300.:100.));
    scaleFactor->Draw();

    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+legLabel+"SB"+tag+".png");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+legLabel+"SB"+tag+".eps");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_"+legLabel+"SB"+tag+".pdf");

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

    SetRatioErr(antitagSRdata,antitagSRmc,MCRatio);
    setStyle(MCRatio);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        MCRatio.GetXaxis()->SetLimits(300.,900.);
    MCRatio.Draw("A,p");

    scaleFactor = makeRatioLine(antitagSRdata,antitagSRmc,(tag=="_lowDphi"||tag == "_looseCuts_lowDphi"?300.:100.));
    scaleFactor->Draw();

    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_antitagSR"+tag+".png");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_antitagSR"+tag+".eps");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_antitagSR"+tag+".pdf");

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

    SetRatioErr(antitagSBdata,antitagSBmc,MCRatio);
    setStyle(MCRatio);
    if( tag == "_lowDphi" || tag == "_looseCuts_lowDphi" )
        MCRatio.GetXaxis()->SetLimits(300.,900.);
    MCRatio.Draw("A,p");

    scaleFactor = makeRatioLine(antitagSBdata,antitagSBmc,(tag=="_lowDphi"||tag == "_looseCuts_lowDphi"?300.:100.));
    scaleFactor->Draw();

    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_antitagSB"+tag+".png");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_antitagSB"+tag+".eps");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors_antitagSB"+tag+".pdf");

    cout << "// - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "// Integrated stats " << endl;
    cout << "// - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "antitag SR: " << endl;
    computeIntegratedRatio(antitagSRdata,antitagSRmc);
    cout << "antitag SB: " << endl;
    computeIntegratedRatio(antitagSBdata,antitagSBmc);
    if(doubletag)
        cout << "doubletag SR: " << endl;
    else
        cout << "tag SR: " << endl;
    computeIntegratedRatio(doubletagSRdata,doubletagSRmc);
    if(doubletag)
        cout << "doubletag SB: " << endl;
    else 
        cout << "tag SB: " << endl;
    computeIntegratedRatio(doubletagSBdata,doubletagSBmc);
    
}

