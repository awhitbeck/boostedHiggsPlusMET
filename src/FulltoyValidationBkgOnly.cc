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
#include "TProfile.h"

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
  RooWorkspace* wspace = new RooWorkspace("wspace");

  wspace->factory("mu[1.,0.00001,10]");

  //wspace->factory("Gaussian::RpassFailQCDPrior(RpassFailQCDNuis[1.,0.00001,4.],RpassFailQCDUncMean[1.0,0.00001,10.],RpassFailQCDUncSigma[0.005,0.00001,10.])");
  //wspace->var("RpassFailQCDUncMean")->setConstant(true);
  //wspace->var("RpassFailQCDUncSigma")->setConstant(true);
  TString modelPdfs="";
  TString modelObs="";
  int nBins = 7;
  for( int i = 0 ; i < nBins ; i++ ){
    
    TString index="";
    index+=i;

    //MET dependent uncertainties:
    wspace->factory("Gaussian::RlostPrior_"+index+"(Rlost_"+index+"[3.8,0.00001,8.],RlostUncMean_"+index+"[3.8,0.00001,10.],RlostUncSigma_"+index+"[0.5,0.00001,10.])");
    wspace->var("RlostUncMean_"+index)->setConstant(true);
    wspace->var("RlostUncSigma_"+index)->setConstant(true);

    wspace->factory("Gaussian::RpassFailQCDPrior_"+index+"(RpassFailQCD_"+index+"[.6,.00001,8.],RpassFailQCDUncMean_"+index+"[0.6,0.00001,10.],RpassFailQCDUncSigma_"+index+"[0.5,0.00001,10.])");
    wspace->var("RpassFailQCDUncMean_"+index)->setConstant(true);
    wspace->var("RpassFailQCDUncSigma_"+index)->setConstant(true);
    
    

    wspace->factory("Poisson::SB_"+index+"(obsSB_"+index+"[0,10000],sum::expSB_"+index+"(QCDexpSB_"+index+"[200.,0.00001,10000],prod::tWexpSB_"+index+"(tWexpMuSB_"+index+"[200.,0.00001,10000],Rlost_"+index+")))");
    //wspace->var("Rlost")->setVal(3.8);
    //wspace->var("Rlost")->setConstant(true);
    wspace->factory("prod::tWexpSR_"+index+"(tWexpSB_"+index+",RpassFailTW_"+index+"[0.2,0.00001,2.])");
    wspace->factory("prod::QCDexpSR_"+index+"(QCDexpSB_"+index+",RpassFailQCD_"+index+")");
    wspace->factory("prod::scaledSig_"+index+"(expSig_"+index+"[20.,0,10000],mu)");
    wspace->var("expSig_"+index)->setConstant(true);
    wspace->factory("Poisson::SR_"+index+"(obsSR_"+index+"[0,10000],sum::expSR_"+index+"(scaledSig_"+index+",QCDexpSR_"+index+",tWexpSR_"+index+"))");

    wspace->factory("Poisson::muSB_"+index+"(obsMuSB_"+index+"[0,10000],tWexpMuSB_"+index+")");
    wspace->factory("Poisson::muSR_"+index+"(obsMuSR_"+index+"[0,10000],prod::expMuSR_"+index+"(tWexpMuSB_"+index+",RpassFailTW_"+index+"))");

    wspace->factory("Poisson::ASB_"+index+"(obsASB_"+index+"[0,10000],sum::expASB_"+index+"(QCDexpASB_"+index+"[200.,0.00001,10000],prod::tWexpASB_"+index+"(tWexpMuASB_"+index+"[200.,0.00001,10000],Rlost_"+index+")))");
    
    wspace->factory("Poisson::ASR_"+index+"(obsASR_"+index+"[0,10000],sum::expASR_"+index+"(prod::QCDexpASR_"+index+"(QCDexpASB_"+index+",RpassFailQCD_"+index+"),prod::tWexpASR_"+index+"(tWexpMuASB_"+index+",Rlost_"+index+",RantiPassFailTW_"+index+"[0.5,0.00001,2.])))");

    wspace->factory("Poisson::muASB_"+index+"(obsMuASB_"+index+"[0,10000],tWexpMuASB_"+index+")");

    wspace->factory("Poisson::muASR_"+index+"(obsMuASR_"+index+"[0,10000],prod::expMuASR_"+index+"(tWexpMuASB_"+index+",RantiPassFailTW_"+index+"))");
  
    if( modelPdfs == "" )
      modelPdfs+="RlostPrior_"+index+",RpassFailQCDPrior_"+index+",SB_"+index+",muSB_"+index+",muSR_"+index+",ASB_"+index+",ASR_"+index+",muASB_"+index+",muASR_"+index;
    else
      modelPdfs+=",RlostPrior_"+index+",RpassFailQCDPrior_"+index+",SB_"+index+",muSB_"+index+",muSR_"+index+",ASB_"+index+",ASR_"+index+",muASB_"+index+",muASR_"+index;
    /*
    if( modelPdfs == "" )
      modelPdfs+="RlostPrior_"+index+",SB_"+index+",muSB_"+index+",muSR_"+index+",ASB_"+index+",ASR_"+index+",muASB_"+index+",muASR_"+index;
    else
      modelPdfs+=",RlostPrior_"+index+",SB_"+index+",muSB_"+index+",muSR_"+index+",ASB_"+index+",ASR_"+index+",muASB_"+index+",muASR_"+index;
    */
    if( modelObs == "" )
      modelObs+="obsSB_"+index+",obsMuSB_"+index+",obsMuSR_"+index+",obsASB_"+index+",obsASR_"+index+",obsMuASB_"+index+",obsMuASR_"+index;
    else
      modelObs+=",obsSB_"+index+",obsMuSB_"+index+",obsMuSR_"+index+",obsASB_"+index+",obsASR_"+index+",obsMuASB_"+index+",obsMuASR_"+index;
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
    
    int numEvents = 1000;//ntuple->fChain->GetEntries();
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

    int numEvents = 1000;//ntuple->fChain->GetEntries();
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

  mutagSR_versusMET.buildSum();
  mutagSB_versusMET.buildSum();
  muantitagSR_versusMET.buildSum();
  muantitagSB_versusMET.buildSum();

  double QCDexpSR[nBins],QCDexpSB[nBins],QCDexpASR[nBins],QCDexpASB[nBins];
  double QCDexpMuSR[nBins],QCDexpMuSB[nBins],QCDexpMuASR[nBins],QCDexpMuASB[nBins];
  double tWexpSR[nBins],tWexpSB[nBins],tWexpASR[nBins],tWexpASB[nBins];
  double tWexpMuSR[nBins],tWexpMuSB[nBins],tWexpMuASR[nBins],tWexpMuASB[nBins];
  double obsSR[nBins],obsSB[nBins],obsASR[nBins],obsASB[nBins];
  double obsMuSR[nBins],obsMuSB[nBins],obsMuASR[nBins],obsMuASB[nBins];
  double signalSR[nBins];

  TH2F Closure("Closure","Closure",nBins,-0.5,nBins-0.5,40,0,4);
  TH2F NbkgMeasured("NbkgMeasured","NbkgMeasured",nBins,-0.5,nBins-0.5,400,0,1200);
  TH2F NbkgObserved("NbkgObserved","NbkgObserved",nBins,-0.5,nBins-0.5,400,0,1200);

  TRandom r;

  wspace->var("mu")->setVal(0.);
  wspace->var("mu")->setConstant(true);

  TFile* outputFile = new TFile("40fbFullLikelihoodBkgOnly.root","RECREATE");
  TTree* outputTree = new TTree("toys","toys");

  outputTree->Branch("nBins",&nBins,"nBins/I");

  outputTree->Branch("signalSR",&signalSR,"signalSR[nBins]/D");

  outputTree->Branch("obsSR",&obsSR,"obsSR[nBins]/D");
  outputTree->Branch("obsSB",&obsSB,"obsSB[nBins]/D");
  outputTree->Branch("obsASR",&obsASR,"obsASR[nBins]/D");
  outputTree->Branch("obsASB",&obsASB,"obsASB[nBins]/D");
  outputTree->Branch("obsMuSR",&obsMuSR,"obsMuSR[nBins]/D");
  outputTree->Branch("obsMuSB",&obsMuSB,"obsMuSB[nBins]/D");
  outputTree->Branch("obsMuASR",&obsMuASR,"obsMuASR[nBins]/D");
  outputTree->Branch("obsMuASB",&obsMuASB,"obsMuASB[nBins]/D");

  outputTree->Branch("QCDexpSRTruth",&QCDexpSR,"QCDexpSRTruth[nBins]/D");
  outputTree->Branch("QCDexpSBTruth",&QCDexpSB,"QCDexpSBTruth[nBins]/D");
  outputTree->Branch("QCDexpASRTruth",&QCDexpASR,"QCDexpASRTruth[nBins]/D");
  outputTree->Branch("QCDexpASBTruth",&QCDexpASB,"QCDexpASBTruth[nBins]/D");
  outputTree->Branch("QCDexpMuSRTruth",&QCDexpMuSR,"QCDexpMuSRTruth[nBins]/D");
  outputTree->Branch("QCDexpMuSBTruth",&QCDexpMuSB,"QCDexpMuSBTruth[nBins]/D");
  outputTree->Branch("QCDexpMuASRTruth",&QCDexpMuASR,"QCDexpMuASRTruth[nBins]/D");
  outputTree->Branch("QCDexpMuASBTruth",&QCDexpMuASB,"QCDexpMuASBTruth[nBins]/D");

  outputTree->Branch("tWexpSRTruth",&tWexpSR,"tWexpSRTruth[nBins]/D");
  outputTree->Branch("tWexpSBTruth",&tWexpSB,"tWexpSBTruth[nBins]/D");
  outputTree->Branch("tWexpASRTruth",&tWexpASR,"tWexpASRTruth[nBins]/D");
  outputTree->Branch("tWexpASBTruth",&tWexpASB,"tWexpASBTruth[nBins]/D");
  outputTree->Branch("tWexpMuSRTruth",&tWexpMuSR,"tWexpMuSRTruth[nBins]/D");
  outputTree->Branch("tWexpMuSBTruth",&tWexpMuSB,"tWexpMuSBTruth[nBins]/D");
  outputTree->Branch("tWexpMuASRTruth",&tWexpMuASR,"tWexpMuASRTruth[nBins]/D");
  outputTree->Branch("tWexpMuASBTruth",&tWexpMuASB,"tWexpMuASBTruth[nBins]/D");

  double tWexpMuSBfit[nBins],tWexpMuASBfit[nBins];
  double RpassFailTWfit[nBins], Rlostfit[nBins];
  double RantiPassFailTWfit[nBins];
  double QCDexpSBfit[nBins],QCDexpASBfit[nBins];
  double RpassFailQCDfit[nBins];

  outputTree->Branch("tWexpMuSBFit",&tWexpMuSBfit,"tWexpMuSBFit[nBins]/D");
  outputTree->Branch("tWexpMuASBFit",&tWexpMuASBfit,"tWexpMuASBFit[nBins]/D");
  outputTree->Branch("QCDexpSBFit",&QCDexpSBfit,"QCDexpSBFit[nBins]/D");
  outputTree->Branch("QCDexpASBFit",&QCDexpASBfit,"QCDexpASBFit[nBins]/D");
  outputTree->Branch("RpassFailQCDFit",&RpassFailQCDfit,"RpassFailQCDFit[nBins]/D");
  outputTree->Branch("RpassFailTWFit",&RpassFailTWfit,"RpassFailTWFit[nBins]/D");
  outputTree->Branch("RantiPassFailTWFit",&RantiPassFailTWfit,"RantiPassFailTWFit[nBins]/D");
  outputTree->Branch("RlostFit",&Rlostfit,"Rlost[nBins]/D");

  int Ntoys = 5000;
  for( int iToy = 0 ; iToy < Ntoys ; iToy++ ){

    cout << "generate toy data" << endl;
    RooDataSet data("data","",*wspace->set("obs"));
    cout << "check" << endl;
    for( int i = 0 ; i < nBins ; i++ ){ 
      TString index="_";
      index+=i;
      
      
      QCDexpSR[i] = tagSR_versusMET.histoMap[skims.findNtuple("QCD")]->GetBinContent(i+1) + tagSR_versusMET.histoMap[skims.findNtuple("ZJets")]->GetBinContent(i+1) ;
      QCDexpSB[i] = tagSB_versusMET.histoMap[skims.findNtuple("QCD")]->GetBinContent(i+1) + tagSB_versusMET.histoMap[skims.findNtuple("ZJets")]->GetBinContent(i+1) ;
      QCDexpASR[i] = antitagSR_versusMET.histoMap[skims.findNtuple("QCD")]->GetBinContent(i+1) + antitagSR_versusMET.histoMap[skims.findNtuple("ZJets")]->GetBinContent(i+1) ;
      QCDexpASB[i] = antitagSB_versusMET.histoMap[skims.findNtuple("QCD")]->GetBinContent(i+1) + antitagSB_versusMET.histoMap[skims.findNtuple("ZJets")]->GetBinContent(i+1) ;

      QCDexpMuSR[i] = 0.;
      QCDexpMuSB[i] = 0.;
      QCDexpMuASR[i] = 0.;
      QCDexpMuASB[i] = 0.;
      
      tWexpSR[i] = tagSR_versusMET.histoMap[skims.findNtuple("TT")]->GetBinContent(i+1) + tagSR_versusMET.histoMap[skims.findNtuple("WJets")]->GetBinContent(i+1) ;
      tWexpSB[i] = tagSB_versusMET.histoMap[skims.findNtuple("TT")]->GetBinContent(i+1) + tagSB_versusMET.histoMap[skims.findNtuple("WJets")]->GetBinContent(i+1) ;
      tWexpASR[i] = antitagSR_versusMET.histoMap[skims.findNtuple("TT")]->GetBinContent(i+1) + antitagSR_versusMET.histoMap[skims.findNtuple("WJets")]->GetBinContent(i+1) ;
      tWexpASB[i] = antitagSB_versusMET.histoMap[skims.findNtuple("TT")]->GetBinContent(i+1) + antitagSB_versusMET.histoMap[skims.findNtuple("WJets")]->GetBinContent(i+1) ;
      
      tWexpMuSR[i] = mutagSR_versusMET.histoMap[skimsMu.findNtuple("TT")]->GetBinContent(i+1) + mutagSR_versusMET.histoMap[skimsMu.findNtuple("WJets")]->GetBinContent(i+1) ;
      tWexpMuSB[i] = mutagSB_versusMET.histoMap[skimsMu.findNtuple("TT")]->GetBinContent(i+1) + mutagSB_versusMET.histoMap[skimsMu.findNtuple("WJets")]->GetBinContent(i+1) ;
      tWexpMuASR[i] = muantitagSR_versusMET.histoMap[skimsMu.findNtuple("TT")]->GetBinContent(i+1) + muantitagSR_versusMET.histoMap[skimsMu.findNtuple("WJets")]->GetBinContent(i+1) ;
      tWexpMuASB[i] = muantitagSB_versusMET.histoMap[skimsMu.findNtuple("TT")]->GetBinContent(i+1) + muantitagSB_versusMET.histoMap[skimsMu.findNtuple("WJets")]->GetBinContent(i+1) ;
      
      signalSR[i] = 1. ; // tagSR_versusMET.signalHistoMap[skims.findNtuple(signalSampleName)]->GetBinContent(i+1);

      cout << "            QCD     t/W " << endl;
      cout << "SB      " << QCDexpSB[i] << " " << tWexpSB[i] << endl;
      cout << "SB      " << QCDexpSR[i] << " " << tWexpSR[i] << endl;
      cout << "ASB     " << QCDexpASB[i] << " " << tWexpASB[i] << endl;
      cout << "ASR     " << QCDexpASR[i] << " " << tWexpASR[i] << endl;
      cout << "MuSB        0.0   " << tWexpMuSB[i] << endl;
      cout << "MuSR        0.0   " << tWexpMuSR[i] << endl;
      cout << "MuASB       0.0   " << tWexpMuASB[i] << endl;
      cout << "MuASR       0.0   " << tWexpMuASR[i] << endl;

      wspace->var("QCDexpASB"+index)->setVal(QCDexpASB[i]);
      wspace->var("QCDexpSB"+index)->setVal(QCDexpSB[i]);
      wspace->var("RantiPassFailTW"+index)->setVal(0.5);//tWexpMuASB[i]>0.?tWexpMuASR[i]/tWexpMuASB[i]:0.5);
      wspace->var("RlostUncMean"+index)->setVal(tWexpMuSB[i]>0.?tWexpSB[i]/tWexpMuSB[i]:6.0);
      wspace->var("RpassFailTW"+index)->setVal(tWexpMuSB[i]>0.?tWexpMuSR[i]/tWexpMuSB[i]:0.5);
      wspace->var("RpassFailQCDUncMean"+index)->setVal(QCDexpASB[i]>0.?QCDexpASR[i]/QCDexpASB[i]:0.5);
      //wspace->var("RpassFailQCD"+index)->setVal(QCDexpASR[i]/QCDexpASB[i]);
      wspace->var("tWexpMuASB"+index)->setVal(tWexpMuASB[i]);
      wspace->var("tWexpMuSB"+index)->setVal(tWexpMuSB[i]);
      wspace->var("expSig"+index)->setVal(signalSR[i]);

      wspace->var("obsSR"+index)->setVal(r.Poisson(QCDexpSR[i]+tWexpSR[i]));
      wspace->var("obsSB"+index)->setVal(r.Poisson(QCDexpSB[i]+tWexpSB[i]));
      wspace->var("obsMuSB"+index)->setVal(r.Poisson(tWexpMuSB[i]));
      wspace->var("obsMuSR"+index)->setVal(r.Poisson(tWexpMuSR[i]));
      wspace->var("obsASB"+index)->setVal(r.Poisson(QCDexpASB[i]+tWexpASB[i]));
      wspace->var("obsASR"+index)->setVal(r.Poisson(QCDexpASR[i]+tWexpASR[i]));
      wspace->var("obsMuASB"+index)->setVal(r.Poisson(tWexpMuASB[i]));
      wspace->var("obsMuASR"+index)->setVal(r.Poisson(tWexpMuASR[i]));

    }

    cout << "add data" << endl;
    data.add(*wspace->set("obs"));
    data.Print("v");
    if( wspace->pdf("model")->getParameters(data)->selectByAttrib("Constant",false) )
      wspace->pdf("model")->getParameters(data)->selectByAttrib("Constant",false)->Print("v");
    else 
      cout << "PROBLEM WITH FLOATING PARAMS" << endl;
    cout << "fit toy data" << endl;
    for( int i = 0 ; i < nBins ; i++ ){                                                                                                                                               
      TString index="_";                                                                                                                                                              
      index+=i;        
      cout << "SR"+index << " " << wspace->pdf("SR"+index)->getVal(*wspace->set("obs")) << endl;;
      cout << "SB"+index << " " << wspace->pdf("SB"+index)->getVal(*wspace->set("obs")) << endl;;
      cout << "ASR"+index << " " << wspace->pdf("ASR"+index)->getVal(*wspace->set("obs")) << endl;
      cout << "ASB"+index << " " << wspace->pdf("ASB"+index)->getVal(*wspace->set("obs")) << endl;
      //cout << "MuSR"+index << " " << wspace->pdf("MuSR"+index)->getVal(*wspace->set("obs")) << endl;
      //cout << "MuSB"+index << " " << wspace->pdf("MuSB"+index)->getVal(*wspace->set("obs")) << endl;
      //cout << "MuASR"+index << " " << wspace->pdf("MuASR"+index)->getVal(*wspace->set("obs")) << endl;
      cout << "MuASB"+index << " " << wspace->pdf("MuASB"+index)->getVal(*wspace->set("obs")) << endl;
    }
    cout << "model " << wspace->pdf("model")->getVal(*wspace->set("obs")) << endl;
    //wspace->pdf("model")->fitTo(data);//,RooFit::PrintEvalErrors(-1));

    data.Print("v");
    wspace->pdf("model")->getParameters(data)->selectByAttrib("Constant",false)->Print("v");

    for( int i = 0 ; i < nBins ; i++ ){
      TString index="_";
      index+=i;
      cout << "bin: " << i << endl;
      cout << "obsSR: " << wspace->var("obsSR"+index)->getVal() << endl;
      cout << "QCDexpSB: " << wspace->var("QCDexpSB"+index)->getVal() << endl;
      cout << "RpassFailQCD: " << wspace->var("RpassFailQCD"+index)->getVal() << endl;
      cout << "tWexpMuSB: " << wspace->var("tWexpMuSB"+index)->getVal() << endl;
      cout << "RpassFailTW: " << wspace->var("RpassFailTW"+index)->getVal() << endl;
      cout << "Rlost: " << wspace->var("Rlost"+index)->getVal() << endl;
      cout << " result: " << wspace->var("obsSR"+index)->getVal()/(wspace->var("QCDexpSB"+index)->getVal()*wspace->var("RpassFailQCD"+index)->getVal()+wspace->var("tWexpMuSB"+index)->getVal()*wspace->var("RpassFailTW"+index)->getVal()*wspace->var("Rlost"+index)->getVal()) << endl;
      
      NbkgObserved.Fill(i,wspace->var("obsSR"+index)->getVal());
      NbkgMeasured.Fill(i,wspace->var("QCDexpSB"+index)->getVal()*wspace->var("RpassFailQCD"+index)->getVal()+wspace->var("tWexpMuSB"+index)->getVal()*wspace->var("RpassFailTW"+index)->getVal()*wspace->var("Rlost"+index)->getVal());
      Closure.Fill(i,wspace->var("obsSR"+index)->getVal()/(wspace->var("QCDexpSB"+index)->getVal()*wspace->var("RpassFailQCD"+index)->getVal()+wspace->var("tWexpMuSB"+index)->getVal()*wspace->var("RpassFailTW"+index)->getVal()*wspace->var("Rlost"+index)->getVal()));

      obsSR[i] = wspace->var("obsSR"+index)->getVal();
      obsSB[i] = wspace->var("obsSB"+index)->getVal();
      obsASR[i] = wspace->var("obsASR"+index)->getVal();
      obsASB[i] = wspace->var("obsASB"+index)->getVal();
      obsMuSR[i] = wspace->var("obsMuSR"+index)->getVal();
      obsMuSB[i] = wspace->var("obsMuSB"+index)->getVal();
      obsMuASR[i] = wspace->var("obsMuASR"+index)->getVal();
      obsMuASB[i] = wspace->var("obsMuASB"+index)->getVal();

      tWexpMuSBfit[i] = wspace->var("tWexpMuSB"+index)->getVal();
      tWexpMuASBfit[i] = wspace->var("tWexpMuASB"+index)->getVal();
      QCDexpSBfit[i] = wspace->var("QCDexpSB"+index)->getVal();
      QCDexpASBfit[i] = wspace->var("QCDexpASB"+index)->getVal();
      RpassFailQCDfit[i] = wspace->var("RpassFailQCD"+index)->getVal();
      RpassFailTWfit[i] = wspace->var("RpassFailTW"+index)->getVal();
      RantiPassFailTWfit[i] = wspace->var("RantiPassFailTW"+index)->getVal();
      Rlostfit[i] = wspace->var("Rlost"+index)->getVal();
      
    }
    outputTree->Fill();


  }

  outputTree->Write();
  outputFile->Close();

  TCanvas* can = new TCanvas("can","can",500,500);
  can->Divide(1,2);
  can->cd(1);
  TProfile* NbkgMeasuredProf = NbkgMeasured.ProfileX("NbkgMeasuredProf",1,-1,"S");
  NbkgMeasuredProf->SetMarkerColor(2);
  NbkgMeasuredProf->SetLineColor(2);
  NbkgMeasuredProf->SetMarkerStyle(8);
  TProfile* NbkgObservedProf = NbkgObserved.ProfileX("NbkgObservedProf",1,-1,"S");
  NbkgObservedProf->SetMarkerStyle(4);
  
  NbkgMeasuredProf->GetYaxis()->SetRangeUser(0.01,max(NbkgMeasuredProf->GetMaximum(),NbkgObservedProf->GetMaximum())*10.);
  NbkgMeasuredProf->Draw();
  NbkgObservedProf->Draw("SAME");
  gPad->SetLogy();
  //NbkgMeasured.Draw("colz");
  can->cd(2);
  TProfile* ClosureProf = Closure.ProfileX("ClosureProf",1,-1,"S");
  ClosureProf->SetMarkerStyle(8);
  ClosureProf->GetYaxis()->SetRangeUser(0.,2.);
  ClosureProf->Draw();
  //NbkgObserved.Draw("colz");
  gStyle->SetOptStat(111);
  can->SaveAs("40fbFullLikelihoodBkgOnly.png");

  return 1;
}
  
