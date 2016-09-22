Repo for studying boosted Higgs tools with the RA2b trees.  This package relies on another package for setting up some basic 
classes to facilitate some things.  

#General Stuff:

#### Setting up the code:
<pre>
cmsrel CMSSW_7_4_2
cd CMSSW_7_4_2/src/
cmsenv

git clone https://github.com/awhitbeck/AnalysisTools.git
git clone https://github.com/awhitbeck/boostedHiggsPlusMET.git
</pre>

#### Compiling:

There is currently no makefile for this repository.  However, to compile any of the code, one can use <code>build.sh</code>
by passing the name of the target .cc minus the file extension as an arugment.  The executable will will have the same
root as the target file name, but will be append with '.exe'
 
#### Batch:

Before submitting any batch jobs, be sure to retar your working area and copy it into the <code>src/</code> directory.

<pre>
cd $CMSSW_BASE/../
tar -cf workingArea.tar CMSSW_7_4_2 --exclude='*.dag.*' --exclude='*tar' --exclude='*root' --exclude='*png' --exclude='*pdf' --exclude='*stdout' --exclude='*stderr' --exclude='*condor'
mv workingArea.tar $CMSSW_BASE/src/boostedHiggsHeppy/src/
cd $CMSSW_BASE/src/boostedHiggsHeppy/src/
</pre>

This repo is largely a bunch of individual analysis scripts that can be used to perform various
measurements and/or validations.  This list includes:

|  Section Link | Quick description |
|:------------------------|:---------|
|[Baseline Skims](baselineSkim) | | 
|[Single-μ Skims](singleMuSkim)| |
|[Generate Datacard Inputs](datacardInputs)| | 
|[Plot Observables](plotObs)| | 
|[Toy Validations](toyValidation)| | 

# <a name="baselineSkim"></a>Baseline Skims

baselineSkim.cc is used to reduce the heppy trees down to a managable size by
selecting one the events that pass a set of baseline cuts.  These cuts are
defined in <code>src/selecBaseline.cc</code>. This script take two arguments, 
the input file name and the output eos directory.  The input file must exist 
in the input list found in <code>data/RA2bInputs.txt</code>.  

Example:
<pre>
./baselineSkim.exe /store/user/lpcsusyhad/SusyRA2Analysis2015/Run2ProductionV10/Spring16.TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_0_RA2AnalysisTree.root ./
</pre>

#### Batch submit:

To submit the code to condor @ the LPC, the simplest method is to first create a list of DAG files.  A script exists
to generate these dag files automatically.  The input arguments to the bash script (<code>baslineSkim.sh</code>) which is executed 
on the worker nodes are passed to the JDL files via the DAG files.  An example job configuration is:
<pre>
JOB baselineSkim_QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_0 baselineSkim.jdl
VARS baselineSkim_QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_0 arguments="/store/user/lpcsusyhad/SusyRA2Analysis2015/Run2ProductionV10/Spring16.QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_ext1_9_RA2AnalysisTree.root root://cmseos.fnal.gov//store/user/awhitbe1/RA2bSkims_V10_v0/ "
</pre>

To generate all of the necessary DAG files, run:
<pre>
python prepareSkimDAG.py
</pre>
The output will be one root DAG file and one sub-DAG for each sample.  

Then submitting all jobs is reduce to:
<pre>
condor_submit_dag baselineSkim.dag
</pre>

The root dag job continuously dumps reports in <code>baselineSkim.dag.dagman.out</code>.  For example, to 
monitor the progress of the sample-level DAG jobs:
<pre>
tail prepareSkimDAG.py.dagman.out
</pre>
Similarly, one can check on the progress of each sub-DAG. 

# <a name="singleMuSkim"></a> Single Muon Skims

This should be merged with the baseline skims... workflows are very very similar.

# <a name="datacardInputs"></a> Generating datacard inputs

<code>datacardInputs_MET.cc</code> can be used to create a root file with expected yields for generating
datacards.  

# <a name="plotObs"></a> Plotting Observables

<code>plotObs_antitag.cc</code>, <code>plotObs_baseline.cc</code>, <code>plotObs_singleHiggsTag.cc</code>, <code>plotObs_singleMuCR_antitag.cc</code>, <code>plotObs_singleMuCR_singleHiggsTag.cc</code> can be used to
plot various observables in the signal region and each of the control regions.

# <a name="toyValidation"></a> Toy validations

<code>FulltoyValidation.cc</code>, and <code>FulltoyValidationBkgOnly.cc</code> can be used to construct the
likelihood model used for background estimations, generete toys, and validate closure and signal bias based
on the fitted parameters from each toy.
