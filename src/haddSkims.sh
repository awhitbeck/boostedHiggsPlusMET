#!/bin/bash

samples="""QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
ZJetsToNuNu_HT-1200To2500_13TeV-madgraph
ZJetsToNuNu_HT-200To400_13TeV-madgraph
ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph
ZJetsToNuNu_HT-400To600_13TeV-madgraph
ZJetsToNuNu_HT-600To800_13TeV-madgraph
ZJetsToNuNu_HT-800To1200_13TeV-madgraph
WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8"""

for sample in $samples 
do
    echo $sample
    hadd -f -k -v 0 -j5 heppSkim_$sample.root ~/eos/heppySkims_V23v2/*$sample*root
done

hadd -f -k -v 0 -j6 heppSkim_QCD.root heppSkim_QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root

rm heppSkim_QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root

hadd -f -k -v 0 -j6 heppSkim_ZJets.root heppSkim_ZJetsToNuNu_HT-1200To2500_13TeV-madgraph.root heppSkim_ZJetsToNuNu_HT-200To400_13TeV-madgraph.root heppSkim_ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph.root heppSkim_ZJetsToNuNu_HT-400To600_13TeV-madgraph.root heppSkim_ZJetsToNuNu_HT-600To800_13TeV-madgraph.root heppSkim_ZJetsToNuNu_HT-800To1200_13TeV-madgraph.root

rm heppSkim_ZJetsToNuNu_HT-1200To2500_13TeV-madgraph.root heppSkim_ZJetsToNuNu_HT-200To400_13TeV-madgraph.root heppSkim_ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph.root heppSkim_ZJetsToNuNu_HT-400To600_13TeV-madgraph.root heppSkim_ZJetsToNuNu_HT-600To800_13TeV-madgraph.root heppSkim_ZJetsToNuNu_HT-800To1200_13TeV-madgraph.root

hadd -f -k -v 0 -j6 heppSkim_WJets.root heppSkim_WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root

rm heppSkim_WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root heppSkim_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root

exit 

sample="TT_TuneCUETP8M1_13TeV-powheg-pythia8"
hadd -f -k -v 0 -j6 heppSkim_${sample}_x.root ~/eos/heppySkims_V23v2/heppySkim_${sample}_[0-9].root
hadd -f -k -v 0 -j6 heppSkim_${sample}_xx.root ~/eos/heppySkims_V23v2/heppySkim_${sample}_[0-9][0-9].root
hadd -f -k -v 0 -j6 heppSkim_${sample}_xxx.root ~/eos/heppySkims_V23v2/heppySkim_${sample}_[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 heppSkim_${sample}_1xxx.root ~/eos/heppySkims_V23v2/heppySkim_${sample}_1[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 heppSkim_${sample}_2xxx.root ~/eos/heppySkims_V23v2/heppySkim_${sample}_2[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 heppSkim_${sample}_3xxx.root ~/eos/heppySkims_V23v2/heppySkim_${sample}_3[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 heppSkim_${sample}_4xxx.root ~/eos/heppySkims_V23v2/heppySkim_${sample}_4[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 heppSkim_${sample}.root heppSkim_${sample}_*x*.root
rm heppSkim_${sample}_*x*.root

sample="HTMHT"
hadd -f -k -v 0 -j6 heppSkim_${sample}_x.root ~/eos/heppySkims_V23v2/heppySkim_${sample}_[0-9].root
hadd -f -k -v 0 -j6 heppSkim_${sample}_xx.root ~/eos/heppySkims_V23v2/heppySkim_${sample}_[0-9][0-9].root
hadd -f -k -v 0 -j6 heppSkim_${sample}_xxx.root ~/eos/heppySkims_V23v2/heppySkim_${sample}_[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 heppSkim_${sample}_1xxx.root ~/eos/heppySkims_V23v2/heppySkim_${sample}_1[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 heppSkim_${sample}_2xxx.root ~/eos/heppySkims_V23v2/heppySkim_${sample}_2[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 heppSkim_${sample}_3xxx.root ~/eos/heppySkims_V23v2/heppySkim_${sample}_3[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 heppSkim_${sample}.root heppSkim_${sample}_*x*.root
rm heppSkim_${sample}_*x*.root

