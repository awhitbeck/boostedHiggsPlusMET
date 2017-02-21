#include "TChain.h"
#include "RA2bTree.cc"
#include "TString.h"

#include <vector>

class skimSamples{

public : 

    TChain *WJets, *ZJets, *QCD, *TT,*GJets,*GJets0p4,*Other,*DY; 
    TChain *mGluino1300, *mGluino1400, *mGluino1500, *mGluino1600, *mGluino1700;
    TChain *T5HH1300,*T5HH1700;
    TChain *data;
    std::vector<RA2bTree*> ntuples,signalNtuples;
    RA2bTree* dataNtuple;
    std::vector<TString> sampleName, signalSampleName;
    std::vector<TString> dataSampleName; 
    std::vector<int> fillColor, lineColor;

    enum region {kSignal,kPhoton,kSLm,kSLe,kNumRegions};
    TString regionNames[kNumRegions]={"signal","photon","SLm","SLe"};

    TString skimType,skimTypeLDP;

    skimSamples(region r=kSignal){

        skimType="";
        skimTypeLDP="";

        if( r == kSignal ){
            skimType="root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV11/tree_signal/";
            skimTypeLDP="root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV11/tree_LDP/";
        }
        if( r == kPhoton ){
            skimType="root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV11/tree_GJet_CleanVars/";
            skimTypeLDP="root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV11/tree_GJetLDP_CleanVars/";
        }
        if( r == kSLm ){
            skimType="root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV11/tree_SLm/";
            skimTypeLDP="root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV11/tree_SLmLDP/";
        }
        if( r == kSLe ){
            skimType="root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV11/tree_SLe/";
            skimTypeLDP="root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV11/tree_SLeLDP/";
        }

        ///////////////////////////////////////////////////////////////////////
        // - - - - - - - - - - BACKGROUND INPUTS - - - - - - - - - - - - - - //
        ///////////////////////////////////////////////////////////////////////
        std::vector<TString> OtherFileNames;
        OtherFileNames.push_back("tree_ST_s-channel.root");
        OtherFileNames.push_back("tree_ST_t-channel_antitop.root");
        OtherFileNames.push_back("tree_ST_t-channel_top.root");
        OtherFileNames.push_back("tree_ST_tW_antitop.root");
        OtherFileNames.push_back("tree_ST_tW_top.root");
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
            Other->Add(skimTypeLDP+"/"+OtherFileNames[i]);
        }
        //ntuples.push_back(new RA2bTree(Other));
        //sampleName.push_back("Other");
        //fillColor.push_back(kRed+1);

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
            ZJets->Add(skimTypeLDP+"/"+ZJetsFileNames[i]);
        }
        if( r == kSignal ){ 
            ntuples.push_back(new RA2bTree(ZJets));
            sampleName.push_back("ZJets");
            fillColor.push_back(kGreen+1);
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
            WJets->Add(skimTypeLDP+"/"+WJetsFileNames[i]);
        }
        if( r == kSignal || r == kSLm || r == kSLe ){
            ntuples.push_back(new RA2bTree(WJets));
            sampleName.push_back("WJets");
            fillColor.push_back(kBlue);
        }

        std::vector<TString> TTFileNames;
        TTFileNames.push_back("tree_TTJets_HT-1200to2500.root");
        TTFileNames.push_back("tree_TTJets_HT-2500toInf.root");
        TTFileNames.push_back("tree_TTJets_HT-600to800.root");
        TTFileNames.push_back("tree_TTJets_HT-800to1200.root");
        TT = new TChain("tree");
        for( int i = 0 ; i < TTFileNames.size() ; i++ ){
            TT->Add(skimType+"/"+TTFileNames[i]);
            TT->Add(skimTypeLDP+"/"+TTFileNames[i]);
        }
        if( r == kSignal || r == kSLm || r == kSLe ){
            ntuples.push_back(new RA2bTree(TT));
            sampleName.push_back("TT");
            fillColor.push_back(kCyan);
        }

        std::vector<TString> DYFileNames;
        DYFileNames.push_back("tree_DYJetsToLL_M-50_HT-100to200.root");
        DYFileNames.push_back("tree_DYJetsToLL_M-50_HT-200to400.root");
        DYFileNames.push_back("tree_DYJetsToLL_M-50_HT-400to600.root");
        DYFileNames.push_back("tree_DYJetsToLL_M-50_HT-600toInf.root");
        DY = new TChain("tree");
        for( int i = 0 ; i < DYFileNames.size() ; i++ ){
            DY->Add(skimType+"/"+DYFileNames[i]);
            DY->Add(skimTypeLDP+"/"+DYFileNames[i]);
        }
        //ntuples.push_back(new RA2bTree(DY));
        //sampleName.push_back("DY");
        //fillColor.push_back(kGreen);

        std::vector<TString> GJets0p4FileNames;
        GJets0p4FileNames.push_back("tree_GJets_DR-0p4_HT-100to200.root");
        GJets0p4FileNames.push_back("tree_GJets_DR-0p4_HT-200to400.root");
        GJets0p4FileNames.push_back("tree_GJets_DR-0p4_HT-400to600.root");
        GJets0p4FileNames.push_back("tree_GJets_DR-0p4_HT-600toInf.root");
        GJets0p4 = new TChain("tree");
        for( int i = 0 ; i < GJets0p4FileNames.size() ; i++ ){
            GJets0p4->Add(skimType+"/"+GJets0p4FileNames[i]);
            GJets0p4->Add(skimTypeLDP+"/"+GJets0p4FileNames[i]);
        }
        //if( r == kPhoton || r== kPhotonLDP ){
        //ntuples.push_back(new RA2bTree(GJets0p4));
        //sampleName.push_back("GJets");
        //fillColor.push_back(kGreen);
        //}

        std::vector<TString> GJetsFileNames;
        GJetsFileNames.push_back("tree_GJets_HT-100to200.root");
        GJetsFileNames.push_back("tree_GJets_HT-200to400.root");
        GJetsFileNames.push_back("tree_GJets_HT-400to600.root");
        GJetsFileNames.push_back("tree_GJets_HT-600toInf.root");
        GJets = new TChain("tree");
        for( int i = 0 ; i < GJetsFileNames.size() ; i++ ){
            GJets->Add(skimType+"/"+GJetsFileNames[i]);
            GJets->Add(skimTypeLDP+"/"+GJetsFileNames[i]);
        }
        if( r == kPhoton ){
            ntuples.push_back(new RA2bTree(GJets));
            sampleName.push_back("GJets");
            fillColor.push_back(kGreen);
        }

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
            QCD->Add(skimTypeLDP+"/"+QCDFileNames[i]);
        }
        if( r == kSignal || r == kPhoton ){
            ntuples.push_back(new RA2bTree(QCD));
            sampleName.push_back("QCD");
            fillColor.push_back(kGray);
        }


        ////////////////////////////////////////////////////////////
        // - - - - - - - - - - - DATA INPUTS - - - - - - - - - -  //
        ////////////////////////////////////////////////////////////

        std::vector<TString> HTMHTFileNames;
        HTMHTFileNames.push_back("tree_HTMHT_2016B.root");
        HTMHTFileNames.push_back("tree_HTMHT_2016C.root");
        HTMHTFileNames.push_back("tree_HTMHT_2016D.root");
        HTMHTFileNames.push_back("tree_HTMHT_2016E.root");
        HTMHTFileNames.push_back("tree_HTMHT_2016F.root");
        HTMHTFileNames.push_back("tree_HTMHT_2016G.root");
        HTMHTFileNames.push_back("tree_HTMHT_2016H2.root");
        HTMHTFileNames.push_back("tree_HTMHT_2016H3.root");
        if( r == kSignal ){
            data = new TChain("tree");
            for( int i = 0 ; i < HTMHTFileNames.size() ; i++ ){
                data->Add(skimType+"/"+HTMHTFileNames[i]);
                data->Add(skimTypeLDP+"/"+HTMHTFileNames[i]);
            }    
            dataNtuple = new RA2bTree(data); 
        }

        std::vector<TString> SingleElectronNames;
        SingleElectronNames.push_back("tree_SingleElectron_2016C.root");
        SingleElectronNames.push_back("tree_SingleElectron_2016D.root");
        SingleElectronNames.push_back("tree_SingleElectron_2016E.root");
        SingleElectronNames.push_back("tree_SingleElectron_2016F.root");
        SingleElectronNames.push_back("tree_SingleElectron_2016G.root");
        SingleElectronNames.push_back("tree_SingleElectron_2016H2.root");
        SingleElectronNames.push_back("tree_SingleElectron_2016H3.root");
        if( r == kSLe ){
            data = new TChain("tree");
            for( int i = 0 ; i < SingleElectronNames.size() ; i++ ){
                data->Add(skimType+"/"+SingleElectronNames[i]);
                data->Add(skimTypeLDP+"/"+SingleElectronNames[i]);
            }
            dataNtuple = new RA2bTree(data);
        }

        std::vector<TString> SingleMuonNames;
        SingleMuonNames.push_back("tree_SingleMuon_2016B.root");
        SingleMuonNames.push_back("tree_SingleMuon_2016C.root");
        SingleMuonNames.push_back("tree_SingleMuon_2016D.root");
        SingleMuonNames.push_back("tree_SingleMuon_2016E.root");
        SingleMuonNames.push_back("tree_SingleMuon_2016F.root");
        SingleMuonNames.push_back("tree_SingleMuon_2016G.root");
        SingleMuonNames.push_back("tree_SingleMuon_2016H2.root");
        SingleMuonNames.push_back("tree_SingleMuon_2016H3.root");
        if( r == kSLm ){
            data = new TChain("tree");
            for( int i = 0 ; i < SingleMuonNames.size() ; i++ ){
                data->Add(skimType+"/"+SingleMuonNames[i]);
                data->Add(skimTypeLDP+"/"+SingleMuonNames[i]);
            }
            dataNtuple = new RA2bTree(data);
        }

        std::vector<TString> SinglePhotonFileNames;
        SinglePhotonFileNames.push_back("tree_SinglePhoton_2016B.root");
        SinglePhotonFileNames.push_back("tree_SinglePhoton_2016C.root");
        SinglePhotonFileNames.push_back("tree_SinglePhoton_2016D.root");
        SinglePhotonFileNames.push_back("tree_SinglePhoton_2016E.root");
        SinglePhotonFileNames.push_back("tree_SinglePhoton_2016F.root");
        SinglePhotonFileNames.push_back("tree_SinglePhoton_2016G.root");
        SinglePhotonFileNames.push_back("tree_SinglePhoton_2016H2.root");
        SinglePhotonFileNames.push_back("tree_SinglePhoton_2016H3.root");
        if( r == kPhoton ){
            data = new TChain("tree");
            for( int i = 0 ; i < SinglePhotonFileNames.size() ; i++ ){
                data->Add(skimTypeLDP+"/"+SinglePhotonFileNames[i]);
                data->Add(skimType+"/"+SinglePhotonFileNames[i]);
            }
            dataNtuple = new RA2bTree(data);
        }

        std::vector<TString> T5HH1300FilesNames;
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_0_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_1_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_2_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_3_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_4_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_5_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_6_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_7_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_8_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_9_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_10_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_11_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_12_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_13_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_14_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_15_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_16_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_17_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_18_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_19_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_20_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_21_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_22_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_23_RA2AnalysisTree.root");
        T5HH1300FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1300_mNLSP1250_privateProduction_24_RA2AnalysisTree.root");
        if( r == kSignal ){
            T5HH1300 = new TChain("TreeMaker2/PreSelection");
            for( int i = 0 ; i < T5HH1300FilesNames.size() ; i++ ){
                T5HH1300->Add(T5HH1300FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1300));
            signalSampleName.push_back("T5HH1300");
            lineColor.push_back(kRed);
        }

        std::vector<TString> T5HH1700FilesNames;
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_0_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_1_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_2_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_3_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_4_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_5_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_6_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_7_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_8_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_9_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_10_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_11_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_12_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_13_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_14_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_15_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_16_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_17_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_18_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_19_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_20_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_21_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_22_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_23_RA2AnalysisTree.root");
        T5HH1700FilesNames.push_back("root://cmseos.fnal.gov//store/user/awhitbe1/T5HH/Spring16.SMS-T5HH_mGluino1700_mNLSP1650_privateProduction_24_RA2AnalysisTree.root");
        if( r == kSignal ){
            T5HH1700 = new TChain("TreeMaker2/PreSelection");
            for( int i = 0 ; i < T5HH1700FilesNames.size() ; i++ ){
                T5HH1700->Add(T5HH1700FilesNames[i]);
            }
            signalNtuples.push_back(new RA2bTree(T5HH1700));
            signalSampleName.push_back("T5HH1700");
            lineColor.push_back(kRed+1);
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
