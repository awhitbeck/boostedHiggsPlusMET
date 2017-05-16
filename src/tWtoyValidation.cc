#include "RooWorkspace.h"
#include "RooRealVar.h"
#include "RooSimultaneous.h"
#include "RooDataSet.h"
#include "RooPoisson.h"
#include "RooGaussian.h"
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

  gROOT->ProcessLine(".L tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");

  //////////////////////////////////////////////////////////////////////////////
  // - - - - - - - - - - SET UP LIKELIHOO PARAMETERIZATION - - - - - - - - -  //
  //////////////////////////////////////////////////////////////////////////////
  RooWorkspace* wspace = new RooWorkspace("wspace");
  wspace->factory("Gaussian::RpassFailPrior(RpassFailNuis[1.,0.00001,4.],RpassFailUncMean[1.,0.00001,10.],RpassFailUncSigma[0.2,0.00001,10.])");
  wspace->var("RpassFailUncMean")->setConstant(true);
  wspace->var("RpassFailUncSigma")->setConstant(true);
  TString modelPdfs="";
  TString modelObs="";
  int nBins = 5;
  for( int i = 0 ; i < nBins ; i++ ){
    
    TString index="";
    index+=i;


    wspace->factory("Poisson::SB_"+index+"(obsSB_"+index+"[0,10000],expSB_"+index+"[200.,0.00001,10000])");
    wspace->factory("Poisson::muSB_"+index+"(obsMuSB_"+index+"[0,10000],expMuSB_"+index+"[200.,0.00001,10000])");
    if( i == 0 ){
      wspace->factory("prod::expBkgSR_"+index+"(expSB_"+index+",RpassFail[0.5,0.00001,2.])");
      wspace->factory("prod::scaledSig_"+index+"(expSig_"+index+"[0,10000],mu[1.,0.00001,10])");
      wspace->factory("Poisson::muSR_"+index+"(obsMuSR_"+index+"[0,10000],prod::expMuSR_"+index+"(expMuSB_"+index+",RpassFail))");
    }else{
      wspace->factory("prod::expBkgSR_"+index+"(expSB_"+index+",RpassFail)");
      wspace->factory("prod::scaledSig_"+index+"(expSig_"+index+"[0,10000],mu)");
      wspace->factory("Poisson::muSR_"+index+"(obsMuSR_"+index+"[0,10000],prod::expMuSR_"+index+"(expMuSB_"+index+",RpassFail))");
    }
    wspace->var("expSig_"+index)->setConstant(true);
    wspace->factory("Poisson::SR_"+index+"(obsSR_"+index+"[0,10000],sum::expSR_"+index+"(scaledSig_"+index+",expBkgSR_"+index+"))");

    if( modelPdfs == "" )
      modelPdfs+="SB_"+index+",SR_"+index+",muSB_"+index+",muSR_"+index;
    else
      modelPdfs+=",SB_"+index+",SR_"+index+",muSB_"+index+",muSR_"+index;

    if( modelObs == "" )
      modelObs+="obsSB_"+index+",obsSR_"+index+",obsMuSB_"+index+",obsMuSR_"+index;
    else
      modelObs+=",obsSB_"+index+",obsSR_"+index+",obsMuSB_"+index+",obsMuSR_"+index;
  }

  wspace->factory("PROD::model("+modelPdfs+")");
  wspace->defineSet("obs",modelObs);
    
  ////////////////////////////////////////////////////////////////////////
  // - - - - - - - - - TEST WITH EXPECTED RATES FROM MC  - - - - - - -  //
  ////////////////////////////////////////////////////////////////////////

  skimSamples skims;
  skimSamples skimsMu("singleMuCR");

  for( int i = 0 ; i < skims.sampleName.size() ; i++ ){
    if( skims.sampleName[i] == "QCD" || skims.sampleName[i] == "ZJets" ){
      skims.ntuples.erase(skims.ntuples.begin()+i);
      skims.sampleName.erase(skims.sampleName.begin()+i);
      skims.fillColor.erase(skims.fillColor.begin()+i);
    }
  }

  for( int i = 0 ; i < skimsMu.sampleName.size() ; i++ ){
    if( skimsMu.sampleName[i] == "QCD" || skimsMu.sampleName[i] == "ZJets" ){
      skimsMu.ntuples.erase(skimsMu.ntuples.begin()+i);
      skimsMu.sampleName.erase(skimsMu.sampleName.begin()+i);
      skimsMu.fillColor.erase(skimsMu.fillColor.begin()+i);
    }
  }


  double (*arbitrationFunc)(heppySkimTree*) = *fillLeadingJetMass<heppySkimTree>;
  typedef plot<heppySkimTree> plot;

  plot tagSR_versusMET(*fillMET<heppySkimTree>,"tagSR_versusMET","E_{T}^{miss} [GeV]",4,300.,1200.);
  plot tagSB_versusMET(*fillMET<heppySkimTree>,"tagSB_versusMET","E_{T}^{miss} [GeV]",4,300.,1200.);
  plot mutagSR_versusMET(*fillMET<heppySkimTree>,"mutagSR_versusMET","E_{T}^{miss} [GeV]",4,300.,1200.);
  plot mutagSB_versusMET(*fillMET<heppySkimTree>,"mutagSB_versusMET","E_{T}^{miss} [GeV]",4,300.,1200.);

  // MC backgrounds - 0 lepton regions
  for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){
    
    heppySkimTree* ntuple = skims.ntuples[iSample];
    tagSR_versusMET.addNtuple(ntuple,skims.sampleName[iSample]);
    tagSB_versusMET.addNtuple(ntuple,skims.sampleName[iSample]);

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
    }
  }

  // MC backgrounds - 1 muon regions
  for( int iSample = 0 ; iSample < skimsMu.ntuples.size() ; iSample++){
    
    heppySkimTree* ntuple = skimsMu.ntuples[iSample];
    mutagSR_versusMET.addNtuple(ntuple,skimsMu.sampleName[iSample]);
    mutagSB_versusMET.addNtuple(ntuple,skimsMu.sampleName[iSample]);

    int numEvents = ntuple->fChain->GetEntries();
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 1000000 == 0 ) cout << skimsMu.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
      if(!baselineCut(ntuple)) continue; 
      if( taggingCut(ntuple) ){
	double testMass = arbitrationFunc(ntuple);
	if( testMass > 85. && testMass < 135. ){ 
	  mutagSR_versusMET.fill(ntuple);
	}else if( testMass > 50. && testMass < 200. ){
	  mutagSB_versusMET.fill(ntuple);
	}
      }
    }
  }

  // Signal samples
  heppySkimTree* ntuple = skims.signalNtuples[0];
  tagSR_versusMET.addSignalNtuple(ntuple,skims.signalSampleName[0]);
  tagSB_versusMET.addSignalNtuple(ntuple,skims.signalSampleName[0]);
  mutagSR_versusMET.addSignalNtuple(ntuple,skimsMu.signalSampleName[0]);
  mutagSB_versusMET.addSignalNtuple(ntuple,skimsMu.signalSampleName[0]);
  
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
	mutagSR_versusMET.fillSignal(ntuple);
      }else if( testMass > 50. && testMass < 200. ){
	mutagSB_versusMET.fillSignal(ntuple);
      }
    }
  }

  tagSR_versusMET.buildSum();
  tagSB_versusMET.buildSum();
  mutagSR_versusMET.buildSum();
  mutagSB_versusMET.buildSum();

  TH1F NsigMeasured("NsigMeasured","NsigMeasured",30,0,3);
  TH1F NtWSRMeasured("NtwSRMeasured","NtwSRMeasured",1000,0,1000);
  TH1F NtWMuSRMeasured("NtwMuSRMeasured","NtwMuSRMeasured",1000,0,1000);
  TH1F NtWSBMeasured("NtwSBMeasured","NtwSBMeasured",1000,0,1000);
  TH1F NtWMuSBMeasured("NtwMuSBMeasured","NtwMuSBMeasured",1000,0,1000);
  TH1F RpassFailMeasured("RpassFailMeasured","RpassFailMeasured",100,0.,2.);

  TRandom r;

  int Ntoys = 1000;
  for( int iToy = 0 ; iToy < Ntoys ; iToy++ ){

    cout << "generate toy data" << endl;
    RooDataSet data("data","",*wspace->set("obs"));

    for( int i = 0 ; i < nBins ; i++ ){ 
      TString index="_";
      index+=i;

      cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
      cout << "tagSB("<<i+1<<"): " << tagSB_versusMET.sum->GetBinContent(i+1) << "+/-" << tagSB_versusMET.sum->GetBinError(i+1) << endl;
      cout << "MuTagSB("<<i+1<<"): " << mutagSB_versusMET.sum->GetBinContent(i+1) << "+/-" << mutagSB_versusMET.sum->GetBinError(i+1) << endl;
      cout << "tagSR("<<i+1<<"): " << tagSR_versusMET.sum->GetBinContent(i+1) << "+/-" << tagSR_versusMET.sum->GetBinError(i+1) << endl;
      cout << "MuTagSR("<<i+1<<"): " << mutagSR_versusMET.sum->GetBinContent(i+1) << "+/-" << mutagSR_versusMET.sum->GetBinError(i+1) << endl;
      cout << "tag ratio: " << tagSR_versusMET.sum->GetBinContent(i+1) / tagSB_versusMET.sum->GetBinContent(i+1) << endl;
      cout << "Mu tag ratio: " << mutagSR_versusMET.sum->GetBinContent(i+1) / mutagSB_versusMET.sum->GetBinContent(i+1) << endl;
      cout << "signal: " << tagSR_versusMET.signalHistoMap[skims.signalNtuples[0]]->GetBinContent(i+1) << endl;

      wspace->var("RpassFail")->setVal(tagSR_versusMET.sum->GetBinContent(0+1)/tagSB_versusMET.sum->GetBinContent(0+1));
      wspace->var("expMuSB"+index)->setVal(mutagSB_versusMET.sum->GetBinContent(i+1));
      wspace->var("expSB"+index)->setVal(tagSB_versusMET.sum->GetBinContent(i+1));
      wspace->var("mu")->setVal(1.);

      wspace->var("expSig"+index)->setVal(tagSR_versusMET.signalHistoMap[skims.signalNtuples[0]]->GetBinContent(i+1));
      wspace->var("obsSR"+index)->setVal(r.Poisson(tagSR_versusMET.sum->GetBinContent(i+1)+tagSR_versusMET.signalHistoMap[skims.signalNtuples[0]]->GetBinContent(i+1)));
      wspace->var("obsSB"+index)->setVal(r.Poisson(tagSB_versusMET.sum->GetBinContent(i+1)));
      wspace->var("obsMuSB"+index)->setVal(r.Poisson(mutagSB_versusMET.sum->GetBinContent(i+1)));
      wspace->var("obsMuSR"+index)->setVal(r.Poisson(mutagSR_versusMET.sum->GetBinContent(i+1)));
      
    }

    data.add(*wspace->set("obs"));
    data.Print("v");

    cout << "fit toy data" << endl;
    wspace->pdf("model")->fitTo(data);

    cout << "mu: " << wspace->var("mu")->getVal() << endl;
    //cout << "NtwSR[0]: " << NtwSR[0]->getVal() << " tagSR_versusMET: " << tagSR_versusMET.sum->GetBinContent(0+1) << endl;
    //cout << "NtwSB[0]: " << NtwSB[0]->getVal() << " tagSB_versusMET: " << tagSB_versusMET.sum->GetBinContent(0+1) << endl;
    //cout << "NtwMuSB[0]: " << NtwMuSB[0]->getVal() << " mutagSB_versusMET: " << mutagSB_versusMET.sum->GetBinContent(0+1) << endl;
    //cout << "RpassFail[0]: " << RpassFail[0]->getVal() << " tagSR_versusMET.sum->GetBinContent(0+1) / tagSB_versusMET.sum->GetBinContent(0+1): " << tagSR_versusMET.sum->GetBinContent(0+1) / tagSB_versusMET.sum->GetBinContent(0+1) << endl;

    NsigMeasured.Fill(wspace->var("mu")->getVal());
    //NtWSRMeasured.Fill((NtwSR[0]->getVal()-tagSR_versusMET.sum->GetBinContent(0+1))); // / NtwSR[0]->getError());
    //NtWMuSRMeasured.Fill((NtwMuSR[0]->getVal()-mutagSR_versusMET.sum->GetBinContent(0+1))); // / NtwMuSR[0]->getError());
    //NtWSBMeasured.Fill((NtwSB[0]->getVal()-tagSB_versusMET.sum->GetBinContent(0+1)));// / NtwSB[0]->getError());
    //NtWMuSBMeasured.Fill((NtwMuSB[0]->getVal()-mutagSB_versusMET.sum->GetBinContent(0+1)));// / NtwMuSB[0]->getError());
    //RpassFailMeasured.Fill((RpassFail[0]->getVal()-tagSR_versusMET.sum->GetBinContent(0+1) / tagSB_versusMET.sum->GetBinContent(0+1)));// / RpassFail[0]->getError());
  }
  
  TCanvas* can = new TCanvas("can","can",500,500);
  NsigMeasured.Draw();
  gStyle->SetOptStat(111);
  can->SaveAs("toyTest.png");

  cout << "Measured Signal: " << NsigMeasured.GetMean() << " +/- " << NsigMeasured.GetRMS()/sqrt(Ntoys) << endl; 
  cout << "RMS Measured Signal: " << NsigMeasured.GetRMS() << endl;
  cout << "Measured tagged SR pull: " << NtWSRMeasured.GetMean() << " +/- " << NtWSRMeasured.GetRMS() << endl;
  cout << "Measured tagged SB pull: " << NtWSBMeasured.GetMean() << " +/- " << NtWSBMeasured.GetRMS() << endl;
  cout << "Measured muon SR pull: " << NtWMuSRMeasured.GetMean() << " +/- " << NtWMuSRMeasured.GetRMS() << endl;
  cout << "Measured muon SB pull: " << NtWMuSBMeasured.GetMean() << " +/- " << NtWMuSBMeasured.GetRMS() << endl;
  cout << "Measured RpassFail pull: " << RpassFailMeasured.GetMean() << " +/- " << RpassFailMeasured.GetRMS() << endl;
  return 1;
}
  
