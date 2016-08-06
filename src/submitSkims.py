import os

inputs = open("skimInputs.txt","read")

for f in inputs : 
    f = f[:-1]
    inputFile = f.split()[0]
    xsection = f.split()[1]
    print "file:",inputFile
    print "xsec:",xsection
    
    os.system("condor_submit singleLepCRSkim.jdl arguments='root://cmseos.fnal.gov//store/user/lpchbb/HeppyNtuples/V14/ root://cmseos.fnal.gov//store/user/awhitbe1/heppySkims/ {0} {1}'".format(inputFile,xsection))
