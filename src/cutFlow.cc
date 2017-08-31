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

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    int region(0);
    int MAX_EVENTS(99999999);
    if( argc >= 2 ) 
        region = atoi(argv[1]);
    if( argc >= 3 ) 
        MAX_EVENTS = atoi(argv[2]);

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
        skims_ = new skimSamples(skimSamples::kLowDphi);
    else        
        assert(1);
    
    skimSamples skims = *skims_;

    typedef plot<RA2bTree> plot;
    typedef bool(*cutFunc)(RA2bTree*);
    vector<cutFunc> cutFlow;
    vector<TString> cutName;

    cutFlow.push_back(*FiltersCut<RA2bTree>);
    cutName.push_back("Filters");
    
    if( region == 3 ){ 
        cutFlow.push_back(*lowDPhiCuts<RA2bTree>);
        cutName.push_back("lowDeltaPhi");
    }else{
        cutFlow.push_back(*DeltaPhiCuts<RA2bTree>);
        cutName.push_back("DeltaPhi");
    }
    
    if( region == 1 ){
        cutFlow.push_back(*singleMuCut<RA2bTree>);
        cutName.push_back("SingleMu");
    }
    if( region == 2 ){
        cutFlow.push_back(*singleEleCut<RA2bTree>);
        cutName.push_back("SingleEle");
    }

    cutFlow.push_back(*METHTlooseCut<RA2bTree>);
    cutName.push_back("METHTLoose");
    cutFlow.push_back(*METHTCut<RA2bTree>);
    cutName.push_back("METHT");
    cutFlow.push_back(*AK8MultCut<RA2bTree>);
    cutName.push_back("AK8Multiplicity");
    cutFlow.push_back(*AK8JetPtCut<RA2bTree>);
    cutName.push_back("JetPt");
    cutFlow.push_back(*AK8JetLooseMassCut<RA2bTree>);
    cutName.push_back("LooseJetMass");
    cutFlow.push_back(*OneOrMoreHiggsTagLooseCut<RA2bTree>);
    cutName.push_back("OnePlusBBtag");
    cutFlow.push_back(*doubleTaggingLooseCut<RA2bTree>);
    cutName.push_back("doubleBBtag");
    cutFlow.push_back(*doubleMassCut<RA2bTree>);
    cutName.push_back("doubleMass");

    //vector<vector<plot> > plots;
    vector<vector<plot> > plots;

    for( int iCut = 0 ; iCut < cutFlow.size() ; iCut++ ){

        vector<plot> tempPlots;
        tempPlots.push_back(plot(*fillMET<RA2bTree>,"MET_"+cutName[iCut],"MET [GeV]",20,300.,1300.));
        tempPlots.push_back(plot(*fillMET<RA2bTree>,"METwide_"+cutName[iCut],"MET [GeV]",24,0.,800.));
        tempPlots.push_back(plot(*fillHT<RA2bTree>,"HT_"+cutName[iCut],"H_{T} [GeV]",17,300,2000.));
        tempPlots.push_back(plot(*fillLeadingJetMass<RA2bTree>,"J1M_"+cutName[iCut],"leading m_{J} [GeV]",20,50.,200.));
        tempPlots.push_back(plot(*fillLeadingJetMass<RA2bTree>,"J1Mwide_"+cutName[iCut],"leading m_{J} [GeV]",20,0.,200.));
        tempPlots.push_back(plot(*fillLeadingBBtag<RA2bTree>,"J1BB_"+cutName[iCut],"leading bb-tag",20,-1.,1.));
        tempPlots.push_back(plot(*fillLeadingTau21<RA2bTree>,"J1Tau21_"+cutName[iCut],"leading #tau_{21}",20,0.,1.));
        tempPlots.push_back(plot(*fillLeadingJetPt<RA2bTree>,"J1Pt_"+cutName[iCut],"leading p_{T,J} [GeV]",40,300.,2300.));
        tempPlots.push_back(plot(*fillLeadingJetPt<RA2bTree>,"J1PtWide_"+cutName[iCut],"leading p_{T,J} [GeV]",46,0.,2300.));
        tempPlots.push_back(plot(*fillSubLeadingJetMass<RA2bTree>,"J2M_"+cutName[iCut],"subleading m_{J} [GeV]",20,50.,200.));
        tempPlots.push_back(plot(*fillSubLeadingJetMass<RA2bTree>,"J2Mwide_"+cutName[iCut],"subleading m_{J} [GeV]",20,0.,200.));
        tempPlots.push_back(plot(*fillSubLeadingBBtag<RA2bTree>,"J2BB_"+cutName[iCut],"subleading bb-tag",20,-1.,1.));
        tempPlots.push_back(plot(*fillSubLeadingTau21<RA2bTree>,"J2Tau21_"+cutName[iCut],"subleading #tau_{21}",20,0.,1.));
        tempPlots.push_back(plot(*fillSubLeadingJetPt<RA2bTree>,"J2Pt_"+cutName[iCut],"subleading p_{T,J} [GeV]",40,300.,2300.));
        tempPlots.push_back(plot(*fillSubLeadingJetPt<RA2bTree>,"J2PtWide_"+cutName[iCut],"subleading p_{T,J} [GeV]",46,0.,2300.));
        tempPlots.push_back(plot(*fillDeltaPhi1<RA2bTree>,"DeltaPhi1_"+cutName[iCut],"#Delta#Phi_{1}",20,0.,3.1415));
        tempPlots.push_back(plot(*fillDeltaPhi2<RA2bTree>,"DeltaPhi2_"+cutName[iCut],"#Delta#Phi_{2}",20,0.,3.1415));
        tempPlots.push_back(plot(*fillDeltaPhi3<RA2bTree>,"DeltaPhi3_"+cutName[iCut],"#Delta#Phi_{3}",20,0.,3.1415));
        tempPlots.push_back(plot(*fillDeltaPhi4<RA2bTree>,"DeltaPhi4_"+cutName[iCut],"#Delta#Phi_{4}",20,0.,3.1415));

        tempPlots.push_back(plot(*fillJetPt1<RA2bTree>,"Ak4JetPt1_"+cutName[iCut],"p_{T,j1} [GeV]",50,0,1000));
        tempPlots.push_back(plot(*fillJetPt2<RA2bTree>,"Ak4JetPt2_"+cutName[iCut],"p_{T,j2} [GeV]",50,0,1000));
        tempPlots.push_back(plot(*fillJetPt3<RA2bTree>,"Ak4JetPt3_"+cutName[iCut],"p_{T,j3} [GeV]",50,0,600));
        tempPlots.push_back(plot(*fillJetPt4<RA2bTree>,"Ak4JetPt4_"+cutName[iCut],"p_{T,j4} [GeV]",50,0,500));

        plots.push_back(tempPlots);
    }

    // background MC samples
  
    for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

        RA2bTree* ntuple = skims.ntuples[iSample];
        for( int iCut = 0 ; iCut < plots.size() ; iCut++){
            for( int iPlot = 0 ; iPlot < plots[iCut].size() ; iPlot++){
                plots[iCut][iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
                plots[iCut][iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
                plots[iCut][iPlot].dataHist=0;
            }
        }

        int numEvents = ntuple->fChain->GetEntries();
        ntupleBranchStatus<RA2bTree>(ntuple);
        double weight = 0.;
        TString filename;
        for( int iEvt = 0 ; iEvt < min(MAX_EVENTS,numEvents) ; iEvt++ ){
            ntuple->GetEntry(iEvt);
            if( iEvt % 100000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
            
            filename = ntuple->fChain->GetFile()->GetName();
            if( ( filename.Contains("SingleLept") || filename.Contains("DiLept") ) && ntuple->madHT>600. )continue;

            // ----------- compute weights --------------
            weight = ntuple->Weight*lumi*customPUweights(ntuple);
            //cout << "xsec weight: " << ntuple->Weight*lumi << endl;
            //if( skims.sampleName[iSample] == "TT" ){
            //    weight *= ISRweights(ntuple);
            //    //cout << "ISR: " << ISRweights(ntuple) << endl;
            // }
            if(region==0){
                std::vector<double> EfficiencyCenterUpDown = Eff_MetMhtSextetReal_CenterUpDown(ntuple->HT, ntuple->MHT, ntuple->NJets);
                weight*=EfficiencyCenterUpDown[0];
            }else if( region == 1 ){
                weight*=singleMuonTrigWeights(ntuple);
            }else if( region == 2 ){
                weight*=singleElectronTrigWeights(ntuple);
            }else if( region == 3 ){
                weight*=lowDphiTrigWeights(ntuple);
            }
            // ------------------------------------------
            for( int iCut = 0 ; iCut < cutFlow.size() ; iCut++ ){
                if( ! cutFlow[iCut](ntuple) ) break;
                for( int iPlot = 0 ; iPlot < plots[iCut].size() ; iPlot++ ){
                    plots[iCut][iPlot].fill(ntuple,weight);
                }
            }
        }
    }
    
    // Signal samples
    vector<RA2bTree*> sigSamples;
    for( int iSample = 0 ; iSample < ( region == 0 ? skims.signalNtuples.size() : 0 )  ; iSample++){
        if( skims.signalSampleName[iSample] != "T5HH1300" && skims.signalSampleName[iSample] != "T5HH1700" ) continue;
            
        RA2bTree* ntuple = skims.signalNtuples[iSample];
        sigSamples.push_back(ntuple);
        for( int iCut = 0 ; iCut < cutFlow.size() ; iCut++){
            for( int iPlot = 0 ; iPlot < plots[iCut].size() ; iPlot++){
                plots[iCut][iPlot].addSignalNtuple(ntuple,skims.signalSampleName[iSample]);
                plots[iCut][iPlot].setLineColor(ntuple,skims.sigLineColor[iSample]);
            }
        }

        int numEvents = ntuple->fChain->GetEntries();
        ntupleBranchStatus<RA2bTree>(ntuple);
        for( int iEvt = 0 ; iEvt < min(MAX_EVENTS,numEvents) ; iEvt++ ){
            ntuple->GetEntry(iEvt);
            if( iEvt % 100000 == 0 ) cout << skims.signalSampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
            if( !genLevelHHcut(ntuple) ) continue;
            for( int iCut = 0 ; iCut < cutFlow.size() ; iCut++ ){
                if( ! cutFlow[iCut](ntuple) ) break;
                for( int iPlot = 0 ; iPlot < plots[iCut].size() ; iPlot++ ){
                    if( skims.signalSampleName[iSample] == "T5HH1300" )
                        plots[iCut][iPlot].fillSignal(ntuple,lumi*0.0460525/102482.);
                    if( skims.signalSampleName[iSample] == "T5HH1700" )
                        plots[iCut][iPlot].fillSignal(ntuple,lumi*0.00470323/103791.);
                }
            }
        }
    }

    // data
    RA2bTree* ntuple = skims.dataNtuple;
    for( int iCut = 0 ; iCut < cutFlow.size() ; iCut++){
        for( int iPlot = 0 ; iPlot < plots[iCut].size() ; iPlot++){
            plots[iCut][iPlot].addDataNtuple(ntuple,"data");
        }
    }
  
    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    for( int iEvt = 0 ; iEvt < min(MAX_EVENTS,numEvents) ; iEvt++ ){
        ntuple->GetEntry(iEvt);
        if( iEvt % 100000 == 0 ) cout << "data: " << iEvt << "/" << min(MAX_EVENTS,numEvents) << endl;
        if( region == 0 ){
            if( !signalTriggerCut(ntuple) ) continue;
        }else if( region == 1){
            if( !singleMuTriggerCut(ntuple) ) continue;
        }else if( region == 2){
            if( !singleEleTriggerCut(ntuple) ) continue;
        }else if( region == 3 ){ 
            if( !lowDphiTriggerCut(ntuple) ) continue;
        }
        for( int iCut = 0 ; iCut < cutFlow.size() ; iCut++ ){
            if( ! cutFlow[iCut](ntuple) ) break;
            for( int iPlot = 0 ; iPlot < plots[iCut].size() ; iPlot++ ){
                plots[iCut][iPlot].fillData(ntuple);
            }
        }
    }

    TString outputDir[4]={"../plots/cutFlow_plots","../plots/cutFlow_singleMuCR_plots","../plots/cutFlow_singleEleCR_plots","../plots/cutFlow_lowDPhi_plots"};
    for( int iCut = 0 ; iCut < cutFlow.size() ; iCut++ ){
        for( int iPlot = 0 ; iPlot < plots[iCut].size() ; iPlot++){
            TCanvas* can = new TCanvas("can","can",500,500);
            if( region == 0 )
                plots[iCut][iPlot].DrawNoRatio(can,skims.ntuples,sigSamples,outputDir[region]);
            else
                plots[iCut][iPlot].Draw(can,skims.ntuples,sigSamples,outputDir[region],0.1,2.0,true);
        }
    }

    cout << " & All Bkg. " << endl;
    for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){ 
        cout << " & " << skims.sampleName[iSample] ; 
    }
    for( int iSample = 0 ; iSample < ( region == 0 ? skims.signalNtuples.size() : 0 ) ; iSample++){
        cout << " & " << skims.signalSampleName[iSample] ;
    }
    cout << endl;
    cout << "% ------------------------------------------------------------------" << endl;
    for( int iCut = 0 ; iCut < cutFlow.size() ; iCut++ ){
        plots[iCut][0].buildSum();
        cout << cutName[iCut] << " & " << plots[iCut][0].sum->Integral();
        for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){ 
            RA2bTree* ntuple = skims.ntuples[iSample];
            cout << " & " << plots[iCut][0].histoMap[ntuple]->Integral();
        }
        for( int iSample = 0 ; iSample < ( region == 0 ? skims.signalNtuples.size() : 0 ) ; iSample++){
            RA2bTree* ntuple = skims.signalNtuples[iSample];
            cout << " & " << plots[iCut][0].signalHistoMap[ntuple]->Integral();
        }
        cout << " & " << plots[iCut][0].dataHist->Integral();
        cout << " \\\\ \\hline" << endl;
    }
}
