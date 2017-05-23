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

using namespace std;
using namespace alphabet;

static const int MAX_EVENTS=99999999;

int main(int argc, char** argv){

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");
    
    skimSamples skims(skimSamples::kPhoton);

    typedef plot<RA2bTree> plot;
    double mJbins[4]={50.,85.,135.,250.};
    vector<vector<plot> > plots;

    for( int i = 0 ; i < numMETbins ; i++ ) {
        TString tag="_";
        tag+=lowestMET+i*binWidth;
        vector<plot> plotsTemp;
        plotsTemp.push_back(plot(*fillLeadingJetMass_photon<RA2bTree>,"mJ_tagSR"+tag,"m_{J} [GeV]",3,mJbins));
        plotsTemp.push_back(plot(*fillLeadingJetMass_photon<RA2bTree>,"mJ_tagSB"+tag,"m_{J} [GeV]",3,mJbins));
    
        plotsTemp.push_back(plot(*fillLeadingJetMass_photon<RA2bTree>,"mJ_antitagSR"+tag,"m_{J} [GeV]",3,mJbins));
        plotsTemp.push_back(plot(*fillLeadingJetMass_photon<RA2bTree>,"mJ_antitagSB"+tag,"m_{J} [GeV]",3,mJbins));
    
        plotsTemp.push_back(plot(*fillLeadingJetMass_photon<RA2bTree>,"mJ_doubletagSR"+tag,"m_{J} [GeV]",3,mJbins));
        plotsTemp.push_back(plot(*fillLeadingJetMass_photon<RA2bTree>,"mJ_doubletagSB"+tag,"m_{J} [GeV]",3,mJbins));

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
        int bin;
        double jetMass1;
        float weight;
        for( int iEvt = 0 ; iEvt < min(MAX_EVENTS,numEvents) ; iEvt++ ){
            ntuple->GetEntry(iEvt);
            if( iEvt % 100000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << min(MAX_EVENTS,numEvents) << endl;
            if(! photonBaselineCut(ntuple) ) continue;
            if( skims.sampleName[iSample] == "QCD" && ntuple->Photons_nonPrompt->at(0) == 0 && ntuple->madMinPhotonDeltaR>0.4 && ntuple->madMinDeltaRStatus==1 ) continue;
            if( skims.sampleName[iSample] == "GJets" && ntuple->Photons_nonPrompt->at(0) == 1 ) continue;

            bin = -1;
            weight = 0. ;
            if( ntuple->METclean < lowestMET ) continue;
            if( ntuple->METclean > lowestMET+binWidth*(numMETbins-1) )
                bin = numMETbins-1;
            else
                bin = int((ntuple->METclean-lowestMET)/binWidth);

            weight = ntuple->Weight*lumi*customPUweights(ntuple);
            if( doubleTaggingLooseCut_photon(ntuple) ){
                jetMass1 = fillLeadingJetMass_photon(ntuple);
                //double jetMass2 = fillSubLeadingJetMass_photon(ntuple);
                if( jetMass1 > 85 && jetMass1 < 135 ){ 
                    plots[bin][4].fill(ntuple,weight);
                    METprojPlots[4].fill(ntuple,weight);
                }else{
                    plots[bin][5].fill(ntuple,weight);
                    METprojPlots[5].fill(ntuple,weight);
                }
            }else{
                if( singleHiggsTagLooseCut_photon(ntuple) ){
                    jetMass1 = fillLeadingJetMass_photon(ntuple);
                   //double jetMass2 = fillSubLeadingJetMass_photon(ntuple);
                    if( jetMass1 > 85 && jetMass1 < 135 ){
                        plots[bin][0].fill(ntuple,weight);
                        METprojPlots[0].fill(ntuple,weight);
                    }else{
                        plots[bin][1].fill(ntuple,weight);
                        METprojPlots[1].fill(ntuple,weight);
                    }
                }
                if( antiTaggingLooseCut_photon(ntuple) ){
                    jetMass1 = fillLeadingJetMass_photon(ntuple);
                    //double jetMass2 = fillSubLeadingJetMass_photon(ntuple);
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
    int bin;
    double jetMass1;
    for( int iEvt = 0 ; iEvt < min(MAX_EVENTS,numEvents) ; iEvt++ ){
        ntuple->GetEntry(iEvt);
        if( iEvt % 100000 == 0 ) cout << "data: " << iEvt << "/" << min(MAX_EVENTS,numEvents) << endl;
        if(! photonBaselineCut(ntuple) ) continue;
        if( !ntuple->TriggerPass->at(51)==1 ) continue;

        bin = -1;
        if( ntuple->METclean < lowestMET ) continue;
        if( ntuple->METclean > lowestMET+binWidth*(numMETbins-1) )
            bin = numMETbins-1;
        else
            bin = int((ntuple->METclean-lowestMET)/binWidth);

        if( doubleTaggingLooseCut_photon(ntuple) ){
            jetMass1 = fillLeadingJetMass_photon(ntuple);
            //double jetMass2 = fillSubLeadingJetMass(ntuple);
            if( jetMass1 > 85 && jetMass1 < 135 ){
                plots[bin][4].fillData(ntuple);
                METprojPlots[4].fillData(ntuple);
            }else{
                plots[bin][5].fillData(ntuple);
                METprojPlots[5].fillData(ntuple);
            }
        }else{
            if( singleHiggsTagLooseCut_photon(ntuple) ){
                jetMass1 = fillLeadingJetMass_photon(ntuple);
                //double jetMass2 = fillSubLeadingJetMass(ntuple);
                if( jetMass1 > 85 && jetMass1 < 135 ){
                    plots[bin][0].fillData(ntuple);
                    METprojPlots[0].fillData(ntuple);
                }else{
                    plots[bin][1].fillData(ntuple);
                    METprojPlots[1].fillData(ntuple);
                }
            }
            if( antiTaggingLooseCut_photon(ntuple) ){
                jetMass1 = fillLeadingJetMass_photon(ntuple);
                //double jetMass2 = fillSubLeadingJetMass(ntuple);
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
    outputFile = new TFile("ALPHABEThistos_photon.root","RECREATE");
    
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
