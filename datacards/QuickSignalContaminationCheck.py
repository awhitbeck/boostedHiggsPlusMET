from ROOT import *


fileIn=TFile("datacardInputsDefault.root","READ")
regions=["tagSR","antitagSR", "tagSB","antitagSB"]
MassPoints=[750, 1200, 1600, 2000]
SigWeight=[35862.824*2.26585/(400307*0.5), 35862.824*0.0856418/(400482*0.5), 35862.824*0.00810078/(397668*0.5), 35862.824*0.000981077/(417293*0.5)]

for r in regions:
			 
	QCDMC=fileIn.Get("AnalysisMETBins_%s_QCD" %r);
	WJetsMC=fileIn.Get("AnalysisMETBins_%s_WJets" %r)
	ZJetsMC=fileIn.Get("AnalysisMETBins_%s_ZJets" %r);
	TTJetsMC=fileIn.Get("AnalysisMETBins_%s_TT" %r);
	TotalBkg=QCDMC.Clone("TotalBkg")
	TotalBkg.Add(WJetsMC);
	TotalBkg.Add(ZJetsMC);
	TotalBkg.Add(TTJetsMC);
	massPoint=0;
	for m in MassPoints:
		SignalMC=fileIn.Get("AnalysisMETT5HZ_%s_T5HH%d" %(r,m));
		for i in range(3):print "MET Bin %d Control Region %s Total Bkg  %g Signal Contam METT5HZ_%d %g " %(i+1, r, TotalBkg.GetBinContent(i+1), m,SignalMC.GetBinContent(i+1)*SigWeight[massPoint])
		massPoint=massPoint+1
