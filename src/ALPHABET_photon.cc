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

    bool looseCuts(false);
    int MAX_EVENTS(99999999);

    if( argc >= 2 ){
        looseCuts = atoi(argv[1]);
        if( argc >= 3 )
            MAX_EVENTS = atoi(argv[2]);    
    }else
        cout << "Running with default cuts region ... " << endl;

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");
    
    skimSamples skims(skimSamples::kPhoton);

    typedef bool(*cuts)(RA2bTree*);
    vector<cuts> baselineCuts;

    if( looseCuts ){
        baselineCuts.push_back(*photonBaselineCut_loose<RA2bTree>);
    }else{
        baselineCuts.push_back(*photonBaselineCut<RA2bTree>);
    }

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

    //vector<plot> tempPlots;
    plot MET_Plot(*fillMETclean<RA2bTree>,"MET","m_{J} [GeV]",3,100,700);
    
    vector<plot> doubletagSRPlots;
    doubletagSRPlots.push_back(plot(MET_Plot));

    vector<plot> doubletagSBPlots;
    doubletagSBPlots.push_back(plot(MET_Plot));

    vector<plot> tagSRPlots;
    tagSRPlots.push_back(plot(MET_Plot));

    vector<plot> tagSBPlots;
    tagSBPlots.push_back(plot(MET_Plot));

    vector<plot> antitagSRPlots;
    antitagSRPlots.push_back(plot(MET_Plot));

    vector<plot> antitagSBPlots;
    antitagSBPlots.push_back(plot(MET_Plot));
    
    // background MC samples - 0 lepton regions
    for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

        RA2bTree* ntuple = skims.ntuples[iSample];

        for( int iBin = 0 ; iBin < numMETbins ; iBin++){
            for( int iPlot = 0 ; iPlot < plots[iBin].size() ; iPlot++){
                plots[iBin][iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
                plots[iBin][iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
            }
        }
        for( int iPlot = 0 ; iPlot < doubletagSRPlots.size() ; iPlot++){
            doubletagSRPlots[iPlot].addNtuple(ntuple,"doubletagSR_"+skims.sampleName[iSample]);
            doubletagSRPlots[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);  
        }
        for( int iPlot = 0 ; iPlot < doubletagSBPlots.size() ; iPlot++){
            doubletagSBPlots[iPlot].addNtuple(ntuple,"doubletagSB_"+skims.sampleName[iSample]);
            doubletagSBPlots[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);  
        }
        for( int iPlot = 0 ; iPlot < tagSRPlots.size() ; iPlot++){
            tagSRPlots[iPlot].addNtuple(ntuple,"tagSR_"+skims.sampleName[iSample]);
            tagSRPlots[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);  
        }
        for( int iPlot = 0 ; iPlot < tagSBPlots.size() ; iPlot++){
            tagSBPlots[iPlot].addNtuple(ntuple,"tagSB_"+skims.sampleName[iSample]);
            tagSBPlots[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);  
        }
        for( int iPlot = 0 ; iPlot < antitagSRPlots.size() ; iPlot++){
            antitagSRPlots[iPlot].addNtuple(ntuple,"antitagSR_"+skims.sampleName[iSample]);
            antitagSRPlots[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);  
        }
        for( int iPlot = 0 ; iPlot < antitagSBPlots.size() ; iPlot++){
            antitagSBPlots[iPlot].addNtuple(ntuple,"antitagSB_"+skims.sampleName[iSample]);
            antitagSBPlots[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);  
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
            if( doubletagSRCut_photon(ntuple) ){
                plots[bin][4].fill(ntuple,weight);
                for( int i = 0 ; i < doubletagSRPlots.size() ; i++ )
                    doubletagSRPlots[i].fill (ntuple,weight);
            }else if( doubletagSBCut_photon(ntuple) ){
                plots[bin][5].fill(ntuple,weight);
                for( int i = 0 ; i < doubletagSBPlots.size() ; i++ )
                    doubletagSBPlots[i].fill (ntuple,weight);
            }else if( tagSRCut_photon(ntuple) ){
                plots[bin][0].fill(ntuple,weight);
                for( int i = 0 ; i < tagSRPlots.size() ; i++ )
                    tagSRPlots[i].fill (ntuple,weight);
            }else if( tagSBCut_photon(ntuple) ){
                plots[bin][1].fill(ntuple,weight);
                for( int i = 0 ; i < tagSBPlots.size() ; i++ )
                    tagSBPlots[i].fill (ntuple,weight);
            }else if( antitagSRCut_photon(ntuple) ){
                plots[bin][2].fill(ntuple,weight);
                for( int i = 0 ; i < antitagSRPlots.size() ; i++ )
                    antitagSRPlots[i].fill (ntuple,weight);
            }else if( antitagSBCut_photon(ntuple) ){
                plots[bin][3].fill(ntuple,weight);
                for( int i = 0 ; i < antitagSBPlots.size() ; i++ )
                    antitagSBPlots[i].fill (ntuple,weight);
            }// end if-else-if block for tagging regions
        }// end event loop 
    }// end sample loop 


    // data 
    RA2bTree* ntuple = skims.dataNtuple;
  
    for( int iBin = 0 ; iBin < numMETbins ; iBin++){
        for( int iPlot = 0 ; iPlot < plots[iBin].size() ; iPlot++){
            plots[iBin][iPlot].addDataNtuple(ntuple,"data");
        }
    }
    for( int i = 0 ; i < doubletagSRPlots.size() ; i++ ){
        doubletagSRPlots[i].addDataNtuple(ntuple,"doubletagSR_data");
    }
    for( int i = 0 ; i < doubletagSBPlots.size() ; i++ ){
        doubletagSBPlots[i].addDataNtuple(ntuple,"doubletagSB_data");
    }
    for( int i = 0 ; i < tagSRPlots.size() ; i++ ){
        tagSRPlots[i].addDataNtuple(ntuple,"tagSR_data");
    }
    for( int i = 0 ; i < tagSBPlots.size() ; i++ ){
        tagSBPlots[i].addDataNtuple(ntuple,"tagSB_data");
    }
    for( int i = 0 ; i < antitagSRPlots.size() ; i++ ){
        antitagSRPlots[i].addDataNtuple(ntuple,"antitagSR_data");
    }
    for( int i = 0 ; i < antitagSBPlots.size() ; i++ ){
        antitagSBPlots[i].addDataNtuple(ntuple,"antitagSB_data");
    }



    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    int bin;
    double jetMass1;
    for( int iEvt = 0 ; iEvt < min(MAX_EVENTS,numEvents) ; iEvt++ ){
        ntuple->GetEntry(iEvt);
        if( iEvt % 100000 == 0 ) cout << "data: " << iEvt << "/" << min(MAX_EVENTS,numEvents) << endl;
        if( !photonBaselineCut(ntuple) ) continue;
        if( !photonTriggerCut(ntuple) ) continue;

        bin = -1;
        if( ntuple->METclean < lowestMET ) continue;
        if( ntuple->METclean > lowestMET+binWidth*(numMETbins-1) )
            bin = numMETbins-1;
        else
            bin = int((ntuple->METclean-lowestMET)/binWidth);
        
        if( doubletagSRCut_photon(ntuple) ){
            plots[bin][4].fillData(ntuple);
            for( int i = 0 ; i < doubletagSRPlots.size() ; i++ )
                doubletagSRPlots[i].fillData(ntuple);
        }else if( doubletagSBCut_photon(ntuple) ){
            plots[bin][5].fillData(ntuple);
            for( int i = 0 ; i < doubletagSBPlots.size() ; i++ )
                doubletagSBPlots[i].fillData(ntuple);
        }else if( tagSRCut_photon(ntuple) ){
            plots[bin][0].fillData(ntuple);
            for( int i = 0 ; i < tagSRPlots.size() ; i++ )
                tagSRPlots[i].fillData(ntuple);
        }else if( tagSBCut_photon(ntuple) ){
            plots[bin][1].fillData(ntuple);
            for( int i = 0 ; i < tagSBPlots.size() ; i++ )
                tagSBPlots[i].fillData(ntuple);
        }else if( antitagSRCut_photon(ntuple) ){
            plots[bin][2].fillData(ntuple);
            for( int i = 0 ; i < antitagSRPlots.size() ; i++ )
                antitagSRPlots[i].fillData(ntuple);
        }else if( antitagSBCut_photon(ntuple) ){
            plots[bin][3].fillData(ntuple);
            for( int i = 0 ; i < antitagSBPlots.size() ; i++ )
                antitagSBPlots[i].fillData(ntuple);
        }// end if-else-if block for tagging regions
    }// end event loop 

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

    for( int i = 0 ; i < doubletagSRPlots.size() ; i++ ){
        outputFile->cd();
        doubletagSRPlots[i].buildSum("doubletagSR");
        doubletagSRPlots[i].Write();
        doubletagSRPlots[i].sum->Write();
    }
    for( int i = 0 ; i < doubletagSBPlots.size() ; i++ ){
        outputFile->cd();
        doubletagSBPlots[i].buildSum("doubletagSB");
        doubletagSBPlots[i].Write();
        doubletagSBPlots[i].sum->Write();
    }
    for( int i = 0 ; i < tagSRPlots.size() ; i++ ){
        outputFile->cd();
        tagSRPlots[i].buildSum("tagSR");
        tagSRPlots[i].Write();
        tagSRPlots[i].sum->Write();
    }
    for( int i = 0 ; i < tagSBPlots.size() ; i++ ){
        outputFile->cd();
        tagSBPlots[i].buildSum("tagSB");
        tagSBPlots[i].Write();
        tagSBPlots[i].sum->Write();
    }
    for( int i = 0 ; i < antitagSRPlots.size() ; i++ ){
        outputFile->cd();
        antitagSRPlots[i].buildSum("antitagSR");
        antitagSRPlots[i].Write();
        antitagSRPlots[i].sum->Write();
    }
    for( int i = 0 ; i < antitagSBPlots.size() ; i++ ){
        outputFile->cd();
        antitagSBPlots[i].buildSum("antitagSB");
        antitagSBPlots[i].Write();
        antitagSBPlots[i].sum->Write();
    }

    outputFile->Close();
}
