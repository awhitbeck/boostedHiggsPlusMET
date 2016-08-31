#include "TLorentzVector.h"

// constants
// ==============================================
double bbtagCut = 0.3;
// ==============================================

double CalcdPhi( double phi1 , double phi2 ){

  double dPhi = phi1-phi2;
  if( dPhi < -TMath::Pi() ) 
    dPhi += 2*TMath::Pi() ;
  if( dPhi > TMath::Pi() )
    dPhi -= 2*TMath::Pi() ;
  return fabs(dPhi);

}

//////////////////////
//////////////////////
//////////////////////
// Lepton functions //
//////////////////////
//////////////////////
//////////////////////


/////////////////////
// Gen Lepton Info //
/////////////////////

template<typename ntupleType> bool SingleGenMuon(ntupleType* ntuple){
  int genMuons = 0 ;
  int genElectrons = 0 ;

  for( int iLep = 0 ; iLep < ntuple->nGenLep ; iLep++ ){
    if( abs(ntuple->GenLep_pdgId[iLep]) == 13 )
      genMuons++;
    if( abs(ntuple->GenLep_pdgId[iLep]) == 11 )
      genElectrons++;
  }

  return genMuons==1 && genElectrons==0 ; 

}

template<typename ntupleType> bool SingleMuonAccept(ntupleType* ntuple){
  int genMuons = 0 ;

  for( int iLep = 0 ; iLep < ntuple->nGenLep ; iLep++ ){
    if( abs(ntuple->GenLep_pdgId[iLep]) == 13 && ntuple->GenLep_pt[iLep]>10. && fabs(ntuple->GenLep_eta[iLep])<2.4 )
      genMuons++;
  }

  return genMuons>0 ;

}

///////////////////////////
// RECO Muon definitions //
///////////////////////////

template<typename ntupleType> int getAMuonIndex(ntupleType* ntuple){
  for( int iLep = 0 ; iLep < ntuple->naLeptons ; iLep++ ){
    if( ntuple->aLeptons_pt[iLep]>10. && abs(ntuple->aLeptons_eta[iLep])<2.4 && ntuple->aLeptons_mediumMuonId[iLep] == 1 && ntuple->aLeptons_miniRelIso[iLep] < 0.2  ){
      return iLep;
    }
  }
  return -1;
}
template<typename ntupleType> int getVMuonIndex(ntupleType* ntuple){
  for( int iLep = 0 ; iLep < ntuple->nvLeptons ; iLep++ ){
    if( ntuple->vLeptons_pt[iLep]>10. && abs(ntuple->vLeptons_eta[iLep])<2.4 && ntuple->vLeptons_mediumMuonId[iLep] == 1 && ntuple->vLeptons_miniRelIso[iLep] < 0.2  ){
      return iLep;
    }
  }
  return -1;
}

template<typename ntupleType> int numMuons(ntupleType* ntuple){
  int numMuons_ = 0 ;
  for( int iLep = 0 ; iLep < ntuple->nvLeptons ; iLep++ ){
    if( ntuple->vLeptons_pt[iLep]>10. && abs(ntuple->vLeptons_eta[iLep])<2.4 && ntuple->vLeptons_mediumMuonId[iLep] == 1 && ntuple->vLeptons_miniRelIso[iLep] < 0.2  ){
      numMuons_++;
    }
  }
  for( int iLep = 0 ; iLep < ntuple->naLeptons ; iLep++ ){
    if( ntuple->aLeptons_pt[iLep]>10. && abs(ntuple->aLeptons_eta[iLep])<2.4 && ntuple->aLeptons_mediumMuonId[iLep] == 1 && ntuple->aLeptons_miniRelIso[iLep] < 0.2  ){
      numMuons_++;
    }
  }  
  return numMuons_;
}

template<typename ntupleType> double fillNumMuons(ntupleType* ntuple){
  return double(numMuons(ntuple));
}

template<typename ntupleType> int numElectrons(ntupleType* ntuple){
  int numElectrons_ = 0;
  for( int iLep = 0 ; iLep < ntuple->naLeptons ; iLep++ ){
    if( ( ntuple->aLeptons_pt[iLep]>10. && abs(ntuple->aLeptons_eta[iLep])<2.5 && ntuple->aLeptons_miniRelIso[iLep] < 0.1 ) &&
	( ( abs(ntuple->aLeptons_etaSc[iLep]) < 1.479 && ntuple->aLeptons_eleSieie[iLep] < 0.0115 && abs(ntuple->aLeptons_eleDEta[iLep]) < 0.00749 &&
	    abs(ntuple->aLeptons_eleDPhi[iLep]) < 0.228 && ntuple->aLeptons_eleHoE[iLep] < 0.356 && ntuple->aLeptons_eleooEmooP[iLep] < 0.299 && 
	    ntuple->aLeptons_eleExpMissingInnerHits[iLep] <= 2 
	    ) || 
	  ( abs(ntuple->aLeptons_etaSc[iLep]) > 1.479 && ntuple->aLeptons_eleSieie[iLep] < 0.037 && abs(ntuple->aLeptons_eleDEta[iLep]) < 0.00895 && 
	    abs(ntuple->aLeptons_eleDPhi[iLep]) < 0.213 && ntuple->aLeptons_eleHoE[iLep] < 0.211 && ntuple->aLeptons_eleooEmooP[iLep] < 0.15 && 
	    ntuple->aLeptons_eleExpMissingInnerHits[iLep] <= 3 ))){ 
      numElectrons_++;
    }
  }

  for( int iLep = 0 ; iLep < ntuple->nvLeptons ; iLep++ ){
    if( ( ntuple->vLeptons_pt[iLep]>10. && abs(ntuple->vLeptons_eta[iLep])<2.5 && ntuple->vLeptons_miniRelIso[iLep] < 0.1 ) &&
	( ( abs(ntuple->vLeptons_etaSc[iLep]) < 1.479 && ntuple->vLeptons_eleSieie[iLep] < 0.0115 && abs(ntuple->vLeptons_eleDEta[iLep]) < 0.00749 &&
	    abs(ntuple->vLeptons_eleDPhi[iLep]) < 0.228 && ntuple->vLeptons_eleHoE[iLep] < 0.356 && ntuple->vLeptons_eleooEmooP[iLep] < 0.299 && 
	    ntuple->vLeptons_eleExpMissingInnerHits[iLep] <= 2 
	    ) || 
	  ( abs(ntuple->vLeptons_etaSc[iLep]) > 1.479 && ntuple->vLeptons_eleSieie[iLep] < 0.037 && abs(ntuple->vLeptons_eleDEta[iLep]) < 0.00895 && 
	    abs(ntuple->vLeptons_eleDPhi[iLep]) < 0.213 && ntuple->vLeptons_eleHoE[iLep] < 0.211 && ntuple->vLeptons_eleooEmooP[iLep] < 0.15 && 
	    ntuple->vLeptons_eleExpMissingInnerHits[iLep] <= 3 ))){ 
      numElectrons_++;
    }
  }
  return numElectrons_;
}

template<typename ntupleType> double fillLepPt(ntupleType* ntuple){
  int index = getAMuonIndex(ntuple);
  if( index != -1 ) 
    return ntuple->aLeptons_pt[index];
  else{
    index = getVMuonIndex(ntuple);
    if( index != -1 )
      return ntuple->vLeptons_pt[index];
    else
      return -9999.;
  }
}

template<typename ntupleType> double fillLepActivity(ntupleType* ntuple){
  int index = getAMuonIndex(ntuple);
  if( index != -1 ) 
    return ntuple->aLeptons_relIso04[index] - ntuple->aLeptons_miniRelIso[index];
  else{
    index = getVMuonIndex(ntuple);
    if( index != -1 )
      return ntuple->vLeptons_relIso04[index] - ntuple->vLeptons_miniRelIso[index];
    else
      return -9999.;
  }
}

//////////////////////
// END LEPTON STUFF //
//////////////////////


template<typename ntupleType> double fillDeltaPhi1(ntupleType* ntuple){
  int count = 0;
  double dPhi = -9999.;
  for(int iJet = 0 ; iJet < ntuple->nJet ; iJet++ ){
    if( ntuple->Jet_pt[iJet]>30. && fabs(ntuple->Jet_eta[iJet])<2.4 ){
      count++;
      if( count == 1 ){
	return CalcdPhi(ntuple->Jet_phi[iJet],ntuple->met_phi);
      }      
    }
  }
}

template<typename ntupleType> double fillDeltaPhi2(ntupleType* ntuple){
  int count = 0;
  double dPhi = -9999.;
  for(int iJet = 0 ; iJet < ntuple->nJet ; iJet++ ){
    if( ntuple->Jet_pt[iJet]>30. && fabs(ntuple->Jet_eta[iJet])<2.4 ){
      count++;
      if( count == 2 ){
	return CalcdPhi(ntuple->Jet_phi[iJet],ntuple->met_phi);
      } 
    }     
  }
}

template<typename ntupleType> double fillDeltaPhi3(ntupleType* ntuple){
  int count = 0;
  double dPhi = -9999.;
  for(int iJet = 0 ; iJet < ntuple->nJet ; iJet++ ){
    if( ntuple->Jet_pt[iJet]>30. && fabs(ntuple->Jet_eta[iJet])<2.4 ){
      count++;
      if( count == 3 ){
	return CalcdPhi(ntuple->Jet_phi[iJet],ntuple->met_phi);
      }      
    }
  }
}

template<typename ntupleType> double fillDeltaPhi4(ntupleType* ntuple){
  int count = 0;
  double dPhi = -9999.;
  for(int iJet = 0 ; iJet < ntuple->nJet ; iJet++ ){
    if( ntuple->Jet_pt[iJet]>30. && fabs(ntuple->Jet_eta[iJet])<2.4 ){
      count++;
      if( count == 4 ){
	return CalcdPhi(ntuple->Jet_phi[iJet],ntuple->met_phi);
      }      
    }
  }
}

template<typename ntupleType> double fillMHT(ntupleType* ntuple){

  TLorentzVector MHTvec(0.,0.,0.,0.);
  for(int iJet = 0 ; iJet < ntuple->nJet ; iJet++ ){
    if( ntuple->Jet_pt[iJet]>30. && fabs(ntuple->Jet_eta[iJet])<5.0 ){
      TLorentzVector temp;
      temp.SetPtEtaPhiM(ntuple->Jet_pt[iJet],ntuple->Jet_eta[iJet],ntuple->Jet_phi[iJet],ntuple->Jet_mass[iJet]);
      MHTvec-=temp;
    }
  }
  return MHTvec.Pt();
}

template<typename ntupleType> double fillMET(ntupleType* ntuple){
  return ntuple->met_pt;
}

template<typename ntupleType> double fillOne(ntupleType* ntuple){
  return 1.;
}

template<typename ntupleType> double fillNJets(ntupleType* ntuple){
  double NJets = 0.;
  for(int iJet = 0 ; iJet < ntuple->nJet ; iJet++ ){
    if( ntuple->Jet_pt[iJet]>30. && fabs(ntuple->Jet_eta[iJet])<2.4 )
      NJets+=1.;
  }
  return NJets;
}

template<typename ntupleType> double fillBTags(ntupleType* ntuple){
  double BTags = 0.;
  for(int iJet = 0 ; iJet < ntuple->nJet ; iJet++ ){
    if( ntuple->Jet_pt[iJet]>30. && fabs(ntuple->Jet_eta[iJet])<2.4 && ntuple->Jet_btagCSV[iJet]>0.89 )
      BTags+=1.;
  }
  return BTags;
}

template<typename ntupleType> double fillLeadingJetMass(ntupleType* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=0) 
    return -1.;
  else
    return ntuple->FatjetAK08ungroomed_mpruned[0];
}

template<typename ntupleType> double fillLeadingJetFlavor(ntupleType* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=0) 
    return -1.;
  else
    return ntuple->FatjetAK08ungroomed_Flavour[0];
}

template<typename ntupleType> double fillSubLeadingJetFlavor(ntupleType* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    return ntuple->FatjetAK08ungroomed_Flavour[1];
}

template<typename ntupleType> double fillLeadingBBtagJetMass(ntupleType* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    if( ntuple->FatjetAK08ungroomed_bbtag[0] >= ntuple->FatjetAK08ungroomed_bbtag[1] )
      return ntuple->FatjetAK08ungroomed_mpruned[0];
    else
      return ntuple->FatjetAK08ungroomed_mpruned[1];
}

template<typename ntupleType> double fillLeadingBBtagJetPt(ntupleType* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    if( ntuple->FatjetAK08ungroomed_bbtag[0] >= ntuple->FatjetAK08ungroomed_bbtag[1] )
      return ntuple->FatjetAK08ungroomed_pt[0];
    else
      return ntuple->FatjetAK08ungroomed_pt[1];
}

template<typename ntupleType> double fillLeadingBBtagJetBBtag(ntupleType* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    if( ntuple->FatjetAK08ungroomed_bbtag[0] >= ntuple->FatjetAK08ungroomed_bbtag[1] )
      return ntuple->FatjetAK08ungroomed_bbtag[0];
    else
      return ntuple->FatjetAK08ungroomed_bbtag[1];
}

template<typename ntupleType> double fillLeadingBBtagJetTau21(ntupleType* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    if( ntuple->FatjetAK08ungroomed_bbtag[0] >= ntuple->FatjetAK08ungroomed_bbtag[1] )
      return ntuple->FatjetAK08ungroomed_tau2[0]/ntuple->FatjetAK08ungroomed_tau1[0];
    else
      return ntuple->FatjetAK08ungroomed_tau2[1]/ntuple->FatjetAK08ungroomed_tau1[1];
}

// - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - - - - - 
template<typename ntupleType> double fillSubLeadingBBtagJetMass(ntupleType* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    if( ntuple->FatjetAK08ungroomed_bbtag[0] < ntuple->FatjetAK08ungroomed_bbtag[1] )
      return ntuple->FatjetAK08ungroomed_mpruned[0];
    else
      return ntuple->FatjetAK08ungroomed_mpruned[1];
}

template<typename ntupleType> double fillSubLeadingBBtagJetPt(ntupleType* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    if( ntuple->FatjetAK08ungroomed_bbtag[0] < ntuple->FatjetAK08ungroomed_bbtag[1] )
      return ntuple->FatjetAK08ungroomed_pt[0];
    else
      return ntuple->FatjetAK08ungroomed_pt[1];
}

template<typename ntupleType> double fillSubLeadingBBtagJetBBtag(ntupleType* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    if( ntuple->FatjetAK08ungroomed_bbtag[0] < ntuple->FatjetAK08ungroomed_bbtag[1] )
      return ntuple->FatjetAK08ungroomed_bbtag[0];
    else
      return ntuple->FatjetAK08ungroomed_bbtag[1];
}

template<typename ntupleType> double fillSubLeadingBBtagJetTau21(ntupleType* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    if( ntuple->FatjetAK08ungroomed_bbtag[0] < ntuple->FatjetAK08ungroomed_bbtag[1] )
      return ntuple->FatjetAK08ungroomed_tau2[0]/ntuple->FatjetAK08ungroomed_tau1[0];
    else
      return ntuple->FatjetAK08ungroomed_tau2[1]/ntuple->FatjetAK08ungroomed_tau1[1];
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template<typename ntupleType> double fillSubLeadingJetMass(ntupleType* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    return ntuple->FatjetAK08ungroomed_mpruned[1];
}

template<typename ntupleType> double fillLeadingJetPt(ntupleType* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=0) 
    return -1.;
  else
    return ntuple->FatjetAK08ungroomed_pt[0];
}

template<typename ntupleType> double fillSubLeadingJetPt(ntupleType* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    return ntuple->FatjetAK08ungroomed_pt[1];
}

template<typename ntupleType> double fillLeadingBBtag(ntupleType* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=0) 
    return -1.;
  else
    return ntuple->FatjetAK08ungroomed_bbtag[0];
}

template<typename ntupleType> double fillSubLeadingBBtag(ntupleType* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    return ntuple->FatjetAK08ungroomed_bbtag[1];
}

template<typename ntupleType> double fillLeadingTau21(ntupleType* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=0) 
    return -1.;
  else
    return ntuple->FatjetAK08ungroomed_tau2[0]/ntuple->FatjetAK08ungroomed_tau1[0];
}

template<typename ntupleType> double fillSubLeadingTau21(ntupleType* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    return ntuple->FatjetAK08ungroomed_tau2[1]/ntuple->FatjetAK08ungroomed_tau1[1];
}

template<typename ntupleType> double fillHT(ntupleType* ntuple){
  double HT = 0.;
  //cout << "nJets: " << ntuple->nJet << endl;
  for(int iJet = 0 ; iJet < ntuple->nJet ; iJet++ ){
    if( ntuple->Jet_pt[iJet]>30. && fabs(ntuple->Jet_eta[iJet])<2.4 )
      HT+=ntuple->Jet_pt[iJet];
  }
  
  return HT;
}

template<typename ntupleType> double fillSingleJetMass(ntupleType* ntuple){

  const int maxJets=2;
  for( int i = 0 ; i < maxJets ; i++){ 
    if( ntuple->nFatjetAK08ungroomed > i && 
	ntuple->FatjetAK08ungroomed_pt[i] > 300. && 
	ntuple->FatjetAK08ungroomed_mpruned[i] > 85. && 
	ntuple->FatjetAK08ungroomed_mpruned[i] < 135. && 
	ntuple->FatjetAK08ungroomed_bbtag[i] > bbtagCut )
      return ntuple->FatjetAK08ungroomed_mpruned[i];
  }
  return -9999.;
}

template<typename ntupleType> double fillLooseSingleJetMass(ntupleType* ntuple){

  const int maxJets=2;
  for( int i = 0 ; i < maxJets ; i++){ 
    if( ntuple->nFatjetAK08ungroomed > i && 
	ntuple->FatjetAK08ungroomed_pt[i] > 300. && 
	ntuple->FatjetAK08ungroomed_mpruned[i] > 50. && 
	ntuple->FatjetAK08ungroomed_mpruned[i] < 200. )
      return ntuple->FatjetAK08ungroomed_mpruned[i];
  }
  return -9999.;
}

template<typename ntupleType> double fillSingleBBtag(ntupleType* ntuple){

  const int maxJets=2;
  for( int i = 0 ; i < maxJets ; i++){ 
    if( ntuple->nFatjetAK08ungroomed > i && 
	ntuple->FatjetAK08ungroomed_pt[i] > 300. && 
	ntuple->FatjetAK08ungroomed_mpruned[i] > 85. && 
	ntuple->FatjetAK08ungroomed_mpruned[i] < 135. && 
	ntuple->FatjetAK08ungroomed_bbtag[i] > bbtagCut )
      return ntuple->FatjetAK08ungroomed_bbtag[i];
  }
  return -9999.;
}

template<typename ntupleType> double fillSingleTau21(ntupleType* ntuple){

  const int maxJets=2;
  for( int i = 0 ; i < maxJets ; i++){ 
    if( ntuple->nFatjetAK08ungroomed > i && 
	ntuple->FatjetAK08ungroomed_pt[i] > 300. && 
	ntuple->FatjetAK08ungroomed_mpruned[i] > 85. && 
	ntuple->FatjetAK08ungroomed_mpruned[i] < 135. && 
	ntuple->FatjetAK08ungroomed_bbtag[i] > bbtagCut )
      return ntuple->FatjetAK08ungroomed_tau2[i]/ntuple->FatjetAK08ungroomed_tau1[i];
  }
  return -9999.;
}

template<typename ntupleType> double fillSinglePt(ntupleType* ntuple){

  const int maxJets=2;
  for( int i = 0 ; i < maxJets ; i++){ 
    if( ntuple->nFatjetAK08ungroomed > i && 
	ntuple->FatjetAK08ungroomed_pt[i] > 300. && 
	ntuple->FatjetAK08ungroomed_mpruned[i] > 85. && 
	ntuple->FatjetAK08ungroomed_mpruned[i] < 135. && 
	ntuple->FatjetAK08ungroomed_bbtag[i] > bbtagCut )
      return ntuple->FatjetAK08ungroomed_pt[i];
  }
  return -9999.;
}

template<typename ntupleType> double fillLooseSinglePt(ntupleType* ntuple){

  const int maxJets=2;
  for( int i = 0 ; i < maxJets ; i++){ 
    if( ntuple->nFatjetAK08ungroomed > i && 
	ntuple->FatjetAK08ungroomed_pt[i] > 300. && 
	ntuple->FatjetAK08ungroomed_mpruned[i] > 50. && 
	ntuple->FatjetAK08ungroomed_mpruned[i] < 200. )
      return ntuple->FatjetAK08ungroomed_pt[i];
  }
  return -9999.;
}

template<typename ntupleType> double fillAnalysisBins(ntupleType* ntuple){
  double MET = ntuple->met_pt;
  double HT = fillHT(ntuple);

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

  int BTags = int(fillBTags(ntuple));
  int NJets = int(fillNJets(ntuple));

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

template<typename ntupleType> bool ptBinCut(ntupleType* ntuple , int ithBin){
  if( ithBin > 5 ) return false;
  double ptCut[6] = {300.,400.,500.,700.,1000.,999999.};
  double pt = fillLooseSinglePt(ntuple);
  return pt>ptCut[ithBin] && pt<ptCut[ithBin+1];
}
 
template<typename ntupleType> bool RA2bBaselineCut(ntupleType* ntuple){

  double DeltaPhi1 = fillDeltaPhi1(ntuple);
  double DeltaPhi2 = fillDeltaPhi2(ntuple);
  double DeltaPhi3 = fillDeltaPhi3(ntuple);
  double DeltaPhi4 = fillDeltaPhi4(ntuple);
  double HT = fillHT(ntuple);
  double MET = ntuple->met_pt;
  int NJets = int(fillNJets(ntuple));

  //cout << "DeltaPhi1: " << DeltaPhi1 << " DetaPhi2: " << DeltaPhi2 << " DeltaPhi3: " << DeltaPhi3 << " DeltaPhi4: " << DeltaPhi4 << endl;

  return (NJets == 3 && MET > 300. && HT > 300. && DeltaPhi1 > 0.5 && DeltaPhi2 > 0.5 && DeltaPhi3 > 0.3) || (NJets > 3 && MET > 300. && HT > 300. && DeltaPhi1 > 0.5 && DeltaPhi2 > 0.5 && DeltaPhi3 > 0.3 && DeltaPhi4 > 0.3);

}

template<typename ntupleType> bool baselineCut(ntupleType* ntuple){
  double HT = fillHT(ntuple);

  return ( //ntuple->naLeptons == 0            &&
	   ntuple->met_pt > 300.             &&
	   HT > 600.                         &&
	   ntuple->nFatjetAK08ungroomed >= 2 &&
	   ntuple->FatjetAK08ungroomed_pt[0] > 300. && 
	   ntuple->FatjetAK08ungroomed_mpruned[0] > 50. && 
	   ntuple->FatjetAK08ungroomed_mpruned[0] < 200. && 
	   ntuple->FatjetAK08ungroomed_pt[1] > 300. &&
	   ntuple->FatjetAK08ungroomed_mpruned[1] > 50. && 
	   ntuple->FatjetAK08ungroomed_mpruned[1] < 200. );

}

template<typename ntupleType> bool taggingCut(ntupleType* ntuple ){ 
  return ( baselineCut(ntuple) && 
	   ( ntuple->FatjetAK08ungroomed_bbtag[0] > bbtagCut
	     // && ntuple->FatjetAK08ungroomed_mpruned[0] > 85. 
	     // && ntuple->FatjetAK08ungroomed_mpruned[0] < 135. 
	     ) || 
	   ( ntuple->FatjetAK08ungroomed_bbtag[1] > bbtagCut 
	     // && ntuple->FatjetAK08ungroomed_mpruned[1] > 85.
	     // && ntuple->FatjetAK08ungroomed_mpruned[1] < 135. 
	     ));
}

template<typename ntupleType> bool antiTaggingCut(ntupleType* ntuple ){
  return ( baselineCut(ntuple) && 
	   ! ( ( ntuple->FatjetAK08ungroomed_bbtag[0] > bbtagCut
		 // && ntuple->FatjetAK08ungroomed_mpruned[0] > 85.
		 // && ntuple->FatjetAK08ungroomed_mpruned[0] < 135. 
		 ) ||
	       ( ntuple->FatjetAK08ungroomed_bbtag[1] > bbtagCut 
		 // && ntuple->FatjetAK08ungroomed_mpruned[1] > 85.
		 // && ntuple->FatjetAK08ungroomed_mpruned[1] < 135. 
		 ) ) ) ;
}

template<typename ntupleType> bool singleHiggsTagCut(ntupleType* ntuple ){
  double HT = fillHT(ntuple);

  return ( //ntuple->naLeptons == 0            &&
	   ntuple->met_pt > 300.             &&
	   HT > 600.                         &&
	   ntuple->nFatjetAK08ungroomed > 1 &&
	   ntuple->FatjetAK08ungroomed_pt[0] > 300. && 
	   ntuple->FatjetAK08ungroomed_pt[1] > 300. && 
	   ( ntuple->FatjetAK08ungroomed_mpruned[0] > 85. && 
	     ntuple->FatjetAK08ungroomed_mpruned[0] < 135. && 
	     ntuple->FatjetAK08ungroomed_bbtag[0] > bbtagCut ) ||
	   ( ntuple->FatjetAK08ungroomed_mpruned[1] > 85. && 
	     ntuple->FatjetAK08ungroomed_mpruned[1] < 135. && 
	     ntuple->FatjetAK08ungroomed_bbtag[1] > bbtagCut ) );


}

template<typename ntupleType> bool doubleHiggsTagCut(ntupleType* ntuple ){
  double HT = fillHT(ntuple);

  return ( //ntuple->naLeptons == 0            &&
	   ntuple->met_pt > 300.             &&
	   HT > 600.                         &&
	   ntuple->nFatjetAK08ungroomed > 2 &&
	   ntuple->FatjetAK08ungroomed_pt[0] > 300. && 
	   ntuple->FatjetAK08ungroomed_mpruned[0] > 85. && 
	   ntuple->FatjetAK08ungroomed_mpruned[0] < 135. && 
	   ntuple->FatjetAK08ungroomed_bbtag[0] > bbtagCut &&
	   ntuple->FatjetAK08ungroomed_pt[1] > 300. && 
	   ntuple->FatjetAK08ungroomed_mpruned[1] > 85. && 
	   ntuple->FatjetAK08ungroomed_mpruned[1] < 135. && 
	   ntuple->FatjetAK08ungroomed_bbtag[1] > bbtagCut ); 

}
