from ROOT import *

inputFileName="RA2b160Bins/datacardInputs.root"
histoTag="RA2b160Bins"
signalTags=["mGluino1300","mGluino1400","mGluino1500","mGluino1600","mGluino1700"]

for signalTag in signalTags : 

    inputFile = TFile(inputFileName,"read")

    regions = ["SR"]

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
        
        #histos = [signal,WJets,ZJets,TT,QCD]
        #histoLabel = ["signal","WJets","ZJets","TT","QCD"]
        histos = [signal,total]
        histoLabel = ["signal","bkg"]

        #if WJets.GetNbinsX() != ZJets.GetNbinsX() != TT.GetNbinsX() != QCD.GetNbinsX() != signal.GetNbinsX() : 
        if total.GetNbinsX() != signal.GetNbinsX() : 
            assert(0)

        for i in range(signal.GetNbinsX()) :

            outputFile = open("RA2b160Bins/datacard_"+histoTag+"_"+r+"_"+signalTag+"_bin{0}.txt".format(i),'w')
            outputFile.write("imax 1  #number of channels \n")
            outputFile.write("jmax 1  #number of backgrounds \n")
            outputFile.write("kmax 1  #number of nuisances \n")
            outputFile.write("------------ \n")
            outputFile.write("bin {0}_bin{1} \n ".format(r,i))
            outputFile.write("observation 0 \n")
            lines = {}
            lines["binIndex"] = "bin "
            lines["processNames"] = "process "
            lines["processIndex"] = "process "
            lines["rate"] = "rate "
            lines["BkgSyst"] = "BkgSyst_bin{0} lnN - 1.2 ".format(i)
                
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
            outputFile.write(lines["BkgSyst"]+"\n")
            
            outputFile.close()

