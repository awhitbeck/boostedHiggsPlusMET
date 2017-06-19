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

    TChain *WJets,*ZJets,*QCD,*SnglT,*TT,*TTExtra,*GJets,*GJets0p4,*Other,*DY,*TTinc;
    TChain *T5HH750, *T5HH1000, *T5HH1100,*T5HH1200,*T5HH1300,*T5HH1400,*T5HH1500,*T5HH1600,*T5HH1700,*T5HH1800,*T5HH1900,*T5HH2000,*T5HH2100;
    TChain *data;
    std::vector<RA2bTree*> ntuples,signalNtuples;
    RA2bTree* dataNtuple;
    std::vector<TString> sampleName, signalSampleName;
    std::vector<TString> dataSampleName; 
    std::vector<int> fillColor, lineColor, sigLineColor;

    enum region {kSignal,kPhoton,kSLm,kSLe,kLowDphi, kNumRegions};
    TString regionNames[kNumRegions]={"signal","photon","SLm","SLe","kLowDphi"};

    TString skimType;

    skimSamples(region r=kSignal){

        skimType="";

        if( r == kSignal ){
            skimType=BASE_DIR+"tree_signal/";
        }
        if( r == kPhoton ){
            skimType="root://cmseos.fnal.gov//store/user/fojensen/boostedSkims_14062017/Run2ProductionV12/tree_GJet/";
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
        for( int i = 0 ; i < OtherFileNames.size() ; i++ ){
            Other->Add(skimType+"/"+OtherFileNames[i]);
        }
        if( r == kSignal || r == kSLm || r == kSLe || r == kLowDphi ){
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
        for( int i = 0 ; i < WJetsFileNames.size() ; i++ ){
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
        for( int i = 0 ; i < SnglTFileNames.size() ; i++ ) {
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
        for( int i = 0 ; i < TTincFileNames.size() ; i++ ){
            //TTinc->Add(skimTypeLDP+"/"+TTincFileNames[i]);
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
        for( int i = 0 ; i < TTFileNames.size() ; i++ ){
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
        for( int i = 0 ; i < DYFileNames.size() ; i++ ){
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
        for( int i = 0 ; i < GJets0p4FileNames.size() ; i++ ){
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
        for( int i = 0 ; i < GJetsFileNames.size() ; i++ ){
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
        QCDFileNames.push_back("tree_QCD_HT-1000to1500.root");
        QCDFileNames.push_back("tree_QCD_HT-1500to2000.root");
        QCDFileNames.push_back("tree_QCD_HT-2000toInf.root");
        QCD = new TChain("tree");
        for( int i = 0 ; i < QCDFileNames.size() ; i++ ){
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

        std::vector<TString> HTMHTFileNames;
        HTMHTFileNames.push_back("tree_HTMHT_re2016B.root");
        HTMHTFileNames.push_back("tree_HTMHT_re2016C.root");
        HTMHTFileNames.push_back("tree_HTMHT_re2016D.root");
        HTMHTFileNames.push_back("tree_HTMHT_re2016E.root");
        HTMHTFileNames.push_back("tree_HTMHT_re2016F.root");
        HTMHTFileNames.push_back("tree_HTMHT_re2016G.root");
        HTMHTFileNames.push_back("tree_HTMHT_re2016H2.root");
        HTMHTFileNames.push_back("tree_HTMHT_re2016H3.root");
        if( r == kSignal || r == kLowDphi ){
            data = new TChain("tree");
            for( int i = 0 ; i < HTMHTFileNames.size() ; i++ ){
                data->Add(skimType+"/"+HTMHTFileNames[i]);
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
            for( int i = 0 ; i < SinglePhotonFileNames.size() ; i++ ){
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
        for(unsigned int i=0; i<26; ++i)T5HH2100FilesNames.push_back(TString::Format("root://cmseos.fnal.gov//store/user/fojensen/T5qqqqZHProduction/Summer16.SMS-T5qqqqZH-mGluino2100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_%d_RA2AnalysisTree.root",i));
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
            sigLineColor.push_back(kOrange);
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
