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
    TH1F* result = new TH1F(name,name,h->GetNbinsX()+1,h->GetBinLowEdge(1),h->GetBinLowEdge(h->GetNbinsX())+2*h->GetBinWidth(h->GetNbinsX()));
    for( int i = 1 ; i < h->GetNbinsX()+2 ; i++ ){
        result->SetBinContent(i,h->GetBinContent(i));
        result->SetBinError(i,h->GetBinError(i));
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

    vector<vector<double> > corrTT(4);
    vector<vector<double> > corrErrTT(4);
    vector<vector<double> > corrWJets(4);
    vector<vector<double> > corrErrWJets(4);
    vector<vector<double> > corrZJets(4);
    vector<vector<double> > corrErrZJets(4);
    vector<vector<double> > corrQCD(4);
    vector<vector<double> > corrErrQCD(4);
    vector<vector<double> > kappa(4);
    vector<vector<double> > kappaErr(4);

    TString regionTags[4];
    if( doubletag ){
        regionTags[0] = "doubletagSR";
        regionTags[1] = "doubletagSB";
    }else{
        regionTags[0] = "tagSR";
        regionTags[1] = "tagSB";
    }
    regionTags[2] = "antitagSR";
    regionTags[3] = "antitagSB";

    enum regions {kA,kB,kC,kD,kNumRegions};

    // these are relative uncertainties!
    vector<double> singleLepMETunc={0.025,0.025,0.32,0.69};

    if( doubletag ){
        kappa[0] = vector<double>(4,0.);       kappaErr[0] = vector<double>(4,0.);
        kappa[1] = vector<double>(4,0.82);     kappaErr[1] = vector<double>(4,0.19);
        kappa[2] = vector<double>(4,0.53);     kappaErr[2] = vector<double>(4,0.17);
        kappa[3] = vector<double>(4,0.61);     kappaErr[3] = vector<double>(4,0.30);
        corrTT[0]=vector<double>(4,0.64);      corrErrTT[0]=vector<double>(4,0.15);
        corrTT[1]=vector<double>(4,0.71);      corrErrTT[1]=vector<double>(4,0.059);
        corrTT[2]={0.56,0.43,0.17,0.11};       corrErrTT[2]={0.07,0.08,0.11,0.11};
        corrTT[3]={0.52,0.54,0.32,0.13};       corrErrTT[3]={0.02,0.03,0.07,0.07};
        // inflate uncertainties to account for MET systematics
        for( int i = 0 ; i < corrErrTT[0].size() ; i++ ){
            corrErrTT[0][i] = sqrt(corrErrTT[0][i]*corrErrTT[0][i]/corrTT[0][i]/corrTT[0][i]+singleLepMETunc[i]*singleLepMETunc[i])*corrTT[0][i];
            corrErrTT[1][i] = sqrt(corrErrTT[1][i]*corrErrTT[1][i]/corrTT[1][i]/corrTT[1][i]+singleLepMETunc[i]*singleLepMETunc[i])*corrTT[1][i];
        }
        kappa[0] = vector<double>(4,0.);       kappaErr[0] = vector<double>(4,0.);
        kappa[1] = vector<double>(4,1.03);     kappaErr[1] = vector<double>(4,0.15);
        kappa[2] = vector<double>(4,1.03);     kappaErr[2] = vector<double>(4,0.22);
        kappa[3] = vector<double>(4,0.83);     kappaErr[3] = vector<double>(4,0.18);
        corrWJets[0]=corrTT[0];                corrErrWJets[0]=corrErrTT[0];
        corrWJets[1]=corrTT[1];                corrErrWJets[1]=corrErrTT[1];
        corrWJets[2]=corrTT[2];                corrErrWJets[2]=corrErrTT[2];
        corrWJets[3]=corrTT[3];                corrErrWJets[3]=corrErrTT[3];
        corrZJets[0]=vector<double>(4,0.75);   corrErrZJets[0]=vector<double>(4,0.29);
        corrZJets[1]=vector<double>(4,2.58);    corrErrZJets[1]=vector<double>(4,0.63);
        corrZJets[2]=vector<double>(4,0.5);   corrErrZJets[2]=vector<double>(4,0.07);
        corrZJets[3]=vector<double>(4,0.71);    corrErrZJets[3]=vector<double>(4,0.035);
        corrQCD[0]=vector<double>(4,0.85);     corrErrQCD[0]=vector<double>(4,0.12);
        corrQCD[1]=vector<double>(4,1.2);      corrErrQCD[1]=vector<double>(4,0.16);
        corrQCD[2]=vector<double>(4,0.93);     corrErrQCD[2]=vector<double>(4,0.1);
        corrQCD[3]=vector<double>(4,0.71);     corrErrQCD[3]=vector<double>(4,0.027);
    }else{
        corrTT[0]=vector<double>(4,0.63);      corrErrTT[0]=vector<double>(4,0.069); //signal          
        corrTT[1]=vector<double>(4,0.65);      corrErrTT[1]=vector<double>(4,0.1);//sideband       
        corrTT[2]={0.56,0.43,0.17,0.11};       corrErrTT[2]={0.07,0.08,0.11,0.11};
        corrTT[3]={0.52,0.54,0.32,0.13};       corrErrTT[3]={0.02,0.03,0.07,0.07};
        // inflate uncertainties to account for MET systematics
        for( int i = 0 ; i < corrErrTT[0].size() ; i++ ){
            corrErrTT[0][i] = sqrt(corrErrTT[0][i]*corrErrTT[0][i]/corrTT[0][i]/corrTT[0][i]+singleLepMETunc[i]*singleLepMETunc[i])*corrTT[0][i];
            corrErrTT[1][i] = sqrt(corrErrTT[1][i]*corrErrTT[1][i]/corrTT[1][i]/corrTT[1][i]+singleLepMETunc[i]*singleLepMETunc[i])*corrTT[1][i];
        }
        corrWJets[0]=corrTT[0];    corrErrWJets[0]=corrErrTT[0];              
        corrWJets[1]=corrTT[1];    corrErrWJets[1]=corrErrTT[1];              
        corrWJets[2]=corrTT[2];    corrErrWJets[2]=corrErrTT[2];              
        corrWJets[3]=corrTT[3];    corrErrWJets[3]=corrErrTT[3];              
        corrZJets[0]=vector<double>(4,0.61);   corrErrZJets[0]=vector<double>(4,0.088);                
        corrZJets[1]=vector<double>(4,0.98);   corrErrZJets[1]=vector<double>(4,0.0094);                
        corrZJets[2]=vector<double>(4,0.5);   corrErrZJets[2]=vector<double>(4,0.07);               
        corrZJets[3]=vector<double>(4,0.71);    corrErrZJets[3]=vector<double>(4,.035);                 
        corrQCD[0]=vector<double>(4,1.1);      corrErrQCD[0]=vector<double>(4,0.33);                   
        corrQCD[1]=vector<double>(4,0.88);     corrErrQCD[1]=vector<double>(4,0.04);                  
        corrQCD[2]=vector<double>(4,0.93);     corrErrQCD[2]=vector<double>(4,0.1);                   
        corrQCD[3]=vector<double>(4,0.71);     corrErrQCD[3]=vector<double>(4,0.027);
    }

    TFile* inputFile;
    if( looseCuts ) 
        inputFile = new TFile("/uscms/home/awhitbe1/eos/boostedHiggsPlusMET/"+inputDir+"/ALPHABEThistos.root");
    else 
        inputFile = new TFile("/uscms/home/awhitbe1/eos/boostedHiggsPlusMET/"+inputDir+"/ALPHABEThistos_looseCuts.root");

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    vector<TH1F*> hTTvec(4);
    vector<TH1F*> hWJetsvec(4);
    vector<TH1F*> hZJetsvec(4);
    vector<TH1F*> hQCDvec(4);
    vector<TH1F*> hSnglTvec(4);
    vector<TH1F*> hOthervec(4);
    vector<TH1F*> hSumvec(4);
    vector<TH1F*> hDatavec(4);

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

        TLegend* leg = new TLegend(.7,.5,.9,.9);
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
        stack->SetMaximum(max(stack->GetMaximum(),hData->GetMaximum())*1.5);
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
            can->SaveAs("../plots/unblindSignalRegion/unblindSignalRegion_"+regionTags[reg]+".png");
            can->SaveAs("../plots/unblindSignalRegion/unblindSignalRegion_"+regionTags[reg]+".pdf");
            can->SaveAs("../plots/unblindSignalRegion/unblindSignalRegion_"+regionTags[reg]+".eps");
        }else{
            can->SaveAs("../plots/unblindSignalRegion/unblindSignalRegion_looseCuts_"+regionTags[reg]+".png");
            can->SaveAs("../plots/unblindSignalRegion/unblindSignalRegion_looseCuts_"+regionTags[reg]+".eps");
            can->SaveAs("../plots/unblindSignalRegion/unblindSignalRegion_looseCuts_"+regionTags[reg]+".pdf");
        }

    }
    
    TH1F* hKappa = new TH1F(*hSumvec[kA]);
    hKappa->Multiply(hSumvec[kD]);
    hKappa->Divide(hSumvec[kB]);
    hKappa->Divide(hSumvec[kC]);

    TH1F* prediction = new TH1F(*hDatavec[kB]);
    assert(prediction);
    prediction->SetNameTitle("prediction","prediction");
    prediction->SetMarkerColor(4);
    prediction->SetLineColor(4);
    prediction->Multiply(hDatavec[kC]);
    prediction->Divide(hDatavec[kD]);
    prediction->Multiply(hKappa);


    TH1F* predictionRaw = new TH1F(*hDatavec[kB]);
    assert(predictionRaw);
    predictionRaw->SetNameTitle("predictionRaw","predictionRaw");
    predictionRaw->SetMarkerColor(4);
    predictionRaw->SetLineColor(4);
    predictionRaw->Multiply(hDatavec[kC]);
    predictionRaw->Divide(hDatavec[kD]);

    for( int i = 1 ; i <= prediction->GetNbinsX(); i++ ){
        cout << "MET bin: " << i << endl;
        cout << "hSum: " << hSumvec[kA]->GetBinContent(i) << " +/- " << hSumvec[kA]->GetBinError(i) << endl;
        cout << "raw prediction: " << predictionRaw->GetBinContent(i) << " +/- " << predictionRaw->GetBinError(i) << endl;
        cout << "hKappa: " << hKappa->GetBinContent(i) << " +/- " << hKappa->GetBinError(i) << endl;
        cout << "prediction: " << prediction->GetBinContent(i) << " +/- " << prediction->GetBinError(i) << endl;
        cout << "observation: " << hDatavec[kA]->GetBinContent(i) << " +/- " << hDatavec[kA]->GetBinError(i) << endl;
    }
}
