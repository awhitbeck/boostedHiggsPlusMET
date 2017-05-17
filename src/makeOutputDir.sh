#!/bin/bash

newDir=$1

if [ -d ~/eos/boostedHiggsPlusMET/$newDir ] 
    then
    echo "DIRECTORY ALREADY EXISTS -- I DON'T KNOW HOW TO HANDLE THIS...BYE"
    exit 1
fi

mkdir ~/eos/boostedHiggsPlusMET/$newDir
mkdir ~/eos/boostedHiggsPlusMET/$newDir/plots
plotsDirList="plotObs_singleEleCR_baseline_plots plotObs_doubleHiggsTag_plots plotObs_singleHiggsTag_plots plotObs_singleMuCR_baseline_plots ABCDscaleFactors cutFlow_plots plotObs_lowDPhi_baseline_plots ALPHABET NminusOne_plots plotObs_antitag_plots plotObs_photon_baseline_plots plotObs_baseline_plots"
for i in $plotsDirList 
do 
    mkdir ~/eos/boostedHiggsPlusMET/$newDir/plots/$i
done


