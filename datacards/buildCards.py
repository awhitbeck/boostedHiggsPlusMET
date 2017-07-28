from ROOT import *
import os
import math
from searchRegion import *
from singleBin import *
from cardUtilities import *
import random
from optparse import OptionParser
from array import array

parser = OptionParser()
parser.add_option("--mGo", dest="mGo", default='2100', help="Mass of Gluino", metavar="mGo")
parser.add_option("--mu", dest="mu", default = 0.,help="mass of LSP", metavar="mu")
parser.add_option("--ScaleSyst", dest="ScaleSyst", default = 1.,help="mass of LSP", metavar="mu")
parser.add_option("--model", dest="model", default = "T5HH",help="mass of LSP", metavar="mu")
(options, args) = parser.parse_args()
#add options here


if __name__ == '__main__':

	#open ABCD Signal and Bkg
	odir="Unblinding%s%s" %(options.model,options.mGo)
	if os.path.exists(odir): os.system( "rm -rf %s" % (odir) );
	os.makedirs(odir);
	tagsForSignalRegion=["MET300", "MET500","MET700"]
	inputfile =TFile.Open("bkgInputs/datacardInputsUnblinding.root")
	#inputfile =TFile.Open("datacardInputsTest.root")
	#Signal Region 2H
	DataSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_data");
	QCDMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_QCD");
	WJetsMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_WJets");
	ZJetsMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_ZJets");
	TTJetsMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_TT");
	SnglTMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_SnglT");
	OtherMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_Other");
	#TTJetsLeptonsMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_TTExtra");
	#TTJetsMCSignalRegion2H.Add(TTJetsLeptonsMCSignalRegion2H);
	SignalT5HH_2H=inputfile.Get("AnalysisMET%s_doubletagSR_T5HH%s" %(options.model,options.mGo))
	Sigweight=35862.824*0.0460525/(408233.);
	if options.mGo=="750": Sigweight=35862.824*2.26585/(400307);
	if options.mGo=="1000": Sigweight=35862.824*0.325388/(396239);
	if options.mGo=="1100": Sigweight=35862.824*0.163491 /(413868);
	if options.mGo=="1200": Sigweight=35862.824*0.0856418/(400482);
	if options.mGo=="1300": Sigweight=35862.824*0.0460525/(408233);
	if options.mGo=="1400": Sigweight=35862.824*0.0252977/(400887);
	if options.mGo=="1500": Sigweight=35862.824*0.0141903/(394281);
	if options.mGo=="1600": Sigweight=35862.824*0.00810078/(397668);
	if options.mGo=="1700": Sigweight=35862.824*0.00470323 /(414063);
	if options.mGo=="1800": Sigweight=35862.824*0.00276133/(389625);
	if options.mGo=="1900": Sigweight=35862.824*0.00163547/(404812);
	if options.mGo=="2000": Sigweight=35862.824*0.000981077/(417293);
	if options.mGo=="2100": Sigweight=35862.824*0.000591918/(391445);
	if  options.model=="T5HH":Sigweight=Sigweight/0.25
	if options.model=="T5HZ":Sigweight=Sigweight/0.5
	#print Sigweight
	SignalT5HH_2H.Scale(Sigweight)
	#Signal Region 1H
	DataSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_data");
	QCDMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_QCD");
	WJetsMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_WJets");
	ZJetsMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_ZJets");
	TTJetsMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_TT");
	SnglTMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_SnglT");
	OtherMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_Other");
	SignalT5HH_1H=inputfile.Get("AnalysisMET%s_tagSR_T5HH%s" %(options.model,options.mGo))
	SignalT5HH_1H.Scale(Sigweight)		
	#Sideband Region 
	DataSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_data")
	QCDMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_QCD");
	WJetsMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_WJets");
	ZJetsMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_ZJets");
	TTJetsMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_TT");
	SnglTMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_SnglT");
	OtherMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_Other");
				     
	SidebandT5HH_2H=inputfile.Get("AnalysisMET%s_doubletagSB_T5HH%s" %(options.model,options.mGo))
	SidebandT5HH_2H.Scale(Sigweight)	
	#Signal Region 1H
	DataSideband1H=inputfile.Get("AnalysisMETBins_tagSB_data");
	QCDMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_QCD");
	WJetsMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_WJets");
	ZJetsMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_ZJets");
	TTJetsMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_TT");
	SnglTMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_SnglT");
	OtherMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_Other");
	SidebandT5HH_1H=inputfile.Get("AnalysisMET%s_tagSB_T5HH%s" %(options.model,options.mGo))
	SidebandT5HH_1H.Scale(Sigweight)	
	#Antitag Region
	DataAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_data") 
	QCDMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_QCD");
	WJetsMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_WJets");
	ZJetsMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_ZJets");
	TTJetsMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_TT");
	SnglTMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_SnglT");
	OtherMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_Other");
	AntitagT5HH=inputfile.Get("AnalysisMET%s_antitagSR_T5HH%s" %(options.model,options.mGo))
	AntitagT5HH.Scale(Sigweight)
	#Sideband Antitag Region 
	DataAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_data") 
	QCDMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_QCD");
	WJetsMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_WJets");
	ZJetsMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_ZJets");
	TTJetsMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_TT");
	SnglTMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_SnglT");
	OtherMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_Other");
	AntitagSBT5HH=inputfile.Get("AnalysisMET%s_antitagSB_T5HH%s" %(options.model,options.mGo))
	AntitagSBT5HH.Scale(Sigweight)
	contributionsPerBin = [];
	for i in range(len(tagsForSignalRegion)): 
		tmpcontributions = [];
		tmpcontributions.append('sig');
		tmpcontributions.append('qcd')
		tmpcontributions.append('zvv')
		tmpcontributions.append('W')
		tmpcontributions.append('Top')
		tmpcontributions.append('rare')
		contributionsPerBin.append(tmpcontributions)
	signalRegion = searchRegion('signal', contributionsPerBin, tagsForSignalRegion)	
	signalRegion1H = searchRegion('signal1H', contributionsPerBin, tagsForSignalRegion)	
	antitagRegion = searchRegion('antitagRegion', contributionsPerBin, tagsForSignalRegion)	
	sidebandATRegion = searchRegion('sidebandATRegion', contributionsPerBin, tagsForSignalRegion)	
	sidebandRegion1H = searchRegion('sidebandRegion1H', contributionsPerBin, tagsForSignalRegion)	
	sidebandRegion = searchRegion('sidebandRegion', contributionsPerBin, tagsForSignalRegion)	
	
	signalRegion1H_Rates = [];
	signalRegion1H_Obs = [];

	signalRegion_Rates = [];
	signalRegion_Obs = [];
	antitagRegionSB_Rates = [];
	antitagRegionSB_Obs = [];
	antitagRegion_Rates = [];
	antitagRegion_Obs = [];
	sideband_Rates=[]
	sideband_Obs=[]
	sideband1H_Rates=[]
	sideband1H_Obs=[]
        fout=TFile(odir+"/DatacardYields.root", "RECREATE")
	tagSRSF=readSFFile("bkgInputs/SFInputs.txt", "tagSR")
	doubletagSRSF=readSFFile("bkgInputs/SFInputs.txt", "doubletagSR")
	tagSBSF=readSFFile("bkgInputs/SFInputs.txt", "tagSB")
	doubletagSBSF=readSFFile("bkgInputs/SFInputs.txt", "doubletagSB")
	antitagSRSF=readSFFile("bkgInputs/SFInputs.txt", "antitagSR")
	antitagSBSF=readSFFile("bkgInputs/SFInputs.txt", "antitagSB")

	QCDMCSignalRegion1H.Scale(tagSRSF[0])
	WJetsMCSignalRegion1H.Scale(tagSRSF[1])
	TTJetsMCSignalRegion1H.Scale(tagSRSF[1])
	ZJetsMCSignalRegion1H.Scale(tagSRSF[2])

	QCDMCSignalRegion2H.Scale(doubletagSRSF[0])
	WJetsMCSignalRegion2H.Scale(doubletagSRSF[1])
	TTJetsMCSignalRegion2H.Scale(doubletagSRSF[1])
	ZJetsMCSignalRegion2H.Scale(doubletagSRSF[2])

	QCDMCAntitagRegion.Scale(antitagSRSF[0])
	#WJetsMCAntitagRegion.Scale(antitagSRSF[1])
	#TTJetsMCAntitagRegion.Scale(antitagSRSF[1])
	ZJetsMCAntitagRegion.Scale(antitagSRSF[2])

	QCDMCAntitagRegionSB.Scale(antitagSBSF[0])
	#WJetsMCAntitagRegionSB.Scale(antitagSBSF[1])
	#TTJetsMCAntitagRegionSB.Scale(antitagSBSF[1])
	ZJetsMCAntitagRegionSB.Scale(antitagSBSF[2])
	METDependSFATSR=[0.56, 0.43, 0.17, 0.11]
	METDependSFATSB=[0.52, 0.54, 0.32, 0.13]
	for i in range(1,4):
		TTJetsMCAntitagRegionSB.SetBinContent(i,TTJetsMCAntitagRegionSB.GetBinContent(i)*METDependSFATSB[i-1])	
		WJetsMCAntitagRegionSB.SetBinContent(i,WJetsMCAntitagRegionSB.GetBinContent(i)*METDependSFATSB[i-1])	
		TTJetsMCAntitagRegion.SetBinContent(i,TTJetsMCAntitagRegion.GetBinContent(i)*METDependSFATSR[i-1])	
		WJetsMCAntitagRegion.SetBinContent(i,WJetsMCAntitagRegion.GetBinContent(i)*METDependSFATSR[i-1])	
	QCDMCSideband1H.Scale(tagSBSF[0]) 
	WJetsMCSideband1H.Scale(tagSBSF[1])
	TTJetsMCSideband1H.Scale(tagSBSF[1])
	ZJetsMCSideband1H.Scale(tagSBSF[2])

	QCDMCSideband2H.Scale(doubletagSBSF[0])
	WJetsMCSideband2H.Scale(doubletagSBSF[1])
	TTJetsMCSideband2H.Scale(doubletagSBSF[1])
	ZJetsMCSideband2H.Scale(doubletagSBSF[2])

        METBins = array('d',[300.,500.,700.,2500.]);
        Signal2H=TH1D("Signal2H","E_{T}^{miss}", 3, METBins);
        Signal1H=TH1D("Signal1H","E_{T}^{miss}", 3, METBins);
        QCD_2H=TH1D("QCD_2H","E_{T}^{miss}", 3, METBins);
        TTJets_2H=TH1D("TTJets_2H","E_{T}^{miss}", 3, METBins);
        WJets_2H=TH1D("WJets_2H","E_{T}^{miss}", 3, METBins);
        ZJets_2H=TH1D("ZJets_2H","E_{T}^{miss}", 3, METBins);
        QCD_1H=TH1D("QCD_1H","E_{T}^{miss}", 3, METBins);
        TTJets_1H=TH1D("TTJets_1H","E_{T}^{miss}", 3, METBins);
        WJets_1H=TH1D("WJets_1H","E_{T}^{miss}", 3, METBins);
        ZJets_1H=TH1D("ZJets_1H","E_{T}^{miss}", 3, METBins);
	for i in range(signalRegion._nBins):
		tmpList = [];
		srobs = 0;
		
		tmpList.append(SignalT5HH_2H.GetBinContent(i+1));	
		tmpList.append(QCDMCSignalRegion2H.GetBinContent(i+1));	
		tmpList.append(ZJetsMCSignalRegion2H.GetBinContent(i+1));	
		tmpList.append(WJetsMCSignalRegion2H.GetBinContent(i+1));	
		tmpList.append(TTJetsMCSignalRegion2H.GetBinContent(i+1));
		tmpList.append(SnglTMCSignalRegion2H.GetBinContent(i+1)+OtherMCSignalRegion2H.GetBinContent(i+1));
		###Still Blinded	
		srobs=QCDMCSignalRegion2H.GetBinContent(i+1)+ZJetsMCSignalRegion2H.GetBinContent(i+1)+WJetsMCSignalRegion2H.GetBinContent(i+1)+TTJetsMCSignalRegion2H.GetBinContent(i+1)+SnglTMCSignalRegion2H.GetBinContent(i+1)+OtherMCSignalRegion2H.GetBinContent(i+1)
		signalRegion_Rates.append(tmpList)
		signalRegion_Obs.append(srobs)
		tmpList = [];
		tmpList.append(SignalT5HH_1H.GetBinContent(i+1));
                tmpList.append(QCDMCSignalRegion1H.GetBinContent(i+1));
                tmpList.append(ZJetsMCSignalRegion1H.GetBinContent(i+1));
                tmpList.append(WJetsMCSignalRegion1H.GetBinContent(i+1));
                tmpList.append(TTJetsMCSignalRegion1H.GetBinContent(i+1));
		tmpList.append(SnglTMCSignalRegion1H.GetBinContent(i+1)+OtherMCSignalRegion1H.GetBinContent(i+1));
		#still Blinded
                srobs=QCDMCSignalRegion1H.GetBinContent(i+1)+ZJetsMCSignalRegion1H.GetBinContent(i+1)+WJetsMCSignalRegion1H.GetBinContent(i+1)+TTJetsMCSignalRegion1H.GetBinContent(i+1)+SnglTMCSignalRegion1H.GetBinContent(i+1)+OtherMCSignalRegion1H.GetBinContent(i+1)
                signalRegion1H_Rates.append(tmpList)
                signalRegion1H_Obs.append(srobs)
		Signal2H.SetBinContent(i+1,SignalT5HH_2H.GetBinContent(i+1));
		Signal1H.SetBinContent(i+1,SignalT5HH_1H.GetBinContent(i+1));
                QCD_2H.SetBinContent(i+1,QCDMCSignalRegion2H.GetBinContent(i+1))
                TTJets_2H.SetBinContent(i+1,TTJetsMCSignalRegion2H.GetBinContent(i+1))
                ZJets_2H.SetBinContent(i+1,ZJetsMCSignalRegion2H.GetBinContent(i+1))
                WJets_2H.SetBinContent(i+1,WJetsMCSignalRegion2H.GetBinContent(i+1))
                QCD_1H.SetBinContent(i+1,QCDMCSignalRegion1H.GetBinContent(i+1))
                TTJets_1H.SetBinContent(i+1,TTJetsMCSignalRegion1H.GetBinContent(i+1))
                ZJets_1H.SetBinContent(i+1,ZJetsMCSignalRegion1H.GetBinContent(i+1))
                WJets_1H.SetBinContent(i+1,WJetsMCSignalRegion1H.GetBinContent(i+1))
        fout.cd();
        Signal1H.Write("signal_tag");
        QCD_1H.Write("QCD_tag");
        TTJets_1H.Write("TTJets_tag");
        ZJets_1H.Write("ZJets_tag");
        WJets_1H.Write("WJets_tag");
        Signal2H.Write("signal_doubletag");
        QCD_2H.Write("QCD_doubletag");
        TTJets_2H.Write("TTJets_doubletag");
        ZJets_2H.Write("ZJets_doubletag");
        WJets_2H.Write("WJets_doubletag");
        fout.Close()
	#os.system("cp DatacardYields.root ./%s " %odir) 
        for i in range(antitagRegion._nBins):
		tmpList = [];
                srobs = 0;
		tmpList.append(AntitagT5HH.GetBinContent(i+1));
		#tmpList.append(0.0);
		tmpList.append(QCDMCAntitagRegion.GetBinContent(i+1));		
		tmpList.append(ZJetsMCAntitagRegion.GetBinContent(i+1));		
		tmpList.append(WJetsMCAntitagRegion.GetBinContent(i+1));		
		tmpList.append(TTJetsMCAntitagRegion.GetBinContent(i+1));
		tmpList.append(SnglTMCAntitagRegion.GetBinContent(i+1)+OtherMCAntitagRegion.GetBinContent(i+1));
		#srobs=QCDMCAntitagRegion.GetBinContent(i+1)+ZJetsMCAntitagRegion.GetBinContent(i+1)+WJetsMCAntitagRegion.GetBinContent(i+1)+TTJetsMCAntitagRegion.GetBinContent(i+1)
		srobs=DataAntitagRegion.GetBinContent(i+1)
		#srobs=float(options.mu)*AntitagT5HH.GetBinContent(i+1)+QCDMCAntitagRegion.GetBinContent(i+1)+ZJetsMCAntitagRegion.GetBinContent(i+1)+WJetsMCAntitagRegion.GetBinContent(i+1)+TTJetsMCAntitagRegion.GetBinContent(i+1)
                antitagRegion_Rates.append(tmpList)
                antitagRegion_Obs.append(srobs)	
		tmpList = [];
                srobs = 0;
		tmpList.append(AntitagSBT5HH.GetBinContent(i+1));
		#tmpList.append(0.0);
		tmpList.append(QCDMCAntitagRegionSB.GetBinContent(i+1));		
		tmpList.append(ZJetsMCAntitagRegionSB.GetBinContent(i+1));		
		tmpList.append(WJetsMCAntitagRegionSB.GetBinContent(i+1));		
		tmpList.append(TTJetsMCAntitagRegionSB.GetBinContent(i+1));
		tmpList.append(SnglTMCAntitagRegionSB.GetBinContent(i+1)+OtherMCAntitagRegionSB.GetBinContent(i+1));
		srobs=DataAntitagRegionSB.GetBinContent(i+1)
		#srobs=float(options.mu)*AntitagSBT5HH.GetBinContent(i+1)+QCDMCAntitagRegionSB.GetBinContent(i+1)+ZJetsMCAntitagRegionSB.GetBinContent(i+1)+WJetsMCAntitagRegionSB.GetBinContent(i+1)+TTJetsMCAntitagRegionSB.GetBinContent(i+1)
                antitagRegionSB_Rates.append(tmpList)
                antitagRegionSB_Obs.append(srobs)	
	
	for i in range(sidebandRegion._nBins):
		tmpList = [];
		srobs = 0;
		tmpList.append(SidebandT5HH_2H.GetBinContent(i+1));	
		#tmpList.append(0.0);	
		tmpList.append(QCDMCSideband2H.GetBinContent(i+1));	
		tmpList.append(ZJetsMCSideband2H.GetBinContent(i+1));	
		tmpList.append(WJetsMCSideband2H.GetBinContent(i+1));	
		tmpList.append(TTJetsMCSideband2H.GetBinContent(i+1));	
		tmpList.append(SnglTMCSideband2H.GetBinContent(i+1)+OtherMCSideband2H.GetBinContent(i+1));
		#srobs=QCDMCSideband2H.GetBinContent(i+1)+ZJetsMCSideband2H.GetBinContent(i+1)+WJetsMCSideband2H.GetBinContent(i+1)+TTJetsMCSideband2H.GetBinContent(i+1)
		srobs=DataSideband2H.GetBinContent(i+1)
		#srobs=float(options.mu)*SidebandT5HH_2H.GetBinContent(i+1)+QCDMCSideband2H.GetBinContent(i+1)+ZJetsMCSideband2H.GetBinContent(i+1)+WJetsMCSideband2H.GetBinContent(i+1)+TTJetsMCSideband2H.GetBinContent(i+1)
		sideband_Rates.append(tmpList)
		sideband_Obs.append(srobs)
		tmpList = [];
		tmpList.append(SidebandT5HH_1H.GetBinContent(i+1));
		#tmpList.append(0.0);
                tmpList.append(QCDMCSideband1H.GetBinContent(i+1));
                tmpList.append(ZJetsMCSideband1H.GetBinContent(i+1));
                tmpList.append(WJetsMCSideband1H.GetBinContent(i+1));
                tmpList.append(TTJetsMCSideband1H.GetBinContent(i+1));
		tmpList.append(SnglTMCSideband1H.GetBinContent(i+1)+OtherMCSideband1H.GetBinContent(i+1));
                srobs=DataSideband1H.GetBinContent(i+1)
                #srobs=float(options.mu)*SidebandT5HH_1H.GetBinContent(i+1)+QCDMCSideband1H.GetBinContent(i+1)+ZJetsMCSideband1H.GetBinContent(i+1)+WJetsMCSideband1H.GetBinContent(i+1)+TTJetsMCSideband1H.GetBinContent(i+1)
                sideband1H_Rates.append(tmpList)
                sideband1H_Obs.append(srobs)
	
	signalRegion.fillRates(signalRegion_Rates );
	signalRegion.setObservedManually(signalRegion_Obs)
	signalRegion1H.fillRates(signalRegion1H_Rates );
	signalRegion1H.setObservedManually(signalRegion1H_Obs)
	sidebandRegion1H.fillRates(sideband1H_Rates)
	sidebandRegion1H.setObservedManually(sideband1H_Obs)
	sidebandRegion.fillRates(sideband_Rates);
	sidebandRegion.setObservedManually(sideband_Obs)
	
	signalRegion.writeRates();
	signalRegion1H.writeRates();
	sidebandRegion.writeRates();
	sidebandRegion1H.writeRates();
	
	antitagRegion.fillRates(antitagRegion_Rates);
	antitagRegion.setObservedManually(antitagRegion_Obs);
	antitagRegion.writeRates();
	sidebandATRegion.fillRates(antitagRegionSB_Rates);
	sidebandATRegion.setObservedManually(antitagRegionSB_Obs);
	sidebandATRegion.writeRates();
	#Code up the ABCD FIT
		
	kappa2H=readKappaFile("./bkgInputs/KappaInputs.txt", "doubletagSR")
	kappa1H=readKappaFile("./bkgInputs/KappaInputs.txt", "tagSR")
	kappa2Hsigma=readKappaFile("./bkgInputs/KappaInputs.txt", "doubletagSR", True)
	kappa1Hsigma=readKappaFile("./bkgInputs/KappaInputs.txt", "tagSR", True)
	signalSysInput=TFile("SignalSysInputs/SignalSysCommon.root", "READ")
	signalSysInput2=TFile("SignalSysInputs/SignalSysT5HH.root", "READ")
	ResErrdoubletagSR=binsToList(signalSysInput2.Get("MassResErr_doubletagSR_%s%s" %(options.model, options.mGo)))
	ResErrdoubletagSB=binsToList(signalSysInput2.Get("MassResErr_doubletagSB_%s%s" %(options.model, options.mGo)))
	ResErrtagSR=binsToList(signalSysInput2.Get("MassResErr_tagSR_%s%s" %(options.model, options.mGo)))
	ResErrtagSB=binsToList(signalSysInput2.Get("MassResErr_tagSB_%s%s" %(options.model, options.mGo)))
	ResErrantitagSR=binsToList(signalSysInput2.Get("MassResErr_antitagSR_%s%s" %(options.model, options.mGo)))
	ResErrantitagSB=binsToList(signalSysInput2.Get("MassResErr_antitagSB_%s%s" %(options.model, options.mGo)))
	for i in range(3):
		sidebandRegion1H.addSingleSystematic("MassResoUnc_MET%d_tag" %i, 'lnN', ['sig'], ResErrtagSB, '', i)
		signalRegion1H.addSingleSystematic("MassResoUnc_MET%d_tag" %i, 'lnN', ['sig'], ResErrtagSR, '', i)
		signalRegion.addSingleSystematic("MassResoUnc_MET%d_doubletag" %i, 'lnN', ['sig'], ResErrdoubletagSR, '', i)
		sidebandRegion.addSingleSystematic("MassResoUnc_MET%d_doubletag" %i, 'lnN', ['sig'], ResErrdoubletagSB, '', i)
		antitagRegion.addSingleSystematic("MassResoUnc_MET%d_antitag" %i, 'lnN', ['sig'], ResErrantitagSR, '', i)
		sidebandATRegion.addSingleSystematic("MassResoUnc_MET%d_antitag" %i, 'lnN', ['sig'], ResErrantitagSB, '', i)
	StatErrdoubletagSR=binsToList(signalSysInput2.Get("MCStatErr_doubletagSR_%s%s" %(options.model, options.mGo)))
	StatErrdoubletagSB=binsToList(signalSysInput2.Get("MCStatErr_doubletagSB_%s%s" %(options.model, options.mGo)))
	StatErrtagSR=binsToList(signalSysInput2.Get("MCStatErr_tagSR_%s%s" %(options.model, options.mGo)))
	StatErrtagSB=binsToList(signalSysInput2.Get("MCStatErr_tagSB_%s%s" %(options.model, options.mGo)))
	StatErrantitagSR=binsToList(signalSysInput2.Get("MCStatErr_antitagSR_%s%s" %(options.model, options.mGo)))
	StatErrantitagSB=binsToList(signalSysInput2.Get("MCStatErr_antitagSB_%s%s" %(options.model, options.mGo)))
	for i in range(3):
		 sidebandRegion1H.addSingleSystematic("MCStatUnc_sideband1H_MET%d" %i, 'lnN', ['sig'], StatErrtagSB, '', i)
		 sidebandRegion.addSingleSystematic("MCStatUnc_sideband_MET%d" %i, 'lnN', ['sig'], StatErrdoubletagSB, '', i)
		 signalRegion.addSingleSystematic("MCStatUnc_doubletag_MET%d" %i, 'lnN', ['sig'], StatErrdoubletagSR, '', i)
		 signalRegion1H.addSingleSystematic("MCStatUnc_tag_MET%d" %i, 'lnN', ['sig'], StatErrtagSR, '', i)
		 antitagRegion.addSingleSystematic("MCStatUnc_antitag_MET%d" %i,'lnN', ['sig'], StatErrantitagSR, '', i)
		 sidebandATRegion.addSingleSystematic("MCStatUnc_antitagSB_MET%d" %i,'lnN', ['sig'], StatErrantitagSB, '', i)
	BBTagSFdoubletag=binsToList(signalSysInput2.Get("BBTagSF_doubletagSR_%s%s"%(options.model, options.mGo)))
	BBTagSFtag=binsToList(signalSysInput2.Get("BBTagSF_doubletagSR_%s%s"%(options.model, options.mGo)))
	BBTagSFantitag=binsToList(signalSysInput2.Get("BBTagSF_antitagSR_%s%s"%(options.model, options.mGo)))
	BBTagSFantitagSB=binsToList(signalSysInput2.Get("BBTagSF_antitagSB_%s%s"%(options.model, options.mGo)))
	BBTagSFsideband=binsToList(signalSysInput2.Get("BBTagSF_doubletagSB_%s%s"%(options.model, options.mGo)))
	BBTagSFsideband1H=binsToList(signalSysInput2.Get("BBTagSF_tagSB_%s%s"%(options.model, options.mGo)))
	BBTagSFDndoubletag=binsToList(signalSysInput2.Get("BBTagSFDn_doubletagSR_%s%s"%(options.model, options.mGo)))
	BBTagSFDntag=binsToList(signalSysInput2.Get("BBTagSFDn_doubletagSR_%s%s"%(options.model, options.mGo)))
	BBTagSFDnantitag=binsToList(signalSysInput2.Get("BBTagSFDn_antitagSR_%s%s"%(options.model, options.mGo)))
	BBTagSFDnantitagSB=binsToList(signalSysInput2.Get("BBTagSFDn_antitagSB_%s%s"%(options.model, options.mGo)))
	BBTagSFDnsideband=binsToList(signalSysInput2.Get("BBTagSFDn_doubletagSB_%s%s"%(options.model, options.mGo)))
	BBTagSFDnsideband1H=binsToList(signalSysInput2.Get("BBTagSFDn_tagSB_%s%s"%(options.model, options.mGo)))
	for i in range(3):
		#In Mass Window
		signalRegion.addAsymSystematic("DoubleBTagSF_MET%d_SR" %i,'lnN', ['sig'], BBTagSFdoubletag,BBTagSFDndoubletag, '', i) 
		signalRegion1H.addAsymSystematic("DoubleBTagSF_MET%d_SR" %i,'lnN', ['sig'], BBTagSFtag,BBTagSFDntag, '', i) 
		antitagRegion.addAsymSystematic("DoubleBTagSF_MET%d_SR" %i,'lnN', ['sig'], BBTagSFantitag,BBTagSFDnantitag, '', i) 
		#In Sideband
		sidebandRegion.addAsymSystematic("DoubleBTagSF_MET%d_SB" %i,'lnN', ['sig'], BBTagSFsideband, BBTagSFDnsideband,'', i) 
		sidebandRegion1H.addAsymSystematic("DoubleBTagSF_MET%d_SB" %i,'lnN', ['sig'], BBTagSFsideband1H, BBTagSFDnsideband1H,'', i) 
		sidebandATRegion.addAsymSystematic("DoubleBTagSF_MET%d_SB" %i,'lnN', ['sig'], BBTagSFantitagSB, BBTagSFDnantitagSB,'', i) 

	ISRSysUp=binsToList(signalSysInput.Get("ISRUp_%s" %options.mGo));	
	ISRSysDn=binsToList(signalSysInput.Get("ISRDn_%s" %options.mGo));	
	JECSysUp=binsToList(signalSysInput.Get("JECUp_%s" %options.mGo));	
	JECSysDn=binsToList(signalSysInput.Get("JECDn_%s" %options.mGo));	
	JERSysUp=binsToList(signalSysInput.Get("JERUp_%s" %options.mGo));	
	JERSysDn=binsToList(signalSysInput.Get("JERDn_%s" %options.mGo));	
	ScaleSysUp=binsToList(signalSysInput.Get("ScaleUp_%s" %options.mGo));	
	ScaleSysDn=binsToList(signalSysInput.Get("ScaleDn_%s" %options.mGo));	
	
	signalRegion.addAsymSystematic("JECUnc", 'lnN', ['sig'], JECSysUp, JECSysDn)
	signalRegion1H.addAsymSystematic("JECUnc", 'lnN', ['sig'], JECSysUp, JECSysDn)
	antitagRegion.addAsymSystematic("JECUnc", 'lnN', ['sig'], JECSysUp, JECSysDn)
	sidebandRegion1H.addAsymSystematic("JECUnc", 'lnN', ['sig'], JECSysUp, JECSysDn)
	sidebandRegion.addAsymSystematic("JECUnc", 'lnN', ['sig'], JECSysUp, JECSysDn)
	sidebandATRegion.addAsymSystematic("JECUnc", 'lnN', ['sig'], JECSysUp, JECSysDn)
	
	signalRegion.addSingleSystematic("JERUnc", 'lnN', ['sig'], JERSysUp)
	signalRegion1H.addSingleSystematic("JERUnc", 'lnN', ['sig'], JERSysUp)
	antitagRegion.addSingleSystematic("JERUnc", 'lnN', ['sig'], JERSysUp)
	sidebandRegion1H.addSingleSystematic("JERUnc", 'lnN', ['sig'], JERSysUp)
	sidebandRegion.addSingleSystematic("JERUnc", 'lnN', ['sig'], JERSysUp)
	sidebandATRegion.addSingleSystematic("JERUnc", 'lnN', ['sig'], JERSysUp)

	signalRegion.addAsymSystematic("ScaleUnc", 'lnN', ['sig'], ScaleSysUp, ScaleSysDn)
	signalRegion1H.addAsymSystematic("ScaleUnc", 'lnN', ['sig'], ScaleSysUp, ScaleSysDn)
	antitagRegion.addAsymSystematic("ScaleUnc", 'lnN', ['sig'], ScaleSysUp, ScaleSysDn)
	sidebandRegion1H.addAsymSystematic("ScaleUnc", 'lnN', ['sig'], ScaleSysUp, ScaleSysDn)
	sidebandRegion.addAsymSystematic("ScaleUnc", 'lnN', ['sig'], ScaleSysUp, ScaleSysDn)
	sidebandATRegion.addAsymSystematic("ScaleUnc", 'lnN', ['sig'], ScaleSysUp, ScaleSysDn)
	
	signalRegion.addAsymSystematic("ISRUnc", 'lnN', ['sig'], ISRSysUp, ISRSysDn)
	signalRegion1H.addAsymSystematic("ISRUnc", 'lnN', ['sig'], ISRSysUp, ISRSysDn)
	antitagRegion.addAsymSystematic("ISRUnc", 'lnN', ['sig'], ISRSysUp, ISRSysDn)
	sidebandRegion1H.addAsymSystematic("ISRUnc", 'lnN', ['sig'], ISRSysUp, ISRSysDn)
	sidebandRegion.addAsymSystematic("ISRUnc", 'lnN', ['sig'], ISRSysUp, ISRSysDn)
	sidebandATRegion.addAsymSystematic("ISRUnc", 'lnN', ['sig'], ISRSysUp, ISRSysDn)
	signalRegion.addSingleSystematic('lumi','lnN',['sig'],1.027);
	signalRegion.addSingleSystematic('IsoTrackEff','lnN',['sig'],1.02);
	signalRegion.addSingleSystematic('TrigEff','lnN',['sig'],1.02);
	antitagRegion.addSingleSystematic('lumi','lnN',['sig'],1.027);
	antitagRegion.addSingleSystematic('IsoTrackEff','lnN',['sig'],1.02);
	antitagRegion.addSingleSystematic('TrigEff','lnN',['sig'],1.02);
	sidebandRegion1H.addSingleSystematic('lumi','lnN',['sig'],1.027);
	sidebandRegion1H.addSingleSystematic('IsoTrackEff','lnN',['sig'],1.02);
	sidebandRegion1H.addSingleSystematic('TrigEff','lnN',['sig'],1.02);
	sidebandRegion.addSingleSystematic('lumi','lnN',['sig'],1.027);
	sidebandRegion.addSingleSystematic('IsoTrackEff','lnN',['sig'],1.02);
	sidebandRegion.addSingleSystematic('TrigEff','lnN',['sig'],1.02);
	sidebandATRegion.addSingleSystematic('lumi','lnN',['sig'],1.027);
	sidebandATRegion.addSingleSystematic('IsoTrackEff','lnN',['sig'],1.02);
	sidebandATRegion.addSingleSystematic('TrigEff','lnN',['sig'],1.02);
	signalRegion1H.addSingleSystematic('lumi','lnN',['sig'],1.027);
	signalRegion1H.addSingleSystematic('IsoTrackEff','lnN',['sig'],1.02);
	signalRegion1H.addSingleSystematic('TrigEff','lnN',['sig'],1.02);
	
	for i in range(sidebandRegion._nBins):
		#signalRegion.addGausSystematic("kappa"+str(i),"param",1.0,0.001,i)	
		#signalRegion1H.addGausSystematic("kappa"+str(i)+"_1H","param",1.0,0.001,i)	
	
		signalRegion.addGausSystematic("kappa"+str(i),"param",kappa2H[i],kappa2Hsigma[i],i)	
		signalRegion1H.addGausSystematic("kappa"+str(i)+"_1H","param",kappa1H[i],kappa1Hsigma[i],i)	
		#signalRegion.addGausSystematic("kappa"+str(i),"param",kappa2H[i],kappa2Hsigma[i] ,i)	
		#signalRegion1H.addGausSystematic("kappa"+str(i)+"_1H","param",kappa1H[i],kappa1Hsigma[i] ,i)	
		antitagRegion.addABCDSystematic("Beta"+str(i), 'rateParam','Top', 1, 0,4,i)
		sidebandRegion1H.addABCDSystematic("Gamma_1H_"+str(i), 'rateParam','Top', 1, 0,4,i)
		sidebandRegion.addABCDSystematic("Gamma"+str(i), 'rateParam','Top', 1, 0,4,i)
		sidebandATRegion.addABCDSystematic("Delta"+str(i), 'rateParam','Top', 1, 0,4,i)
		antitagRegion.addABCDSystematic("Beta"+str(i), 'rateParam','zvv', 1, 0,4,i)
		sidebandRegion1H.addABCDSystematic("Gamma_1H_"+str(i), 'rateParam','zvv', 1, 0,4,i)
		sidebandRegion.addABCDSystematic("Gamma"+str(i), 'rateParam','zvv', 1, 0,4,i)
		sidebandATRegion.addABCDSystematic("Delta"+str(i), 'rateParam','zvv', 1, 0,4,i)
		antitagRegion.addABCDSystematic("Beta"+str(i), 'rateParam','W', 1, 0,4,i)
		sidebandRegion1H.addABCDSystematic("Gamma_1H_"+str(i), 'rateParam','W', 1, 0,4,i)
		sidebandRegion.addABCDSystematic("Gamma"+str(i), 'rateParam','W', 1, 0,4,i)
		sidebandATRegion.addABCDSystematic("Delta"+str(i), 'rateParam','W', 1, 0,4,i)
		antitagRegion.addABCDSystematic("Beta"+str(i), 'rateParam','qcd', 1, 0,4,i)
		sidebandRegion1H.addABCDSystematic("Gamma_1H_"+str(i), 'rateParam','qcd', 1, 0,4,i)
		sidebandRegion.addABCDSystematic("Gamma"+str(i), 'rateParam','qcd', 1, 0,4,i)
		sidebandATRegion.addABCDSystematic("Delta"+str(i), 'rateParam','qcd', 1, 0,4,i)
		signalRegion.addABCDFormula("Alpha"+str(i), 'rateParam','qcd', 1, 0,4,i,"Beta%d,Gamma%d,Delta%d,kappa%d" %(i,i,i,i));
		signalRegion1H.addABCDFormula("Alpha_1H"+str(i), 'rateParam','qcd', 1, 0,4,i,"Beta%d,Gamma_1H_%d,Delta%d,kappa%d_1H" %(i,i,i,i));
		signalRegion.addABCDFormula("Alpha"+str(i), 'rateParam','zvv', 1, 0,4,i,"Beta%d,Gamma%d,Delta%d,kappa%d" %(i,i,i,i));
		signalRegion1H.addABCDFormula("Alpha_1H"+str(i), 'rateParam','zvv', 1, 0,4,i,"Beta%d,Gamma_1H_%d,Delta%d,kappa%d_1H" %(i,i,i,i));
		signalRegion.addABCDFormula("Alpha"+str(i), 'rateParam','Top', 1, 0,4,i,"Beta%d,Gamma%d,Delta%d,kappa%d" %(i,i,i,i));
		signalRegion1H.addABCDFormula("Alpha_1H"+str(i), 'rateParam','Top', 1, 0,4,i,"Beta%d,Gamma_1H_%d,Delta%d,kappa%d_1H" %(i,i,i,i));
		signalRegion.addABCDFormula("Alpha"+str(i), 'rateParam','W', 1, 0,4,i,"Beta%d,Gamma%d,Delta%d,kappa%d" %(i,i,i,i));
		signalRegion1H.addABCDFormula("Alpha_1H"+str(i), 'rateParam','W', 1, 0,4,i,"Beta%d,Gamma_1H_%d,Delta%d,kappa%d_1H" %(i,i,i,i));
	antitagRegion.writeCards(odir);
	sidebandATRegion.writeCards(odir);
	sidebandRegion1H.writeCards(odir);
	sidebandRegion.writeCards(odir);
	signalRegion1H.writeCards( odir );
	signalRegion.writeCards( odir );
