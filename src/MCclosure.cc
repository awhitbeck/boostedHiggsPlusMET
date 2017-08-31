#include "CMS_lumi.cc"
#include "TH2F.h"
#include "TH1F.h"
#include "TFile.h"
#include "TString.h"
#include "TROOT.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TLegend.h"
#include <iostream>
#include <iomanip>
#include "TStyle.h"
void SetRatioErr(TH1F*TotalBkg, TH1F*Pred, TGraphAsymmErrors &Closure){
    TRandom3 rand;
    TH2F* kappaDist = new TH2F("kappaDist","kappaDist",Pred->GetNbinsX(),Pred->GetBinLowEdge(1),Pred->GetBinLowEdge(Pred->GetNbinsX()+1),1000,0.,5.);
    kappaDist->Reset();
    for( int m=1; m<=Pred->GetNbinsX(); ++m){
        for(int i=0; i<10000; ++i){
            float num=rand.Gaus(TotalBkg->GetBinContent(m),TotalBkg->GetBinError(m));
            float den=rand.Gaus(Pred->GetBinContent(m),Pred->GetBinError(m));
            if(TotalBkg->GetBinError(m)<0.00001 && TotalBkg->GetBinContent(m)<0.0001){
                num=1.0;
                den=rand.Gaus(Pred->GetBinContent(m),Pred->GetBinError(m));
                den=1.0+den;
            }
            if(TotalBkg->GetBinCenter(m)<900)kappaDist->Fill(TotalBkg->GetBinCenter(m),num/den);
            else kappaDist->Fill(850,num/den);
        
        }
        TH1D*METBinKappa=(TH1D*)kappaDist->QuantilesX(0.5, "METBinKappa");
        TH1D*METBinKappaUncUp=(TH1D*)kappaDist->QuantilesX(0.5+0.34, "METBinKappaUnc");
        TH1D*METBinKappaUncDn=(TH1D*)kappaDist->QuantilesX(0.5-0.34, "METBinKappaUnc");
        float RatioErrorUp=fabs(METBinKappaUncUp->GetBinContent(m)-METBinKappa->GetBinContent(m));	
        float RatioErrorDn=METBinKappa->GetBinContent(m)-METBinKappaUncDn->GetBinContent(m);	
        Closure.SetPoint(m-1, TotalBkg->GetBinCenter(m), METBinKappa->GetBinContent(m));
        Closure.SetPointError(m-1,Pred->GetBinWidth(m)/2.,Pred->GetBinWidth(m)/2., RatioErrorDn,RatioErrorUp);
        std::cout<<"Kappa Bin "<< TotalBkg->GetBinCenter(m)<<" Kappa  "<<METBinKappa->GetBinContent(m)<<" + "<<RatioErrorUp<<" - "<< RatioErrorDn<<std::endl;
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

void MCclosure(TString tag = "", bool doubleHiggsRegion = false, TString sample="sum", TString baseDir="./"){

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");
    TFile* f = new TFile(baseDir+"ALPHABEThistos"+tag+".root","READ");
    TH1F* hdata,*hmc;

    const int numSamples = 2;
    const int numMETbins = 2;
    double METbins[numMETbins+2] = {300,500,700,900};

    const int numRegions = 4;
    TString regionLabels[numRegions] = {"doubletagSR","antitagSR","doubletagSB","antitagSB"};
    if( ! doubleHiggsRegion ){
        regionLabels[0] = "tagSR";
        regionLabels[2] = "tagSB";
    }
    TH1F* temp[numRegions];
    TH1F* MC[numRegions];

    for( int r = 0 ; r < numRegions ; r++ ){
        MC[r] = (TH1F*) f->Get("MET_"+regionLabels[r]+"_"+sample);
        MC[r] = include_overflow(MC[r]);
        MC[r]->SetNameTitle("MC_"+regionLabels[r],"MC_"+regionLabels[r]);
        MC[r]->SetLineColor(1);
        MC[r]->SetFillColor(2);
        MC[r]->GetXaxis()->SetTitle("MET [GeV]");
        MC[r]->GetYaxis()->SetTitle("Events");
        MC[r]->GetYaxis()->SetLabelFont(43);
        MC[r]->GetYaxis()->SetLabelSize(14);
        MC[r]->GetYaxis()->SetTitleFont(43);
        MC[r]->GetYaxis()->SetTitleSize(20);
        MC[r]->GetYaxis()->SetTitleOffset(1.6);
        MC[r]->SetMarkerStyle(8);
        MC[r]->GetXaxis()->SetLabelFont(43);
        MC[r]->GetXaxis()->SetLabelSize(14);
        MC[r]->GetXaxis()->SetTitleFont(43);
        MC[r]->GetXaxis()->SetTitleSize(20);
        MC[r]->GetXaxis()->SetTitleOffset(1.6);
    	MC[r]->SetMarkerSize(0.7);
    }

    TH1F* MCprediction = new TH1F(*MC[1]);
    MCprediction->SetNameTitle("MCprediction","MCprediction");
    MCprediction->Multiply(MC[2]);
    MCprediction->Divide(MC[3]);
    MCprediction->SetMarkerSize(0.01);
    MCprediction->SetLineColor(kBlue);
    MCprediction->SetFillStyle(3490);
    MCprediction->SetFillColor(2);
    TGraphAsymmErrors* grClose=new TGraphAsymmErrors(MC[0]->GetNbinsX());
    SetRatioErr(MC[0], MCprediction, *grClose);
    
    grClose->SetMarkerStyle(8);
    
    grClose->GetYaxis()->SetLabelSize(14);
    grClose->GetYaxis()->SetLabelFont(43);
    grClose->GetYaxis()->SetTitleFont(43);
    grClose->GetYaxis()->SetTitleSize(20);
    grClose->GetYaxis()->SetTitleOffset(1.6);
    grClose->GetYaxis()->SetTitle("#kappa");

    grClose->GetXaxis()->SetLabelFont(43);
    grClose->GetXaxis()->SetLabelSize(14);
    grClose->GetXaxis()->SetTitleFont(43);
    grClose->GetXaxis()->SetTitleSize(20);
    grClose->GetXaxis()->SetTitleOffset(2.);
    grClose->GetXaxis()->SetTitle("MET [GeV]");

    TCanvas* can = new TCanvas("can","can",500,500);
    gStyle->SetErrorX(0.5);
    TPad* topPad = new TPad("topPad","topPad",0.,0.4,.99,.99);
    TPad* botPad = new TPad("botPad","botPad",0.,0.01,.99,.39);
    botPad->SetBottomMargin(0.25);
    botPad->SetTopMargin(0.02);
    topPad->SetTopMargin(0.06);
    topPad->SetBottomMargin(0.17);
    topPad->Draw();
    botPad->Draw();
    topPad->cd();
    MCprediction->Draw("e2");
    MC[0]->Draw("p,e1,same");

    writeExtraText = true;
    extraText="Preliminary";
    char lumiString[4];
    lumi_13TeV = "35.9 fb^{-1}";
    CMS_lumi( can , 4 , 0 );
    can->Update();
    can->RedrawAxis();
    can->GetFrame()->Draw();

    TLegend* leg = new TLegend(.6,.75,.9,.9);
    leg->SetFillColor(0);
    leg->SetBorderSize(0);
    leg->AddEntry(grClose,"MC Truth (A) ","pl");
    leg->AddEntry(MCprediction,"Pred: B*C/D ","F");
    leg->Draw();
    
    botPad->cd();
	grClose->Draw("A,p");
    grClose->SetMaximum(2.0);
    grClose->SetMinimum(0.0);
    TGraph*KappaNom=new TGraph();
	KappaNom->SetPoint(0, 0,1);
    KappaNom->SetPoint(1,9999999,1);
	KappaNom->SetLineWidth(2.0);
	KappaNom->SetLineStyle(kDashed);
	KappaNom->Draw("lsame");
    cout << "\\begin{table}" << endl;
    cout << "\\begin{tabular}{c|c|c|c|c|c|c}" << endl;
    cout << "\\\\ \\hline" << endl;
    
    if( doubleHiggsRegion ) 
        cout << " bin & 2H SR & 0H SR & 2H SB & 0H SB & Pred. & Closure \\\\ \\hline" << endl;
    else 
        cout << " bin & 1H SR & 0H SR & 1H SB & 0H SB & Pred. & Closure \\\\ \\hline" << endl;

    double ratio,MET;
    for( int b = 1 ; b <= MC[0]->GetNbinsX() ; b++ ){
        cout << std::setprecision(3) << MC[0]->GetBinLowEdge(b) << "-" << MC[0]->GetBinLowEdge(b+1) ;
        for( int r = 0 ; r < numRegions ; r++ ){
            cout << " & " << MC[r]->GetBinContent(b) << " $\\pm$ " << MC[r]->GetBinError(b);
        }
        cout << " & " << MCprediction->GetBinContent(b) << " $\\pm$ " << MCprediction->GetBinError(b) ;
        grClose->GetPoint(b-1,MET,ratio);
        cout << " & " << ratio << " $\\pm$ " << grClose->GetErrorY(b-1) ;
        cout << "\\\\ \\hline" << endl;
    }
    cout << "\\end{tabular}" << endl;
    cout << "\\end{table}" << endl;

    double error;
    for( int r = 0 ; r<numRegions ; r++ ){
        cout << regionLabels[r] << ": " << MC[r]->IntegralAndError(1,4,error) << " +/- " << error << endl;
    }

    if( doubleHiggsRegion ){
        can->SaveAs("Unblinding_doubleHiggsRegion.png");
        can->SaveAs("Unblinding_doubleHiggsRegion.pdf");
        can->SaveAs("Unblinding_doubleHiggsRegion.eps");
    }else{
        can->SaveAs("Unblinding_singleHiggsRegion.png");
        can->SaveAs("Unblinding_singleHiggsRegion.pdf");
        can->SaveAs("Unblinding_singleHiggsRegion.eps");        
    }
}

