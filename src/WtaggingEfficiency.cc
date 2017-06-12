#include "TString.h"
#include "TChain.h"
#include "TH1F.h"
#include "TROOT.h"
#include "THStack.h"
#include "TPad.h"

#include <vector>
#include <map>
#include <iostream>
#include <cassert>

#include "plotterUtils.cc"
#include "skimSamples.cc"
#include "definitions.cc"
#include "RA2bTree.cc"
#include "TriggerEfficiencySextet.cc"

using namespace std;

int main(int argc, char** argv){

    int region(0);
    if( argc >= 2 ) 
        region = atoi(argv[1]);

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    skimSamples* skims_;
    if( region == 1 )
        skims_ = new skimSamples(skimSamples::kSLm);
    else if( region == 2 )
        skims_ = new skimSamples(skimSamples::kSLe);
    else        
        assert(1);
    skimSamples skims = *skims_;

    typedef plot<RA2bTree> plot;
    typedef bool(*cutFunc)(RA2bTree*);
    vector<cutFunc> cutFlow;

    cutFlow.push_back(*FiltersCut<RA2bTree>);
    cutFlow.push_back(*DeltaPhiCuts<RA2bTree>);
    
    if( region == 1 ){
        cutFlow.push_back(*singleMuCut<RA2bTree>);
    }
    if( region == 2 ){
        cutFlow.push_back(*singleEleCut<RA2bTree>);
    }
    cutFlow.push_back(*METHTlooseCut<RA2bTree>);

    vector<plot> plots_tag;
    vector<plot> plots_noTag;

    double ptBinning[5]={150,300,400,500,2000};

    plots_tag.push_back(plot(*fillMET<RA2bTree>,"MET_WtaggingEff_tag","MET [GeV]",40,100.,1300.));
    plots_tag.push_back(plot(*fillHT<RA2bTree>,"HT_WtaggingEff_tag","H_{T} [GeV]",40,100.,2000.));
    plots_tag.push_back(plot(*fillLeadingJetMass<RA2bTree>,"J1M_WtaggingEff_tag","leading m_{J} [GeV]",100,40.,140.));
    plots_tag.push_back(plot(*fillLeadingJetPt<RA2bTree>,"J1Pt_WtaggingEff_tag","leading p_{T,J} [GeV]",4,ptBinning));
    plots_tag.push_back(plot(*fillSubLeadingJetMass<RA2bTree>,"J2M_WtaggingEff_tag","subleading m_{J} [GeV]",100,40.,140.));
    plots_tag.push_back(plot(*fillSubLeadingJetPt<RA2bTree>,"J2Pt_WtaggingEff_tag","subleading p_{T,J} [GeV]",50,0.,2000.));

    plots_noTag.push_back(plot(*fillMET<RA2bTree>,"MET_WtaggingEff_noTag","MET [GeV]",40,100.,1300.));
    plots_noTag.push_back(plot(*fillHT<RA2bTree>,"HT_WtaggingEff_noTag","H_{T} [GeV]",40,100.,2000.));
    plots_noTag.push_back(plot(*fillLeadingJetMass<RA2bTree>,"J1M_WtaggingEff_noTag","leading m_{J} [GeV]",100,40.,140.));
    plots_noTag.push_back(plot(*fillLeadingJetPt<RA2bTree>,"J1Pt_WtaggingEff_noTag","leading p_{T,J} [GeV]",4,ptBinning));
    plots_noTag.push_back(plot(*fillSubLeadingJetMass<RA2bTree>,"J2M_WtaggingEff_noTag","subleading m_{J} [GeV]",100,40.,140.));
    plots_noTag.push_back(plot(*fillSubLeadingJetPt<RA2bTree>,"J2Pt_WtaggingEff_noTag","subleading p_{T,J} [GeV]",50,0.,2000.));

    // background MC samples
  
    for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

        RA2bTree* ntuple = skims.ntuples[iSample];
        for( int iPlot = 0 ; iPlot < plots_tag.size() ; iPlot++){
            plots_tag[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plots_tag[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
            plots_tag[iPlot].dataHist=0;
        }
        for( int iPlot = 0 ; iPlot < plots_noTag.size() ; iPlot++){
            plots_noTag[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plots_noTag[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
            plots_noTag[iPlot].dataHist=0;
        }

        int numEvents = ntuple->fChain->GetEntries();
        ntupleBranchStatus<RA2bTree>(ntuple);
        double weight = 0.;
        TString filename;
        bool pass = true;
        for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
            ntuple->GetEntry(iEvt);
            if( iEvt % 100000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
            
            filename = ntuple->fChain->GetFile()->GetName();
            if( ( filename.Contains("SingleLept") || filename.Contains("DiLept") ) && ntuple->madHT>600. )continue;

            // ----------- compute weights --------------
            weight = ntuple->Weight*lumi*customPUweights(ntuple);
            //if( skims.sampleName[iSample] == "TT" ){
            //    weight *= ISRweights(ntuple);
            // }
            if( region == 1 ){
                weight*=singleMuonTrigWeights(ntuple);
            }
            if( region == 2 ){
                weight*=singleElectronTrigWeights(ntuple);
            }
            // ------------------------------------------
            pass = true;
            for( int iCut = 0 ; iCut < cutFlow.size() ; iCut++ ){
                pass&=cutFlow[iCut](ntuple);
            }
            if( !pass )continue;
            if( ntuple->JetsAK8->size() > 0 && genWmatched(ntuple) && fillLeadingJetMinDRB(ntuple) > 0.8 ){
                for( int iPlot = 0 ; iPlot < plots_tag.size() ; iPlot++ ){
                    plots_tag[iPlot].fill(ntuple,weight);
                }
            }else{
                for( int iPlot = 0 ; iPlot < plots_noTag.size() ; iPlot++ ){
                    plots_noTag[iPlot].fill(ntuple,weight);
                }
            }
        }
    }
    
    // data
    RA2bTree* ntuple = skims.dataNtuple;
    for( int iPlot = 0 ; iPlot < plots_tag.size() ; iPlot++){
        plots_tag[iPlot].addDataNtuple(ntuple,"data");
    }
    for( int iPlot = 0 ; iPlot < plots_noTag.size() ; iPlot++){
        plots_noTag[iPlot].addDataNtuple(ntuple,"data");
    }

  
    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    bool pass=true;
    for( int iEvt = 0 ; iEvt < ( region == 0 ? 0 : numEvents ) ; iEvt++ ){
        ntuple->GetEntry(iEvt);
        if( iEvt % 100000 == 0 ) cout << "data: " << iEvt << "/" << numEvents << endl;
        if( region == 1){
            if( !singleMuTriggerCut(ntuple) ) continue;
        } 
        if( region == 2){
            if( !singleEleTriggerCut(ntuple) ) continue;
        }
        pass = true;
        for( int iCut = 0 ; iCut < cutFlow.size() ; iCut++ ){
            pass&=cutFlow[iCut](ntuple);
        }
        if( !pass ) continue;
        for( int iPlot = 0 ; iPlot < plots_noTag.size() ; iPlot++ ){
            plots_noTag[iPlot].fillData(ntuple);
        }
    }

    TString outputTag[2] = {"singleMuCR","singleEleCR"};
    TFile * outputFile = new TFile("WtaggingEff_"+outputTag[region-1]+".root","RECREATE"); 

    for( int iPlot = 0 ; iPlot < plots_tag.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        plots_tag[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/WtaggingEff_"+outputTag[region-1]+"_plots",0.1,2.0,false);
        plots_tag[iPlot].buildSum();
        plots_tag[iPlot].Write();
        plots_tag[iPlot].sum->Write();
    }

    for( int iPlot = 0 ; iPlot < plots_noTag.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        plots_noTag[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/WtaggingEff_"+outputTag[region-1]+"_plots",0.1,2.0,false);
        plots_noTag[iPlot].buildSum();
        plots_noTag[iPlot].Write();
        plots_noTag[iPlot].sum->Write();
    }

    outputFile->Close();
}
