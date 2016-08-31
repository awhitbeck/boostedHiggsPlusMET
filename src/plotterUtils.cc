#include "heppySkimTree.h"
#include "TH1F.h"
#include "TString.h"
#include "TCanvas.h"
#include "TLegend.h"

#include <iostream>
#include <vector>
#include <map>

using namespace std;

//double lumi=9200.;
double lumi=15000.;

template <typename ntupleType> class plot{

 public: 

  plot( double (*fillerFunc_)(ntupleType*) , TString label_="var"){
    fillerFunc = fillerFunc_;
    label = label_;
    xlabel = "" ; 
    nbins = 40; lower = 200.; upper = 1200.;
    stack=new THStack(label+"_stack",label+"_stack");
  };

  plot( double (*fillerFunc_)(ntupleType*) , 
	TString label_="var",TString xlabel_="var",
	int nbins_=20 , double lower_=200. , double upper_=2200.){
    fillerFunc = fillerFunc_;
    label = label_;
    xlabel =xlabel_ ; 
    nbins = nbins_; lower = lower_; upper = upper_;
    stack=new THStack(label+"_stack",label+"_stack");
  };
  
  void setBinning(int nbins_ , double lower_ , double upper_ ){
    nbins = nbins_ ; lower = lower_ ; upper = upper_ ;
  };
  
  void addNtuple(ntupleType* ntuple_,TString tag="test"){ 
    //cout << "nbins: " << nbins << " lower: " << lower << " upper: " << upper << endl;
    tagMap[ntuple_] = tag;
    histoMap[ntuple_] = new TH1F(label+"_"+tag,label+"_"+tag,nbins,lower,upper);
    histoMap[ntuple_]->Sumw2();
  };

  void addSignalNtuple(ntupleType* ntuple_,TString tag="test"){ 
    //cout << "nbins: " << nbins << " lower: " << lower << " upper: " << upper << endl;
    tagMap[ntuple_] = tag;
    signalHistoMap[ntuple_] = new TH1F(label+"_"+tag,label+"_"+tag,nbins,lower,upper);
    signalHistoMap[ntuple_]->Sumw2();
  };
  
  void addDataNtuple(ntupleType* ntuple_,TString tag="test"){
    //cout << "nbins: " << nbins << " lower: " << lower << " upper: " << upper << endl;
    tagMap[ntuple_] = tag ;
    dataHist = new TH1F(label+"_"+tag,label+"_"+tag,nbins,lower,upper);
    dataHist->SetMarkerStyle(8);
  };
  
  void fill(ntupleType* ntuple ){
    if( histoMap.find(ntuple) != histoMap.end() ){
      histoMap[ntuple]->Fill(fillerFunc(ntuple),ntuple->xsec*lumi);
    }else{
      cout << "plot::fill - ERROR: key not found: " << ntuple << endl;
    }
  };

  void fillSignal(ntupleType* ntuple ){
    if( signalHistoMap.find(ntuple) != signalHistoMap.end() ){
      signalHistoMap[ntuple]->Fill(fillerFunc(ntuple),ntuple->xsec*lumi);
    }else{
      cout << "plot::fillSignal - ERROR: key not found, " << ntuple << endl;
    }
  };

  void fill(ntupleType* ntuple , float customWeight ){
    if( histoMap.find(ntuple) != histoMap.end() ){
      histoMap[ntuple]->Fill(fillerFunc(ntuple),lumi*customWeight);
    }else{
      cout << "plot::fill - ERROR: key not found: " << ntuple << endl;
    }
  };

  void fillSignal(ntupleType* ntuple , float customWeight ){
    if( signalHistoMap.find(ntuple) != signalHistoMap.end() ){
      signalHistoMap[ntuple]->Fill(fillerFunc(ntuple),customWeight);
    }else{
      cout << "plot::fillSignal - ERROR: key not found, " << ntuple << endl;
    }
  };

  void fillData(ntupleType* ntuple ){
    if( dataHist )
      dataHist->Fill(fillerFunc(ntuple));
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
    }else{
      cout << "plot::setFillColor - ERROR: couldn't find key, " << ntuple << endl;
    }
  };

  void buildStack(vector<ntupleType*> ntuples){
    if( stack ){
      for( int iSample = 0 ; iSample < ntuples.size() ; iSample++ ){
	stack->Add(histoMap[ntuples[iSample]]);
      }    
    }
  };

  void buildStack(){
    
    vector<ntupleType*> ntuples;
    for( typename map<ntupleType*,TH1F*>::iterator it = histoMap.begin() ;
	 it != histoMap.end() ; 
	 ++it){
      ntuples.push_back(it->first);
    }
    buildStack(ntuples);
  };

  void buildSum(){
    sum = NULL;
    for( typename map<ntupleType*,TH1F*>::iterator it = histoMap.begin() ;
	 it != histoMap.end() ; 
	 ++it){
      if( sum == NULL ){
	sum = new TH1F(*(it->second));
	sum->SetNameTitle(label+"_sum",label+"_sum");
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
    //if( dataHist ) 
    //  dataHist->Write();

  };

  void Draw(TCanvas* can,
	    vector<ntupleType*>ntuples,
	    vector<ntupleType*>signalNtuples,
	    TString dir = "./" ){

    if( ! can ) return ;
    can->cd();

    buildStack(ntuples);
    stack->Draw("histo");
    cout << "xlabel: " << xlabel << endl;
    stack->GetXaxis()->SetTitle(xlabel);
    stack->GetXaxis()->SetNdivisions(505);
    stack->GetYaxis()->SetTitle("Events");
    buildSum();
    double max = sum->GetMaximum(); 
    for(int iSample = 0 ; iSample < signalNtuples.size() ; iSample++){
      TH1F* temp = signalHistoMap[signalNtuples[iSample]];
      if( temp ){
	//temp->Scale(sum->Integral()/temp->Integral());
	temp->Draw("histo,SAME");
	if( temp->GetMaximum() > max ) 
	  max = temp->GetMaximum();
      }
    }
    //dataHist->Draw("e1,SAME");
    //if( dataHist->GetMaximum() > max ) 
    //  max = dataHist->GetMaximum();

    stack->SetMaximum(max);
    stack->SetMinimum(0.1);

    gPad->SetLogy(false);
    can->SaveAs(dir+"/"+label+".png");
    gPad->SetLogy(true);
    can->SaveAs(dir+"/"+label+"_LogY.png");

    TCanvas* legCan = new TCanvas("legCan","legCan",500,500);
    TLegend* leg = new TLegend(0.1,.1,.9,.9);
    leg->SetBorderSize(0);
    leg->SetFillColor(0);
    for(int iSample = 0 ; iSample < ntuples.size() ; iSample++){
      leg->AddEntry(histoMap[ntuples[iSample]],tagMap[ntuples[iSample]],"f");
    }
    for(int iSample = 0 ; iSample < signalNtuples.size() ; iSample++){
      leg->AddEntry(signalHistoMap[signalNtuples[iSample]],tagMap[signalNtuples[iSample]],"f");
    }
    // leg->AddEntry(dataHist,"data","p");
    leg->Draw();
    legCan->SaveAs(dir+"/legend.png");
  }

  TString label;
  TString xlabel;
  int nbins;
  double lower,upper;
  map<ntupleType*,TH1F*> histoMap;
  map<ntupleType*,TString> tagMap;
  map<ntupleType*,TH1F*> signalHistoMap;
  TH1F* dataHist;
  double (*fillerFunc)(ntupleType*);
  THStack* stack;
  TH1F* sum; 
};
