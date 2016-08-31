import os

inputs = open("../data/heppyInputs.txt","read")

def getSampleNorm( sample = "" ):

    normFile = open("../data/norms.dat","r")
    for line in normFile : 
        if line.split()[0] == sample : 
            return line.split()[1]

    return 1.

dagFiles = {}
indices = {}
#skimType = "baseline"
skimType = "singleMuCR"
masterDAG = open("{0}Skim.dag".format(skimType),"w")

for f in reversed(inputs.readlines()):
    f = f[:-1]
    inputFile = f.split()[0]
    sample = f.split()[1]
    if not sample in dagFiles : 
        dagFiles[sample] = open("{0}Skim_{1}.dag".format(skimType,sample),"w")
        indices[sample] = 0 
        masterDAG.write("SUBDAG EXTERNAL {0}Skim_{1} {0}Skim_{1}.dag \n".format(skimType,sample))
    norm = getSampleNorm(sample)

    dagFiles[sample].write("JOB {0}Skim_{1}_{2} {0}Skim.jdl \n".format(skimType,sample,indices[sample]))
    dagFiles[sample].write("VARS {0}Skim_{1}_{2} arguments=\"{3} root://cmseos.fnal.gov//store/user/awhitbe1/heppySkims_V23v4/ {4}\" \n".format(skimType,sample,indices[sample],inputFile,norm))
    indices[sample]=indices[sample]+1
