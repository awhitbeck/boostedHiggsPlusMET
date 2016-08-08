from ROOT import *

gROOT.ProcessLine("struct treeFormat {\
   Float_t         MET;\
   Float_t         HT;\
   Float_t*        FatJeMass;\
   Float_t         J1pt;\
   Float_t         J2pt;\
   Float_t         J1tau21;\
   Float_t         J2tau21;\
   Float_t         J1bbtag;\
   Float_t         J2bbtag;\
   Float_t         norm;\
   Float_t         xsec;\
   Float_t         Trigger_PFMET100;\
   Float_t         Trigger_PFHT800;\
   Float_t         nMuons;\
   Float_t         nElectrons;\
}")

histoFillColor = { "HTMHT":1 , 
                   "TT":kCyan,
                   "QCD":kGray,
                   "WJetsToLNu":kBlue,
                   "ZJetsToNuNu":kRed,
                   #"DiBoson":kOrange 
                   }

lumi = 9200.

def SignalRegion( treeVars = treeFormat() , sample="" ):
    ### trigger requirement
    if sample == "HTMHT" and treeVars.Trigger_PFHT800 != 1 : return False
    
    if treeVars.nElectrons==0 and treeVars.nMuons==0 and treeVars.HT>1000. and treeVars.MHT>200. and treeVars.J1pt>200. and treeVars.J2pt>200. : return True
    else : return False

def DoubleHiggsTag( treeVars = treeFormat() , sample="" ):
    if ( ( treeVars.J1Mass > 90 and treeVars.J1Mass < 140 and treeVars.J1bbtag>0.4 ) and ( treeVars.J2Mass > 90 and treeVars.J2Mass < 140 and treeVars.J2bbtag>0.4 ) ) : return True
    else : return False

def SingleHiggsTag( treeVars = treeFormat() , sample="" ):
    if ( ( treeVars.J1Mass > 90 and treeVars.J1Mass < 140 and treeVars.J1bbtag>0.4 ) or ( treeVars.J2Mass > 90 and treeVars.J2Mass < 140 and treeVars.J2bbtag>0.4 ) ) : return True
    else : return False

def SingleMuonCR( treeVars = treeFormat() , sample="" ):
    ### trigger requirement                                                                                                                                                                                  
    if sample == "HTMHT" and treeVars.Trigger_PFHT800 != 1 : return False
    
    if treeVars.nElectrons==0 and treeVars.nMuons==1 : return True
    else : return False

def SingleElectronCR( treeVars = treeFormat() , sample="" ):
    ### trigger requirement                                                                                                                                                                                  
    if sample == "HTMHT" and treeVars.Trigger_PFHT800 != 1 : return False
    
    if treeVars.nElectrons==1 and treeVars.nMuons==0 : return True
    else : return False


class METSignalRegion:

    def __init__(self,samples):
        self.histos={}
        for sample in samples : 
            self.histos[sample] = TH1F("MET_"+sample,"MET_"+sample,25,200,600)
            if sample != "HTMHT" :
                self.histos[sample].SetFillColor(histoFillColor[sample])
                self.histos[sample].SetLineColor(1)
                self.histos[sample].SetLineStyle(1)
                self.histos[sample].SetLineWidth(2)
            else :   
                self.histos[sample].SetMarkerStyle(8)
            
    def fill( self , treeVars = treeFormat() , sample=""):

        if SignalRegion( treeVars , sample ):
        #if SingleElectronCR( treeVars , sample ):
        #if SingleMuonCR( treeVars , sample ):
            if sample == "HTMHT" : 
                self.histos[sample].Fill(treeVars.MET)
            else : 
                self.histos[sample].Fill(treeVars.MET,treeVars.xsec*lumi/treeVars.norm)

class LeadingJetMassSignalRegion:

    def __init__(self,samples):
        self.histos={}
        for sample in samples : 
            self.histos[sample] = TH1F("LeadingJetsmass_"+sample,"LeadingJetMass_"+sample,25,50,150)
            if sample != "HTMHT" :
                self.histos[sample].SetFillColor(histoFillColor[sample])
                self.histos[sample].SetLineColor(1)
                self.histos[sample].SetLineStyle(1)
                self.histos[sample].SetLineWidth(2)
            else :   
                self.histos[sample].SetMarkerStyle(8)
            
    def fill( self , treeVars = treeFormat() , sample=""):

        if SignalRegion( treeVars , sample ):
        #if SingleElectronCR( treeVars , sample ):
        #if SingleMuonCR( treeVars , sample ):
            if sample == "HTMHT" : 
                self.histos[sample].Fill(treeVars.J1Mass)
            else : 
                self.histos[sample].Fill(treeVars.J1Mass,treeVars.xsec*lumi/treeVars.norm)

class LeadingBBtagSignalRegion:

    def __init__(self,samples):
        self.histos={}
        for sample in samples : 
            self.histos[sample] = TH1F("LeadingBBtag_"+sample,"LeadingBBtag_"+sample,20,-1,1)
            if sample != "HTMHT" :
                self.histos[sample].SetFillColor(histoFillColor[sample])
                self.histos[sample].SetLineColor(1)
                self.histos[sample].SetLineStyle(1)
                self.histos[sample].SetLineWidth(2)
            else :   
                self.histos[sample].SetMarkerStyle(8)
            
    def fill( self , treeVars = treeFormat() , sample=""):

        if SignalRegion( treeVars , sample ):
        #if SingleElectronCR( treeVars , sample ):
        #if SingleMuonCR( treeVars , sample ):
            if sample == "HTMHT" : 
                self.histos[sample].Fill(treeVars.J1bbtag)
            else : 
                self.histos[sample].Fill(treeVars.J1bbtag,treeVars.xsec*lumi/treeVars.norm)

class SubLeadingBBtagSignalRegion:

    def __init__(self,samples):
        self.histos={}
        for sample in samples : 
            self.histos[sample] = TH1F("SubLeadingBBtag_"+sample,"SubLeadingBBtag_"+sample,20,-1,1)
            if sample != "HTMHT" :
                self.histos[sample].SetFillColor(histoFillColor[sample])
                self.histos[sample].SetLineColor(1)
                self.histos[sample].SetLineStyle(1)
                self.histos[sample].SetLineWidth(2)
            else :   
                self.histos[sample].SetMarkerStyle(8)
            
    def fill( self , treeVars = treeFormat() , sample=""):

        if SignalRegion( treeVars , sample ):
        #if SingleElectronCR( treeVars , sample ):
        #if SingleMuonCR( treeVars , sample ):
            if sample == "HTMHT" : 
                self.histos[sample].Fill(treeVars.J2bbtag)
            else : 
                self.histos[sample].Fill(treeVars.J2bbtag,treeVars.xsec*lumi/treeVars.norm)

class SubLeadingJetMassSignalRegion:

    def __init__(self,samples):
        self.histos={}
        for sample in samples : 
            self.histos[sample] = TH1F("SubLeadingJetsmass_"+sample,"SubLeadingJetMass_"+sample,25,50,150)
            if sample != "HTMHT" :
                self.histos[sample].SetFillColor(histoFillColor[sample])
                self.histos[sample].SetLineColor(1)
                self.histos[sample].SetLineStyle(1)
                self.histos[sample].SetLineWidth(2)
            else :   
                self.histos[sample].SetMarkerStyle(8)
            
    def fill( self , treeVars = treeFormat() , sample=""):

        if SignalRegion( treeVars , sample ):
        #if SingleElectronCR( treeVars , sample ):
        #if SingleMuonCR( treeVars , sample ):
            if sample == "HTMHT" : 
                self.histos[sample].Fill(treeVars.J2Mass)
            else : 
                self.histos[sample].Fill(treeVars.J2Mass,treeVars.xsec*lumi/treeVars.norm)

class HTSignalRegion:
    
    def __init__(self,samples):
        self.histos={}
        for sample in samples : 
            self.histos[sample] = TH1F("HT_"+sample,"HT_"+sample,25,1000,2000)
            if sample != "HTMHT" :
                self.histos[sample].SetFillColor(histoFillColor[sample])
                self.histos[sample].SetLineColor(1)
                self.histos[sample].SetLineStyle(1)
                self.histos[sample].SetLineWidth(2)
            else :   
                self.histos[sample].SetMarkerStyle(8)
            
    def fill( self , treeVars = treeFormat() , sample="" ):

        if SignalRegion( treeVars , sample ):
        #if SingleElectronCR( treeVars , sample ):
        #if SingleMuonCR( treeVars , sample ):
            if sample == "HTMHT" : 
                self.histos[sample].Fill(treeVars.HT)
            else : 
                self.histos[sample].Fill(treeVars.HT,treeVars.xsec*lumi/treeVars.norm)

def createStack( tag="test" , histoList={} , samples=[] , scale = 1.0) :  

    stack = THStack("stack_"+tag,"stack_"+tag)
    for sample in histoList : 
        if sample == "HTMHT" : continue
        histoList[sample].Scale(scale)
        stack.Add(histoList[sample])

    return stack

def createSum( tag="test" , histoList={} ):

    first = True
    for sample in samples : 
        if sample == "HTMHT" : continue
        if first : 
            histoSum = TH1F(histoList[sample])
            histoSum.SetNameTitle("sum_"+tag,"sum_"+tag)
            first = False 
        else :
            histoSum.Add(histoList[sample])
        
    return histoSum

trees = {}
samples=["ZJetsToNuNu","WJetsToLNu","TT","QCD","HTMHT"]
histo = {}


METhistos = METSignalRegion(samples)
HThistos = HTSignalRegion(samples)
J1Masshistos = LeadingJetMassSignalRegion(samples)
J2Masshistos = SubLeadingJetMassSignalRegion(samples)
J1bbtaghistos = LeadingBBtagSignalRegion(samples)
J2bbtaghistos = SubLeadingBBtagSignalRegion(samples)

for sample in samples :

    print sample
    
    trees[sample] = TChain("myTree")
    trees[sample].Add("miniTreeSkim_{0}.root".format(sample))
    treeVars = treeFormat()
    trees[sample].SetBranchStatus("*",0)
    trees[sample].SetBranchAddress("met_pt",AddressOf(treeVars,"MET"))
    trees[sample].SetBranchAddress("Jet_pt",AddressOf(treeVars,"Jetpt"))
    trees[sample].SetBranchAddress("FatJetpmass",AddressOf(treeVars,"FatJetMass"))
    trees[sample].SetBranchAddress("FatJetpt",AddressOf(treeVars,"FatJetpt"))
    trees[sample].SetBranchAddress("FatJettau2",AddressOf(treeVars,"FatJettau2"))
    trees[sample].SetBranchAddress("FatJettau1",AddressOf(treeVars,"FatJettau1"))
    trees[sample].SetBranchAddress("FatJetbbtag",AddressOf(treeVars,"FatJetbbtag"))
    trees[sample].SetBranchAddress("xsec",AddressOf(treeVars,"xsec"))
    trees[sample].SetBranchAddress("HLT_PFMET100_PFMHT100_IDTight_v",AddressOf(treeVars,"Trigger_PFMET100"))
    trees[sample].SetBranchAddress("HLT_PFHT800_v",AddressOf(treeVars,"Trigger_PFHT800"))

    numEvents = trees[sample].GetEntries()
    for iEvt in range(numEvents):
        trees[sample].GetEntry(iEvt)
        if iEvt % 1000000 == 0 : print iEvt,"/",numEvents

        METhistos.fill(treeVars,sample)
        HThistos.fill(treeVars,sample)
        J1Masshistos.fill(treeVars,sample)
        J2Masshistos.fill(treeVars,sample)
        J1bbtaghistos.fill(treeVars,sample)
        J2bbtaghistos.fill(treeVars,sample)

METtotal = createSum("MET",METhistos.histos)
METstack = createStack("MET",METhistos.histos,samples,METhistos.histos["HTMHT"].Integral()/METtotal.Integral())

HTtotal = createSum("HT",HThistos.histos)
HTstack = createStack("HT",HThistos.histos,samples,HThistos.histos["HTMHT"].Integral()/HTtotal.Integral())

J1Masstotal = createSum("J1Mass",J1Masshistos.histos)
J1Massstack = createStack("J1Mass",J1Masshistos.histos,samples,J1Masshistos.histos["HTMHT"].Integral()/J1Masstotal.Integral())

J2Masstotal = createSum("J2Mass",J2Masshistos.histos)
J2Massstack = createStack("J2Mass",J2Masshistos.histos,samples,J2Masshistos.histos["HTMHT"].Integral()/J2Masstotal.Integral())

J1bbtagtotal = createSum("J1bbtag",J1bbtaghistos.histos)
J1bbtagstack = createStack("J1bbtag",J1bbtaghistos.histos,samples,J1bbtaghistos.histos["HTMHT"].Integral()/J1bbtagtotal.Integral())

J2bbtagtotal = createSum("J2bbtag",J2bbtaghistos.histos)
J2bbtagstack = createStack("J2bbtag",J2bbtaghistos.histos,samples,J2bbtaghistos.histos["HTMHT"].Integral()/J2bbtagtotal.Integral())

print "MC integral:",METtotal.Integral()
print "Data integral:",METhistos.histos["HTMHT"].Integral()

canMET = TCanvas("canMET","canMET",500,500)
METstack.Draw("hist")
METstack.GetYaxis().SetRangeUser(0.1,1000000)
METhistos.histos["HTMHT"].Draw("SAME,e1")

canHT = TCanvas("canHT","canHT",500,500)
HTstack.Draw("hist")
HTstack.GetYaxis().SetRangeUser(0.1,1000000)
HThistos.histos["HTMHT"].Draw("SAME,e1")

canJ1Mass = TCanvas("canJ1Mass","canJ1Mass",500,500)
J1Massstack.Draw("hist")
J1Massstack.GetYaxis().SetRangeUser(0.1,1000000)
J1Masshistos.histos["HTMHT"].Draw("SAME,e1")

canJ2Mass = TCanvas("canJ2Mass","canJ2Mass",500,500)
J2Massstack.Draw("hist")
J2Massstack.GetYaxis().SetRangeUser(0.1,1000000)
J2Masshistos.histos["HTMHT"].Draw("SAME,e1")

canJ1bbtag = TCanvas("canJ1bbtag","canJ1bbtag",500,500)
J1bbtagstack.Draw("hist")
J1bbtagstack.GetYaxis().SetRangeUser(0.1,1000000)
J1bbtaghistos.histos["HTMHT"].Draw("SAME,e1")

canJ2bbtag = TCanvas("canJ2bbtag","canJ2bbtag",500,500)
J2bbtagstack.Draw("hist")
J2bbtagstack.GetYaxis().SetRangeUser(0.1,1000000)
J2bbtaghistos.histos["HTMHT"].Draw("SAME,e1")
