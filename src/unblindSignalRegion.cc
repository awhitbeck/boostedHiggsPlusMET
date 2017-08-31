#include "CMS_lumi.cc"
#include "TH1F.h"
#include "TString.h"
#include "TCanvas.h"
#include "TFile.h"
#include "THStack.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TPad.h"

#include <cassert>
#include <iostream>

using namespace std;

double lumi = 35862.824;

void apply_met_dep_scale_factors(TH1F& h, vector<double> sf, vector<double> sf_err){
    if( h.GetNbinsX() > sf.size() || h.GetNbinsX() > sf_err.size() ){
        cout << "inputs are inconsistent: " << h.GetNbinsX() << " versus: " << sf.size() << " / " << sf_err.size() << endl;
        return;
    }
    double y,e;
    for( int i = 1 ; i <= h.GetNbinsX() ; i++ ){
        y = h.GetBinContent(i);
        e = h.GetBinError(i);
        h.SetBinContent(i,y*sf[i-1]);
        h.SetBinError(i,sqrt(e*e/y/y+sf_err[i-1]*sf_err[i-1]/sf[i-1]/sf[i-1])*y*sf[i-1]);
    }
}

void init_sum(TH1F& h){
    for( int i = 1 ; i <= h.GetNbinsX() ; i++ ){
        if( h.GetBinContent(i) == 0. )
            h.SetBinError(i,0.);
    }
}

void sum_histo(TH1F& target,TH1F* sum){
    assert( target.GetNbinsX() == sum->GetNbinsX() );
    for( int i = 1 ; i <= target.GetNbinsX() ; i++ ){
        if( sum->GetBinContent(i)>0. ){
            target.SetBinContent(i,target.GetBinContent(i)+sum->GetBinContent(i));
            target.SetBinError(i,sqrt(target.GetBinError(i)*target.GetBinError(i)+sum->GetBinError(i)*sum->GetBinError(i)));
        }
    }
}

TH1F* include_overflow(TH1F* h){
    TString name = h->GetName();
    name+="_withOverflow";
    TH1F* result = new TH1F(name,name,h->GetNbinsX(),h->GetBinLowEdge(2),h->GetBinLowEdge(h->GetNbinsX())+2*h->GetBinWidth(h->GetNbinsX()));
    for( int i = 2 ; i <= h->GetNbinsX()+1 ; i++ ){
        result->SetBinContent(i-1,h->GetBinContent(i));
        result->SetBinError(i-1,h->GetBinError(i));
    }
    return result;
}

TH1F* shift_histo(TH1F* h,double shift = 1.0){
    TString name = h->GetName();
    name+="_shifted";
    TH1F* result = new TH1F(name,name,h->GetNbinsX(),h->GetBinLowEdge(1)+shift,h->GetBinLowEdge(h->GetNbinsX())+h->GetBinWidth(h->GetNbinsX())+shift);
    for(int i = 1 ; i < h->GetNbinsX()+1 ; i++){
        result->SetBinContent(i,h->GetBinContent(i));
        result->SetBinError(i,h->GetBinError(i));
    }
    return result;
}

void dump_histo(TH1F& h){
    cout << "histo dump: " << h.GetName() << endl;
    for( int i = 1 ; i<=h.GetNbinsX() ; i++ ){
        cout << "binContent("<<i<<"): " << h.GetBinContent(i) << " +/- " << h.GetBinError(i) << endl;
    }
}

void set_style(TH1& h,int fillColor=1){
    h.SetFillColor(fillColor);
    h.SetLineColor(1);
    h.SetLineStyle(1);
    h.SetLineWidth(2);
}

void style_axes(TH1& h){
    h.GetYaxis()->SetLabelFont(43);
    h.GetYaxis()->SetLabelSize(14);
    h.GetYaxis()->SetTitleFont(43);
    h.GetYaxis()->SetTitleSize(20);
    h.GetYaxis()->SetTitleOffset(1.6);
    
    h.GetXaxis()->SetLabelFont(43);
    h.GetXaxis()->SetLabelSize(14);
    h.GetXaxis()->SetTitleFont(43);
    h.GetXaxis()->SetTitleSize(20);
    h.GetXaxis()->SetTitleOffset(1.8);
    h.GetXaxis()->SetNdivisions(503);
}

int main(int argc, char** argv){
    
    TString inputDir = "deb5600d74266f4c654c8e7478d2b2f01aa75606";
    bool doubletag = true;
    bool verbose = false;
    bool looseCuts = false;
    if( argc >= 3 )
        inputDir = argv[1];
    if( argc >= 3 )
        doubletag = atoi(argv[2]);
    if( argc >= 4 )
        verbose = atoi(argv[3]);
    if( argc >= 5 )
        looseCuts = atoi(argv[4]);

    vector<vector<double> > corrTT(6);
    vector<vector<double> > corrErrTT(6);
    vector<vector<double> > corrWJets(6);
    vector<vector<double> > corrErrWJets(6);
    vector<vector<double> > corrZJets(6);
    vector<vector<double> > corrErrZJets(6);
    vector<vector<double> > corrQCD(6);
    vector<vector<double> > corrErrQCD(6);
    
    vector<double> kappa2H={0.82,0.53,0.61};
    vector<double> kappa2HErr={0.19,0.17,0.30};

    vector<double> kappa1H={1.03,1.03,0.83};
    vector<double> kappa1HErr={0.15,0.22,0.18};

    TString regionTags[6] = {"doubletagSR","doubletagSB","tagSR","tagSB","antitagSR","antitagSB"};

    enum regions {kA2,kB2,kA1,kB1,kC,kD,kNumRegions};

    // these are relative uncertainties!
    vector<double> singleLepMETunc={0.015777,0.088778,0.12758};

    // scale factors and errors for each backgrounds
    corrTT[kA2]=vector<double>(3,0.59);      corrErrTT[kA2]=vector<double>(3,0.082);
    corrTT[kB2]=vector<double>(3,0.71);      corrErrTT[kB2]=vector<double>(3,0.037);
    corrTT[kA1]=vector<double>(3,0.61);      corrErrTT[kA1]=vector<double>(3,0.042); //signal          
    corrTT[kB1]=vector<double>(3,0.59);      corrErrTT[kB1]=vector<double>(3,0.016);//sideband       
    corrTT[kC]={0.49,0.64,0.15};            corrErrTT[kC]={0.05,0.15,0.09};
    corrTT[kD]={0.54,0.43,0.30};            corrErrTT[kD]={0.016,0.04,0.06};
    // inflate uncertainties to account for MET systematics
    for( int i = 0 ; i < corrErrTT[kA2].size() ; i++ ){
        corrErrTT[kA2][i] = sqrt(corrErrTT[kA2][i]*corrErrTT[kA2][i]/corrTT[kA2][i]/corrTT[kA2][i]+singleLepMETunc[i]*singleLepMETunc[i])*corrTT[kA2][i];
        corrErrTT[kB2][i] = sqrt(corrErrTT[kB2][i]*corrErrTT[kB2][i]/corrTT[kB2][i]/corrTT[kB2][i]+singleLepMETunc[i]*singleLepMETunc[i])*corrTT[kB2][i];
        corrErrTT[kA1][i] = sqrt(corrErrTT[kA1][i]*corrErrTT[kA1][i]/corrTT[kA1][i]/corrTT[kA1][i]+singleLepMETunc[i]*singleLepMETunc[i])*corrTT[kA1][i];
        corrErrTT[kB1][i] = sqrt(corrErrTT[kB1][i]*corrErrTT[kB1][i]/corrTT[kB1][i]/corrTT[kB1][i]+singleLepMETunc[i]*singleLepMETunc[i])*corrTT[kB1][i];
    }
    corrWJets[kA2]=corrTT[kA2];                corrErrWJets[kA2]=corrErrTT[kA2];
    corrWJets[kB2]=corrTT[kB2];                corrErrWJets[kB2]=corrErrTT[kB2];
    corrWJets[kA1]=corrTT[kA1];                corrErrWJets[kA1]=corrErrTT[kA1];              
    corrWJets[kB1]=corrTT[kB1];                corrErrWJets[kB1]=corrErrTT[kB1];              
    corrWJets[kC]=corrTT[kC];                corrErrWJets[kC]=corrErrTT[kC];
    corrWJets[kD]=corrTT[kD];                corrErrWJets[kD]=corrErrTT[kD];
    corrZJets[kA2]=vector<double>(3,0.75);   corrErrZJets[kA2]=vector<double>(3,0.29);
    corrZJets[kB2]=vector<double>(3,2.58);   corrErrZJets[kB2]=vector<double>(3,0.63);
    corrZJets[kA1]=vector<double>(3,0.61);   corrErrZJets[kA1]=vector<double>(3,0.088);                
    corrZJets[kB1]=vector<double>(3,0.98);   corrErrZJets[kB1]=vector<double>(3,0.094);                
    corrZJets[kC]=vector<double>(3,0.5);    corrErrZJets[kC]=vector<double>(3,0.07);
    corrZJets[kD]=vector<double>(3,0.71);   corrErrZJets[kD]=vector<double>(3,0.035);
    corrQCD[kA2]=vector<double>(3,0.85);     corrErrQCD[kA2]=vector<double>(3,0.12);
    corrQCD[kB2]=vector<double>(3,1.2);      corrErrQCD[kB2]=vector<double>(3,0.16);
    corrQCD[kA1]=vector<double>(3,1.1);      corrErrQCD[kA1]=vector<double>(3,0.33);                   
    corrQCD[kB1]=vector<double>(3,0.88);     corrErrQCD[kB1]=vector<double>(3,0.04);                  
    corrQCD[kC]=vector<double>(3,0.93);     corrErrQCD[kC]=vector<double>(3,0.1);
    corrQCD[kD]=vector<double>(3,0.71);     corrErrQCD[kD]=vector<double>(3,0.027);

    TFile* inputFile;
    if( looseCuts ) 
        inputFile = new TFile("/uscms/home/awhitbe1/eos/boostedHiggsPlusMET/"+inputDir+"/ALPHABEThistos_looseCuts.root");
    else 
        inputFile = new TFile("/uscms/home/awhitbe1/eos/boostedHiggsPlusMET/"+inputDir+"/ALPHABEThistos.root");

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    vector<TH1F*> hTTvec(6);
    vector<TH1F*> hWJetsvec(6);
    vector<TH1F*> hZJetsvec(6);
    vector<TH1F*> hQCDvec(6);
    vector<TH1F*> hSnglTvec(6);
    vector<TH1F*> hOthervec(6);
    vector<TH1F*> hSumvec(6);
    vector<TH1F*> hDatavec(6);

    for( int reg = 0 ; reg < kNumRegions ; reg++ ){
        
        TCanvas* can = new TCanvas("can","can",500,500);
        
        TPad* topPad = new TPad("topPad","topPad",0.,0.4,.99,.99);
        TPad* botPad = new TPad("botPad","botPad",0.,0.01,.99,.39);
        botPad->SetBottomMargin(0.25);
        botPad->SetTopMargin(0.02);
        topPad->SetTopMargin(0.06);
        topPad->SetBottomMargin(0.17);
        topPad->Draw();
        botPad->Draw();
        topPad->cd();

        TH1F* hTT = (TH1F*) inputFile->Get("MET_"+regionTags[reg]+"_TT");
        hTT = include_overflow(hTT);
        apply_met_dep_scale_factors(*hTT,corrTT[reg],corrErrTT[reg]);
        if( verbose ) dump_histo(*hTT);
        set_style(*hTT,kCyan);
        hTTvec[reg] = hTT;

        TH1F* hWJets = (TH1F*) inputFile->Get("MET_"+regionTags[reg]+"_WJets");
        hWJets = include_overflow(hWJets);
        apply_met_dep_scale_factors(*hWJets,corrWJets[reg],corrErrWJets[reg]);
        if( verbose ) dump_histo(*hWJets);
        set_style(*hWJets,kBlue);
        hWJetsvec[reg] = hWJets;

        TH1F* hZJets = (TH1F*) inputFile->Get("MET_"+regionTags[reg]+"_ZJets");
        hZJets = include_overflow(hZJets);
        apply_met_dep_scale_factors(*hZJets,corrZJets[reg],corrErrZJets[reg]);
        if( verbose ) dump_histo(*hZJets);
        set_style(*hZJets,kGreen+1);
        hZJetsvec[reg] = hZJets;
        
        TH1F* hQCD = (TH1F*) inputFile->Get("MET_"+regionTags[reg]+"_QCD");
        hQCD = include_overflow(hQCD);
        apply_met_dep_scale_factors(*hQCD,corrQCD[reg],corrErrQCD[reg]);
        if( verbose ) dump_histo(*hQCD);
        set_style(*hQCD,kGray);
        hQCDvec[reg] = hQCD;

        TH1F* hSnglT = (TH1F*) inputFile->Get("MET_"+regionTags[reg]+"_SnglT");
        hSnglT = include_overflow(hSnglT);
        set_style(*hSnglT,kOrange);
        hSnglTvec[reg] = hSnglT;

        TH1F* hOther = (TH1F*) inputFile->Get("MET_"+regionTags[reg]+"_Other");
        hOther = include_overflow(hOther);
        set_style(*hOther,kRed+1);
        hOthervec[reg] = hOther;

        TH1F* sum = new TH1F(*hTT);
        sum->SetNameTitle("sum","sum");
        init_sum(*sum);
        sum->SetFillStyle(3490);        
        sum->SetFillColor(kGray);

        TLegend* leg = new TLegend(.2,.7,.9,.9);
        leg->SetNColumns(3);
        leg->SetBorderSize(0);
        leg->SetFillColor(0);

        THStack* stack = new THStack("stack","stack");
        stack->Add(hTT);
        leg->AddEntry(hTT,"t#bar{t}","f");
        stack->Add(hWJets);
        sum_histo(*sum,hWJets);
        leg->AddEntry(hWJets,"W+Jets","f");
        stack->Add(hZJets);
        sum_histo(*sum,hZJets);
        leg->AddEntry(hZJets,"Z+Jets","f");
        stack->Add(hQCD);
        sum_histo(*sum,hQCD);
        leg->AddEntry(hQCD,"QCD","f");
        stack->Add(hSnglT);
        sum_histo(*sum,hSnglT);
        leg->AddEntry(hSnglT,"single top","f");
        stack->Add(hOther);
        sum_histo(*sum,hOther);
        leg->AddEntry(hOther,"Other","f");

        if( verbose ) dump_histo(*sum);
        hSumvec[reg] = sum;

        TH1F* hData = (TH1F*) inputFile->Get("MET_"+regionTags[reg]+"_data");
        hData = include_overflow(hData);
        hData->SetMarkerStyle(8);
        leg->AddEntry(hData,"data","pl");
        hDatavec[reg] = hData;

        gStyle->SetErrorX(0.5);  

        stack->Draw("histo");
        style_axes(*(stack->GetHistogram()));
        stack->GetXaxis()->SetRangeUser(301,899);
        stack->GetXaxis()->SetNdivisions(503);
        stack->SetMaximum(max(sum->GetMaximum()+sum->GetBinError(sum->GetMaximumBin()),hData->GetMaximum()+hData->GetBinError(hData->GetMaximumBin()))*1.5);
        stack->GetXaxis()->SetTitle("MET");
        stack->GetYaxis()->SetTitle("Events");
        sum->Draw("e2,SAME");
        hData->Draw("e1,SAME");

        leg->Draw();

        writeExtraText = true;
        extraText="Preliminary";
        char lumiString[4];
        sprintf(lumiString,"%.1f",lumi/1000.);
        lumi_13TeV = lumiString;
        CMS_lumi( can , 4 , 0 );
        can->Update();
        can->RedrawAxis();
        can->GetFrame()->Draw();

        can->cd();
        botPad->cd();

        TH1F* ratio = new TH1F(*hData);
        ratio->SetNameTitle("ratio","ratio");
        ratio->Divide(sum);

        style_axes(*ratio);

        ratio->GetXaxis()->SetRangeUser(301,899);
        if( regionTags[reg] == "antitagSR" )
            ratio->GetYaxis()->SetRangeUser(0.,3.);
        else
            ratio->GetYaxis()->SetRangeUser(0.,2.);
        ratio->GetYaxis()->SetTitle("data/MC");
        ratio->GetXaxis()->SetTitle("MET");
        ratio->Draw("e1");

        TLine* one = new TLine(300.,1.,900.,1.);
        one->SetLineWidth(2);
        one->SetLineStyle(2);
        one->SetLineColor(1);
        one->Draw();

        if( looseCuts ){ 
            can->SaveAs("~/eos/boostedHiggsPlusMET/"+inputDir+"/plots/unblindSignalRegion/unblindSignalRegion_looseCuts_"+regionTags[reg]+".png");
            can->SaveAs("~/eos/boostedHiggsPlusMET/"+inputDir+"/plots/unblindSignalRegion/unblindSignalRegion_looseCuts_"+regionTags[reg]+".eps");
            can->SaveAs("~/eos/boostedHiggsPlusMET/"+inputDir+"/plots/unblindSignalRegion/unblindSignalRegion_looseCuts_"+regionTags[reg]+".pdf");
        }else{
            can->SaveAs("~/eos/boostedHiggsPlusMET/"+inputDir+"/plots/unblindSignalRegion/unblindSignalRegion_"+regionTags[reg]+".png");
            can->SaveAs("~/eos/boostedHiggsPlusMET/"+inputDir+"/plots/unblindSignalRegion/unblindSignalRegion_"+regionTags[reg]+".pdf");
            can->SaveAs("~/eos/boostedHiggsPlusMET/"+inputDir+"/plots/unblindSignalRegion/unblindSignalRegion_"+regionTags[reg]+".eps");
        }

    }
    
    /*
      TH1F* hKappa = new TH1F(*hSumvec[kA]);
    hKappa->Multiply(hSumvec[kD]);
    hKappa->Divide(hSumvec[kB]);
    hKappa->Divide(hSumvec[kC]);
    */

    TH1F* prediction1H = new TH1F(*hDatavec[kB1]);
    assert(prediction1H);
    prediction1H->SetNameTitle("prediction","prediction");
    prediction1H->SetMarkerColor(4);
    prediction1H->SetLineColor(4);
    prediction1H->Multiply(hDatavec[kC]);
    prediction1H->Divide(hDatavec[kD]);
    apply_met_dep_scale_factors(*prediction1H,kappa1H,kappa1HErr);

    TH1F* prediction2H = new TH1F(*hDatavec[kB2]);
    assert(prediction2H);
    prediction2H->SetNameTitle("prediction","prediction");
    prediction2H->SetMarkerColor(4);
    prediction2H->SetLineColor(4);
    prediction2H->Multiply(hDatavec[kC]);
    prediction2H->Divide(hDatavec[kD]);
    apply_met_dep_scale_factors(*prediction2H,kappa2H,kappa2HErr);

    /*
    TH1F* predictionRaw = new TH1F(*hDatavec[kB]);
    assert(predictionRaw);
    predictionRaw->SetNameTitle("predictionRaw","predictionRaw");
    predictionRaw->SetMarkerColor(4);
    predictionRaw->SetLineColor(4);
    predictionRaw->Multiply(hDatavec[kC]);
    predictionRaw->Divide(hDatavec[kD]);
    */

    for( int i = 1 ; i <= prediction1H->GetNbinsX(); i++ ){
        cout << "MET bin: " << i << endl;
        cout << "hSum1H: " << hSumvec[kA1]->GetBinContent(i) << " +/- " << hSumvec[kA1]->GetBinError(i) << endl;
        //cout << "raw prediction: " << predictionRaw->GetBinContent(i) << " +/- " << predictionRaw->GetBinError(i) << endl;
        //cout << "hKappa: " << hKappa->GetBinContent(i) << " +/- " << hKappa->GetBinError(i) << endl;
        cout << "prediction1H: " << prediction1H->GetBinContent(i) << " +/- " << prediction1H->GetBinError(i) << endl;
        cout << "observation1H: " << hDatavec[kA1]->GetBinContent(i) << " +/- " << hDatavec[kA1]->GetBinError(i) << endl;
        cout << endl;
        cout << "hSum2H: " << hSumvec[kA2]->GetBinContent(i) << " +/- " << hSumvec[kA2]->GetBinError(i) << endl;
        cout << "prediction2H: " << prediction2H->GetBinContent(i) << " +/- " << prediction2H->GetBinError(i) << endl;
        cout << "observation2H: " << hDatavec[kA2]->GetBinContent(i) << " +/- " << hDatavec[kA2]->GetBinError(i) << endl;
    }

    TCanvas* can = new TCanvas("can","can",500,500);
          
    TPad* topRightPad = new TPad("topRightPad","topRightPad",.55,0.4,.99,.99);
    TPad* botRightPad = new TPad("botRightPad","botRightPad",.55,0.01,.99,.40);
    TPad* topLeftPad = new TPad("topLeftPad","topLeftPad",0.,0.4,.55,.99);
    TPad* botLeftPad = new TPad("botLeftPad","botLeftPad",0.,0.01,.55,.40);

    botRightPad->SetBottomMargin(0.25);
    botRightPad->SetTopMargin(0.);
    botRightPad->SetLeftMargin(0.);

    botLeftPad->SetBottomMargin(0.25);
    botLeftPad->SetTopMargin(0.);
    botLeftPad->SetRightMargin(0.);
    botLeftPad->SetLeftMargin(0.3);

    topRightPad->SetTopMargin(0.06);
    topRightPad->SetBottomMargin(0.17);
    topRightPad->SetLeftMargin(0.);
    topRightPad->SetBottomMargin(0.);

    topLeftPad->SetTopMargin(0.06);
    topLeftPad->SetRightMargin(0.);
    topLeftPad->SetLeftMargin(0.3);
    topLeftPad->SetBottomMargin(0.);

    topRightPad->Draw();
    topLeftPad->Draw();
    botRightPad->Draw();
    botLeftPad->Draw();

    topRightPad->cd();
    gStyle->SetErrorX(0.5);
    prediction2H->GetYaxis()->SetRangeUser(0.015,(prediction1H->GetMaximum()+prediction1H->GetBinError(prediction1H->GetMaximumBin()))*10.);
    prediction2H->SetFillColor(2);
    prediction2H->SetMarkerColor(2);
    prediction2H->SetMarkerStyle(0);
    prediction2H->SetFillStyle(3490);
    prediction2H->GetXaxis()->SetNdivisions(503);
    prediction2H->GetXaxis()->SetTitleFont(43);
    prediction2H->GetXaxis()->SetTitleSize(21);
    prediction2H->GetXaxis()->SetTitleOffset(2.8);
    prediction2H->GetXaxis()->SetLabelOffset(2.8);
    prediction2H->GetXaxis()->SetLabelFont(43);
    prediction2H->GetXaxis()->SetLabelSize(21);
    prediction2H->GetXaxis()->SetTitle("MET");
    prediction2H->Draw("e2");
    hDatavec[kA2]->Draw("e1,SAME");
    topRightPad->SetLogy();

    writeExtraText = true;
    extraText="Preliminary";
    CMS_lumi( can , 4 , 0 );
    can->Update();
    can->RedrawAxis();
    can->GetFrame()->Draw();

    TLegend* legRight = new TLegend(.75,.70,.95,.85);
    legRight->SetTextFont(43);
    legRight->SetTextSize(18);
    legRight->SetBorderSize(0);
    legRight->SetFillColor(0);
    legRight->AddEntry(prediction2H,"#kappaBC/D","f");
    legRight->AddEntry(hDatavec[kA2],"data","p");

    legRight->Draw();

    TText* labelRight = new TText(.75,.86,"2 Higgs tag");
    labelRight->SetNDC();
    labelRight->SetTextFont(43);
    labelRight->SetTextSize(18);
    labelRight->Draw();

    botRightPad->cd();
    TH1F* ratio2H = new TH1F(*hDatavec[kA2]);
    ratio2H->SetNameTitle("ratio2H","ratio2H");
    ratio2H->Divide(prediction2H);
    ratio2H->GetXaxis()->SetNdivisions(503);
    ratio2H->GetYaxis()->SetTitleFont(43);
    ratio2H->GetYaxis()->SetTitleSize(21);
    ratio2H->GetXaxis()->SetTitleFont(43);
    ratio2H->GetXaxis()->SetTitleOffset(2.8);
    ratio2H->GetXaxis()->SetTitleSize(21);
    ratio2H->GetXaxis()->SetLabelFont(43);
    ratio2H->GetXaxis()->SetLabelSize(21);
    ratio2H->GetYaxis()->SetLabelFont(43);
    ratio2H->GetYaxis()->SetLabelSize(1);
    ratio2H->GetYaxis()->SetLabelOffset(21);
    ratio2H->GetYaxis()->SetRangeUser(0.,1.99);
    ratio2H->GetXaxis()->SetTitle("MET");
    ratio2H->Draw("e1");

    topLeftPad->cd();
    prediction1H->GetYaxis()->SetRangeUser(0.015,(prediction1H->GetMaximum()+prediction1H->GetBinError(prediction1H->GetMaximumBin()))*10.);
    prediction1H->SetFillColor(2);
    prediction1H->SetMarkerColor(2);
    prediction1H->SetMarkerStyle(0);
    prediction1H->SetFillStyle(3490);
    prediction1H->GetXaxis()->SetNdivisions(503);
    prediction1H->GetYaxis()->SetTitleFont(43);
    prediction1H->GetYaxis()->SetTitleSize(21);
    prediction1H->GetYaxis()->SetTitleOffset(2.8);
    prediction1H->GetXaxis()->SetTitleFont(43);
    prediction1H->GetXaxis()->SetTitleSize(21);
    prediction1H->GetYaxis()->SetLabelFont(43);
    prediction1H->GetYaxis()->SetLabelSize(21);
    prediction1H->GetXaxis()->SetLabelFont(43);
    prediction1H->GetXaxis()->SetLabelSize(21);
    prediction1H->GetXaxis()->SetLabelOffset(2.8);
    prediction1H->GetYaxis()->SetTitle("Events");
    prediction1H->Draw("e2");
    hDatavec[kA1]->Draw("e1,SAME");
    topLeftPad->SetLogy();

    TText* labelLeft = new TText(.6,.8,"1 Higgs tag");
    labelLeft->SetNDC();
    labelLeft->SetTextFont(43);
    labelLeft->SetTextSize(18);
    labelLeft->Draw();

    botLeftPad->cd();
    TH1F* ratio1H = new TH1F(*hDatavec[kA1]);
    ratio1H->SetNameTitle("ratio1H","ratio1H");
    ratio1H->Divide(prediction1H);
    ratio1H->GetXaxis()->SetNdivisions(503);
    ratio1H->GetYaxis()->SetTitleFont(43);
    ratio1H->GetYaxis()->SetTitleSize(21);
    ratio1H->GetYaxis()->SetTitleOffset(2.8);
    ratio1H->GetXaxis()->SetTitleFont(43);
    ratio1H->GetXaxis()->SetTitleSize(21);
    ratio1H->GetXaxis()->SetLabelFont(43);
    ratio1H->GetXaxis()->SetLabelSize(21);
    ratio1H->GetYaxis()->SetLabelFont(43);
    ratio1H->GetYaxis()->SetLabelSize(21);
    ratio1H->GetYaxis()->SetNdivisions(504);
    ratio1H->GetYaxis()->SetRangeUser(0.,1.99);
    ratio1H->GetYaxis()->SetTitle("Observed/Predicted");
    ratio1H->Draw("e1");

    can->SaveAs("~/eos/boostedHiggsPlusMET/"+inputDir+"/plots/unblindSignalRegion/predictionsVsObservation.png");
    can->SaveAs("~/eos/boostedHiggsPlusMET/"+inputDir+"/plots/unblindSignalRegion/predictionsVsObservation.eps");
    can->SaveAs("~/eos/boostedHiggsPlusMET/"+inputDir+"/plots/unblindSignalRegion/predictionsVsObservation.pdf");
}
