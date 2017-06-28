#include "TString.h"
#include "TChain.h"
#include "TH1F.h"
#include "TROOT.h"
#include "THStack.h"
#include "TPad.h"

#include <vector>
#include <map>
#include <iostream>

#include "plotterUtils.cc"
#include "skimSamples.cc"
#include "definitions.cc"
#include "RA2bTree.cc"
#include "TriggerEfficiencySextet.cc"

using namespace std;

const int MAX_EVENTS = 99999999;
int main(int argc, char** argv){

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");
  
    skimSamples skims;
    typedef plot<RA2bTree> plot;

    plot METplot(*fillMET<RA2bTree>,"MET_baseline","MET [GeV]",15,300.,1800.);
    plot HTplot(*fillHT<RA2bTree>,"HT_baseline","H_{T} [GeV]",15,300,2800.);
    plot NJetsplot(*fillNJets<RA2bTree>,"NJets_baseline","n_{j}",14,1.5,15.5);
    plot BTagsplot(*fillBTags<RA2bTree>,"BTags_baseline","n_{b}",6,-0.5,5.5);
    plot Binsplot(*fillAnalysisBins<RA2bTree>,"AnalysisBins_baseline","i^th Bin",8,0.5,8.5);

    plot DeltaPhi1plot(*fillDeltaPhi1<RA2bTree>,"DeltaPhi1_baseline","#Delta#Phi_{1}",20,0,3.1415);
    plot DeltaPhi2plot(*fillDeltaPhi2<RA2bTree>,"DeltaPhi2_baseline","#Delta#Phi_{2}",20,0,3.1415);
    plot DeltaPhi3plot(*fillDeltaPhi3<RA2bTree>,"DeltaPhi3_baseline","#Delta#Phi_{3}",20,0,3.1415);
    plot DeltaPhi4plot(*fillDeltaPhi4<RA2bTree>,"DeltaPhi4_baseline","#Delta#Phi_{4}",20,0,3.1415);

    plot J1pt_Massplot(*fillLeadingJetMass<RA2bTree>,"J1pt_Mass_baseline","m_{J} [GeV]",20,50.,200.);
    plot J2pt_Massplot(*fillSubLeadingJetMass<RA2bTree>,"J2pt_Mass_baseline","m_{J} [GeV]",20,50.,200.);
    plot J1bbtag_Massplot(*fillLeadingBBtagJetMass<RA2bTree>,"J1bbtag_Mass_baseline","m_{J} [GeV]",20,50.,200.);
    plot J2bbtag_Massplot(*fillSubLeadingBBtagJetMass<RA2bTree>,"J2bbtag_Mass_baseline","m_{J} [GeV]",20,50.,200.);
    plot J1mass_Massplot(*fillLeadingMassJetMass<RA2bTree>,"J1mass_Mass_baseline","m_{J} [GeV]",20,50.,200.);
    plot J2mass_Massplot(*fillSubLeadingMassJetMass<RA2bTree>,"J2mass_Mass_baseline","m_{J} [GeV]",20,50.,200.);

    plot J1pt_BBplot(*fillLeadingBBtag<RA2bTree>,"J1pt_BBtag_baseline","bb-tag",20,-1.,1.);
    plot J2pt_BBplot(*fillSubLeadingBBtag<RA2bTree>,"J2pt_BBtag_baseline","bb-tag",20,-1.,1.);
    plot J1bbtag_BBplot(*fillLeadingBBtagJetBBtag<RA2bTree>,"J1bbtag_BBtag_baseline","bb-tag",20,-1.,1.);
    plot J2bbtag_BBplot(*fillSubLeadingBBtagJetBBtag<RA2bTree>,"J2bbtag_BBtag_baseline","bb-tag",20,-1.,1.);
    plot J1mass_BBplot(*fillLeadingMassJetBBtag<RA2bTree>,"J1mass_BBtag_baseline","bb-tag",20,-1.,1.);
    plot J2mass_BBplot(*fillSubLeadingMassJetBBtag<RA2bTree>,"J2mass_BBtag_baseline","bb-tag",20,-1.,1.);

    plot J1pt_Tau21plot(*fillLeadingTau21<RA2bTree>,"J1pt_Tau21_baseline","#tau_{21}",20,0.,1.);
    plot J2pt_Tau21plot(*fillSubLeadingTau21<RA2bTree>,"J2pt_Tau21_baseline","#tau_{21}",20,0.,1.);
    plot J1bbtag_Tau21plot(*fillLeadingBBtagJetTau21<RA2bTree>,"J1bbtag_Tau21_baseline","#tau_{21}",20,0.,1.);
    plot J2bbtag_Tau21plot(*fillSubLeadingBBtagJetTau21<RA2bTree>,"J2bbtag_Tau21_baseline","#tau_{21}",20,0.,1.);
    plot J1mass_Tau21plot(*fillLeadingMassJetTau21<RA2bTree>,"J1mass_Tau21_baseline","#tau_{21}",20,0.,1.);
    plot J2mass_Tau21plot(*fillSubLeadingMassJetTau21<RA2bTree>,"J2mass_Tau21_baseline","#tau_{21}",20,0.,1.);

    plot J1pt_Ptplot(*fillLeadingJetPt<RA2bTree>,"J1pt_Pt_baseline","p_{T,J} [GeV]",40,300.,2300.);
    plot J2pt_Ptplot(*fillSubLeadingJetPt<RA2bTree>,"J2pt_Pt_baseline","p_{T,J} [GeV]",40,300.,2300.);
    plot J1bbtag_Ptplot(*fillLeadingBBtagJetPt<RA2bTree>,"J1bbtag_Pt_baseline","p_{T,J} [GeV]",40,300.,2300.);
    plot J2bbtag_Ptplot(*fillSubLeadingBBtagJetPt<RA2bTree>,"J2bbtag_Pt_baseline","p_{T,J} [GeV]",40,300.,2300.);
    plot J1mass_Ptplot(*fillLeadingMassJetPt<RA2bTree>,"J1mass_Pt_baseline","p_{T,J} [GeV]",40,300.,2300.);
    plot J2mass_Ptplot(*fillSubLeadingMassJetPt<RA2bTree>,"J2mass_Pt_baseline","p_{T,J} [GeV]",40,300.,2300.);

    plot J1pt_JetFlavorPlot(*fillLeadingJetFlavor<RA2bTree>,"J1pt_JetFlavorPlot","Jet Flavor",22,0.5,21.5);
    plot J2pt_JetFlavorPlot(*fillSubLeadingJetFlavor<RA2bTree>,"J2pt_JetFlavorPlot","Jet Flavor",22,0.5,21.5);

    vector<plot> plots;
    plots.push_back(METplot);
    plots.push_back(HTplot);
    plots.push_back(NJetsplot);
    plots.push_back(BTagsplot);

    plots.push_back(DeltaPhi1plot);
    plots.push_back(DeltaPhi2plot);
    plots.push_back(DeltaPhi3plot);
    plots.push_back(DeltaPhi4plot);

    plots.push_back(Binsplot);
    plots.push_back(J1pt_Massplot);
    plots.push_back(J2pt_Massplot);
    plots.push_back(J1bbtag_Massplot);
    plots.push_back(J2bbtag_Massplot);
    plots.push_back(J1mass_Massplot);
    plots.push_back(J2mass_Massplot);
    plots.push_back(J1pt_BBplot);
    plots.push_back(J2pt_BBplot);
    plots.push_back(J1bbtag_BBplot);
    plots.push_back(J2bbtag_BBplot);
    plots.push_back(J1mass_BBplot);
    plots.push_back(J2mass_BBplot);
    plots.push_back(J1pt_Tau21plot);
    plots.push_back(J2pt_Tau21plot);
    plots.push_back(J1bbtag_Tau21plot);
    plots.push_back(J2bbtag_Tau21plot);
    plots.push_back(J1mass_Tau21plot);
    plots.push_back(J2mass_Tau21plot);
    plots.push_back(J1pt_Ptplot);
    plots.push_back(J2pt_Ptplot);
    plots.push_back(J1bbtag_Ptplot);
    plots.push_back(J2bbtag_Ptplot);
    plots.push_back(J1mass_Ptplot);
    plots.push_back(J2mass_Ptplot);
    plots.push_back(J1pt_JetFlavorPlot);
    plots.push_back(J2pt_JetFlavorPlot);

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
            if(! baselineCut(ntuple) ) continue;

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
            if(! baselineCut(ntuple) ) continue;
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
    for( int iEvt = 0 ; iEvt < 0/*min(MAX_EVENTS,numEvents)*/ ; iEvt++ ){
        ntuple->GetEntry(iEvt);
        if( iEvt % 1000000 == 0 ) cout << "data_HTMHT: " << iEvt << "/" << numEvents << endl;
        if(! baselineCut(ntuple) ) continue;
        if( !signalTriggerCut(ntuple) ) continue;
        for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
            plots[iPlot].fillData(ntuple);
        }
    }

    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        plots[iPlot].dataHist = NULL;
        plots[iPlot].DrawNoRatio(can,skims.ntuples,sigSamples,"../plots/plotObs_baseline_plots");
    }
}
