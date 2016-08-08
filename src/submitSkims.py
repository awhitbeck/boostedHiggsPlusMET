import os

inputs = open("../data/heppyInputs.txt","read")

def getSampleNorm( sample = "" ):

    normFile = open("../data/norms.dat","r")
    for line in normFile : 
        if line.split()[0] == sample : 
            return line.split()[1]

    return 1.

for f in reversed(inputs.readlines()):
    f = f[:-1]
    inputFile = f.split()[0]
    sample = f.split()[1]
    norm = getSampleNorm(sample)
    print "file:",inputFile
    print "norm:",norm 
    os.system("condor_submit baselineSkim.jdl arguments='{0} root://cmseos.fnal.gov//store/user/awhitbe1/heppySkims_V23/ {1}'".format(inputFile,norm))
    break
