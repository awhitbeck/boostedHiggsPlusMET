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
masterDAG = open("baselineSkim.dag","w")

for f in reversed(inputs.readlines()):
    f = f[:-1]
    inputFile = f.split()[0]
    sample = f.split()[1]
    if not sample in dagFiles : 
        dagFiles[sample] = open("baselineSkim_{0}.dag".format(sample),"w")
        indices[sample] = 0 
        masterDAG.write("SUBDAG EXTERNAL baselineSkim_{0} baselineSkim_{0}.dag \n".format(sample))
    norm = getSampleNorm(sample)
    #print "file:",inputFile
    #print "norm:",norm 
    dagFiles[sample].write("JOB baselineSkim_{0}_{1} baselineSkim.jdl \n".format(sample,indices[sample]))
    dagFiles[sample].write("VARS baselineSkim_{0}_{1} arguments=\"{2} root://cmseos.fnal.gov//store/user/awhitbe1/heppySkims_V23v3/ {3}\" \n".format(sample,indices[sample],inputFile,norm))
    indices[sample]=indices[sample]+1

#for sample,dagFile in enumerate(dagFiles) : 
#    dagFile.close()

#masterDAG.close()
