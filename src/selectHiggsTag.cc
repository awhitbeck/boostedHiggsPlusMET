#ifndef SELECTHIGGSTAG
#define SELECTHIGGSTAG

#include "processor.h"

#include "TString.h"
#include "TChain.h"
#include "TFile.h"

#include <cstdio>
#include <string>
#include <iostream>

using namespace std; 

/* 
   selector to cut on the number of higgs tags
*/

template <class TreeType> class selectHiggsTag : public processor<TreeType> {

public :

  TH1F* histo;
  TH1F *matched_bbtag,*fake_0bHadrons_bbtag,*fake_1bHadrons_bbtag,*fake_2bHadrons_bbtag;
  TreeType* ntuple;
  TString label,weight;
  int maxTags, minTags;

  selectHiggsTag( TreeType* ntuple_ , int minTags_ , int maxTags_ , TString label_ , TString weight_ = "weight")
    : processor<TreeType>("selectHiggsTag"+label_)
  {
    ntuple = ntuple_ ; 
    maxTags = maxTags_ ; 
    minTags = minTags_ ; 
    label = label_ ;
    weight = weight_;

    histo = new TH1F("selectHiggsTag_"+label,"selectHiggsTag_"+label,4,0.5,4.5);
    matched_bbtag = new TH1F("matched_bbtag_"+label,"matched_bbtag_"+label,100,-1,1);
    fake_0bHadrons_bbtag = new TH1F("fake_0bHadrons_bbtag_"+label,"fake_0bHadrons_bbtag_"+label,100,-1,1);
    fake_1bHadrons_bbtag = new TH1F("fake_1bHadrons_bbtag_"+label,"fake_1bHadrons_bbtag_"+label,100,-1,1);
    fake_2bHadrons_bbtag = new TH1F("fake_2bHadrons_bbtag_"+label,"fake_2bHadrons_bbtag_"+label,100,-1,1);

    ntuple->fChain->SetBranchStatus("nFatjetAK08ungroomed",1);
    ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_pt",1);
    ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_eta",1);
    ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_phi",1);
    ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_mass",1);
    ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_mpruned",1);
    ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_tau2",1);
    ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_tau1",1);
    ntuple->fChain->SetBranchStatus("FatjetAK08ungroomed_bbtag",1);
    ntuple->fChain->SetBranchStatus("nGenJet",1);
    ntuple->fChain->SetBranchStatus("GenJet_pt",1);
    ntuple->fChain->SetBranchStatus("GenJet_eta",1);
    ntuple->fChain->SetBranchStatus("GenJet_phi",1);
    ntuple->fChain->SetBranchStatus("GenJet_mass",1);
    ntuple->fChain->SetBranchStatus("GenJet_numBHadrons",1);
    ntuple->fChain->SetBranchStatus("nGenHiggsBoson",1);
    ntuple->fChain->SetBranchStatus("GenHiggsBoson_pt",1);
    ntuple->fChain->SetBranchStatus("GenHiggsBoson_eta",1);
    ntuple->fChain->SetBranchStatus("GenHiggsBoson_phi",1);
    ntuple->fChain->SetBranchStatus("GenHiggsBoson_mass",1);

  };

  ~selectHiggsTag(){
    delete histo;
  };

  bool process() override {
    
    int nHiggsTags = 0 ;
    
    for( int iJet = 0 ; iJet < ntuple->nFatjetAK08ungroomed ; iJet++ ){
      histo->Fill(0);
      
      if( ntuple->FatjetAK08ungroomed_pt[iJet] < 200. ) continue;
      histo->Fill(1);
      if( ntuple->FatjetAK08ungroomed_mpruned[iJet] < 90 || 
	  ntuple->FatjetAK08ungroomed_mpruned[iJet] > 130 ) continue;
      histo->Fill(2);
      if( ntuple->FatjetAK08ungroomed_tau2[iJet]/ntuple->FatjetAK08ungroomed_tau1[iJet] > 1.0 )  continue;
      histo->Fill(3);
      
      // ------------------------------------------------------------------------------
      // ------------------------------- GEN MATCHING ---------------------------------
      // ------------------------------------------------------------------------------
      TLorentzVector fatJet(ntuple->FatjetAK08ungroomed_pt[iJet],ntuple->FatjetAK08ungroomed_eta[iJet],ntuple->FatjetAK08ungroomed_phi[iJet],ntuple->FatjetAK08ungroomed_mass[iJet]);
      int nBhadrons=0;
      bool matched=false;
      for( int iGenJet = 0 ; iGenJet < ntuple->nGenJet ; iGenJet++ ){
	TLorentzVector genJet(ntuple->GenJet_pt[iGenJet],ntuple->GenJet_eta[iGenJet],ntuple->GenJet_phi[iGenJet],ntuple->GenJet_mass[iGenJet]);
	if(fatJet.DeltaR(genJet)<0.4)
	  nBhadrons+=ntuple->GenJet_numBHadrons[iGenJet];
      }
      for( int iHiggs = 0 ; iHiggs < ntuple->nGenHiggsBoson ; iHiggs++ ){
	TLorentzVector genHiggs(ntuple->GenHiggsBoson_pt[iHiggs],ntuple->GenHiggsBoson_eta[iHiggs],ntuple->GenHiggsBoson_phi[iHiggs],ntuple->GenHiggsBoson_mass[iHiggs]);
	if(fatJet.DeltaR(genHiggs)<0.4)
	  matched=true;
      }
      if(matched)
	matched_bbtag->Fill( ntuple->FatjetAK08ungroomed_bbtag[iJet] , ntuple->fChain->GetLeaf( weight.Data() )->GetValue() );
      else{
	if( nBhadrons==0 )
	  fake_0bHadrons_bbtag->Fill( ntuple->FatjetAK08ungroomed_bbtag[iJet] , ntuple->fChain->GetLeaf( weight.Data() )->GetValue() );
	if( nBhadrons==1 )
	  fake_1bHadrons_bbtag->Fill( ntuple->FatjetAK08ungroomed_bbtag[iJet] , ntuple->fChain->GetLeaf( weight.Data() )->GetValue() );
	if( nBhadrons>=2 )
	  fake_2bHadrons_bbtag->Fill( ntuple->FatjetAK08ungroomed_bbtag[iJet] , ntuple->fChain->GetLeaf( weight.Data() )->GetValue() );
      }
      // ----------------------------- END GEN MATCHING -------------------------------
      // ------------------------------------------------------------------------------

      if( ntuple->FatjetAK08ungroomed_bbtag[iJet] < -0.5 ) continue;
      histo->Fill(4);
      nHiggsTags++;

    }

    return (nHiggsTags <= maxTags) && (nHiggsTags >= minTags) ; 

  };

  void postProcess() override {
    histo->Write();
    matched_bbtag->Write();
    fake_0bHadrons_bbtag->Write();
    fake_1bHadrons_bbtag->Write();
    fake_2bHadrons_bbtag->Write();
  }

};

#endif
