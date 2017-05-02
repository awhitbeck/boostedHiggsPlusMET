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

int main(int argc, char** argv){

    gROOT->ProcessLine(".L ~/tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");
    
    skimSamples skims(skimSamples::kPhoton);

    typedef plot<RA2bTree> plot;

    vector<vector<plot> > plots;

    for( int i = 0 ; i < numMETbins ; i++ ) {
        TString tag="_";
        tag+=lowestMET+i*binWidth;
        vector<plot> plotsTemp;
        plotsTemp.push_back(plot(*fillLeadingJetMass_photon<RA2bTree>,"mJ_tagSR"+tag,"m_{J} [GeV]",40,50.,250.));
        plotsTemp.push_back(plot(*fillLeadingJetMass_photon<RA2bTree>,"mJ_tagSB"+tag,"m_{J} [GeV]",40,50.,250.));
    
        plotsTemp.push_back(plot(*fillLeadingJetMass_photon<RA2bTree>,"mJ_antitagSR"+tag,"m_{J} [GeV]",40,50.,250.));
        plotsTemp.push_back(plot(*fillLeadingJetMass_photon<RA2bTree>,"mJ_antitagSB"+tag,"m_{J} [GeV]",40,50.,250.));
    
        plotsTemp.push_back(plot(*fillLeadingJetMass_photon<RA2bTree>,"mJ_doubletagSR"+tag,"m_{J} [GeV]",40,50.,250.));
        plotsTemp.push_back(plot(*fillLeadingJetMass_photon<RA2bTree>,"mJ_doubletagSB"+tag,"m_{J} [GeV]",40,50.,250.));

        plots.push_back(plotsTemp);
    }

    // background MC samples - 0 lepton regions
    for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

        RA2bTree* ntuple = skims.ntuples[iSample];

        for( int iBin = 0 ; iBin < numMETbins ; iBin++){
            for( int iPlot = 0 ; iPlot < plots[iBin].size() ; iPlot++){
                plots[iBin][iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
                plots[iBin][iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
            }
        }

        int numEvents = ntuple->fChain->GetEntries();
        ntupleBranchStatus<RA2bTree>(ntuple);
        for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
            ntuple->GetEntry(iEvt);
            if( iEvt % 100000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
            if(! photonBaselineCut(ntuple) ) continue;
            if( skims.sampleName[iSample] == "QCD" && ntuple->Photons_nonPrompt->at(0) == 0 ) continue;
            if( skims.sampleName[iSample] == "GJets" && ntuple->Photons_nonPrompt->at(0) == 1 ) continue;

            int bin = -1;
            for( int iBin = 0 ; iBin < numMETbins ; iBin++ ){
                if( ntuple->MET > lowestMET ){
                    if( ntuple->MET > numMETbins*(binWidth-1)+lowestMET )
                        bin = numMETbins-1;
                    else
                        bin = int((ntuple->MET-lowestMET)/binWidth);
                }
            }
            if( bin < 0 ) continue;
      
            if( doubleTaggingLooseCut_photon(ntuple) ){
                double jetMass1 = fillLeadingJetMass_photon(ntuple);
                //double jetMass2 = fillSubLeadingJetMass(ntuple);
                if( ( jetMass1 > 85 && jetMass1 < 135 ) /*&& ( jetMass2 > 85 && jetMass2 < 135 )*/ ){
                    plots[bin][4].fill(ntuple);
                }else /*if( ( ( jetMass1 > 50 && jetMass1 < 85 ) || ( jetMass1 > 135 && jetMass1 < 250 ) ) !=  ( ( jetMass2 > 50 && jetMass2 < 85 ) || ( jetMass2 > 135 && jetMass2 < 250 ) ) )*/{ 
                    plots[bin][5].fill(ntuple);
                }
            }else{
                if( singleHiggsTagLooseCut_photon(ntuple) ){
                    double jetMass1 = fillLeadingJetMass_photon(ntuple);
                    //double jetMass2 = fillSubLeadingJetMass(ntuple);
                    if( ( jetMass1 > 85 && jetMass1 < 135 ) /*&& ( jetMass2 > 85 && jetMass2 < 135 )*/ ){
                        plots[bin][0].fill(ntuple);
                    }else /*if( ( ( jetMass1 > 50 && jetMass1 < 85 ) || ( jetMass1 > 135 && jetMass1 < 250 ) ) !=  ( ( jetMass2 > 50 && jetMass2 < 85 ) || ( jetMass2 > 135 && jetMass2 < 250 ) ) )*/{ 
                        plots[bin][1].fill(ntuple);
                    }
                }
                if( antiTaggingLooseCut_photon(ntuple) ){
                    double jetMass1 = fillLeadingJetMass_photon(ntuple);
                    //double jetMass2 = fillSubLeadingJetMass(ntuple);
                    if( ( jetMass1 > 85 && jetMass1 < 135 ) /*&& ( jetMass2 > 85 && jetMass2 < 135 )*/ ){
                        plots[bin][2].fill(ntuple);
                    }else /*if( ( ( jetMass1 > 50 && jetMass1 < 85 ) || ( jetMass1 > 135 && jetMass1 < 250 ) ) !=  ( ( jetMass2 > 50 && jetMass2 < 85 ) || ( jetMass2 > 135 && jetMass2 < 250 ) ) )*/{ 
                        plots[bin][3].fill(ntuple);
                    }
                }
            }
        }
    }


    // data 
    RA2bTree* ntuple = skims.dataNtuple;
  
    for( int iBin = 0 ; iBin < numMETbins ; iBin++){
        for( int iPlot = 0 ; iPlot < plots[iBin].size() ; iPlot++){
            plots[iBin][iPlot].addDataNtuple(ntuple,"data");
        }
    }

    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
        ntuple->GetEntry(iEvt);
        if( iEvt % 100000 == 0 ) cout << "data: " << iEvt << "/" << numEvents << endl;
        if(! photonBaselineCut(ntuple) ) continue;
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
      
        if( doubleTaggingLooseCut_photon(ntuple) ){
            double jetMass1 = fillLeadingJetMass_photon(ntuple);
            //double jetMass2 = fillSubLeadingJetMass(ntuple);
            if( ( jetMass1 > 85 && jetMass1 < 135 ) /*&& ( jetMass2 > 85 && jetMass2 < 135 )*/ ){
                plots[bin][4].fillData(ntuple);
            }else /*if( ( ( jetMass1 > 50 && jetMass1 < 85 ) || ( jetMass1 > 135 && jetMass1 < 250 ) ) !=  ( ( jetMass2 > 50 && jetMass2 < 85 ) || ( jetMass2 > 135 && jetMass2 < 250 ) ) )*/{ 
                plots[bin][5].fillData(ntuple);
            }
        }else{
            if( singleHiggsTagLooseCut_photon(ntuple) ){
                double jetMass1 = fillLeadingJetMass_photon(ntuple);
                //double jetMass2 = fillSubLeadingJetMass(ntuple);
                if( ( jetMass1 > 85 && jetMass1 < 135 ) /*&& ( jetMass2 > 85 && jetMass2 < 135 )*/ ){ 
                    plots[bin][0].fillData(ntuple);
                }else /*if( ( ( jetMass1 > 50 && jetMass1 < 85 ) || ( jetMass1 > 135 && jetMass1 < 250 ) ) !=  ( ( jetMass2 > 50 && jetMass2 < 85 ) || ( jetMass2 > 135 && jetMass2 < 250 ) ) )*/{ 
                    plots[bin][1].fillData(ntuple);
                }
            }
            if( antiTaggingLooseCut_photon(ntuple) ){
                double jetMass1 = fillLeadingJetMass_photon(ntuple);
                //double jetMass2 = fillSubLeadingJetMass(ntuple);
                if( ( jetMass1 > 85 && jetMass1 < 135 ) /*&& ( jetMass2 > 85 && jetMass2 < 135 )*/ ){
                    plots[bin][2].fillData(ntuple);
                }else /*if( ( ( jetMass1 > 50 && jetMass1 < 85 ) || ( jetMass1 > 135 && jetMass1 < 250 ) ) !=  ( ( jetMass2 > 50 && jetMass2 < 85 ) || ( jetMass2 > 135 && jetMass2 < 250 ) ) )*/{ 
                    plots[bin][3].fillData(ntuple);
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
    outputFile->Close();
}
