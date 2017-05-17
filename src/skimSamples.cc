// ROOT/custom libraries
#include "TChain.h"
#include "RA2bTree.cc"
#include "TString.h"

// STL libraries
#include <iostream>
#include <vector>

static const TString BASE_DIR="root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/";

class skimSamples{

public : 

    TChain *WJets,*ZJets,*QCD,*SnglT,*TT,*TTExtra,*GJets,*GJets0p4,*Other,*DY; 
    TChain *QCDfrank,*GJetsfrank,*GJets0p4frank,*DYfrank; 
    TChain *mGluino1300, *mGluino1400, *mGluino1500, *mGluino1600, *mGluino1700;
    TChain *T5HH750, *T5HH1000, *T5HH1100,*T5HH1200,*T5HH1300,*T5HH1400,*T5HH1500,*T5HH1600,*T5HH1700,*T5HH1800,*T5HH1900,*T5HH2000,*T5HH2100;
    TChain *data;
    std::vector<RA2bTree*> ntuples,signalNtuples;
    RA2bTree* dataNtuple;
    std::vector<TString> sampleName, signalSampleName;
    std::vector<TString> dataSampleName; 
    std::vector<int> fillColor, lineColor, sigLineColor;

    enum region {kSignal,kPhoton,kSLm,kSLe,kLowDPhi,kNumRegions};
    TString regionNames[kNumRegions]={"signal","photon","SLm","SLe","LDP"};

    TString skimType,skimTypeLDP;

    skimSamples(region r=kSignal){

        skimType="";
        skimTypeLDP="";

        if( r == kSignal ){
            skimType=BASE_DIR+"tree_signal/";
            //skimTypeLDP=BASE_DIR+"tree_LDP/";
        }
        if( r == kPhoton ){
            skimType="root://cmseos.fnal.gov//store/user/fojensen/boostedSkims/";
            skimTypeLDP="root://cmseos.fnal.gov//store/user/fojensen/boostedSkims/";
        }
        if( r == kSLm ){
            skimType=BASE_DIR+"tree_SLm/";
            //skimTypeLDP=BASE_DIR+"tree_SLmLDP/";
        }
        if( r == kSLe ){
            skimType=BASE_DIR+"tree_SLe/";
            //skimTypeLDP=BASE_DIR+"tree_SLeLDP/";
        }
	if(r == kLowDPhi){
		skimTypeLDP=BASE_DIR+"tree_LDP/";
        }
        ///////////////////////////////////////////////////////////////////////
        // - - - - - - - - - - BACKGROUND INPUTS - - - - - - - - - - - - - - //
        ///////////////////////////////////////////////////////////////////////
        
        // -- Frank's private skims -- 
        std::vector<TString> QCDfrankFileNames;
        QCDfrankFileNames.push_back("Summer16.QCD_HT300to500.root");
        QCDfrankFileNames.push_back("Summer16.QCD_HT500to700.root");
        QCDfrankFileNames.push_back("Summer16.QCD_HT700to1000.root");
        QCDfrankFileNames.push_back("Summer16.QCD_HT1000to1500.root");
        QCDfrankFileNames.push_back("Summer16.QCD_HT1500to2000.root");
        QCDfrankFileNames.push_back("Summer16.QCD_HT2000toInf.root");
        QCDfrank = new TChain("PreSelection");
        for( int i = 0 ; i < QCDfrankFileNames.size() ; i++ ){
            QCDfrank->Add(skimType+"/"+QCDfrankFileNames[i]);
        }
        if( r == kPhoton ){ 
            ntuples.push_back(new RA2bTree(QCDfrank));
            sampleName.push_back("QCD");
            fillColor.push_back(kGray);
            lineColor.push_back(1);
        }

        std::vector<TString> GJetsfrankFileNames;
        GJetsfrankFileNames.push_back("Summer16.GJets_DR-0p4_HT-100To200.root");
        GJetsfrankFileNames.push_back("Summer16.GJets_DR-0p4_HT-200To400.root");
        GJetsfrankFileNames.push_back("Summer16.GJets_DR-0p4_HT-400To600.root");
        GJetsfrankFileNames.push_back("Summer16.GJets_DR-0p4_HT-600ToInf.root");
        GJetsfrank = new TChain("PreSelection");
        for( int i = 0 ; i < GJetsfrankFileNames.size() ; i++ ){
            GJetsfrank->Add(skimType+"/"+GJetsfrankFileNames[i]);
        }
        if( r == kPhoton ){ 
            ntuples.push_back(new RA2bTree(GJetsfrank));
            sampleName.push_back("GJets");
            fillColor.push_back(kGreen);
            lineColor.push_back(1);
        }

        std::vector<TString> SinglePhotonFrankFileNames;
        SinglePhotonFrankFileNames.push_back("Run2016B-03Feb2017_ver2-v2.SinglePhoton.root");
        SinglePhotonFrankFileNames.push_back("Run2016C-03Feb2017-v1.SinglePhoton.root");
        SinglePhotonFrankFileNames.push_back("Run2016D-03Feb2017-v1.SinglePhoton.root");
        SinglePhotonFrankFileNames.push_back("Run2016E-03Feb2017-v1.SinglePhoton.root");
        SinglePhotonFrankFileNames.push_back("Run2016F-03Feb2017-v1.SinglePhoton.root");
        SinglePhotonFrankFileNames.push_back("Run2016G-03Feb2017-v1.SinglePhoton.root");
        SinglePhotonFrankFileNames.push_back("Run2016H-03Feb2017_ver2-v1.SinglePhoton.root");
        SinglePhotonFrankFileNames.push_back("Run2016H-03Feb2017_ver3-v1.SinglePhoton.root");
        if( r == kPhoton ){
            data = new TChain("PreSelection");
            for( int i = 0 ; i < SinglePhotonFrankFileNames.size() ; i++ ){
                data->Add(skimType+"/"+SinglePhotonFrankFileNames[i]);
            }
            dataNtuple = new RA2bTree(data);
        }
        
        // -- RA2b central skims -- 
        std::vector<TString> OtherFileNames;
        OtherFileNames.push_back("tree_WWTo1L1Nu2Q.root");
        OtherFileNames.push_back("tree_WWTo2L2Nu.root");
        OtherFileNames.push_back("tree_WWZ.root");
        OtherFileNames.push_back("tree_WZTo1L1Nu2Q.root");
        OtherFileNames.push_back("tree_WZTo1L3Nu.root");
        OtherFileNames.push_back("tree_WZZ.root");
        OtherFileNames.push_back("tree_ZZTo2L2Q.root");
        OtherFileNames.push_back("tree_ZZTo2Q2Nu.root");
        OtherFileNames.push_back("tree_ZZZ.root");
        OtherFileNames.push_back("tree_TTTT.root");
        OtherFileNames.push_back("tree_TTWJetsToLNu.root");
        OtherFileNames.push_back("tree_TTWJetsToQQ.root");
        OtherFileNames.push_back("tree_TTGJets.root");
        OtherFileNames.push_back("tree_TTZToLLNuNu.root");
        OtherFileNames.push_back("tree_TTZToQQ.root");
        Other = new TChain("tree");
        for( int i = 0 ; i < OtherFileNames.size() ; i++ ){
            if(r==kSignal)Other->Add(skimType+"/"+OtherFileNames[i]);
           if(r==kLowDPhi)Other->Add(skimTypeLDP+"/"+OtherFileNames[i]);
        }
        if( r == kSignal || r == kSLm || r == kSLe ){
            ntuples.push_back(new RA2bTree(Other));
            sampleName.push_back("Other");
            fillColor.push_back(kRed+1);
            lineColor.push_back(1);
        }
        std::vector<TString> ZJetsFileNames;
        ZJetsFileNames.push_back("tree_ZJetsToNuNu_HT-100to200.root");
        ZJetsFileNames.push_back("tree_ZJetsToNuNu_HT-200to400.root");
        ZJetsFileNames.push_back("tree_ZJetsToNuNu_HT-400to600.root");
        ZJetsFileNames.push_back("tree_ZJetsToNuNu_HT-600to800.root");
        ZJetsFileNames.push_back("tree_ZJetsToNuNu_HT-800to1200.root");
        ZJetsFileNames.push_back("tree_ZJetsToNuNu_HT-1200to2500.root");
        ZJetsFileNames.push_back("tree_ZJetsToNuNu_HT-2500toInf.root");
        ZJets = new TChain("tree");
        for( int i = 0 ; i < ZJetsFileNames.size() ; i++ ){
            if(r==kSignal)ZJets->Add(skimType+"/"+ZJetsFileNames[i]);
            if(r==kLowDPhi)ZJets->Add(skimTypeLDP+"/"+ZJetsFileNames[i]);
            }
        if( r == kSignal || r==kLowDPhi ){ 
            ntuples.push_back(new RA2bTree(ZJets));
            sampleName.push_back("ZJets");
            fillColor.push_back(kGreen+1);
            lineColor.push_back(1);
        }
        std::vector<TString> WJetsFileNames;
        WJetsFileNames.push_back("tree_WJetsToLNu_HT-100to200.root");
        WJetsFileNames.push_back("tree_WJetsToLNu_HT-1200to2500.root");
        WJetsFileNames.push_back("tree_WJetsToLNu_HT-200to400.root");
        WJetsFileNames.push_back("tree_WJetsToLNu_HT-2500toInf.root");
        WJetsFileNames.push_back("tree_WJetsToLNu_HT-400to600.root");
        WJetsFileNames.push_back("tree_WJetsToLNu_HT-600to800.root");
        WJetsFileNames.push_back("tree_WJetsToLNu_HT-800to1200.root");
        WJets = new TChain("tree");
        for( int i = 0 ; i < WJetsFileNames.size() ; i++ ){
            if(r==kSignal)WJets->Add(skimType+"/"+WJetsFileNames[i]);
            if(r==kLowDPhi)WJets->Add(skimTypeLDP+"/"+WJetsFileNames[i]);
        }
        if( r == kSignal || r == kSLm || r == kSLe || r==kLowDPhi ){
            ntuples.push_back(new RA2bTree(WJets));
            sampleName.push_back("WJets");
            fillColor.push_back(kBlue);
            lineColor.push_back(1);
        }
        std::vector<TString> SnglTFileNames;
        SnglTFileNames.push_back("tree_ST_s-channel.root");
        SnglTFileNames.push_back("tree_ST_t-channel_antitop.root");
        SnglTFileNames.push_back("tree_ST_t-channel_top.root");
        SnglTFileNames.push_back("tree_ST_tW_antitop.root");
        SnglTFileNames.push_back("tree_ST_tW_top.root");
        SnglT = new TChain("tree");
        for( int i = 0 ; i < SnglTFileNames.size() ; i++ ) {
         if(r==kSignal)SnglT->Add(skimType+"/"+SnglTFileNames[i]);
         if(r==kLowDPhi) SnglT->Add(skimTypeLDP+"/"+SnglTFileNames[i]);
        }
        if( r == kSignal || r == kSLm || r == kSLe  || r==kLowDPhi){
            ntuples.push_back(new RA2bTree(SnglT));
            sampleName.push_back("SnglT");
            fillColor.push_back(kOrange);
            lineColor.push_back(1);
        }
        std::vector<TString> TTFileNames;
        //TTFileNames.push_back("tree_TTJets.root");
        TTFileNames.push_back("tree_TTJets_HT-600to800.root");
        TTFileNames.push_back("tree_TTJets_HT-800to1200.root");
        TTFileNames.push_back("tree_TTJets_HT-1200to2500.root");
        TTFileNames.push_back("tree_TTJets_HT-2500toInf.root");
        TT = new TChain("tree");
        for( int i = 0 ; i < TTFileNames.size() ; i++ ){
           if(r==kSignal) TT->Add(skimType+"/"+TTFileNames[i]);
           if(r==kLowDPhi)TT->Add(skimTypeLDP+"/"+TTFileNames[i]);

        }
        if( r == kSignal || r == kSLm || r == kSLe ||r==kLowDPhi ){
            ntuples.push_back(new RA2bTree(TT));
            sampleName.push_back("TT");
            fillColor.push_back(kCyan);
            lineColor.push_back(kCyan);
        }
        std::vector<TString> TTExtraFileNames;
        TTExtraFileNames.push_back("tree_TTJets_SingleLeptFromT.root");
        TTExtraFileNames.push_back("tree_TTJets_SingleLeptFromTbar.root");
        TTExtraFileNames.push_back("tree_TTJets_DiLept.root");        
        TTExtra = new TChain("tree");
        for( int i = 0 ; i < TTExtraFileNames.size() ; i++ ){
          if(r==kSignal)TTExtra->Add(skimType+"/"+TTExtraFileNames[i]);
          if(r==kLowDPhi)TTExtra->Add(skimTypeLDP+"/"+TTExtraFileNames[i]);
        }
        if( r == kSignal || r == kSLm || r == kSLe || r==kLowDPhi ){
            ntuples.push_back(new RA2bTree(TTExtra));
            sampleName.push_back("TTExtra");
            fillColor.push_back(kCyan);
            lineColor.push_back(1);
        }
        std::vector<TString> DYFileNames;
        DYFileNames.push_back("tree_DYJetsToLL_M-50_HT-100to200.root");
        DYFileNames.push_back("tree_DYJetsToLL_M-50_HT-200to400.root");
        DYFileNames.push_back("tree_DYJetsToLL_M-50_HT-400to600.root");
        DYFileNames.push_back("tree_DYJetsToLL_M-50_HT-600toInf.root");
        DY = new TChain("tree");
        for( int i = 0 ; i < DYFileNames.size() ; i++ ){
            DY->Add(skimType+"/"+DYFileNames[i]);
         //   DY->Add(skimTypeLDP+"/"+DYFileNames[i]);
        }
        //ntuples.push_back(new RA2bTree(DY));
        //sampleName.push_back("DY");
        //fillColor.push_back(kGreen);
        //lineColor.push_back(1);
	/*
        std::vector<TString> GJets0p4FileNames;
        GJets0p4FileNames.push_back("tree_GJets_DR-0p4_HT-100to200.root");
        GJets0p4FileNames.push_back("tree_GJets_DR-0p4_HT-200to400.root");
        GJets0p4FileNames.push_back("tree_GJets_DR-0p4_HT-400to600.root");
        GJets0p4FileNames.push_back("tree_GJets_DR-0p4_HT-600toInf.root");
        GJets0p4 = new TChain("tree");
        for( int i = 0 ; i < GJets0p4FileNames.size() ; i++ ){
            GJets0p4->Add(skimType+"/"+GJets0p4FileNames[i]);
          //  GJets0p4->Add(skimTypeLDP+"/"+GJets0p4FileNames[i]);
        }
        //if( r == kPhoton || r== kPhotonLDP ){
        //ntuples.push_back(new RA2bTree(GJets0p4));
        //sampleName.push_back("GJets");
        //fillColor.push_back(kGreen);
        //lineColor.push_back(1);
        //}

        std::vector<TString> GJetsFileNames;
        GJetsFileNames.push_back("tree_GJets_HT-100to200.root");
        GJetsFileNames.push_back("tree_GJets_HT-200to400.root");
        GJetsFileNames.push_back("tree_GJets_HT-400to600.root");
        GJetsFileNames.push_back("tree_GJets_HT-600toInf.root");
        GJets = new TChain("tree");
        for( int i = 0 ; i < GJetsFileNames.size() ; i++ ){
            GJets->Add(skimType+"/"+GJetsFileNames[i]);
         //   GJets->Add(skimTypeLDP+"/"+GJetsFileNames[i]);
        }
	*/
/*
        if( r == kPhoton ){
            ntuples.push_back(new RA2bTree(GJets));
            sampleName.push_back("GJets");
            fillColor.push_back(kGreen);
            lineColor.push_back(1);
        }*/

        std::vector<TString> QCDFileNames;
        QCDFileNames.push_back("tree_QCD_HT-200to300.root");
        QCDFileNames.push_back("tree_QCD_HT-300to500.root");
        QCDFileNames.push_back("tree_QCD_HT-500to700.root");
        QCDFileNames.push_back("tree_QCD_HT-700to1000.root");
        QCDFileNames.push_back("tree_QCD_HT-1000to1500.root");
        QCDFileNames.push_back("tree_QCD_HT-1000to1500.root");
        QCDFileNames.push_back("tree_QCD_HT-1500to2000.root");
        QCDFileNames.push_back("tree_QCD_HT-2000toInf.root");
        QCD = new TChain("tree");
        for( int i = 0 ; i < QCDFileNames.size() ; i++ ){
            if(r==kSignal)QCD->Add(skimType+"/"+QCDFileNames[i]);
            if(r==kLowDPhi)QCD->Add(skimTypeLDP+"/"+QCDFileNames[i]);
        }
        if( r == kSignal || r == kLowDPhi ){
            ntuples.push_back(new RA2bTree(QCD));
            sampleName.push_back("QCD");
            fillColor.push_back(kGray);
            lineColor.push_back(1);
        }


        ////////////////////////////////////////////////////////////
        // - - - - - - - - - - - DATA INPUTS - - - - - - - - - -  //
        ////////////////////////////////////////////////////////////

        std::vector<TString> HTMHTFileNames;
        std::vector<TString> HTFileNames;
        HTFileNames.push_back("tree_JetHT_re2016B.root");
        HTFileNames.push_back("tree_JetHT_re2016C.root");
        HTFileNames.push_back("tree_JetHT_re2016D.root");
        HTFileNames.push_back("tree_JetHT_re2016E.root");
        HTFileNames.push_back("tree_JetHT_re2016F.root");
        HTFileNames.push_back("tree_JetHT_re2016G.root");
        HTFileNames.push_back("tree_JetHT_re2016H2.root");
        HTFileNames.push_back("tree_JetHT_re2016H3.root");
        HTMHTFileNames.push_back("tree_HTMHT_re2016B.root");
        HTMHTFileNames.push_back("tree_HTMHT_re2016C.root");
        HTMHTFileNames.push_back("tree_HTMHT_re2016D.root");
        HTMHTFileNames.push_back("tree_HTMHT_re2016E.root");
        HTMHTFileNames.push_back("tree_HTMHT_re2016F.root");
        HTMHTFileNames.push_back("tree_HTMHT_re2016G.root");
        HTMHTFileNames.push_back("tree_HTMHT_re2016H2.root");
        HTMHTFileNames.push_back("tree_HTMHT_re2016H3.root");
        if( r == kSignal || r==kLowDPhi ){
            data = new TChain("tree");
            for( int i = 0 ; i < HTMHTFileNames.size() ; i++ ){
                if(r==kSignal)data->Add(skimType+"/"+HTMHTFileNames[i]);
		if(r==kLowDPhi)data->Add(skimTypeLDP+"/"+HTFileNames[i]);
            }    
            dataNtuple = new RA2bTree(data); 
        }

        std::vector<TString> SingleElectronNames;
        SingleElectronNames.push_back("tree_SingleElectron_re2016C.root");
        SingleElectronNames.push_back("tree_SingleElectron_re2016D.root");
        SingleElectronNames.push_back("tree_SingleElectron_re2016E.root");
        SingleElectronNames.push_back("tree_SingleElectron_re2016F.root");
        SingleElectronNames.push_back("tree_SingleElectron_re2016G.root");
        SingleElectronNames.push_back("tree_SingleElectron_re2016H2.root");
        SingleElectronNames.push_back("tree_SingleElectron_re2016H3.root");
        if( r == kSLe ){
            data = new TChain("tree");
            for( int i = 0 ; i < SingleElectronNames.size() ; i++ ){
                data->Add(skimType+"/"+SingleElectronNames[i]);
              //  data->Add(skimTypeLDP+"/"+SingleElectronNames[i]);
            }
            dataNtuple = new RA2bTree(data);
        }

        std::vector<TString> SingleMuonNames;
        SingleMuonNames.push_back("tree_SingleMuon_re2016B.root");
        SingleMuonNames.push_back("tree_SingleMuon_re2016C.root");
        SingleMuonNames.push_back("tree_SingleMuon_re2016D.root");
        SingleMuonNames.push_back("tree_SingleMuon_re2016E.root");
        SingleMuonNames.push_back("tree_SingleMuon_re2016F.root");
        SingleMuonNames.push_back("tree_SingleMuon_re2016G.root");
        SingleMuonNames.push_back("tree_SingleMuon_re2016H2.root");
        SingleMuonNames.push_back("tree_SingleMuon_re2016H3.root");
        if( r == kSLm ){
            data = new TChain("tree");
            for( int i = 0 ; i < SingleMuonNames.size() ; i++ ){
                data->Add(skimType+"/"+SingleMuonNames[i]);
           //     data->Add(skimTypeLDP+"/"+SingleMuonNames[i]);
            }
            dataNtuple = new RA2bTree(data);
        }

        std::vector<TString> SinglePhotonFileNames;
        SinglePhotonFileNames.push_back("tree_SinglePhoton_re2016B.root");
        SinglePhotonFileNames.push_back("tree_SinglePhoton_re2016C.root");
        SinglePhotonFileNames.push_back("tree_SinglePhoton_re2016D.root");
        SinglePhotonFileNames.push_back("tree_SinglePhoton_re2016E.root");
        SinglePhotonFileNames.push_back("tree_SinglePhoton_re2016F.root");
        SinglePhotonFileNames.push_back("tree_SinglePhoton_re2016G.root");
        SinglePhotonFileNames.push_back("tree_SinglePhoton_re2016H2.root");
        SinglePhotonFileNames.push_back("tree_SinglePhoton_re2016H3.root");
        /*if( r == kPhoton ){
            data = new TChain("tree");
            for( int i = 0 ; i < SinglePhotonFileNames.size() ; i++ ){
                data->Add(skimTypeLDP+"/"+SinglePhotonFileNames[i]);
                data->Add(skimType+"/"+SinglePhotonFileNames[i]);
            }
            dataNtuple = new RA2bTree(data);
        }*/
	std::vector<TString> T5HH750FilesNames;
	std::vector<TString> T5HH1000FilesNames;
	std::vector<TString> T5HH1100FilesNames;
	std::vector<TString> T5HH1200FilesNames;
	std::vector<TString> T5HH1300FilesNames;
	std::vector<TString> T5HH1400FilesNames;
	std::vector<TString> T5HH1500FilesNames;
	std::vector<TString> T5HH1600FilesNames;
	std::vector<TString> T5HH1700FilesNames;
	std::vector<TString> T5HH1800FilesNames;
	std::vector<TString> T5HH1900FilesNames;
	std::vector<TString> T5HH2000FilesNames;
	std::vector<TString> T5HH2100FilesNames;
	for(unsigned int i=0; i<14; ++i)T5HH750FilesNames.push_back(TString::Format("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino750_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_%d_RA2AnalysisTree.root",i));
	for(unsigned int i=0; i<19; ++i)T5HH1000FilesNames.push_back(TString::Format("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_%d_RA2AnalysisTree.root",i));
	for(unsigned int i=0; i<11; ++i)T5HH1100FilesNames.push_back(TString::Format("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_%d_RA2AnalysisTree.root",i));
	for(unsigned int i=0; i<22; ++i)T5HH1200FilesNames.push_back(TString::Format("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_%d_RA2AnalysisTree.root",i));
	for(unsigned int i=0; i<13; ++i)T5HH1300FilesNames.push_back(TString::Format("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_%d_RA2AnalysisTree.root",i));
	for(unsigned int i=0; i<19; ++i)T5HH1400FilesNames.push_back(TString::Format("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_%d_RA2AnalysisTree.root",i));
	for(unsigned int i=0; i<25; ++i)T5HH1500FilesNames.push_back(TString::Format("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_%d_RA2AnalysisTree.root",i));
	for(unsigned int i=0; i<15; ++i)T5HH1600FilesNames.push_back(TString::Format("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_%d_RA2AnalysisTree.root",i));
	for(unsigned int i=0; i<8; ++i)T5HH1700FilesNames.push_back(TString::Format("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_%d_RA2AnalysisTree.root",i));
	for(unsigned int i=0; i<9; ++i)T5HH1800FilesNames.push_back(TString::Format("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_%d_RA2AnalysisTree.root",i));
	for(unsigned int i=0; i<9; ++i)T5HH1900FilesNames.push_back(TString::Format("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1900_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_%d_RA2AnalysisTree.root",i));
	//for(unsigned int i=0; i<8; ++i)T5HH2000FilesNames.push_back(TString::Format("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_%d_RA2AnalysisTree.root",i);
	for(unsigned int i=0; i<26; ++i)T5HH2100FilesNames.push_back(TString::Format("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino2100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_%d_RA2AnalysisTree.root",i));
	/*	
        std::vector<TString> T5HH1000FilesNames;
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_0_RA2AnalysisTree.root");
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_10_RA2AnalysisTree.root");
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_11_RA2AnalysisTree.root");
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_12_RA2AnalysisTree.root");
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_13_RA2AnalysisTree.root");
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_14_RA2AnalysisTree.root");
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_15_RA2AnalysisTree.root");
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_16_RA2AnalysisTree.root");
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_17_RA2AnalysisTree.root");
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_18_RA2AnalysisTree.root");
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_1_RA2AnalysisTree.root");
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_2_RA2AnalysisTree.root");
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_3_RA2AnalysisTree.root");
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphML-pythia8_4_RA2AnalysisTree.root");
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_5_RA2AnalysisTree.root");
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_6_RA2AnalysisTree.root");
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_7_RA2AnalysisTree.root");
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_8_RA2AnalysisTree.root");
        T5HH1000FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_9_RA2AnalysisTree.root");
	*/
        if( r == kSignal ){
            T5HH750 = new TChain("TreeMaker2/PreSelection");
            for( int i = 0 ; i < T5HH750FilesNames.size() ; i++ ){
                T5HH750->Add(T5HH750FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH750));
            signalSampleName.push_back("T5HH750");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal ){
            T5HH1000 = new TChain("TreeMaker2/PreSelection");
            for( int i = 0 ; i < T5HH1000FilesNames.size() ; i++ ){
                T5HH1000->Add(T5HH1000FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1000));
            signalSampleName.push_back("T5HH1000");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal ){
            T5HH1100 = new TChain("TreeMaker2/PreSelection");
            for( int i = 0 ; i < T5HH1100FilesNames.size() ; i++ ){
                T5HH1100->Add(T5HH1100FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1100));
            signalSampleName.push_back("T5HH1100");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal ){
            T5HH1200 = new TChain("TreeMaker2/PreSelection");
            for( int i = 0 ; i < T5HH1200FilesNames.size() ; i++ ){
                T5HH1200->Add(T5HH1200FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1200));
            signalSampleName.push_back("T5HH1200");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal ){
            T5HH1300 = new TChain("TreeMaker2/PreSelection");
            for( int i = 0 ; i < T5HH1300FilesNames.size() ; i++ ){
                T5HH1300->Add(T5HH1300FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1300));
            signalSampleName.push_back("T5HH1300");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal ){
            T5HH1400 = new TChain("TreeMaker2/PreSelection");
            for( int i = 0 ; i < T5HH1400FilesNames.size() ; i++ ){
                T5HH1400->Add(T5HH1400FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1400));
            signalSampleName.push_back("T5HH1400");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal ){
            T5HH1500 = new TChain("TreeMaker2/PreSelection");
            for( int i = 0 ; i < T5HH1500FilesNames.size() ; i++ ){
                T5HH1500->Add(T5HH1500FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1500));
            signalSampleName.push_back("T5HH1500");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal ){
            T5HH1600 = new TChain("TreeMaker2/PreSelection");
            for( int i = 0 ; i < T5HH1600FilesNames.size() ; i++ ){
                T5HH1600->Add(T5HH1600FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1600));
            signalSampleName.push_back("T5HH1600");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal ){
            T5HH1700 = new TChain("TreeMaker2/PreSelection");
            for( int i = 0 ; i < T5HH1700FilesNames.size() ; i++ ){
                T5HH1700->Add(T5HH1700FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1700));
            signalSampleName.push_back("T5HH1700");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal ){
            T5HH1800 = new TChain("TreeMaker2/PreSelection");
            for( int i = 0 ; i < T5HH1800FilesNames.size() ; i++ ){
                T5HH1800->Add(T5HH1800FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1800));
            signalSampleName.push_back("T5HH1800");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal ){
            T5HH1900 = new TChain("TreeMaker2/PreSelection");
            for( int i = 0 ; i < T5HH1900FilesNames.size() ; i++ ){
                T5HH1900->Add(T5HH1900FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1900));
            signalSampleName.push_back("T5HH1900");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal ){
            T5HH2100 = new TChain("TreeMaker2/PreSelection");
            for( int i = 0 ; i < T5HH2100FilesNames.size() ; i++ ){
                T5HH2100->Add(T5HH2100FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH2100));
            signalSampleName.push_back("T5HH2100");
            sigLineColor.push_back(kRed);
        }
	/*
        std::vector<TString> T5HH1300FilesNames;
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_0_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov///store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_10_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov///store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_11_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov///store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_12_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov///store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_1_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov///store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_2_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov///store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_3_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov///store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_4_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov///store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_5_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov///store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_6_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov///store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_7_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov///store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_8_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov///store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_9_RA2AnalysisTree.root");
        if( r == kSignal ){
            T5HH1300 = new TChain("TreeMaker2/PreSelection");
            for( int i = 0 ; i < T5HH1300FilesNames.size() ; i++ ){
                T5HH1300->Add(T5HH1300FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1300));
            signalSampleName.push_back("T5HH1300");
            sigLineColor.push_back(kRed);
        }
*/
/*

        std::vector<TString> T5HH1900FilesNames;
        T5HH1900FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1900_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_0_RA2AnalysisTree.root");
T5HH1900FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1900_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_1_RA2AnalysisTree.root");
T5HH1900FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1900_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_2_RA2AnalysisTree.root");
T5HH1900FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1900_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_3_RA2AnalysisTree.root");
T5HH1900FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1900_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_4_RA2AnalysisTree.root");
T5HH1900FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1900_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_5_RA2AnalysisTree.root");
T5HH1900FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1900_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_6_RA2AnalysisTree.root");
T5HH1900FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1900_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_7_RA2AnalysisTree.root");
T5HH1900FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1900_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_8_RA2AnalysisTree.root");

        if( r == kSignal ){
            T5HH1900 = new TChain("TreeMaker2/PreSelection");
            for( int i = 0 ; i < T5HH1900FilesNames.size() ; i++ ){
                T5HH1900->Add(T5HH1900FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1900));
            signalSampleName.push_back("T5HH1900");
            sigLineColor.push_back(kRed);
        }

        std::vector<TString> T5HH1700FilesNames;
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_0_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_1_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_2_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_3_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_4_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_5_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_6_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino1700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_7_RA2AnalysisTree.root");
        if( r == kSignal ){
            T5HH1700 = new TChain("TreeMaker2/PreSelection");
            for( int i = 0 ; i < T5HH1700FilesNames.size() ; i++ ){
                T5HH1700->Add(T5HH1700FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1700));
            signalSampleName.push_back("T5HH1700");
            sigLineColor.push_back(kRed+1);
        }
*/

    };

    RA2bTree* findNtuple(TString name){
        for( int iSam = 0 ; iSam < sampleName.size() ; iSam++ ){
            if( sampleName[iSam] == name )
                return ntuples[iSam] ;
        }
        for( int iSam = 0 ; iSam < signalSampleName.size() ; iSam++ ){
            if( signalSampleName[iSam] == name )
                return signalNtuples[iSam] ;
        }
        return NULL;
    };
};
