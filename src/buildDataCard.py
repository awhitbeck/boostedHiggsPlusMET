from ROOT import *

inputFileName="datacardInputsRA2b10.root"
histoTag="AnalysisRA2b10Bins"
signalTags=["mGluino1300","mGluino1500","mGluino1700","mHiggsino900","mHiggsino1000"]

for signalTag in signalTags : 

    inputFile = TFile(inputFileName,"read")

    regions = ["tagSR","tagSB","antitagSR","antitagSB","doubletagSR","doubletagSB","mutagSR","mutagSB","muantitagSR","muantitagSB","muDoubletagSR","muDoubletagSB"]
    for r in regions : 

        WJets = inputFile.Get(histoTag+"_"+r+"_WJets")
        ZJets = inputFile.Get(histoTag+"_"+r+"_ZJets")
        TT = inputFile.Get(histoTag+"_"+r+"_TT")
        QCD = inputFile.Get(histoTag+"_"+r+"_QCD")
        signal = inputFile.Get(histoTag+"_"+r+"_"+signalTag)
        
        histos = [signal,total]
        histoLabel = ["signal","bkg"]

        if total.GetNbinsX() != signal.GetNbinsX() : 
            assert(0)

        for i in range(signal.GetNbinsX()) :

            outputFile = open("RA2bSkims_datacards_MET/datacard_"+histoTag+"_"+r+"_"+signalTag+"_bin{0}.txt".format(i),'w')
            outputFile.write("imax 1  #number of channels \n")
            outputFile.write("jmax 1  #number of backgrounds \n")
            if r=="tagSR":
                outputFile.write("kmax 1  #number of nuisances \n")
            if r=="tagSB":
                outputFile.write("kmax 2  #number of nuisances \n")
            if r=="antitagSR":
                outputFile.write("kmax 1  #number of nuisances \n")
            if r=="antitagSB":
                outputFile.write("kmax 2  #number of nuisances \n")
            outputFile.write("------------ \n")
            outputFile.write("bin {0}_bin{1} \n ".format(r,i))
            outputFile.write("observation 0 \n")
            lines = {}
            lines["binIndex"] = "bin "
            lines["processNames"] = "process "
            lines["processIndex"] = "process "
            lines["rate"] = "rate "
            if r == "tagSR" :
                lines["RpassFail"] = "RpassFail_bin{0} lnU - 200 ".format(i)
            if r == "tagSB" :
                lines["RpassFail"] = "RpassFail_bin{0} lnU - 200 ".format(i)
                lines["TagAntitag"] = "TagAntitag_bin{0} lnU - 200 ".format(i)
            if r == "antitagSR" :
                lines["AntiRpassFail"] = "AntiRpassFail_bin{0} lnU - 200 ".format(i)
            if r == "antitagSB" :
                lines["AntiRpassFail"] = "AntiRpassFail_bin{0} lnU - 200 ".format(i)
                lines["TagAntitag"] = "TagAntitag_bin{0} lnU - 200 ".format(i)
                
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
            if r == "tagSR" : 
                outputFile.write(lines["RpassFail"]+"\n")
            if r == "tagSB" : 
                outputFile.write(lines["RpassFail"]+"\n")
                outputFile.write(lines["TagAntitag"]+"\n")
            if r == "antitagSR" : 
                outputFile.write(lines["AntiRpassFail"]+"\n")
            if r == "antitagSB" : 
                outputFile.write(lines["AntiRpassFail"]+"\n")
                outputFile.write(lines["TagAntitag"]+"\n")

            outputFile.close()

