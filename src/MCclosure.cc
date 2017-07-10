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
    TH2F* kappaDist = new TH2F("kappaDist","kappaDist",3,300.,900.,1000,0.,5.);
    kappaDist->Reset();
    for( int m=1; m<=3; ++m){
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
	
//	for(int i=1;i<=1000; ++i){

        }
	//TH1D*METBinKappa=(TH1D*)kappaDist->ProjectionY("METBinKappa", m,m);
	TH1D*METBinKappa=(TH1D*)kappaDist->QuantilesX(0.5, "METBinKappa");
	TH1D*METBinKappaUncUp=(TH1D*)kappaDist->QuantilesX(0.5+0.34, "METBinKappaUnc");
	TH1D*METBinKappaUncDn=(TH1D*)kappaDist->QuantilesX(0.5-0.34, "METBinKappaUnc");
	float RatioErrorUp=fabs(METBinKappaUncUp->GetBinContent(m)-METBinKappa->GetBinContent(m));	
	float RatioErrorDn=METBinKappa->GetBinContent(m)-METBinKappaUncDn->GetBinContent(m);	
	Closure.SetPoint(m-1, TotalBkg->GetBinCenter(m), METBinKappa->GetBinContent(m));
	Closure.SetPointError(m-1, 100,100, RatioErrorDn,RatioErrorUp);
	if(m==3) Closure.SetPointError(m-1, 400,400, RatioErrorDn,RatioErrorUp);
	//std::cout<<"Mean"<<METBinKappa->GetBinContent(m)<<" +/- "<< RatioErrorUp<<std::endl;
	  std::cout<<"Kappa Bin "<< TotalBkg->GetBinCenter(m)<<" Kappa  "<<METBinKappa->GetBinContent(m)<<" + "<<RatioErrorUp<<" - "<< RatioErrorDn<<std::endl;
         //   RatioMCPred.SetBinContent(m,METBinKappa->GetBinContent(m));            RatioMCPred.SetBinError(m,RatioError);

      }
    
}	

void MCclosure(TString tag = "", bool doubleHiggsRegion = false, TString baseDir="./"){

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");
    TFile* f = new TFile(baseDir+"ALPHABEThistosTTSingleLept.root","READ");
    //TFile* f = new TFile("./c754f9d68b4c310fa189e7a91a4feb84da28388b/ALPHABEThistos_lowDphi.root","READ");
    TH1F* hdata,*hmc;

    const int numSamples = 2;
    const int numMETbins = 2;
    double METbins[numMETbins+2] = {300,500,700,1500};

    const int numRegions = 4;
    TString sampleLabels[numSamples]={"TTJets"};
    //TString METlabels[numMETbins] = {"300","500","700"};
    TString regionLabels[numRegions] = {"doubletagSR","antitagSR","doubletagSB","antitagSB"};
    if( ! doubleHiggsRegion ){
        regionLabels[0] = "tagSR";
        regionLabels[2] = "tagSB";
    }
    TH1F* temp[numRegions];
    TH1F* MC[numRegions];

    for( int r = 0 ; r < numRegions ; r++ ){
        temp[r] = (TH1F*) f->Get("MET_"+regionLabels[r]+"_TT");
        //temp[r] = (TH1F*) f->Get("MET_"+regionLabels[r]+"_ZJets");
        //temp[r]=(TH1F*)f->Get("MET_"+regionLabels[r]+"_ZJets");
        MC[r] = new TH1F("MC_"+regionLabels[r],"MC_"+regionLabels[r],numMETbins+1,METbins);
        //MC[r]->SetFillStyle(3490);
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

        for( int b = 1 ; b <= numMETbins+1 ; b++ ){
            MC[r]->SetBinContent(b,temp[r]->GetBinContent(b));
            MC[r]->SetBinError(b,temp[r]->GetBinError(b));
            cout << " & " <<  MC[r]->GetBinContent(b) << " $\\pm$ " << MC[r]->GetBinError(b) ;
        }
    }

    TH1F* MCprediction = new TH1F(*MC[1]);
    MCprediction->SetNameTitle("MCprediction","MCprediction");
    MCprediction->Multiply(MC[2]);
    MCprediction->Divide(MC[3]);
    //MCprediction->SetMarkerColor(1);
    MCprediction->SetMarkerSize(0.01);
    //MCprediction->SetMarkerStyle(8);
    //MCprediction->SetMarkerColor(kBlue);
    MCprediction->SetLineColor(kBlue);
    MCprediction->SetFillStyle(3490);
    MCprediction->SetFillColor(2);
    TH1F* Closure = new TH1F(*MC[0]);
    Closure->SetNameTitle("Closure","Closure");
    Closure->Divide(MCprediction);
   TGraphAsymmErrors* grClose=new TGraphAsymmErrors(Closure);
    SetRatioErr(MC[0], MCprediction, *grClose);
    Closure->Reset();
    Closure->GetYaxis()->SetTitle("#kappa");
    Closure->SetMarkerStyle(8);
    Closure->SetLineColor(1);
    Closure->GetYaxis()->SetRangeUser(0.,10.);
        
    Closure->GetYaxis()->SetLabelFont(43);
    Closure->GetYaxis()->SetLabelSize(14);
    Closure->GetYaxis()->SetTitleFont(43);
    Closure->GetYaxis()->SetTitleSize(20);
    Closure->GetYaxis()->SetTitleOffset(1.6);

    Closure->GetXaxis()->SetLabelFont(43);
    Closure->GetXaxis()->SetLabelSize(14);
    Closure->GetXaxis()->SetTitleFont(43);
    Closure->GetXaxis()->SetTitleSize(20);
    Closure->GetXaxis()->SetTitleOffset(2.);

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
   //MC[0]->Draw("p,e1");
    //MCprediction->Draw("e2,same");

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
    leg->AddEntry(Closure,"MC Truth (A) ","pl");
    leg->AddEntry(MCprediction,"Pred: B*C/D ","F");
    leg->Draw();
    
    botPad->cd();
    Closure->Draw("p,e1");
    Closure->GetYaxis()->SetRangeUser(0.,3.);
      Closure->Draw("p,e1");
	grClose->Draw("p,e,same");
    TGraph*KappaNom_1=new TGraph();
	KappaNom_1->SetPoint(0, 0,1);
 KappaNom_1->SetPoint(1,9999999,1);
	KappaNom_1->SetLineWidth(2.0);
	KappaNom_1->SetLineStyle(kDashed);
	KappaNom_1->Draw("lsame");
    cout << "\\begin{table}" << endl;
    cout << "\\begin{tabular}{c|c|c|c|c|c|c}" << endl;
    cout << "\\\\ \\hline" << endl;
    
    if( doubleHiggsRegion ) 
        cout << " bin & 2H SR & 0H SR & 2H SB & 0H SB & Pred. & Closure \\\\ \\hline" << endl;
    else 
        cout << " bin & 1H SR & 0H SR & 1H SB & 0H SB & Pred. & Closure \\\\ \\hline" << endl;
    for( int b = 1 ; b <= numMETbins+1 ; b++ ){
        cout << std::setprecision(3) << MC[0]->GetBinLowEdge(b) << "-" << MC[0]->GetBinLowEdge(b+1) ;
        for( int r = 0 ; r < numRegions ; r++ ){
            cout << " & " << temp[r]->GetBinContent(b) << " $\\pm$ " << temp[r]->GetBinError(b);
        }
        cout << " & " <<  MCprediction->GetBinContent(b) << " $\\pm$ " << MCprediction->GetBinError(b) ;
	
        cout << " & " << Closure->GetBinContent(b) << " $\\pm$ " << Closure->GetBinError(b) ;
        cout << "\\\\ \\hline" << endl;
    }
    cout << "\\end{tabular}" << endl;
    cout << "\\end{table}" << endl;

    if( doubleHiggsRegion ){
        can->SaveAs("MCclosure_doubleHiggsRegion.png");
        can->SaveAs("MCclosure_doubleHiggsRegion.pdf");
        can->SaveAs("MCclosure_doubleHiggsRegion.eps");
    }else{
        can->SaveAs("MCclosure_singleHiggsRegion.png");
        can->SaveAs("MCclosure_singleHiggsRegion.pdf");
        can->SaveAs("MCclosure_singleHiggsRegion.eps");        
    }
}

