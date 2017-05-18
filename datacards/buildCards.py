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
parser.add_option("--mGo", dest="mGo", default='1300', help="Mass of Gluino", metavar="mGo")
(options, args) = parser.parse_args()
#add options here


if __name__ == '__main__':

	#open ABCD Signal and Bkg
	odir="SignalT5HH%s" %options.mGo
	if os.path.exists(odir): os.system( "rm -rf %s" % (odir) );
	os.makedirs(odir);
	tagsForSignalRegion=["MET300", "MET500","MET700"]
	inputfile =TFile.Open("datacardInputs.root")
	#Signal Region 2H
	QCDMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_QCD");
	WJetsMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_WJets");
	ZJetsMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_ZJets");
	TTJetsMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_TT");
	TTJetsLeptonsMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_TTExtra");
	TTJetsMCSignalRegion2H.Add(TTJetsLeptonsMCSignalRegion2H);
	SignalT5HH_2H=inputfile.Get("AnalysisMETT5HZ_doubletagSR_T5HH%s" %options.mGo)
	Sigweight=35862.824*0.0460525/(408233.*0.25);
	if options.mGo=="750": Sigweight=35862.824*2.26585/(400307*0.5);
	if options.mGo=="1000": Sigweight=35862.824*0.325388/(396239*0.5);
	if options.mGo=="1100": Sigweight=35862.824*0.163491 /(413868*0.5);
	if options.mGo=="1200": Sigweight=35862.824*0.0856418/(400482*0.5);
	if options.mGo=="1300": Sigweight=35862.824*0.0460525/(408233*0.5);
	if options.mGo=="1400": Sigweight=35862.824*0.0252977/(400887*0.5);
	if options.mGo=="1500": Sigweight=35862.824*0.0141903/(394281*0.5);
	if options.mGo=="1600": Sigweight=35862.824*0.00810078/(397668*0.5);
	if options.mGo=="1700": Sigweight=35862.824*0.00470323 /(414063*0.5);
	if options.mGo=="1800": Sigweight=35862.824*0.00276133/(389625*0.5);
	if options.mGo=="1900": Sigweight=35862.824*0.00163547/(404812*0.5);
	if options.mGo=="2100": Sigweight=35862.824*0.000591918/(391445*0.5);
	SignalT5HH_2H.Scale(Sigweight)
	print SignalT5HH_2H.GetBinContent(1);
	#Signal Region 1H
	QCDMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_QCD");
	WJetsMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_WJets");
	ZJetsMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_ZJets");
	TTJetsMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_TT");
	TTJetsLeptonsMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_TTExtra");
	TTJetsMCSignalRegion1H.Add(TTJetsLeptonsMCSignalRegion1H);
	SignalT5HH_1H=inputfile.Get("AnalysisMETT5HZ_tagSR_T5HH%s" %options.mGo)
	SignalT5HH_1H.Scale(Sigweight)		
	#Sideband Region 
	QCDMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_QCD");
	WJetsMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_WJets");
	ZJetsMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_ZJets");
	TTJetsMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_TT");
	TTJetsLeptonsMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_TTExtra");
	TTJetsMCSideband2H.Add(TTJetsLeptonsMCSideband2H);
				     
	SidebandT5HH_2H=inputfile.Get("AnalysisMETT5HZ_doubletagSB_T5HH%s" %options.mGo)
	SidebandT5HH_2H.Scale(Sigweight)	
	#Signal Region 1H
	QCDMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_QCD");
	WJetsMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_WJets");
	ZJetsMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_ZJets");
	TTJetsMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_TT");
	TTJetsLeptonsMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_TTExtra");
	TTJetsMCSideband1H.Add(TTJetsLeptonsMCSideband1H);
	SidebandT5HH_1H=inputfile.Get("AnalysisMETT5HZ_tagSB_T5HH%s" %options.mGo)
	SidebandT5HH_1H.Scale(Sigweight)	
	#Antitag Region 
	QCDMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_QCD");
	WJetsMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_WJets");
	ZJetsMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_ZJets");
	TTJetsMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_TT");
	TTJetsLeptonsMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_TTExtra");
	TTJetsMCAntitagRegion.Add(TTJetsLeptonsMCAntitagRegion);
	AntitagT5HH=inputfile.Get("AnalysisMETT5HZ_antitagSR_T5HH%s" %options.mGo)
	AntitagT5HH.Scale(Sigweight)	
	#Sideband Antitag Region 
	QCDMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_QCD");
	WJetsMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_WJets");
	ZJetsMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_ZJets");
	TTJetsMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_TT");
	TTJetsLeptonsMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_TTExtra");
	TTJetsMCAntitagRegionSB.Add(TTJetsLeptonsMCAntitagRegionSB);
	AntitagSBT5HH=inputfile.Get("AnalysisMETT5HZ_antitagSR_T5HH%s" %options.mGo)
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
        fout=TFile("DatacardYields.root", "RECREATE")
    	#root_data = TVectorD(4)
        #METBins = [300.,500.,700.,2500.];
	#for i in range(0,4):
	#	root_data[0]=METBins[i]
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
		srobs=SignalT5HH_2H.GetBinContent(i+1)+QCDMCSignalRegion2H.GetBinContent(i+1)+ZJetsMCSignalRegion2H.GetBinContent(i+1)+WJetsMCSignalRegion2H.GetBinContent(i+1)+TTJetsMCSignalRegion2H.GetBinContent(i+1)
		signalRegion_Rates.append(tmpList)
		signalRegion_Obs.append(srobs)
		tmpList = [];
		tmpList.append(SignalT5HH_1H.GetBinContent(i+1));
                tmpList.append(QCDMCSignalRegion1H.GetBinContent(i+1));
                tmpList.append(ZJetsMCSignalRegion1H.GetBinContent(i+1));
                tmpList.append(WJetsMCSignalRegion1H.GetBinContent(i+1));
                tmpList.append(TTJetsMCSignalRegion1H.GetBinContent(i+1));
                srobs=SignalT5HH_1H.GetBinContent(i+1)+QCDMCSignalRegion1H.GetBinContent(i+1)+ZJetsMCSignalRegion1H.GetBinContent(i+1)+WJetsMCSignalRegion1H.GetBinContent(i+1)+TTJetsMCSignalRegion1H.GetBinContent(i+1)
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
	os.system("cp DatacardYields.root ./%s " %odir) 
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
		tmpList = [];
                srobs = 0;
		tmpList.append(AntitagSBT5HH.GetBinContent(i+1));
		tmpList.append(QCDMCAntitagRegionSB.GetBinContent(i+1));		
		tmpList.append(ZJetsMCAntitagRegionSB.GetBinContent(i+1));		
		tmpList.append(WJetsMCAntitagRegionSB.GetBinContent(i+1));		
		tmpList.append(TTJetsMCAntitagRegionSB.GetBinContent(i+1));
		srobs=QCDMCAntitagRegionSB.GetBinContent(i+1)+ZJetsMCAntitagRegionSB.GetBinContent(i+1)+WJetsMCAntitagRegionSB.GetBinContent(i+1)+TTJetsMCAntitagRegionSB.GetBinContent(i+1)
                antitagRegionSB_Rates.append(tmpList)
                antitagRegionSB_Obs.append(srobs)	
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
	sidebandRegion.fillRates(sideband_Rates);
	sidebandRegion.setObservedManually(sideband_Obs)
	
	signalRegion.writeRates();
	signalRegion1H.writeRates();

	antitagRegion.fillRates(antitagRegion_Rates);
	antitagRegion.setObservedManually(antitagRegion_Obs);
	antitagRegion.writeRates();
	sidebandATRegion.fillRates(antitagRegionSB_Rates);
	sidebandATRegion.setObservedManually(antitagRegionSB_Obs);
	sidebandATRegion.writeRates();
	
	#Code up the ABCD FIT
	for i in range(sidebandRegion._nBins):
		antitagRegion.addSingleSystematic("ABCDExtrapQCD"+str(i), 'lnU', ['qcd'], 10000, '', i)
		antitagRegion.addSingleSystematic("ABCDExtrapZ"+str(i), 'lnU', ['zvv'], 10000, '', i)
		antitagRegion.addSingleSystematic("ABCDExtrapW"+str(i), 'lnU', ['W'], 10000, '', i)
		antitagRegion.addSingleSystematic("ABCDExtrapTop"+str(i), 'lnU', ['Top'], 10000, '', i)			

		antitagRegion.addSingleSystematic("ABCDExtrapQCD1H"+str(i), 'lnU', ['qcd'], 10000, '', i)
		antitagRegion.addSingleSystematic("ABCDExtrapZ1H"+str(i), 'lnU', ['zvv'], 10000, '', i)
		antitagRegion.addSingleSystematic("ABCDExtrapW1H"+str(i), 'lnU', ['W'], 10000, '', i)
		antitagRegion.addSingleSystematic("ABCDExtrapTop1H"+str(i), 'lnU', ['Top'], 10000, '', i)			

		signalRegion1H.addSingleSystematic("ABCDExtrapQCD1H"+str(i), 'lnU', ['qcd'], 10000, '', i)
		signalRegion1H.addSingleSystematic("ABCDExtrapZ1H"+str(i), 'lnU', ['zvv'], 10000, '', i)
		signalRegion1H.addSingleSystematic("ABCDExtrapW1H"+str(i), 'lnU', ['W'], 10000, '', i)
		signalRegion1H.addSingleSystematic("ABCDExtrapTop1H"+str(i), 'lnU', ['Top'], 10000, '', i)			


		signalRegion.addSingleSystematic("ABCDExtrapQCD"+str(i), 'lnU', ['qcd'], 10000, '', i)
		signalRegion.addSingleSystematic("ABCDExtrapZ"+str(i), 'lnU', ['zvv'], 10000, '', i)
		signalRegion.addSingleSystematic("ABCDExtrapW"+str(i), 'lnU', ['W'], 10000, '', i)
		signalRegion.addSingleSystematic("ABCDExtrapTop"+str(i), 'lnU', ['Top'], 10000, '', i)			
	
	#Extrapolate from C/D to B
		antitagRegion.addSingleSystematic("SidebandExtrapQCD"+str(i), 'lnU', ['qcd'], 10000, '', i)
		antitagRegion.addSingleSystematic("SidebandExtrapZ"+str(i), 'lnU', ['zvv'], 10000, '', i)
		antitagRegion.addSingleSystematic("SidebandExtrapW"+str(i), 'lnU', ['W'], 10000, '', i)
		antitagRegion.addSingleSystematic("SidebandExtrapTop"+str(i), 'lnU', ['Top'], 10000, '', i)			

		sidebandRegion.addSingleSystematic("SidebandExtrapQCD"+str(i), 'lnU', ['qcd'], 10000, '', i)
		sidebandRegion.addSingleSystematic("SidebandExtrapZ"+str(i), 'lnU', ['zvv'], 10000, '', i)
		sidebandRegion.addSingleSystematic("SidebandExtrapW"+str(i), 'lnU', ['W'], 10000, '', i)
		sidebandRegion.addSingleSystematic("SidebandExtrapTop"+str(i), 'lnU', ['Top'], 10000, '', i)		

		sidebandRegion1H.addSingleSystematic("SidebandExtrapQCD1H"+str(i), 'lnU', ['qcd'], 10000, '', i)
		sidebandRegion1H.addSingleSystematic("SidebandExtrapZ1H"+str(i), 'lnU', ['zvv'], 10000, '', i)
		sidebandRegion1H.addSingleSystematic("SidebandExtrapW1H"+str(i), 'lnU', ['W'], 10000, '', i)
		sidebandRegion1H.addSingleSystematic("SidebandExtrapTop1H"+str(i), 'lnU', ['Top'], 10000, '', i)		

		antitagRegion.addSingleSystematic("SidebandExtrapQCD1H"+str(i), 'lnU', ['qcd'], 10000, '', i)
		antitagRegion.addSingleSystematic("SidebandExtrapZ1H"+str(i), 'lnU', ['zvv'], 10000, '', i)
		antitagRegion.addSingleSystematic("SidebandExtrapW1H"+str(i), 'lnU', ['W'], 10000, '', i)
		antitagRegion.addSingleSystematic("SidebandExtrapTop1H"+str(i), 'lnU', ['Top'], 10000, '', i)			

	#C/D
		sidebandRegion.addSingleSystematic("SidebandRatioQCD"+str(i), 'lnU', ['qcd'], 10000, '', i)
		sidebandRegion.addSingleSystematic("SidebandRatioZ"+str(i), 'lnU', ['zvv'], 10000, '', i)
		sidebandRegion.addSingleSystematic("SidebandRatioW"+str(i), 'lnU', ['W'], 10000, '', i)
		sidebandRegion.addSingleSystematic("SidebandRatioTop"+str(i), 'lnU', ['Top'], 10000, '', i)		
		sidebandATRegion.addSingleSystematic("SidebandRatioQCD"+str(i), 'lnU', ['qcd'], 10000, '', i)
		sidebandATRegion.addSingleSystematic("SidebandRatioZ"+str(i), 'lnU', ['zvv'], 10000, '', i)
		sidebandATRegion.addSingleSystematic("SidebandRatioW"+str(i), 'lnU', ['W'], 10000, '', i)
		sidebandATRegion.addSingleSystematic("SidebandRatioTop"+str(i), 'lnU', ['Top'], 10000, '', i)		

		sidebandATRegion.addSingleSystematic("SidebandRatioQCD1H"+str(i), 'lnU', ['qcd'], 10000, '', i)
		sidebandATRegion.addSingleSystematic("SidebandRatioZ1H"+str(i), 'lnU', ['zvv'], 10000, '', i)
		sidebandATRegion.addSingleSystematic("SidebandRatioW1H"+str(i), 'lnU', ['W'], 10000, '', i)
		sidebandATRegion.addSingleSystematic("SidebandRatioTop1H"+str(i), 'lnU', ['Top'], 10000, '', i)		

		sidebandRegion1H.addSingleSystematic("SidebandRatioQCD1H"+str(i), 'lnU', ['qcd'], 10000, '', i)
		sidebandRegion1H.addSingleSystematic("SidebandRatioZ1H"+str(i), 'lnU', ['zvv'], 10000, '', i)
		sidebandRegion1H.addSingleSystematic("SidebandRatioW1H"+str(i), 'lnU', ['W'], 10000, '', i)
		sidebandRegion1H.addSingleSystematic("SidebandRatioTop1H"+str(i), 'lnU', ['Top'], 10000, '', i)		
	antitagRegion.writeCards(odir);
	sidebandATRegion.writeCards(odir);
	sidebandRegion1H.writeCards(odir);
	sidebandRegion.writeCards(odir);
	signalRegion1H.writeCards( odir );
	signalRegion.writeCards( odir );
	sidebandRegion1H.writeCards( odir );
	sidebandRegion.writeCards( odir );
	
