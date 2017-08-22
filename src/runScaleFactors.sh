#!/bin/sh

if [ $# != 1 ]
then
    echo "NEED TO PROVIDE HASH CODE"
    exit
fi

COMMIT=$1

echo "COMMIT: ${COMMIT}"

hadd -f ~/eos/boostedHiggsPlusMET/$COMMIT/ALPHABEThistos_singleLep.root ~/eos/boostedHiggsPlusMET/$COMMIT/ALPHABEThistos_singleEle.root ~/eos/boostedHiggsPlusMET/$COMMIT/ALPHABEThistos_singleMu.root

hadd -f ~/eos/boostedHiggsPlusMET/$COMMIT/ALPHABEThistos_looseCuts_singleLep.root ~/eos/boostedHiggsPlusMET/$COMMIT/ALPHABEThistos_looseCuts_singleEle.root ~/eos/boostedHiggsPlusMET/$COMMIT/ALPHABEThistos_looseCuts_singleMu.root

regions="_looseCuts_photon _photon _singleMu _looseCuts_singleMu _singleEle _looseCuts_singleEle _singleLep _looseCuts_singleLep _lowDphi _looseCuts_lowDphi"

echo "^^^^ Signal region ^^^^^" 
echo ">>>> >100 "
root -l -n -b -q 'checkScaleFactors.cc("",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","MET",1,4,"~/eos/boostedHiggsPlusMET/'$COMMIT'/plots/ABCDscaleFactors/")'
root -l -n -b -q 'checkScaleFactors.cc("",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","MET",1,4,"~/eos/boostedHiggsPlusMET/'$COMMIT'/plots/ABCDscaleFactors/")'
echo ">>>> >100 fine"
root -l -n -b -q 'checkScaleFactors.cc("",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","METfine",1,4,"~/eos/boostedHiggsPlusMET/'$COMMIT'/plots/ABCDscaleFactors/")'
root -l -n -b -q 'checkScaleFactors.cc("",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","METfine",1,4,"~/eos/boostedHiggsPlusMET/'$COMMIT'/plots/ABCDscaleFactors/")'
echo ">>>> >300 "
root -l -n -b -q 'checkScaleFactors.cc("",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","MET",2,4,"~/eos/boostedHiggsPlusMET/'$COMMIT'/plots/ABCDscaleFactors/")'
root -l -n -b -q 'checkScaleFactors.cc("",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","MET",2,4,"~/eos/boostedHiggsPlusMET/'$COMMIT'/plots/ABCDscaleFactors/")'

for region in $regions 
do
    echo "^^^^ "$region" region ^^^^^" 
    echo ">>>> >100 "
    root -l -n -b -q 'checkScaleFactors.cc("'$region'",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","MET",1,4,"~/eos/boostedHiggsPlusMET/'$COMMIT'/plots/ABCDscaleFactors/")'
    root -l -n -b -q 'checkScaleFactors.cc("'$region'",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","MET",1,4,"~/eos/boostedHiggsPlusMET/'$COMMIT'/plots/ABCDscaleFactors/")'
    echo ">>>> >100 fine"
    root -l -n -b -q 'checkScaleFactors.cc("'$region'",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","METfine",1,4,"~/eos/boostedHiggsPlusMET/'$COMMIT'/plots/ABCDscaleFactors/")'
    root -l -n -b -q 'checkScaleFactors.cc("'$region'",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","METfine",1,4,"~/eos/boostedHiggsPlusMET/'$COMMIT'/plots/ABCDscaleFactors/")'
    echo ">>>> >300 "
    root -l -n -b -q 'checkScaleFactors.cc("'$region'",true,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","MET",2,4,"~/eos/boostedHiggsPlusMET/'$COMMIT'/plots/ABCDscaleFactors/")'
    root -l -n -b -q 'checkScaleFactors.cc("'$region'",false,"~/eos/boostedHiggsPlusMET/'$COMMIT'/","MET",2,4,"~/eos/boostedHiggsPlusMET/'$COMMIT'/plots/ABCDscaleFactors/")'
done
