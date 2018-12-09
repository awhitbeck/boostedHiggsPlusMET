#include "TLorentzVector.h"
#include "TRandom3.h"
#include <iostream>

// constants
// ==============================================
double bbtagCut = 0.3;
TFile* puWeightFile = new TFile("../data/PileupHistograms_0121_69p2mb_pm4p6.root");
TH1F* puWeightHist = (TH1F*) puWeightFile->Get("pu_weights_down");
// - - - - - - weights for WJets, GJets, - - - - - - - - 
// - - - - - - and ZJets NLO Pt distribution - - - - - - 
TFile* NLOWeightFile = new TFile("../data/kfactors.root");
TH1F* GJets_NLO = (TH1F*) NLOWeightFile->Get("GJets_1j_NLO/nominal_G");
TH1F* GJets_LO = (TH1F*) NLOWeightFile->Get("GJets_LO/inv_pt_G");
TH1F* WJets_NLO = (TH1F*) NLOWeightFile->Get("WJets_012j_NLO/nominal");
TH1F* WJets_LO = (TH1F*) NLOWeightFile->Get("WJets_LO/inv_pt");
TH1F* ZJets_NLO = (TH1F*) NLOWeightFile->Get("ZJets_01j_NLO/nominal");
TH1F* ZJets_LO = (TH1F*) NLOWeightFile->Get("ZJets_LO/inv_pt");
// ==============================================

double CalcdPhi( double phi1 , double phi2 ){
  double dPhi = phi1-phi2;
  if( dPhi < -TMath::Pi() ) 
    dPhi += 2*TMath::Pi() ;
  if( dPhi > TMath::Pi() )
    dPhi -= 2*TMath::Pi() ;
  return fabs(dPhi);
  //return dPhi;

}


double CalcDeltaR( double eta1, double phi1 , double eta2, double phi2 ){
    float dEta = (eta1-eta2);
    float dPhi = CalcdPhi(phi1, phi2);
    return sqrt((dEta*dEta) + (dPhi * dPhi));
}

double ZMT(double pt1, double phi1, double pt2, double phi2){
    TLorentzVector v1, v2;
    v1.SetPtEtaPhiM(pt1,0,phi1,0);
    v2.SetPtEtaPhiM(pt2,0,phi2,0);
    return (v1+v2).M();
}

template<typename ntupleType>void ntupleBranchStatus(ntupleType* ntuple){
  ntuple->fChain->SetBranchStatus("*",0);
  ntuple->fChain->SetBranchStatus("Muons",1);
  ntuple->fChain->SetBranchStatus("Electrons",1);
  ntuple->fChain->SetBranchStatus("isoElectronTracksclean",1);
  ntuple->fChain->SetBranchStatus("isoMuonTracksclean",1);
  ntuple->fChain->SetBranchStatus("isoPionTracksclean",1);
  ntuple->fChain->SetBranchStatus("isoElectronTracks",1);
  ntuple->fChain->SetBranchStatus("isoMuonTracks",1);
  ntuple->fChain->SetBranchStatus("isoPionTracks",1);
  ntuple->fChain->SetBranchStatus("Photon*",1);
  ntuple->fChain->SetBranchStatus("DeltaPhi*",1);
  
  ntuple->fChain->SetBranchStatus("TriggerNames",1); 
  ntuple->fChain->SetBranchStatus("TriggerPass",1);
  ntuple->fChain->SetBranchStatus("MHT",1);
  ntuple->fChain->SetBranchStatus("HT",1);
  ntuple->fChain->SetBranchStatus("NJets",1);
  ntuple->fChain->SetBranchStatus("BTags",1);
  ntuple->fChain->SetBranchStatus("MET",1);
  ntuple->fChain->SetBranchStatus("MHT",1);
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
  ntuple->fChain->SetBranchStatus("globalTightHalo2016Filter",1);
  ntuple->fChain->SetBranchStatus("CaloMET",1);
  ntuple->fChain->SetBranchStatus("NVtx",1);
  ntuple->fChain->SetBranchStatus("NumInteractions",1);
  ntuple->fChain->SetBranchStatus("nAllVertices",1);
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

template<typename ntupleType> double FillGenWPt(ntupleType* ntuple){
    //cout << "FillGenWPt:" << endl;
    if( ntuple->GenParticles == NULL ) return -999.;
    double pt = -999.;
    for( unsigned int p = 0 ; p < ntuple->GenParticles->size() ; p++ ){
        if( abs(ntuple->GenParticles_PdgId->at(p)) == 24 ){
            //std::cout << "pt: " << ntuple->GenParticles->at(p).Pt() << std::endl;
            pt = ntuple->GenParticles->at(p).Pt();
        }
    }
    return pt; 
}

template<typename ntupleType> double FillGenZPt(ntupleType* ntuple){
    //cout << "FillGenZPt:" << endl;
    if( ntuple->GenParticles == NULL ) return -999.;
    double pt = -999.;
    for( unsigned int p = 0 ; p < ntuple->GenParticles->size() ; p++ ){
        if( abs(ntuple->GenParticles_PdgId->at(p)) == 23 ){
            //std::cout << "pt: " << ntuple->GenParticles->at(p).Pt() << std::endl;
            pt = ntuple->GenParticles->at(p).Pt();
        }
    }
    return pt; 
}

template<typename ntupleType> bool genWmatched(ntupleType* ntuple){
    if( ntuple->JetsAK8->size() == 0 ) return false;
    
    for( int i=0 ; i < ntuple->GenParticles->size() ; i++ ){
        if( abs(ntuple->GenParticles_PdgId->at(i)) == 24 && ntuple->JetsAK8->at(0).DeltaR(ntuple->GenParticles->at(i))<0.4)
            return true;
    }
    return false;
}

template<typename ntupleType> bool genTmatched(ntupleType* ntuple){
    if( ntuple->JetsAK8->size() == 0 ) return false;
    
    for( int i=0 ; i < ntuple->GenParticles->size() ; i++ ){
        if( abs(ntuple->GenParticles_PdgId->at(i)) == 6 && ntuple->JetsAK8->at(0).DeltaR(ntuple->GenParticles->at(i))<0.4)
            return true;
    }
    return false;
}

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
template<typename ntupleType> double GJetsNLOWeights(ntupleType* ntuple){
    if( ntuple->Photons->size() == 0 ) return 0.;
    double photon_pt = -999.;//ntuple->Photons->at(0).Pt();
    int photonIndex=-1;
    for( unsigned int p = 0 ; p < ntuple->GenParticles->size() ; p++ ){
        if( abs(ntuple->GenParticles_PdgId->at(p)) == 22 ){
            if( photonIndex < 0 )
                photonIndex = p;
            else if( ntuple->GenParticles->at(p).Pt() > ntuple->GenParticles->at(photonIndex).Pt() )
                photonIndex = p;
        }
    }               
    photon_pt = ntuple->GenParticles->at(photonIndex).Pt();
    
    if( photon_pt>150. ){
        double LO = GJets_LO->GetBinContent( GJets_LO->FindBin(photon_pt) );
        double NLO = GJets_NLO->GetBinContent( GJets_NLO->FindBin(photon_pt) );
        return (LO==0?0.:NLO/LO);
    }else
        return GJets_NLO->GetBinContent(1)/GJets_LO->GetBinContent(1);
}

template<typename ntupleType> double WJetsNLOWeights(ntupleType* ntuple){
    double Wpt=-999.;
    for( unsigned int p = 0 ; p < ntuple->GenParticles->size() ; p++ ){
        if( abs(ntuple->GenParticles_PdgId->at(p)) == 24 )
            Wpt = ntuple->GenParticles->at(p).Pt();
    }
    if( Wpt>150. ){
        double LO = WJets_LO->GetBinContent( WJets_LO->FindBin(Wpt) );
        double NLO = WJets_NLO->GetBinContent( WJets_NLO->FindBin(Wpt) );
        return (LO==0?0.:NLO/LO/1.21);
    }else
        return WJets_NLO->GetBinContent(1)/WJets_LO->GetBinContent(1)/1.21;
}

template<typename ntupleType> double ZJetsNLOWeights(ntupleType* ntuple){
    double Zpt=-999.;
    for( unsigned int p = 0 ; p < ntuple->GenParticles->size() ; p++ ){
        if( abs(ntuple->GenParticles_PdgId->at(p)) == 23 )
            Zpt = ntuple->GenParticles->at(p).Pt();
    }
    if( Zpt>150. ){
        double LO = ZJets_LO->GetBinContent( ZJets_LO->FindBin(Zpt) );
        double NLO = ZJets_NLO->GetBinContent( ZJets_NLO->FindBin(Zpt) );
        return (LO==0?0.:NLO/LO/1.23);
    }else
        return ZJets_NLO->GetBinContent(1)/ZJets_LO->GetBinContent(1)/1.23;
}

template<typename ntupleType> double singleMuonTrigWeights(ntupleType* ntuple){
    if( ntuple->Muons->size() == 0 ) return 0.;
    else if( ntuple->HT > 300. ){
        if( ntuple->HT < 500.){
            if( ntuple->Muons->at(0).Pt() > 25. ){
                if( ntuple->Muons->at(0).Pt() < 30. ){
                    return .787;
                }else if( ntuple->Muons->at(0).Pt() < 50. ){
                    return .843;
                }else{
                    return .908;
                }
            }else{
                return 0.;
            }
        }else if( ntuple->HT > 500. ){
            return .949;
        }else{
            return 0.;
        }
    }
}

template<typename ntupleType> double singleElectronTrigWeights(ntupleType* ntuple){
    if( ntuple->Electrons->size() == 0 ) return 0.;
    else if( ntuple->HT > 450. ){
        
        //cout << "ntuple->HT: " << ntuple->HT << endl;
        //cout << "ntuple->Electrons->at(0).Pt(): " << ntuple->Electrons->at(0).Pt() << endl;

        if( ntuple->Electrons->at(0).Pt() > 25. ){
            if( ntuple->Electrons->at(0).Pt() < 30. ){
                return 0.794;
            }else if( ntuple->Electrons->at(0).Pt() < 40. ){
                return 0.826;
            }else if( ntuple->Electrons->at(0).Pt() < 50. ){
                return 0.872;
            }else if( ntuple->Electrons->at(0).Pt() < 75. ){
                return 0.884;
            }else if( ntuple->Electrons->at(0).Pt() < 100. ){
                return 0.913;
            }else{
                return 0.947;
            }
        }else{
            return 0.;
        }
    }else if( ntuple->HT > 300. ){

        //cout << "ntuple->HT: " << ntuple->HT << endl;
        //cout << "ntuple->Electrons->at(0).Pt(): " << ntuple->Electrons->at(0).Pt() << endl;

        if( ntuple->Electrons->at(0).Pt() > 25. ){
            if( ntuple->Electrons->at(0).Pt() < 30. ){
                return 0.572;
            }else if( ntuple->Electrons->at(0).Pt() < 40. ){
                return 0.775;
            }else if( ntuple->Electrons->at(0).Pt() < 50. ){
                return 0.858;
            }else if( ntuple->Electrons->at(0).Pt() < 75. ){
                return 0.861;
            }else if( ntuple->Electrons->at(0).Pt() < 100. ){
                return 0.932;
            }else{
                return 1.;
            }  
        }else{
            return 0.;
        }
    }else{
        return 0.;
    }
}

template<typename ntupleType> double lowDphiTrigWeights(ntupleType* ntuple){
    if( ntuple->MET>100. ){
        if( ntuple->MET<200. ){
            return 0.500;
        }else if( ntuple->MET<300. ){
            return 0.712;
        }else if( ntuple->MET<400. ){
            return 0.806;
        }else if( ntuple->MET<500. ){
            return 0.874;
        }else if( ntuple->MET<700. ){
            return 0.866;
        }else{
            return 0.766;
        }
    }else
        return 0.;
}

template<typename ntupleType> double customPUweights(ntupleType* ntuple){
    int nVtx = ntuple->TrueNumInteractions;
    return puWeightHist->GetBinContent(puWeightHist->GetXaxis()->FindBin(min(ntuple->TrueNumInteractions,puWeightHist->GetBinLowEdge(puWeightHist->GetNbinsX()+1))));
}

enum ISRweightType {kNom,kUp,kDn};
template<typename ntupleType> double ISRweights(ntupleType* ntuple, ISRweightType wType = kNom ){

    double wanted_w_isr=1.;
    double wanted_sys_isr[2]={1.,1.};

    TString sample = ntuple->fChain->GetFile()->GetName();

    // these are taken from here:
    // https://github.com/manuelfs/babymaker/blob/3a57e1bace6c52832fe40e401cf37bc6b50923c3/bmaker/genfiles/src/change_weights.cxx#L156-L175
    // via Manuel Franco Sevilla
    if(sample.Contains("TTJets_HT-600to800")) {
        wanted_w_isr = 0.7838;
        wanted_sys_isr[0] = 0.8965;
        wanted_sys_isr[1] = 0.6604;
    }else if(sample.Contains("TTJets_HT-800to1200")) {
        wanted_w_isr = 0.7600;
        wanted_sys_isr[0] = 0.8851;
        wanted_sys_isr[1] = 0.6230;
    }else if(sample.Contains("TTJets_HT-1200to2500")) {
        wanted_w_isr = 0.7365;
        wanted_sys_isr[0] = 0.8739;
        wanted_sys_isr[1] = 0.5861;
    }else if(sample.Contains("TTJets_HT-2500toInf")) {
        wanted_w_isr = 0.7254;
        wanted_sys_isr[0] = 0.8686;
        wanted_sys_isr[1] = 0.5687;
    }else{ //  if(sample.Contains("TTJets_SingleLept") or sample.Contains("TTJets_DiLept") ){
        // these numbers should really only be applied to the inclusive sample
        wanted_w_isr = 1.071;
        wanted_sys_isr[0] = 1.071;
        wanted_sys_isr[1] = 1.071;
    }
    
    double D;
    if( wType == kNom ) D = wanted_w_isr;
    else D = wanted_sys_isr[wType-1];

    double w[6]={0.920,0.821,0.715,0.662,0.561,0.511};
    if( ntuple->NJetsISR == 0 )
        return D;
    else if( ntuple->NJetsISR >= 6 )
        return w[5]*D;
    else 
        return w[ntuple->NJetsISR]*D;
}

//////////////////////
// Lepton functions //
//////////////////////

template<typename ntupleType> double computeMuonMT(ntupleType* ntuple){ 
    if( ntuple->Muons->size() == 0 ) return -9999.;
    double lepPt = ntuple->Muons->at(0).Pt();
    double lepPhi = ntuple->Muons->at(0).Phi(); 
    double MET = ntuple->MET;
    double METPhi = ntuple->METPhi;
    return sqrt( 2*lepPt*MET * ( 1 - cos( METPhi-lepPhi ) ) );
}

////////////////////////////////////////////////////////////
// - - - - - - - - EVENT LEVEL VARIABLES - - - - - - - -  //
////////////////////////////////////////////////////////////

template<typename ntupleType> double fillJetPt1(ntupleType* ntuple){
    if( ntuple->Jets->size() >= 1) 
        return ntuple->Jets->at(0).Pt();
    else 
        return -999.;
}

template<typename ntupleType> double fillJetPt2(ntupleType* ntuple){
    if( ntuple->Jets->size() >= 2) 
        return ntuple->Jets->at(1).Pt();
    else 
        return -999.;
}

template<typename ntupleType> double fillJetPt3(ntupleType* ntuple){
    if( ntuple->Jets->size() >= 3) 
        return ntuple->Jets->at(2).Pt();
    else 
        return -999.;
}

template<typename ntupleType> double fillJetPt4(ntupleType* ntuple){
    if( ntuple->Jets->size() >= 4) 
        return ntuple->Jets->at(3).Pt();
    else 
        return -999.;
}

template<typename ntupleType> double fillNVtx(ntupleType* ntuple){
  return ntuple->NVtx;
}

template<typename ntupleType> double fillnAllVertices(ntupleType* ntuple){
  return ntuple->nAllVertices;
}

template<typename ntupleType> double fillNumInteractions(ntupleType* ntuple){
  return ntuple->NumInteractions;
}

template<typename ntupleType> double fillMadHT(ntupleType* ntuple){
  return ntuple->madHT;
}

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


template<typename ntupleType> double fillNAK8Jets(ntupleType* ntuple){
ntuple->JetsAK8->size();
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
template<typename ntupleType> double fillLeadingJetMinDRB(ntupleType* ntuple){
    if( ntuple->JetsAK8->size() == 0 ) return -999.;
    else{
        double minDRB = 999.;
        double DRB = 999.;
        for( int i = 0 ; i < ntuple->Jets->size() ; i++ ){
            DRB = 999.;            
            if( abs(ntuple->Jets_partonFlavor->at(i)) == 5 ){
                DRB = ntuple->JetsAK8->at(0).DeltaR(ntuple->Jets->at(i));
            }
            if( DRB < minDRB ) 
                minDRB = DRB;
        }
        return minDRB;
    }
}

template<typename ntupleType> double fillLeadingJetMass(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()==0) return -99999.;
  return ntuple->JetsAK8_prunedMass->at(0);
}

template<typename ntupleType> double fillLeadingJetMass_photon(ntupleType* ntuple){
    if(ntuple->JetsAK8Clean_prunedMass->size()==0) return -99999.;
    return ntuple->JetsAK8Clean_prunedMass->at(0);
}

template<typename ntupleType> double fillLeadingJetPt(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()==0) return-99999.;
  return ntuple->JetsAK8->at(0).Pt();
}

template<typename ntupleType> bool AK8JEtaCut(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()==0) return-99999.;
  double AK8Eta = fabs(ntuple->JetsAK8->at(0).Eta()); 
  return (AK8Eta<1.0);
}

template<typename ntupleType> double fillLeadingJetEta(ntupleType* ntuple){
  return ntuple->JetsAK8->at(0).Eta();
}

template<typename ntupleType> double fillLeadingTau21(ntupleType* ntuple){
  if(ntuple->JetsAK8->size()==0) return-99999.;
  return ntuple->JetsAK8_NsubjettinessTau2->at(0)/ntuple->JetsAK8_NsubjettinessTau1->at(0);
}

////////////////////////////////////////
// HIGHEST BBtag AK8 JET PROPERTIES  //
//////////////////////////////////////

/////////////////////////////////////////////
// SECOND HIGHEST BBtag AK8 JET PROPERTIES //
/////////////////////////////////////////////


/////////////////////////////////////////////
// SECOND HIGHEST Mass AK8 JET PROPERTIES //
/////////////////////////////////////////////

/////////////////////////////////////////////
// SECOND HIGHEST Mass AK8 JET PROPERTIES //
/////////////////////////////////////////////

  /////////////////
 // OTHER STUFF //
/////////////////

template<typename ntupleType> bool FiltersCut(ntupleType* ntuple){
    return ntuple->HBHENoiseFilter==1 && 
        ntuple->HBHEIsoNoiseFilter==1 && 
        ntuple->eeBadScFilter==1 && 
        ntuple->EcalDeadCellTriggerPrimitiveFilter == 1 && 
        ntuple->NVtx>0 && 
        ntuple->MET/ntuple->CaloMET < 5. &&
        ntuple->BadPFMuonFilter == 1 &&
        ntuple->BadChargedCandidateFilter == 1 &&
        ntuple->globalTightHalo2016Filter == 1;
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
  //return ntuple->DeltaPhi3>0.3;
  return ntuple->DeltaPhi3>0.5;
}

template<typename ntupleType> bool DeltaPhi4Cut(ntupleType* ntuple){
  //return ntuple->DeltaPhi4>0.3;
  return ntuple->DeltaPhi4>0.5;
}

template<typename ntupleType> bool DeltaPhiCuts(ntupleType* ntuple){
    return ( DeltaPhi1Cut(ntuple) &&
             DeltaPhi2Cut(ntuple) &&
             DeltaPhi3Cut(ntuple) &&
             DeltaPhi4Cut(ntuple) ) ;
}             

template<typename ntupleType> bool lowDPhiCuts(ntupleType* ntuple){
    return !DeltaPhiCuts(ntuple);
}

template<typename ntupleType> bool AK8JetPtCut(ntupleType* ntuple){
  return ( ntuple->JetsAK8->size() >= 1 &&
	   ntuple->JetsAK8->at(0).Pt() > 0. );
	   //ntuple->JetsAK8->at(0).Pt() > 200. );
}

template<typename ntupleType> bool METCut(ntupleType* ntuple){
  return ( ntuple->MET > 0.);
	   //ntuple->MET > 200. );
}
template<typename ntupleType> bool DeltaPhiAK8JMETCut(ntupleType* ntuple){
  double DeltaPhiAK8JMET=CalcdPhi(ntuple->JetsAK8->at(0).Phi(), ntuple->METPhi);
  return DeltaPhiAK8JMET>2.0;
}

template<typename ntupleType> double fillDeltaPhiAK8JMET(ntupleType* ntuple){
  double DeltaPhiAK8JMET=CalcdPhi(ntuple->JetsAK8->at(0).Phi(), ntuple->METPhi);
  return DeltaPhiAK8JMET;
}


template<typename ntupleType> double fillZMT(ntupleType* ntuple){
     double AK8Pt = ntuple->JetsAK8->at(0).Pt();
     double AK8Phi = ntuple->JetsAK8->at(0).Phi();
     double MET = ntuple->MET;
     double METPhi = ntuple->METPhi;
     return ZMT(AK8Pt, AK8Phi, MET, METPhi);
     //return sqrt( 2*AK8Pt*MET * ( 1 - cos( DeltaPhiAK8JMETCut(ntuple)) ) );
}

// Plot the jet mass for different MT interval to see how it changes with MT

template<typename ntupleType> double fillMZ510MT(ntupleType* ntuple){
    if (fillZMT(ntuple) >500 && fillZMT(ntuple) <1000)
    return ntuple->JetsAK8_prunedMass->at(0);
}

template<typename ntupleType> double fillMZ1015MT(ntupleType* ntuple){
    if (fillZMT(ntuple) >1000 && fillZMT(ntuple) <1500)
    return ntuple->JetsAK8_prunedMass->at(0);
}

template<typename ntupleType> double fillMZ1520MT(ntupleType* ntuple){
    if (fillZMT(ntuple) >1500 && fillZMT(ntuple) <2000)
    return ntuple->JetsAK8_prunedMass->at(0);
}

template<typename ntupleType> double fillMZ2025MT(ntupleType* ntuple){
    if (fillZMT(ntuple) >2000 && fillZMT(ntuple) <2500)
    return ntuple->JetsAK8_prunedMass->at(0);
}

template<typename ntupleType> double fillMZ2530MT(ntupleType* ntuple){
    if (fillZMT(ntuple) >2500 && fillZMT(ntuple) <3000)
    return ntuple->JetsAK8_prunedMass->at(0);
}


// DDT Calculation: HP: <0.55, LP: <0.95
// DDT = tau21 + 0.082*log(m*m/pt)
template<typename ntupleType> double fillDDT(ntupleType* ntuple){
    double tau21 = ntuple->JetsAK8_NsubjettinessTau2->at(0)/ntuple->JetsAK8_NsubjettinessTau1->at(0);
    double m = ntuple->JetsAK8_prunedMass->at(0);
    double m2 = m*m;
    double p = ntuple->JetsAK8->at(0).Pt(); 
  return (tau21+(0.082*log(m2/p)));
}


////////////////////////////////////////
// VBF JET   //
//////////////////////////////////////

// skip Z jets function
template<typename ntupleType> vector<TLorentzVector>  skipZjets(ntupleType* ntuple, int iJ=0){
    vector<TLorentzVector> skipZ_jets;
    for( unsigned int iak4 = 0 ; iak4 < ntuple->Jets->size() ; iak4++ ){
        if(!((ntuple->JetsAK8->at(iJ).DeltaR(ntuple->Jets->at(iak4)) < 0.8 ) && 
            (ntuple->JetsAK8->at(0).Pt()>200 && (ntuple->JetsAK8_NsubjettinessTau2->at(iJ)/ntuple->JetsAK8_NsubjettinessTau1->at(iJ)<0.75) &&
            ntuple->JetsAK8_prunedMass->at(iJ)<300 &&
            ntuple->JetsAK8_prunedMass->at(iJ)>30))){
            skipZ_jets.push_back(TLorentzVector(ntuple->Jets->at(iak4)));
        }// end if block to make sure there is a valid Ztag
    }// end for loop over ak4 jets
   return skipZ_jets;
} 

template<typename ntupleType> vector<TLorentzVector>  cleanedVBFjets(ntupleType* ntuple, int iJ=0){
    vector<TLorentzVector> cleaned_jets=skipZjets(ntuple,iJ);
    vector<TLorentzVector> vj(2);
    //vj[0].SetPxPyPzE(-99.,-99.,-99.,-99.);
    vj[0].SetPtEtaPhiM(1.0,-99.,-99.,0.);
    vj[1].SetPtEtaPhiM(1.0,99.,99.,0.);

    int nj = cleaned_jets.size() ;
    if (nj<2) return vj;
    double MassMax = 0.0;
    for( unsigned int iak4 = 0 ; iak4 < (nj-1); iak4++ ){
        if (cleaned_jets[iak4].Pt()<30) continue;
        for( unsigned int jak4 = iak4+1; jak4 < nj; jak4++ ){        
            if (cleaned_jets[jak4].Pt()<30) continue;
            TLorentzVector vjA, vjB;
            vjA.SetPtEtaPhiM(cleaned_jets[iak4].Pt(), cleaned_jets[iak4].Eta(), 
                             cleaned_jets[iak4].Phi(),cleaned_jets[iak4].M());
            vjB.SetPtEtaPhiM(cleaned_jets[jak4].Pt(), cleaned_jets[jak4].Eta(),
                             cleaned_jets[jak4].Phi(),cleaned_jets[jak4].M());
            double jetABMass = (vjA+vjB).M();                       
            if (jetABMass > MassMax){
                MassMax = jetABMass;
                vj[0] = vjA;
                vj[1] = vjB;
            }
        }// end for loop over jak4 jets
    }// end for loop over iak4 jets
  return vj;
} 

template<typename ntupleType> double fillVBF_Mjj(ntupleType* ntuple){
    //double fwdMjj = -1.0
    vector<TLorentzVector> vbf_jets = cleanedVBFjets(ntuple,0);
    //if (vbf_jets[0].Pt()>30.0 && vbf_jets[1].Pt()>30.0){
    //if( vbf_jets.size() < 2 ) return -1.;
        TLorentzVector temp(vbf_jets[0]);
        temp+=vbf_jets[1];
     //   fwdMjj = temp.M();
    return temp.M(); 
}

template<typename ntupleType> double fillVBF_Ptjj(ntupleType* ntuple){
    vector<TLorentzVector> vbf_jets = cleanedVBFjets(ntuple,0);
    //if( vbf_jets.size() < 2 ) return -1.;
    TLorentzVector temp(vbf_jets[0]);
    temp+=vbf_jets[1];
    return temp.Pt(); 
}

template<typename ntupleType> double fillVBF_dEta(ntupleType* ntuple){
    vector<TLorentzVector> vbf_jets = cleanedVBFjets(ntuple,0);
    return  fabs(vbf_jets[0].Eta()-vbf_jets[1].Eta());
}

template<typename ntupleType> double fillVBF_dPhi(ntupleType* ntuple){
    vector<TLorentzVector> vbf_jets = cleanedVBFjets(ntuple,0);
    return CalcdPhi(vbf_jets[0].Phi(), vbf_jets[1].Phi());
}

template<typename ntupleType> double fillVBF_j1Eta(ntupleType* ntuple){
    //double j1Eta = -10.0;
    vector<TLorentzVector> vbf_jets = cleanedVBFjets(ntuple,0);
    return  vbf_jets[0].Eta();
    //return  j1Eta;
}

template<typename ntupleType> double fillVBF_j2Eta(ntupleType* ntuple){
    vector<TLorentzVector> vbf_jets = cleanedVBFjets(ntuple,0);
    return  vbf_jets[1].Eta();
}

template<typename ntupleType> double fillVBF_j1Phi(ntupleType* ntuple){
    vector<TLorentzVector> vbf_jets = cleanedVBFjets(ntuple,0);
    return  vbf_jets[0].Phi();
}

template<typename ntupleType> double fillVBF_j2Phi(ntupleType* ntuple){
    vector<TLorentzVector> vbf_jets = cleanedVBFjets(ntuple,0);
    return  vbf_jets[1].Phi();
}
template<typename ntupleType> double fillVBF_j1j2Eta(ntupleType* ntuple){
    vector<TLorentzVector> vbf_jets = cleanedVBFjets(ntuple,0);
    return  (vbf_jets[0].Eta()*vbf_jets[1].Eta());
}

template<typename ntupleType> double fillVBF_j1Pt(ntupleType* ntuple){
    vector<TLorentzVector> vbf_jets = cleanedVBFjets(ntuple,0);
    return  vbf_jets[0].Pt();
}

template<typename ntupleType> double fillVBF_j2Pt(ntupleType* ntuple){
    vector<TLorentzVector> vbf_jets = cleanedVBFjets(ntuple,0);
    return  vbf_jets[1].Pt();
}

template<typename ntupleType> bool AK4JptCuts(ntupleType* ntuple){
    for( unsigned int iak4 = 0 ; iak4 < ntuple->Jets->size() ; iak4++ ){
    return ( ntuple->Jets->at(iak4).Pt() > 30.0
             ) ;
    }
}             

template<typename ntupleType> bool VBFCuts(ntupleType* ntuple){
    vector<TLorentzVector> vbf_jets = cleanedVBFjets(ntuple,0);
    
    return ( fillVBF_dEta(ntuple)>4.0 &&
             fillVBF_Mjj(ntuple)>500 &&
             fillVBF_j1j2Eta(ntuple)<0 &&
             vbf_jets[0].Pt()>30.0 && vbf_jets[1].Pt()>30.0);
}             
// end of B2G ZV VBF part
template<typename ntupleType> bool AK8JetSideBandCut(ntupleType* ntuple){
    return   (ntuple->JetsAK8_prunedMass->size() >= 1  &&
              (
               ( ntuple->JetsAK8_prunedMass->at(0) > 30. && ntuple->JetsAK8_prunedMass->at(0) < 65.) ||
               ( ntuple->JetsAK8_prunedMass->at(0) > 135. && ntuple->JetsAK8_prunedMass->at(0) < 300.)
              )
             );	   
}

template<typename ntupleType> bool AlphaSideBandCut(ntupleType* ntuple){
    return   (ntuple->JetsAK8_prunedMass->size() >= 1  &&
              (
               ( ntuple->JetsAK8_prunedMass->at(0) > 40. && ntuple->JetsAK8_prunedMass->at(0) < 65.) ||
               ( ntuple->JetsAK8_prunedMass->at(0) > 135. && ntuple->JetsAK8_prunedMass->at(0) < 150.)
              )
             );	   
}
template<typename ntupleType> bool AK8JetSRCut(ntupleType* ntuple){
    return   (ntuple->JetsAK8_prunedMass->size() >= 1  &&
             (ntuple->JetsAK8_prunedMass->at(0) > 65. &&
             ntuple->JetsAK8_prunedMass->at(0) < 105.)
            );
}

template<typename ntupleType> bool HighPurityCut(ntupleType* ntuple){
  return (
         (ntuple->JetsAK8_NsubjettinessTau2->at(0)/ntuple->JetsAK8_NsubjettinessTau1->at(0))<0.45
         );
}

template<typename ntupleType> bool LowPurityCut(ntupleType* ntuple){
  return (
         (ntuple->JetsAK8_NsubjettinessTau2->at(0)/ntuple->JetsAK8_NsubjettinessTau1->at(0))>0.45 &&
         (ntuple->JetsAK8_NsubjettinessTau2->at(0)/ntuple->JetsAK8_NsubjettinessTau1->at(0))<0.75
        );
}


// 1) Baseline selection without VBF cut
template<typename ntupleType> bool baselineCutNoVBF(ntupleType* ntuple){
  return ( METCut(ntuple)  &&
           AK8JetPtCut(ntuple)); //&& 
           //DeltaPhiCuts(ntuple) &&
           //DeltaPhiAK8JMETCut(ntuple) && 
           //ntuple->Photons->size()==0 &&  
           //ntuple->Muons->size()==0 &&
           //ntuple->Electrons->size()==0 &&
           //ntuple->BTags == 0  
           //&& ntuple->isoElectronTracks==0 && ntuple->isoMuonTracks==0 && ntuple->isoPionTracks==0 &&
           //FiltersCut(ntuple) &&
           //ntuple->JetID == 1);
}
    
// 2) Baseline with VBF cut
template<typename ntupleType> bool baselineCut(ntupleType* ntuple){
  return (baselineCutNoVBF(ntuple) &&
           VBFCuts(ntuple));
}

// 3) Baseline + Z Signal region i.e. Pruned Mass [65,105] GeV without VBF cut 
template<typename ntupleType> bool ZSignalRegionCutNoVBF(ntupleType* ntuple){
 
  return (baselineCutNoVBF(ntuple) && 
          AK8JetSRCut(ntuple)); 
}

// 4) Baseline + Z Signal region i.e. Pruned Mass [65,105] GeV + VBF cut 
template<typename ntupleType> bool ZSignalRegionCut(ntupleType* ntuple){
 
  return ( ZSignalRegionCutNoVBF(ntuple) &&
           VBFCuts(ntuple));
}

// 5) Baseline + Z Signal region i.e. Pruned Mass [65,105] GeV + HP without  VBF cut 
template<typename ntupleType> bool ZSignalRegionHPCutNoVBF(ntupleType* ntuple){
 
  return (  ZSignalRegionCutNoVBF(ntuple) && 
            HighPurityCut(ntuple));
}

// 6) Baseline + Z Signal region i.e. Pruned Mass [65,105] GeV + HP with  VBF cut 
template<typename ntupleType> bool ZSignalRegionHPCut(ntupleType* ntuple){
 
  return (ZSignalRegionHPCutNoVBF(ntuple) && 
           VBFCuts(ntuple));
}

// 6A) ZSRHPVBF + AK8 L1J eta > 1 cut 
template<typename ntupleType> bool ZHPEtaCut(ntupleType* ntuple){
  return (ZSignalRegionHPCut(ntuple) &&
           AK8JEtaCut(ntuple));
}
// 7) Baseline + Z Signal region i.e. Pruned Mass [65,105] GeV + LP without  VBF cut 
template<typename ntupleType> bool ZSignalRegionLPCutNoVBF(ntupleType* ntuple){
 
  return (  ZSignalRegionCutNoVBF(ntuple) && 
            LowPurityCut(ntuple));
}

// 8) Baseline + Z Signal region i.e. Pruned Mass [65,105] GeV + LP with  VBF cut 
template<typename ntupleType> bool ZSignalRegionLPCut(ntupleType* ntuple){
 
  return ( ZSignalRegionLPCutNoVBF(ntuple) &&
           VBFCuts(ntuple));
}

// 9) Z side band w/o vbf cut selection ([30,65][>145])
template<typename ntupleType> bool ZSidebandnoVBFCut(ntupleType* ntuple){
  return ( baselineCutNoVBF(ntuple) &&
           AK8JetSideBandCut(ntuple) ); 
}

// 10) Z side band selection ([30,65][>145]) + vbf cut
template<typename ntupleType> bool ZSidebandCut(ntupleType* ntuple){
  return ( ZSidebandnoVBFCut(ntuple) &&
           VBFCuts(ntuple));
}

// Z side band HP(tau21<0.45) selection
// https://twiki.cern.ch/twiki/bin/view/CMS/JetWtagging#2016_scale_factors_and_correctio
// 11) Z sideband high purity but without VBF cut
template<typename ntupleType> bool ZSidebandHPCutnoVBF(ntupleType* ntuple){
 
  return (ZSidebandnoVBFCut(ntuple) &&
          HighPurityCut(ntuple));            
}

// 12) Z sideband High purity with VBF cut
template<typename ntupleType> bool ZSidebandHPCut(ntupleType* ntuple){
 
  return ( ZSidebandHPCutnoVBF(ntuple) && 
           VBFCuts(ntuple));
}
// For Alpha Closure test
template<typename ntupleType> bool ZAlphaHPCutnoVBF(ntupleType* ntuple){
 
  return ( baselineCutNoVBF(ntuple) &&
          AlphaSideBandCut(ntuple) &&
          HighPurityCut(ntuple));            
}
template<typename ntupleType> bool ZAlphaHPCutVBF(ntupleType* ntuple){
 
  return ( baselineCutVBF(ntuple) &&
          AlphaSideBandCut(ntuple) &&
          HighPurityCut(ntuple));            
}
// end of Alhpha Closure part

// 13) Z side band LP (0.45<tau21<0.75) without VBF selection
template<typename ntupleType> bool ZSidebandLPCutnoVBF(ntupleType* ntuple){
 
  return ( ZSidebandnoVBFCut(ntuple) &&
           LowPurityCut(ntuple)); 
}

// 14) Z side band LP (0.45<tau21<0.75) wit VBF selection
template<typename ntupleType> bool ZSidebandLPCut(ntupleType* ntuple){
 
  return ( ZSidebandLPCutnoVBF(ntuple) && 
           VBFCuts(ntuple));
}


/////////////////////////
//// End of VBF Part ////
/////////////////////////

template<typename ntupleType> bool singleMuCut(ntupleType* ntuple){
    if( ntuple->Muons->size() != 1 || ntuple->Electrons->size() != 0 ) return false;
    double MT = computeMuonMT(ntuple);
    return ntuple->Muons->at(0).Pt()>25. &&
           MT < 100.;

}

template<typename ntupleType> bool singleMuBaselineCut(ntupleType* ntuple){

    return ( singleMuCut(ntuple) && 
             ntuple->MET > 100.             &&
             ntuple->HT > 600.                         &&
             ntuple->JetsAK8->size() >= 2 &&
             ntuple->JetsAK8->at(0).Pt() > 300. && 
             ntuple->JetsAK8_prunedMass->at(0) > 50. && 
             ntuple->JetsAK8_prunedMass->at(0) < 250. && 
             ntuple->JetsAK8->at(1).Pt() > 300. &&
             ntuple->JetsAK8_prunedMass->at(1) > 50. && 
             ntuple->JetsAK8_prunedMass->at(1) < 250.&&
             DeltaPhiCuts( ntuple ) && 
             FiltersCut(ntuple) &&
             ntuple->JetID == 1);
    
}

template<typename ntupleType> bool singleEleCut(ntupleType* ntuple){
    if( ntuple->Muons->size() != 0 || ntuple->Electrons->size() != 1 ) return false;
    double MT = computeElectronMT(ntuple);
    return ( ntuple->Electrons->at(0).Pt()>25. && 
             MT < 100. ) ;
}
template<typename ntupleType> bool singleEleBaselineCut(ntupleType* ntuple){


    return ( singleEleCut(ntuple) && 
             ntuple->MET > 100.             &&
             ntuple->HT > 600.                         &&
             ntuple->JetsAK8->size() >= 2 &&
             ntuple->JetsAK8->at(0).Pt() > 300. && 
             ntuple->JetsAK8_prunedMass->at(0) > 50. && 
             ntuple->JetsAK8_prunedMass->at(0) < 250. && 
             ntuple->JetsAK8->at(1).Pt() > 300. &&
             ntuple->JetsAK8_prunedMass->at(1) > 50. && 
             ntuple->JetsAK8_prunedMass->at(1) < 250.&&
             DeltaPhiCuts( ntuple ) && 
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
             ! DeltaPhiCuts( ntuple ) && 
             FiltersCut(ntuple) &&
             ntuple->JetID == 1);
}

template<typename ntupleType> bool photonBaselineCut(ntupleType* ntuple){
    return ( ntuple->Photons->size()==1 &&
             ntuple->Photons->at(0).Pt() > 100. && 
             ntuple->Photons_fullID->size() == 1 && 
             ntuple->Photons_fullID->at(0) == 1 &&
             ntuple->METclean > 100.             &&
             ntuple->HTclean > 400.                         &&
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
             FiltersCut(ntuple) &&
             ntuple->JetIDclean == 1);
}

template<typename ntupleType> bool photonBaselineCut_loose(ntupleType* ntuple){
    return ( ntuple->Photons->size()==1 &&
             ntuple->Photons->at(0).Pt() > 100. && 
             ntuple->Photons_fullID->size() == 1 && 
             ntuple->Photons_fullID->at(0) == 1 &&
             ntuple->METclean > 100.             &&
             ntuple->HTclean > 400.                         &&
             ntuple->JetsAK8Clean->size()>=2 && 
             ntuple->DeltaPhi1clean>0.5 && 
             ntuple->DeltaPhi2clean>0.5 &&
             ntuple->DeltaPhi3clean>0.3 && 
             ntuple->DeltaPhi4clean>0.3 &&
             ntuple->isoElectronTracksclean==0 &&
             ntuple->isoMuonTracksclean == 0 && 
             ntuple->isoPionTracksclean == 0 &&
             ntuple->Electrons->size() == 0 &&
             ntuple->Muons->size() == 0 && 
             FiltersCut(ntuple) &&
             ntuple->JetIDclean == 1);
}

template<typename ntupleType> bool leadJetTighMassCut(ntupleType* ntuple ){ 
    return ntuple->JetsAK8_doubleBDiscriminator->size()>=1 && 
           (ntuple->JetsAK8_prunedMass->at(0) > 85. && 
            ntuple->JetsAK8_prunedMass->at(0) < 135.);    
}

template<typename ntupleType> bool subleadJetTighMassCut(ntupleType* ntuple ){ 
    return ntuple->JetsAK8_doubleBDiscriminator->size()>=2 && 
           (ntuple->JetsAK8_prunedMass->at(1) > 85. && 
            ntuple->JetsAK8_prunedMass->at(1) < 135.);
}

template<typename ntupleType> bool singleHiggsTagLooseCut(ntupleType* ntuple ){ 
    return ( ntuple->JetsAK8_doubleBDiscriminator->size()>=2 &&
             ( ( ntuple->JetsAK8_doubleBDiscriminator->at(0) > bbtagCut ) 
             && ( ntuple->JetsAK8_doubleBDiscriminator->at(1) < bbtagCut ) ) ||
        ( ( ntuple->JetsAK8_doubleBDiscriminator->at(0) < bbtagCut ) 
          && ( ntuple->JetsAK8_doubleBDiscriminator->at(1) > bbtagCut ) ) );
}

template<typename ntupleType> bool OneOrMoreHiggsTagLooseCut(ntupleType* ntuple ){ 
    return ( ntuple->JetsAK8_doubleBDiscriminator->size()>=2 &&
             ( ntuple->JetsAK8_doubleBDiscriminator->at(0) > bbtagCut ||
               ntuple->JetsAK8_doubleBDiscriminator->at(1) > bbtagCut ) );
}

template<typename ntupleType> bool antiTaggingLooseCut(ntupleType* ntuple ){
    return ( ntuple->JetsAK8_doubleBDiscriminator->size()>=2 &&
             ( ( ntuple->JetsAK8_doubleBDiscriminator->at(0) < bbtagCut
               ) &&
             ( ntuple->JetsAK8_doubleBDiscriminator->at(1) < bbtagCut 
               ) ) ) ;
}

template<typename ntupleType> bool doubleTaggingLooseCut(ntupleType* ntuple ){
    return ( ntuple->JetsAK8_doubleBDiscriminator->size()>=2 &&
             ntuple->JetsAK8_doubleBDiscriminator->at(0) > bbtagCut && 
             ntuple->JetsAK8_doubleBDiscriminator->at(1) > bbtagCut );
}

template<typename ntupleType> bool doubleMassCut(ntupleType* ntuple ){
    return ( ntuple->JetsAK8_doubleBDiscriminator->size()>=2 &&
             ntuple->JetsAK8_prunedMass->at(0) > 85. &&
             ntuple->JetsAK8_prunedMass->at(0) < 135. &&
             ntuple->JetsAK8_prunedMass->at(1) > 85. &&
             ntuple->JetsAK8_prunedMass->at(1) < 135. 
             );
}

template<typename ntupleType> bool singleHiggsTagCut(ntupleType* ntuple ){
    return ntuple->JetsAK8_doubleBDiscriminator->size()>=2 && 
        ( (ntuple->JetsAK8_prunedMass->at(0) > 85. && 
           ntuple->JetsAK8_prunedMass->at(0) < 135. && 
           ntuple->JetsAK8_doubleBDiscriminator->at(0) > bbtagCut ) ||
          (ntuple->JetsAK8_prunedMass->at(1) > 85. && 
           ntuple->JetsAK8_prunedMass->at(1) < 135. && 
           ntuple->JetsAK8_doubleBDiscriminator->at(1) > bbtagCut ) );
}

template<typename ntupleType> bool doubleHiggsTagCut(ntupleType* ntuple ){
    return ntuple->JetsAK8_doubleBDiscriminator->size()>=2 &&
        ( ntuple->JetsAK8_prunedMass->at(0) > 85. && 
          ntuple->JetsAK8_prunedMass->at(0) < 135. && 
          ntuple->JetsAK8_doubleBDiscriminator->at(0) > bbtagCut &&
          ntuple->JetsAK8_prunedMass->at(1) > 85. && 
          ntuple->JetsAK8_prunedMass->at(1) < 135. && 
          ntuple->JetsAK8_doubleBDiscriminator->at(1) > bbtagCut ) ;
}

template<typename ntupleType> bool tagSR(ntupleType* ntuple, int i){
    if( ntuple->JetsAK8_doubleBDiscriminator->size() <= i || 
        ntuple->JetsAK8_prunedMass->size() <= i ) return false;
    return ( ntuple->JetsAK8_doubleBDiscriminator->at(i) > bbtagCut &&
             ntuple->JetsAK8_prunedMass->at(i) > 85. && 
             ntuple->JetsAK8_prunedMass->at(i) < 135. );
}

template<typename ntupleType> bool tagSB(ntupleType* ntuple, int i ){
    if( ntuple->JetsAK8_doubleBDiscriminator->size() <= i || 
        ntuple->JetsAK8_prunedMass->size() <= i ) return false;
    return ( ntuple->JetsAK8_doubleBDiscriminator->at(i) > bbtagCut && 
             (
              ( ntuple->JetsAK8_prunedMass->at(i) < 85. &&
                ntuple->JetsAK8_prunedMass->at(i) > 50. ) ||
              ( ntuple->JetsAK8_prunedMass->at(i) > 135. &&
                ntuple->JetsAK8_prunedMass->at(i) < 250. ) 
              ) 
             );
}

template<typename ntupleType> bool antitagSR(ntupleType* ntuple, int i){
        if( ntuple->JetsAK8_doubleBDiscriminator->size() <= i || 
        ntuple->JetsAK8_prunedMass->size() <= i ) return false;
    return ( ntuple->JetsAK8_doubleBDiscriminator->at(i) < bbtagCut &&
             ( ntuple->JetsAK8_prunedMass->at(i) > 85. &&
               ntuple->JetsAK8_prunedMass->at(i) < 135. ) );
}
        
template<typename ntupleType> bool antitagSB(ntupleType* ntuple, int i){
    if( ntuple->JetsAK8_doubleBDiscriminator->size() <= i || 
        ntuple->JetsAK8_prunedMass->size() <= i ) return false;
    return ( ntuple->JetsAK8_doubleBDiscriminator->at(i) < bbtagCut &&
             (
              ( ntuple->JetsAK8_prunedMass->at(i) < 85. &&
                ntuple->JetsAK8_prunedMass->at(i) > 50. ) ||
              ( ntuple->JetsAK8_prunedMass->at(i) > 135. &&
                ntuple->JetsAK8_prunedMass->at(i) < 250. ) 
              )
             );
}

template<typename ntupleType> bool antitagSRCut(ntupleType* ntuple){
    return ( antitagSR(ntuple,0)&&antitagSR(ntuple,1) );
}

template<typename ntupleType> bool antitagSBCut(ntupleType* ntuple){
    return ( ( antitagSB(ntuple,0)&&antitagSB(ntuple,1) ) ||
             ( antitagSB(ntuple,0)&&antitagSR(ntuple,1) ) ||
             ( antitagSR(ntuple,0)&&antitagSB(ntuple,1) ) );
}

template<typename ntupleType> bool tagSRCut(ntupleType* ntuple){
    return ( ( tagSR(ntuple,0)&&antitagSR(ntuple,1) ) || 
             ( antitagSR(ntuple,0)&&tagSR(ntuple,1) ) ) ;
}

template<typename ntupleType> bool tagSBCut(ntupleType* ntuple){
    return ( ( tagSB(ntuple,0)&&antitagSB(ntuple,1) ) ||
             ( tagSR(ntuple,0)&&antitagSB(ntuple,1) ) ||
             ( tagSB(ntuple,0)&&antitagSR(ntuple,1) ) ||
             ( antitagSB(ntuple,0)&&tagSB(ntuple,1) ) ||
             ( antitagSR(ntuple,0)&&tagSB(ntuple,1) ) ||
             ( antitagSB(ntuple,0)&&tagSR(ntuple,1) ) );

}

template<typename ntupleType> bool doubletagSRCut(ntupleType* ntuple){
    return ( tagSR(ntuple,0)&&tagSR(ntuple,1) );
}

template<typename ntupleType> bool doubletagSBCut(ntupleType* ntuple){
    return ( ( tagSB(ntuple,0)&&tagSB(ntuple,1) ) ||
             ( tagSB(ntuple,0)&&tagSR(ntuple,1) ) ||
             ( tagSR(ntuple,0)&&tagSB(ntuple,1) ) );
}

////////////////////////////////////////////////////////////////////////
// - - - - - - - - - - photon specializations - - - - - - - - - - - - //
////////////////////////////////////////////////////////////////////////
template<typename ntupleType> double fillPhotonPt(ntupleType* ntuple ){ 
    if( ntuple->Photons->size() == 0 )
        return -999.;
    else
        return ntuple->Photons->at(0).Pt();
}

template<typename ntupleType> bool singleHiggsTagLooseCut_photon(ntupleType* ntuple ){ 
  return ( ( ntuple->JetsAK8Clean_doubleBDiscriminator->at(0) > bbtagCut ) 
           && ( ntuple->JetsAK8Clean_doubleBDiscriminator->at(1) < bbtagCut ) ) || 
      ( ( ntuple->JetsAK8Clean_doubleBDiscriminator->at(0) < bbtagCut ) 
        && ( ntuple->JetsAK8Clean_doubleBDiscriminator->at(1) > bbtagCut ) );
}

template<typename ntupleType> bool antiTaggingLooseCut_photon(ntupleType* ntuple ){
    return ( ( ( ntuple->JetsAK8Clean_doubleBDiscriminator->at(0) < bbtagCut
               ) &&
             ( ntuple->JetsAK8Clean_doubleBDiscriminator->at(1) < bbtagCut 
               ) ) ) ;
}

template<typename ntupleType> bool doubleTaggingLooseCut_photon(ntupleType* ntuple ){
    return ( ntuple->JetsAK8Clean_doubleBDiscriminator->at(0) > bbtagCut && 
             ntuple->JetsAK8Clean_doubleBDiscriminator->at(1) > bbtagCut );
}

template<typename ntupleType> bool doubleMassCut_photon(ntupleType* ntuple ){
    return ( ntuple->JetsAK8Clean_prunedMass->at(0) > 85. &&
             ntuple->JetsAK8Clean_prunedMass->at(0) < 135. &&
             ntuple->JetsAK8Clean_prunedMass->at(1) > 85. &&
             ntuple->JetsAK8Clean_prunedMass->at(1) < 135. );
}

template<typename ntupleType> bool singleHiggsTagCut_photon(ntupleType* ntuple ){
    return ( (ntuple->JetsAK8Clean_prunedMass->at(0) > 85. && 
              ntuple->JetsAK8Clean_prunedMass->at(0) < 135. && 
              ntuple->JetsAK8Clean_doubleBDiscriminator->at(0) > bbtagCut ) ||
             (ntuple->JetsAK8Clean_prunedMass->at(1) > 85. && 
              ntuple->JetsAK8Clean_prunedMass->at(1) < 135. && 
              ntuple->JetsAK8Clean_doubleBDiscriminator->at(1) > bbtagCut ) );
}

template<typename ntupleType> bool doubleHiggsTagCut_photon(ntupleType* ntuple ){
    return ( ntuple->JetsAK8Clean_prunedMass->at(0) > 85. && 
             ntuple->JetsAK8Clean_prunedMass->at(0) < 135. && 
             ntuple->JetsAK8Clean_doubleBDiscriminator->at(0) > bbtagCut &&
             ntuple->JetsAK8Clean_prunedMass->at(1) > 85. && 
             ntuple->JetsAK8Clean_prunedMass->at(1) < 135. && 
             ntuple->JetsAK8Clean_doubleBDiscriminator->at(1) > bbtagCut ) ;
}

template<typename ntupleType> bool tagSR_photon(ntupleType* ntuple, int i){
    if( ntuple->JetsAK8Clean_doubleBDiscriminator->size() <= i || 
        ntuple->JetsAK8_prunedMass->size() <= i ) return false;
    return ( ntuple->JetsAK8Clean_doubleBDiscriminator->at(i) > bbtagCut &&
             ntuple->JetsAK8Clean_prunedMass->at(i) > 85. && 
             ntuple->JetsAK8Clean_prunedMass->at(i) < 135. );
}

template<typename ntupleType> bool tagSB_photon(ntupleType* ntuple, int i ){
    if( ntuple->JetsAK8Clean_doubleBDiscriminator->size() <= i || 
        ntuple->JetsAK8Clean_prunedMass->size() <= i ) return false;
    return ( ntuple->JetsAK8Clean_doubleBDiscriminator->at(i) > bbtagCut && 
             (
              ( ntuple->JetsAK8Clean_prunedMass->at(i) < 85. &&
                ntuple->JetsAK8Clean_prunedMass->at(i) > 50. ) ||
              ( ntuple->JetsAK8Clean_prunedMass->at(i) > 135. &&
                ntuple->JetsAK8Clean_prunedMass->at(i) < 250. ) 
              ) 
             );
}

template<typename ntupleType> bool antitagSR_photon(ntupleType* ntuple, int i){
        if( ntuple->JetsAK8Clean_doubleBDiscriminator->size() <= i || 
        ntuple->JetsAK8Clean_prunedMass->size() <= i ) return false;
    return ( ntuple->JetsAK8Clean_doubleBDiscriminator->at(i) < bbtagCut &&
             ( ntuple->JetsAK8Clean_prunedMass->at(i) > 85. &&
               ntuple->JetsAK8Clean_prunedMass->at(i) < 135. ) );
}
        
template<typename ntupleType> bool antitagSB_photon(ntupleType* ntuple, int i){
    if( ntuple->JetsAK8Clean_doubleBDiscriminator->size() <= i || 
        ntuple->JetsAK8Clean_prunedMass->size() <= i ) return false;
    return ( ntuple->JetsAK8Clean_doubleBDiscriminator->at(i) < bbtagCut &&
             (
              ( ntuple->JetsAK8Clean_prunedMass->at(i) < 85. &&
                ntuple->JetsAK8Clean_prunedMass->at(i) > 50. ) ||
              ( ntuple->JetsAK8Clean_prunedMass->at(i) > 135. &&
                ntuple->JetsAK8Clean_prunedMass->at(i) < 250. ) 
              )
             );
}

template<typename ntupleType> bool antitagSRCut_photon(ntupleType* ntuple){
    return ( antitagSR_photon(ntuple,0)&&antitagSR_photon(ntuple,1) );
}

template<typename ntupleType> bool antitagSBCut_photon(ntupleType* ntuple){
    return ( ( antitagSB_photon(ntuple,0)&&antitagSB_photon(ntuple,1) ) ||
             ( antitagSB_photon(ntuple,0)&&antitagSR_photon(ntuple,1) ) ||
             ( antitagSR_photon(ntuple,0)&&antitagSB_photon(ntuple,1) ) );
}

template<typename ntupleType> bool tagSRCut_photon(ntupleType* ntuple){
    return ( ( tagSR_photon(ntuple,0)&&antitagSR_photon(ntuple,1) ) || 
             ( antitagSR_photon(ntuple,0)&&tagSR_photon(ntuple,1) ) ) ;
}

template<typename ntupleType> bool tagSBCut_photon(ntupleType* ntuple){
    return ( ( tagSB_photon(ntuple,0)&&antitagSB_photon(ntuple,1) ) ||
             ( tagSR_photon(ntuple,0)&&antitagSB_photon(ntuple,1) ) ||
             ( tagSB_photon(ntuple,0)&&antitagSR_photon(ntuple,1) ) ||
             ( antitagSB_photon(ntuple,0)&&tagSB_photon(ntuple,1) ) ||
             ( antitagSR_photon(ntuple,0)&&tagSB_photon(ntuple,1) ) ||
             ( antitagSB_photon(ntuple,0)&&tagSR_photon(ntuple,1) ) );

}

template<typename ntupleType> bool doubletagSRCut_photon(ntupleType* ntuple){
    return ( tagSR_photon(ntuple,0)&&tagSR_photon(ntuple,1) );
}

template<typename ntupleType> bool doubletagSBCut_photon(ntupleType* ntuple){
    return ( ( tagSB_photon(ntuple,0)&&tagSB_photon(ntuple,1) ) ||
             ( tagSB_photon(ntuple,0)&&tagSR_photon(ntuple,1) ) ||
             ( tagSR_photon(ntuple,0)&&tagSB_photon(ntuple,1) ) );
}

/////////////////////////////////////////////////
// - - - - - - - Trigger Cuts - - - - - - - -  //
/////////////////////////////////////////////////
template<typename ntupleType> bool signalTriggerCut(ntupleType* ntuple){
    return ntuple->TriggerPass->at(42) == 1 || ntuple->TriggerPass->at(43) == 1 || ntuple->TriggerPass->at(44) == 1 || ntuple->TriggerPass->at(45) == 1 ; 
}

template<typename ntupleType> bool singleMuTriggerCut(ntupleType* ntuple){
    return ( ntuple->TriggerPass->at(20)==1 || ntuple->TriggerPass->at(21)==1 || ntuple->TriggerPass->at(22)==1 || ntuple->TriggerPass->at(23)==1 || ntuple->TriggerPass->at(24)==1 || ntuple->TriggerPass->at(28)==1 || ntuple->TriggerPass->at(29)==1 );
}

template<typename ntupleType> bool singleEleTriggerCut(ntupleType* ntuple){
    return ntuple->TriggerPass->at(6) == 1 || ntuple->TriggerPass->at(7) == 1 || ntuple->TriggerPass->at(8) == 1 || ntuple->TriggerPass->at(9) == 1 || ntuple->TriggerPass->at(10) == 1 || ntuple->TriggerPass->at(11) == 1 || ntuple->TriggerPass->at(12) == 1 || ntuple->TriggerPass->at(13) == 1 || ntuple->TriggerPass->at(14) == 1 ;
}

template<typename ntupleType> bool lowDphiTriggerCut(ntupleType* ntuple){
    return ntuple->TriggerPass->at(42) == 1 || ntuple->TriggerPass->at(43) == 1 || ntuple->TriggerPass->at(44) == 1 || ntuple->TriggerPass->at(45) == 1 ; 
}

template<typename ntupleType> bool photonTriggerCut(ntupleType* ntuple){
    return ntuple->TriggerPass->at(53) == 1 || ntuple->TriggerPass->at(54) == 1 ; // || ntuple->TriggerPass->at(51) || ntuple->TriggerPass->at(52);
}

// print out trigger name
/*vector<string> TriggerNames;
    int n = ntuple->TriggerNames.size();
    for(int i=0; i<n; i++){
        string TName = TriggerNames[i];
        std::cout<<"Trigger Names: "<<TName<<std::endl;
    }
*/
// end of Trigger name printout

template<typename ntupleType> int getClosestGenHiggses(ntupleType* ntuple, double jeteta, double jetphi){
    float dRMin=999999.;
    for( int i=0 ; i < ntuple->GenParticles->size() ; i++ ){
        if( ntuple->GenParticles_PdgId->at(i) == 25 &&
            ntuple->GenParticles_ParentId->at(i) == 1000023 &&
            ntuple->GenParticles_Status->at(i) == 22 ){
                float dR=sqrt((jeteta-ntuple->GenParticles->at(i).Eta())*(jeteta-ntuple->GenParticles->at(i).Eta()) +(jetphi-ntuple->GenParticles->at(i).Phi())*(jetphi-ntuple->GenParticles->at(i).Phi()));
                if(dRMin>dR)dRMin=dR;
                }
    }
    return dRMin;
}
template<typename ntupleType> int getClosestGenZ(ntupleType* ntuple, double jeteta, double jetphi){
    float dRMin=999999.;
    for( int i=0 ; i < ntuple->GenParticles->size() ; i++ ){
        if( ntuple->GenParticles_PdgId->at(i) == 23 &&
            ntuple->GenParticles_ParentId->at(i) == 1000023 &&
            ntuple->GenParticles_Status->at(i) == 22 ){
                float dR=sqrt((jeteta-ntuple->GenParticles->at(i).Eta())*(jeteta-ntuple->GenParticles->at(i).Eta()) +(jetphi-ntuple->GenParticles->at(i).Phi())*(jetphi-ntuple->GenParticles->at(i).Phi()));
                if(dRMin>dR)dRMin=dR;
                }
    }
    return dRMin;
}
template<typename ntupleType>double ResolutionSmear(ntupleType* ntuple, int j,unsigned int seed, bool SFUp=false){
TRandom3 rand(seed);
double sigmaJMR=0;
if(ntuple->JetsAK8_NumBhadrons->at(j)!=2)return ntuple->JetsAK8_prunedMass->at(j);
if(ntuple->JetsAK8->at(j).Pt()>300. && ntuple->JetsAK8->at(j).Pt()<=600.)sigmaJMR=12.55;
if(ntuple->JetsAK8->at(j).Pt()>600. && ntuple->JetsAK8->at(j).Pt()<=800.)sigmaJMR=10.24;
if(ntuple->JetsAK8->at(j).Pt()>800. && ntuple->JetsAK8->at(j).Pt()<=1000.)sigmaJMR= 9.85;
if(ntuple->JetsAK8->at(j).Pt()>1000.)sigmaJMR=9.44;
sigmaJMR=sigmaJMR/110.;
double sigmaJMRSF=1.23;
if(SFUp)sigmaJMRSF=sigmaJMRSF-0.18;
double dRHiggs=getClosestGenHiggses(ntuple, ntuple->JetsAK8->at(j).Eta(), ntuple->JetsAK8->at(j).Phi());
double dRZ=getClosestGenZ(ntuple, ntuple->JetsAK8->at(j).Eta(), ntuple->JetsAK8->at(j).Phi());
if(dRHiggs>dRZ){
if(ntuple->JetsAK8->at(j).Pt()>300. && ntuple->JetsAK8->at(j).Pt()<=600.)sigmaJMR=8.27;
if(ntuple->JetsAK8->at(j).Pt()>600. && ntuple->JetsAK8->at(j).Pt()<=800.)sigmaJMR=7.13;
if(ntuple->JetsAK8->at(j).Pt()>800. && ntuple->JetsAK8->at(j).Pt()<=1000.)sigmaJMR=6.83;
if(ntuple->JetsAK8->at(j).Pt()>1000.)sigmaJMR=6.90;
sigmaJMR=sigmaJMR/83.;
}
double gausSmear=rand.Gaus(0, sigmaJMR)*sqrt((sigmaJMRSF*sigmaJMRSF -1));
double smearmass=(gausSmear+1.)*ntuple->JetsAK8_prunedMass->at(j);
return smearmass;
}
template<typename ntupleType>double SignalISRCorrection(ntupleType* ntuple){
float ISRWeights[7]={1.0, 0.920, 0.821, 0.715, 0.662, 0.561,0.511};
if(ntuple->NJetsISR==0) return ISRWeights[0];
if(ntuple->NJetsISR==1) return ISRWeights[1];
if(ntuple->NJetsISR==2) return ISRWeights[2];
if(ntuple->NJetsISR==3) return ISRWeights[3];
if(ntuple->NJetsISR==4) return ISRWeights[4];
if(ntuple->NJetsISR==5) return ISRWeights[5];
if(ntuple->NJetsISR>=6) return ISRWeights[6];
}
template<typename ntupleType> double doubleBSF(ntupleType* ntuple,int j){
double doubleBSF=1.0;
if(ntuple->JetsAK8->at(j).Pt()>300. && ntuple->JetsAK8->at(j).Pt()<=350)doubleBSF=0.96;
if(ntuple->JetsAK8->at(j).Pt()>350. && ntuple->JetsAK8->at(j).Pt()<=430)doubleBSF=1.00;
if(ntuple->JetsAK8->at(j).Pt()>430.)doubleBSF=1.01;
return doubleBSF;
}
template<typename ntupleType> double doubleBSFUp(ntupleType* ntuple,int j){
double doubleBSF=1.0;
if(ntuple->JetsAK8->at(j).Pt()>300. && ntuple->JetsAK8->at(j).Pt()<=350)doubleBSF=0.96+0.03;
if(ntuple->JetsAK8->at(j).Pt()>350. && ntuple->JetsAK8->at(j).Pt()<=430)doubleBSF=1.00+0.024;
if(ntuple->JetsAK8->at(j).Pt()>430. && ntuple->JetsAK8->at(j).Pt()<840)doubleBSF=1.01+0.02;
if(ntuple->JetsAK8->at(j).Pt()>840)doubleBSF=1.01+0.04;
return doubleBSF;
}
template<typename ntupleType> double doubleBSFDn(ntupleType* ntuple,int j){
double doubleBSF=1.0;
if(ntuple->JetsAK8->at(j).Pt()>300. && ntuple->JetsAK8->at(j).Pt()<=350)doubleBSF=0.96-0.02;
if(ntuple->JetsAK8->at(j).Pt()>350. && ntuple->JetsAK8->at(j).Pt()<=430)doubleBSF=1.00-0.043;
if(ntuple->JetsAK8->at(j).Pt()>430. && ntuple->JetsAK8->at(j).Pt()<840)doubleBSF=1.01-0.04;
if(ntuple->JetsAK8->at(j).Pt()>840)doubleBSF=1.01-0.08;
return doubleBSF;
}
