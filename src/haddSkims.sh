#!/bin/bash

skims="V23v4"
#skimType="heppySkim"
skimType="singleMuCR"
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
    hadd -f -k -v 0 -j5 ${skimType}_$sample.root ~/eos/heppySkims_${skims}/${skimType}*${sample}*root
done

hadd -f -k -v 0 -j6 ${skimType}_QCD.root ${skimType}_QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root

rm ${skimType}_QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root

hadd -f -k -v 0 -j6 ${skimType}_ZJets.root ${skimType}_ZJetsToNuNu_HT-1200To2500_13TeV-madgraph.root ${skimType}_ZJetsToNuNu_HT-200To400_13TeV-madgraph.root ${skimType}_ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph.root ${skimType}_ZJetsToNuNu_HT-400To600_13TeV-madgraph.root ${skimType}_ZJetsToNuNu_HT-600To800_13TeV-madgraph.root ${skimType}_ZJetsToNuNu_HT-800To1200_13TeV-madgraph.root

rm ${skimType}_ZJetsToNuNu_HT-1200To2500_13TeV-madgraph.root ${skimType}_ZJetsToNuNu_HT-200To400_13TeV-madgraph.root ${skimType}_ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph.root ${skimType}_ZJetsToNuNu_HT-400To600_13TeV-madgraph.root ${skimType}_ZJetsToNuNu_HT-600To800_13TeV-madgraph.root ${skimType}_ZJetsToNuNu_HT-800To1200_13TeV-madgraph.root

hadd -f -k -v 0 -j6 ${skimType}_WJets.root ${skimType}_WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root

rm ${skimType}_WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${skimType}_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root

sample="TT_TuneCUETP8M1_13TeV-powheg-pythia8"
hadd -f -k -v 0 -j6 ${skimType}_${sample}_x.root ~/eos/heppySkims_${skims}/${skimType}_${sample}_[0-9].root
hadd -f -k -v 0 -j6 ${skimType}_${sample}_xx.root ~/eos/heppySkims_${skims}/${skimType}_${sample}_[0-9][0-9].root
hadd -f -k -v 0 -j6 ${skimType}_${sample}_xxx.root ~/eos/heppySkims_${skims}/${skimType}_${sample}_[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 ${skimType}_${sample}_1xxx.root ~/eos/heppySkims_${skims}/${skimType}_${sample}_1[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 ${skimType}_${sample}_2xxx.root ~/eos/heppySkims_${skims}/${skimType}_${sample}_2[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 ${skimType}_${sample}_3xxx.root ~/eos/heppySkims_${skims}/${skimType}_${sample}_3[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 ${skimType}_${sample}_4xxx.root ~/eos/heppySkims_${skims}/${skimType}_${sample}_4[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 ${skimType}_${sample}.root ${skimType}_${sample}_*x*.root
rm ${skimType}_${sample}_*x*.root

sample="HTMHT"
hadd -f -k -v 0 -j6 ${skimType}_${sample}_x.root ~/eos/heppySkims_${skims}/${skimType}_${sample}_[0-9].root
hadd -f -k -v 0 -j6 ${skimType}_${sample}_xx.root ~/eos/heppySkims_${skims}/${skimType}_${sample}_[0-9][0-9].root
hadd -f -k -v 0 -j6 ${skimType}_${sample}_xxx.root ~/eos/heppySkims_${skims}/${skimType}_${sample}_[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 ${skimType}_${sample}_1xxx.root ~/eos/heppySkims_${skims}/${skimType}_${sample}_1[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 ${skimType}_${sample}_2xxx.root ~/eos/heppySkims_${skims}/${skimType}_${sample}_2[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 ${skimType}_${sample}_3xxx.root ~/eos/heppySkims_${skims}/${skimType}_${sample}_3[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 ${skimType}_${sample}.root ${skimType}_${sample}_*x*.root
rm ${skimType}_${sample}_*x*.root

samples="T5GH_mGluino_1300_mNLSP_1250 T5GH_mGluino_1400_mNLSP_1350 T5GH_mGluino_1500_mNLSP_1450 T5GH_mGluino_1600_mNLSP_1550 T5GH_mGluino_1700_mNLSP_1650"
for sample in $samples
do 
    hadd -f -k -v 0 -j6 ${skimType}_${sample}.root ${skimType}_${sample}_0.root
done

