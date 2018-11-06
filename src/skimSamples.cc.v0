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

    TChain *WJets,*ZJets,*QCD,*SnglT,*TT,*GJets,*GJets0p4,*Other,*DY,*TTinc;
    TChain *T5HH750, *T5HH1000, *T5HH1100,*T5HH1200,*T5HH1300,*T5HH1400,*T5HH1500,*T5HH1600,*T5HH1700,*T5HH1800,*T5HH1900,*T5HH2000,*T5HH2100;
    TChain *TChiHH127, *TChiHH150, *TChiHH175,*TChiHH200,*TChiHH225,*TChiHH250,*TChiHH275,*TChiHH300,*TChiHH325,*TChiHH350,*TChiHH375;
    TChain *TChiHH400,*TChiHH425,*TChiHH450,*TChiHH475,*TChiHH500,*TChiHH525,*TChiHH550,*TChiHH575,*TChiHH600,*TChiHH625,*TChiHH650,*TChiHH675;
    TChain *TChiHH700,*TChiHH725,*TChiHH750,*TChiHH775,*TChiHH800,*TChiHH825,*TChiHH850,*TChiHH875,*TChiHH900,*TChiHH925,*TChiHH950,*TChiHH975,*TChiHH1000;
    TChain *data;
    std::vector<RA2bTree*> ntuples,signalNtuples;
    RA2bTree* dataNtuple;
    std::vector<TString> sampleName, signalSampleName;
    std::vector<TString> dataSampleName; 
    std::vector<int> fillColor, lineColor, sigLineColor;

    enum signalType {kGluino,kElectroweak};
    enum region {kSignal,kPhoton,kSLm,kSLe,kLowDphi, kNumRegions};
    TString regionNames[kNumRegions]={"signal","photon","SLm","SLe","kLowDphi"};

    TString skimType;

    skimSamples(region r=kSignal, signalType s=kGluino){

        skimType="";

        if( r == kSignal ){
            skimType=BASE_DIR+"tree_signal/";
        }
        if( r == kPhoton ){
            skimType="root://cmseos.fnal.gov//store/user/fojensen/boostedSkims_19062017/Run2ProductionV12/tree_GJet/";
        }
        if( r == kSLm ){
            skimType=BASE_DIR+"tree_SLm/";
        }
        if( r == kSLe ){
            skimType=BASE_DIR+"tree_SLe/";
        }
        if(r==kLowDphi){
            skimType=BASE_DIR+"tree_LDP/";
        }
        ///////////////////////////////////////////////////////////////////////
        // - - - - - - - - - - BACKGROUND INPUTS - - - - - - - - - - - - - - //
        ///////////////////////////////////////////////////////////////////////

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
        for( unsigned int i = 0 ; i < OtherFileNames.size() ; i++ ){
            Other->Add(skimType+"/"+OtherFileNames[i]);
        }
        if( r == kSignal || r == kSLm || r == kSLe || r == kLowDphi || r == kPhoton ){
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
        for( unsigned int i = 0 ; i < ZJetsFileNames.size() ; i++ ){
            ZJets->Add(skimType+"/"+ZJetsFileNames[i]);
        }
        if( r == kSignal || r == kLowDphi ){ 
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
        for( unsigned int i = 0 ; i < WJetsFileNames.size() ; i++ ){
            WJets->Add(skimType+"/"+WJetsFileNames[i]);
        }
        if( r == kSignal || r == kSLm || r == kSLe || r == kLowDphi ){
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
        for( unsigned int i = 0 ; i < SnglTFileNames.size() ; i++ ) {
            SnglT->Add(skimType+"/"+SnglTFileNames[i]);
        }
        if( r == kSignal || r == kSLm || r == kSLe ){
            ntuples.push_back(new RA2bTree(SnglT));
            sampleName.push_back("SnglT");
            fillColor.push_back(kOrange);
            lineColor.push_back(1);
        }

        std::vector<TString> TTincFileNames;
        TTincFileNames.push_back("tree_TTJets.root");
        TTinc = new TChain("tree");
        for( unsigned int i = 0 ; i < TTincFileNames.size() ; i++ ){
            TTinc->Add(skimType+"/"+TTincFileNames[i]);
        }
        /*
        if( r == kSignal || r == kSLm || r == kSLe || r == kLowDphi ){
            ntuples.push_back(new RA2bTree(TTinc));
            sampleName.push_back("TT");
            fillColor.push_back(kCyan);
            lineColor.push_back(kCyan);
        }
        */

        std::vector<TString> TTFileNames;
        TTFileNames.push_back("tree_TTJets_HT-600to800.root");
        TTFileNames.push_back("tree_TTJets_HT-800to1200.root");
        TTFileNames.push_back("tree_TTJets_HT-1200to2500.root");
        TTFileNames.push_back("tree_TTJets_HT-2500toInf.root");
        TTFileNames.push_back("tree_TTJets_SingleLeptFromT.root");
        TTFileNames.push_back("tree_TTJets_SingleLeptFromTbar.root");
        TTFileNames.push_back("tree_TTJets_DiLept.root");        
        TT = new TChain("tree");
        for( unsigned int i = 0 ; i < TTFileNames.size() ; i++ ){
            TT->Add(skimType+"/"+TTFileNames[i]);
        }
        if( r == kSignal || r == kSLm || r == kSLe || r == kLowDphi ){
            ntuples.push_back(new RA2bTree(TT));
            sampleName.push_back("TT");
            fillColor.push_back(kCyan);
            lineColor.push_back(kCyan);
        }

        std::vector<TString> DYFileNames;
        DYFileNames.push_back("tree_DYJetsToLL_M-50_HT-100to200.root");
        DYFileNames.push_back("tree_DYJetsToLL_M-50_HT-200to400.root");
        DYFileNames.push_back("tree_DYJetsToLL_M-50_HT-400to600.root");
        DYFileNames.push_back("tree_DYJetsToLL_M-50_HT-600toInf.root");
        DY = new TChain("tree");
        for( unsigned int i = 0 ; i < DYFileNames.size() ; i++ ){
            DY->Add(skimType+"/"+DYFileNames[i]);
            //DY->Add(skimTypeLDP+"/"+DYFileNames[i]);
        }
        //ntuples.push_back(new RA2bTree(DY));
        //sampleName.push_back("DY");
        //fillColor.push_back(kGreen);
        //lineColor.push_back(1);

        std::vector<TString> GJets0p4FileNames;
        GJets0p4FileNames.push_back("tree_GJets_DR-0p4_HT-100to200.root");
        GJets0p4FileNames.push_back("tree_GJets_DR-0p4_HT-200to400.root");
        GJets0p4FileNames.push_back("tree_GJets_DR-0p4_HT-400to600.root");
        GJets0p4FileNames.push_back("tree_GJets_DR-0p4_HT-600toInf.root");
        GJets0p4 = new TChain("tree");
        for( unsigned int i = 0 ; i < GJets0p4FileNames.size() ; i++ ){
            GJets0p4->Add(skimType+"/"+GJets0p4FileNames[i]);
        }
        if( r == kPhoton ){
            ntuples.push_back(new RA2bTree(GJets0p4));
            sampleName.push_back("GJets");
            fillColor.push_back(kGreen);
            lineColor.push_back(1);
        }

        std::vector<TString> GJetsFileNames;
        GJetsFileNames.push_back("tree_GJets_HT-100to200.root");
        GJetsFileNames.push_back("tree_GJets_HT-200to400.root");
        GJetsFileNames.push_back("tree_GJets_HT-400to600.root");
        GJetsFileNames.push_back("tree_GJets_HT-600toInf.root");
        GJets = new TChain("tree");
        for( unsigned int i = 0 ; i < GJetsFileNames.size() ; i++ ){
            GJets->Add(skimType+"/"+GJetsFileNames[i]);
        }
        /*if( r == kPhoton ){
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
        QCDFileNames.push_back("tree_QCD_HT-1500to2000.root");
        QCDFileNames.push_back("tree_QCD_HT-2000toInf.root");
        QCD = new TChain("tree");
        for( unsigned int i = 0 ; i < QCDFileNames.size() ; i++ ){
            QCD->Add(skimType+"/"+QCDFileNames[i]);
        }
        if( r == kSignal || r == kPhoton || r == kLowDphi ){
            ntuples.push_back(new RA2bTree(QCD));
            sampleName.push_back("QCD");
            fillColor.push_back(kGray);
            lineColor.push_back(1);
        }


        ////////////////////////////////////////////////////////////
        // - - - - - - - - - - - DATA INPUTS - - - - - - - - - -  //
        ////////////////////////////////////////////////////////////

        std::vector<TString> METFileNames;
        METFileNames.push_back("tree_MET_re2016B.root");
        METFileNames.push_back("tree_MET_re2016C.root");
        METFileNames.push_back("tree_MET_re2016D.root");
        METFileNames.push_back("tree_MET_re2016E.root");
        METFileNames.push_back("tree_MET_re2016F.root");
        METFileNames.push_back("tree_MET_re2016G.root");
        METFileNames.push_back("tree_MET_re2016H2.root");
        METFileNames.push_back("tree_MET_re2016H3.root");
        if( r == kSignal || r == kLowDphi ){
            data = new TChain("tree");
            for( unsigned int i = 0 ; i < METFileNames.size() ; i++ ){
                data->Add(skimType+"/"+METFileNames[i]);
            }    
            dataNtuple = new RA2bTree(data);
            //ntuples.push_back(dataNtuple);
            sampleName.push_back("data"); 
            fillColor.push_back(kWhite);
            lineColor.push_back(1);
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
            for( unsigned int i = 0 ; i < SingleElectronNames.size() ; i++ ){
                data->Add(skimType+"/"+SingleElectronNames[i]);
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
            for( unsigned int i = 0 ; i < SingleMuonNames.size() ; i++ ){
                data->Add(skimType+"/"+SingleMuonNames[i]);
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
        if( r == kPhoton ){
            data = new TChain("tree");
            for( unsigned int i = 0 ; i < SinglePhotonFileNames.size() ; i++ ){
                data->Add(skimType+"/"+SinglePhotonFileNames[i]);
            }
            dataNtuple = new RA2bTree(data);
        }

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
        for(unsigned int i=0; i<29; ++i)T5HH2000FilesNames.push_back(TString::Format("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction_18052017/Summer16.SMS-T5qqqqZH-mGluino2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_%d_RA2AnalysisTree.root",i));
        for(unsigned int i=0; i<26; ++i)T5HH2100FilesNames.push_back(TString::Format("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino2100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_%d_RA2AnalysisTree.root",i));
        if( r == kSignal && s==kGluino ){
            T5HH750 = new TChain("TreeMaker2/PreSelection");
            for( unsigned int i = 0 ; i < T5HH750FilesNames.size() ; i++ ){
                T5HH750->Add(T5HH750FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH750));
            signalSampleName.push_back("T5HH750");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal && s==kGluino ){
            T5HH1000 = new TChain("TreeMaker2/PreSelection");
            for( unsigned int i = 0 ; i < T5HH1000FilesNames.size() ; i++ ){
                T5HH1000->Add(T5HH1000FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1000));
            signalSampleName.push_back("T5HH1000");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal && s==kGluino ){
            T5HH1100 = new TChain("TreeMaker2/PreSelection");
            for( unsigned int i = 0 ; i < T5HH1100FilesNames.size() ; i++ ){
                T5HH1100->Add(T5HH1100FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1100));
            signalSampleName.push_back("T5HH1100");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal && s==kGluino ){
            T5HH1200 = new TChain("TreeMaker2/PreSelection");
            for( unsigned int i = 0 ; i < T5HH1200FilesNames.size() ; i++ ){
                T5HH1200->Add(T5HH1200FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1200));
            signalSampleName.push_back("T5HH1200");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal && s==kGluino ){
            T5HH1300 = new TChain("TreeMaker2/PreSelection");
            for( unsigned int i = 0 ; i < T5HH1300FilesNames.size() ; i++ ){
                T5HH1300->Add(T5HH1300FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1300));
            signalSampleName.push_back("T5HH1300");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal && s==kGluino ){
            T5HH1400 = new TChain("TreeMaker2/PreSelection");
            for( unsigned int i = 0 ; i < T5HH1400FilesNames.size() ; i++ ){
                T5HH1400->Add(T5HH1400FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1400));
            signalSampleName.push_back("T5HH1400");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal && s==kGluino ){
            T5HH1500 = new TChain("TreeMaker2/PreSelection");
            for( unsigned int i = 0 ; i < T5HH1500FilesNames.size() ; i++ ){
                T5HH1500->Add(T5HH1500FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1500));
            signalSampleName.push_back("T5HH1500");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal && s==kGluino ){
            T5HH1600 = new TChain("TreeMaker2/PreSelection");
            for( unsigned int i = 0 ; i < T5HH1600FilesNames.size() ; i++ ){
                T5HH1600->Add(T5HH1600FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1600));
            signalSampleName.push_back("T5HH1600");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal && s==kGluino ){
            T5HH1700 = new TChain("TreeMaker2/PreSelection");
            for( unsigned int i = 0 ; i < T5HH1700FilesNames.size() ; i++ ){
                T5HH1700->Add(T5HH1700FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1700));
            signalSampleName.push_back("T5HH1700");
            sigLineColor.push_back(kOrange);
        }
        if( r == kSignal && s==kGluino ){
            T5HH1800 = new TChain("TreeMaker2/PreSelection");
            for( unsigned int i = 0 ; i < T5HH1800FilesNames.size() ; i++ ){
                T5HH1800->Add(T5HH1800FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1800));
            signalSampleName.push_back("T5HH1800");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal && s==kGluino ){
            T5HH1900 = new TChain("TreeMaker2/PreSelection");
            for( unsigned int i = 0 ; i < T5HH1900FilesNames.size() ; i++ ){
                T5HH1900->Add(T5HH1900FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1900));
            signalSampleName.push_back("T5HH1900");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal && s==kGluino ){
            T5HH2000 = new TChain("TreeMaker2/PreSelection");
            for( unsigned int i = 0 ; i < T5HH2000FilesNames.size() ; i++ ){
                T5HH2000->Add(T5HH2000FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH2000));
            signalSampleName.push_back("T5HH2000");
            sigLineColor.push_back(kRed);
        }
        if( r == kSignal && s==kGluino ){
            T5HH2100 = new TChain("TreeMaker2/PreSelection");
            for( unsigned int i = 0 ; i < T5HH2100FilesNames.size() ; i++ ){
                T5HH2100->Add(T5HH2100FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH2100));
            signalSampleName.push_back("T5HH2100");
            sigLineColor.push_back(kRed);
        }

        TChiHH127 = new TChain("tree");
        TChiHH127->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_127_1_fast.root");
        TChiHH150 = new TChain("tree");
        TChiHH150->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_150_1_fast.root");
        TChiHH175 = new TChain("tree");
        TChiHH175->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_175_1_fast.root");

        TChiHH200 = new TChain("tree");
        TChiHH200->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_200_1_fast.root");
        TChiHH225 = new TChain("tree");
        TChiHH225->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_225_1_fast.root");
        TChiHH250 = new TChain("tree");
        TChiHH250->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_250_1_fast.root");
        TChiHH275 = new TChain("tree");
        TChiHH275->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_275_1_fast.root");

        TChiHH300 = new TChain("tree");
        TChiHH300->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_300_1_fast.root");
        TChiHH325 = new TChain("tree");
        TChiHH325->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_325_1_fast.root");
        TChiHH350 = new TChain("tree");
        TChiHH350->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_350_1_fast.root");
        TChiHH375 = new TChain("tree");
        TChiHH375->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_375_1_fast.root");

        TChiHH400 = new TChain("tree");
        TChiHH400->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_400_1_fast.root");
        TChiHH425 = new TChain("tree");
        TChiHH425->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_425_1_fast.root");
        TChiHH450 = new TChain("tree");
        TChiHH450->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_450_1_fast.root");
        TChiHH475 = new TChain("tree");
        TChiHH475->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_475_1_fast.root");

        TChiHH500 = new TChain("tree");
        TChiHH500->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_500_1_fast.root");
        TChiHH525 = new TChain("tree");
        TChiHH525->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_525_1_fast.root");
        TChiHH550 = new TChain("tree");
        TChiHH550->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_550_1_fast.root");
        TChiHH575 = new TChain("tree");
        TChiHH575->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_575_1_fast.root");
        
        TChiHH600 = new TChain("tree");
        TChiHH600->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_600_1_fast.root");
        TChiHH625 = new TChain("tree");
        TChiHH625->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_625_1_fast.root");
        TChiHH650 = new TChain("tree");
        TChiHH650->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_650_1_fast.root");
        TChiHH675 = new TChain("tree");
        TChiHH675->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_675_1_fast.root");
        
        TChiHH700 = new TChain("tree");
        TChiHH700->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_700_1_fast.root");
        TChiHH725 = new TChain("tree");
        TChiHH725->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_725_1_fast.root");
        TChiHH750 = new TChain("tree");
        TChiHH750->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_750_1_fast.root");
        TChiHH775 = new TChain("tree");
        TChiHH775->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_775_1_fast.root");
        
        TChiHH800 = new TChain("tree");
        TChiHH800->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_800_1_fast.root");
        TChiHH825 = new TChain("tree");
        TChiHH825->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_825_1_fast.root");
        TChiHH850 = new TChain("tree");
        TChiHH850->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_850_1_fast.root");
        TChiHH875 = new TChain("tree");
        TChiHH875->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_875_1_fast.root");
        
        TChiHH900 = new TChain("tree");
        TChiHH900->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_900_1_fast.root");
        TChiHH925 = new TChain("tree");
        TChiHH925->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_925_1_fast.root");
        TChiHH950 = new TChain("tree");
        TChiHH950->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_950_1_fast.root");
        TChiHH975 = new TChain("tree");
        TChiHH975->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_975_1_fast.root");
        
        TChiHH1000 = new TChain("tree");
        TChiHH1000->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/scan/tree_signal/tree_TChiHH_HToBB_HToBB_1000_1_fast.root");

        if( r == kSignal && s == kElectroweak ){
            signalNtuples.push_back(new RA2bTree(TChiHH127)); signalSampleName.push_back("TChiHH127"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH150)); signalSampleName.push_back("TChiHH150"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH175)); signalSampleName.push_back("TChiHH175"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH200)); signalSampleName.push_back("TChiHH200"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH225)); signalSampleName.push_back("TChiHH225"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH250)); signalSampleName.push_back("TChiHH250"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH275)); signalSampleName.push_back("TChiHH275"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH300)); signalSampleName.push_back("TChiHH300"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH325)); signalSampleName.push_back("TChiHH325"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH350)); signalSampleName.push_back("TChiHH350"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH375)); signalSampleName.push_back("TChiHH375"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH400)); signalSampleName.push_back("TChiHH400"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH425)); signalSampleName.push_back("TChiHH425"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH450)); signalSampleName.push_back("TChiHH450"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH475)); signalSampleName.push_back("TChiHH475"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH500)); signalSampleName.push_back("TChiHH500"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH525)); signalSampleName.push_back("TChiHH525"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH550)); signalSampleName.push_back("TChiHH550"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH575)); signalSampleName.push_back("TChiHH575"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH600)); signalSampleName.push_back("TChiHH600"); sigLineColor.push_back(kOrange);
            signalNtuples.push_back(new RA2bTree(TChiHH625)); signalSampleName.push_back("TChiHH625"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH650)); signalSampleName.push_back("TChiHH650"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH675)); signalSampleName.push_back("TChiHH675"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH700)); signalSampleName.push_back("TChiHH700"); sigLineColor.push_back(kViolet);
            signalNtuples.push_back(new RA2bTree(TChiHH725)); signalSampleName.push_back("TChiHH725"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH750)); signalSampleName.push_back("TChiHH750"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH775)); signalSampleName.push_back("TChiHH775"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH800)); signalSampleName.push_back("TChiHH800"); sigLineColor.push_back(kMagenta);
            signalNtuples.push_back(new RA2bTree(TChiHH825)); signalSampleName.push_back("TChiHH825"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH850)); signalSampleName.push_back("TChiHH850"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH875)); signalSampleName.push_back("TChiHH875"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH900)); signalSampleName.push_back("TChiHH900"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH925)); signalSampleName.push_back("TChiHH925"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH950)); signalSampleName.push_back("TChiHH950"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH975)); signalSampleName.push_back("TChiHH975"); sigLineColor.push_back(kRed);
            signalNtuples.push_back(new RA2bTree(TChiHH1000)); signalSampleName.push_back("TChiHH1000"); sigLineColor.push_back(kRed);
        }
    };

    RA2bTree* findNtuple(TString name){
        for( unsigned int iSam = 0 ; iSam < sampleName.size() ; iSam++ ){
            if( sampleName[iSam] == name )
                return ntuples[iSam] ;
        }
        for( unsigned int iSam = 0 ; iSam < signalSampleName.size() ; iSam++ ){
            if( signalSampleName[iSam] == name )
                return signalNtuples[iSam] ;
        }
        return NULL;
    };

};
