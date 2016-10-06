#!/Bin/bash


#skims="V23v4"
skims="RA2bSkims_V10_v0"
#skimType="RA2bSkim"
skimType="singleMuCR"
eos="root://cmseos.fnal.gov//store/user/awhitbe1/"
eosWrite="root://cmsxrootd.fnal.gov/"
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
WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
TTJets_HT-600to800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
TTJets_HT-800to1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
TTJets_HT-1200to2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
TTJets_HT-2500toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8
"""

for sample in $samples 
do
    echo $sample
    #echo `xrdfs root://cmseos.fnal.gov ls -u /store/user/awhitbe1/${skims} | grep "${skimType}_${sample}_" | grep \.root`
    hadd -f -k -v 0 ${skimType}_$sample.root `xrdfs root://cmseos.fnal.gov ls -u /store/user/awhitbe1/${skims} | grep "${skimType}_${sample}_" | grep \.root` 
    xrdcp --force ${skimType}_$sample.root root://cmseos.fnal.gov//store/user/awhitbe1/${skims}/${skimType}_$sample.root
    rm ${skimType}_$sample.root
    #hadd -f -k -v 0 -j5 ${skimType}_$sample.root ~/eos/${skims}/${skimType}*${sample}*root
done

sample="ZJetsToNuNu_HT-600To800_13TeV-madgraph"
hadd -f -k -v 0 -j6 ${skimType}_${sample}_x.root ~/eos/${skims}/${skimType}_${sample}_[0-9].root
hadd -f -k -v 0 -j6 ${skimType}_${sample}_xx.root ~/eos/${skims}/${skimType}_${sample}_[0-9][0-9].root
hadd -f -k -v 0 -j6 ${skimType}_${sample}_xxx.root ~/eos/${skims}/${skimType}_${sample}_[0-9][0-9][0-9].root
hadd -f -k -v 0 -j6 ${skimType}_${sample}.root ${skimType}_${sample}_*x*.root
xrdcp --force ${skimType}_$sample.root root://cmseos.fnal.gov//store/user/awhitbe1/${skims}/${skimType}_$sample.root
rm ${skimType}_${sample}*.root

hadd -f -k -v 0 -j6 ${skimType}_QCD.root ${eos}/${skims}/${skimType}_QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${eos}/${skims}/${skimType}_QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${eos}/${skims}/${skimType}_QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${eos}/${skims}/${skimType}_QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${eos}/${skims}/${skimType}_QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${eos}/${skims}/${skimType}_QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root

xrdcp --force ${skimType}_QCD.root root://cmseos.fnal.gov//store/user/awhitbe1/${skims}/${skimType}_QCD.root
rm ${skimType}_QCD.root

hadd -f -k -v 0 -j6 ${skimType}_TTJets.root ${eos}/${skims}/${skimType}_TTJets_HT-600to800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${eos}/${skims}/${skimType}_TTJets_HT-800to1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${eos}/${skims}/${skimType}_TTJets_HT-1200to2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${eos}/${skims}/${skimType}_TTJets_HT-2500toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root 
xrdcp --force ${skimType}_TTJets.root root://cmseos.fnal.gov//store/user/awhitbe1/${skims}/${skimType}_TTJets.root
rm ${skimType}_TTJets.root

hadd -f -k -v 0 -j6 ${skimType}_ZJets.root ${eos}/${skims}/${skimType}_ZJetsToNuNu_HT-1200To2500_13TeV-madgraph.root ${eos}/${skims}/${skimType}_ZJetsToNuNu_HT-200To400_13TeV-madgraph.root ${eos}/${skims}/${skimType}_ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph.root ${eos}/${skims}/${skimType}_ZJetsToNuNu_HT-400To600_13TeV-madgraph.root ${eos}/${skims}/${skimType}_ZJetsToNuNu_HT-600To800_13TeV-madgraph.root ${eos}/${skims}/${skimType}_ZJetsToNuNu_HT-800To1200_13TeV-madgraph.root
xrdcp --force ${skimType}_ZJets.root root://cmseos.fnal.gov//store/user/awhitbe1/${skims}/${skimType}_ZJets.root
rm ${skimType}_ZJets.root

hadd -f -k -v 0 -j6 ${skimType}_WJets.root ${eos}/${skims}/${skimType}_WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${eos}/${skims}/${skimType}_WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${eos}/${skims}/${skimType}_WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${eos}/${skims}/${skimType}_WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${eos}/${skims}/${skimType}_WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root ${eos}/${skims}/${skimType}_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root
xrdcp --force ${skimType}_WJets.root root://cmseos.fnal.gov//store/user/awhitbe1/${skims}/${skimType}_WJets.root
rm ${skimType}_WJets.root

sample="HTMHT"
hadd -f -k -v 0 -j6 ${skimType}_${sample}_x.root `xrdfs root://cmseos.fnal.gov ls -u /store/user/awhitbe1/${skims} | grep '${skimType}_${sample}_[0-9].root'`
hadd -f -k -v 0 -j6 ${skimType}_${sample}_xx.root `xrdfs root://cmseos.fnal.gov ls -u /store/user/awhitbe1/${skims} | grep '${skimType}_${sample}_[0-9][0-9].root'`
hadd -f -k -v 0 -j6 ${skimType}_${sample}_xxx.root `xrdfs root://cmseos.fnal.gov ls -u /store/user/awhitbe1/${skims} | grep '${skimType}_${sample}_[0-9][0-9][0-9].root'`
hadd -f -k -v 0 -j6 ${skimType}_${sample}_1xxx.root `xrdfs root://cmseos.fnal.gov ls -u /store/user/awhitbe1/${skims} | grep '${skimType}_${sample}_1[0-9][0-9][0-9].root'`
hadd -f -k -v 0 -j6 ${skimType}_${sample}.root ${skimType}_${sample}_*x*.root
xrdcp --force ${skimType}_$sample.root ${eos}/${skims}/${skimType}_$sample.root
rm ${skimType}_${sample}*.root

#samples="T5GH_mGluino_1300_mNLSP_1250 T5GH_mGluino_1400_mNLSP_1350 T5GH_mGluino_1500_mNLSP_1450 T5GH_mGluino_1600_mNLSP_1550 T5GH_mGluino_1700_mNLSP_1650"
#for sample in $samples
#do 
#    hadd -f -k -v 0 -j6 ${skimType}_${sample}.root ${skimType}_${sample}_0.root
#done

