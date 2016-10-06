from ROOT import *

inputFileName="datacardInputs_MET_BTags1_DeltaPhi12.root"
histoTag="MET"
#signalTags=["mGluino1300","mGluino1500","mGluino1700"]
signalTags=["mHiggsino900","mHiggsino1000","mHiggsino800","mHiggsino700","mHiggsino600","mHiggsino500","mHiggsino400","mHiggsino300"]

for signalTag in signalTags : 

    inputFile = TFile(inputFileName,"read")

    regions = ["tagSR","doubletagSR"]

    for r in regions : 

        WJets = inputFile.Get(histoTag+"_"+r+"_WJets")
        ZJets = inputFile.Get(histoTag+"_"+r+"_ZJets")
        TT = inputFile.Get(histoTag+"_"+r+"_TT")
        QCD = inputFile.Get(histoTag+"_"+r+"_QCD")
        total = TH1F(WJets)
        total.SetNameTitle("total","total")
        total.Add(ZJets)
        total.Add(TT)
        total.Add(QCD)
        signal = inputFile.Get(histoTag+"_"+r+"_"+signalTag)
        signal.Scale(.58*.58)

        histos = [signal,WJets,ZJets,TT,QCD]
        histoLabel = ["signal","WJets","ZJets","TT","QCD"]
        #histos = [signal,total]
        #histoLabel = ["signal","bkg"]

        if WJets.GetNbinsX() != ZJets.GetNbinsX() != TT.GetNbinsX() != QCD.GetNbinsX() != signal.GetNbinsX() : 
        #if total.GetNbinsX() != signal.GetNbinsX() : 
            assert(0)

        for i in range(signal.GetNbinsX()+1) :  ### +1 to include overflow

            outputFile = open("RA2bSkims_datacards_MET_BTags1_DeltaPhi12_simple/datacard_"+histoTag+"_"+r+"_"+signalTag+"_bin{0}.txt".format(i),'w')
            outputFile.write("imax 1  #number of channels \n")
            outputFile.write("jmax 4  #number of backgrounds \n")
            outputFile.write("kmax 4  #number of nuisances \n")
            outputFile.write("------------ \n")
            outputFile.write("bin {0}_bin{1} \n ".format(r,i))
            outputFile.write("observation {0} \n".format(total.GetBinContent(i+1)))
            lines = {}
            lines["binIndex"] = "bin "
            lines["processNames"] = "process "
            lines["processIndex"] = "process "
            lines["rate"] = "rate "
            lines["ZJetsSyst"] = "ZJetsSyst_bin{0} lnN - - 1.2 - - ".format(i)
            lines["WJetsSyst"] = "WJetsSyst_bin{0} lnN - 1.2 - - - ".format(i)
            lines["TTSyst"] = "TTSyst_bin{0} lnN - - - 1.2 - ".format(i)
            lines["QCDSyst"] = "QCDSyst_bin{0} lnN - - - - 1.2 ".format(i)
                
            for iHisto,h in enumerate(histos) : 
                lines["binIndex"] = lines["binIndex"] + "{0}_bin{1} ".format(r,i)
                lines["processNames"] = lines["processNames"] + histoLabel[iHisto] + " "
                lines["processIndex"] = lines["processIndex"] + str(iHisto) + " " 
                if h.GetBinContent(i+1) == 0 : 
                    lines["rate"] = lines["rate"] + "0.00001 " 
                else : 
                    lines["rate"] = lines["rate"] + str(h.GetBinContent(i+1)) + " " 

            outputFile.write(lines["binIndex"]+"\n")
            outputFile.write(lines["processNames"]+"\n")
            outputFile.write(lines["processIndex"]+"\n")
            outputFile.write(lines["rate"]+"\n")
            outputFile.write("------------ \n")
            outputFile.write(lines["ZJetsSyst"]+"\n")
            outputFile.write(lines["WJetsSyst"]+"\n")
            outputFile.write(lines["TTSyst"]+"\n")
            outputFile.write(lines["QCDSyst"]+"\n")
            
            outputFile.close()

