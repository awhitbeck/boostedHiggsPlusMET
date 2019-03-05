#include "TString.h"
#include "TChain.h"
#include "TH1F.h"
#include "TROOT.h"
#include "THStack.h"
#include "TPad.h"

#include <vector>
#include <map>
#include <iostream>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <cassert>
#include "plotterUtils.cc"
#include "skimSamples.cc"
#include "definitions.cc"
#include "RA2bTree.cc"
#include "TriggerEfficiencySextet.cc"

using namespace std;

int main(int argc, char** argv){
  
    skimSamples::system sys=skimSamples::kLPC;
    if( argc > 3 ) 
      sys=skimSamples::system(atoi(argv[3]));

    int MAX_EVENTS = 99999999;
    if( argc > 2 )
        MAX_EVENTS = atoi(argv[2]);
    
    assert(argc > 1);
    TString selection_label = argv[1];
    bool (*selectionFunc)(RA2bTree*);
    //if( selection_label == "baselineNoVBF" ){
    if( selection_label == "ZNoSelection_Test_V16"){
    //if( selection_label == "ZNoSelection-Test"){
        selectionFunc = baselineCutNoVBF;
    }else if( selection_label == "baselineVBF" ){
        selectionFunc = baselineCut;
    }else if( selection_label == "ZSRNoVBF"){
        selectionFunc = ZSignalRegionCutNoVBF;
    }else if( selection_label == "ZSRVBF"){
        selectionFunc = ZSignalRegionCut;
    //}else if( selection_label == "ZSRHPNoVBF"){
    }else if( selection_label == "ZSRHPNoVBF_SigBkg"){
        selectionFunc = ZSignalRegionHPCutNoVBF;
    }else if( selection_label == "ZSRHPVBF"){
        selectionFunc = ZSignalRegionHPCut;
    //}else if( selection_label == "ZSRHPVBF-dEta5p5-sig"){
    //}else if( selection_label == "ZSRHPVBF_Loose"){
    //}else if( selection_label == "ZSRHPVBF_Loose_Sig_Unweighted"){
    //}else if( selection_label == "ZSRHPVBF-TestFwdMjj"){
    }else if( selection_label == "ZSRHPVBF-TightMjjdEta"){
        selectionFunc = ZSignalRegionHPCut;
    }else if( selection_label == "ZSRHPVBF-Test1"){
        selectionFunc = ZSignalRegionHPCut;
    }else if( selection_label == "ZSRHPVBFEta"){
        selectionFunc = ZHPEtaCut;
    }else if( selection_label == "ZSRLPNoVBF"){
        selectionFunc = ZSignalRegionLPCutNoVBF;
    }else if( selection_label == "ZSRLPVBF"){
        selectionFunc = ZSignalRegionLPCut;
    //}else if( selection_label == "ZSBNoVBF" ){
    }else if( selection_label == "ZSBNoVBF_Test" ){
        selectionFunc = ZSidebandnoVBFCut;
    }else if( selection_label == "ZSBVBF" ){
        selectionFunc = ZSidebandCut;
    }else if( selection_label == "ZSBHPNoVBF" ){
    //}else if( selection_label == "ZSBHPNoVBF_SigBkg" ){
        selectionFunc = ZSidebandHPCutnoVBF;
    }else if( selection_label == "ZSBHPVBF" ){
    //}else if( selection_label == "ZSBHPVBF_Loose" ){
    //}else if( selection_label == "ZSBHPVBF_Loose_Sig" ){
    //}else if( selection_label == "ZSBHPVBF_Loose_debug" ){
        selectionFunc = ZSidebandHPCut;
    }else if( selection_label == "ZSBLPNoVBF"){
        selectionFunc = ZSidebandLPCutnoVBF;
    }else if( selection_label == "ZSBLPVBF"){
        selectionFunc = ZSidebandLPCut;

    }else
        assert(0);

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");
  
    skimSamples skims(skimSamples::kSignal,sys);
    typedef plot<RA2bTree> plot;

    plot NVtxplot(*fillNVtx<RA2bTree>,"NVtx_"+selection_label,"NVtx",80,0.5,80.5);//1 bin
    plot METplot(*fillMET<RA2bTree>,"MET_"+selection_label,"MET [GeV]",56,200.,3000.);//50 GeV bin
    plot MET2plot(*fillMET<RA2bTree>,"MET2_"+selection_label,"MET [GeV]",60,0.,3000.);//50 GeV bin
    plot MET1plot(*fillMET<RA2bTree>,"MET1_"+selection_label,"MET [GeV]",25,200.,1200.);//40 GeV bin
    plot HTplot(*fillHT<RA2bTree>,"HT_"+selection_label,"H_{T} [GeV]",30,300,3300.);
    plot NJetsplot(*fillNJets<RA2bTree>,"NJets_"+selection_label,"n_{jets}",15,0.5,15.5);
    plot NAK8Jetsplot(*fillNJets<RA2bTree>,"NAK8Jets_"+selection_label,"nAK8_{jets}",15,0.5,15.5);

    // AK4 Jets plots: pt, eta, phi, Nemf
    plot AK4j1pt_plot(*fillJetPt1<RA2bTree>,"AK4j1pt_plot_"+selection_label,"pt_{j1}^{AK4} [GeV]",50,0,1500);
    plot AK4j2pt_plot(*fillJetPt2<RA2bTree>,"AK4j2pt_plot_"+selection_label,"pt_{j2}^{AK4} [GeV]",50,0,1500);
    plot AK4j3pt_plot(*fillJetPt3<RA2bTree>,"AK4j3pt_plot_"+selection_label,"pt_{j3}^{AK4} [GeV]",50,0,1500);
    plot AK4j4pt_plot(*fillJetPt4<RA2bTree>,"AK4j4pt_plot_"+selection_label,"pt_{j4}^{AK4} [GeV]",50,0,1500);

    plot AK4j1Eta1_plot(*fillJetEta1<RA2bTree>,"AK4j1Eta1_plot_"+selection_label,"#eta_{j1}^{AK4} 1",100,-5.,5.);
    plot AK4j1Eta_plot(*fillJetEta1<RA2bTree>,"AK4j1Eta_plot_"+selection_label,"#eta_{j1}^{AK4}",50,-5.,5.);
    plot AK4j2Eta_plot(*fillJetEta2<RA2bTree>,"AK4j2Eta_plot_"+selection_label,"#eta_{j2}^{AK4}",50,-5.,5.);
    plot AK4j3Eta_plot(*fillJetEta3<RA2bTree>,"AK4j3Eta_plot_"+selection_label,"#eta_{j3}^{AK4}",50,-5.,5.);
    plot AK4j4Eta_plot(*fillJetEta4<RA2bTree>,"AK4j4Eta_plot_"+selection_label,"#eta_{j4}^{AK4}",50,-5.,5.);

    plot AK4j1Phi_plot(*fillJetPhi1<RA2bTree>,"AK4j1Phi_plot_"+selection_label,"#phi_{j1}^{AK4}",70,-3.5,3.5);
    plot AK4j2Phi_plot(*fillJetPhi2<RA2bTree>,"AK4j2Phi_plot_"+selection_label,"#phi_{j2}^{AK4}",70,-3.5,3.5);
    plot AK4j3Phi_plot(*fillJetPhi3<RA2bTree>,"AK4j3Phi_plot_"+selection_label,"#phi_{j3}^{AK4}",70,-3.5,3.5);
    plot AK4j4Phi_plot(*fillJetPhi4<RA2bTree>,"AK4j4Phi_plot_"+selection_label,"#phi_{j4}^{AK4}",70,-3.5,3.5);

    plot AK4j1NEMF_plot(*fillJetNEMF1<RA2bTree>,"AK4j1NEMF_plot_"+selection_label,"NEMF_{j1}^{AK4}",20,0.,1.);
    plot AK4j2NEMF_plot(*fillJetNEMF2<RA2bTree>,"AK4j2NEMF_plot_"+selection_label,"NEMF_{j2}^{AK4}",20,0.,1.);
    plot AK4j3NEMF_plot(*fillJetNEMF3<RA2bTree>,"AK4j3NEMF_plot_"+selection_label,"NEMF_{j3}^{AK4}",20,0.,1.);
    plot AK4j4NEMF_plot(*fillJetNEMF4<RA2bTree>,"AK4j4NEMF_plot_"+selection_label,"NEMF_{j4}^{AK4}",20,0.,1.);

   // 2D plot for AK4 Objects: 
    plot AK4j1ptvsEtaplot(*fillJetEta1<RA2bTree>,*fillJetPt1<RA2bTree>,"AK4j1ptvsEta_"+selection_label,"#eta_{j1}^{AK4}","pt_{j1}^{AK4} [GeV]",50,-5.,5.,50,0.,1500.); 
/*    plot AK4j1PhivsEtaplot(*fillJetEta1<RA2bTree>,*fillJetPhi1<RA2bTree>,"AK4j1PhivsEta_"+selection_label,"#eta_{j1}^{AK4}","#phi_{j1}^{AK4}",50,-5.,5.,70,-3.5,3.5); 
    plot AK4j1NEMFvsEtaplot(*fillJetEta1<RA2bTree>,*fillJetNEMF1<RA2bTree>,"AK4j1NEMFvsEta_"+selection_label,"#eta_{j1}^{AK4}","NEMF_{j1}^{AK4}",50,-5.,5.,20,0.,1.); 
    plot AK4j1NEMFvsPtplot(*fillJetPt1<RA2bTree>,*fillJetNEMF1<RA2bTree>,"AK4j1NEMFvsPt_"+selection_label,"pt_{j1}^{AK4} [GeV]","NEMF_{j1}^{AK4}",50,0.,1500.,20,0.,1.); 

    plot AK4j2ptvsEtaplot(*fillJetEta2<RA2bTree>,*fillJetPt2<RA2bTree>,"AK4j2ptvsEta_"+selection_label,"#eta_{j2}^{AK4}","pt_{j2}^{AK4} [GeV]",50,-5.,5.,50,0.,1500.); 
    plot AK4j2PhivsEtaplot(*fillJetEta2<RA2bTree>,*fillJetPhi2<RA2bTree>,"AK4j2PhivsEta_"+selection_label,"#eta_{j2}^{AK4}","#phi_{j2}^{AK4}",50,-5.,5.,70,-3.5,3.5); 
    plot AK4j2NEMFvsEtaplot(*fillJetEta2<RA2bTree>,*fillJetNEMF2<RA2bTree>,"AK4j2NEMFvsEta_"+selection_label,"#eta_{j2}^{AK4}","NEMF_{j2}^{AK4}",50,-5.,5.,20,0.,1.); 
    plot AK4j2NEMFvsPtplot(*fillJetPt2<RA2bTree>,*fillJetNEMF2<RA2bTree>,"AK4j2NEMFvsPt_"+selection_label,"pt_{j2}^{AK4} [GeV]","NEMF_{j2}^{AK4}",50,0.,1500.,20,0.,1.); 
*/

    plot DeltaPhi1plot(*fillDeltaPhi1<RA2bTree>,"DeltaPhi1_"+selection_label,"#Delta#Phi_{1}",20,0,3.1415);
    plot DeltaPhi2plot(*fillDeltaPhi2<RA2bTree>,"DeltaPhi2_"+selection_label,"#Delta#Phi_{2}",20,0,3.1415);
    plot DeltaPhi3plot(*fillDeltaPhi3<RA2bTree>,"DeltaPhi3_"+selection_label,"#Delta#Phi_{3}",20,0,3.1415);
    plot DeltaPhi4plot(*fillDeltaPhi4<RA2bTree>,"DeltaPhi4_"+selection_label,"#Delta#Phi_{4}",20,0,3.1415);
    plot DeltaPhiAK8JMETplot(*fillDeltaPhiAK8JMET<RA2bTree>,"DeltaPhiAK8JMET_"+selection_label,"#Delta#Phi(AK8J,MET)",20,0,3.1415);

    plot J1pt_Massplot(*fillLeadingJetMass<RA2bTree>,"J1pt_Mass_"+selection_label,"m_{J} [GeV]",54,30.,300.);//5 Gev bin
    plot J1_SDMassplot(*fillLeadingJetSDMass<RA2bTree>,"J1_SDMass_"+selection_label,"SoftDrop m_{J} [GeV]",54,30.,300.);//5 Gev bin
    // Turn on the line below for SR only
    plot J1pt_Mass1plot(*fillLeadingJetMass<RA2bTree>,"J1pt_Mass1_"+selection_label,"m_{J} [GeV]",14,50.,120.);//5 Gev bin
    plot J1pt_Tau21plot(*fillLeadingTau21<RA2bTree>,"J1pt_Tau21_"+selection_label,"#tau_{21}",20,0.,1.);
    plot DDT_Tau21plot(*fillDDT<RA2bTree>,"DDT_Tau21_"+selection_label,"DDT",20,0.,1.);

    plot GMassvsZMTplot(*fillGMass<RA2bTree>,*fillZMT<RA2bTree>,"GMassvsZMT_"+selection_label,"M_{G} [GeV]","MT_{Z} [GeV]",25,500.,3000.,45,500.,5000.); // 100 GeV bin
    plot GMassplot(*fillGMass<RA2bTree>,"GMass_"+selection_label,"M_{G} [GeV]",25,500.,3000.); // 100 GeV bin
    plot GMass1plot(*fillGMass<RA2bTree>,"GMass1_"+selection_label,"M_{G} [GeV]",70,0.,7000.); // 100 GeV bin
    plot GMass2plot(*fillGMass<RA2bTree>,"GMass2_"+selection_label,"M_{G} [GeV]",65,500.,7000.); // 100 GeV bin
    plot ZMTplot(*fillZMT<RA2bTree>,"ZMT_"+selection_label,"MT_{Z} [GeV]",45,500.,5000.); // 100 GeV bin
    plot ZMT1plot(*fillZMT<RA2bTree>,"ZMT1_"+selection_label,"MT_{Z} [GeV]",25,500.,3000.); // 100 GeV bin
    plot ZMT2plot(*fillZMT<RA2bTree>,"ZMT2_"+selection_label,"MT_{Z} [GeV]",50,0.,5000.); // 100 GeV bin
    plot ZMT3plot(*fillZMT<RA2bTree>,"ZMT3_"+selection_label,"MT_{Z} [GeV]",30,2000.,5000.); // 100 GeV bin
    plot ZMT4plot(*fillZMT<RA2bTree>,"ZMT4_"+selection_label,"MT_{Z} [GeV]",19,100.,2000.); // 100 GeV bin
/*    plot MZ510MTplot(*fillMZ510MT<RA2bTree>,"MZ510MT_"+selection_label,"m_{J} for MT [0.5-1 Tev] [GeV]",54,30.,300.); // 5 GeV bin
    plot MZ1015MTplot(*fillMZ1015MT<RA2bTree>,"MZ1015MT_"+selection_label,"m_{J} for MT [1-1.5 TeV] [GeV]",54,30.,300.); // 5 GeV bin
    plot MZ1520MTplot(*fillMZ1520MT<RA2bTree>,"MZ1520MT_"+selection_label,"m_{J} for MT [1.5-2 TeV] [GeV]",54,30.,300.); // 5 GeV bin
    plot MZ2025MTplot(*fillMZ2025MT<RA2bTree>,"MZ2025MT_"+selection_label,"m_{J} for MT [2-2.5 TeV] [GeV]",54,30.,300.); // 5 GeV bin
    plot MZ2530MTplot(*fillMZ2530MT<RA2bTree>,"MZ2530MT_"+selection_label,"m_{J} for MT [2.5-3.0 TeV] [GeV]",54,30.,300.); // 5 GeV bin
  */  plot J1pt_Ptplot(*fillLeadingJetPt<RA2bTree>,"J1pt_Pt_"+selection_label,"p_{T,J} [GeV]",56,200.,3000.); //50 GeV bin;
    plot J1pt_Pt1plot(*fillLeadingJetPt<RA2bTree>,"J1pt_Pt1_"+selection_label,"p_{T,J} [GeV]",60,0.,3000.); //50 GeV bin;
    //plot J1pt_Ptplot(*fillLeadingJetPt<RA2bTree>,"J1pt_Pt_"+selection_label,"p_{T,J} [GeV]",36,200.,2000.); //50 GeV bin;
    //plot J1pt_Etaplot(*fillLeadingJetEta<RA2bTree>,"J1pt_Eta_"+selection_label,"#eta_{AK8J} [GeV]",30,-3.,3.); //50 GeV bin;
    plot J1pt_Etaplot(*fillLeadingJetEta<RA2bTree>,"J1pt_Eta_"+selection_label,"#eta_{AK8J} [GeV]",50,-5.,5.); //50 GeV bin;
    plot J1pt_Eta1plot(*fillLeadingJetEta<RA2bTree>,"J1pt_Eta1_"+selection_label,"#eta_{AK8J} [GeV]",20,-2.,2.); //0.2 GeV bin;

    plot VBFmjj_plot(*fillVBF_Mjj<RA2bTree>,"VBFmjj_plot_"+selection_label,"m_{jj}^{VBF} [GeV]",40,0,4000);
    plot VBFptjj_plot(*fillVBF_Ptjj<RA2bTree>,"VBFptjj_plot_"+selection_label,"pt_{jj}^{VBF} [GeV]",40,0,4000);
    plot VBFj1pt_plot(*fillVBF_j1Pt<RA2bTree>,"VBFj1pt_plot_"+selection_label,"pt_{j1}^{VBF} [GeV]",50,0,1500);
    plot VBFj2pt_plot(*fillVBF_j2Pt<RA2bTree>,"VBFj2pt_plot_"+selection_label,"pt_{j2}^{VBF} [GeV]",50,0,1500);
    plot VBFdEta_plot(*fillVBF_dEta<RA2bTree>,"VBFdEta_plot_"+selection_label,"#Delta#eta^{VBF}",20,0,10);
    plot VBFdPhi_plot(*fillVBF_dPhi<RA2bTree>,"VBFdPhi_"+selection_label,"#Delta#Phi VBF(j1,j2)",20,0,3.1415);
    plot VBFj1Eta_plot(*fillVBF_j1Eta<RA2bTree>,"VBFj1Eta_plot_"+selection_label,"#eta_{j1}^{VBF}",50,-5.,5.);
    plot VBFj2Eta_plot(*fillVBF_j2Eta<RA2bTree>,"VBFj2Eta_plot_"+selection_label,"#eta_{j2}^{VBF}",50,-5.,5.);
    plot VBFj1Phi_plot(*fillVBF_j1Phi<RA2bTree>,"VBFj1Phi_plot_"+selection_label,"#Phi_{j1}^{VBF}",40,-3.1415,3.1415);
    plot VBFj2Phi_plot(*fillVBF_j2Phi<RA2bTree>,"VBFj2Phi_plot_"+selection_label,"#Phi_{j2}^{VBF}",40,-3.1415,3.1415);
    plot VBFj1j2Eta_plot(*fillVBF_j1j2Eta<RA2bTree>,"VBFj1j2Eta_plot_"+selection_label,"#eta_{j1.j2}^{VBF}",100,-25,25);


    vector<plot> plots;
    plots.push_back(NVtxplot);
    plots.push_back(METplot);
    plots.push_back(MET1plot);
    plots.push_back(MET2plot);
    plots.push_back(HTplot);
    plots.push_back(GMassvsZMTplot);

    plots.push_back(AK4j1pt_plot);
    plots.push_back(AK4j2pt_plot);
    plots.push_back(AK4j3pt_plot);
    plots.push_back(AK4j4pt_plot);

    plots.push_back(AK4j1Eta1_plot);
    plots.push_back(AK4j1Eta_plot);
    plots.push_back(AK4j2Eta_plot);
    plots.push_back(AK4j3Eta_plot);
    plots.push_back(AK4j4Eta_plot);

    plots.push_back(AK4j1Phi_plot);
    plots.push_back(AK4j2Phi_plot);
    plots.push_back(AK4j3Phi_plot);
    plots.push_back(AK4j4Phi_plot);

    plots.push_back(AK4j1NEMF_plot);
    plots.push_back(AK4j2NEMF_plot);
    plots.push_back(AK4j3NEMF_plot);
    plots.push_back(AK4j4NEMF_plot);

    plots.push_back(AK4j1ptvsEtaplot);   
/*    plots.push_back(AK4j1PhivsEtaplot);  
    plots.push_back(AK4j1NEMFvsEtaplot); 
    plots.push_back(AK4j1NEMFvsPtplot);   

    plots.push_back(AK4j2ptvsEtaplot  );
    plots.push_back(AK4j2PhivsEtaplot );
    plots.push_back(AK4j2NEMFvsEtaplot);
    plots.push_back(AK4j2NEMFvsPtplot ); 
*/
    plots.push_back(GMassplot);
    plots.push_back(GMass1plot);
    plots.push_back(GMass2plot);
    plots.push_back(ZMTplot);
    plots.push_back(ZMT1plot);
    plots.push_back(ZMT2plot);
    plots.push_back(ZMT3plot);
    plots.push_back(ZMT4plot);
    /*plots.push_back(MZ510MTplot);
    plots.push_back(MZ1015MTplot);
    plots.push_back(MZ1520MTplot);
    plots.push_back(MZ2025MTplot);
    plots.push_back(MZ2530MTplot);
    */plots.push_back(NJetsplot);
    plots.push_back(NAK8Jetsplot);

    plots.push_back(DeltaPhi1plot);
    plots.push_back(DeltaPhi2plot);
    plots.push_back(DeltaPhi3plot);
    plots.push_back(DeltaPhi4plot);
    plots.push_back(DeltaPhiAK8JMETplot);

    plots.push_back(J1_SDMassplot);
    plots.push_back(J1pt_Massplot);
    plots.push_back(J1pt_Mass1plot);
    plots.push_back(J1pt_Tau21plot);
    plots.push_back(DDT_Tau21plot);
    plots.push_back(J1pt_Ptplot);
    plots.push_back(J1pt_Pt1plot);
    plots.push_back(J1pt_Etaplot);
    plots.push_back(J1pt_Eta1plot);

    plots.push_back(VBFmjj_plot);
    plots.push_back(VBFdEta_plot);
    plots.push_back(VBFdPhi_plot);
    plots.push_back(VBFptjj_plot);
    plots.push_back(VBFj1pt_plot);
    plots.push_back(VBFj2pt_plot);
    plots.push_back(VBFj1Eta_plot);
    plots.push_back(VBFj2Eta_plot);
    plots.push_back(VBFj1Phi_plot);
    plots.push_back(VBFj2Phi_plot);
    plots.push_back(VBFj1j2Eta_plot);

    // background MC samples
    for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

        RA2bTree* ntuple = skims.ntuples[iSample];

        for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
            plots[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plots[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        }

        int numEvents = ntuple->fChain->GetEntries();
        ntupleBranchStatus<RA2bTree>(ntuple);
        TString filename;
        double weight = 0.;
        for( int iEvt = 0 ; iEvt < min(MAX_EVENTS,numEvents) ; iEvt++ ){
        //for( int iEvt = 0 ; iEvt < min(10,numEvents) ; iEvt++ ){
            ntuple->GetEntry(iEvt);
            if( iEvt % 1000000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;

            filename = ntuple->fChain->GetFile()->GetName();
            if( ( filename.Contains("SingleLept") || filename.Contains("DiLept") ) && ntuple->madHT>600. )continue;
            if(! selectionFunc(ntuple) ) continue;

            // print out trigger name
            /*
            int n = ntuple->TriggerNames->size();
            for(int i=0; i<n; i++){
                std::cout<<"Trigger Names: "<<ntuple->TriggerNames->at(i)<<std::endl;
            }
            */       
            // end of Trigger name printout
            // ---------- custom weights -----------
            std::vector<double> EfficiencyCenterUpDown = Eff_MetMhtSextetReal_CenterUpDown(ntuple->HT, ntuple->MHT, ntuple->NJets);
            weight = ntuple->Weight*lumi*customPUweights(ntuple)*EfficiencyCenterUpDown[0];
            if( skims.sampleName[iSample] == "TT" )
                weight *= ISRweights(ntuple);
            if( skims.sampleName[iSample] == "WJets" ){
                weight *= WJetsNLOWeights(ntuple);
            }
            if( skims.sampleName[iSample] == "ZJets" ){
                weight *= ZJetsNLOWeights(ntuple);
            }
            // ------------ end weights -------------
            for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++ ){
                plots[iPlot].fill(ntuple,weight);
            }
        }
    }

    // Signal samples
  
  vector<RA2bTree*> sigSamples;
    for( int iSample = 0 ; iSample < skims.signalNtuples.size() ; iSample++){
        std::cout<<"Skims check 1: "<<skims.signalSampleName[iSample]<<std::endl;
        RA2bTree* ntuple = skims.signalNtuples[iSample];
        sigSamples.push_back(ntuple);
        for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
            plots[iPlot].addSignalNtuple(ntuple,skims.signalSampleName[iSample]);
            plots[iPlot].setLineColor(ntuple,skims.sigLineColor[iSample]);
        }

        int numEvents = ntuple->fChain->GetEntries();
        std::cout<<"Skims check Num evts: "<<numEvents<<std::endl;
        ntupleBranchStatus<RA2bTree>(ntuple);
        for( int iEvt = 0 ; iEvt < min(MAX_EVENTS,numEvents) ; iEvt++ ){
            ntuple->GetEntry(iEvt);
            if( iEvt % 1000000 == 0 ) cout << skims.signalSampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
            if(! selectionFunc(ntuple) ) continue;
            for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
               if (skims.signalSampleName[iSample]=="VBFG1000") 
                  //plots[iPlot].fillSignal(ntuple,1);
                  //plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*0.001);
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*1);
/*
               if (skims.signalSampleName[iSample]=="VBFG1200") 
                  //plots[iPlot].fillSignal(ntuple,1);
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*0.001);
               if (skims.signalSampleName[iSample]=="VBFG1400") 
                  //plots[iPlot].fillSignal(ntuple,1);
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*0.001);
               if (skims.signalSampleName[iSample]=="VBFG1600") 
                  //plots[iPlot].fillSignal(ntuple,1);
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*0.001);
               if (skims.signalSampleName[iSample]=="VBFG1800") 
                  //plots[iPlot].fillSignal(ntuple,1);
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*0.001);
  */
               if (skims.signalSampleName[iSample]=="VBFG2000") 
                  //plots[iPlot].fillSignal(ntuple,1);
                  //plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*0.001);
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*1);
/*               if (skims.signalSampleName[iSample]=="VBFG2500") 
                  //plots[iPlot].fillSignal(ntuple,1);
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*0.001);
               if (skims.signalSampleName[iSample]=="VBFG3000") 
                  //plots[iPlot].fillSignal(ntuple,1);
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*0.001);
               if (skims.signalSampleName[iSample]=="VBFG3500") 
                  //plots[iPlot].fillSignal(ntuple,1);
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*0.001);
               if (skims.signalSampleName[iSample]=="VBFG4000") 
                  //plots[iPlot].fillSignal(ntuple,1);
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*0.001);
               if (skims.signalSampleName[iSample]=="VBFG4500") 
                  //plots[iPlot].fillSignal(ntuple,1);
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*0.001);
  */          }
        }
    }

    // Data samples
    RA2bTree* ntuple = skims.dataNtuple;
    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
        plots[iPlot].addDataNtuple(ntuple,"data_MET");
    }
  
    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    for( int iEvt = 0 ; iEvt < min(MAX_EVENTS,numEvents) ; iEvt++ ){
    //for( int iEvt = 0 ; iEvt < min(0,numEvents) ; iEvt++ ){
        ntuple->GetEntry(iEvt);
        if( iEvt % 1000000 == 0 ) cout << "data_MET: " << iEvt << "/" << min(MAX_EVENTS,numEvents) << endl;
        if(! selectionFunc(ntuple) ) continue;
        if( !signalTriggerCut(ntuple) ) continue;

        for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
            plots[iPlot].fillData(ntuple);
        }
    }

    TFile* outputFile = new TFile("plotObs_"+selection_label+".root","RECREATE");

    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        //plots[iPlot].dataHist = NULL;
        plots[iPlot].Write();
        if (plots[iPlot].is2Dhist) continue;
        //plots[iPlot].DrawNoRatio(can,skims.ntuples,sigSamples,"../plots/plotObs_"+selection_label+"_plots");
        plots[iPlot].Draw(can,skims.ntuples,sigSamples,"../plots_V16_2016/plotObs_"+selection_label+"_plots",0.1,2.0,true);
        //plots[iPlot].Draw(can,skims.ntuples,sigSamples,"../plots/plotObs_"+selection_label+"_plots",0.1,2.0,true);
        plots[iPlot].sum->Write();
    }
    outputFile->Close();
}
