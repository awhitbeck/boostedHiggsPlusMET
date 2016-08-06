#ifndef FILLHTAGGINGVARS
#define FILLHTAGGINGVARS

#include "filler.h"
#include <iostream>
#include <string>
#include <cassert>

#include "TLeaf.h"
#include "TString.h"
#include "TLorentzVector.h"

using namespace std;

template <class TreeType> class fillHtaggingVars : public filler<TreeType> {

public : 

  TH1F *histoLeadingPt,*histoSubleadingPt,*histoLeadingPrunedMass,*histoSubleadingPrunedMass,*histoLeadingTau21,*histoSubleadingTau21,*histoLeadingBbDisc,*histoSubleadingBbDisc;
  TreeType* ntuple;
  TString weightbranch;

  fillHtaggingVars()
    : filler<TreeType>("fillHtaggingVars"){
    ntuple = 0;
    histoLeadingPt = 0;
    histoSubleadingPt = 0;
    histoLeadingPrunedMass = 0;
    histoSubleadingPrunedMass = 0;
    histoLeadingTau21 = 0 ;
    histoSubleadingTau21 = 0 ;
    histoLeadingBbDisc = 0 ; 
    histoSubleadingBbDisc = 0 ;
  };
  
  fillHtaggingVars( TreeType* ntuple_ , 
		 TString histotag ,
		 TString weightbranch_ )
    : filler<TreeType>("fillHtaggingVars")
  {

    ntuple = ntuple_;
    weightbranch = weightbranch_;

    histoLeadingPt = new TH1F("histoLeadingPt_"+histotag,"histoLeadingPt_"+histotag,100,0,1000);
    histoSubleadingPt = new TH1F("histoSubleadingPt_"+histotag,"histoSubleadingPt_"+histotag,100,0,1000);
    histoLeadingPrunedMass = new TH1F("histoLeadingPrunedMass_"+histotag,"histoLeadingPrunedMass_"+histotag,100,0.,250.);
    histoSubleadingPrunedMass = new TH1F("histoSubleadingPrunedMass_"+histotag,"histoSubleadingPrunedMass_"+histotag,100,0.,250.);
    histoLeadingTau21 = new TH1F("histoLeadingTau21_"+histotag,"histoLeadingTau21_"+histotag,20,0.,1.);
    histoSubleadingTau21 = new TH1F("histoSubleadingTau21_"+histotag,"histoSubleadingTau21_"+histotag,20,0.,1.);
    histoLeadingBbDisc = new TH1F("histoLeadingBbDisc_"+histotag,"histoLeadingBbDisc_"+histotag,40,-1.,1.);
    histoSubleadingBbDisc = new TH1F("histoSubleadingBbDisc_"+histotag,"histoSubleadingBbDisc_"+histotag,40,-1.,1.);

    if( ntuple->fChain->GetLeaf( weightbranch ) == NULL )
      assert(0);       

  };

  bool process( ) override {

    //cout << "pruned mass : " << ntuple->FatjetAK08ungroomed_mpruned[0] << " " << ntuple->FatjetAK08ungroomed_mpruned[1] << endl;
    //cout << "tau2/tau1 : " << ntuple->FatjetAK08ungroomed_tau2[0]/ntuple->FatjetAK08ungroomed_tau1[0] << " " << ntuple->FatjetAK08ungroomed_tau2[1]/ntuple->FatjetAK08ungroomed_tau1[1] << endl;
    //cout << "bb Disc: " << ntuple->FatjetAK08ungroomed_bbtag[0] << " " << ntuple->FatjetAK08ungroomed_bbtag[1] << endl;

    histoLeadingPt->Fill( ntuple->FatjetAK08ungroomed_pt[0] , ntuple->fChain->GetLeaf( weightbranch.Data() )->GetValue() );
    histoSubleadingPt->Fill( ntuple->FatjetAK08ungroomed_pt[1] , ntuple->fChain->GetLeaf( weightbranch.Data() )->GetValue() );
    histoLeadingPrunedMass->Fill( ntuple->FatjetAK08ungroomed_mpruned[0] , ntuple->fChain->GetLeaf( weightbranch.Data() )->GetValue() );
    histoSubleadingPrunedMass->Fill( ntuple->FatjetAK08ungroomed_mpruned[0] , ntuple->fChain->GetLeaf( weightbranch.Data() )->GetValue() );
    histoLeadingTau21->Fill( ntuple->FatjetAK08ungroomed_tau2[0]/ntuple->FatjetAK08ungroomed_tau1[0] , ntuple->fChain->GetLeaf( weightbranch.Data() )->GetValue() );
    histoSubleadingTau21->Fill( ntuple->FatjetAK08ungroomed_tau2[1]/ntuple->FatjetAK08ungroomed_tau1[1] , ntuple->fChain->GetLeaf( weightbranch.Data() )->GetValue() );
    histoLeadingBbDisc->Fill( ntuple->FatjetAK08ungroomed_bbtag[0] , ntuple->fChain->GetLeaf( weightbranch.Data() )->GetValue() );
    histoSubleadingBbDisc->Fill( ntuple->FatjetAK08ungroomed_bbtag[1] , ntuple->fChain->GetLeaf( weightbranch.Data() )->GetValue() );
    
    return true;

  };

  void postProcess(){
    histoLeadingPt->Write();
    histoSubleadingPt->Write();
    histoLeadingPrunedMass->Write();
    histoSubleadingPrunedMass->Write();
    histoLeadingTau21->Write();
    histoSubleadingTau21->Write();
    histoLeadingBbDisc->Write();
    histoSubleadingBbDisc->Write();
  };

};

#endif
