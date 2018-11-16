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

    int MAX_EVENTS = 99999999;
    if( argc > 2 )
        MAX_EVENTS = atoi(argv[2]);
    
    assert(argc > 1);
    TString selection_label = argv[1];
    bool (*selectionFunc)(RA2bTree*);
    if( selection_label == "baselineNoVBF" ){
    //if( selection_label == "baselineTestNoVBF" ){
        selectionFunc = baselineCutNoVBF;
    }else if( selection_label == "baselineVBF" ){
        selectionFunc = baselineCut;
    }else if( selection_label == "ZSRNoVBF"){
        selectionFunc = ZSignalRegionCutNoVBF;
    }else if( selection_label == "ZSRVBF"){
        selectionFunc = ZSignalRegionCut;
    }else if( selection_label == "ZSRHPNoVBF"){
        selectionFunc = ZSignalRegionHPCutNoVBF;
    }else if( selection_label == "ZSRHPVBF"){
        selectionFunc = ZSignalRegionHPCut;
    }else if( selection_label == "ZSRHPVBFEta"){
        selectionFunc = ZHPEtaCut;
    }else if( selection_label == "ZSRLPNoVBF"){
        selectionFunc = ZSignalRegionLPCutNoVBF;
    }else if( selection_label == "ZSRLPVBF"){
        selectionFunc = ZSignalRegionLPCut;
    }else if( selection_label == "ZSBNoVBF" ){
        selectionFunc = ZSidebandnoVBFCut;
    }else if( selection_label == "ZSBVBF" ){
        selectionFunc = ZSidebandCut;
    }else if( selection_label == "ZSBHPNoVBF" ){
        selectionFunc = ZSidebandHPCutnoVBF;
    }else if( selection_label == "ZSBHPVBF" ){
        selectionFunc = ZSidebandHPCut;
    }else if( selection_label == "ZSBLPNoVBF"){
        selectionFunc = ZSidebandLPCutnoVBF;
    }else if( selection_label == "ZSBLPVBF"){
        selectionFunc = ZSidebandLPCut;

    }else
        assert(0);

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");
  
    skimSamples skims;
    typedef plot<RA2bTree> plot;

    plot NVtxplot(*fillNVtx<RA2bTree>,"NVtx_"+selection_label,"NVtx",79,1.5,80.5);//1 bin
    plot METplot(*fillMET<RA2bTree>,"MET_"+selection_label,"MET [GeV]",36,200.,2000.);//50 GeV bin
    plot MET1plot(*fillMET<RA2bTree>,"MET1_"+selection_label,"MET [GeV]",25,200.,1200.);//40 GeV bin
    plot HTplot(*fillHT<RA2bTree>,"HT_"+selection_label,"H_{T} [GeV]",15,300,2800.);
    plot NJetsplot(*fillNJets<RA2bTree>,"NJets_"+selection_label,"n_{jets}",14,1.5,15.5);
    plot NAK8Jetsplot(*fillNJets<RA2bTree>,"NAK8Jets_"+selection_label,"nAK8_{jets}",14,1.5,15.5);

    plot DeltaPhi1plot(*fillDeltaPhi1<RA2bTree>,"DeltaPhi1_"+selection_label,"#Delta#Phi_{1}",20,0,3.1415);
    plot DeltaPhi2plot(*fillDeltaPhi2<RA2bTree>,"DeltaPhi2_"+selection_label,"#Delta#Phi_{2}",20,0,3.1415);
    plot DeltaPhi3plot(*fillDeltaPhi3<RA2bTree>,"DeltaPhi3_"+selection_label,"#Delta#Phi_{3}",20,0,3.1415);
    plot DeltaPhi4plot(*fillDeltaPhi4<RA2bTree>,"DeltaPhi4_"+selection_label,"#Delta#Phi_{4}",20,0,3.1415);
    plot DeltaPhiAK8JMETplot(*fillDeltaPhiAK8JMET<RA2bTree>,"DeltaPhiAK8JMET_"+selection_label,"#Delta#Phi(AK8J,MET)",20,0,3.1415);

    plot J1pt_Massplot(*fillLeadingJetMass<RA2bTree>,"J1pt_Mass_"+selection_label,"m_{J} [GeV]",54,30.,300.);//5 Gev bin
    // Turn on the line below for SR only
    plot J1pt_Mass1plot(*fillLeadingJetMass<RA2bTree>,"J1pt_Mass1_"+selection_label,"m_{J} [GeV]",14,50.,120.);//5 Gev bin
    plot J1pt_Tau21plot(*fillLeadingTau21<RA2bTree>,"J1pt_Tau21_"+selection_label,"#tau_{21}",20,0.,1.);
    plot DDT_Tau21plot(*fillDDT<RA2bTree>,"DDT_Tau21_"+selection_label,"DDT",20,0.,1.);

    plot ZMTplot(*fillZMT<RA2bTree>,"ZMT_"+selection_label,"MT_{Z} [GeV]",45,500.,5000.); // 100 GeV bin
    plot ZMT1plot(*fillZMT<RA2bTree>,"ZMT1_"+selection_label,"MT_{Z} [GeV]",25,500.,3000.); // 100 GeV bin
    plot MZ510MTplot(*fillMZ510MT<RA2bTree>,"MZ510MT_"+selection_label,"m_{J} for MT [0.5-1 Tev] [GeV]",54,30.,300.); // 5 GeV bin
    plot MZ1015MTplot(*fillMZ1015MT<RA2bTree>,"MZ1015MT_"+selection_label,"m_{J} for MT [1-1.5 TeV] [GeV]",54,30.,300.); // 5 GeV bin
    plot MZ1520MTplot(*fillMZ1520MT<RA2bTree>,"MZ1520MT_"+selection_label,"m_{J} for MT [1.5-2 TeV] [GeV]",54,30.,300.); // 5 GeV bin
    plot MZ2025MTplot(*fillMZ2025MT<RA2bTree>,"MZ2025MT_"+selection_label,"m_{J} for MT [2-2.5 TeV] [GeV]",54,30.,300.); // 5 GeV bin
    plot MZ2530MTplot(*fillMZ2530MT<RA2bTree>,"MZ2530MT_"+selection_label,"m_{J} for MT [2.5-3.0 TeV] [GeV]",54,30.,300.); // 5 GeV bin
    plot J1pt_Ptplot(*fillLeadingJetPt<RA2bTree>,"J1pt_Pt_"+selection_label,"p_{T,J} [GeV]",36,200.,2000.); //50 GeV bin;
    plot J1pt_Etaplot(*fillLeadingJetEta<RA2bTree>,"J1pt_Eta_"+selection_label,"#eta_{AK8J} [GeV]",50,-5.,5.); //50 GeV bin;

    plot VBFmjj_plot(*fillVBF_Mjj<RA2bTree>,"VBFmjj_plot_"+selection_label,"m_{jj}^{VBF} [GeV]",40,0,4000);
    plot VBFptjj_plot(*fillVBF_Ptjj<RA2bTree>,"VBFptjj_plot_"+selection_label,"pt_{jj}^{VBF} [GeV]",40,0,4000);
    plot VBFj1pt_plot(*fillVBF_j1Pt<RA2bTree>,"VBFj1pt_plot_"+selection_label,"pt_{j1}^{VBF} [GeV]",50,0,1500);
    plot VBFj2pt_plot(*fillVBF_j2Pt<RA2bTree>,"VBFj2pt_plot_"+selection_label,"pt_{j2}^{VBF} [GeV]",50,0,1500);
    plot VBFdEta_plot(*fillVBF_dEta<RA2bTree>,"VBFdEta_plot_"+selection_label,"#Delta#eta^{VBF}",20,0,10);
    plot VBFdPhi_plot(*fillVBF_dPhi<RA2bTree>,"VBFdPhi_"+selection_label,"#Delta#Phi VBF(j1,j2)",20,0,3.1415);
    plot VBFj1Eta_plot(*fillVBF_j1Eta<RA2bTree>,"VBFj1Eta_plot_"+selection_label,"#eta_{j1}^{VBF}",40,-5,5);
    plot VBFj2Eta_plot(*fillVBF_j2Eta<RA2bTree>,"VBFj2Eta_plot_"+selection_label,"#eta_{j2}^{VBF}",40,-5,5);
    plot VBFj1Phi_plot(*fillVBF_j1Phi<RA2bTree>,"VBFj1Phi_plot_"+selection_label,"#Phi_{j1}^{VBF}",40,-3.1415,3.1415);
    plot VBFj2Phi_plot(*fillVBF_j2Phi<RA2bTree>,"VBFj2Phi_plot_"+selection_label,"#Phi_{j2}^{VBF}",40,-3.1415,3.1415);
    plot VBFj1j2Eta_plot(*fillVBF_j1j2Eta<RA2bTree>,"VBFj1j2Eta_plot_"+selection_label,"#eta_{j1.j2}^{VBF}",100,-25,25);


    vector<plot> plots;
    plots.push_back(NVtxplot);
    plots.push_back(METplot);
    plots.push_back(MET1plot);
    plots.push_back(HTplot);
    plots.push_back(ZMTplot);
    plots.push_back(ZMT1plot);
    plots.push_back(MZ510MTplot);
    plots.push_back(MZ1015MTplot);
    plots.push_back(MZ1520MTplot);
    plots.push_back(MZ2025MTplot);
    plots.push_back(MZ2530MTplot);
    plots.push_back(NJetsplot);
    plots.push_back(NAK8Jetsplot);

    plots.push_back(DeltaPhi1plot);
    plots.push_back(DeltaPhi2plot);
    plots.push_back(DeltaPhi3plot);
    plots.push_back(DeltaPhi4plot);
    plots.push_back(DeltaPhiAK8JMETplot);

    plots.push_back(J1pt_Massplot);
    plots.push_back(J1pt_Mass1plot);
    plots.push_back(J1pt_Tau21plot);
    plots.push_back(DDT_Tau21plot);
    plots.push_back(J1pt_Ptplot);
    plots.push_back(J1pt_Etaplot);

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
               plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*1);
            }
        }
    }

    // Data samples
    RA2bTree* ntuple = skims.dataNtuple;
    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
        plots[iPlot].addDataNtuple(ntuple,"data_MET");
    }
  
    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    //for( int iEvt = 0 ; iEvt < min(MAX_EVENTS,numEvents) ; iEvt++ ){
    for( int iEvt = 0 ; iEvt < min(0,numEvents) ; iEvt++ ){
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
        plots[iPlot].DrawNoRatio(can,skims.ntuples,sigSamples,"../plots/plotObs_"+selection_label+"_plots");
        //plots[iPlot].Draw(can,skims.ntuples,sigSamples,"../plots/plotObs_"+selection_label+"_plots",0.1,2.0,true);
        plots[iPlot].Write();
        plots[iPlot].sum->Write();
    }
    
    outputFile->Close();
}
