#!/bin/bash

submitDir=$PWD
branch=$1
hash=`git rev-parse origin/${branch}`

if [ ! -e /eos/uscms/store/user/${USER}/boostedHiggsPlusMET/ ] 
    then
    echo "I need /eos/uscms/store/user/${USER}/boostedHiggsPlusMET/"
    exit
fi

echo "hash ${hash}"               # this is intended to correspond to the hash of your git commit for tracking/reproducibility
                                  # -- you can get the hash with `git rev-parse origin/RA2b_V12_v0`
source makeOutputDir.sh $hash     # setup directories in eos for output
source makeTar.sh                 # package up code to transfer to worker nodes
cd $submitDir

condor_submit batchExecute.jdl exec_name="cutFlow" arguments="${hash} cutFlow"

condor_submit batchExecute.jdl exec_name="plotObs_baseline" arguments="${hash} plotObs_baseline"
condor_submit batchExecute.jdl exec_name="plotObs_antitag" arguments="${hash} plotObs_antitag"
condor_submit batchExecute.jdl exec_name="plotObs_doubleHiggsTag" arguments="${hash} plotObs_doubleHiggsTag"
condor_submit batchExecute.jdl exec_name="plotObs_singleHiggsTag" arguments="${hash} plotObs_singleHiggsTag"

condor_submit batchExecute.jdl exec_name="plotObs_singleEleCR_baseline" arguments="${hash} plotObs_singleEleCR_baseline"
condor_submit batchExecute.jdl exec_name="plotObs_singleMuCR_baseline" arguments="${hash} plotObs_singleMuCR_baseline"

condor_submit batchExecute.jdl exec_name="plotObs_photon_baseline" arguments="${hash} plotObs_photon_baseline"

condor_submit batchExecute.jdl exec_name="plotObs_lowDPhi_baseline" arguments="${hash} plotObs_lowDPhi_baseline"

condor_submit batchExecute.jdl exec_name="ALPHABET_signal" arguments="${hash} ALPHABET 0"
condor_submit batchExecute.jdl exec_name="ALPHABET_singleMu" arguments="${hash} ALPHABET 1"
condor_submit batchExecute.jdl exec_name="ALPHABET_singleEle" arguments="${hash} ALPHABET 2"
condor_submit batchExecute.jdl exec_name="ALPHABET_lowDPhi" arguments="${hash} ALPHABET 3"
condor_submit batchExecute.jdl exec_name="ALPHABET_photon" arguments="${hash} ALPHABET_photon"

condor_submit batchExecute.jdl exec_name="datacardInputs" arguments="${hash} datacardInputs"

