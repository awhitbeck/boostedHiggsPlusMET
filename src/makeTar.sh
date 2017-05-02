#!/bin/bash

cd $CMSSW_BASE/../
tar -cf workingArea.tar CMSSW_7_4_2 --exclude='*.dag.*' --exclude='*tar' --exclude='*root' --exclude='*png' --exclude='*pdf' --exclude='*stdout' --exclude='*stderr' --exclude='*condor'
mv workingArea.tar CMSSW_7_4_2/src/boostedHiggsPlusMET/src/.