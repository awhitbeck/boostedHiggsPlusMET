#include "RooRealVar.h"
#include "RooSimultaneous.h"
#include "RooDataSet.h"
#include "RooPoisson.h"
#include "RooGaussian.h"
#include "RooLognormal.h"
#include "RooProdPdf.h"
#include "RooArgList.h"
#include "RooFormulaVar.h"
#include "TH1F.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TRandom.h"

#include <vector>
#include <map>
#include <iostream>
#include <cstdio>

#include "plotterUtils.cc"
#include "skimSamples.cc"
#include "definitions.cc"

int main(int argc, char** argv){

  gROOT->ProcessLine(".L ~/tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");

  //RooMsgService::instance().setSilentMode(true); 

  //////////////////////////////////////////////////////////////////////////////
  // - - - - - - - - - - SET UP LIKELIHOO PARAMETERIZATION - - - - - - - - -  //
  //////////////////////////////////////////////////////////////////////////////
  // observables
  RooRealVar mu("mu","mu",1.,0.,1000.);
  RooRealVar RpassFailNuis("RpassFailNuis","RpassFailNuis",1.,0.,5.);
  RooRealVar RpassFailMean("RpassFailMean","RpassFailMean",1.,0.,2.);
  RooRealVar RpassFailUnc("RpassFailUnc","RpassFailUnc",.4,0.,2.);
  RpassFailUnc.setConstant(true);
  RpassFailMean.setConstant(true);
  //RpassFail prior
  RooGaussian RpassFailPrior("RpassFailPrior","RpassFailPrior",RpassFailNuis,RpassFailMean,RpassFailUnc);
  
  vector<RooRealVar*> NobsSR;
  vector<RooRealVar*> NobsSB;
  vector<RooRealVar*> NobsASR;
  vector<RooRealVar*> NobsASB;
  
  // parameters
  vector<RooRealVar*> RpassFail;
  vector<RooRealVar*> NqcdSB;
  vector<RooRealVar*> NqcdASB;
  vector<RooRealVar*> NqcdSR;
  vector<RooRealVar*> NqcdASR;
  vector<RooRealVar*> NsigSR;
  // distributions
  // with constraints
  vector<RooFormulaVar*> NexpSRConst;
  vector<RooPoisson*> PoissSR;
  // with constraints
  vector<RooFormulaVar*> NqcdASRConst;
  vector<RooPoisson*> PoissASR;

  vector<RooFormulaVar*> NexpSR;
  vector<RooPoisson*> PoissSRTrue;
  vector<RooPoisson*> PoissASRTrue;

  vector<RooPoisson*> PoissSB;
  vector<RooPoisson*> PoissASB;

  RooArgList modelPdfs,trueModelPdfs;
  modelPdfs.add(RpassFailPrior);
  RooArgSet modelParams;

  int nBins = 6;
  for( int i = 0 ; i < nBins ; i++ ){
    TString index="_";
    index+=i;
    NobsSR.push_back(new RooRealVar("NobsSR"+index,"NobsSR"+index,1.,0.,99999999.));
    NobsSB.push_back(new RooRealVar("NobsSB"+index,"NobsSB"+index,1.,0.,99999999.));
    NobsASR.push_back(new RooRealVar("NobsASR"+index,"NobsASR"+index,1.,0.,99999999.));
    NobsASB.push_back(new RooRealVar("NobsASB"+index,"NobsASB"+index,1.,0.,99999999.));
    
    RpassFail.push_back(new RooRealVar("RpassFail"+index,"RpassFail"+index,.5,0.,5.));
    //RpassFail[i]->setConstant(true);
    NqcdSB.push_back(new RooRealVar("NqcdSB"+index,"NqcdSB"+index,5.,0.,99999999.));
    NqcdASB.push_back(new RooRealVar("NqcdASB"+index,"NqcdASB"+index,1.,0.,99999999.));
    NqcdSR.push_back(new RooRealVar("NqcdSR"+index,"NqcdSR"+index,5.,0.,99999999.));
    NqcdASR.push_back(new RooRealVar("NqcdASR"+index,"NqcdASR"+index,1.,0.,99999999.));
    NsigSR.push_back(new RooRealVar("NsigSR"+index,"NsigSR"+index,1.,0.,99999999.));
    NsigSR[i]->setConstant(true);

    //signal region PDF
    //if( i >= 7) 
    //  NexpSRConst.push_back(new RooFormulaVar("NexpSRConst"+index,"@0*@1*@4+@2*@3",RooArgList(*NqcdSB[i],*RpassFail[3],*NsigSR[i],mu,RpassFailNuis)));
    //else
    NexpSRConst.push_back(new RooFormulaVar("NexpSRConst"+index,"@0*@1*@4+@2*@3",RooArgList(*NqcdSB[i],*RpassFail[i],*NsigSR[i],mu,RpassFailNuis)));
    PoissSR.push_back(new RooPoisson("PoissSR"+index,"PoissSR"+index,*NobsSR[i],*NexpSRConst[i]));

    //if( i >= 7)
    //  NqcdASRConst.push_back(new RooFormulaVar("NqcdASRConst"+index,"@0*@1",RooArgList(*NqcdASB[i],*RpassFail[3])));
    //else
    NqcdASRConst.push_back(new RooFormulaVar("NqcdASRConst"+index,"@0*@1",RooArgList(*NqcdASB[i],*RpassFail[i])));
    PoissASR.push_back(new RooPoisson("PoissASR"+index,"PoissASR"+index,*NobsASR[i],*NqcdASRConst[i]));
    
    NexpSR.push_back(new RooFormulaVar("NexpSR"+index,"@0+@1",RooArgList(*NqcdSR[i],*NsigSR[i])));
    PoissSRTrue.push_back(new RooPoisson("PoissSRTrue"+index,"PoissSRTrue"+index,*NobsSR[i],*NexpSR[i]));
    PoissASRTrue.push_back(new RooPoisson("PoissASRTrue"+index,"PoissASRTrue"+index,*NobsASR[i],*NqcdASR[i]));
    
    PoissSB.push_back(new RooPoisson("PoissSB"+index,"PoissSB"+index,*NobsSB[i],*NqcdSB[i]));
    PoissASB.push_back(new RooPoisson("PoissASB"+index,"PoissASB"+index,*NobsASB[i],*NqcdASB[i]));
    
    modelPdfs.add(*PoissSR[i]);
    modelPdfs.add(*PoissSB[i]);
    modelPdfs.add(*PoissASR[i]);
    modelPdfs.add(*PoissASB[i]);
    
    trueModelPdfs.add(*PoissSRTrue[i]);
    trueModelPdfs.add(*PoissSB[i]);
    trueModelPdfs.add(*PoissASRTrue[i]);
    trueModelPdfs.add(*PoissASB[i]);

    modelParams.add(*NobsSB[i]);
    modelParams.add(*NobsASB[i]);
    modelParams.add(*NobsSR[i]);
    modelParams.add(*NobsASR[i]);

  }

  RooProdPdf likelihood("likelihood","likelihood",modelPdfs); // RooArgList(*PoissSR[i],*PoissSB[i],*PoissASR[i],*PoissASB[i]));
  RooProdPdf likelihoodTrue("likelihoodTrue","likelihoodTrue",trueModelPdfs); // RooArgList(*PoissSRTrue[i],*PoissSB[i],*PoissASRTrue[i],*PoissASB[i]));
  
  ////////////////////////////////////////////////////////////////////////
  // - - - - - - - - - TEST WITH EXPECTED RATES FROM MC  - - - - - - -  //
  ////////////////////////////////////////////////////////////////////////

  skimSamples skims;
  for( int i = 0 ; i < skims.sampleName.size() ; i++ ){
    if( skims.sampleName[i] == "TT" || skims.sampleName[i] == "WJets" ){
      skims.ntuples.erase(skims.ntuples.begin()+i);
      skims.sampleName.erase(skims.sampleName.begin()+i);
      skims.fillColor.erase(skims.fillColor.begin()+i);
    }
  }

  double (*arbitrationFunc)(heppySkimTree*) = *fillLeadingBBtagJetMass<heppySkimTree>;
  typedef plot<heppySkimTree> plot;

  plot tagSR_versusMET(*fillMET<heppySkimTree>,"tagSR_versusMET","E_{T}^{miss} [GeV]",5,300.,800.);
  plot tagSB_versusMET(*fillMET<heppySkimTree>,"tagSB_versusMET","E_{T}^{miss} [GeV]",5,300.,800.);
  plot antitagSR_versusMET(*fillMET<heppySkimTree>,"antitagSR_versusMET","E_{T}^{miss} [GeV]",5,300.,800.);
  plot antitagSB_versusMET(*fillMET<heppySkimTree>,"antitagSB_versusMET","E_{T}^{miss} [GeV]",5,300.,800.);

  // MC backgrounds
  for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){
    
    heppySkimTree* ntuple = skims.ntuples[iSample];
    tagSR_versusMET.addNtuple(ntuple,skims.sampleName[iSample]);
    tagSB_versusMET.addNtuple(ntuple,skims.sampleName[iSample]);
    antitagSR_versusMET.addNtuple(ntuple,skims.sampleName[iSample]);
    antitagSB_versusMET.addNtuple(ntuple,skims.sampleName[iSample]);

    int numEvents = ntuple->fChain->GetEntries();
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 1000000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      if(!baselineCut(ntuple)) continue; 
      if( taggingCut(ntuple) ){
	double testMass = arbitrationFunc(ntuple);
	if( testMass > 85. && testMass < 135. ){ 
	  tagSR_versusMET.fill(ntuple);
	}else if( testMass > 50. && testMass < 200. ){
	  tagSB_versusMET.fill(ntuple);
	}
      }
      if( antiTaggingCut(ntuple) ){
	double testMass = arbitrationFunc(ntuple);
	if( testMass > 85. && testMass < 135. ){ 
	  antitagSR_versusMET.fill(ntuple);
	}else if( testMass > 50. && testMass < 200. ){
	  antitagSB_versusMET.fill(ntuple);
	}
      }
    }
  }

  // Signal samples
  heppySkimTree* ntuple = skims.signalNtuples[0];
  tagSR_versusMET.addSignalNtuple(ntuple,skims.signalSampleName[0]);
  tagSB_versusMET.addSignalNtuple(ntuple,skims.signalSampleName[0]);
  antitagSR_versusMET.addSignalNtuple(ntuple,skims.signalSampleName[0]);
  antitagSB_versusMET.addSignalNtuple(ntuple,skims.signalSampleName[0]);
  
  int numEvents = ntuple->fChain->GetEntries();
  for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
    ntuple->GetEntry(iEvt);
    if( iEvt % 1000000 == 0 ) cout << skims.signalSampleName[0] << ": " << iEvt << "/" << numEvents << endl;
    if(! baselineCut(ntuple) ) continue;
    if(ntuple->nGenHiggsBoson!=2) continue;
    if( taggingCut(ntuple) ){
      double testMass = arbitrationFunc(ntuple);
      if( testMass > 85. && testMass < 135. ){ 
	tagSR_versusMET.fillSignal(ntuple);
      }else if( testMass > 50. && testMass < 200. ){
	tagSB_versusMET.fillSignal(ntuple);
      }
    }
    if( antiTaggingCut(ntuple) ){
      double testMass = arbitrationFunc(ntuple);
      if( testMass > 85. && testMass < 135. ){ 
	antitagSR_versusMET.fillSignal(ntuple);
      }else if( testMass > 50. && testMass < 200. ){
	antitagSB_versusMET.fillSignal(ntuple);
      }
    }
  }

  tagSR_versusMET.buildSum();
  tagSB_versusMET.buildSum();
  antitagSR_versusMET.buildSum();
  antitagSB_versusMET.buildSum();

  TH1F NsigMeasured("NsigMeasured","NsigMeasured",30,0,3);
  int Ntoys = 1000;
  for( int iToy = 0 ; iToy < Ntoys ; iToy++ ){
    cout << "set values " << endl;
    for( int i = 0 ; i < nBins ; i++ ){ 
      cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
      cout << "tagSB("<<i+1<<"): " << tagSB_versusMET.sum->GetBinContent(i+1) << "+/-" << tagSB_versusMET.sum->GetBinError(i+1) << endl;
      cout << "antitagSB("<<i+1<<"): " << antitagSB_versusMET.sum->GetBinContent(i+1) << "+/-" << antitagSB_versusMET.sum->GetBinError(i+1) << endl;
      cout << "tagSR("<<i+1<<"): " << tagSR_versusMET.sum->GetBinContent(i+1) << "+/-" << tagSR_versusMET.sum->GetBinError(i+1) << endl;
      cout << "antitagSR("<<i+1<<"): " << antitagSR_versusMET.sum->GetBinContent(i+1) << "+/-" << antitagSR_versusMET.sum->GetBinError(i+1) << endl;
      cout << "tag ratio: " << tagSR_versusMET.sum->GetBinContent(i+1) / tagSB_versusMET.sum->GetBinContent(i+1) << endl;
      cout << "antitag ratio: " << antitagSR_versusMET.sum->GetBinContent(i+1) / antitagSB_versusMET.sum->GetBinContent(i+1) << endl;
      cout << "signal: " << tagSR_versusMET.signalHistoMap[skims.signalNtuples[0]]->GetBinContent(i+1) << endl;

      NqcdSB[i]->setVal(tagSB_versusMET.sum->GetBinContent(i+1));
      //if( NqcdSB[i]->getVal() == 0 )  NqcdSB[i]->setVal(0.0001);
      NqcdASB[i]->setVal(antitagSB_versusMET.sum->GetBinContent(i+1));
      //if( NqcdASB[i]->getVal() == 0 )  NqcdASB[i]->setVal(0.0001);
      NqcdSR[i]->setVal(tagSR_versusMET.sum->GetBinContent(i+1));
      //if( NqcdSR[i]->getVal() == 0 )  NqcdSR[i]->setVal(0.0001);
      NqcdASR[i]->setVal(antitagSR_versusMET.sum->GetBinContent(i+1));
      //if( NqcdASR[i]->getVal() == 0 )  NqcdASR[i]->setVal(0.0001);
      NsigSR[i]->setVal(tagSR_versusMET.signalHistoMap[skims.signalNtuples[0]]->GetBinContent(i+1));
      
    }

    cout << "generate toy data" << endl;
    RooDataSet* testData = (RooDataSet*) likelihoodTrue.generate(modelParams,1);
    for( int i = 0 ; i < nBins ; i++){
      TString temp = "";
      temp+=i;
      cout << "NobsSB("<<i << "): " << testData->get(0)->getRealValue("NobsSB_"+temp) << endl;
      cout << "NobsSR("<<i<<"): " << testData->get(0)->getRealValue("NobsSR_"+temp) << endl;
      cout << "NobsASB("<<i<<"): " << testData->get(0)->getRealValue("NobsASB_"+temp) << endl;
      cout << "NobsASR("<<i<<"): " << testData->get(0)->getRealValue("NobsASR_"+temp) << endl;
    }
    cout << "fit toy data" << endl;
    likelihood.fitTo(*testData);//,RooFit::PrintEvalErrors(-1));
    cout << "mu: " << mu.getVal() << "+/-" << mu.getError() << endl;
    NsigMeasured.Fill(mu.getVal());
  }
  
  TCanvas* can = new TCanvas("can","can",500,500);
  NsigMeasured.Draw();
  gStyle->SetOptStat(111);
  can->SaveAs("toyTest.png");

  cout << "Measured Signal: " << NsigMeasured.GetMean() << " +/- " << NsigMeasured.GetRMS()/sqrt(Ntoys) << endl; 
  cout << "RMS Measured Signal: " << NsigMeasured.GetRMS() << endl;
  return 1;
}
  
