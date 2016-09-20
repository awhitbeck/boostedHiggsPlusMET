#ifndef SELECTBASELINE_HEPPY
#define SELECTBASELINE_HEPPY

#include "processor.h"

#include "TH1F.h"
#include "TLorentzVector.h"

#include <iostream>

using namespace std;

template <class TreeType> class selectBaseline : public processor<TreeType> {

public : 

  TH1F* histo;
  TreeType* ntuple;
  TString label;
  int minMu,maxMu,minEle,maxEle;

  selectBaseline()
    : processor<TreeType>("selectBaseline")
  {
    ntuple = 0; 
  };
  selectBaseline( TreeType *ntuple_ ,
		  TString label_ ,
		  int minMu_ = 0 , int maxMu_ = 0 , 
		  int minEle_= 0 , int maxEle_= 0 )
    : processor<TreeType>("selectBaseline")
  {
    ntuple = ntuple_;
    label = label_;
    minMu = minMu_ ; maxMu = maxMu_ ; 
    minEle = minEle_ ; maxEle = maxEle_ ;
    histo = new TH1F("selectBaselineYields_"+label,"selectBaselineYields_"+label,4,0.5,4.5);

  };

  bool process( ) override {

    histo->Fill(0);

    if( ntuple->Muons->size() >= minMu && ntuple->Muons->size() <= maxMu ) 
      histo->Fill(1);
    else
      return false;

    if( ntuple->Electrons->size() >= minEle && ntuple->Electrons->size() <= maxEle )
      histo->Fill(2);
    else 
      return false;

    if( ntuple->MET>300. ) 
      histo->Fill(3); 
    else
      return false;
   
    if( ntuple->HT>600. ) 
      histo->Fill(3); 
    else
      return false;
  
    return true;

  };

  void postProcess( ) override {
    histo->Write();
  }

};

#endif
