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
(options, args) = parser.parse_args()
#add options here


if __name__ == '__main__':

	#open ABCD Signal and Bkg
	odir="FullKappaScale%dUncSignalT5HZ%s" %(int(options.ScaleSyst),options.mGo)
	if os.path.exists(odir): os.system( "rm -rf %s" % (odir) );
	os.makedirs(odir);
	tagsForSignalRegion=["MET300", "MET500","MET700"]
	inputfile =TFile.Open("datacardInputsTest.root")
	#Signal Region 2H
	QCDMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_QCD");
	WJetsMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_WJets");
	ZJetsMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_ZJets");
	TTJetsMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_TT");
	#TTJetsLeptonsMCSignalRegion2H=inputfile.Get("AnalysisMETBins_doubletagSR_TTExtra");
	#TTJetsMCSignalRegion2H.Add(TTJetsLeptonsMCSignalRegion2H);
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
	if options.mGo=="2000": Sigweight=35862.824*0.000981077/(417293*0.5);
	if options.mGo=="2100": Sigweight=35862.824*0.000591918/(391445*0.5);
	SignalT5HH_2H.Scale(Sigweight)
	#Signal Region 1H
	QCDMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_QCD");
	WJetsMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_WJets");
	ZJetsMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_ZJets");
	TTJetsMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_TT");
	#TTJetsLeptonsMCSignalRegion1H=inputfile.Get("AnalysisMETBins_tagSR_TTExtra");
	#TTJetsMCSignalRegion1H.Add(TTJetsLeptonsMCSignalRegion1H);
	SignalT5HH_1H=inputfile.Get("AnalysisMETT5HZ_tagSR_T5HH%s" %options.mGo)
	SignalT5HH_1H.Scale(Sigweight)		
	#Sideband Region 
	QCDMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_QCD");
	WJetsMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_WJets");
	ZJetsMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_ZJets");
	TTJetsMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_TT");
	#TTJetsLeptonsMCSideband2H=inputfile.Get("AnalysisMETBins_doubletagSB_TTExtra");
	#TTJetsMCSideband2H.Add(TTJetsLeptonsMCSideband2H);
				     
	SidebandT5HH_2H=inputfile.Get("AnalysisMETT5HZ_doubletagSB_T5HH%s" %options.mGo)
	SidebandT5HH_2H.Scale(Sigweight)	
	#Signal Region 1H
	QCDMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_QCD");
	WJetsMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_WJets");
	ZJetsMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_ZJets");
	TTJetsMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_TT");
	#TTJetsLeptonsMCSideband1H=inputfile.Get("AnalysisMETBins_tagSB_TTExtra");
	#TTJetsMCSideband1H.Add(TTJetsLeptonsMCSideband1H);
	SidebandT5HH_1H=inputfile.Get("AnalysisMETT5HZ_tagSB_T5HH%s" %options.mGo)
	SidebandT5HH_1H.Scale(Sigweight)	
	#Antitag Region 
	QCDMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_QCD");
	WJetsMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_WJets");
	ZJetsMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_ZJets");
	TTJetsMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_TT");
	#TTJetsLeptonsMCAntitagRegion=inputfile.Get("AnalysisMETBins_antitagSR_TTExtra");
	#TTJetsMCAntitagRegion.Add(TTJetsLeptonsMCAntitagRegion);
	AntitagT5HH=inputfile.Get("AnalysisMETT5HZ_antitagSR_T5HH%s" %options.mGo)
	AntitagT5HH.Scale(Sigweight)
	#Sideband Antitag Region 
	QCDMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_QCD");
	WJetsMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_WJets");
	ZJetsMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_ZJets");
	TTJetsMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_TT");
	#TTJetsLeptonsMCAntitagRegionSB=inputfile.Get("AnalysisMETBins_antitagSB_TTExtra");
	#TTJetsMCAntitagRegionSB.Add(TTJetsLeptonsMCAntitagRegionSB);
	AntitagSBT5HH=inputfile.Get("AnalysisMETT5HZ_antitagSB_T5HH%s" %options.mGo)
	AntitagSBT5HH.Scale(Sigweight)
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
        fout=TFile(odir+"/DatacardYields.root", "RECREATE")
    	#root_data = TVectorD(4)
        #METBins = [300.,500.,700.,2500.];
	#for i in range(0,4):
	#	root_data[0]=METBins[i]
	SLSF1H=[0.49, 0.52, 0.47, 0.42]
	LDPSF1H=[0.77, 0.8, 0.86, 0.66]
	SFGamma1H=[0.8,0.97, 0.55, 0.64]

	SLSF2H=[0.48, 0.63, 0.47, 0.42]
	LDPSF2H=[0.95, 1.1, 0.86, 0.66]
	SFGamma2H=[0.23,0.2, 0.55, 0.64]
	'''
	QCDMCSignalRegion1H.Scale(LDPSF1H[0])
	ZJetsMCSignalRegion1H.Scale(SFGamma1H[0])
	WJetsMCSignalRegion1H.Scale(SLSF1H[0])
	TTJetsMCSignalRegion1H.Scale(SLSF1H[0])
	QCDMCSignalRegion2H.Scale(LDPSF2H[0])
	ZJetsMCSignalRegion2H.Scale(SFGamma2H[0])
	WJetsMCSignalRegion2H.Scale(SLSF2H[0])
	TTJetsMCSignalRegion2H.Scale(SLSF2H[0])


	QCDMCAntitagRegion.Scale(LDPSF2H[2])
	ZJetsMCAntitagRegion.Scale(SFGamma2H[2])
	WJetsMCAntitagRegion.Scale(SLSF2H[2])
	TTJetsMCAntitagRegion.Scale(SLSF2H[2])
	QCDMCAntitagRegionSB.Scale(LDPSF2H[3])
	ZJetsMCAntitagRegionSB.Scale(SFGamma2H[3])
	WJetsMCAntitagRegionSB.Scale(SLSF2H[3])
	TTJetsMCAntitagRegionSB.Scale(SLSF2H[3])
	QCDMCSideband1H.Scale(LDPSF1H[1])
	ZJetsMCSideband1H.Scale(SFGamma1H[1])
	WJetsMCSideband1H.Scale(SLSF1H[1])
	TTJetsMCSideband1H.Scale(SLSF1H[1])
	QCDMCSideband2H.Scale(LDPSF2H[1])
	ZJetsMCSideband2H.Scale(SFGamma2H[1])
	WJetsMCSideband2H.Scale(SLSF2H[1])
	TTJetsMCSideband2H.Scale(SLSF2H[1])
	'''	
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
		'''
		if QCDMCAntitagRegionSB.GetBinContent(i+1)>0.0 :tmpList.append(QCDMCAntitagRegion.GetBinContent(i+1)*QCDMCSideband2H.GetBinContent(i+1)/QCDMCAntitagRegionSB.GetBinContent(i+1))
		else: tmpList.append(0.01)
		tmpList.append(ZJetsMCAntitagRegion.GetBinContent(i+1)*ZJetsMCSideband2H.GetBinContent(i+1)/ZJetsMCAntitagRegionSB.GetBinContent(i+1))
		tmpList.append(WJetsMCAntitagRegion.GetBinContent(i+1)*WJetsMCSideband2H.GetBinContent(i+1)/WJetsMCAntitagRegionSB.GetBinContent(i+1))
		tmpList.append(TTJetsMCAntitagRegion.GetBinContent(i+1)*TTJetsMCSideband2H.GetBinContent(i+1)/TTJetsMCAntitagRegionSB.GetBinContent(i+1))
		srobs=float(options.mu)*SignalT5HH_2H.GetBinContent(i+1)+QCDMCSignalRegion2H.GetBinContent(i+1)+ZJetsMCSignalRegion2H.GetBinContent(i+1)+WJetsMCSignalRegion2H.GetBinContent(i+1)+TTJetsMCSignalRegion2H.GetBinContent(i+1)
		'''
		srobs=QCDMCSignalRegion2H.GetBinContent(i+1)+ZJetsMCSignalRegion2H.GetBinContent(i+1)+WJetsMCSignalRegion2H.GetBinContent(i+1)+TTJetsMCSignalRegion2H.GetBinContent(i+1)
		signalRegion_Rates.append(tmpList)
		signalRegion_Obs.append(srobs)
		tmpList = [];
		tmpList.append(SignalT5HH_1H.GetBinContent(i+1));
                tmpList.append(QCDMCSignalRegion1H.GetBinContent(i+1));
                tmpList.append(ZJetsMCSignalRegion1H.GetBinContent(i+1));
                tmpList.append(WJetsMCSignalRegion1H.GetBinContent(i+1));
                tmpList.append(TTJetsMCSignalRegion1H.GetBinContent(i+1));
		'''
		if QCDMCAntitagRegionSB.GetBinContent(i+1)>0.0 :tmpList.append(QCDMCAntitagRegion.GetBinContent(i+1)*QCDMCSideband1H.GetBinContent(i+1)/QCDMCAntitagRegionSB.GetBinContent(i+1))
		else: tmpList.append(0.01)
		tmpList.append(ZJetsMCAntitagRegion.GetBinContent(i+1)*ZJetsMCSideband1H.GetBinContent(i+1)/ZJetsMCAntitagRegionSB.GetBinContent(i+1))
		tmpList.append(WJetsMCAntitagRegion.GetBinContent(i+1)*WJetsMCSideband1H.GetBinContent(i+1)/WJetsMCAntitagRegionSB.GetBinContent(i+1))
		tmpList.append(TTJetsMCAntitagRegion.GetBinContent(i+1)*TTJetsMCSideband1H.GetBinContent(i+1)/TTJetsMCAntitagRegionSB.GetBinContent(i+1))
		
                srobs=float(options.mu)*SignalT5HH_1H.GetBinContent(i+1)+QCDMCSignalRegion1H.GetBinContent(i+1)+ZJetsMCSignalRegion1H.GetBinContent(i+1)+WJetsMCSignalRegion1H.GetBinContent(i+1)+TTJetsMCSignalRegion1H.GetBinContent(i+1)
		'''
                srobs=QCDMCSignalRegion1H.GetBinContent(i+1)+ZJetsMCSignalRegion1H.GetBinContent(i+1)+WJetsMCSignalRegion1H.GetBinContent(i+1)+TTJetsMCSignalRegion1H.GetBinContent(i+1)
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
		#srobs=QCDMCAntitagRegion.GetBinContent(i+1)+ZJetsMCAntitagRegion.GetBinContent(i+1)+WJetsMCAntitagRegion.GetBinContent(i+1)+TTJetsMCAntitagRegion.GetBinContent(i+1)
		srobs=float(options.mu)*AntitagT5HH.GetBinContent(i+1)+QCDMCAntitagRegion.GetBinContent(i+1)+ZJetsMCAntitagRegion.GetBinContent(i+1)+WJetsMCAntitagRegion.GetBinContent(i+1)+TTJetsMCAntitagRegion.GetBinContent(i+1)
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
		srobs=float(options.mu)*AntitagSBT5HH.GetBinContent(i+1)+QCDMCAntitagRegionSB.GetBinContent(i+1)+ZJetsMCAntitagRegionSB.GetBinContent(i+1)+WJetsMCAntitagRegionSB.GetBinContent(i+1)+TTJetsMCAntitagRegionSB.GetBinContent(i+1)
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
		#srobs=QCDMCSideband2H.GetBinContent(i+1)+ZJetsMCSideband2H.GetBinContent(i+1)+WJetsMCSideband2H.GetBinContent(i+1)+TTJetsMCSideband2H.GetBinContent(i+1)
		srobs=float(options.mu)*SidebandT5HH_2H.GetBinContent(i+1)+QCDMCSideband2H.GetBinContent(i+1)+ZJetsMCSideband2H.GetBinContent(i+1)+WJetsMCSideband2H.GetBinContent(i+1)+TTJetsMCSideband2H.GetBinContent(i+1)
		sideband_Rates.append(tmpList)
		sideband_Obs.append(srobs)
		tmpList = [];
		tmpList.append(SidebandT5HH_1H.GetBinContent(i+1));
		#tmpList.append(0.0);
                tmpList.append(QCDMCSideband1H.GetBinContent(i+1));
                tmpList.append(ZJetsMCSideband1H.GetBinContent(i+1));
                tmpList.append(WJetsMCSideband1H.GetBinContent(i+1));
                tmpList.append(TTJetsMCSideband1H.GetBinContent(i+1));
                srobs=float(options.mu)*SidebandT5HH_1H.GetBinContent(i+1)+QCDMCSideband1H.GetBinContent(i+1)+ZJetsMCSideband1H.GetBinContent(i+1)+WJetsMCSideband1H.GetBinContent(i+1)+TTJetsMCSideband1H.GetBinContent(i+1)
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
	kappa2H=[0.98,0.96,0.85]	
	#kappa2H=[ 0.82, 0.61,0.56]	
	#kappa2Hsigma=[0.210804,0.31574, 1.13147]
	kappa1H=[ 0.66, 0.48, 0.43]
        #kappa1Hsigma=[0.0657248,0.114894,0.161858]
	#kappa2H=[0.829983,  0.737553, 1.9501]
	kappa2Hsigma=[0.19,0.11,0.21 ]
	#kappa1H=[0.870, 0.8772,  0.781]
	kappa1Hsigma=[0.13, 0.13, 0.13]
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
