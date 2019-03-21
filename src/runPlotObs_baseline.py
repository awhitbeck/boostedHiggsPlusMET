from multiprocessing import Process
import os

#os.environ["DYLD_LIBRARY_PATH"] = "/Users/whitbeck/root_build/lib"

backgroundSamples=["QCD_200to300",
                   "QCD_300to500",
                   "QCD_500to700",
                   "QCD_700to1000",
                   "QCD_1000to1500",
                   "QCD_1500to2000",
                   "QCD_2000toInf",
                   "ZJets_100to200",
                   "ZJets_200to400",
                   "ZJets_400to600",
                   "ZJets_600to800",
                   "ZJets_800to1200",
                   "ZJets_1200to2500",
                   "ZJets_2500toInf",
                   "WJets_100to200",
                   "WJets_200to400",
                   "WJets_400to600",
                   "WJets_600to800",
                   "WJets_800to1200",
                   "WJets_1200to2500",
                   "WJets_2500toInf",
                   "TT_600to800",
                   "TT_800to1200",
                   "TT_1200to2500",
                   "TT_2500toInf",
                   "ST_s-channel",
                   "ST_t-channel_antitop",
                   "ST_t-channel_top",
                   "ST_tW_antitop",
                   "ST_tW_antitop",

                   # "Other_WWTo1L1Nu2Q",
                   # "Other_WWTo2L2Nu",
                   # "Other_WWZ",
                   # "Other_WZTo1L1Nu2Q",
                   # "Other_WZTo1L3Nu",
                   # "Other_WZZ",
                   # "Other_ZZTo2L2Q",
                   # "Other_ZZTo2Q2Nu",
                   # "Other_ZZZ",
                   # "Other_TTTT",
                   # "Other_TTWJetsToLNu",
                   # "Other_TTWJetsToQQ",
                   # "Other_TTGJets",
                   # "Other_TTZToLLNuNu",
                   # "Other_TTZToQQ",
]

dataSamples=["MET_2016B",
             "MET_2016C",
             "MET_2016D",
             "MET_2016E",
             "MET_2016F",
             "MET_2016G",
             "MET_2016H"
             ]

def runPlotObsBaseline(sel,bkg,sig,data):
    print '../bin/plotObs_baseline "{0}" "{1}" "{2}" "{3}"'.format(sel,bkg,sig,data)
    os.system('../bin/plotObs_baseline "{0}" "{1}" "{2}" "{3}"'.format(sel,bkg,sig,data))

processes=[]
for sample in backgroundSamples : 
    p = Process(target=runPlotObsBaseline, args=("ZSBNoVBF",sample,"","") )
    p.start()
    processes.append(p)

for sample in dataSamples : 
    p = Process(target=runPlotObsBaseline, args=("ZSBNoVBF","","", sample) )
    p.start()
    processes.append(p)

for p in processes : 
    p.join()

#os.system("hadd -f plotObs_photon_baseline.root plotObs_photon_baseline_*.root")
#os.system("rm plotObs_photon_baseline_*.root")
2    
    


