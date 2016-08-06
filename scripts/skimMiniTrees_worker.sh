#!/bin/bash                                                                                                                                         
SAMPLE=$1

source /cvmfs/cms.cern.ch/cmsset_default.sh
scram p CMSSW CMSSW_7_4_2
cd CMSSW_7_4_2/src
eval `scramv1 runtime -sh`
cd -

python skimMiniTrees.py -s $SAMPLE

# not transferring to eos...
#xrdcp miniTreeSkim_${SAMPLE}.root root://cmseos.fnal.gov//store/user/awhitbe1/TPskims_v2/miniTreeSkim_${SAMPLE}.root
#rm *root
