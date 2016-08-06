from ROOT import *
from parseInputs import *
from optparse import OptionParser

gROOT.ProcessLine("struct treeFormat{Float_t norm;Float_t xsec;}")

parser = OptionParser()
parser.add_option("-s", "--sample", dest="sample", default="QCD", help="input sample")

(options, args) = parser.parse_args()

sample = options.sample

treeVars = treeFormat()

sampleDict = parseInputs("heppyInputs.txt")
print sampleDict[sample]["xsec"]
treeDict = initTrees( sampleDict , "tree"  )
t = treeDict[sample]

#inputFile = TFile.Open("root://cmsxrootd.fnal.gov//store/user/mkrohn/HHTo4b/V23/miniTrees/{0}.root".format(sample),"READ")
#t = inputFile.Get("myTree")

#normFromHisto = inputFile.Get("CountWeighted").GetBinContent(1)

t.SetBranchStatus("*",0)
t.SetBranchStatus("run",1)
t.SetBranchStatus("lumi",1)           
t.SetBranchStatus("evt",1)            
t.SetBranchStatus("xsec",1)           
t.SetBranchStatus("puWeight",1)       
t.SetBranchStatus("nTrueInt",1)       
t.SetBranchStatus("genWeight",1)      
t.SetBranchStatus("nPU0",1)           
t.SetBranchStatus("nPVs",1)           
t.SetBranchStatus("rho",1)            
t.SetBranchStatus("Flag_HBHENoiseIsoFilter",1)
t.SetBranchStatus("Flag_EcalDeadCellTriggerPrimitiveFilter",1)
t.SetBranchStatus("Flag_trkPOG_manystripclus53X",1)
t.SetBranchStatus("Flag_ecalLaserCorrFilter",1)
t.SetBranchStatus("Flag_trkPOG_toomanystripclus53X",1)
t.SetBranchStatus("Flag_hcalLaserEventFilter",1)
t.SetBranchStatus("Flag_muonBadTrackFilter",1)
t.SetBranchStatus("Flag_trkPOG_logErrorTooManyClusters",1)
t.SetBranchStatus("Flag_trkPOGFilters",1)
t.SetBranchStatus("Flag_trackingFailureFilter",1)
t.SetBranchStatus("Flag_CSCTightHaloFilter",1)
t.SetBranchStatus("Flag_HBHENoiseFilter",1)
t.SetBranchStatus("Flag_chargedHadronTrackResolutionFilter",1)
t.SetBranchStatus("Flag_goodVertices",1)
t.SetBranchStatus("Flag_METFilters",1)
t.SetBranchStatus("Flag_CSCTightHalo2015Filter",1)
t.SetBranchStatus("Flag_eeBadScFilter",1)
t.SetBranchStatus("HLT2_BIT_HLT_PFMET90_PFMHT90_IDTight_v",1)
t.SetBranchStatus("HLT2_BIT_HLT_PFMET100_PFMHT100_IDTight_v",1)
t.SetBranchStatus("HLT2_BIT_HLT_PFMET110_PFMHT110_IDTight_v",1)
t.SetBranchStatus("HLT2_BIT_HLT_PFMET120_PFMHT120_IDTight_v",1)
t.SetBranchStatus("HLT2_BIT_HLT_PFMET170_NoiseCleaned_v",1)
t.SetBranchStatus("HLT2_BIT_HLT_PFHT800_v",1) 
t.SetBranchStatus("met_pt",1) 
t.SetBranchStatus("met_phi",1) 
t.SetBranchStatus("nGenHiggsBoson",1) 
t.SetBranchStatus("GenHiggsBoson_pdgId",1)
t.SetBranchStatus("GenHiggsBoson_pt",1)
t.SetBranchStatus("GenHiggsBoson_eta",1)
t.SetBranchStatus("GenHiggsBoson_phi",1)
t.SetBranchStatus("GenHiggsBoson_mass",1)
t.SetBranchStatus("GenHiggsBoson_charge",1)
t.SetBranchStatus("GenHiggsBoson_status",1)
t.SetBranchStatus("naLeptons",1)      
t.SetBranchStatus("aLeptons_charge",1)
t.SetBranchStatus("aLeptons_tightId",1)
t.SetBranchStatus("aLeptons_pdgId",1) 
t.SetBranchStatus("aLeptons_pt",1)    
t.SetBranchStatus("aLeptons_eta",1)   
t.SetBranchStatus("aLeptons_phi",1)   
t.SetBranchStatus("aLeptons_mass",1)  
t.SetBranchStatus("nJet",1)           
t.SetBranchStatus("Jet_btagCSV",1)    
t.SetBranchStatus("Jet_btagCMVA",1)   
t.SetBranchStatus("Jet_partonFlavour",1)
t.SetBranchStatus("Jet_hadronFlavour",1)
t.SetBranchStatus("Jet_mcMatchId",1)  
t.SetBranchStatus("Jet_pt",1)         
t.SetBranchStatus("Jet_eta",1)        
t.SetBranchStatus("Jet_phi",1)        
t.SetBranchStatus("Jet_mass",1)       
t.SetBranchStatus("Jet_btagBDT",1)    
t.SetBranchStatus("Jet_btagCSVV0",1)  
t.SetBranchStatus("Jet_btagCMVAV2",1) 
t.SetBranchStatus("nFatjetAK08ungroomed",1)
t.SetBranchStatus("FatjetAK08ungroomed_pt",1)
t.SetBranchStatus("FatjetAK08ungroomed_eta",1)
t.SetBranchStatus("FatjetAK08ungroomed_phi",1)
t.SetBranchStatus("FatjetAK08ungroomed_mass",1)
t.SetBranchStatus("FatjetAK08ungroomed_tau1",1)
t.SetBranchStatus("FatjetAK08ungroomed_tau2",1)
t.SetBranchStatus("FatjetAK08ungroomed_mpruned",1)
t.SetBranchStatus("FatjetAK08ungroomed_mprunedcorr",1)
t.SetBranchStatus("FatjetAK08ungroomed_bbtag",1)
t.SetBranchStatus("FatjetAK08ungroomed_chargedHadronEnergyFraction",1)
t.SetBranchStatus("FatjetAK08ungroomed_chargedMultiplicity",1)
t.SetBranchStatus("FatjetAK08ungroomed_Flavour",1)
t.SetBranchStatus("FatjetAK08ungroomed_BhadronFlavour",1)
t.SetBranchStatus("FatjetAK08ungroomed_ChadronFlavour",1)

outputTree = t.CloneTree(0)
outputTree.SetNameTitle("myTree","myTree")

t.SetBranchAddress("xsec",AddressOf(treeVars,"xsec"))
outputTree.Branch("norm",AddressOf(treeVars,"norm"),"norm/F")
numEntries = t.GetEntries() 

for iEvt in range(numEntries):
    t.GetEntry(iEvt)
    treeVars.xsec = sampleDict[sample]["xsec"]
    treeVars.norm = float(numEntries)
    print "norm:",treeVars.norm
    if iEvt % 100000 == 0 : print iEvt,"/",numEntries
    #if iEvt > 10000 : break

    MET = getattr(t,"met_pt")
    if MET > 250. :
        outputTree.Fill()
        
outputFile = TFile("miniTreeSkim_"+sample+".root","RECREATE")
outputTree.Write()
outputFile.Close()




