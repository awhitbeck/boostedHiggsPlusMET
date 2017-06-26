#include "TString.h"
#include "TChain.h"
#include "TH1F.h"
#include "TROOT.h"
#include "THStack.h"
#include "TPad.h"

#include <vector>
#include <map>
#include <iostream>
#include "ALPHABET.h"
#include "plotterUtils.cc"
#include "skimSamples.cc"
#include "definitions.cc"
#include "TriggerEfficiencySextet.cc"
#include "RA2bTree.cc"
using namespace std;

int main(int argc, char** argv){

    gROOT->ProcessLine(".L ./tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");
  
    skimSamples skims;
    typedef plot<RA2bTree> plot;
    double METBins[4] = {300.,500.,700.,2500.};

    /*
      plot BinsSRSingleHiggsPlot(*fillAnalysisBins<RA2bTree>,"AnalysisMETBins_tagSR","MET",3,METBins);
      plot BinsSRAntiTagPlot(*fillAnalysisBins<RA2bTree>,"AnalysisMETBins_antitagSR","MET",3,METBins);
      plot BinsSBSingleHiggsPlot(*fillAnalysisBins<RA2bTree>,"AnalysisMETBins_tagSB","MET",3,METBins);
      plot BinsSBAntiTagPlot(*fillAnalysisBins<RA2bTree>,"AnalysisMETBins_antitagSB","MET",3,METBins);
    */
    vector<TH1D*> plots;
    //plots.push_back(BinsSRSingleHiggsPlot);
    //plots.push_back(BinsSRAntiTagPlot);
    //plots.push_back(BinsSBSingleHiggsPlot);
    // plots.push_back(BinsSBAntiTagPlot);


    // Signal samples
    for( int iSample = 0 ; iSample < skims.signalNtuples.size() ; iSample++){
	TH1D*JetMassSmear1=new TH1D("JetMassSmear1_"+skims.signalSampleName[iSample], "", 40, 50,250);
	TH1D*JetMassSmear2=new TH1D("JetMassSmear2_"+skims.signalSampleName[iSample], "", 40, 50,250);

	TH1D*JetPt300MassUnsmear=new TH1D("JetPt300MassUnsmear_"+skims.signalSampleName[iSample], "", 200, 50,250);
	TH1D*JetPt400MassUnsmear=new TH1D("JetPt400MassUnsmear_"+skims.signalSampleName[iSample], "", 200, 50,250);
	TH1D*JetPt600MassUnsmear=new TH1D("JetPt600MassUnsmear_"+skims.signalSampleName[iSample], "", 200, 50,250);
	TH1D*JetPt800MassUnsmear=new TH1D("JetPt800MassUnsmear_"+skims.signalSampleName[iSample], "", 200, 50,250);
	TH1D*JetPt1000MassUnsmear=new TH1D("JetPt1000MassUnsmear_"+skims.signalSampleName[iSample], "", 200, 50,250);
	TH1D*JetPt300Masssmear=new TH1D("JetPt300Masssmear_"+skims.signalSampleName[iSample], "", 200, 50,250);
	TH1D*JetPt400Masssmear=new TH1D("JetPt400Masssmear_"+skims.signalSampleName[iSample], "", 200, 50,250);
	TH1D*JetPt600Masssmear=new TH1D("JetPt600Masssmear_"+skims.signalSampleName[iSample], "", 200, 50,250);
	TH1D*JetPt800Masssmear=new TH1D("JetPt800Masssmear_"+skims.signalSampleName[iSample], "", 200, 50,250);
	TH1D*JetPt1000Masssmear=new TH1D("JetPt1000Masssmear_"+skims.signalSampleName[iSample], "", 200, 50,250);
        
	TH1D*JetMassUnsmear1=new TH1D("JetMassUnsmear1_"+skims.signalSampleName[iSample], "", 40, 50,250);
	TH1D*JetMassUnsmear2=new TH1D("JetMassUnsmear2_"+skims.signalSampleName[iSample], "", 40, 50,250);
 	TH1D*JetPt1=new TH1D("JetPt1_"+skims.signalSampleName[iSample],"p_{T,J} [GeV]",40,300.,2300.);
 	TH1D*JetPt2=new TH1D("JetPt2_"+skims.signalSampleName[iSample],"p_{T,J} [GeV]",40,300.,2300.);
        RA2bTree* ntuple = skims.signalNtuples[iSample];
        ntupleBranchStatus<RA2bTree>(ntuple);

        int numEvents = ntuple->fChain->GetEntries();
        float trigWeight,weight,MET;
        double jetMass1,jetMass2;
        vector<double> EfficiencyCenterUpDown;

        for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
            ntuple->GetEntry(iEvt);
            if( iEvt % 10000 == 0 ) cout << skims.signalSampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
	 //   if(skims.signalSampleName[iSample]!="T5HH750" )break;
            if(!baselineCut(ntuple) ) continue;
            //std::cout<<"Gen Higgs Content "<<getNumGenHiggses(ntuple)<<std::endl;
            if(getNumGenHiggses(ntuple)<2) continue;
          //  if(getNumGenZs(ntuple)<2) continue;
            MET=ntuple->MET;
            EfficiencyCenterUpDown = Eff_MetMhtSextetReal_CenterUpDown(ntuple->HT, ntuple->MHT, ntuple->NJets);
            trigWeight=EfficiencyCenterUpDown[0];
            weight = trigWeight;	
	    double DoubleTagSF=doubleBSF(ntuple,0)*doubleBSF(ntuple,1);
	    double AntiTagSF=1.0/(doubleBSF(ntuple,0))*1.0/(doubleBSF(ntuple,1));
                jetMass1 = fillLeadingJetMass(ntuple);
                jetMass2 = fillSubLeadingJetMass(ntuple);
       	JetMassUnsmear1->Fill(jetMass1);
       	JetMassUnsmear2->Fill(jetMass2);
//		jetMass1=ResolutionSmear(jetMass1);
//		jetMass2=ResolutionSmear(jetMass2);
       	JetMassSmear1->Fill(jetMass1);
       	JetMassSmear2->Fill(jetMass2);
	double jetPt1=fillJetPt1(ntuple);
	double jetPt2=fillJetPt2(ntuple);
	JetPt1->Fill(jetPt1);
	JetPt2->Fill(jetPt2);
	int leadJetFlavor= fillLeadingJetFlavor(ntuple);
	int subleadJetFlavor= fillSubLeadingJetFlavor(ntuple);
        double jetMass1Smear=ResolutionSmear(ntuple,0,iEvt);
        double jetMass2Smear=ResolutionSmear(ntuple,1,iEvt);
	if(leadJetFlavor==21 && getClosestGenHiggses(ntuple,ntuple->JetsAK8->at(0).Eta(), ntuple->JetsAK8->at(0).Phi())<0.8){
	//if(getClosestGenZ(ntuple,ntuple->JetsAK8->at(0).Eta(), ntuple->JetsAK8->at(0).Phi())<0.8){
	//if(getClosestGenHiggses(ntuple,ntuple->JetsAK8->at(0).Eta(), ntuple->JetsAK8->at(0).Phi())<0.8){
	if(jetPt1>300 && jetPt1<=400)JetPt300MassUnsmear->Fill(jetMass1);
	if(jetPt1>400 && jetPt1<=600)JetPt400MassUnsmear->Fill(jetMass1);
	if(jetPt1>600 && jetPt1<=800)JetPt600MassUnsmear->Fill(jetMass1);
	if(jetPt1>800 && jetPt1<=1000)JetPt800MassUnsmear->Fill(jetMass1);
	if(jetPt1>1000 )JetPt1000MassUnsmear->Fill(jetMass1);
	if(jetPt1>300 && jetPt1<=400)JetPt300Masssmear->Fill(jetMass1Smear);
	if(jetPt1>400 && jetPt1<=600)JetPt400Masssmear->Fill(jetMass1Smear);
	if(jetPt1>600 && jetPt1<=800)JetPt600Masssmear->Fill(jetMass1Smear);
	if(jetPt1>800 && jetPt1<=1000)JetPt800Masssmear->Fill(jetMass1Smear);
	if(jetPt1>1000 )JetPt1000Masssmear->Fill(jetMass1Smear);
	}
	if(subleadJetFlavor==21 && getClosestGenHiggses(ntuple,ntuple->JetsAK8->at(1).Eta(), ntuple->JetsAK8->at(1).Phi())<0.8){
	//if(getClosestGenZ(ntuple,ntuple->JetsAK8->at(1).Eta(), ntuple->JetsAK8->at(1).Phi())<0.8){
	//if(getClosestGenHiggses(ntuple,ntuple->JetsAK8->at(1).Eta(), ntuple->JetsAK8->at(1).Phi())<0.8){
	if(jetPt2>300 && jetPt2<=400)JetPt300MassUnsmear->Fill(jetMass2);
	if(jetPt2>400 && jetPt2<=600)JetPt400MassUnsmear->Fill(jetMass2);
	if(jetPt2>600 && jetPt2<=800)JetPt600MassUnsmear->Fill(jetMass2);
	if(jetPt2>800 && jetPt2<=1000)JetPt800MassUnsmear->Fill(jetMass2);
	if(jetPt2>1000 )JetPt1000MassUnsmear->Fill(jetMass2);
	if(jetPt2>300 && jetPt2<=400)JetPt300Masssmear->Fill(jetMass2Smear);
	if(jetPt2>400 && jetPt2<=600)JetPt400Masssmear->Fill(jetMass2Smear);
	if(jetPt2>600 && jetPt2<=800)JetPt600Masssmear->Fill(jetMass2Smear);
	if(jetPt2>800 && jetPt2<=1000)JetPt800Masssmear->Fill(jetMass2Smear);
	if(jetPt2>1000 )JetPt1000Masssmear->Fill(jetMass2Smear);
	}
        }
	plots.push_back(JetMassSmear1);
	plots.push_back(JetMassSmear2);
	plots.push_back(JetPt300MassUnsmear);
	plots.push_back(JetPt400MassUnsmear);
	plots.push_back(JetPt600MassUnsmear);
	plots.push_back(JetPt800MassUnsmear);
	plots.push_back(JetPt1000MassUnsmear);
	plots.push_back(JetPt300Masssmear);
	plots.push_back(JetPt400Masssmear);
	plots.push_back(JetPt600Masssmear);
	plots.push_back(JetPt800Masssmear);
	plots.push_back(JetPt1000Masssmear);
	plots.push_back(JetMassUnsmear1);
	plots.push_back(JetMassUnsmear2);
	plots.push_back(JetPt1);
	plots.push_back(JetPt2);

    }

    /*
      if( taggingCut(ntuple) ){
      double jetMass = fillLeadingBBtagJetMass(ntuple);
      if( jetMass > 85 && jetMass < 135 ){ 
	  plots[0].fillSignal(ntuple);
      }else if( jetMass > 55 && jetMass < 205){
	  plots[2].fillSignal(ntuple);
      }
      }
      if( antiTaggingCut(ntuple) ){
      double jetMass = fillLeadingBBtagJetMass(ntuple);
      if( jetMass > 85 && jetMass < 135 ){
	  plots[1].fillSignal(ntuple);
      }else if( jetMass > 55 && jetMass < 205){
	  plots[3].fillSignal(ntuple);
      }
      }
    */
    //}
    // }
    TFile* outputFile = new TFile("datacardInputsMassResolutionSmearH.root","RECREATE");
    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
        //plots[iPlot].Draw(can,skims.ntuples,skims.signalNtuples);
        outputFile->cd();
        plots[iPlot]->Write();
    }
    outputFile->Close();

}
