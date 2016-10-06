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
#include "TFile.h"
#include "TTree.h"

#include <vector>
#include <map>
#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char** argv){

  if( argc != 2 ) return 1;

  gROOT->ProcessLine(".L ~/tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");

  RooMsgService::instance().setSilentMode(true); 

  //////////////////////////////////////////////////////////////////////////////
  // - - - - - - - - - - SET UP LIKELIHOO PARAMETERIZATION - - - - - - - - -  //
  //////////////////////////////////////////////////////////////////////////////
  RooWorkspace* wspace = new RooWorkspace("wspace");
  
  wspace->factory("Gaussian::RpassFailQCDPrior(RpassFailQCD[1.,0.00001,4.],RpassFailQCDUncMean[1.,0.00001,10.],RpassFailQCDUncSigma[0.2,0.00001,10.])");
  wspace->var("RpassFailQCDUncMean")->setConstant(true);
  wspace->var("RpassFailQCDUncSigma")->setConstant(true);
  
  wspace->factory("Gaussian::RlostPrior(Rlost[1.4,0.00001,10.],RlostUncMean[1.4,0.00001,10.],RlostUncSigma[0.3,0.00001,10.])");
  wspace->var("RlostUncMean")->setConstant(true);
  wspace->var("RlostUncSigma")->setConstant(true);
  
  TString modelPdfs="RpassFailQCDPrior,RlostPrior,";
  TString modelObs="";
  int nBins = 8;
  for( int i = 0 ; i < nBins ; i++ ){
    
    TString index="";
    index+=i;
    wspace->factory("Poisson::SB_"+index+"(obsSB_"+index+"[0,10000],sum::expSB_"+index+"(QCDexpSB_"+index+"[200.,0.00001,10000],prod::tWexpSB_"+index+"(tWexpMuSB_"+index+"[200.,0.00001,10000],Rlost)))");

    wspace->factory("prod::tWexpSR_"+index+"(tWexpSB_"+index+",RpassFailTW_"+index+"[0.5,0.00001,2.])");
    wspace->factory("prod::QCDexpSR_"+index+"(QCDexpSB_"+index+",RpassFailQCD)");
    wspace->factory("prod::scaledSig_"+index+"(expSig_"+index+"[20.,0,10000],mu[1.,0.00001,10])");
    wspace->var("expSig_"+index)->setConstant(true);
    wspace->factory("Poisson::SR_"+index+"(obsSR_"+index+"[0,10000],sum::expSR_"+index+"(scaledSig_"+index+",QCDexpSR_"+index+",tWexpSR_"+index+"))");

    wspace->factory("Poisson::muSB_"+index+"(obsMuSB_"+index+"[0,10000],tWexpMuSB_"+index+")");
    wspace->factory("Poisson::muSR_"+index+"(obsMuSR_"+index+"[0,10000],tWexpMuSR_"+index+"[200.,0.00001,10000])");

    wspace->factory("Poisson::ASB_"+index+"(obsASB_"+index+"[0,10000],sum::expASB_"+index+"(QCDexpASB_"+index+"[200.,0.00001,10000],prod::tWexpASB_"+index+"(tWexpMuASB_"+index+"[200.,0.00001,10000],Rlost)))");
    
    wspace->factory("Poisson::ASR_"+index+"(obsASR_"+index+"[0,10000],sum::expASR_"+index+"(prod::QCDexpASR_"+index+"(QCDexpASB_"+index+",RpassFailQCD),prod::tWexpASR_"+index+"(tWexpMuASR_"+index+"[200.,0.00001,10000],Rlost)))");

    wspace->factory("Poisson::muASB_"+index+"(obsMuASB_"+index+"[0,10000],tWexpMuASB_"+index+")");

    wspace->factory("Poisson::muASR_"+index+"(obsMuASR_"+index+"[0,10000],tWexpMuASR_"+index+")");
    
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

  TString signalSampleName(argv[1]);
  TFile* inputFile = new TFile("datacardInputs_MET.root");

  double QCDexpSR[nBins],QCDexpSB[nBins],QCDexpASR[nBins],QCDexpASB[nBins];
  double QCDexpMuSR[nBins],QCDexpMuSB[nBins],QCDexpMuASR[nBins],QCDexpMuASB[nBins];
  double tWexpSR[nBins],tWexpSB[nBins],tWexpASR[nBins],tWexpASB[nBins];
  double tWexpMuSR[nBins],tWexpMuSB[nBins],tWexpMuASR[nBins],tWexpMuASB[nBins];
  double obsSR[nBins],obsSB[nBins],obsASR[nBins],obsASB[nBins];
  double obsMuSR[nBins],obsMuSB[nBins],obsMuASR[nBins],obsMuASB[nBins];
  double signalSR[nBins];
  double mu;

  TFile* outputFile = new TFile("40fbFullLikelihoodSignalBias.root","RECREATE");
  TTree* outputTree = new TTree("toys","toys");

  outputTree->Branch("nBins",&nBins,"nBins/I");

  outputTree->Branch("signalSR",&signalSR,"signalSR[nBins]/D");

  outputTree->Branch("mu",&mu,"mu/D");

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
  double tWexpMuSRfit[nBins],tWexpMuASRfit[nBins];
  // double RpassFailTWfit[nBins], 
  double Rlostfit;
  //double RantiPassFailTWfit[nBins];
  double QCDexpSBfit[nBins],QCDexpASBfit[nBins];
  double RpassFailQCDfit;

  outputTree->Branch("tWexpMuSBFit",&tWexpMuSBfit,"tWexpMuSBFit[nBins]/D");
  outputTree->Branch("tWexpMuASBFit",&tWexpMuASBfit,"tWexpMuASBFit[nBins]/D");
  outputTree->Branch("tWexpMuSRFit",&tWexpMuSRfit,"tWexpMuSRFit[nBins]/D");
  outputTree->Branch("tWexpMuASRFit",&tWexpMuASRfit,"tWexpMuASRFit[nBins]/D");
  outputTree->Branch("QCDexpSBFit",&QCDexpSBfit,"QCDexpSBFit[nBins]/D");
  outputTree->Branch("QCDexpASBFit",&QCDexpASBfit,"QCDexpASBFit[nBins]/D");
  outputTree->Branch("RpassFailQCDFit",&RpassFailQCDfit,"RpassFailQCDFit/D");
  //outputTree->Branch("RpassFailTWFit",&RpassFailTWfit,"RpassFailTWFit[nBins]/D");
  //outputTree->Branch("RantiPassFailTWFit",&RantiPassFailTWfit,"RantiPassFailTWFit[nBins]/D");
  outputTree->Branch("RlostFit",&Rlostfit,"Rlost/D");

  TRandom r;

  int Ntoys = 1000;
  for( int iToy = 0 ; iToy < Ntoys ; iToy++ ){

    cout << "generate toy data" << endl;
    RooDataSet data("data","",*wspace->set("obs"));

    for( int i = 0 ; i < nBins ; i++ ){ 
      TString index="_";
      index+=i;
      
      
      QCDexpSR[i] = ((TH1F*)inputFile->Get("MET_tagSR_QCD"))->GetBinContent(i+1) + ((TH1F*)inputFile->Get("MET_tagSR_ZJets"))->GetBinContent(i+1) ;
      QCDexpSB[i] = ((TH1F*)inputFile->Get("MET_tagSB_QCD"))->GetBinContent(i+1) + ((TH1F*)inputFile->Get("MET_tagSB_ZJets"))->GetBinContent(i+1) ;
      QCDexpASR[i] = ((TH1F*)inputFile->Get("MET_antitagSR_QCD"))->GetBinContent(i+1) + ((TH1F*)inputFile->Get("MET_antitagSR_ZJets"))->GetBinContent(i+1) ;
      QCDexpASB[i] = ((TH1F*)inputFile->Get("MET_antitagSB_QCD"))->GetBinContent(i+1) + ((TH1F*)inputFile->Get("MET_antitagSB_ZJets"))->GetBinContent(i+1) ;

      QCDexpMuSR[i] = 0.;
      QCDexpMuSB[i] = 0.;
      QCDexpMuASR[i] = 0.;
      QCDexpMuASB[i] = 0.;
      
      tWexpSR[i] = ((TH1F*)inputFile->Get("MET_tagSR_TT"))->GetBinContent(i+1) + ((TH1F*)inputFile->Get("MET_tagSR_WJets"))->GetBinContent(i+1) ;
      tWexpSB[i] = ((TH1F*)inputFile->Get("MET_tagSB_TT"))->GetBinContent(i+1) + ((TH1F*)inputFile->Get("MET_tagSB_WJets"))->GetBinContent(i+1) ;
      tWexpASR[i] = ((TH1F*)inputFile->Get("MET_antitagSR_TT"))->GetBinContent(i+1) + ((TH1F*)inputFile->Get("MET_antitagSR_WJets"))->GetBinContent(i+1) ;
      tWexpASB[i] = ((TH1F*)inputFile->Get("MET_antitagSB_TT"))->GetBinContent(i+1) + ((TH1F*)inputFile->Get("MET_antitagSB_WJets"))->GetBinContent(i+1) ;
      
      tWexpMuSR[i] = ((TH1F*)inputFile->Get("MET_mutagSR_TT"))->GetBinContent(i+1) + ((TH1F*)inputFile->Get("MET_mutagSR_WJets"))->GetBinContent(i+1) ;
      tWexpMuSB[i] = ((TH1F*)inputFile->Get("MET_mutagSB_TT"))->GetBinContent(i+1) + ((TH1F*)inputFile->Get("MET_mutagSB_WJets"))->GetBinContent(i+1) ;
      tWexpMuASR[i] = ((TH1F*)inputFile->Get("MET_muantitagSR_TT"))->GetBinContent(i+1) + ((TH1F*)inputFile->Get("MET_muantitagSR_WJets"))->GetBinContent(i+1) ;
      tWexpMuASB[i] = ((TH1F*)inputFile->Get("MET_muantitagSB_TT"))->GetBinContent(i+1) + ((TH1F*)inputFile->Get("MET_muantitagSB_WJets"))->GetBinContent(i+1) ;
      
      signalSR[i] = ((TH1F*)inputFile->Get("MET_tagSR_"+signalSampleName))->GetBinContent(i+1);

      wspace->var("QCDexpASB"+index)->setVal(QCDexpASB[i]);
      wspace->var("QCDexpSB"+index)->setVal(QCDexpSB[i]);
      //wspace->var("RantiPassFailTW"+index)->setVal(tWexpMuASR[i]/tWexpMuASB[i]);
      wspace->var("RpassFailQCDUncMean")->setVal(QCDexpSR[i]/QCDexpSB[i]);
      wspace->var("RlostUncMean")->setVal(tWexpMuSR[i]/tWexpSR[i]);
      //wspace->var("RpassFailTW"+index)->setVal(tWexpMuSR[i]/tWexpMuSB[i]);
      wspace->var("tWexpMuASB"+index)->setVal(tWexpMuASB[i]);
      wspace->var("tWexpMuSB"+index)->setVal(tWexpMuSB[i]);
      wspace->var("tWexpMuASR"+index)->setVal(tWexpMuASR[i]);
      wspace->var("tWexpMuSR"+index)->setVal(tWexpMuSR[i]);
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
    //if( wspace->pdf("model")->getParameters(data)->selectByAttrib("Constant",false) )
    //  wspace->pdf("model")->getParameters(data)->selectByAttrib("Constant",false)->Print("v");
    //else 
    //  cout << "PROBLEM WITH FLOATING PARAMS" << endl;
    
    cout << "fit toy data" << endl;
    wspace->pdf("model")->fitTo(data,RooFit::PrintEvalErrors(-1));

    cout << "mu: " << wspace->var("mu")->getVal() << endl;

    for( int i = 0 ; i < nBins ; i++ ){
      TString index="_";
      index+=i;
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
      tWexpMuSRfit[i] = wspace->var("tWexpMuSR"+index)->getVal();
      tWexpMuASRfit[i] = wspace->var("tWexpMuASR"+index)->getVal();
      QCDexpSBfit[i] = wspace->var("QCDexpSB"+index)->getVal();
      QCDexpASBfit[i] = wspace->var("QCDexpASB"+index)->getVal();
      RpassFailQCDfit = wspace->var("RpassFailQCD")->getVal();
      //RpassFailTWfit[i] = wspace->var("RpassFailTW"+index)->getVal();
      //RantiPassFailTWfit[i] = wspace->var("RantiPassFailTW"+index)->getVal();
      Rlostfit = wspace->var("Rlost")->getVal();

      mu = wspace->var("mu")->getVal();
    }
    outputTree->Fill();
  }
  outputFile->cd();
  outputTree->Write();
  inputFile->Close();
  outputFile->Close();
  return 1;
}
  
