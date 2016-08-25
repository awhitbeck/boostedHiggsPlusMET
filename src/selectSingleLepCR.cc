#ifndef SELECTSINGLELEPCR_HEPPY
#define SELECTSINGLELEPCR_HEPPY

#include "processor.h"

#include "TH1F.h"
#include "TLorentzVector.h"

#include <iostream>

using namespace std;

template <class TreeType> class selectSingleLepCR : public processor<TreeType> {

public : 

  TH1F* histo;
  TreeType* ntuple;
  TString label;

  selectSingleLepCR()
    : processor<TreeType>("selectSingleLepCR")
  {
    ntuple = 0; 
  };
  selectSingleLepCR( TreeType *ntuple_ ,
		  TString label_ )
    : processor<TreeType>("selectSingleLepCR")
  {
    ntuple = ntuple_;
    label = label_;
    histo = new TH1F("selectSingleLepCRYields_"+label,"selectSingleLepCRYields_"+label,3,0.5,3.5);

    ntuple->fChain->SetBranchStatus("naLeptons",1);
    ntuple->fChain->SetBranchStatus("aLeptons_pt",1);
    ntuple->fChain->SetBranchStatus("aLeptons_isPFMuon",1);
    ntuple->fChain->SetBranchStatus("aLeptons_isGlobalMuon",1);
    ntuple->fChain->SetBranchStatus("aLeptons_isTrackerMuon",1);
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
      if( (ntuple->aLeptons_pt)[iLep]>20. && ntuple->aLeptons_isPFMuon[iLep] && (ntuple->aLeptons_isGlobalMuon[iLep]||ntuple->aLeptons_isTrackerMuon[iLep]) ){
	numMuons++;
      }
    }
    histo->Fill(1);
    for( int iLep = 0 ; iLep < ntuple->naLeptons ; iLep++ ){
      if( ntuple->aLeptons_pt[iLep]>20. && 
	  ( ( abs(ntuple->aLeptons_etaSc[iLep]) < 1.479 && ntuple->aLeptons_relIso03[iLep] < 0.0994 && ntuple->aLeptons_eleSieie[iLep] < 0.011 && abs(ntuple->aLeptons_eleDEta[iLep]) < 0.00477 && abs(ntuple->aLeptons_eleDPhi[iLep]) < 0.222 && ntuple->aLeptons_eleHoE[iLep] < 0.298 && ntuple->aLeptons_eleooEmooP[iLep] < 0.241 && ntuple->aLeptons_eleExpMissingInnerHits[iLep] <= 1 ) ||
	    ( abs(ntuple->aLeptons_etaSc[iLep]) > 1.479 && ntuple->aLeptons_relIso03[iLep] < 0.107 && ntuple->aLeptons_eleSieie[iLep] < 0.0314 && abs(ntuple->aLeptons_eleDEta[iLep]) < 0.00868 && abs(ntuple->aLeptons_eleDPhi[iLep]) < 0.213 && ntuple->aLeptons_eleHoE[iLep] < 0.101 && ntuple->aLeptons_eleooEmooP[iLep] < 0.14 && ntuple->aLeptons_eleExpMissingInnerHits[iLep] <= 1 ) )){
	return false;
      }
    }
    histo->Fill(2);
    if( ntuple->met_pt>200. ) histo->Fill(3); 
    else{
      return false;
    }
    return true;

  };

  void postProcess( ) override {
    histo->Write();
  }

};

#endif
