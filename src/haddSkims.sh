#!/bin/bash

samples="HTMHT"
# JetHT
# samples="""BulkGravTohhTohVVhbb_narrow_M-1000_13TeV-madgraph
# TT_TuneCUETP8M1_13TeV-powheg-pythia8
# QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
# QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
# QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
# QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
# QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
# QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
# ZJetsToNuNu_HT-1200To2500_13TeV-madgraph
# ZJetsToNuNu_HT-200To400_13TeV-madgraph
# ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph
# ZJetsToNuNu_HT-400To600_13TeV-madgraph
# ZJetsToNuNu_HT-600To800_13TeV-madgraph
# ZJetsToNuNu_HT-800To1200_13TeV-madgraph
# WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
# WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
# WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
# WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
# WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
# WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8"""

for sample in $samples 
do
    echo $sample
    hadd -f -k -v 0 -j6 heppSkim_$sample.root ~/eos/heppySkims_V23/*$sample*root
done