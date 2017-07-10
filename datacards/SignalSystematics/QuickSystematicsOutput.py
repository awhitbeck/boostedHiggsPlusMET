from ROOT import *
finDC=TFile("datacardInputsNominal.root","READ");
finDCSFup=TFile("datacardInputsSFUp.root","READ");
finDCSmear=TFile("datacardInputsMassResolutionSmearHZ.root","READ");
finDCSmearUp=TFile("datacardInputsMassResolutionSmearHZSFup.root","READ");
#LOOK AT DOUBLE TAG FOR Maximal effect
finNom=TFile("datacardInputsDoubleSFNominal.root","READ")
ModelPoints=[750,1000, 1100, 1200,1300,1400,1500,1600, 1700,1800,1900,2000,2100]
Regions=["tagSR", "antitagSR", "tagSB", "antitagSB", "doubletagSB", "doubletagSR"]
SignalSys=TFile("SignalSysT5HH.root", "RECREATE")
for m in ModelPoints:
	for r in Regions:
		NominalSF=finNom.Get("AnalysisMETT5HZ_%s_T5HH%d" %(r,m))
		SFUp=finDCSFup.Get("AnalysisMETT5HZ_%s_T5HH%d" %(r,m))
		MassResSmear=finDCSmear.Get("AnalysisMETT5HZ_%s_T5HH%d" %(r,m))
		MassResSmearUp=finDCSmearUp.Get("AnalysisMETT5HZ_%s_T5HH%d" %(r,m))
		BBTagSF=NominalSF.Clone("BBTagSF_%s_%d" %(r,m))
		MCStatErr=NominalSF.Clone("MCStatErr_%s_%d" %(r,m))
		MassResErr=NominalSF.Clone("MassResErr_%s_%d" %(r,m))
		for i in range(1):
			if NominalSF.GetBinContent(i+1)<0.000001:Unc=1.0
			else: Unc=SFUp.GetBinContent(i+1)/NominalSF.GetBinContent(i+1)
			#print r,m,Unc
			#BBTagSF.SetBinContent(i+1, Unc)
			#MCStatErr.SetBinContent(i+1, NominalSF.GetBinError(i+1)/NominalSF.GetBinContent(i+1))
			#MassResErr.SetBinContent(i+1,MassResSmear.Integral()/NominalSF.Integral())
        		Sigweight=35862.824*0.0460525/(408233.*0.5);
        		if m==750: Sigweight=35862.824*2.26585/(400307*0.5);
        		if m==1000: Sigweight=35862.824*0.325388/(396239*0.5);
        		if m==1100: Sigweight=35862.824*0.163491 /(413868*0.5);
        		if m==1200: Sigweight=35862.824*0.0856418/(400482*0.5);
        		if m==1300: Sigweight=35862.824*0.0460525/(408233*0.5);
        		if m==1400: Sigweight=35862.824*0.0252977/(400887*0.5);
        		if m==1500: Sigweight=35862.824*0.0141903/(394281*0.5);
        		if m==1600: Sigweight=35862.824*0.00810078/(397668*0.5);
        		if m==1700: Sigweight=35862.824*0.00470323 /(414063*0.5);
        		if m==1800: Sigweight=35862.824*0.00276133/(389625*0.5);
        		if m==1900: Sigweight=35862.824*0.00163547/(404812*0.5);
        		if m==2000: Sigweight=35862.824*0.000981077/(417293*0.5);
        		if m==2100: Sigweight=35862.824*0.000591918/(391445*0.5);
			
			#if  r=="tagSR" or  r=="doubletagSR": print r, m,  Sigweight*NominalSF.Integral(),Sigweight*MassResSmear.Integral(), Sigweight*MassResSmearUp.Integral();
			if   r=="tagSR": print r, m,  Sigweight*NominalSF.Integral(),Sigweight*MassResSmear.Integral(), Sigweight*MassResSmearUp.Integral();
		BBTagSF.Write("BBTagSF_%s_T5HH%d" %(r,m))
		MCStatErr.Write("MCStatErr_%s_T5HH%d" %(r,m))
		MassResErr.Write("MassResErr_%s_T5HH%d" %(r,m))
for m in ModelPoints:
	for r in Regions:
		NominalSF=finDC.Get("AnalysisMETT5HZ_%s_T5HH%d" %(r,m))
		SFUp=finDCSFup.Get("AnalysisMETT5HZ_%s_T5HH%d" %(r,m))
		MassResSmear=finDCSmear.Get("AnalysisMETT5HZ_%s_T5HH%d" %(r,m))
		BBTagSF=NominalSF.Clone("BBTagSF_%s_%d" %(r,m))
		MCStatErr=NominalSF.Clone("MCStatErr_%s_%d" %(r,m))
		MassResErr=NominalSF.Clone("MassResErr_%s_%d" %(r,m))
		for i in range(3):
			if NominalSF.GetBinContent(i+1)<0.000001:Unc=1.0
			else: Unc=SFUp.GetBinContent(i+1)/NominalSF.GetBinContent(i+1)
			#print r,m,Unc
			BBTagSF.SetBinContent(i+1, Unc)
			MCStatErr.SetBinContent(i+1, NominalSF.GetBinError(i+1)/NominalSF.GetBinContent(i+1))
			MassResErr.SetBinContent(i+1,MassResErr.GetBinContent(i+1)/NominalSF.GetBinContent(i+1))
			#print r, m, 1.0+NominalSF.GetBinError(i+1)/NominalSF.GetBinContent(i+1);
		BBTagSF.Write("BBTagSF_%s_T5HZ%d" %(r,m))
		MCStatErr.Write("MCStatErr_%s_T5HZ%d" %(r,m))
		MassResErr.Write("MassResErr_%s_T5HZ%d" %(r,m))
		#print "BBTagSF_%s_%d" %(r,m)
			#Fill the output in a file
finJERUp=TFile("datacards_syst/RA2bin_signal_JERup_T5qqqqZH.root","READ");
finJERDn=TFile("datacards_syst/RA2bin_signal_JERdown_T5qqqqZH.root","READ");
finJECUp=TFile("datacards_syst/RA2bin_signal_JECup_T5qqqqZH.root","READ");
finJECDn=TFile("datacards_syst/RA2bin_signal_JECdown_T5qqqqZH.root","READ");
fin=TFile("datacards_syst/RA2bin_signal_T5qqqqZH.root","READ");
#RA2bin_T5qqqqZH_2100_JERup
#lumi, Isotrack, and TrigWeight are all pretty much flat uncertainties
SignalSys=TFile("SignalSysCommon.root", "RECREATE")
for m in ModelPoints:
	T5HH=fin.Get("RA2bin_T5qqqqZH_%d_nominal" %m)
	T5HH_scaleDn=fin.Get("RA2bin_T5qqqqZH_%d_scaleuncDown" %m)
	T5HH_scaleUp=fin.Get("RA2bin_T5qqqqZH_%d_scaleuncUp" %m)
	T5HH_isrDn=fin.Get("RA2bin_T5qqqqZH_%d_isruncDown" %m)
	T5HH_isrUp=fin.Get("RA2bin_T5qqqqZH_%d_isruncUp" %m)
	T5HH_JECDn=finJECDn.Get("RA2bin_T5qqqqZH_%d_JECdown" %m)
	T5HH_JECUp=finJECUp.Get("RA2bin_T5qqqqZH_%d_JECup"%m)
	T5HH_JERDn=finJERDn.Get("RA2bin_T5qqqqZH_%d_JERdown" %m)
	T5HH_JERUp=finJERUp.Get("RA2bin_T5qqqqZH_%d_JERup"%m)
	JERUp=T5HH.Clone("JERUp_%d" %m)
	JERDn=T5HH.Clone("JERDn_%d" %m)
	JECUp=T5HH.Clone("JECUp_%d" %m)
	JECDn=T5HH.Clone("JECDn_%d" %m)
	ScaleUp=T5HH.Clone("ScaleUp_%d" %m)
	ScaleDn=T5HH.Clone("ScaleDn_%d" %m)
	ISRDn=T5HH.Clone("ISRDn_%d" %m)
	ISRUp=T5HH.Clone("ISRUp_%d" %m)
	for i in range(3):
		ISRUp.SetBinContent(i+1, T5HH_isrUp.GetBinContent(i+1)/T5HH.GetBinContent(i+1))	
		ISRDn.SetBinContent(i+1, T5HH_isrDn.GetBinContent(i+1)/T5HH.GetBinContent(i+1))
		ScaleUp.SetBinContent(i+1, T5HH_scaleUp.GetBinContent(i+1)/T5HH.GetBinContent(i+1))	
		ScaleDn.SetBinContent(i+1, T5HH_scaleDn.GetBinContent(i+1)/T5HH.GetBinContent(i+1))	
		JECUp.SetBinContent(i+1, T5HH_JECUp.GetBinContent(i+1)/T5HH.GetBinContent(i+1))
		JECDn.SetBinContent(i+1, T5HH_JECDn.GetBinContent(i+1)/T5HH.GetBinContent(i+1))
		JERUp.SetBinContent(i+1, T5HH_JERUp.GetBinContent(i+1)/T5HH.GetBinContent(i+1))
		JERDn.SetBinContent(i+1, T5HH_JERDn.GetBinContent(i+1)/T5HH.GetBinContent(i+1))
	ISRUp.Write("ISRUp_%d" %m)
	ISRDn.Write("ISRDn_%d" %m)
	ScaleUp.Write("ScaleUp_%d" %m)
	ScaleDn.Write("ScaleDn_%d" %m)
	JECUp.Write("JECUp_%d" %m)
	JECDn.Write("JECDn_%d" %m)
	JERUp.Write("JERUp_%d" %m)
	JERDn.Write("JERDn_%d" %m)
	
	
		#print "Mass %d ISR up/down %g / %g" %(m,T5HH_isrUp.GetBinContent(i+1)/T5HH.GetBinContent(i+1), T5HH_isrDown.GetBinContent(i+1)/T5HH.GetBinContent(i+1));
		#print "Mass %d Scale Up/down %g / %g " %(m,T5HH_scaleUp.GetBinContent(i+1)/T5HH.GetBinContent(i+1), T5HH_scaleDown.GetBinContent(i+1)/T5HH.GetBinContent(i+1))
		#print "Mass %d JEC Up/down %g / %g " %(m,T5HH_JECUp.GetBinContent(i+1)/T5HH.GetBinContent(i+1), T5HH_JECDn.GetBinContent(i+1)/T5HH.GetBinContent(i+1))
		#print "Mass %d JER Up/down %g / %g " %(m,T5HH_JERUp.GetBinContent(i+1)/T5HH.GetBinContent(i+1), T5HH_JERDn.GetBinContent(i+1)/T5HH.GetBinContent(i+1))
		
#need isr, pdfScale, JEC, JER, 
#for i in range(3):
	
#LOOK AT MASS POINTS OVERALL AND CHECK MAXIMAL Shift

#Contract into a single file:


#WHAT IS MISSING IS THE PU Unc
#MASS RESOLUTION UNC

