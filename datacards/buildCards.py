from ROOT import *
import os
import math
from searchRegion import *
from singleBin import *
from cardUtilities import *
import random
from optparse import OptionParser


parser = OptionParser()
parser.add_option("--mGo", dest="mGo", default='1300', help="Mass of Gluino", metavar="mGo")
(options, args) = parser.parse_args()
#add options here


if __name__ == '__main__':

	#open ABCD Signal and Bkg
	odir="TestCards/"
	if os.path.exists(odir): os.system( "rm -rf %s" % (odir) );
	os.makedirs(odir);
	tagsForSignalRegion=["MET300", "MET500","MET700"]
	inputfile =TFile.Open("datacardInputsTest.root")
	#Signal Region 2H
	QCDMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_QCD");
	WJetsMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_WJets");
	ZJetsMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_ZJets");
	TTJetsMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_TT");
	TTJetsLeptonsMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_TTExtra");
	TTJetsMCSignalRegion2H.Add(TTJetsLeptonsMCSignalRegion2H);
	SignalT5HH_2H=inputfile.Get("AnalysisMETT5HH_doubletagSR_T5HH%s" %options.mGo)
	#Signal Region 1H
	QCDMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_QCD");
	WJetsMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_WJets");
	ZJetsMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_ZJets");
	TTJetsMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_TT");
	TTJetsLeptonsMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_TTExtra");
	TTJetsMCSignalRegion1H.Add(TTJetsLeptonsMCSignalRegion1H);
	SignalT5HH_1H=inputfile.Get("AnalysisMETT5HH_tagSR_T5HH%s" %options.mGo)
	
	#Sideband Region 
	QCDMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_QCD");
	WJetsMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_WJets");
	ZJetsMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_ZJets");
	TTJetsMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_TT");
	TTJetsLeptonsMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_TTExtra");
	TTJetsMCSideband2H.Add(TTJetsLeptonsMCSideband2H);
				     
	SidebandT5HH_2H=inputfile.Get("AnalysisMETT5HH_doubletagSB_T5HH%s" %options.mGo)
	#Signal Region 1H
	QCDMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_QCD");
	WJetsMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_WJets");
	ZJetsMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_ZJets");
	TTJetsMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_TT");
	TTJetsLeptonsMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_TTExtra");
	TTJetsMCSideband1H.Add(TTJetsLeptonsMCSideband1H);
	SidebandT5HH_1H=inputfile.Get("AnalysisMETT5HH_tagSB_T5HH%s" %options.mGo)
	
	#Antitag Region 
	QCDMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_QCD");
	WJetsMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_WJets");
	ZJetsMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_ZJets");
	TTJetsMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_TT");
	TTJetsLeptonsMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_TTExtra");
	TTJetsMCAntitagRegion.Add(TTJetsLeptonsMCAntitagRegion);
	AntitagT5HH=inputfile.Get("AnalysisMETT5HH_antitagSR_T5HH%s" %options.mGo)

	#Sideband Antitag Region 
	QCDMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_QCD");
	WJetsMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_WJets");
	ZJetsMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_ZJets");
	TTJetsMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_TT");
	TTJetsLeptonsMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_TTExtra");
	TTJetsMCAntitagRegionSB.Add(TTJetsLeptonsMCAntitagRegionSB);
	AntitagSBT5HH=inputfile.Get("AnalysisMETT5HH_antitagSR_T5HH%s" %options.mGo)
	contributionsPerBin = [];
	for i in range(len(tagsForSignalRegion)): 
		tmpcontributions = [];
		tmpcontributions.append('sig');
		tmpcontributions.append('qcd')
		tmpcontributions.append('zvv')
		tmpcontributions.append('W')
		tmpcontributions.append('Top')
		contributionsPerBin.append(tmpcontributions)
	signalRegion = searchRegion('signal', contributionsPerBin, tagsForSignalRegion)	
	signalRegion1H = searchRegion('signal1H', contributionsPerBin, tagsForSignalRegion)	
	antitagRegion = searchRegion('antitagRegion', contributionsPerBin, tagsForSignalRegion)	
	sidebandRegion = searchRegion('sidebandRegion', contributionsPerBin, tagsForSignalRegion)	
	sidebandRegion1H = searchRegion('sidebandRegion1H', contributionsPerBin, tagsForSignalRegion)	
	
	signalRegion1H_Rates = [];
	signalRegion1H_Obs = [];

	signalRegion_Rates = [];
	signalRegion_Obs = [];
	antitagRegion_Rates = [];
	antitagRegion_Obs = [];
	sideband_Rates=[]
	sideband_Obs=[]
	sideband1H_Rates=[]
	sideband1H_Obs=[]
	for i in range(signalRegion._nBins):
		tmpList = [];
		srobs = 0;
		tmpList.append(SignalT5HH_2H.GetBinContent(i+1));	
		tmpList.append(QCDMCSignalRegion2H.GetBinContent(i+1));	
		tmpList.append(ZJetsMCSignalRegion2H.GetBinContent(i+1));	
		tmpList.append(WJetsMCSignalRegion2H.GetBinContent(i+1));	
		tmpList.append(TTJetsMCSignalRegion2H.GetBinContent(i+1));	
		srobs=QCDMCSignalRegion2H.GetBinContent(i+1)+ZJetsMCSignalRegion2H.GetBinContent(i+1)+WJetsMCSignalRegion2H.GetBinContent(i+1)+TTJetsMCSignalRegion2H.GetBinContent(i+1)
		signalRegion_Rates.append(tmpList)
		signalRegion_Obs.append(srobs)
		tmpList = [];
		tmpList.append(SignalT5HH_1H.GetBinContent(i+1));
                tmpList.append(QCDMCSignalRegion1H.GetBinContent(i+1));
                tmpList.append(ZJetsMCSignalRegion1H.GetBinContent(i+1));
                tmpList.append(WJetsMCSignalRegion1H.GetBinContent(i+1));
                tmpList.append(TTJetsMCSignalRegion1H.GetBinContent(i+1));
                srobs=QCDMCSignalRegion1H.GetBinContent(i+1)+ZJetsMCSignalRegion1H.GetBinContent(i+1)+WJetsMCSignalRegion1H.GetBinContent(i+1)+TTJetsMCSignalRegion1H.GetBinContent(i+1)
                signalRegion1H_Rates.append(tmpList)
                signalRegion1H_Obs.append(srobs)
        for i in range(antitagRegion._nBins):
		tmpList = [];
                srobs = 0;
		tmpList.append(AntitagT5HH.GetBinContent(i+1));
		tmpList.append(QCDMCAntitagRegion.GetBinContent(i+1));		
		tmpList.append(ZJetsMCAntitagRegion.GetBinContent(i+1));		
		tmpList.append(WJetsMCAntitagRegion.GetBinContent(i+1));		
		tmpList.append(TTJetsMCAntitagRegion.GetBinContent(i+1));
		srobs=QCDMCAntitagRegion.GetBinContent(i+1)+ZJetsMCAntitagRegion.GetBinContent(i+1)+WJetsMCAntitagRegion.GetBinContent(i+1)+TTJetsMCAntitagRegion.GetBinContent(i+1)
                antitagRegion_Rates.append(tmpList)
                antitagRegion_Obs.append(srobs)	
	for i in range(sidebandRegion._nBins):
		tmpList = [];
		srobs = 0;
		tmpList.append(SidebandT5HH_2H.GetBinContent(i+1));	
		tmpList.append(QCDMCSideband2H.GetBinContent(i+1));	
		tmpList.append(ZJetsMCSideband2H.GetBinContent(i+1));	
		tmpList.append(WJetsMCSideband2H.GetBinContent(i+1));	
		tmpList.append(TTJetsMCSideband2H.GetBinContent(i+1));	
		srobs=QCDMCSideband2H.GetBinContent(i+1)+ZJetsMCSideband2H.GetBinContent(i+1)+WJetsMCSideband2H.GetBinContent(i+1)+TTJetsMCSideband2H.GetBinContent(i+1)
		sideband_Rates.append(tmpList)
		sideband_Obs.append(srobs)
		tmpList = [];
		tmpList.append(SidebandT5HH_1H.GetBinContent(i+1));
                tmpList.append(QCDMCSideband1H.GetBinContent(i+1));
                tmpList.append(ZJetsMCSideband1H.GetBinContent(i+1));
                tmpList.append(WJetsMCSideband1H.GetBinContent(i+1));
                tmpList.append(TTJetsMCSideband1H.GetBinContent(i+1));
                srobs=QCDMCSideband1H.GetBinContent(i+1)+ZJetsMCSideband1H.GetBinContent(i+1)+WJetsMCSideband1H.GetBinContent(i+1)+TTJetsMCSideband1H.GetBinContent(i+1)
                sideband1H_Rates.append(tmpList)
                sideband1H_Obs.append(srobs)
	signalRegion.fillRates(signalRegion_Rates );
	signalRegion.setObservedManually(signalRegion_Obs)
	signalRegion1H.fillRates(signalRegion1H_Rates );
	signalRegion1H.setObservedManually(signalRegion1H_Obs)
	sidebandRegion1H.fillRates(sideband1H_Rates)
	sidebandRegion1H.setObservedManually(sideband1H_Obs)
	sidebandRegion1H.writeCards( odir );
	sidebandRegion.fillRates(sideband_Rates);
	sidebandRegion.setObservedManually(sideband_Obs)
	sidebandRegion.writeCards( odir );
	
	signalRegion.writeRates();
	signalRegion.writeCards( odir );
	signalRegion1H.writeRates();
	signalRegion1H.writeCards( odir );

	sidebandRegion1H.writeRates();
	sidebandRegion.writeRates();
	sidebandRegion1H.writeCards(odir);
	sidebandRegion.writeCards(odir);
	
	antitagRegion.fillRates(antitagRegion_Rates);
	antitagRegion.setObservedManually(antitagRegion_Obs);
	antitagRegion.writeRates();
	antitagRegion.writeCards(odir);
	
