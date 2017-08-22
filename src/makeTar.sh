#!/bin/bash

cd $CMSSW_BASE/../
tar -cf workingArea.tar CMSSW_7_4_2 --exclude='*.dag.*' --exclude='*tar' --exclude='CMSSW_7_4_2/*/src/*root' --exclude='*eps' --exclude='*png' --exclude='*pdf' --exclude='*stdout' --exclude='*stderr' --exclude='*condor' --exclude='CMSSW_7_4_2/*/bin/*' --exclude='CMSSW_7_4_2/src/boostedHiggsPlusMET/.git/*' --exclude='CMSSW_7_4_2/src/boostedHiggsPlusMET/src/*dag' --exclude='CMSSW_7_4_2/src/boostedHiggsPlusMET/datacards'
mv workingArea.tar CMSSW_7_4_2/src/boostedHiggsPlusMET/src/.