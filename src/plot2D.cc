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
    if( selection_label == "ZNoSelection-Test"){
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
    }else if( selection_label == "ZSRHPVBF-Test"){
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
  
    skimSamples skims(skimSamples::kSignal,sys);
    typedef plot<RA2bTree> plot;

    plot ZMT_J1pt_plot(*fillZMT<RA2bTree>,*fillLeadingJetPt<RA2bTree>,"ZMT_J1pt_"+selection_label,"MT_{Z} [GeV]","p_{T,j1} [GeV}",100,500.,5000.,100,500.,5000.); // 100 GeV bin
    plot ZMT_J1Eta_plot(*fillZMT<RA2bTree>,*fillLeadingJetEta<RA2bTree>,"ZMT_J1Eta_"+selection_label,"MT_{Z} [GeV]","#eta_{AK8J} [GeV]",100,500.,5000.,50,-5.,5.); //50 GeV bin;

    //plot VBFmjj_plot(*fillVBF_Mjj<RA2bTree>,"VBFmjj_plot_"+selection_label,"m_{jj}^{VBF} [GeV]",40,0,4000);
    //plot VBFptjj_plot(*fillVBF_Ptjj<RA2bTree>,"VBFptjj_plot_"+selection_label,"pt_{jj}^{VBF} [GeV]",40,0,4000);

    vector<plot> plots;
    plots.push_back(ZMT_J1pt_plot);
    plots.push_back(ZMT_J1Eta_plot);
    
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

            // ---------- custom weights -----------
            std::vector<double> EfficiencyCenterUpDown = Eff_MetMhtSextetReal_CenterUpDown(ntuple->HT, ntuple->MHT, ntuple->NJets);
            weight = ntuple->Weight*lumi*customPUweights(ntuple)*EfficiencyCenterUpDown[0];

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
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*1);
               if (skims.signalSampleName[iSample]=="VBFG1200") 
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*1);
               if (skims.signalSampleName[iSample]=="VBFG1400") 
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*1);
               if (skims.signalSampleName[iSample]=="VBFG1600") 
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*1);
               if (skims.signalSampleName[iSample]=="VBFG1800") 
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*1);
               if (skims.signalSampleName[iSample]=="VBFG2000") 
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*1);
               if (skims.signalSampleName[iSample]=="VBFG2500") 
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*1);
               if (skims.signalSampleName[iSample]=="VBFG3000") 
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*1);
               if (skims.signalSampleName[iSample]=="VBFG3500") 
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*1);
               if (skims.signalSampleName[iSample]=="VBFG4000") 
                  plots[iPlot].fillSignal(ntuple,ntuple->Weight*lumi*1);
               if (skims.signalSampleName[iSample]=="VBFG4500") 
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

    TFile* outputFile = new TFile("plot2D_"+selection_label+".root","RECREATE");

    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
        plots[iPlot].Write();
    }
    outputFile->Close();
}
