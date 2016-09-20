#!/bin/bash

INPUTFILE=$1
OUTPUTDIR=$2

tar -xf workingArea.tar
cd CMSSW_7_4_2/src
eval `scramv1 runtime -sh`

ls 
cd boostedHiggsHeppy/src
./baselineSkim.exe $INPUTFILE ./

FILE=`ls *.root`
xrdcp --force $FILE $OUTPUTDIR/$FILE
#./baselineSkim.exe root://cmseos.fnal.gov//store/user/lpchbb/HeppyNtuples/V14/ root://cmseos.fnal.gov//store/user/awhitbe1/heppySkims/ TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root





