from ROOT import *

histoFillColor = { "Data":1 , 
                   "TT":kCyan,
                   "QCD":kGray,
                   "DiBoson":kOrange }

def parseInputs( inputList = "miniTreeInputs.txt" ): 

    baseDir = ""
    tag = ""
    xsec = 1.
    inputFile = open(inputList,"r")

    sampleDict = {}

    count = 0 
    for line in inputFile : 
        line = line[:-1]
        if line[0] == "#" :
            line = line[1:]
            if line.split()[0] == "tag" :
                tag = line.split()[1]
                sampleDict[tag] = {"xsec":1.,"files":[]}
            if line.split()[0] == "xsec" :
                sampleDict[tag]["xsec"] = float(line.split()[1])
            continue
        #if line.split()[1] in sampleDict : 
            #sampleDict[line.split()[1]].append("root://cmseos.fnal.gov/"+baseDir+line.split()[0])
        #else : 
            #sampleDict[line.split()[1]]=["root://cmseos.fnal.gov/"+baseDir+line.split()[0]]

        if tag in sampleDict : 
            if count < 10 : 
                sampleDict[tag]["files"].append("root://cmseos.fnal.gov/"+line.split()[0])
            count = count+1
        else : 
            print "ERROR: input file not formatted right"
            return sampleDict

    return sampleDict

def initTrees( sampleDict , treeName = "myTree" ) : 

    treeDict = {}

    for sample in sampleDict : 
        treeDict[sample] = TChain("tree")
        for fileName in sampleDict[sample]["files"] : 
            treeDict[sample].Add(fileName)

    return treeDict
