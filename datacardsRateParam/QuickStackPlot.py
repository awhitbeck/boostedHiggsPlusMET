from ROOT import *


f=TFile("TightSignalT5HH2100/DatacardYields.root","READ")
Signal=f.Get("signal_doubletag")
QCD=f.Get("QCD_doubletag")
TT=f.Get("TTJets_doubletag")
ZJets=f.Get("ZJets_doubletag")
WJets=f.Get("WJets_doubletag")

hs=THStack()
QCD.SetFillColor(kMagenta)
WJets.SetFillColor(kCyan)
ZJets.SetFillColor(kRed)
TT.SetFillColor(kBlue)
hs.Add(QCD)
hs.Add(ZJets)
hs.Add(WJets)
hs.Add(TT)

c2= TCanvas("c2", "", 800,800);

hs.Draw("hist");
hs.SetMaximum(36.0)
Signal.SetLineColor(kBlack)

#Signal.SetLineWidth(2.0)
Signal.Draw("same");

c2.Print("StackTightRegion2H.pdf");
