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
#include "TriggerEfficiencySextet.cp"
#include "RA2bTree.cc"
using namespace std;

int main(int argc, char** argv){

  gROOT->ProcessLine(".L ~/tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");
  
  skimSamples skims;
  typedef plot<RA2bTree> plot;
  double METBins[4] = {300.,500.,700.,2500.};
  TFile*inputFile = new TFile("ALPHABEThistos.root","read");
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
 for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){
	std::cout<<"Sample Name "<<skims.sampleName[iSample]<<std::endl;
	TH1D*AnalysisMETBins_tagSR=new TH1D("AnalysisMETBins_tagSR_"+skims.sampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETBins_antitagSR=new TH1D("AnalysisMETBins_antitagSR_"+skims.sampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETBins_tagSB=new TH1D("AnalysisMETBins_tagSB_"+skims.sampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETBins_antitagSB=new TH1D("AnalysisMETBins_antitagSB_"+skims.sampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETBins_doubletagSB=new TH1D("AnalysisMETBins_doubletagSB_"+skims.sampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETBins_doubletagSR=new TH1D("AnalysisMETBins_doubletagSR_"+skims.sampleName[iSample],"MET",3,METBins) ;
    for( int i = 1 ; i < alphabet::numMETbins ; i++ ) {
        TString tag="_";
        tag+=TString::Format("%d",alphabet::lowestMET+i*alphabet::binWidth)+"_"+skims.sampleName[iSample];
	TString signalantitag="mJ_antitagSR"+tag;
	TString signal1Htag="mJ_tagSR"+tag;
	TString signal2Htag="mJ_doubletagSR"+tag;
	TString sideband1Htag="mJ_tagSB"+tag;
	TString sideband2Htag="mJ_doubletagSB"+tag;
	TString sidebandantitag="mJ_antitagSB"+tag;
	double error=0;
	//std::cout<<tag<<std::endl;
	double MetBin=((TH1F*)inputFile->Get(signal2Htag))->IntegralAndError(1,40,error);
	AnalysisMETBins_doubletagSR->SetBinContent(i, MetBin);
	AnalysisMETBins_doubletagSR->SetBinError(i, error);
	MetBin=((TH1F*)inputFile->Get(signal1Htag))->IntegralAndError(1,40,error);
	AnalysisMETBins_tagSR->SetBinContent(i, MetBin);
	AnalysisMETBins_tagSR->SetBinError(i, error);
	MetBin=((TH1F*)inputFile->Get(signalantitag))->IntegralAndError(1,40,error);
	AnalysisMETBins_antitagSR->SetBinContent(i, MetBin);
	AnalysisMETBins_antitagSR->SetBinError(i, error);
	MetBin=((TH1F*)inputFile->Get(signal2Htag))->IntegralAndError(1,40,error);
	AnalysisMETBins_doubletagSB->SetBinContent(i, MetBin);
	AnalysisMETBins_doubletagSB->SetBinError(i, error);
	MetBin=((TH1F*)inputFile->Get(signal1Htag))->IntegralAndError(1,40,error);
	AnalysisMETBins_tagSB->SetBinContent(i, MetBin);
	AnalysisMETBins_tagSB->SetBinError(i, error);
	MetBin=((TH1F*)inputFile->Get(sidebandantitag))->IntegralAndError(1,40,error);
	AnalysisMETBins_antitagSB->SetBinContent(i, MetBin);
	AnalysisMETBins_antitagSB->SetBinError(i, error);
	}
	
	plots.push_back(AnalysisMETBins_tagSR);
	plots.push_back(AnalysisMETBins_antitagSR);
	plots.push_back(AnalysisMETBins_doubletagSR);
	plots.push_back(AnalysisMETBins_tagSB);
	plots.push_back(AnalysisMETBins_antitagSB);
	plots.push_back(AnalysisMETBins_doubletagSB);
}
  // background MC samples
  // Signal samples
  for( int iSample = 0 ; iSample < skims.signalNtuples.size() ; iSample++){
	TH1D*AnalysisMETT5HH_tagSR=new TH1D("AnalysisMETT5HH_tagSR_"+skims.signalSampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETT5HH_antitagSR=new TH1D("AnalysisMETT5HH_antitagSR_"+skims.signalSampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETT5HH_tagSB=new TH1D("AnalysisMETT5HH_tagSB_"+skims.signalSampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETT5HH_antitagSB=new TH1D("AnalysisMETT5HH_antitagSB_"+skims.signalSampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETT5HH_doubletagSB=new TH1D("AnalysisMETT5HH_doubletagSB_"+skims.signalSampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETT5HH_doubletagSR=new TH1D("AnalysisMETT5HH_doubletagSR_"+skims.signalSampleName[iSample],"MET",3,METBins) ;

	TH1D*AnalysisMETT5HZ_tagSR=new TH1D("AnalysisMETT5HZ_tagSR_"+skims.signalSampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETT5HZ_antitagSR=new TH1D("AnalysisMETT5HZ_antitagSR_"+skims.signalSampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETT5HZ_tagSB=new TH1D("AnalysisMETT5HZ_tagSB_"+skims.signalSampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETT5HZ_antitagSB=new TH1D("AnalysisMETT5HZ_antitagSB_"+skims.signalSampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETT5HZ_doubletagSB=new TH1D("AnalysisMETT5HZ_doubletagSB_"+skims.signalSampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETT5HZ_doubletagSR=new TH1D("AnalysisMETT5HZ_doubletagSR_"+skims.signalSampleName[iSample],"MET",3,METBins) ;

	TH1D*AnalysisMETT5ZZ_tagSR=new TH1D("AnalysisMETT5ZZ_tagSR_"+skims.signalSampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETT5ZZ_antitagSR=new TH1D("AnalysisMETT5ZZ_antitagSR_"+skims.signalSampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETT5ZZ_tagSB=new TH1D("AnalysisMETT5ZZ_tagSB_"+skims.signalSampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETT5ZZ_antitagSB=new TH1D("AnalysisMETT5ZZ_antitagSB_"+skims.signalSampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETT5ZZ_doubletagSB=new TH1D("AnalysisMETT5ZZ_doubletagSB_"+skims.signalSampleName[iSample],"MET",3,METBins) ;
	TH1D*AnalysisMETT5ZZ_doubletagSR=new TH1D("AnalysisMETT5ZZ_doubletagSR_"+skims.signalSampleName[iSample],"MET",3,METBins) ;
      RA2bTree* ntuple = skims.signalNtuples[iSample];
  //  heppySkimTree* ntuple = skims.signalNtuples[iSample];
	/*
    for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
      plots[iPlot].addSignalNtuple(ntuple,skims.signalSampleName[iSample]);
      plots[iPlot].setLineColor(ntuple,skims.lineColor[iSample]);
    }
	*/
    int numEvents = ntuple->fChain->GetEntries();
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 1000000 == 0 ) cout << skims.signalSampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      if(!baselineCut(ntuple) ) continue;
	//std::cout<<"Gen Higgs Content "<<getNumGenHiggses(ntuple)<<std::endl;
//      if(getNumGenHiggses(ntuple)!=2) continue;
      float MET=ntuple->MET;
      std::vector<double> EfficiencyCenterUpDown = Eff_MetMhtSextetReal_CenterUpDown(ntuple->HT, ntuple->MHT, ntuple->NJets);
      float trigWeight=EfficiencyCenterUpDown[0];
      float weight = customPUweights(ntuple)*trigWeight;	
      if( doubleTaggingLooseCut(ntuple) ){
                double jetMass1 = fillLeadingJetMass(ntuple);
                double jetMass2 = fillSubLeadingJetMass(ntuple);
                if( ( jetMass1 > 85 && jetMass1 < 135 ) /*&& ( jetMass2 > 85 && jetMass2 < 135 )*/ ){
		 if(getNumGenHiggses(ntuple)==2)AnalysisMETT5HH_doubletagSR->Fill(MET,weight);
		 if(getNumGenHiggses(ntuple)==1)AnalysisMETT5HZ_doubletagSR->Fill(MET,weight);  
		 if(getNumGenHiggses(ntuple)==0)AnalysisMETT5ZZ_doubletagSR->Fill(MET,weight); 
                   // plots[bin][4].fill(ntuple);
                }else /*if( ( ( jetMass1 > 50 && jetMass1 < 85 ) || ( jetMass1 > 135 && jetMass1 < 250 ) ) !=  ( ( jetMass2 > 50 && jetMass2 < 85 ) || ( jetMass2 > 135 && jetMass2 < 250 ) ) )*/{ 
                 //   plots[bin][5].fill(ntuple);
		 if(getNumGenHiggses(ntuple)==2)AnalysisMETT5HH_doubletagSB->Fill(MET,weight);
		 if(getNumGenHiggses(ntuple)==1)AnalysisMETT5HZ_doubletagSB->Fill(MET,weight);  
		 if(getNumGenHiggses(ntuple)==0)AnalysisMETT5ZZ_doubletagSB->Fill(MET,weight); 

                }
            }else{
                if( singleHiggsTagLooseCut(ntuple) ){
                    double jetMass1 = fillLeadingJetMass(ntuple);
                    double jetMass2 = fillSubLeadingJetMass(ntuple);
                    if( ( jetMass1 > 85 && jetMass1 < 135 ) /*&& ( jetMass2 > 85 && jetMass2 < 135 )*/ ){
		 		if(getNumGenHiggses(ntuple)==2)AnalysisMETT5HH_tagSR->Fill(MET,weight);
		 		if(getNumGenHiggses(ntuple)==1)AnalysisMETT5HZ_tagSR->Fill(MET,weight);  
		 		if(getNumGenHiggses(ntuple)==0)AnalysisMETT5ZZ_tagSR->Fill(MET,weight); 
                 //       plots[bin][0].fill(ntuple);
                    }else /*if( ( ( jetMass1 > 50 && jetMass1 < 85 ) || ( jetMass1 > 135 && jetMass1 < 250 ) ) !=  ( ( jetMass2 > 50 && jetMass2 < 85 ) || ( jetMass2 > 135 && jetMass2 < 250 ) ) )*/{ 
                   //     plots[bin][1].fill(ntuple);
		 		if(getNumGenHiggses(ntuple)==2)AnalysisMETT5HH_tagSB->Fill(MET,weight);
		 		if(getNumGenHiggses(ntuple)==1)AnalysisMETT5HZ_tagSB->Fill(MET,weight);  
		 		if(getNumGenHiggses(ntuple)==0)AnalysisMETT5ZZ_tagSB->Fill(MET,weight); 

                    }
                }
                if( antiTaggingLooseCut(ntuple) ){
                    double jetMass1 = fillLeadingJetMass(ntuple);
                    double jetMass2 = fillSubLeadingJetMass(ntuple);
                    if( ( jetMass1 > 85 && jetMass1 < 135 ) /*&& ( jetMass2 > 85 && jetMass2 < 135 )*/ ){
                                if(getNumGenHiggses(ntuple)==2)AnalysisMETT5HH_antitagSR->Fill(MET,weight);
                                if(getNumGenHiggses(ntuple)==1)AnalysisMETT5HZ_antitagSR->Fill(MET,weight);
                                if(getNumGenHiggses(ntuple)==0)AnalysisMETT5ZZ_antitagSR->Fill(MET,weight);	
                    }else /*if( ( ( jetMass1 > 50 && jetMass1 < 85 ) || ( jetMass1 > 135 && jetMass1 < 250 ) ) !=  ( ( jetMass2 > 50 && jetMass2 < 85 ) || ( jetMass2 > 135 && jetMass2 < 250 ) ) )*/{ 
                                if(getNumGenHiggses(ntuple)==2)AnalysisMETT5HH_antitagSB->Fill(MET,weight);
                                if(getNumGenHiggses(ntuple)==1)AnalysisMETT5HZ_antitagSB->Fill(MET,weight);
                                if(getNumGenHiggses(ntuple)==0)AnalysisMETT5ZZ_antitagSB->Fill(MET,weight);	

                    }
                }
	   }

    }
	plots.push_back(AnalysisMETT5HH_tagSR);
	plots.push_back(AnalysisMETT5HH_antitagSR);
	plots.push_back(AnalysisMETT5HH_tagSB);
	plots.push_back(AnalysisMETT5HH_antitagSB);
	plots.push_back(AnalysisMETT5HH_doubletagSB);
	plots.push_back(AnalysisMETT5HH_doubletagSR);

	plots.push_back(AnalysisMETT5HZ_tagSR);
	plots.push_back(AnalysisMETT5HZ_antitagSR);
	plots.push_back(AnalysisMETT5HZ_tagSB);
	plots.push_back(AnalysisMETT5HZ_antitagSB);
	plots.push_back(AnalysisMETT5HZ_doubletagSB);
	plots.push_back(AnalysisMETT5HZ_doubletagSR);

	plots.push_back(AnalysisMETT5ZZ_tagSR);
	plots.push_back(AnalysisMETT5ZZ_antitagSR);
	plots.push_back(AnalysisMETT5ZZ_tagSB);
	plots.push_back(AnalysisMETT5ZZ_antitagSB);
	plots.push_back(AnalysisMETT5ZZ_doubletagSB);
	plots.push_back(AnalysisMETT5ZZ_doubletagSR);

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
  TFile* outputFile = new TFile("datacardInputs.root","RECREATE");
  for( int iPlot = 0 ; iPlot < plots.size() ; iPlot++){
    //plots[iPlot].Draw(can,skims.ntuples,skims.signalNtuples);
    outputFile->cd();
    plots[iPlot]->Write();
  }
  outputFile->Close();

}
