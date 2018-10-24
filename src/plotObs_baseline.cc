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
    if( selection_label == "baseline" ){
        selectionFunc = baselineCut;
    }else if( selection_label == "looseZtag" ){
        selectionFunc = looseZtagCut;
    }else if( selection_label == "tightZtag" ){
        selectionFunc = tightZtagCut;
    }else 
        assert(0);

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    clock_t t;  
    skimSamples skims;
    typedef plot<RA2bTree> plot;

    plot METplot(*fillMET<RA2bTree>,"MET_"+selection_label,"MET [GeV]",15,300.,1800.);
    plot HTplot(*fillHT<RA2bTree>,"HT_"+selection_label,"H_{T} [GeV]",15,300,2800.);
    plot NJetsplot(*fillNJets<RA2bTree>,"NJets_"+selection_label,"n_{j}",14,1.5,15.5);
    plot BTagsplot(*fillBTags<RA2bTree>,"BTags_"+selection_label,"n_{b}",6,-0.5,5.5);

    plot DeltaPhi1plot(*fillDeltaPhi1<RA2bTree>,"DeltaPhi1_"+selection_label,"#Delta#Phi_{1}",20,0,3.1415);
    plot DeltaPhi2plot(*fillDeltaPhi2<RA2bTree>,"DeltaPhi2_"+selection_label,"#Delta#Phi_{2}",20,0,3.1415);
    plot DeltaPhi3plot(*fillDeltaPhi3<RA2bTree>,"DeltaPhi3_"+selection_label,"#Delta#Phi_{3}",20,0,3.1415);
    plot DeltaPhi4plot(*fillDeltaPhi4<RA2bTree>,"DeltaPhi4_"+selection_label,"#Delta#Phi_{4}",20,0,3.1415);

    plot J1pt_Massplot(*fillLeadingJetMass<RA2bTree>,"J1pt_Mass_"+selection_label,"m_{J} [GeV]",20,50.,200.);
    plot J1pt_BBplot(*fillLeadingBBtag<RA2bTree>,"J1pt_BBtag_"+selection_label,"bb-tag",20,-1.,1.);
    plot J1pt_Tau21plot(*fillLeadingTau21<RA2bTree>,"J1pt_Tau21_"+selection_label,"#tau_{21}",20,0.,1.);
    plot J1pt_Ptplot(*fillLeadingJetPt<RA2bTree>,"J1pt_Pt_"+selection_label,"p_{T,J} [GeV]",40,300.,2300.);
    plot J1pt_JetFlavorPlot(*fillLeadingJetFlavor<RA2bTree>,"J1pt_JetFlavorPlot_"+selection_label,"Jet Flavor",22,0.5,21.5);

    vector<plot> plots;
    plots.push_back(METplot);
    plots.push_back(HTplot);
    plots.push_back(NJetsplot);
    plots.push_back(BTagsplot);

    plots.push_back(DeltaPhi1plot);
    plots.push_back(DeltaPhi2plot);
    plots.push_back(DeltaPhi3plot);
    plots.push_back(DeltaPhi4plot);

    plots.push_back(J1pt_Massplot);
    plots.push_back(J1pt_BBplot);
    plots.push_back(J1pt_Tau21plot);
    plots.push_back(J1pt_Ptplot);
    plots.push_back(J1pt_JetFlavorPlot);

    // background MC samples
    for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

        //t = clock();

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
            if( iEvt % 10000 == 0 ){
                cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
                //t = clock()-t;
                //cout << "    time: " << ((float)t)/CLOCKS_PER_SEC << endl;
            }

            filename = ntuple->fChain->GetFile()->GetName();
            if( ( filename.Contains("SingleLept") || filename.Contains("DiLept") ) && ntuple->madHT>600. )continue;
            if(! selectionFunc(ntuple) ) continue;

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
        if( skims.signalSampleName[iSample] != "T5HH1300" && skims.signalSampleName[iSample] != "T5HH1700" ) continue;

        RA2bTree* ntuple = skims.signalNtuples[iSample];
        sigSamples.push_back(ntuple);
        for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
            plots[iPlot].addSignalNtuple(ntuple,skims.signalSampleName[iSample]);
            plots[iPlot].setLineColor(ntuple,skims.sigLineColor[iSample]);
        }

        int numEvents = ntuple->fChain->GetEntries();
        ntupleBranchStatus<RA2bTree>(ntuple);
        for( int iEvt = 0 ; iEvt < min(MAX_EVENTS,numEvents) ; iEvt++ ){
            ntuple->GetEntry(iEvt);
            if( iEvt % 1000000 == 0 ) cout << skims.signalSampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
            if(! selectionFunc(ntuple) ) continue;
            if( !genLevelHHcut(ntuple) ) continue;
            for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
                if( skims.signalSampleName[iSample] == "T5HH1300" )
                    plots[iPlot].fillSignal(ntuple,lumi*0.0460525/102482.);
                if( skims.signalSampleName[iSample] == "T5HH1700" )
                    plots[iPlot].fillSignal(ntuple,lumi*0.00470323/103791.);
            }
        }
    }

    // Data samples
    RA2bTree* ntuple = skims.dataNtuple;
    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
        plots[iPlot].addDataNtuple(ntuple,"data_HTMHT");
    }
  
    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    for( int iEvt = 0 ; iEvt < min(0/*MAX_EVENTS*/,numEvents) ; iEvt++ ){
        ntuple->GetEntry(iEvt);
        if( iEvt % 1000000 == 0 ) cout << "data_HTMHT: " << iEvt << "/" << min(MAX_EVENTS,numEvents) << endl;
        if(! selectionFunc(ntuple) ) continue;
        if( !signalTriggerCut(ntuple) ) continue;
        for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
            plots[iPlot].fillData(ntuple);
        }
    }

    TFile* outputFile = new TFile("plotObs_"+selection_label+".root","RECREATE");

    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        //plots[iPlot].Draw(can,skims.ntuples,sigSamples,"../plots/plotObs_baseline_plots",0.1,1.999,true);
        plots[iPlot].DrawNoRatio(can,skims.ntuples,sigSamples,"../plots/plotObs_"+selection_label+"_plots");//,0.1,1.999,true);
        plots[iPlot].Write();
        plots[iPlot].sum->Write();
    }
    
    outputFile->Close();
}
