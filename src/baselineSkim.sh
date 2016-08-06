#!/bin/sh

INPUTDIR=$1
OUTPUTDIR=$2
FILE=$3
XSECTION=$4

tar -xf workingArea.tar
cd CMSSW_7_4_2/src
eval `scramv1 runtime -sh`

./boostedHiggsHeppy/src/baselineSkim.exe $INPUTDIR ./ $FILE $XSECTION

xrdcp $FILE $OUTPUTDIR/$FILE
#./baselineSkim.exe root://cmseos.fnal.gov//store/user/lpchbb/HeppyNtuples/V14/ root://cmseos.fnal.gov//store/user/awhitbe1/heppySkims/ TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root





