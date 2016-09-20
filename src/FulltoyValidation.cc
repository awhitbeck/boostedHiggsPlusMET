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

  if( argc != 2 ) return 1;

  gROOT->ProcessLine(".L ~/tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");

  RooMsgService::instance().setSilentMode(true); 

  //////////////////////////////////////////////////////////////////////////////
  // - - - - - - - - - - SET UP LIKELIHOO PARAMETERIZATION - - - - - - - - -  //
  //////////////////////////////////////////////////////////////////////////////
  RooWorkspace* wspace = new RooWorkspace("wspace");
  wspace->factory("Gaussian::RpassFailPrior(RpassFailNuis[1.,0.00001,4.],RpassFailUncMean[1.,0.00001,10.],RpassFailUncSigma[0.2,0.00001,10.])");
  wspace->var("RpassFailUncMean")->setConstant(true);
  wspace->var("RpassFailUncSigma")->setConstant(true);
  TString modelPdfs="";
  TString modelObs="";
  int nBins = 7;
  for( int i = 0 ; i < nBins ; i++ ){
    
    TString index="";
    index+=i;
    wspace->factory("Poisson::SB_"+index+"(obsSB_"+index+"[0,10000],sum::expSB_"+index+"(QCDexpSB_"+index+"[200.,0.00001,10000],prod::tWexpSB_"+index+"(tWexpMuSB_"+index+"[200.,0.00001,10000],Rlost[1.,0.00001,10.])))");

    wspace->factory("prod::tWexpSR_"+index+"(tWexpSB_"+index+",RpassFailTW_"+index+"[0.5,0.00001,2.])");
    wspace->factory("prod::QCDexpSR_"+index+"(QCDexpSB_"+index+",RpassFailQCD_"+index+"[0.5,0.00001,2.])");
    wspace->factory("prod::scaledSig_"+index+"(expSig_"+index+"[20.,0,10000],mu[1.,0.00001,10])");
    wspace->var("expSig_"+index)->setConstant(true);
    wspace->factory("Poisson::SR_"+index+"(obsSR_"+index+"[0,10000],sum::expSR_"+index+"(scaledSig_"+index+",QCDexpSR_"+index+",tWexpSR_"+index+"))");

    wspace->factory("Poisson::muSB_"+index+"(obsMuSB_"+index+"[0,10000],tWexpMuSB_"+index+")");
    wspace->factory("Poisson::muSR_"+index+"(obsMuSR_"+index+"[0,10000],prod::expMuSR_"+index+"(tWexpMuSB_"+index+",RpassFailTW_"+index+"))");

    wspace->factory("Poisson::ASB_"+index+"(obsASB_"+index+"[0,10000],sum::expASB_"+index+"(QCDexpASB_"+index+"[200.,0.00001,10000],prod::tWexpASB_"+index+"(tWexpMuASB_"+index+"[200.,0.00001,10000],Rlost)))");
    
    wspace->factory("Poisson::ASR_"+index+"(obsASR_"+index+"[0,10000],sum::expASR_"+index+"(prod::QCDexpASR_"+index+"(QCDexpASB_"+index+",RpassFailQCD_"+index+"),prod::tWexpASR_"+index+"(tWexpMuASB_"+index+",Rlost,RantiPassFailTW_"+index+"[0.5,0.00001,2.])))");

    wspace->factory("Poisson::muASB_"+index+"(obsMuASB_"+index+"[0,10000],tWexpMuASB_"+index+")");

    wspace->factory("Poisson::muASR_"+index+"(obsMuASR_"+index+"[0,10000],prod::expMuASR_"+index+"(tWexpMuASB_"+index+",RantiPassFailTW_"+index+"))");
    
    if( modelPdfs == "" )
      modelPdfs+="SB_"+index+",SR_"+index+",muSB_"+index+",muSR_"+index+",ASB_"+index+",ASR_"+index+",muASB_"+index+",muASR_"+index;
    else
      modelPdfs+=",SB_"+index+",SR_"+index+",muSB_"+index+",muSR_"+index+",ASB_"+index+",ASR_"+index+",muASB_"+index+",muASR_"+index;

    if( modelObs == "" )
      modelObs+="obsSB_"+index+",obsSR_"+index+",obsMuSB_"+index+",obsMuSR_"+index+",obsASB_"+index+",obsASR_"+index+",obsMuASB_"+index+",obsMuASR_"+index;
    else
      modelObs+=",obsSB_"+index+",obsSR_"+index+",obsMuSB_"+index+",obsMuSR_"+index+",obsASB_"+index+",obsASR_"+index+",obsMuASB_"+index+",obsMuASR_"+index;
  }

  wspace->factory("PROD::model("+modelPdfs+")");
  wspace->defineSet("obs",modelObs);

  wspace->Print();

  ////////////////////////////////////////////////////////////////////////
  // - - - - - - - - - TEST WITH EXPECTED RATES FROM MC  - - - - - - -  //
  ////////////////////////////////////////////////////////////////////////

  skimSamples skims;
  skimSamples skimsMu("singleMuCR");

  for( int i = 0 ; i < skimsMu.sampleName.size() ; i++ ){
    if( skimsMu.sampleName[i] == "QCD" || skimsMu.sampleName[i] == "ZJets" ){
      skimsMu.ntuples.erase(skimsMu.ntuples.begin()+i);
      skimsMu.sampleName.erase(skimsMu.sampleName.begin()+i);
      skimsMu.fillColor.erase(skimsMu.fillColor.begin()+i);
    }
  }


  double (*arbitrationFunc)(heppySkimTree*) = *fillLeadingJetMass<heppySkimTree>;
  typedef plot<heppySkimTree> plot;

  plot tagSR_versusMET(*fillMET<heppySkimTree>,"tagSR_versusMET","E_{T}^{miss} [GeV]",6,300.,1200.);
  plot tagSB_versusMET(*fillMET<heppySkimTree>,"tagSB_versusMET","E_{T}^{miss} [GeV]",6,300.,1200.);
  plot mutagSR_versusMET(*fillMET<heppySkimTree>,"mutagSR_versusMET","E_{T}^{miss} [GeV]",6,300.,1200.);
  plot mutagSB_versusMET(*fillMET<heppySkimTree>,"mutagSB_versusMET","E_{T}^{miss} [GeV]",6,300.,1200.);

  plot antitagSR_versusMET(*fillMET<heppySkimTree>,"antitagSR_versusMET","E_{T}^{miss} [GeV]",6,300.,1200.);
  plot antitagSB_versusMET(*fillMET<heppySkimTree>,"antitagSB_versusMET","E_{T}^{miss} [GeV]",6,300.,1200.);
  plot muantitagSR_versusMET(*fillMET<heppySkimTree>,"muantitagSR_versusMET","E_{T}^{miss} [GeV]",6,300.,1200.);
  plot muantitagSB_versusMET(*fillMET<heppySkimTree>,"muantitagSB_versusMET","E_{T}^{miss} [GeV]",6,300.,1200.);

  // MC backgrounds - 0 lepton regions
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

  // MC backgrounds - 1 muon regions
  for( int iSample = 0 ; iSample < skimsMu.ntuples.size() ; iSample++){
    
    heppySkimTree* ntuple = skimsMu.ntuples[iSample];
    mutagSR_versusMET.addNtuple(ntuple,skimsMu.sampleName[iSample]);
    mutagSB_versusMET.addNtuple(ntuple,skimsMu.sampleName[iSample]);
    muantitagSR_versusMET.addNtuple(ntuple,skimsMu.sampleName[iSample]);
    muantitagSB_versusMET.addNtuple(ntuple,skimsMu.sampleName[iSample]);

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
      if( antiTaggingCut(ntuple) ){
	double testMass = arbitrationFunc(ntuple);
	if( testMass > 85. && testMass < 135. ){ 
	  muantitagSR_versusMET.fill(ntuple);
	}else if( testMass > 50. && testMass < 200. ){
	  muantitagSB_versusMET.fill(ntuple);
	}
      }
    }
  }

  //TString signalSampleName="mGluino1600";
  TString signalSampleName=argv[1];
  // Signal samples
  heppySkimTree* ntuple = skims.findNtuple(signalSampleName);
  tagSR_versusMET.addSignalNtuple(skims.findNtuple(signalSampleName),signalSampleName);
  tagSB_versusMET.addSignalNtuple(skims.findNtuple(signalSampleName),signalSampleName);
  mutagSR_versusMET.addSignalNtuple(skims.findNtuple(signalSampleName),signalSampleName);
  mutagSB_versusMET.addSignalNtuple(skims.findNtuple(signalSampleName),signalSampleName);
  
  int numEvents = ntuple->fChain->GetEntries();
  for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
    ntuple->GetEntry(iEvt);
    if( iEvt % 1000000 == 0 ) cout << signalSampleName << ": " << iEvt << "/" << numEvents << endl;
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
  }

  mutagSR_versusMET.buildSum();
  mutagSB_versusMET.buildSum();
  muantitagSR_versusMET.buildSum();
  muantitagSB_versusMET.buildSum();

  double QCDexpSR[nBins],QCDexpSB[nBins],QCDexpASR[nBins],QCDexpASB[nBins];
  double tWexpSR[nBins],tWexpSB[nBins],tWexpASR[nBins],tWexpASB[nBins];
  double tWexpMuSR[nBins],tWexpMuSB[nBins],tWexpMuASR[nBins],tWexpMuASB[nBins];
  double signalSR[nBins];

  TH1F NsigMeasured("NsigMeasured","NsigMeasured",30,0,3);

  TRandom r;

  int Ntoys = 1000;
  for( int iToy = 0 ; iToy < Ntoys ; iToy++ ){

    cout << "generate toy data" << endl;
    RooDataSet data("data","",*wspace->set("obs"));

    for( int i = 0 ; i < nBins ; i++ ){ 
      TString index="_";
      index+=i;
      
      
      QCDexpSR[i] = tagSR_versusMET.histoMap[skims.findNtuple("QCD")]->GetBinContent(i+1) + tagSR_versusMET.histoMap[skims.findNtuple("ZJets")]->GetBinContent(i+1) ;
      QCDexpSB[i] = tagSB_versusMET.histoMap[skims.findNtuple("QCD")]->GetBinContent(i+1) + tagSB_versusMET.histoMap[skims.findNtuple("ZJets")]->GetBinContent(i+1) ;
      QCDexpASR[i] = antitagSR_versusMET.histoMap[skims.findNtuple("QCD")]->GetBinContent(i+1) + antitagSR_versusMET.histoMap[skims.findNtuple("ZJets")]->GetBinContent(i+1) ;
      QCDexpASB[i] = antitagSB_versusMET.histoMap[skims.findNtuple("QCD")]->GetBinContent(i+1) + antitagSB_versusMET.histoMap[skims.findNtuple("ZJets")]->GetBinContent(i+1) ;
      
      tWexpSR[i] = tagSR_versusMET.histoMap[skims.findNtuple("TT")]->GetBinContent(i+1) + tagSR_versusMET.histoMap[skims.findNtuple("WJets")]->GetBinContent(i+1) ;
      tWexpSB[i] = tagSB_versusMET.histoMap[skims.findNtuple("TT")]->GetBinContent(i+1) + tagSB_versusMET.histoMap[skims.findNtuple("WJets")]->GetBinContent(i+1) ;
      tWexpASR[i] = antitagSR_versusMET.histoMap[skims.findNtuple("TT")]->GetBinContent(i+1) + antitagSR_versusMET.histoMap[skims.findNtuple("WJets")]->GetBinContent(i+1) ;
      tWexpASB[i] = antitagSB_versusMET.histoMap[skims.findNtuple("TT")]->GetBinContent(i+1) + antitagSB_versusMET.histoMap[skims.findNtuple("WJets")]->GetBinContent(i+1) ;
      
      tWexpMuSR[i] = mutagSR_versusMET.histoMap[skimsMu.findNtuple("TT")]->GetBinContent(i+1) + mutagSR_versusMET.histoMap[skimsMu.findNtuple("WJets")]->GetBinContent(i+1) ;
      tWexpMuSB[i] = mutagSB_versusMET.histoMap[skimsMu.findNtuple("TT")]->GetBinContent(i+1) + mutagSB_versusMET.histoMap[skimsMu.findNtuple("WJets")]->GetBinContent(i+1) ;
      tWexpMuASR[i] = muantitagSR_versusMET.histoMap[skimsMu.findNtuple("TT")]->GetBinContent(i+1) + muantitagSR_versusMET.histoMap[skimsMu.findNtuple("WJets")]->GetBinContent(i+1) ;
      tWexpMuASB[i] = muantitagSB_versusMET.histoMap[skimsMu.findNtuple("TT")]->GetBinContent(i+1) + muantitagSB_versusMET.histoMap[skimsMu.findNtuple("WJets")]->GetBinContent(i+1) ;
      
      signalSR[i] = tagSR_versusMET.signalHistoMap[skims.findNtuple(signalSampleName)]->GetBinContent(i+1);

      wspace->var("QCDexpASB"+index)->setVal(QCDexpASB[i]);
      wspace->var("QCDexpSB"+index)->setVal(QCDexpSB[i]);
      wspace->var("RantiPassFailTW"+index)->setVal(tWexpMuASR[i]/tWexpMuASB[i]);
      wspace->var("Rlost")->setVal(3.8);
      wspace->var("RpassFailTW"+index)->setVal(tWexpMuSR[i]/tWexpMuSB[i]);
      wspace->var("RpassFailQCD"+index)->setVal(QCDexpASR[i]/QCDexpASB[i]);
      wspace->var("tWexpMuASB"+index)->setVal(tWexpMuASB[i]);
      wspace->var("tWexpMuSB"+index)->setVal(tWexpMuSB[i]);
      wspace->var("mu")->setVal(1.);
      wspace->var("expSig"+index)->setVal(signalSR[i]);

      wspace->var("obsSR"+index)->setVal(r.Poisson(QCDexpSR[i]+tWexpSR[i]+signalSR[i]));
      wspace->var("obsSB"+index)->setVal(r.Poisson(QCDexpSB[i]+tWexpSB[i]));
      wspace->var("obsMuSB"+index)->setVal(r.Poisson(tWexpMuSB[i]));
      wspace->var("obsMuSR"+index)->setVal(r.Poisson(tWexpMuSR[i]));
      wspace->var("obsASB"+index)->setVal(r.Poisson(QCDexpSB[i]+tWexpASB[i]));
      wspace->var("obsASR"+index)->setVal(r.Poisson(QCDexpASR[i]+tWexpASR[i]));
      wspace->var("obsMuASB"+index)->setVal(r.Poisson(tWexpMuASB[i]));
      wspace->var("obsMuASR"+index)->setVal(r.Poisson(tWexpMuASR[i]));
      
    }

    cout << "add data" << endl;
    data.add(*wspace->set("obs"));
    //data.Print("v");

    cout << "fit toy data" << endl;
    wspace->pdf("model")->fitTo(data,RooFit::PrintEvalErrors(-1));

    cout << "mu: " << wspace->var("mu")->getVal() << endl;
    NsigMeasured.Fill(wspace->var("mu")->getVal());

  }
  
  TCanvas* can = new TCanvas("can","can",500,500);
  NsigMeasured.Draw();
  gStyle->SetOptStat(111);
  can->SaveAs("40fbFullLikelihoodSignalBias_"+signalSampleName+".png");

  cout << "Measured Signal: " << NsigMeasured.GetMean() << " +/- " << NsigMeasured.GetRMS()/sqrt(Ntoys) << endl; 
  cout << "RMS Measured Signal: " << NsigMeasured.GetRMS() << endl;

  return 1;
}
  
