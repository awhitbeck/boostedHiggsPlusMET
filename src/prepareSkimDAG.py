import os

inputs = open("../data/RA2bInputs.txt","read")

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

    dagFiles[sample].write("JOB {0}Skim_{1}_{2} {0}Skim.jdl \n".format(skimType,sample,indices[sample]))
    dagFiles[sample].write("VARS {0}Skim_{1}_{2} arguments=\"{3} root://cmseos.fnal.gov//store/user/awhitbe1/RA2bSkims_V10_v0/ \" \n".format(skimType,sample,indices[sample],inputFile))
    indices[sample]=indices[sample]+1
