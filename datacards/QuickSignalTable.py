from ROOT import *


f=TFile("datacardInputsTestTight.root", "READ");
Signal2H1600=f.Get("AnalysisMETT5HH_doubletagSR_T5HH1600")
Signal2H1700=f.Get("AnalysisMETT5HH_doubletagSR_T5HH1700")
Signal2H1800=f.Get("AnalysisMETT5HH_doubletagSR_T5HH1800")
Signal2H1900=f.Get("AnalysisMETT5HH_doubletagSR_T5HH1900")
Signal2H2100=f.Get("AnalysisMETT5HH_doubletagSR_T5HH2100")
BkgTT=f.Get("AnalysisMETBins_doubletagSR_TT")
BkgTTExtra=f.Get("AnalysisMETBins_doubletagSR_TTExtra")
print "Signal 1.6 TeV %g " %Signal2H1600.Integral()
print "Signal 1.7 TeV %g " %Signal2H1700.Integral()
print "Signal 1.8 TeV %g " %Signal2H1800.Integral()
print "Signal 1.9 TeV %g " %Signal2H1900.Integral()
print "Signal 2.1TeV %g " %Signal2H2100.Integral()
print "Bkg TTJets %g " %(BkgTT.Integral()+BkgTTExtra.Integral())
