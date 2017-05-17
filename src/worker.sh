#!/bin/sh
output_dir=$1
executable=$2
args=$3
echo "output_dir ${output_dir}"
echo "executable ${executable}"
echo "args ${args}"

mv ../../workingArea.tar .
tar -xf workingArea.tar
cd CMSSW_7_4_2/src/
eval `scramv1 runtime -sh`
echo "step 2"
cd boostedHiggsPlusMET
export PATH=$PWD/bin/:$PATH
echo "PWD ${PWD}"
echo "PATH ${PATH}"
cd src
make all

`echo $executable $args`

for file in $(ls *root)
do
    xrdcp -f $file root://cmseos.fnal.gov//store/user/awhitbe1/boostedHiggsPlusMET/$output_dir/$file
done

cd ../
for file in $(ls plots/*/*)
do 
    xrdcp -f $file root://cmseos.fnal.gov//store/user/awhitbe1/boostedHiggsPlusMET/$output_dir/$file
done