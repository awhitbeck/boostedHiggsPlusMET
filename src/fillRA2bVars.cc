#ifndef FILLRA2BVARS
#define FILLRA2BVARS

#include "filler.h"
#include <iostream>
#include <string>
#include <cassert>

#include "TLeaf.h"
#include "TString.h"
#include "TLorentzVector.h"

using namespace std;

template <class TreeType> class fillRA2bVars : public filler<TreeType> {

public : 

  TH1F* histoMHT,*histoHT,*histoNJets,*histoDeltaPhi1,*histoDeltaPhi2,*histoDeltaPhi3,*histoDeltaPhi4;
  TreeType* ntuple;
  TString weightbranch;

  fillRA2bVars()
    : filler<TreeType>("fillRA2bVars"){
    ntuple = 0;
    histoMHT = 0; 
    histoHT = 0; 
    histoNJets = 0;
    histoDeltaPhi1 = 0;
    histoDeltaPhi2 = 0;
    histoDeltaPhi3 = 0;
    histoDeltaPhi4 = 0;    
  };
  
  fillRA2bVars( TreeType* ntuple_ , 
		 TString histotag ,
		 TString weightbranch_ )
    : filler<TreeType>("fillRA2bVars")
  {

    ntuple = ntuple_;
    weightbranch = weightbranch_;
    histoMHT = new TH1F("histoMHT_"+histotag,"histoMHT_"+histotag,50,200.,1500.);
    histoHT = new TH1F("histoHT_"+histotag,"histoHT_"+histotag,60,500.,3500.);
    histoNJets = new TH1F("histoNJets_"+histotag,"histoNJets_"+histotag,15,0.5,15.5);
    histoDeltaPhi1 = new TH1F("histoDeltaPhi1_"+histotag,";Events;#Delta#Phi_{j1,E_T^{miss}",40,0.,TMath::Pi());
    histoDeltaPhi2 = new TH1F("histoDeltaPhi2_"+histotag,"",40,0.,TMath::Pi());
    histoDeltaPhi3 = new TH1F("histoDeltaPhi3_"+histotag,"",40,0.,TMath::Pi());
    histoDeltaPhi4 = new TH1F("histoDeltaPhi4_"+histotag,"",40,0.,TMath::Pi());
    
    ntuple->fChain->SetBranchStatus("nJet",1);
    ntuple->fChain->SetBranchStatus("Jet_pt",1);
    ntuple->fChain->SetBranchStatus("Jet_eta",1);
    ntuple->fChain->SetBranchStatus("Jet_phi",1);
    ntuple->fChain->SetBranchStatus("Jet_mass",1);

    if( ntuple->fChain->GetLeaf( weightbranch ) == NULL )
      assert(0);       
  };

  bool process( ) override {

    int NJets = 0;
    double HT = 0.;
    TLorentzVector MHTvec(0.,0.,0.,0.);
    double MHT = 0. ; 
    double DeltaPhi1=-999.,DeltaPhi2=-999.,DeltaPhi3=-999.,DeltaPhi4=-999.;
    TLorentzVector MHTjets[4];
    int MHTjetCount = 0;
    for( int i = 0 ; i < ntuple->nJet ; i++ ){

      /*
      cout << "iJet: " << i << "/" << ntuple->nJet << endl;
      cout << "Jet pt: " << ntuple->Jet_pt[i] << endl; 
      cout << "Jet eta: " << ntuple->Jet_eta[i] << endl; 
      cout << "Jet phi: " << ntuple->Jet_phi[i] << endl; 
      cout << "Jet mass: " << ntuple->Jet_mass[i] << endl; 
      */

      if( ntuple->Jet_pt[i] > 30. && fabs(ntuple->Jet_eta[i])<2.4 ){
	NJets++;
	HT+=ntuple->Jet_pt[i];
      }// HT stuff
      if( ntuple->Jet_pt[i] > 30. && fabs(ntuple->Jet_eta[i])<5.0 ){
	TLorentzVector temp(0.,0.,0.,0.);
	temp.SetPtEtaPhiM(ntuple->Jet_pt[i],ntuple->Jet_eta[i],ntuple->Jet_phi[i],ntuple->Jet_mass[i]);
	MHTvec+=temp;

	if( MHTjetCount < 4 ){
	  MHTjets[MHTjetCount] = temp;
	  MHTjetCount++;
	}
      }// MHT stuff
      
      if( MHTjetCount > 0 ){
	DeltaPhi1 = fabs(MHTvec.DeltaPhi(MHTjets[0]));
      }
      if( MHTjetCount > 1 ){
	DeltaPhi2 = fabs(MHTvec.DeltaPhi(MHTjets[1]));
      }
      if( MHTjetCount > 2 ){
	DeltaPhi3 = fabs(MHTvec.DeltaPhi(MHTjets[2]));
      }
      if( MHTjetCount > 3 ){
	DeltaPhi4 = fabs(MHTvec.DeltaPhi(MHTjets[3]));
      }

    }// end loop over jets

    histoMHT->Fill( MHTvec.Pt() , ntuple->fChain->GetLeaf( weightbranch.Data() )->GetValue() );
    histoHT->Fill( HT , ntuple->fChain->GetLeaf( weightbranch.Data() )->GetValue() );
    histoNJets->Fill( NJets , ntuple->fChain->GetLeaf( weightbranch.Data() )->GetValue() );
    histoDeltaPhi1->Fill( DeltaPhi1 , ntuple->fChain->GetLeaf( weightbranch.Data() )->GetValue() );
    histoDeltaPhi2->Fill( DeltaPhi2 , ntuple->fChain->GetLeaf( weightbranch.Data() )->GetValue() );
    histoDeltaPhi3->Fill( DeltaPhi3 , ntuple->fChain->GetLeaf( weightbranch.Data() )->GetValue() );
    histoDeltaPhi4->Fill( DeltaPhi4 , ntuple->fChain->GetLeaf( weightbranch.Data() )->GetValue() );

    return true;

  };

};

#endif
