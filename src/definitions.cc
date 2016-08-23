#include "heppySkimTree.cc"

// constants
// ==============================================
double bbtagCut = 0.3;
// ==============================================

double fillMET(heppySkimTree* ntuple){
  return ntuple->met_pt;
}

double fillOne(heppySkimTree* ntuple){
  return 1.;
}

double fillNJets(heppySkimTree* ntuple){
  double NJets = 0.;
  for(int iJet = 0 ; iJet < ntuple->nJet ; iJet++ ){
    if( ntuple->Jet_pt[iJet]>30. && abs(ntuple->Jet_eta[iJet])<2.4 )
      NJets+=1.;
  }
  return NJets;
}

double fillBTags(heppySkimTree* ntuple){
  double BTags = 0.;
  for(int iJet = 0 ; iJet < ntuple->nJet ; iJet++ ){
    if( ntuple->Jet_pt[iJet]>30. && abs(ntuple->Jet_eta[iJet])<2.4 && ntuple->Jet_btagCSV[iJet]>0.89 )
      BTags+=1.;
  }
  return BTags;
}

double fillLeadingJetMass(heppySkimTree* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=0) 
    return -1.;
  else
    return ntuple->FatjetAK08ungroomed_mpruned[0];
}

double fillLeadingBBtagJetMass(heppySkimTree* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    if( ntuple->FatjetAK08ungroomed_bbtag[0] >= ntuple->FatjetAK08ungroomed_bbtag[1] )
      return ntuple->FatjetAK08ungroomed_mpruned[0];
    else
      return ntuple->FatjetAK08ungroomed_mpruned[1];
}

double fillLeadingBBtagJetPt(heppySkimTree* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    if( ntuple->FatjetAK08ungroomed_bbtag[0] >= ntuple->FatjetAK08ungroomed_bbtag[1] )
      return ntuple->FatjetAK08ungroomed_pt[0];
    else
      return ntuple->FatjetAK08ungroomed_pt[1];
}

double fillLeadingBBtagJetBBtag(heppySkimTree* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    if( ntuple->FatjetAK08ungroomed_bbtag[0] >= ntuple->FatjetAK08ungroomed_bbtag[1] )
      return ntuple->FatjetAK08ungroomed_bbtag[0];
    else
      return ntuple->FatjetAK08ungroomed_bbtag[1];
}

double fillLeadingBBtagJetTau21(heppySkimTree* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    if( ntuple->FatjetAK08ungroomed_bbtag[0] >= ntuple->FatjetAK08ungroomed_bbtag[1] )
      return ntuple->FatjetAK08ungroomed_tau2[0]/ntuple->FatjetAK08ungroomed_tau1[0];
    else
      return ntuple->FatjetAK08ungroomed_tau2[1]/ntuple->FatjetAK08ungroomed_tau1[1];
}

// - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - - - - - 
double fillSubLeadingBBtagJetMass(heppySkimTree* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    if( ntuple->FatjetAK08ungroomed_bbtag[0] < ntuple->FatjetAK08ungroomed_bbtag[1] )
      return ntuple->FatjetAK08ungroomed_mpruned[0];
    else
      return ntuple->FatjetAK08ungroomed_mpruned[1];
}

double fillSubLeadingBBtagJetPt(heppySkimTree* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    if( ntuple->FatjetAK08ungroomed_bbtag[0] < ntuple->FatjetAK08ungroomed_bbtag[1] )
      return ntuple->FatjetAK08ungroomed_pt[0];
    else
      return ntuple->FatjetAK08ungroomed_pt[1];
}

double fillSubLeadingBBtagJetBBtag(heppySkimTree* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    if( ntuple->FatjetAK08ungroomed_bbtag[0] < ntuple->FatjetAK08ungroomed_bbtag[1] )
      return ntuple->FatjetAK08ungroomed_bbtag[0];
    else
      return ntuple->FatjetAK08ungroomed_bbtag[1];
}

double fillSubLeadingBBtagJetTau21(heppySkimTree* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    if( ntuple->FatjetAK08ungroomed_bbtag[0] < ntuple->FatjetAK08ungroomed_bbtag[1] )
      return ntuple->FatjetAK08ungroomed_tau2[0]/ntuple->FatjetAK08ungroomed_tau1[0];
    else
      return ntuple->FatjetAK08ungroomed_tau2[1]/ntuple->FatjetAK08ungroomed_tau1[1];
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
double fillSubLeadingJetMass(heppySkimTree* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    return ntuple->FatjetAK08ungroomed_mpruned[1];
}

double fillLeadingJetPt(heppySkimTree* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=0) 
    return -1.;
  else
    return ntuple->FatjetAK08ungroomed_pt[0];
}

double fillSubLeadingJetPt(heppySkimTree* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    return ntuple->FatjetAK08ungroomed_pt[1];
}

double fillLeadingBBtag(heppySkimTree* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=0) 
    return -1.;
  else
    return ntuple->FatjetAK08ungroomed_bbtag[0];
}

double fillSubLeadingBBtag(heppySkimTree* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    return ntuple->FatjetAK08ungroomed_bbtag[1];
}

double fillLeadingTau21(heppySkimTree* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=0) 
    return -1.;
  else
    return ntuple->FatjetAK08ungroomed_tau2[0]/ntuple->FatjetAK08ungroomed_tau1[0];
}

double fillSubLeadingTau21(heppySkimTree* ntuple){
  if(ntuple->nFatjetAK08ungroomed<=1) 
    return -1.;
  else
    return ntuple->FatjetAK08ungroomed_tau2[1]/ntuple->FatjetAK08ungroomed_tau1[1];
}

double fillHT(heppySkimTree* ntuple){
  double HT = 0.;
  //cout << "nJets: " << ntuple->nJet << endl;
  for(int iJet = 0 ; iJet < ntuple->nJet ; iJet++ ){
    if( ntuple->Jet_pt[iJet]>30. && abs(ntuple->Jet_eta[iJet])<2.4 )
      HT+=ntuple->Jet_pt[iJet];
  }
  
  return HT;
}

double fillSingleJetMass(heppySkimTree* ntuple){

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

double fillLooseSingleJetMass(heppySkimTree* ntuple){

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

double fillSingleBBtag(heppySkimTree* ntuple){

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

double fillSingleTau21(heppySkimTree* ntuple){

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

double fillSinglePt(heppySkimTree* ntuple){

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

double fillLooseSinglePt(heppySkimTree* ntuple){

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

double fillAnalysisBins(heppySkimTree* ntuple){
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

double fillRA2b10Bins(heppySkimTree* ntuple){
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

bool ptBinCut(heppySkimTree* ntuple , int ithBin){
  if( ithBin > 5 ) return false;
  double ptCut[6] = {300.,400.,500.,700.,1000.,999999.};
  double pt = fillLooseSinglePt(ntuple);
  return pt>ptCut[ithBin] && pt<ptCut[ithBin+1];
}
 
bool baselineCut(heppySkimTree* ntuple){
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

bool taggingCut(heppySkimTree* ntuple ){ 
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

bool antiTaggingCut(heppySkimTree* ntuple ){
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

bool singleHiggsTagCut(heppySkimTree* ntuple ){
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

bool doubleHiggsTagCut(heppySkimTree* ntuple ){
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

