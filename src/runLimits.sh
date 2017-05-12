#!/bin/bash

signals="mGluino1300 mGluino1400 mGluino1500 mGluino1600 mGluino1700"

for signal in $signals 
do
    combineCards.py datacard_AnalysisBins_*_${signal}_bin*.txt > datacard_AnalysisBins_${signal}.txt
    combine -M Asymptotic datacard_AnalysisBins_${signal}.txt -t -1 
    combine -M ProfileLikelihood datacard_AnalysisBins_${signal}.txt -t -1 --significance --expectSignal=1 
done
