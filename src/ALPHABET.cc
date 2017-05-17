#include "TString.h"
#include "TChain.h"
#include "TH1F.h"
#include "TROOT.h"
#include "THStack.h"
#include "TPad.h"

#include <vector>
#include <map>
#include <iostream>
#include <assert.h>

#include "plotterUtils.cc"
#include "skimSamples.cc"
#include "definitions.cc"
#include "RA2bTree.cc"
#include "ALPHABET.h"
#include "TriggerEfficiencySextet.cc"
using namespace std;
using namespace alphabet;

int main(int argc, char** argv){

    int region(0);
    if( argc >= 2 ) 
        region = atoi(argv[1]);

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");
    
    skimSamples* skims_;
    if( region == 0 ) 
        skims_ = new skimSamples(skimSamples::kSignal);
    else if( region == 1 )
        skims_ = new skimSamples(skimSamples::kSLm);
    else if( region == 2 )
        skims_ = new skimSamples(skimSamples::kSLe);
    else if( region == 3 )
        skims_ = new skimSamples(skimSamples::kSignal);
    else        
        assert(1);
    
    skimSamples skims = *skims_;

    typedef plot<RA2bTree> plot;
    
    double mJbins[4]={50.,85.,135.,250.};
    vector<vector<plot> > plots;

    for( int i = 0 ; i < numMETbins ; i++ ) {
        TString tag="_";
        tag+=lowestMET+i*binWidth;
        vector<plot> plotsTemp;
        plotsTemp.push_back(plot(*fillLeadingJetMass<RA2bTree>,"mJ_tagSR"+tag,"m_{J} [GeV]",3,mJbins));
        plotsTemp.push_back(plot(*fillLeadingJetMass<RA2bTree>,"mJ_tagSB"+tag,"m_{J} [GeV]",3,mJbins));
    
        plotsTemp.push_back(plot(*fillLeadingJetMass<RA2bTree>,"mJ_antitagSR"+tag,"m_{J} [GeV]",3,mJbins));
        plotsTemp.push_back(plot(*fillLeadingJetMass<RA2bTree>,"mJ_antitagSB"+tag,"m_{J} [GeV]",3,mJbins));
    
        plotsTemp.push_back(plot(*fillLeadingJetMass<RA2bTree>,"mJ_doubletagSR"+tag,"m_{J} [GeV]",3,mJbins));
        plotsTemp.push_back(plot(*fillLeadingJetMass<RA2bTree>,"mJ_doubletagSB"+tag,"m_{J} [GeV]",3,mJbins));

        plots.push_back(plotsTemp);
    }

    vector<plot> METprojPlots;
    METprojPlots.push_back(plot(*fillMET<RA2bTree>,"MET_tagSR","m_{J} [GeV]",2,300,700));
    METprojPlots.push_back(plot(*fillMET<RA2bTree>,"MET_tagSB","m_{J} [GeV]",2,300,700));
    
    METprojPlots.push_back(plot(*fillMET<RA2bTree>,"MET_antitagSR","m_{J} [GeV]",2,300,700));
    METprojPlots.push_back(plot(*fillMET<RA2bTree>,"MET_antitagSB","m_{J} [GeV]",2,300,700));
    
    METprojPlots.push_back(plot(*fillMET<RA2bTree>,"MET_doubletagSR","m_{J} [GeV]",2,300,700));
    METprojPlots.push_back(plot(*fillMET<RA2bTree>,"MET_doubletagSB","m_{J} [GeV]",2,300,700));
    
    // background MC samples - 0 lepton regions
    for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

        RA2bTree* ntuple = skims.ntuples[iSample];

        for( int iBin = 0 ; iBin < numMETbins ; iBin++){
            for( int iPlot = 0 ; iPlot < plots[iBin].size() ; iPlot++){
                plots[iBin][iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
                plots[iBin][iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
            }
            for( int iPlot = 0 ; iPlot < METprojPlots.size() ; iPlot++){
                METprojPlots[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
                METprojPlots[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);                
            }
        }

        int numEvents = ntuple->fChain->GetEntries();
        ntupleBranchStatus<RA2bTree>(ntuple);
        int bin = -1;
        double weight=0.;
        float trigWeight=1.0;
        for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
            ntuple->GetEntry(iEvt);
            if(region==3 or region==0){
                std::vector<double> EfficiencyCenterUpDown = Eff_MetMhtSextetReal_CenterUpDown(ntuple->HT, ntuple->MHT, ntuple->NJets);
                trigWeight=EfficiencyCenterUpDown[0];
            }
            if( iEvt % 100000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
            if( region == 0 ){
                if(! baselineCut(ntuple) ) continue;
            }else if( region == 1){
                if(! singleMuBaselineCut(ntuple) ) continue;
            }else if( region == 2){
                if(! singleEleBaselineCut(ntuple) ) continue;
            }else if( region == 3){ 
                if(! lowDphiBaselineCut(ntuple) ) continue;
            }
            if( skims.sampleName[iSample] == "TTExtra" && ntuple->madHT>600. )continue;
            bin = -1;
            weight = ntuple->Weight*lumi;//*customPUweights(ntuple);
            //if( skims.sampleName[iSample] == "TTExtra" || skims.sampleName[iSample] == "TTJets" )
            //    weight *= ISRweights(ntuple);
            for( int iBin = 0 ; iBin < numMETbins ; iBin++ ){
                if( ntuple->MET > lowestMET ){
                    if( ntuple->MET > numMETbins*(binWidth-1)+lowestMET )
                        bin = numMETbins-1;
                    else
                        bin = int((ntuple->MET-lowestMET)/binWidth);
                }
            }
            if( bin < 0 ) continue;
      
            if( doubleTaggingLooseCut(ntuple) ){
                double jetMass1 = fillLeadingJetMass(ntuple);
                double jetMass2 = fillSubLeadingJetMass(ntuple);
                if( jetMass1 > 85 && jetMass1 < 135 ) { 
                    plots[bin][4].fill(ntuple,weight);
                    METprojPlots[4].fill(ntuple,weight);
                }else{
                    plots[bin][5].fill(ntuple,weight);
                    METprojPlots[5].fill(ntuple,weight);
                }
            }else{
                if( singleHiggsTagLooseCut(ntuple) ){
                    double jetMass1 = fillLeadingJetMass(ntuple);
                    double jetMass2 = fillSubLeadingJetMass(ntuple);
                    if( jetMass1 > 85 && jetMass1 < 135 ){
                        plots[bin][0].fill(ntuple,weight);
                        METprojPlots[0].fill(ntuple,weight);
                    }else{
                        plots[bin][1].fill(ntuple,weight);
                        METprojPlots[1].fill(ntuple,weight);
                    }
                }
                if( antiTaggingLooseCut(ntuple) ){
                    double jetMass1 = fillLeadingJetMass(ntuple);
                    double jetMass2 = fillSubLeadingJetMass(ntuple);
                    if( jetMass1 > 85 && jetMass1 < 135 ){
                        plots[bin][2].fill(ntuple,weight);
                        METprojPlots[2].fill(ntuple,weight);
                    }else{
                        plots[bin][3].fill(ntuple,weight);
                        METprojPlots[3].fill(ntuple,weight);
                    }
                }// end antitag
            }// end double tag else
        }// end event loop
    }// end sample loop
    

    // data 
    RA2bTree* ntuple = skims.dataNtuple;
  
    for( int iBin = 0 ; iBin < numMETbins ; iBin++){
        for( int iPlot = 0 ; iPlot < plots[iBin].size() ; iPlot++){
            plots[iBin][iPlot].addDataNtuple(ntuple,"data");
        }
        for( int iPlot = 0 ; iPlot < plots[iBin].size() ; iPlot++){
            METprojPlots[iPlot].addDataNtuple(ntuple,"data");
        }
    }

    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
        ntuple->GetEntry(iEvt);
        if( iEvt % 100000 == 0 ) cout << "data: " << iEvt << "/" << numEvents << endl;
        if( region == 0 ){
            if(! baselineCut(ntuple) ) continue;
            // need triggers
        }else if( region == 1){
            if(! singleMuBaselineCut(ntuple) ) continue;
            // need triggers
        }else if( region == 2){
            if(! singleEleBaselineCut(ntuple) ) continue;
            // need triggers
        }else if( region == 3 ){ 
            if(! lowDphiBaselineCut(ntuple) ) continue;
            // need triggers 
        }
        int bin = -1;
        for( int iBin = 0 ; iBin < numMETbins ; iBin++ ){
            if( ntuple->MET > lowestMET ){
                if( ntuple->MET > lowestMET+binWidth*(numMETbins-1) )
                    bin = numMETbins-1;
                else
                    bin = int((ntuple->MET-lowestMET)/binWidth);
            }
        }
        if( bin < 0 ) continue;
      
        if( doubleTaggingLooseCut(ntuple) ){
            double jetMass1 = fillLeadingJetMass(ntuple);
            double jetMass2 = fillSubLeadingJetMass(ntuple);
            if( jetMass1 > 85 && jetMass1 < 135 ){
                if( region != 0 ){
                    plots[bin][4].fillData(ntuple);
                    METprojPlots[4].fillData(ntuple);
                }
            }else{
                plots[bin][5].fillData(ntuple);
                METprojPlots[5].fillData(ntuple);
            }
        }else{
            if( singleHiggsTagLooseCut(ntuple) ){
                double jetMass1 = fillLeadingJetMass(ntuple);
                double jetMass2 = fillSubLeadingJetMass(ntuple);
                if( jetMass1 > 85 && jetMass1 < 135 ){
                    if( region != 0 ){
                        plots[bin][0].fillData(ntuple);
                        METprojPlots[0].fillData(ntuple);
                    }
                }else{
                    plots[bin][1].fillData(ntuple);
                    METprojPlots[1].fillData(ntuple);
                }
            }
            if( antiTaggingLooseCut(ntuple) ){
                double jetMass1 = fillLeadingJetMass(ntuple);
                double jetMass2 = fillSubLeadingJetMass(ntuple);
                if( jetMass1 > 85 && jetMass1 < 135 ){
                    plots[bin][2].fillData(ntuple);
                    METprojPlots[2].fillData(ntuple);
                }else{
                    plots[bin][3].fillData(ntuple);
                    METprojPlots[3].fillData(ntuple);
                }
            }
        }
    }

    TFile* outputFile;
    if( region == 0 )
        outputFile = new TFile("ALPHABEThistos.root","RECREATE");
    if( region == 1 )
        outputFile = new TFile("ALPHABEThistos_singleMu.root","RECREATE");
    if( region == 2 )
        outputFile = new TFile("ALPHABEThistos_singleEle.root","RECREATE");
    if( region == 3 )
        outputFile = new TFile("ALPHABEThistos_lowDphi.root","RECREATE");

    for( int iBin = 0 ; iBin < numMETbins; iBin++){
        for( int iPlot = 0 ; iPlot < plots[iBin].size() ; iPlot++){
            outputFile->cd();
            plots[iBin][iPlot].Write();
            plots[iBin][iPlot].buildSum();
            plots[iBin][iPlot].sum->Write();
            
        }
    }
    for( int iPlot = 0 ; iPlot < METprojPlots.size() ; iPlot++){
        METprojPlots[iPlot].Write();
        METprojPlots[iPlot].buildSum();
        METprojPlots[iPlot].sum->Write();
    }

    outputFile->Close();

}
