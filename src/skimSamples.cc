// ROOT/custom libraries
#include "TChain.h"
#include "RA2bTree.cc"
#include "TString.h"

// STL libraries
#include <iostream>
#include <vector>

class skimSamples{

public : 

  TString BASE_DIR, SIGNAL_DIR;
  
    TChain *WJets,*ZJets,*QCD,*SnglT,*TT,*GJets,*GJets0p4,*Other,*DY,*TTinc;
    //TChain *VBFG1000, *VBFG1200, *VBFG1400, *VBFG1600, *VBFG1800, *VBFG2000, *VBFG2500, *VBFG3000, *VBFG3500, *VBFG4000, *VBFG4500;
    TChain *VBFG1000, *VBFG2000;
    TChain *data;
    std::vector<RA2bTree*> ntuples,signalNtuples;
    RA2bTree* dataNtuple;
    std::vector<TString> sampleName, signalSampleName;
    std::vector<TString> dataSampleName; 
    std::vector<int> fillColor, lineColor, sigLineColor;

    enum system {kLPC,kTTU};
    enum region {kSignal,kPhoton,kSLm,kSLe,kLowDphi, kNumRegions};
    TString regionNames[kNumRegions]={"signal","photon","SLm","SLe","kLowDphi"};

    TString skimType;

    skimSamples(region r=kSignal, system sys=kLPC){

        if( sys == kLPC ){
	  //BASE_DIR="root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/";
	  BASE_DIR="root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV16/";
	  SIGNAL_DIR="root://cmseos.fnal.gov//store/group/lpcdm/noreplica/klamichh/SUSY_VBFZZ_Sig_Samples/";
	  cout << "system: " << BASE_DIR << endl;
	  cout << "        " << SIGNAL_DIR << endl;
	}else if( sys == kTTU ){
	  BASE_DIR="/lustre/hep/awhitbec/RA2bSkims2016/Run2ProductionV12/";
	  SIGNAL_DIR="/lustre/hep/awhitbec/RA2bSkims2016/Run2ProductionV12/VBF_signal/";
	  cout << "system: " << BASE_DIR << endl;
	  cout << "        " << SIGNAL_DIR << endl;
	}else{
	  BASE_DIR="";
	  SIGNAL_DIR="";
	  cout << "system: " << BASE_DIR << endl;
	  cout << "        " << SIGNAL_DIR << endl;
	}

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
/*        if( r == kSignal || r == kPhoton || r == kLowDphi ){
            ntuples.push_back(new RA2bTree(QCD));
            sampleName.push_back("QCD");
            fillColor.push_back(kGray);
            lineColor.push_back(1);
        }
*/
        std::vector<TString> SnglTFileNames;
        //SnglTFileNames.push_back("tree_ST_s-channel.root");
        SnglTFileNames.push_back("tree_ST_s-channel_MC2016.root");
        SnglTFileNames.push_back("tree_ST_t-channel_antitop_MC2016.root");
        SnglTFileNames.push_back("tree_ST_t-channel_top_MC2016.root");
        SnglTFileNames.push_back("tree_ST_tW_antitop_MC2016.root");
        SnglTFileNames.push_back("tree_ST_tW_top_MC2016.root");
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
 // Test KL
        std::vector<TString> TTincFileNames;
        TTincFileNames.push_back("tree_TTJets_MC2016.root");
        TTinc = new TChain("tree");
        for( unsigned int i = 0 ; i < TTincFileNames.size() ; i++ ){
            TTinc->Add(skimType+"/"+TTincFileNames[i]);
        }

	std::vector<TString> TTFileNames;
        TTFileNames.push_back("tree_TTJets_HT-600to800_MC2016.root");
        TTFileNames.push_back("tree_TTJets_HT-800to1200_MC2016.root");
        TTFileNames.push_back("tree_TTJets_HT-1200to2500_MC2016.root");
        TTFileNames.push_back("tree_TTJets_HT-2500toInf_MC2016.root");
        TTFileNames.push_back("tree_TTJets_SingleLeptFromT_MC2016.root");
        TTFileNames.push_back("tree_TTJets_SingleLeptFromTbar_MC2016.root");
        TTFileNames.push_back("tree_TTJets_DiLept_MC2016.root");        
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
 //test KL
        std::vector<TString> OtherFileNames;
        OtherFileNames.push_back("tree_WWTo1L1Nu2Q_MC2016.root");
        OtherFileNames.push_back("tree_WWTo2L2Nu_MC2016.root");
        OtherFileNames.push_back("tree_WWZ_MC2016.root");
        OtherFileNames.push_back("tree_WZTo1L1Nu2Q_MC2016.root");
        OtherFileNames.push_back("tree_WZTo1L3Nu_MC2016.root");
        OtherFileNames.push_back("tree_WZZ_MC2016.root");
        OtherFileNames.push_back("tree_ZZTo2L2Q_MC2016.root");
        OtherFileNames.push_back("tree_ZZTo2Q2Nu_MC2016.root");
        OtherFileNames.push_back("tree_ZZZ_MC2016.root");
        OtherFileNames.push_back("tree_TTTT_MC2016.root");
        OtherFileNames.push_back("tree_TTWJetsToLNu_MC2016.root");
        OtherFileNames.push_back("tree_TTWJetsToQQ_MC2016.root");
        OtherFileNames.push_back("tree_TTGJets_MC2016.root");
        OtherFileNames.push_back("tree_TTZToLLNuNu_MC2016.root");
        OtherFileNames.push_back("tree_TTZToQQ_MC2016.root");
        Other = new TChain("tree");
        for( unsigned int i = 0 ; i < OtherFileNames.size() ; i++ ){
            Other->Add(skimType+"/"+OtherFileNames[i]);
        }
        if( r == kSignal || r == kSLm || r == kSLe || r == kLowDphi || r == kPhoton ){
            ntuples.push_back(new RA2bTree(Other));
            sampleName.push_back("Other");
            //fillColor.push_back(kRed+1);
            fillColor.push_back(28);
            lineColor.push_back(1);
        }
 //test KL
        std::vector<TString> WJetsFileNames;
        WJetsFileNames.push_back("tree_WJetsToLNu_HT-100to200_MC2016.root");
        WJetsFileNames.push_back("tree_WJetsToLNu_HT-1200to2500_MC2016.root");
        WJetsFileNames.push_back("tree_WJetsToLNu_HT-200to400_MC2016.root");
        WJetsFileNames.push_back("tree_WJetsToLNu_HT-2500toInf_MC2016.root");
        WJetsFileNames.push_back("tree_WJetsToLNu_HT-400to600_MC2016.root");
        WJetsFileNames.push_back("tree_WJetsToLNu_HT-600to800_MC2016.root");
        WJetsFileNames.push_back("tree_WJetsToLNu_HT-800to1200_MC2016.root");
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
 //test KL
        std::vector<TString> ZJetsFileNames;
        ZJetsFileNames.push_back("tree_ZJetsToNuNu_HT-100to200_MC2016.root");
        ZJetsFileNames.push_back("tree_ZJetsToNuNu_HT-200to400_MC2016.root");
        ZJetsFileNames.push_back("tree_ZJetsToNuNu_HT-400to600_MC2016.root");
        ZJetsFileNames.push_back("tree_ZJetsToNuNu_HT-600to800_MC2016.root");
        ZJetsFileNames.push_back("tree_ZJetsToNuNu_HT-800to1200_MC2016.root");
        ZJetsFileNames.push_back("tree_ZJetsToNuNu_HT-1200to2500_MC2016.root");
        ZJetsFileNames.push_back("tree_ZJetsToNuNu_HT-2500toInf_MC2016.root");
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

        ////////////////////////////////////////////////////////////
        // - - - - - - - - - - - DATA INPUTS - - - - - - - - - -  //
        ////////////////////////////////////////////////////////////

        std::vector<TString> METFileNames;
        //METFileNames.push_back("tree_MET_re2016B.root");
        METFileNames.push_back("tree_MET_2016B.root");
        METFileNames.push_back("tree_MET_2016C.root");
        METFileNames.push_back("tree_MET_2016D.root");
        METFileNames.push_back("tree_MET_2016E.root");
        METFileNames.push_back("tree_MET_2016F.root");
        METFileNames.push_back("tree_MET_2016G.root");
        METFileNames.push_back("tree_MET_2016H.root");
        //METFileNames.push_back("tree_MET_2016H2.root");
        //METFileNames.push_back("tree_MET_2016H3.root");
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
        // VBF Signal
        VBFG1000 = new TChain("TreeMaker2/PreSelection");
        VBFG1000->Add(SIGNAL_DIR+"tree_VBF_ZZ_mG1000.root");
        /*VBFG1200 = new TChain("TreeMaker2/PreSelection");
        VBFG1200->Add(SIGNAL_DIR+"tree_VBF_ZZ_mG1200.root");
        VBFG1400 = new TChain("TreeMaker2/PreSelection");
        VBFG1400->Add(SIGNAL_DIR+"tree_VBF_ZZ_mG1400.root");
        VBFG1600 = new TChain("TreeMaker2/PreSelection");
        VBFG1600->Add(SIGNAL_DIR+"tree_VBF_ZZ_mG1600.root");
        VBFG1800 = new TChain("TreeMaker2/PreSelection");
        VBFG1800->Add(SIGNAL_DIR+"tree_VBF_ZZ_mG1800.root");
        */VBFG2000 = new TChain("TreeMaker2/PreSelection");
        VBFG2000->Add(SIGNAL_DIR+"tree_VBF_ZZ_mG2000.root");
        /*VBFG2500 = new TChain("TreeMaker2/PreSelection");
        VBFG2500->Add(SIGNAL_DIR+"tree_VBF_ZZ_mG2500.root");
        VBFG3000 = new TChain("TreeMaker2/PreSelection");
        VBFG3000->Add(SIGNAL_DIR+"tree_VBF_ZZ_mG3000.root");
        VBFG3500 = new TChain("TreeMaker2/PreSelection");
        VBFG3500->Add(SIGNAL_DIR+"tree_VBF_ZZ_mG3500.root");
        VBFG4000 = new TChain("TreeMaker2/PreSelection");
        VBFG4000->Add(SIGNAL_DIR+"tree_VBF_ZZ_mG4000.root");
        VBFG4500 = new TChain("TreeMaker2/PreSelection");
        VBFG4500->Add(SIGNAL_DIR+"tree_VBF_ZZ_mG4500.root");
*/
        if( r == kSignal){
            signalNtuples.push_back(new RA2bTree(VBFG1000)); signalSampleName.push_back("VBFG1000"); sigLineColor.push_back(kRed);
            /*signalNtuples.push_back(new RA2bTree(VBFG1200)); signalSampleName.push_back("VBFG1200"); sigLineColor.push_back(4);
            signalNtuples.push_back(new RA2bTree(VBFG1400)); signalSampleName.push_back("VBFG1400"); sigLineColor.push_back(5);
            signalNtuples.push_back(new RA2bTree(VBFG1600)); signalSampleName.push_back("VBFG1600"); sigLineColor.push_back(8);
            signalNtuples.push_back(new RA2bTree(VBFG1800)); signalSampleName.push_back("VBFG1800"); sigLineColor.push_back(6);
            */signalNtuples.push_back(new RA2bTree(VBFG2000)); signalSampleName.push_back("VBFG2000"); sigLineColor.push_back(28);
            /*signalNtuples.push_back(new RA2bTree(VBFG2500)); signalSampleName.push_back("VBFG2500"); sigLineColor.push_back(45);
            signalNtuples.push_back(new RA2bTree(VBFG3000)); signalSampleName.push_back("VBFG3000"); sigLineColor.push_back(kCyan);
            signalNtuples.push_back(new RA2bTree(VBFG3500)); signalSampleName.push_back("VBFG3500"); sigLineColor.push_back(39);
            signalNtuples.push_back(new RA2bTree(VBFG4000)); signalSampleName.push_back("VBFG4000"); sigLineColor.push_back(9);
            signalNtuples.push_back(new RA2bTree(VBFG4500)); signalSampleName.push_back("VBFG4500"); sigLineColor.push_back(kBlack);
        */}
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
