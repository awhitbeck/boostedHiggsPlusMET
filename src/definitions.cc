#include "TLorentzVector.h"

// constants
// ==============================================
double bbtagCut = 0.3;
TFile* puWeightFile = new TFile("../data/PileupHistograms_0121_69p2mb_pm4p6.root");
TH1F* puWeightHist = (TH1F*) puWeightFile->Get("pu_weights_down");
// ==============================================

double CalcdPhi( double phi1 , double phi2 ){

  double dPhi = phi1-phi2;
  if( dPhi < -TMath::Pi() ) 
    dPhi += 2*TMath::Pi() ;
  if( dPhi > TMath::Pi() )
    dPhi -= 2*TMath::Pi() ;
  return fabs(dPhi);

}


template<typename ntupleType>void ntupleBranchStatus(ntupleType* ntuple){
  ntuple->fChain->SetBranchStatus("*",0);
  ntuple->fChain->SetBranchStatus("Muons",1);
  ntuple->fChain->SetBranchStatus("Electrons",1);
  ntuple->fChain->SetBranchStatus("isoElectronTracksclean",1);
  ntuple->fChain->SetBranchStatus("isoMuonTracksclean",1);
  ntuple->fChain->SetBranchStatus("isoPionTracksclean",1);
  ntuple->fChain->SetBranchStatus("Photon*",1);
  ntuple->fChain->SetBranchStatus("DeltaPhi*",1);

  ntuple->fChain->SetBranchStatus("MHT",1);
  ntuple->fChain->SetBranchStatus("HT",1);
  ntuple->fChain->SetBranchStatus("NJets",1);
  ntuple->fChain->SetBranchStatus("BTags",1);
  ntuple->fChain->SetBranchStatus("MET",1);
  ntuple->fChain->SetBranchStatus("METPhi",1);

  ntuple->fChain->SetBranchStatus("HTclean",1);
  ntuple->fChain->SetBranchStatus("NJetsclean",1);
  ntuple->fChain->SetBranchStatus("BTagsclean",1);
  ntuple->fChain->SetBranchStatus("METclean",1);
  ntuple->fChain->SetBranchStatus("METPhiclean",1);

  ntuple->fChain->SetBranchStatus("JetsAK8*",1);
  ntuple->fChain->SetBranchStatus("Jets*",1);
  ntuple->fChain->SetBranchStatus("Weight",1);  
  ntuple->fChain->SetBranchStatus("puWeightNew",1);  
  ntuple->fChain->SetBranchStatus("TrueNumInteractions",1);  
  ntuple->fChain->SetBranchStatus("TriggerPass",1);  
  ntuple->fChain->SetBranchStatus("HBHENoiseFilter",1);
  ntuple->fChain->SetBranchStatus("HBHEIsoNoiseFilter",1);
  ntuple->fChain->SetBranchStatus("eeBadScFilter",1);
  ntuple->fChain->SetBranchStatus("EcalDeadCellTriggerPrimitiveFilter",1);
  ntuple->fChain->SetBranchStatus("BadPFMuonFilter",1);
  ntuple->fChain->SetBranchStatus("BadChargedCandidateFilter",1);
  ntuple->fChain->SetBranchStatus("CaloMET",1);
  ntuple->fChain->SetBranchStatus("NVtx",1);
  ntuple->fChain->SetBranchStatus("JetID*",1);
  ntuple->fChain->SetBranchStatus("madHT",1);
  ntuple->fChain->SetBranchStatus("NJetsISR",1);
  ntuple->fChain->SetBranchStatus("madMinDeltaRStatus",1);
  ntuple->fChain->SetBranchStatus("madMinPhotonDeltaR",1);

  ntuple->fChain->SetBranchStatus("GenParticles*",1);
}

/***************************************************************/
/* - - - - - - - - - - - - gen-level cuts - - - - - - - - - -  */
/***************************************************************/
template<typename ntupleType> int getNumGenHiggses(ntupleType* ntuple){
    int numHiggses=0;
    for( int i=0 ; i < ntuple->GenParticles->size() ; i++ ){
        if( ntuple->GenParticles_PdgId->at(i) == 25 && 
            ntuple->GenParticles_ParentId->at(i) == 1000023 && 
            ntuple->GenParticles_Status->at(i) == 22 )
            numHiggses++;
    }
    return numHiggses;
}

template<typename ntupleType> int getNumGenZs(ntupleType* ntuple){
    int numZs=0;
    for( int i=0 ; i < ntuple->GenParticles->size() ; i++ ){
        if( ntuple->GenParticles_PdgId->at(i) == 23 && 
            ntuple->GenParticles_ParentId->at(i) == 1000023 && 
            ntuple->GenParticles_Status->at(i) == 22 )
            numZs++;    
    }
    return numZs;
}

template<typename ntupleType> bool genLevelHHcut(ntupleType* ntuple){
    int numHiggses=getNumGenHiggses(ntuple),numZs=getNumGenZs(ntuple);
    if(numHiggses==2 && numZs==0) return true;
    else return false;
}

template<typename ntupleType> bool genLevelZHcut(ntupleType* ntuple){
    int numHiggses=getNumGenHiggses(ntuple),numZs=getNumGenZs(ntuple);
    if(numHiggses==1 && numZs==1) return true;
    else return false;
}

template<typename ntupleType> bool genLevelZZcut(ntupleType* ntuple){
    int numHiggses=getNumGenHiggses(ntuple),numZs=getNumGenZs(ntuple);
    if(numHiggses==0 && numZs==2) return true;
    else return false;
}

/***************************************************************/
/* - - - - - - - - - - - - custom weights - - - - - - - - - -  */
/***************************************************************/
template<typename ntupleType> double customPUweights(ntupleType* ntuple){
    int nVtx = ntuple->TrueNumInteractions;
    return puWeightHist->GetBinContent(puWeightHist->GetXaxis()->FindBin(min(ntuple->TrueNumInteractions,puWeightHist->GetBinLowEdge(puWeightHist->GetNbinsX()+1))));
}

template<typename ntupleType> double ISRweights(ntupleType* ntuple){
    double D = 1.071;
    double w[6]={0.920,0.821,0.715,0.662,0.561,0.511};
    if( ntuple->NJetsISR == 0 )
        return 0.0;
    else if( ntuple->NJetsISR >= 6 )
        return w[5]*D;
    else 
        return w[ntuple->NJetsISR]*D;
}
//////////////////////
//////////////////////
//////////////////////
// Lepton functions //
//////////////////////
//////////////////////
//////////////////////

template<typename ntupleType> double computeMuonMT(ntupleType* ntuple){ 
    if( ntuple->Muons->size() == 0 ) return -9999.;
    double lepPt = ntuple->Muons->at(0).Pt();
    double lepPhi = ntuple->Muons->at(0).Phi(); 
    double MET = ntuple->MET;
    double METPhi = ntuple->METPhi;
    return sqrt( 2*lepPt*MET * ( 1 - cos( METPhi-lepPhi ) ) );
}

template<typename ntupleType> double computeElectronMT(ntupleType* ntuple){ 
    if( ntuple->Electrons->size() == 0 ) return -9999.;
    double lepPt = ntuple->Electrons->at(0).Pt();
    double lepPhi = ntuple->Electrons->at(0).Phi(); 
    double MET = ntuple->MET;
    double METPhi = ntuple->METPhi;
    return sqrt( 2*lepPt*MET * ( 1 - cos( METPhi-lepPhi ) ) );
}



///////////////////////////
// RECO Muon definitions //
///////////////////////////
template<typename ntupleType> int numMuons(ntupleType* ntuple){
  return ntuple->Muons->size();
}

template<typename ntupleType> double muonLeadJetdR(ntupleType* ntuple){
    if( ntuple->Muons->size() == 1 ){
        return ntuple->Muons->at(0).DeltaR(ntuple->JetsAK8->at(0));
    }else 
        return ntuple->Muons->size();
}

template<typename ntupleType> double muonSubleadJetdR(ntupleType* ntuple){
    if( ntuple->Muons->size() == 1 ){
        return ntuple->Muons->at(0).DeltaR(ntuple->JetsAK8->at(1));
    }else 
        return ntuple->Muons->size();
}

template<typename ntupleType> double leadJetMuondR_mass(ntupleType* ntuple){
    if( ntuple->Muons->size() == 1 ){
        if( ntuple->Muons->at(0).DeltaR(ntuple->JetsAK8->at(0)) < ntuple->Muons->at(0).DeltaR(ntuple->JetsAK8->at(1)) )
            return ntuple->JetsAK8_prunedMass->at(1);
        else 
            return ntuple->JetsAK8_prunedMass->at(0);
    }else 
        return ntuple->Muons->size();
}

template<typename ntupleType> double subleadJetMuondR_mass(ntupleType* ntuple){
    if( ntuple->Muons->size() == 1 ){
        if( ntuple->Muons->at(0).DeltaR(ntuple->JetsAK8->at(0)) < ntuple->Muons->at(0).DeltaR(ntuple->JetsAK8->at(1)) )
            return ntuple->JetsAK8_prunedMass->at(0);
        else 
            return ntuple->JetsAK8_prunedMass->at(1);
    }else 
        return ntuple->Muons->size();
}

template<typename ntupleType> double leadJetMuondR_bbdisc(ntupleType* ntuple){
    if( ntuple->Muons->size() == 1 ){
        if( ntuple->Muons->at(0).DeltaR(ntuple->JetsAK8->at(0)) < ntuple->Muons->at(0).DeltaR(ntuple->JetsAK8->at(1)) )
            return ntuple->JetsAK8_doubleBDiscriminator->at(1);
        else 
            return ntuple->JetsAK8_doubleBDiscriminator->at(0);
    }else 
        return ntuple->Muons->size();
}

template<typename ntupleType> double subleadJetMuondR_bbdisc(ntupleType* ntuple){
    if( ntuple->Muons->size() == 1 ){
        if( ntuple->Muons->at(0).DeltaR(ntuple->JetsAK8->at(0)) < ntuple->Muons->at(0).DeltaR(ntuple->JetsAK8->at(1)) )
            return ntuple->JetsAK8_doubleBDiscriminator->at(0);
        else 
            return ntuple->JetsAK8_doubleBDiscriminator->at(1);
    }else 
        return ntuple->Muons->size();
}

template<typename ntupleType> double fillNumMuons(ntupleType* ntuple){
  return double(ntuple->Muons->size());
}


///////////////////////////////////////////////
// - - - - - - - RECO ELECTRONS - - - - - -  //
///////////////////////////////////////////////
template<typename ntupleType> double electronLeadJetdR(ntupleType* ntuple){
    if( ntuple->Electrons->size() == 1 ){
        return ntuple->Electrons->at(0).DeltaR(ntuple->JetsAK8->at(0));
    }else 
        return ntuple->Muons->size();
}

template<typename ntupleType> double electronSubleadJetdR(ntupleType* ntuple){
    if( ntuple->Electrons->size() == 1 ){
        return ntuple->Electrons->at(0).DeltaR(ntuple->JetsAK8->at(1));
    }else 
        return ntuple->Electrons->size();
}


template<typename ntupleType> int numElectrons(ntupleType* ntuple){
  return ntuple->Electrons->size();
}

template<typename ntupleType> double fillLepPt(ntupleType* ntuple){
  if( ntuple->Electrons->size() > 0 && ntuple->Muons->size() == 0 )
      return ntuple->Electrons->at(0).Pt();
  else if( ntuple->Electrons->size() ==0 && ntuple->Muons->size() > 0 )
    return ntuple->Muons->at(0).Pt();
  else
    return -9999.;
}

template<typename ntupleType> double fillLepEta(ntupleType* ntuple){
  if( ntuple->Electrons->size() > 0 && ntuple->Muons->size() == 0 )
      return ntuple->Electrons->at(0).Eta();
  else if( ntuple->Electrons->size() ==0 && ntuple->Muons->size() > 0 )
    return ntuple->Muons->at(0).Eta();
  else
    return -9999.;
}

template<typename ntupleType> double fillLepActivity(ntupleType* ntuple){
  if( ntuple->Electrons->size() > 0 && ntuple->Muons->size() == 0 )
    return ntuple->Electrons_MT2Activity->at(0);
  else if( ntuple->Electrons->size() ==0 && ntuple->Muons->size() > 0 )
    return ntuple->Muons_MT2Activity->at(0);
  else
    return -9999.;
}

//////////////////////
// END LEPTON STUFF //
//////////////////////

////////////////////////////////////////////////////////////
// - - - - - - - - EVENT LEVEL VARIABLES - - - - - - - -  //
////////////////////////////////////////////////////////////
template<typename ntupleType> double fillDeltaPhi1(ntupleType* ntuple){
  return ntuple->DeltaPhi1;
}

template<typename ntupleType> double fillDeltaPhi2(ntupleType* ntuple){
  return ntuple->DeltaPhi2;
}

template<typename ntupleType> double fillDeltaPhi3(ntupleType* ntuple){
  return ntuple->DeltaPhi3;
}

template<typename ntupleType> double fillDeltaPhi4(ntupleType* ntuple){
  return ntuple->DeltaPhi4;
}

template<typename ntupleType> double fillDeltaPhi1clean(ntupleType* ntuple){
  return ntuple->DeltaPhi1clean;
}

template<typename ntupleType> double fillDeltaPhi2clean(ntupleType* ntuple){
  return ntuple->DeltaPhi2clean;
}

template<typename ntupleType> double fillDeltaPhi3clean(ntupleType* ntuple){
  return ntuple->DeltaPhi3clean;
}

template<typename ntupleType> double fillDeltaPhi4clean(ntupleType* ntuple){
  return ntuple->DeltaPhi4clean;
}

template<typename ntupleType> double fillHT(ntupleType* ntuple){
  return ntuple->HT;
}

template<typename ntupleType> double fillHTclean(ntupleType* ntuple){
  return ntuple->HTclean;
}

template<typename ntupleType> double fillMHT(ntupleType* ntuple){
  return ntuple->MHT;
}

template<typename ntupleType> double fillMET(ntupleType* ntuple){
  return ntuple->MET;
}

template<typename ntupleType> double fillMETclean(ntupleType* ntuple){
  return ntuple->METclean;
}

template<typename ntupleType> double fillOne(ntupleType* ntuple){
  return 1.;
}

template<typename ntupleType> double fillNJets(ntupleType* ntuple){
  return ntuple->NJets;
}

template<typename ntupleType> double fillNJetsclean(ntupleType* ntuple){
  return ntuple->NJetsclean;
}

template<typename ntupleType> double fillBTags(ntupleType* ntuple){
  return ntuple->BTags;
}

////////////////////////////////
// HIGHEST PT JET PROPERTIES  //
////////////////////////////////
template<typename ntupleType> double fillLeadingJetMass(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()==0) return-99999.;
  return ntuple->JetsAK8_prunedMass->at(0);
}

template<typename ntupleType> double fillLeadingJetMass_photon(ntupleType* ntuple){
  int numAK8jetsNoPhoton ;
  int leadingJetNoPhoton ;
  int subleadingJetNoPhoton ;
  computeNumAK8jetsNoPhoton(ntuple,numAK8jetsNoPhoton,leadingJetNoPhoton,subleadingJetNoPhoton);
  if( leadingJetNoPhoton == -1 ) return -99999.;
  else
      return ntuple->JetsAK8_prunedMass->at(leadingJetNoPhoton);
}

template<typename ntupleType> double fillLeadingJetFlavor(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()==0) return -99999.;
  if( ntuple->JetsAK8_NumBhadrons->at(0)==2 ) 
    return 21.;
  else if( ntuple->JetsAK8_NumBhadrons->at(0)==1 )
    return 5.;
  else return 1.;
}

template<typename ntupleType> double fillLeadingNbHadrons(ntupleType* ntuple){
    return ntuple->JetsAK8_NumBhadrons->at(0);
}

template<typename ntupleType> double fillLeadingJetPt(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()==0) return-99999.;
  return ntuple->JetsAK8->at(0).Pt();
}

template<typename ntupleType> double fillLeadingBBtag(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()==0) return-99999.;
  return ntuple->JetsAK8_doubleBDiscriminator->at(0);
}

template<typename ntupleType> double fillLeadingBBtag_photon(ntupleType* ntuple){
  int numAK8jetsNoPhoton ;
  int leadingJetNoPhoton ;
  int subleadingJetNoPhoton ;
  computeNumAK8jetsNoPhoton(ntuple,numAK8jetsNoPhoton,leadingJetNoPhoton,subleadingJetNoPhoton);
  if( leadingJetNoPhoton == -1 ) 
      return -99999;
  else 
      return ntuple->JetsAK8_doubleBDiscriminator->at(leadingJetNoPhoton);
}

template<typename ntupleType> double fillLeadingTau21(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()==0) return-99999.;
  return ntuple->JetsAK8_NsubjettinessTau2->at(0)/ntuple->JetsAK8_NsubjettinessTau1->at(0);
}

//////////////////////////////////////////
// SECOND HIGHEST PT AK8 JET PROPERTIES //
//////////////////////////////////////////
template<typename ntupleType> double fillSubLeadingJetMass(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()<=1) return-99999.;
  return ntuple->JetsAK8_prunedMass->at(1);
}

template<typename ntupleType> double fillSubLeadingJetFlavor(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()<=1) return-99999.;
  if( ntuple->JetsAK8_NumBhadrons->at(1)==2 ) 
    return 21.;
  else if (ntuple->JetsAK8_NumBhadrons->at(1)==1 )
    return 5.;
  else return 1.;
}

template<typename ntupleType> double fillSubLeadingNbHadrons(ntupleType* ntuple){
    return ntuple->JetsAK8_NumBhadrons->at(1);
}

template<typename ntupleType> double fillSubLeadingJetPt(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()<=1) return-99999.;
  return ntuple->JetsAK8->at(1).Pt();
}

template<typename ntupleType> double fillSubLeadingBBtag(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()<=1) return-99999.;
  return ntuple->JetsAK8_doubleBDiscriminator->at(1);
}

template<typename ntupleType> double fillSubLeadingBBtag_photon(ntupleType* ntuple){
  int numAK8jetsNoPhoton ;
  int leadingJetNoPhoton ;
  int subleadingJetNoPhoton ;
  computeNumAK8jetsNoPhoton(ntuple,numAK8jetsNoPhoton,leadingJetNoPhoton,subleadingJetNoPhoton);
  if( subleadingJetNoPhoton == -1 ) 
      return -99999.;
  else
      return ntuple->JetsAK8_doubleBDiscriminator->at(subleadingJetNoPhoton);
}

template<typename ntupleType> double fillSubLeadingTau21(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()<=1) return-99999.;
  return ntuple->JetsAK8_NsubjettinessTau2->at(1)/ntuple->JetsAK8_NsubjettinessTau1->at(1);
}

////////////////////////////////////////
// HIGHEST BBtag AK8 JET PROPERTIES  //
//////////////////////////////////////
template<typename ntupleType> double fillLeadingBBtagJetMass(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()==0) return-99999.;
  int index;
  if(ntuple->JetsAK8->size()==1) index = 0;
  else{
    index = int( ntuple->JetsAK8_doubleBDiscriminator->at(0) < ntuple->JetsAK8_doubleBDiscriminator->at(1) );
    return ntuple->JetsAK8_prunedMass->at(index);
  }
}

template<typename ntupleType> double fillLeadingBBtagJetFlavor(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()==0) return-99999.;
  int index;
  if(ntuple->JetsAK8->size()==1) index = 0;
  else{
    index = int( ntuple->JetsAK8_doubleBDiscriminator->at(0) < ntuple->JetsAK8_doubleBDiscriminator->at(1) );
    if( ntuple->JetsAK8_NumBhadrons->at(index)==2 ) 
      return 21.;
    else if( ntuple->JetsAK8_NumBhadrons->at(index)==1 )
      return 5.;
    else return 1.;
  }
}

template<typename ntupleType> double fillLeadingBBtagJetPt(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()==0) return-99999.;
  int index;
  if(ntuple->JetsAK8->size()==1) index = 0;
  else{
    index = int( ntuple->JetsAK8_doubleBDiscriminator->at(0) < ntuple->JetsAK8_doubleBDiscriminator->at(1) );
    return ntuple->JetsAK8->at(index).Pt();
  }
}
template<typename ntupleType> double fillLeadingBBtagJetBBtag(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()==0) return-99999.;
  int index;
  if(ntuple->JetsAK8->size()==1) index = 0;
  else{
    index = int( ntuple->JetsAK8_doubleBDiscriminator->at(0) < ntuple->JetsAK8_doubleBDiscriminator->at(1) );
    return ntuple->JetsAK8_doubleBDiscriminator->at(index);
  }
}

template<typename ntupleType> double fillLeadingBBtagJetTau21(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()==0) return-99999.;
  int index;
  if(ntuple->JetsAK8->size()==1) index = 0;
  else{
    index = int( ntuple->JetsAK8_doubleBDiscriminator->at(0) < ntuple->JetsAK8_doubleBDiscriminator->at(1) );
    return ntuple->JetsAK8_NsubjettinessTau2->at(index)/ntuple->JetsAK8_NsubjettinessTau1->at(index);
  }
}

/////////////////////////////////////////////
// SECOND HIGHEST BBtag AK8 JET PROPERTIES //
/////////////////////////////////////////////
template<typename ntupleType> double fillSubLeadingBBtagJetMass(ntupleType* ntuple){
  int index = int( ntuple->JetsAK8_doubleBDiscriminator->at(0) > ntuple->JetsAK8_doubleBDiscriminator->at(1) );
  return ntuple->JetsAK8_prunedMass->at(index);
}

template<typename ntupleType> double fillSubLeadingBBtagJetFlavor(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()==0) return-99999.;
  int index;
  if(ntuple->JetsAK8->size()==1) index = 0;
  else{
    index = int( ntuple->JetsAK8_doubleBDiscriminator->at(0) > ntuple->JetsAK8_doubleBDiscriminator->at(1) );
    if( ntuple->JetsAK8_NumBhadrons->at(index)==2 ) 
      return 21.;
    else if (ntuple->JetsAK8_NumBhadrons->at(index)==1 )
      return 5.;
    else return 1.;
  }
}

template<typename ntupleType> double fillSubLeadingBBtagJetPt(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()==0) return-99999.;
  int index;
  if(ntuple->JetsAK8->size()==1) index = 0;
  else{
    index = int( ntuple->JetsAK8_doubleBDiscriminator->at(0) > ntuple->JetsAK8_doubleBDiscriminator->at(1) );
    return ntuple->JetsAK8->at(index).Pt();
  }
}

template<typename ntupleType> double fillSubLeadingBBtagJetBBtag(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()==0) return-99999.;
  int index;
  if(ntuple->JetsAK8->size()==1) index = 0;
  else{
    index = int( ntuple->JetsAK8_doubleBDiscriminator->at(0) > ntuple->JetsAK8_doubleBDiscriminator->at(1) );
    return ntuple->JetsAK8_doubleBDiscriminator->at(index);
  }
}

template<typename ntupleType> double fillSubLeadingBBtagJetTau21(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()==0) return-99999.;
  int index;
  if(ntuple->JetsAK8->size()==1) index = 0;
  else{
    index = int( ntuple->JetsAK8_doubleBDiscriminator->at(0) > ntuple->JetsAK8_doubleBDiscriminator->at(1) );
    return ntuple->JetsAK8_NsubjettinessTau2->at(index)/ntuple->JetsAK8_NsubjettinessTau1->at(index);
  }
}

  /////////////////
 // OTHER STUFF //
/////////////////
template<typename ntupleType> double fillAnalysisBins(ntupleType* ntuple){
  double MET = ntuple->MET;
  double HT = ntuple->HT;

  if( MET > 300. && MET < 600. ){
    if( HT > 300. && HT < 1000. ){
      return 1.;
    }else if( HT > 1000. && HT < 2000. ){
      return 2.;
    }else if( HT > 2000. ){
      return 3.;
    }else 
      return -1.;
  }else if( MET > 600. && MET < 1000. ){
    if( HT > 600. && HT < 1000. ){
      return 4.;
    }else if( HT > 1000. && HT < 2000. ){
      return 5.;
    }else if( HT > 2000. ){
      return 6.;
    }else 
      return -1.;
  }else if( MET > 1000. ){
    if( HT > 1000. && HT < 2000. ){
      return 7.;
    }else if( HT > 2000. ){
      return 8.;
    }else 
      return -1.;
  }else 
    return -1.;
}

template<typename ntupleType> double fillRA2b10Bins(ntupleType* ntuple){
  double MET = ntuple->met_pt;
  double HT = fillHT(ntuple);

  if( MET > 300. && MET < 350. ){
    if( HT > 300. && HT < 500. ){
      return 1.;
    }else if( HT > 500. && HT < 1000. ){
      return 2.;
    }else if( HT > 1000. ){
      return 3.;
    }else 
      return -1.;
  }else if( MET > 350. && MET < 500. ){
    if( HT > 350. && HT < 500. ){
      return 4.;
    }else if( HT > 500. && HT < 1000. ){
      return 5.;
    }else if( HT > 1000. ){
      return 6.;
    }else 
      return -1.;
  }else if( MET > 500. && MET < 750. ){
    if( HT > 500. && HT < 1000. ){
      return 7.;
    }else if( HT > 1000. ){
      return 8.;
    }else 
      return -1.;
  }else if( MET > 750. ){
    if( HT > 750. && HT < 1500. ){
      return 9.;
    }else if( HT > 1500. ){
      return 10.;
    }else
      return -1.;
  }else 
    return -1.;
}

template<typename ntupleType> double fillRA2b160Bins( ntupleType* ntuple ){

  int BTags = int(ntuple->BTags);
  int NJets = int(ntuple->NJets);

  if( NJets >= 3 && NJets <=4 ){
    if( BTags == 0 ) 
      return fillRA2b10Bins(ntuple);
    else if( BTags == 1 )
      return 10.+fillRA2b10Bins(ntuple);
    else if( BTags == 2 )
      return 20.+fillRA2b10Bins(ntuple);
    else if( BTags >= 3 )
      return 30.+fillRA2b10Bins(ntuple);
  }else if( NJets >= 5 && NJets <= 6 ){
        if( BTags == 0 ) 
      return 40.+fillRA2b10Bins(ntuple);
    else if( BTags == 1 )
      return 50.+fillRA2b10Bins(ntuple);
    else if( BTags == 2 )
      return 60.+fillRA2b10Bins(ntuple);
    else if( BTags >= 3 )
      return 70.+fillRA2b10Bins(ntuple);
  }else if( NJets >= 7 && NJets <= 8 ){
        if( BTags == 0 ) 
      return 80.+fillRA2b10Bins(ntuple);
    else if( BTags == 1 )
      return 90.+fillRA2b10Bins(ntuple);
    else if( BTags == 2 )
      return 100.+fillRA2b10Bins(ntuple);
    else if( BTags >= 3 )
      return 110.+fillRA2b10Bins(ntuple);
  }else if( NJets >= 9 ){
        if( BTags == 0 ) 
      return 120.+fillRA2b10Bins(ntuple);
    else if( BTags == 1 )
      return 130.+fillRA2b10Bins(ntuple);
    else if( BTags == 2 )
      return 140.+fillRA2b10Bins(ntuple);
    else if( BTags >= 3 )
      return 150.+fillRA2b10Bins(ntuple);
  }else 
    return -1.;  
}

template<typename ntupleType> bool ptBinCut(double pt , int ithBin){
  if( ithBin > 5 ) return false;
  double ptCut[6] = {300.,400.,500.,700.,1000.,999999.};
  return pt>ptCut[ithBin] && pt<ptCut[ithBin+1];
}
 
template<typename ntupleType> bool RA2bBaselineCut(ntupleType* ntuple){

  double DeltaPhi1 = ntuple->DeltaPhi1;
  double DeltaPhi2 = ntuple->DeltaPhi2;
  double DeltaPhi3 = ntuple->DeltaPhi3;
  double DeltaPhi4 = ntuple->DeltaPhi4;
  double HT = ntuple->HT;
  double MET = ntuple->MET;
  int NJets = ntuple->NJets;

  return (NJets == 3 && MET > 300. && HT > 300. && DeltaPhi1 > 0.5 && DeltaPhi2 > 0.5 && DeltaPhi3 > 0.3) || (NJets > 3 && MET > 300. && HT > 300. && DeltaPhi1 > 0.5 && DeltaPhi2 > 0.5 && DeltaPhi3 > 0.3 && DeltaPhi4 > 0.3);
}

template<typename ntupleType> bool FiltersCut(ntupleType* ntuple){
    return ntuple->HBHENoiseFilter==1 && 
           ntuple->HBHEIsoNoiseFilter==1 && 
           ntuple->eeBadScFilter==1 && 
           ntuple->EcalDeadCellTriggerPrimitiveFilter == 1 && 
           ntuple->NVtx>0 && 
           ntuple->MET/ntuple->CaloMET < 5. &&
           ntuple->BadPFMuonFilter == 1 &&
           ntuple->BadChargedCandidateFilter == 1 && 
           ntuple->JetID == 1;
}

template<typename ntupleType> bool AK8MultCut(ntupleType* ntuple){
  return ntuple->JetsAK8->size()>1 ; 
}

template<typename ntupleType> bool BTagsCut(ntupleType* ntuple){
  return ntuple->BTags>0 ; 
}

template<typename ntupleType> bool DeltaPhi1Cut(ntupleType* ntuple){
  return ntuple->DeltaPhi1>0.5;
}

template<typename ntupleType> bool DeltaPhi2Cut(ntupleType* ntuple){
  return ntuple->DeltaPhi2>0.5;
}

template<typename ntupleType> bool DeltaPhi3Cut(ntupleType* ntuple){
  return ntuple->DeltaPhi3>0.3;
}

template<typename ntupleType> bool DeltaPhi4Cut(ntupleType* ntuple){
  return ntuple->DeltaPhi4>0.3;
}

template<typename ntupleType> bool METHTCut(ntupleType* ntuple){
  return ( ntuple->MET > 300. && ntuple->HT > 600. );
}

template<typename ntupleType> bool AK8JetPtCut(ntupleType* ntuple){
  return ( ntuple->JetsAK8->size() >= 2 &&
           ntuple->JetsAK8->at(0).Pt() > 300. &&
	   ntuple->JetsAK8->at(1).Pt() > 300. );
}

template<typename ntupleType> bool AK8JetLooseMassCut(ntupleType* ntuple){
  return ( ntuple->JetsAK8_prunedMass->at(0) > 50. &&
	   ntuple->JetsAK8_prunedMass->at(0) < 250. &&
           ntuple->JetsAK8_prunedMass->at(1) > 50. &&
	   ntuple->JetsAK8_prunedMass->at(1) < 250. );	   
}


template<typename ntupleType> bool baselineCut(ntupleType* ntuple){
 
  return ( ntuple->MET > 300.             &&
           ntuple->HT > 600.                         &&
           ntuple->JetsAK8->size() >= 2 &&
           ntuple->JetsAK8->at(0).Pt() > 300. && 
           ntuple->JetsAK8_prunedMass->at(0) > 50. && 
           ntuple->JetsAK8_prunedMass->at(0) < 250. && 
           ntuple->JetsAK8->at(1).Pt() > 300. &&
           ntuple->JetsAK8_prunedMass->at(1) > 50. && 
           ntuple->JetsAK8_prunedMass->at(1) < 250.&&
           ntuple->DeltaPhi1>0.5 && 
           ntuple->DeltaPhi2>0.5 &&
           ntuple->DeltaPhi3>0.3 && 
           ntuple->DeltaPhi4>0.3 &&
/*
           ntuple->HBHENoiseFilter==1 && 
           ntuple->HBHEIsoNoiseFilter==1 && 
           ntuple->eeBadScFilter==1 && 
           ntuple->EcalDeadCellTriggerPrimitiveFilter == 1 && 
           ntuple->NVtx>0 && 
*/
	   FiltersCut(ntuple) &&
           ntuple->JetID == 1);

}

template<typename ntupleType> bool singleMuBaselineCut(ntupleType* ntuple){

    if( ntuple->Muons->size() != 1 || ntuple->Electrons->size() != 0 ) return false;
    double MT = computeMuonMT(ntuple);

    return ( ntuple->Muons->at(0).Pt()>25. &&
             MT < 100. &&
             ntuple->MET > 100.             &&
             ntuple->HT > 600.                         &&
             ntuple->JetsAK8->size() >= 2 &&
             //muonLeadJetdR(ntuple) > 1.0 &&
             //muonSubleadJetdR(ntuple) > 1.0 &&
             ntuple->JetsAK8->at(0).Pt() > 300. && 
             ntuple->JetsAK8_prunedMass->at(0) > 50. && 
             ntuple->JetsAK8_prunedMass->at(0) < 250. && 
             ntuple->JetsAK8->at(1).Pt() > 300. &&
             ntuple->JetsAK8_prunedMass->at(1) > 50. && 
             ntuple->JetsAK8_prunedMass->at(1) < 250.&&
             ntuple->DeltaPhi1>0.5 && 
             ntuple->DeltaPhi2>0.5 &&
             ntuple->DeltaPhi3>0.3 && 
             ntuple->DeltaPhi4>0.3 &&
	     /*
             ntuple->HBHENoiseFilter==1 && 
             ntuple->HBHEIsoNoiseFilter==1 && 
             ntuple->eeBadScFilter==1 && 
             ntuple->EcalDeadCellTriggerPrimitiveFilter == 1 && 
             ntuple->NVtx>0 && 
	     */
	      FiltersCut(ntuple) &&
             ntuple->JetID == 1);
    
}

template<typename ntupleType> bool singleEleBaselineCut(ntupleType* ntuple){

    if( ntuple->Muons->size() != 0 || ntuple->Electrons->size() != 1 ) return false;
    double MT = computeElectronMT(ntuple);

    return ( ntuple->Electrons->at(0).Pt()>25. && 
             MT < 100. &&
             ntuple->MET > 100.             &&
             ntuple->HT > 600.                         &&
             ntuple->JetsAK8->size() >= 2 &&
             ntuple->JetsAK8->at(0).Pt() > 300. && 
             ntuple->JetsAK8_prunedMass->at(0) > 50. && 
             ntuple->JetsAK8_prunedMass->at(0) < 250. && 
             ntuple->JetsAK8->at(1).Pt() > 300. &&
             ntuple->JetsAK8_prunedMass->at(1) > 50. && 
             ntuple->JetsAK8_prunedMass->at(1) < 250.&&
             ntuple->DeltaPhi1>0.5 && 
             ntuple->DeltaPhi2>0.5 &&
             ntuple->DeltaPhi3>0.3 && 
             ntuple->DeltaPhi4>0.3 &&
	     /* 
            ntuple->HBHENoiseFilter==1 && 
             ntuple->HBHEIsoNoiseFilter==1 && 
             ntuple->eeBadScFilter==1 && 
             ntuple->EcalDeadCellTriggerPrimitiveFilter == 1 && 
             ntuple->NVtx>0 && 
	     */
             FiltersCut(ntuple) &&
             ntuple->JetID == 1);
    
}

template<typename ntupleType> bool lowDphiBaselineCut(ntupleType* ntuple){
 
  return ( ntuple->MET > 300.             &&
           ntuple->HT > 600.                         &&
           ntuple->JetsAK8->size() >= 2 &&
           ntuple->JetsAK8->at(0).Pt() > 300. && 
           ntuple->JetsAK8_prunedMass->at(0) > 50. && 
           ntuple->JetsAK8_prunedMass->at(0) < 250. && 
           ntuple->JetsAK8->at(1).Pt() > 300. &&
           ntuple->JetsAK8_prunedMass->at(1) > 50. && 
           ntuple->JetsAK8_prunedMass->at(1) < 250.&&
           ( ntuple->DeltaPhi1<0.5 || 
             ntuple->DeltaPhi2<0.5 ||
             ntuple->DeltaPhi3<0.3 || 
             ntuple->DeltaPhi4<0.3 ) &&
	   /*
           ntuple->HBHENoiseFilter==1 && 
           ntuple->HBHEIsoNoiseFilter==1 && 
           ntuple->eeBadScFilter==1 && 
           ntuple->EcalDeadCellTriggerPrimitiveFilter == 1 && 
           ntuple->NVtx>0 && 
	   */ 
	    FiltersCut(ntuple) &&
           ntuple->JetID == 1);
}

template<typename ntupleType> void computeNumAK8jetsNoPhoton(ntupleType* ntuple, int &nJets, int &leadIndex, int &subleadIndex){

    TLorentzVector photon = ntuple->Photons->at(0);
    subleadIndex = -1;
    leadIndex = -1;
    nJets = 0;
    for( int iJet = 0 ; iJet < ntuple->JetsAK8->size() ; iJet++ ){
        if( ntuple->JetsAK8->at(iJet).DeltaR(photon) > 0.8 ){ 
            nJets++;
            if( nJets == 1 ) 
                leadIndex = iJet;
            if( nJets == 2 )
                subleadIndex = iJet;
        }
    }
}

template<typename ntupleType> bool photonBaselineCut(ntupleType* ntuple){

    return ( ntuple->Photons->size()==1 &&
             ntuple->Photons->at(0).Pt() > 200. && 
             ntuple->Photons_fullID->size() == 1 && 
             ntuple->Photons_fullID->at(0) == 1 &&
             ntuple->METclean > 200.             &&
             ntuple->HTclean > 600.                         &&
             ntuple->JetsAK8Clean->size()>=2 && 
             ntuple->JetsAK8Clean->at(0).Pt() > 300. && 
             ntuple->JetsAK8Clean_prunedMass->at(0) > 50. && 
             ntuple->JetsAK8Clean_prunedMass->at(0) < 250. && 
             ntuple->JetsAK8Clean->at(1).Pt() > 300. &&
             ntuple->JetsAK8Clean_prunedMass->at(1) > 50. && 
             ntuple->JetsAK8Clean_prunedMass->at(1) < 250.&&
             ntuple->DeltaPhi1clean>0.5 && 
             ntuple->DeltaPhi2clean>0.5 &&
             ntuple->DeltaPhi3clean>0.3 && 
             ntuple->DeltaPhi4clean>0.3 &&
             ntuple->isoElectronTracksclean==0 &&
             ntuple->isoMuonTracksclean == 0 && 
             ntuple->isoPionTracksclean == 0 &&
             ntuple->Electrons->size() == 0 &&
             ntuple->Muons->size() == 0 && 
 	     /*
             ntuple->HBHENoiseFilter==1 && 
             ntuple->HBHEIsoNoiseFilter==1 && 
             ntuple->eeBadScFilter==1 && 
             ntuple->EcalDeadCellTriggerPrimitiveFilter == 1 && 
             ntuple->NVtx>0 && 
	     */
	      FiltersCut(ntuple) &&
             ntuple->JetIDclean == 1);
}

template<typename ntupleType> bool singleHiggsTagLooseCut(ntupleType* ntuple ){ 
  return ( ( ntuple->JetsAK8_doubleBDiscriminator->at(0) > bbtagCut ) 
           && ( ntuple->JetsAK8_doubleBDiscriminator->at(1) < bbtagCut )
           //|| ( ntuple->JetsAK8_doubleBDiscriminator->at(1) > bbtagCut )
           );
}

template<typename ntupleType> bool antiTaggingLooseCut(ntupleType* ntuple ){
    return ( ( ( ntuple->JetsAK8_doubleBDiscriminator->at(0) < bbtagCut
               ) &&
             ( ntuple->JetsAK8_doubleBDiscriminator->at(1) < bbtagCut 
               ) ) ) ;
}

template<typename ntupleType> bool doubleTaggingLooseCut(ntupleType* ntuple ){
    return ( ntuple->JetsAK8_doubleBDiscriminator->at(0) > bbtagCut && 
             ntuple->JetsAK8_doubleBDiscriminator->at(1) > bbtagCut );
}

template<typename ntupleType> bool doubleMassCut(ntupleType* ntuple ){
    return ( ntuple->JetsAK8_prunedMass->at(0) > 85. &&
             ntuple->JetsAK8_prunedMass->at(0) < 135. //&&
             //ntuple->JetsAK8_prunedMass->at(1) > 85. &&
             //ntuple->JetsAK8_prunedMass->at(1) < 135. 
             );
}

template<typename ntupleType> bool singleHiggsTagCut(ntupleType* ntuple ){
  return ( (ntuple->JetsAK8_prunedMass->at(0) > 85. && 
            ntuple->JetsAK8_prunedMass->at(0) < 135. && 
            ntuple->JetsAK8_doubleBDiscriminator->at(0) > bbtagCut ) ||
           (ntuple->JetsAK8_prunedMass->at(1) > 85. && 
            ntuple->JetsAK8_prunedMass->at(1) < 135. && 
            ntuple->JetsAK8_doubleBDiscriminator->at(1) > bbtagCut ) );
}

template<typename ntupleType> bool doubleHiggsTagCut(ntupleType* ntuple ){
  return ( ntuple->JetsAK8_prunedMass->at(0) > 85. && 
           ntuple->JetsAK8_prunedMass->at(0) < 135. && 
           ntuple->JetsAK8_doubleBDiscriminator->at(0) > bbtagCut &&
           ntuple->JetsAK8_prunedMass->at(1) > 85. && 
           ntuple->JetsAK8_prunedMass->at(1) < 135. && 
           ntuple->JetsAK8_doubleBDiscriminator->at(1) > bbtagCut ) ;
}

////////////////////////////////////////////////////////////////////////
// - - - - - - - - - - photon specializations - - - - - - - - - - - - //
////////////////////////////////////////////////////////////////////////
template<typename ntupleType> bool singleHiggsTagLooseCut_photon(ntupleType* ntuple ){ 
    int numAK8jetsNoPhoton ;
    int leadingJetNoPhoton ;
    int subleadingJetNoPhoton ;
    computeNumAK8jetsNoPhoton(ntuple,numAK8jetsNoPhoton,leadingJetNoPhoton,subleadingJetNoPhoton);
  return ( ( ntuple->JetsAK8_doubleBDiscriminator->at(leadingJetNoPhoton) > bbtagCut ) 
           && ( ntuple->JetsAK8_doubleBDiscriminator->at(subleadingJetNoPhoton) < bbtagCut )
           //|| ( ntuple->JetsAK8_doubleBDiscriminator->at(subleadingJetNoPhoton) > bbtagCut )
           );
}

template<typename ntupleType> bool antiTaggingLooseCut_photon(ntupleType* ntuple ){
    int numAK8jetsNoPhoton ;
    int leadingJetNoPhoton ;
    int subleadingJetNoPhoton ;
    computeNumAK8jetsNoPhoton(ntuple,numAK8jetsNoPhoton,leadingJetNoPhoton,subleadingJetNoPhoton);
    return ( ( ( ntuple->JetsAK8_doubleBDiscriminator->at(leadingJetNoPhoton) < bbtagCut
               ) &&
             ( ntuple->JetsAK8_doubleBDiscriminator->at(subleadingJetNoPhoton) < bbtagCut 
               ) ) ) ;
}

template<typename ntupleType> bool doubleTaggingLooseCut_photon(ntupleType* ntuple ){
    int numAK8jetsNoPhoton ;
    int leadingJetNoPhoton ;
    int subleadingJetNoPhoton ;
    computeNumAK8jetsNoPhoton(ntuple,numAK8jetsNoPhoton,leadingJetNoPhoton,subleadingJetNoPhoton);
    return ( ntuple->JetsAK8_doubleBDiscriminator->at(leadingJetNoPhoton) > bbtagCut && 
             ntuple->JetsAK8_doubleBDiscriminator->at(subleadingJetNoPhoton) > bbtagCut );
}

template<typename ntupleType> bool doubleMassCut_photon(ntupleType* ntuple ){
    int numAK8jetsNoPhoton ;
    int leadingJetNoPhoton ;
    int subleadingJetNoPhoton ;
    computeNumAK8jetsNoPhoton(ntuple,numAK8jetsNoPhoton,leadingJetNoPhoton,subleadingJetNoPhoton);
    return ( ntuple->JetsAK8_prunedMass->at(leadingJetNoPhoton) > 85. &&
             ntuple->JetsAK8_prunedMass->at(leadingJetNoPhoton) < 135. &&
             ntuple->JetsAK8_prunedMass->at(subleadingJetNoPhoton) > 85. &&
             ntuple->JetsAK8_prunedMass->at(subleadingJetNoPhoton) < 135. );
}

template<typename ntupleType> bool singleHiggsTagCut_photon(ntupleType* ntuple ){
    int numAK8jetsNoPhoton ;
    int leadingJetNoPhoton ;
    int subleadingJetNoPhoton ;
    computeNumAK8jetsNoPhoton(ntuple,numAK8jetsNoPhoton,leadingJetNoPhoton,subleadingJetNoPhoton);
    return ( (ntuple->JetsAK8_prunedMass->at(leadingJetNoPhoton) > 85. && 
              ntuple->JetsAK8_prunedMass->at(leadingJetNoPhoton) < 135. && 
              ntuple->JetsAK8_doubleBDiscriminator->at(leadingJetNoPhoton) > bbtagCut ) ||
             (ntuple->JetsAK8_prunedMass->at(subleadingJetNoPhoton) > 85. && 
              ntuple->JetsAK8_prunedMass->at(subleadingJetNoPhoton) < 135. && 
              ntuple->JetsAK8_doubleBDiscriminator->at(subleadingJetNoPhoton) > bbtagCut ) );
}

template<typename ntupleType> bool doubleHiggsTagCut_photon(ntupleType* ntuple ){
    int numAK8jetsNoPhoton ;
    int leadingJetNoPhoton ;
    int subleadingJetNoPhoton ;
    computeNumAK8jetsNoPhoton(ntuple,numAK8jetsNoPhoton,leadingJetNoPhoton,subleadingJetNoPhoton);
    return ( ntuple->JetsAK8_prunedMass->at(leadingJetNoPhoton) > 85. && 
             ntuple->JetsAK8_prunedMass->at(leadingJetNoPhoton) < 135. && 
             ntuple->JetsAK8_doubleBDiscriminator->at(leadingJetNoPhoton) > bbtagCut &&
             ntuple->JetsAK8_prunedMass->at(subleadingJetNoPhoton) > 85. && 
             ntuple->JetsAK8_prunedMass->at(subleadingJetNoPhoton) < 135. && 
             ntuple->JetsAK8_doubleBDiscriminator->at(subleadingJetNoPhoton) > bbtagCut ) ;
}
