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
    histo = new TH1F("selectBaselineYields_"+label,"selectBaselineYields_"+label,3,0.5,3.5);

    ntuple->fChain->SetBranchStatus("naLeptons",1);
    ntuple->fChain->SetBranchStatus("aLeptons_pt",1);
    ntuple->fChain->SetBranchStatus("aLeptons_isPFMuon",1);
    ntuple->fChain->SetBranchStatus("aLeptons_isGlobalMuon",1);
    ntuple->fChain->SetBranchStatus("aLeptons_isTrackerMuon",1);
    ntuple->fChain->SetBranchStatus("aLeptons_miniRelIso",1);
    ntuple->fChain->SetBranchStatus("aLeptons_mediumMuonId",1);
    ntuple->fChain->SetBranchStatus("aLeptons_etaSc",1);
    ntuple->fChain->SetBranchStatus("aLeptons_relIso03",1);
    ntuple->fChain->SetBranchStatus("aLeptons_eleSieie",1);
    ntuple->fChain->SetBranchStatus("aLeptons_eleDEta",1);
    ntuple->fChain->SetBranchStatus("aLeptons_eleDPhi",1);
    ntuple->fChain->SetBranchStatus("aLeptons_eleHoE",1);
    ntuple->fChain->SetBranchStatus("aLeptons_eleExpMissingInnerHits",1);
    ntuple->fChain->SetBranchStatus("aLeptons_eleooEmooP",1);
    ntuple->fChain->SetBranchStatus("met_pt",1);

  };

  bool process( ) override {

    histo->Fill(0);

    int numElectrons = 0 , numMuons = 0 ;
    for( int iLep = 0 ; iLep < ntuple->naLeptons ; iLep++ ){
      if( ntuple->aLeptons_pt[iLep]>10. && abs(ntuple->aLeptons_eta[iLep])<2.4 && ntuple->aLeptons_mediumMuonId[iLep] == 1 && ntuple->aLeptons_miniRelIso[iLep] < 0.2  ){
	numMuons++;
      }
    }

    if( numMuons >= minMu && numMuons <= maxMu ) 
      histo->Fill(1);
    else
      return false;
    
    for( int iLep = 0 ; iLep < ntuple->naLeptons ; iLep++ ){
      if( ( ntuple->aLeptons_pt[iLep]>10. && abs(ntuple->aLeptons_eta[iLep])<2.5 && ntuple->aLeptons_miniRelIso[iLep] < 0.1 ) &&
	( ( abs(ntuple->aLeptons_etaSc[iLep]) < 1.479 && ntuple->aLeptons_eleSieie[iLep] < 0.0115 && abs(ntuple->aLeptons_eleDEta[iLep]) < 0.00749 &&
	  abs(ntuple->aLeptons_eleDPhi[iLep]) < 0.228 && ntuple->aLeptons_eleHoE[iLep] < 0.356 && ntuple->aLeptons_eleooEmooP[iLep] < 0.299 && 
	  ntuple->aLeptons_eleExpMissingInnerHits[iLep] <= 2 
	    ) || 
	  ( abs(ntuple->aLeptons_etaSc[iLep]) > 1.479 && ntuple->aLeptons_eleSieie[iLep] < 0.037 && abs(ntuple->aLeptons_eleDEta[iLep]) < 0.00895 && 
	    abs(ntuple->aLeptons_eleDPhi[iLep]) < 0.213 && ntuple->aLeptons_eleHoE[iLep] < 0.211 && ntuple->aLeptons_eleooEmooP[iLep] < 0.15 && 
	    ntuple->aLeptons_eleExpMissingInnerHits[iLep] <= 3 ))){ 
	  numElectrons++;
	}
    }
    if( numElectrons >= minEle && numElectrons <= maxEle )
      histo->Fill(2);
    else 
      return false;

    if( ntuple->met_pt>200. ) 
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
