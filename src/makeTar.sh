#!/bin/bash

CMSSW=`echo $CMSSW_BASE | awk -F '/' '{print $NF}'`
cd $CMSSW_BASE/../
tar -cf workingArea.tar $CMSSW --exclude='*.dag.*' --exclude='*tar' --exclude='$CMSSW/*/src/*root' --exclude='*eps' --exclude='*png' --exclude='*pdf' --exclude='*stdout' --exclude='*stderr' --exclude='*condor' --exclude='$CMSSW/*/bin/*' --exclude='$CMSSW/src/boostedHiggsPlusMET/.git/*' --exclude='$CMSSW/src/boostedHiggsPlusMET/src/*dag' --exclude='$CMSSW/src/boostedHiggsPlusMET/datacards'
mv workingArea.tar $CMSSW/src/boostedHiggsPlusMET/src/.