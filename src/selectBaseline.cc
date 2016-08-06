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

  selectBaseline()
    : processor<TreeType>("selectBaseline")
  {
    ntuple = 0; 
  };
  selectBaseline( TreeType *ntuple_ ,
		  TString label_ )
    : processor<TreeType>("selectBaseline")
  {
    ntuple = ntuple_;
    label = label_;
    histo = new TH1F("selectBaselineYields_"+label,"selectBaselineYields_"+label,8,0.5,8.5);

    ntuple->fChain->SetBranchStatus("nbLeptons",1);
    ntuple->fChain->SetBranchStatus("Jet_pt",1);
    ntuple->fChain->SetBranchStatus("Jet_eta",1);
    ntuple->fChain->SetBranchStatus("Jet_phi",1);
    ntuple->fChain->SetBranchStatus("Jet_mass",1);
    ntuple->fChain->SetBranchStatus("nJet",1);

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
      
    }// end loop over jets

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
    
    MHT = MHTvec.Pt();

    /*
    std::cout << "Leptons: " << ntuple->nvLeptons << endl;
    std::cout << "NJets: " << NJets << endl;    
    std::cout << "HT: " << HT << endl;
    std::cout << "MHT: " << MHT << endl;
    std::cout << "DeltaPhi1: " << DeltaPhi1 << endl;
    std::cout << "DeltaPhi2: " << DeltaPhi2 << endl;    
    std::cout << "DeltaPhi3: " << DeltaPhi3 << endl;
    std::cout << "DeltaPhi4: " << DeltaPhi4 << endl;
    */

    histo->Fill(0);
    if( ntuple->nvLeptons == 0 ) histo->Fill(1);
    else return false;
    if( NJets>=4 ) histo->Fill(2);
    else return false;
    if( HT>500. ) histo->Fill(3);
    else return false;
    if( MHT>200. ) histo->Fill(4); 
    else return false;
    if( DeltaPhi1>0.5 ) histo->Fill(5);
    else return false;
    if( DeltaPhi2>0.5 ) histo->Fill(6);
    else return false;
    if( DeltaPhi3>0.3 ) histo->Fill(7);
    else return false;
    if( DeltaPhi4>0.3 ) histo->Fill(8);
    else return false;

    return true;

  };

  void postProcess( ) override {
    histo->Write();
  }

};

#endif
