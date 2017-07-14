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
    TH1F*hratio=new TH1F("hratio", "", 100,0.0, 3.);
    TH2F* kappaDist = new TH2F("kappaDist","kappaDist",3,300.,900.,1000,0.,5.);
    kappaDist->Reset();
    for( int m=1; m<=3; ++m){
    std::cout<<"Met Bin "<<m<<" Region A "<<TotalBkg->GetBinContent(m)<<" +/- "<<TotalBkg->GetBinError(m)<< " Pred "<<Pred->GetBinContent(m)<<" +/- "<<Pred->GetBinError(m) <<std::endl;
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
	std::cout<<"Mean"<<METBinKappa->GetBinContent(m)<<" +/- "<< RatioErrorUp<<std::endl;
	    
         //   RatioMCPred.SetBinContent(m,METBinKappa->GetBinContent(m));            RatioMCPred.SetBinError(m,RatioError);

      }
    
}	

void UnblindingControlSingleRegion(TString tag = "", bool doubleHiggsRegion = false, TString baseDir="./",bool applySF=true){

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    TFile* f = new TFile(baseDir+"ALPHABEThistos"+tag+".root","READ");
    TH1F* hdata,*hmc;

    const int numSamples = 2;
    const int numMETbins = 2;
    double METbins[numMETbins+2] = {300,500,700,1500};

    const int numRegions = 4;
    TString sampleLabels[numSamples]={"TTJets"};
    //TString METlabels[numMETbins] = {"300","500","700"};
    TString regionLabels[numRegions] = {"doubletagSR","antitagSR","doubletagSB","antitagSB"};
	float LDPSF_1H[4]={1.1, 0.93, 0.88,0.71};
	float LDPSFErr_1H[4]={0.33, 0.1, 0.04,0.027};
	float LDPSF_2H[4]={0.85, 0.93,1.2,0.71};
	float LDPSFErr_2H[4]={0.12, 0.1, 0.16,0.027};
	//update this (need the MET Dependant numbers)
	float SLSF_1H[4]={0.58, 0.53, 0.58, 0.48};
	float SLSFErr_1H[4]={0.12, 0.08, 0.049, 0.03};
	float SLSF_2H[4]={0.6, 0.53, 0.74, 0.48};
	float SLSFErr_2H[4]={0.25, 0.08, 0.14, 0.03};
	float ATSR_SLSF[3]={ 0.429583, 0.1725, 0.11};
	float ATSR_SLSFErr[3]={0.0731061, 0.0807372, 0.11};
	float ATSB_SLSF[3]={0.539, 0.32125, 0.134205};
	float ATSB_SLSFErr[3]={0.0315, 0.0694853, 0.0712219};
	//update this
	float PhoSF_1H[4]={0.79, 0.36, 0.91, 0.67};
	float PhoSFErr_1H[4]={0.15, 0.02, 0.06, 0.04};
	float PhoSF_2H[4]={0.51, 0.36, 2.42, 0.67};
	float PhoSFErr_2H[4]={0.18, 0.02, 0.72, 0.04};

    if( ! doubleHiggsRegion ){
        regionLabels[0] = "tagSR";
        regionLabels[2] = "tagSB";
    }
    TH1F* temp[numRegions];
    TH1F* MC[numRegions];
    TH1F* Data[numRegions];
	TH1F*MCZJets = new TH1F("MCZJets","MC",numMETbins+1,METbins);	
	TH1F*MCTTJets = new TH1F("MCTTJets","MC",numMETbins+1,METbins);	
	TH1F*MCWJets = new TH1F("MCWJets","MC",numMETbins+1,METbins);	
	TH1F*MCSnglT = new TH1F("MCSnglT","MC",numMETbins+1,METbins);	
	TH1F*MCOther = new TH1F("MCOther","MC",numMETbins+1,METbins);	
	TH1F*MCQCD = new TH1F("MCQCD","MC",numMETbins+1,METbins);
	
    	MCQCD->SetFillColor(kGray);
	MCOther->SetFillColor(kRed+1);
	MCZJets->SetFillColor(kGreen+1);
	MCTTJets->SetFillColor(kCyan);
	MCSnglT->SetFillColor(kOrange);
	MCWJets->SetFillColor(kBlue);	
     THStack*hstackSignal=new THStack("hstackSignal","");
    for( int r = 0 ; r < 1 ; r++ ){
        
	TH1F*ZJets=(TH1F*) f->Get("MET_"+regionLabels[r]+"_ZJets");
	TH1F*TTJets=(TH1F*) f->Get("MET_"+regionLabels[r]+"_TT");
	TH1F*WJets=(TH1F*) f->Get("MET_"+regionLabels[r]+"_WJets");
	TH1F*SnglT=(TH1F*) f->Get("MET_"+regionLabels[r]+"_SnglT");
	TH1F*Other=(TH1F*) f->Get("MET_"+regionLabels[r]+"_Other");
	TH1F*QCD=(TH1F*) f->Get("MET_"+regionLabels[r]+"_QCD");
	
	for( int b = 2; b <= numMETbins+2 ; b++ ){
		std::cout<<"Met Bin "<<b<<std::endl;	
		MCZJets->SetBinContent(b-1, ZJets->GetBinContent(b));	
		MCWJets->SetBinContent(b-1, WJets->GetBinContent(b));	
		MCTTJets->SetBinContent(b-1, TTJets->GetBinContent(b));	
		MCQCD->SetBinContent(b-1, QCD->GetBinContent(b));	
		MCOther->SetBinContent(b-1, Other->GetBinContent(b));	
		MCSnglT->SetBinContent(b-1, SnglT->GetBinContent(b));
		float QCDErr=sqrt((QCD->GetBinError(b)/QCD->GetBinContent(b))*(QCD->GetBinError(b)/QCD->GetBinContent(b))+(LDPSFErr_1H[r]/LDPSF_1H[r]*LDPSFErr_1H[r]/LDPSF_1H[r]))*LDPSF_1H[r]*QCD->GetBinContent(b);
		if(MCQCD->GetBinContent(b)<0.000001)QCDErr=LDPSFErr_1H[r];
		float ZErr=sqrt((ZJets->GetBinError(b)/ZJets->GetBinContent(b))*(ZJets->GetBinError(b)/ZJets->GetBinContent(b))+(PhoSFErr_1H[r]/PhoSF_1H[r]*PhoSFErr_1H[r]/PhoSF_1H[r]))*PhoSF_1H[r]*ZJets->GetBinContent(b);
		float WErr=sqrt((WJets->GetBinError(b)/WJets->GetBinContent(b))*(WJets->GetBinError(b)/WJets->GetBinContent(b))+(SLSFErr_1H[r]/SLSF_1H[r]*SLSFErr_1H[r]/SLSF_1H[r]))*SLSF_1H[r]*WJets->GetBinContent(b);
		float TErr=sqrt((TTJets->GetBinError(b)/TTJets->GetBinContent(b))*(TTJets->GetBinError(b)/TTJets->GetBinContent(b))+(SLSFErr_1H[r]/SLSF_1H[r]*SLSFErr_1H[r]/SLSF_1H[r]))*SLSF_1H[r]*TTJets->GetBinContent(b);

		MCQCD->SetBinError(b,QCDErr);
		MCZJets->SetBinError(b,ZErr);
		MCWJets->SetBinError(b,WErr);
		MCTTJets->SetBinError(b,TErr);
	}
	if( ! doubleHiggsRegion ){
	MCQCD->Scale(LDPSF_1H[0]);
	MCWJets->Scale(SLSF_1H[0]);	
	MCTTJets->Scale(SLSF_1H[0]);	
	MCZJets->Scale(PhoSF_1H[0]);	
	}
	else{
	MCQCD->Scale(LDPSF_2H[0]);
	MCWJets->Scale(SLSF_2H[0]);	
	MCTTJets->Scale(SLSF_2H[0]);	
	MCZJets->Scale(PhoSF_2H[0]);	
	}
	hstackSignal->Add(MCQCD);
	hstackSignal->Add(MCOther);
	hstackSignal->Add(MCSnglT);
	hstackSignal->Add(MCWJets);
	hstackSignal->Add(MCTTJets);
	hstackSignal->Add(MCZJets);
	TH1D*Total=(TH1D*)hstackSignal->GetStack()->Last();
	for(int i=1; i<=3;++i)std::cout<<"Met Bin Yield Stack"<<Total->GetBinContent(i)<<std::endl;
    }

    for( int r = 0 ; r < numRegions ; r++ ){
	//need to add temp[r]
        //temp[r] = (TH1F*) f->Get("MET_"+regionLabels[r]+"_sum");
        //temp[r] = (TH1F*) f->Get("MET_"+regionLabels[r]+"_ZJets");
        //temp[r]=(TH1F*)f->Get("MET_"+regionLabels[r]+"_ZJets");
	
        Data[r] = new TH1F("Data_"+regionLabels[r],"Data_"+regionLabels[r],numMETbins+1,METbins);
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
	    TH1F*tempQCD=(TH1F*) f->Get("MET_"+regionLabels[r]+"_QCD");
	    TH1F*tempZ=(TH1F*) f->Get("MET_"+regionLabels[r]+"_ZJets");
	    TH1F*tempW=(TH1F*) f->Get("MET_"+regionLabels[r]+"_WJets");
	    TH1F*tempT=(TH1F*) f->Get("MET_"+regionLabels[r]+"_TT");
	    TH1F*tempSnglT=(TH1F*) f->Get("MET_"+regionLabels[r]+"_SnglT");
	    TH1F*tempOther=(TH1F*) f->Get("MET_"+regionLabels[r]+"_Other");
	    TH1F*tempData=(TH1F*) f->Get("MET_"+regionLabels[r]+"_data");

        for( int b = 2 ; b <= numMETbins+2 ; b++ ){
	    tempQCD=(TH1F*) f->Get("MET_"+regionLabels[r]+"_QCD");
	    tempZ=(TH1F*) f->Get("MET_"+regionLabels[r]+"_ZJets");
	    tempW=(TH1F*) f->Get("MET_"+regionLabels[r]+"_WJets");
	    tempT=(TH1F*) f->Get("MET_"+regionLabels[r]+"_TT");
	    tempSnglT=(TH1F*) f->Get("MET_"+regionLabels[r]+"_SnglT");
	    tempOther=(TH1F*) f->Get("MET_"+regionLabels[r]+"_Other");
	    //std::cout<<"Data Label "<<"MET_"+regionLabels[r]+"_data"<<std::endl;
	    if(!doubleHiggsRegion){
		if(r==1){SLSF_1H[r]=ATSR_SLSF[b-2]; SLSFErr_1H[r]=ATSR_SLSFErr[b-2];}
		if(r==3){SLSF_1H[r]=ATSB_SLSF[b-2]; SLSFErr_1H[r]=ATSB_SLSFErr[b-2];}
		float QCDErr=sqrt((tempQCD->GetBinError(b)/tempQCD->GetBinContent(b))*(tempQCD->GetBinError(b)/tempQCD->GetBinContent(b))+(LDPSFErr_1H[r]/LDPSF_1H[r]*LDPSFErr_1H[r]/LDPSF_1H[r]))*LDPSF_1H[r]*tempQCD->GetBinContent(b);
		if(tempQCD->GetBinContent(b)<0.000001)QCDErr=LDPSFErr_1H[r];
		float ZErr=sqrt((tempZ->GetBinError(b)/tempZ->GetBinContent(b))*(tempZ->GetBinError(b)/tempZ->GetBinContent(b))+(PhoSFErr_1H[r]/PhoSF_1H[r]*PhoSFErr_1H[r]/PhoSF_1H[r]))*PhoSF_1H[r]*tempZ->GetBinContent(b);
		float WErr=sqrt((tempW->GetBinError(b)/tempW->GetBinContent(b))*(tempW->GetBinError(b)/tempW->GetBinContent(b))+(SLSFErr_1H[r]/SLSF_1H[r]*SLSFErr_1H[r]/SLSF_1H[r]))*SLSF_1H[r]*tempW->GetBinContent(b);
		float TErr=sqrt((tempT->GetBinError(b)/tempT->GetBinContent(b))*(tempT->GetBinError(b)/tempT->GetBinContent(b))+(SLSFErr_1H[r]/SLSF_1H[r]*SLSFErr_1H[r]/SLSF_1H[r]))*SLSF_1H[r]*tempT->GetBinContent(b);
		tempQCD->SetBinError(b, QCDErr);
		tempZ->SetBinError(b, ZErr);
		tempW->SetBinError(b, WErr);
		tempT->SetBinError(b, TErr);
		tempQCD->SetBinContent(b,tempQCD->GetBinContent(b)*LDPSF_1H[r]);
		tempW->SetBinContent(b,tempW->GetBinContent(b)*SLSF_1H[r]);
		tempT->SetBinContent(b,tempT->GetBinContent(b)*SLSF_1H[r]);
		tempZ->SetBinContent(b,tempZ->GetBinContent(b)*PhoSF_1H[r]);
	    }
	    else{
		//update for the MET Dependant SF for antit-tag region for SL
		if(r==1){SLSF_2H[r]=ATSR_SLSF[b-2]; SLSFErr_2H[r]=ATSR_SLSFErr[b-2];}
		if(r==3){SLSF_2H[r]=ATSB_SLSF[b-2]; SLSFErr_2H[r]=ATSB_SLSFErr[b-2];}
		float QCDErr=sqrt((tempQCD->GetBinError(b)/tempQCD->GetBinContent(b))*(tempQCD->GetBinError(b)/tempQCD->GetBinContent(b))+(LDPSFErr_2H[r]/LDPSF_2H[r]*LDPSFErr_2H[r]/LDPSF_2H[r]))*LDPSF_2H[r]*tempQCD->GetBinContent(b);
		if(tempQCD->GetBinContent(b)<0.000001)QCDErr=LDPSFErr_2H[r];
		float ZErr=sqrt((tempZ->GetBinError(b)/tempZ->GetBinContent(b))*(tempZ->GetBinError(b)/tempZ->GetBinContent(b))+(PhoSFErr_2H[r]/PhoSF_2H[r]*PhoSFErr_2H[r]/PhoSF_2H[r]))*PhoSF_2H[r]*tempZ->GetBinContent(b);
		float WErr=sqrt((tempW->GetBinError(b)/tempW->GetBinContent(b))*(tempW->GetBinError(b)/tempW->GetBinContent(b))+(SLSFErr_2H[r]/SLSF_2H[r]*SLSFErr_2H[r]/SLSF_2H[r]))*SLSF_2H[r]*tempW->GetBinContent(b);
		if(tempW->GetBinContent(b)<0.000001)WErr=SLSF_2H[r];
		float TErr=sqrt((tempT->GetBinError(b)/tempT->GetBinContent(b))*(tempT->GetBinError(b)/tempT->GetBinContent(b))+(SLSFErr_2H[r]/SLSF_2H[r]*SLSFErr_2H[r]/SLSF_2H[r]))*SLSF_2H[r]*tempT->GetBinContent(b);
		if(tempT->GetBinContent(b)<0.0000001)TErr=SLSF_2H[r];
		//tempQCD->SetBinError(b, QCDErr);
		tempZ->SetBinError(b, ZErr);
		tempW->SetBinError(b,WErr);
		tempT->SetBinError(b,TErr);
		tempQCD->SetBinContent(b,tempQCD->GetBinContent(b)*LDPSF_2H[r]);
		tempW->SetBinContent(b,tempW->GetBinContent(b)*SLSF_2H[r]);
		tempT->SetBinContent(b,tempT->GetBinContent(b)*SLSF_2H[r]);
		tempZ->SetBinContent(b,tempZ->GetBinContent(b)*PhoSF_2H[r]);
	    }
	    TH1F*temp=(TH1F*)tempQCD->Clone("temp");	 
	    temp->Reset();
	    temp->Add(tempQCD);
	    temp->Add(tempZ);
	    temp->Add(tempW);
	    temp->Add(tempT);
	    temp->Add(tempSnglT);
	    temp->Add(tempOther);
	    Data[r]->SetBinContent(b-1, tempData->GetBinContent(b));
            MC[r]->SetBinContent(b-1,temp->GetBinContent(b));
            MC[r]->SetBinError(b-1,temp->GetBinError(b));
            cout << " & " <<  MC[r]->GetBinContent(b) << " $\\pm$ " << MC[r]->GetBinError(b) ;
        }
    }

    TH1F* MCprediction = new TH1F(*MC[1]);
    MCprediction->SetNameTitle("MCprediction","MCprediction");
    //MCprediction->Multiply(MC[2]);
    //MCprediction->Divide(MC[3]);
    TH1F*Dataprediction=new TH1F(*Data[1]);
    //Dataprediction->Multiply(Data[2]);
    //Dataprediction->Divide(Data[3]);
    Dataprediction->SetNameTitle("Dataprediction", "Dataprediction");
   Dataprediction->SetMarkerStyle(kFullCircle);
   Dataprediction->SetMarkerColor(kBlack);

    MCprediction->SetFillColor(kRed);
    MCprediction->SetMarkerSize(0.);
    MCprediction->SetMarkerStyle(1);
    MCprediction->SetLineColor(1);
    MCprediction->SetFillStyle(3490);
    MCprediction->SetFillColor(kRed);
    TH1F* Closure = new TH1F(*Dataprediction);
    Closure->SetNameTitle("Closure","Closure");
    Closure->Divide(MCprediction);
   TGraphAsymmErrors* grClose=new TGraphAsymmErrors(Closure); 
    SetRatioErr(Dataprediction, MCprediction, *grClose);
    Closure->Reset();
    Closure->GetYaxis()->SetTitle("Data/MC");
    Closure->SetMarkerStyle(8);
    Closure->SetLineColor(1);
        
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
    MCprediction->GetYaxis()->SetRangeUser(0.0,50.0);
    MCprediction->Draw("e2");
    Dataprediction->Draw("pesame");
    //MCprediction->Draw("e2same");
    //hstackSignal->Draw("histsame");	
   //MCprediction->Draw("e2same");
    //MC[0]->Draw("p,e1,same");

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
    //leg->AddEntry(MCZJets,"Z#rightarrow #nu#nu","f");
    //leg->AddEntry(MCTTJets,"TTbar","f");
    //leg->AddEntry(MCWJets,"W+Jets","f");
    //leg->AddEntry(MCOther,"Rare Diboson","f");
    //leg->AddEntry(MCSnglT,"Single Top","f");
    //leg->AddEntry(MCQCD,"QCD multi-jet","f");
    leg->AddEntry(Dataprediction,"Data Antitag SR ","p");
    leg->AddEntry(MCprediction,"MC Antitag SR ", "f");
        leg->Draw();
    botPad->cd();
    Closure->Draw("p,e1");
    Closure->GetYaxis()->SetRangeUser(0.,2.);
      Closure->Draw("p,e1");
    grClose->Draw("pesame");
    TGraph*KappaNom_1=new TGraph();
        KappaNom_1->SetPoint(0, 0,1);
 KappaNom_1->SetPoint(1,9999999,1);
        KappaNom_1->SetLineWidth(2.0);
        KappaNom_1->SetLineStyle(kDashed);
        KappaNom_1->Draw("lsame");
    if(doubleHiggsRegion){
    can->SaveAs("UnblindingTest_doubletagSBRegionTotal.png");
        can->SaveAs("UnblindingTest_doubletagSBRegionTotal.pdf");
        can->SaveAs("UnblindingTest_doubletagSBRegionTotal.eps");        
    }else{
        can->SaveAs("Unblinding_antitagSRRegionTotal.png");
        can->SaveAs("Unblinding_antitagSRRegionTotal.pdf");
        can->SaveAs("Unblinding_antitagSRRegionTotal.eps");        
    }
}

