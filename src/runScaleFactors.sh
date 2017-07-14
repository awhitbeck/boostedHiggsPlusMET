#!/bin/sh

if [ $# != 1 ]
then
    echo "NEED TO PROVIDE HASH CODE"
    exit
fi

COMMIT=$1

echo "COMMIT: ${COMMIT}"

regions="_looseCuts_photon _photon _singleMu _looseCuts_singleMu _singleEle _looseCuts_singleEle _singleLep _looseCuts_singleLep _lowDphi _looseCuts_lowDphi"

for i in "1 2" 
do 
    echo "^^^^ Signal region ^^^^^" 
    echo ">>>> >100 "
    root -l -n -b -q 'checkScaleFactors.cc("",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
    echo ">>>> >300 "
    root -l -n -b -q 'checkScaleFactors.cc("",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'

    for region in $regions 
    do
        echo "^^^^ "$region" region ^^^^^" 
        echo ">>>> >100 "
        root -l -n -b -q 'checkScaleFactors.cc("'$region'",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        echo ">>>> >300 "
        root -l -n -b -q 'checkScaleFactors.cc("'$region'",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        # root -l -n -b -q 'checkScaleFactors.cc("_photon",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        # root -l -n -b -q 'checkScaleFactors.cc("_photon",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        # root -l -n -b -q 'checkScaleFactors.cc("_singleMu",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        # root -l -n -b -q 'checkScaleFactors.cc("_singleMu",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        # root -l -n -b -q 'checkScaleFactors.cc("_looseCuts_singleMu",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        # root -l -n -b -q 'checkScaleFactors.cc("_looseCuts_singleMu",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        # root -l -n -b -q 'checkScaleFactors.cc("_singleEle",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        # root -l -n -b -q 'checkScaleFactors.cc("_singleEle",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        # root -l -n -b -q 'checkScaleFactors.cc("_looseCuts_singleEle",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        # root -l -n -b -q 'checkScaleFactors.cc("_looseCuts_singleEle",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        # root -l -n -b -q 'checkScaleFactors.cc("_singleLep",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        # root -l -n -b -q 'checkScaleFactors.cc("_singleLep",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        # root -l -n -b -q 'checkScaleFactors.cc("_looseCuts_singleLep",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        # root -l -n -b -q 'checkScaleFactors.cc("_looseCuts_singleLep",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        # root -l -n -b -q 'checkScaleFactors.cc("_lowDphi",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        # root -l -n -b -q 'checkScaleFactors.cc("_lowDphi",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        # root -l -n -b -q 'checkScaleFactors.cc("_looseCuts_lowDphi",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
        # root -l -n -b -q 'checkScaleFactors.cc("_looseCuts_lowDphi",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/",'$i')'
    done
done
