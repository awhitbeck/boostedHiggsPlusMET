#include "TGraphAsymmErrors.h"
#include "THStack.h"
#include "TH1F.h"
#include "TString.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLine.h"
#include "CMS_lumi.cc"

#include <iostream>
#include <vector>
#include <map>

using namespace std;

double lumi=35862.824;

template <typename ntupleType> class plot{

public: 

    plot(){};
    plot( double (*fillerFunc_)(ntupleType*) , TString label_="var"){
        fillerFunc = fillerFunc_;
        label = label_;
        xlabel = "" ; 
        nbins = 40; lower = 200.; upper = 1200.;
        binEdges = NULL;
        stack=new THStack(label+"_stack",label+"_stack");
        dataHist=NULL;
    };

    plot( double (*fillerFunc_)(ntupleType*) , 
          TString label_="var",TString xlabel_="var",
          int nbins_=20 , double lower_=200. , double upper_=2200.){
        fillerFunc = fillerFunc_;
        label = label_;
        xlabel =xlabel_ ; 
        nbins = nbins_; lower = lower_; upper = upper_;
        binEdges=NULL;
        stack=new THStack(label+"_stack",label+"_stack");
    };

    plot( double (*fillerFunc_)(ntupleType*) , 
          TString label_,TString xlabel_,
          int nbins_ , double* bins_){
        fillerFunc = fillerFunc_;
        label = label_;
        xlabel =xlabel_ ; 
        binEdges = bins_;
        nbins = nbins_; lower = binEdges[0]; upper = binEdges[nbins];
        stack=new THStack(label+"_stack",label+"_stack");
    };
  
    void setBinning(int nbins_ , double lower_ , double upper_ ){
        nbins = nbins_ ; lower = lower_ ; upper = upper_ ;
    };
  
    void addNtuple(ntupleType* ntuple_,TString tag="test"){ 
        //cout << "nbins: " << nbins << " lower: " << lower << " upper: " << upper << endl;
        //cout << "tag: " << tag << endl;
        tagMap[ntuple_] = tag;
        if( binEdges )
            histoMap[ntuple_] = new TH1F(label+"_"+tag,label+"_"+tag,nbins,binEdges);
        else
            histoMap[ntuple_] = new TH1F(label+"_"+tag,label+"_"+tag,nbins,lower,upper);
        histoMap[ntuple_]->Sumw2();
    };

    void addSignalNtuple(ntupleType* ntuple_,TString tag="test"){ 
        //cout << "nbins: " << nbins << " lower: " << lower << " upper: " << upper << endl;
        tagMap[ntuple_] = tag;
        if( binEdges )
            signalHistoMap[ntuple_] = new TH1F(label+"_"+tag,label+"_"+tag,nbins,binEdges);   
        else
            signalHistoMap[ntuple_] = new TH1F(label+"_"+tag,label+"_"+tag,nbins,lower,upper);

        signalHistoMap[ntuple_]->Sumw2();
    };
  
    void addDataNtuple(ntupleType* ntuple_,TString tag="test"){
        //cout << "nbins: " << nbins << " lower: " << lower << " upper: " << upper << endl;
        tagMap[ntuple_] = tag ;
        if( binEdges ){
            dataHist = new TH1F(label+"_"+tag,label+"_"+tag,nbins,binEdges);
        }else
            dataHist = new TH1F(label+"_"+tag,label+"_"+tag,nbins,lower,upper);
        dataHist->SetMarkerStyle(8);
    };
  
    int fill(ntupleType* ntuple ){
        if( histoMap.find(ntuple) != histoMap.end() ){
            return histoMap[ntuple]->Fill(fillerFunc(ntuple),ntuple->Weight*lumi);
        }else{
            cout << "plot::fill - ERROR: key not found: " << ntuple << endl;
            return 0;
        }
    };

    int fillSignal(ntupleType* ntuple ){
        if( signalHistoMap.find(ntuple) != signalHistoMap.end() ){
            return signalHistoMap[ntuple]->Fill(fillerFunc(ntuple),ntuple->Weight*lumi);
        }else{
            cout << "plot::fillSignal - ERROR: key not found, " << ntuple << endl;
            return 0;
        }
    };

    int fill(ntupleType* ntuple , float customWeight ){
        if( histoMap.find(ntuple) != histoMap.end() ){
            return histoMap[ntuple]->Fill(fillerFunc(ntuple),customWeight);
        }else{
            cout << "plot::fill - ERROR: key not found: " << ntuple << endl;
            return 0;
        }
    };

    int fillSignal(ntupleType* ntuple , float customWeight ){
        if( signalHistoMap.find(ntuple) != signalHistoMap.end() ){
            return signalHistoMap[ntuple]->Fill(fillerFunc(ntuple),customWeight);
        }else{
            cout << "plot::fillSignal - ERROR: key not found, " << ntuple << endl;
            return 0;
        }
    };

    int fillData(ntupleType* ntuple ){
        if( dataHist )
            return dataHist->Fill(fillerFunc(ntuple));
        else 
            return 0;
    };
  
    void setFillColor(ntupleType* ntuple , int color=1){
        if( histoMap.find(ntuple) != histoMap.end() ){
            histoMap[ntuple]->SetFillColor(color);
            histoMap[ntuple]->SetLineWidth(2);
        }else{
            cout << "plot::setFillColor - ERROR: couldn't find key, " << ntuple << endl;
        }
    };

    void setLineColor(ntupleType* ntuple , int color=1){
        if( signalHistoMap.find(ntuple) != signalHistoMap.end() ){
            signalHistoMap[ntuple]->SetLineColor(color);
            signalHistoMap[ntuple]->SetLineWidth(2);
        }else if(histoMap.find(ntuple) != histoMap.end() ){
            histoMap[ntuple]->SetLineColor(color);
            histoMap[ntuple]->SetLineWidth(2);
        }else{
            cout << "plot::setFillColor - ERROR: couldn't find key, " << ntuple << endl;
        }
    };
  
    void buildStack(vector<ntupleType*> ntuples,double scale=1.0){
        if( stack ){
            for( int iSample = 0 ; iSample < ntuples.size() ; iSample++ ){
                histoMap[ntuples[iSample]]->Scale(scale);
                stack->Add(histoMap[ntuples[iSample]]);
            }    
        }
    };

    void buildStack(double scale=1.0){
    
        vector<ntupleType*> ntuples;
        for( typename map<ntupleType*,TH1F*>::iterator it = histoMap.begin() ;
             it != histoMap.end() ; 
             ++it){
            ntuples.push_back(it->first);
        }
        buildStack(ntuples,scale);
    };

    void buildSum(TString tag=""){
        sum = NULL;
        for( typename map<ntupleType*,TH1F*>::iterator it = histoMap.begin() ;
             it != histoMap.end() ; 
             ++it){
            if( sum == NULL ){
                sum = new TH1F(*(it->second));
                if( tag == "" )
                    sum->SetNameTitle(label+"_sum",label+"_sum");
                else
                    sum->SetNameTitle(label+"_"+tag+"_sum",label+"_"+tag+"_sum");
            }else
                sum->Add(it->second);
        }
    };

    void Write(){

        for( typename map<ntupleType*,TH1F*>::iterator it = histoMap.begin() ;
             it != histoMap.end() ; 
             ++it ){
            if( it->second ) 
                it->second->Write();
        }

        for( typename map<ntupleType*,TH1F*>::iterator it = signalHistoMap.begin() ;
             it != signalHistoMap.end() ; 
             ++it ){
            if( it->second ) 
                it->second->Write();
        }
        if( dataHist )
            dataHist->Write();

    };

    void DrawNoRatio(TCanvas* can, 
                     vector<ntupleType*>ntuples,
                     vector<ntupleType*>signalNtuples,
                     TString dir = "./",
                     bool normalizeMCtoData=false){
      
        if( ! can ) return ;
          
        can->SetTopMargin(0.06);
        double max = 0 ;
        if( histoMap.size() ){

            buildSum();
            max = sum->GetMaximum()*2.0; 

            if( normalizeMCtoData )
                buildStack(ntuples,dataHist->Integral()/sum->Integral());
            else
                buildStack(ntuples);

            stack->Draw("histo");
            cout << "xlabel: " << xlabel << endl;
            stack->GetXaxis()->SetTitle(xlabel);
            stack->GetXaxis()->SetNdivisions(505);
            stack->GetYaxis()->SetTitle("Events");

        }
    
        for(int iSample = 0 ; iSample < signalNtuples.size() ; iSample++){
            TH1F* temp = signalHistoMap[signalNtuples[iSample]];
            if( temp ){

                temp->Draw("histo,SAME");
                if( temp->GetMaximum() > max ) 
                    max = temp->GetMaximum();
            }
        }
        if( dataHist ){
            dataHist->Draw("e1,SAME");
            if( dataHist->GetMaximum() > max ) 
                max = dataHist->GetMaximum();
        }

        stack->SetMaximum(max);
        stack->SetMinimum(0.1);

        stack->GetYaxis()->SetLabelFont(63);
        stack->GetYaxis()->SetLabelSize(14);
        stack->GetYaxis()->SetTitleFont(63);
        stack->GetYaxis()->SetTitleSize(20);
        stack->GetYaxis()->SetTitleOffset(1.6);

        stack->GetXaxis()->SetLabelFont(63);
        stack->GetXaxis()->SetLabelSize(14);
        stack->GetXaxis()->SetTitleFont(63);
        stack->GetXaxis()->SetTitleSize(20);
        stack->GetXaxis()->SetTitleOffset(1.6);

        writeExtraText = true;
        extraText="Preliminary";
        char lumiString[4];
        sprintf(lumiString,"%.1f",lumi/1000.);
        lumi_13TeV = lumiString;
        CMS_lumi( can , 4 , 0 );
        can->Update();
        can->RedrawAxis();
        can->GetFrame()->Draw();

        TLegend* leg = new TLegend(0.3,.8,.9,.9);
        leg->SetNColumns(5);
        leg->SetBorderSize(0);
        leg->SetFillColor(0);
        for(int iSample = 0 ; iSample < ntuples.size() ; iSample++){
            leg->AddEntry(histoMap[ntuples[iSample]],tagMap[ntuples[iSample]],"f");
        }
        for(int iSample = 0 ; iSample < signalNtuples.size() ; iSample++){
            leg->AddEntry(signalHistoMap[signalNtuples[iSample]],tagMap[signalNtuples[iSample]],"f");
        }
        if( dataHist ) 
            leg->AddEntry(dataHist,"data","p");
        leg->Draw();

        gPad->SetLogy(false);
        can->SaveAs(dir+"/"+label+".png");
        can->SaveAs(dir+"/"+label+".eps");
        can->SaveAs(dir+"/"+label+".pdf");
        gPad->SetLogy(true);
        can->SaveAs(dir+"/"+label+"_LogY.png");
        can->SaveAs(dir+"/"+label+"_LogY.eps");
        can->SaveAs(dir+"/"+label+"_LogY.pdf");

    }

    void Draw(TCanvas* can,
              vector<ntupleType*>ntuples,
              vector<ntupleType*>signalNtuples,
              TString dir = "./" ,
              double ratioYmin = 0.1 , 
              double ratioYmax = 2.0 ,
              bool normalizeMCtoData=false){

        if( ! can ) return ;
    
        TPad* topPad = new TPad("topPad","topPad",0.,0.4,.99,.99);
        TPad* botPad = new TPad("botPad","botPad",0.,0.01,.99,.39);
        botPad->SetBottomMargin(0.25);
        botPad->SetTopMargin(0.02);
        topPad->SetTopMargin(0.06);
        topPad->SetBottomMargin(0.17);
        topPad->Draw();
        botPad->Draw();
        topPad->cd();
    
        double max = 0 ;
        if( histoMap.size() ){

            buildSum();
            max = sum->GetMaximum(); 

            if( normalizeMCtoData )
                buildStack(ntuples,dataHist->Integral()/sum->Integral());
            else
                buildStack(ntuples);

            stack->Draw("histo");
            cout << "xlabel: " << xlabel << endl;
            stack->GetXaxis()->SetTitle(xlabel);
            stack->GetXaxis()->SetNdivisions(505);
            stack->GetYaxis()->SetTitle("Events");

        }
    
        for(int iSample = 0 ; iSample < signalNtuples.size() ; iSample++){
            TH1F* temp = signalHistoMap[signalNtuples[iSample]];
            if( temp ){
                //temp->Scale(sum->Integral()/temp->Integral());
                temp->Draw("histo,SAME");
                if( temp->GetMaximum() > max ) 
                    max = temp->GetMaximum();
            }
        }
        if( dataHist ){
            dataHist->Draw("e1,SAME");
            if( dataHist->GetMaximum() > max ) 
                max = dataHist->GetMaximum();
        }

        stack->SetMaximum(max);
        stack->SetMinimum(0.1);

        stack->GetYaxis()->SetLabelFont(63);
        stack->GetYaxis()->SetLabelSize(14);
        stack->GetYaxis()->SetTitleFont(63);
        stack->GetYaxis()->SetTitleSize(20);
        stack->GetYaxis()->SetTitleOffset(1.6);

        stack->GetXaxis()->SetLabelFont(63);
        stack->GetXaxis()->SetLabelSize(14);
        stack->GetXaxis()->SetTitleFont(63);
        stack->GetXaxis()->SetTitleSize(20);
        stack->GetXaxis()->SetTitleOffset(1.6);

        writeExtraText = true;
        extraText="Preliminary";
        char lumiString[4];
        sprintf(lumiString,"%.1f",lumi/1000.);
        lumi_13TeV = lumiString;
        CMS_lumi( can , 4 , 0 );
        can->Update();
        can->RedrawAxis();
        can->GetFrame()->Draw();

        botPad->cd();
        TH1F* ratio;
        if( dataHist ){
            // - - - - - - - build data/MC ratio histogram - - - - - - - - 
            ratio = new TH1F(*dataHist);
            ratio->SetNameTitle(sum->GetName()+TString("ratio"),sum->GetTitle());
            ratio->Divide(sum);
            if( normalizeMCtoData ) 
                ratio->Scale(sum->Integral()/dataHist->Integral());
        
            ratio->SetMarkerStyle(8);
            ratio->GetYaxis()->SetTitle("Data/MC");
            ratio->GetYaxis()->SetRangeUser(ratioYmin,ratioYmax);
            ratio->GetXaxis()->SetRangeUser(lower,upper);
            ratio->GetXaxis()->SetTitle(xlabel);
        
            ratio->GetYaxis()->SetLabelFont(63);
            ratio->GetYaxis()->SetLabelSize(14);
            ratio->GetYaxis()->SetTitleFont(63);
            ratio->GetYaxis()->SetTitleSize(20);
            ratio->GetYaxis()->SetTitleOffset(1.6);

            ratio->GetXaxis()->SetLabelFont(63);
            ratio->GetXaxis()->SetLabelSize(14);
            ratio->GetXaxis()->SetTitleFont(63);
            ratio->GetXaxis()->SetTitleSize(20);
            ratio->GetXaxis()->SetTitleOffset(2.);
            // ------------------------------------------------------------
        
            // - - - - - - - compute data/MC scale factor - - - - - - - - 
            char SF[16];
            sprintf(SF,"data/MC=%1.1f",dataHist->Integral()/sum->Integral());
            TText* scaleFactor = new TText(ratio->GetBinCenter(1)-ratio->GetBinWidth(1)/2.,ratioYmax+0.1,SF);
            scaleFactor->SetTextFont(43);
            scaleFactor->SetTextSize(16);
        
            TLine one(ratio->GetBinCenter(1)-ratio->GetBinWidth(1)/2.,1.,ratio->GetBinCenter(ratio->GetNbinsX())+ratio->GetBinWidth(ratio->GetNbinsX())/2.,1.);
            TLine avg(ratio->GetBinCenter(1)-ratio->GetBinWidth(1)/2.,dataHist->Integral()/sum->Integral(),ratio->GetBinCenter(ratio->GetNbinsX())+ratio->GetBinWidth(ratio->GetNbinsX())/2.,dataHist->Integral()/sum->Integral());
            avg.SetLineColor(2);
            avg.SetLineStyle(2);
            one.SetLineStyle(2);
            // ----------------------------------------------------------
        
            ratio->Draw("e1");
            one.Draw();
            if( normalizeMCtoData ) 
                avg.Draw();
            scaleFactor->Draw();
        }
        can->cd();
        topPad->cd();

        TLegend* leg = new TLegend(0.3,.8,.9,.9);
        leg->SetNColumns(5);
        leg->SetBorderSize(0);
        leg->SetFillColor(0);
        for(int iSample = 0 ; iSample < ntuples.size() ; iSample++){
            leg->AddEntry(histoMap[ntuples[iSample]],tagMap[ntuples[iSample]],"f");
        }
        for(int iSample = 0 ; iSample < signalNtuples.size() ; iSample++){
            leg->AddEntry(signalHistoMap[signalNtuples[iSample]],tagMap[signalNtuples[iSample]],"f");
        }
        if( dataHist ) 
            leg->AddEntry(dataHist,"data","p");
        leg->Draw();

        can->cd();
        topPad->cd();
        gPad->SetLogy(false);
        can->SaveAs(dir+"/"+label+".png");
        can->SaveAs(dir+"/"+label+".eps");
        can->SaveAs(dir+"/"+label+".pdf");
        gPad->SetLogy(true);
        can->SaveAs(dir+"/"+label+"_LogY.png");
        can->SaveAs(dir+"/"+label+"_LogY.eps");
        can->SaveAs(dir+"/"+label+"_LogY.pdf");


    }

    TString label;
    TString xlabel;
    int nbins;
    double lower,upper;
    double* binEdges;
    map<ntupleType*,TH1F*> histoMap;
    map<ntupleType*,TString> tagMap;
    map<ntupleType*,TH1F*> signalHistoMap;
    TH1F* dataHist;
    double (*fillerFunc)(ntupleType*);
    THStack* stack;
    TH1F* sum; 

};
