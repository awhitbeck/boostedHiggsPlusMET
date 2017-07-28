#!/bin/sh

if [ $# != 1 ]
then
    echo "NEED TO PROVIDE HASH CODE"
    exit
fi

COMMIT=$1

echo "COMMIT: ${COMMIT}"

regions="_looseCuts_photon _photon _singleMu _looseCuts_singleMu _singleEle _looseCuts_singleEle _singleLep _looseCuts_singleLep _lowDphi _looseCuts_lowDphi"

echo "^^^^ Signal region ^^^^^" 
echo ">>>> >100 "
root -l -n -b -q 'checkScaleFactors.cc("",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","MET",1)'
#root -l -n -b -q 'checkScaleFactors.cc("",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","MET",1)'
echo ">>>> >100 fine"
root -l -n -b -q 'checkScaleFactors.cc("",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","METfine",1)'
#root -l -n -b -q 'checkScaleFactors.cc("",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","METfine",1)'
echo ">>>> >300 "
root -l -n -b -q 'checkScaleFactors.cc("",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","MET",2)'
#root -l -n -b -q 'checkScaleFactors.cc("",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","MET",2)'

for region in $regions 
do
    echo "^^^^ "$region" region ^^^^^" 
    echo ">>>> >100 "
    root -l -n -b -q 'checkScaleFactors.cc("'$region'",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","MET",1)'
    #root -l -n -b -q 'checkScaleFactors.cc("'$region'",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","MET",1)'
    echo ">>>> >100 fine"
    root -l -n -b -q 'checkScaleFactors.cc("'$region'",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","METfine",1)'
    #root -l -n -b -q 'checkScaleFactors.cc("'$region'",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","METfine",1)'
    echo ">>>> >300 "
    root -l -n -b -q 'checkScaleFactors.cc("'$region'",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","MET",2)'
    #root -l -n -b -q 'checkScaleFactors.cc("'$region'",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","MET",2)'
done
