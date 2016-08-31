Repo for studying boosted Higgs tools with the heppy trees

# Batch:

Before submitting any batch jobs, be sure to retar your working area:

<pre>
cd $CMSSW_BASE/../
tar -cf workingArea.tar CMSSW_7_4_2 --exclude='*.dag.*' --exclude='*tar' --exclude='*root' --exclude='*png' --exclude='*pdf' --exclude='*stdout' --exclude='*stderr' --exclude='*condor'
mv workingArea.tar $CMSSW_BASE/src/boostedHiggsHeppy/src/
cd $CMSSW_BASE/src/boostedHiggsHeppy/src/
</pre>

## baselineSkim

baselineSkim is used to reduce the heppy trees down to a managable size by
selecting one the events that pass a set of baseline cuts.  These cuts are
defined in src/selecBaseline.cc.  

### Compile:

<pre>
g++ `root-config --cflags --glibs` -I$CMSSW_BASE/src/AnalysisTools/src/ -I$CMSSW_BASE/src/boostedHiggsHeppy/src/ $CMSSW_BASE/src/boostedHiggsHeppy/src/baselineSkim.cc -o $CMSSW_BASE/src/boostedHiggsHeppy/src/baselineSkim.exe
</pre>  

<pre>
g++ `root-config --cflags --glibs` -I$CMSSW_BASE/src/AnalysisTools/src/ -I$CMSSW_BASE/src/boostedHiggsHeppy/src/ -I$CMSSW_BASE/src/ $CMSSW_BASE/src/boostedHiggsHeppy/src/go.cc -o $CMSSW_BASE/src/boostedHiggsHeppy/src/go.exe
</pre>
### Batch submit:

The jdl file for run the skims is <code>baselineSkim.jdl</code>.  One should specify the three command line arguments to <code>baselineSkim.sh</code> 
when submitting the job.  e.g.:

<pre>
condor_submit baselineSkim.jdl arguments='root://cmseos.fnal.gov//store/user/lpchbb/HeppyNtuples/V14/ root://cmseos.fnal.gov//store/user/awhitbe1/heppySkims/ TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root'
</pre>