Repo for studying boosted Higgs tools with the RA2b trees.  This package relies on another package for setting up some basic 
classes to facilitate some things.  

#General Stuff:

#### Setting up the code:
<pre>
cmsrel CMSSW_7_4_2
cd CMSSW_7_4_2/src/
cmsenv
git clone https://github.com/awhitbeck/boostedHiggsPlusMET.git
</pre>

NEEDS UPDATING

#### Compiling:

NEEDS UPDATING
 
#### Batch:

All batch submissions are done through `submitBatch.sh`.  Code is tar'ed sent to worker nodes and outputs are transferd to EOS.  
You will need to have a directory in your eos called boostedHiggsPlusMET.  This script by default takes a branch as input
and will create a new EOS area with the name of the latest commit hash from the remote repository (origin is used).

<pre>
bash makeTar.sh        
</pre>

In case you want to submit jobs one by one, you can re-tar your area with `makeTag.sh` and generate the relevant directory
structure in your target EOS area using `makeOutputDir.sh`.  The latter should be passed the target directory.  Individual
jobs can then be submitted with e.g.:

```bash
condor_submit batchExecute.jdl exec_name="plotObs_baseline" arguments="${hash} plotObs_baseline"
```

Argument for the executable can be tacked onto the end of `arguments`.  The variable hash should be your target EOS directory.

#### Things to run

- MC plots of signal region -- minus data: `plotObs_baseline.cc`, `plotObs_doubleHiggsTag.cc`, `plotObs_antitag.cc`

- MC plots of top/W enriched control region (with data): `plotObs_singleMuCR_baseline.cc`, 

#### Region descriptions/definitions

Baseline selections are defined for the signal region and for each of the validation regions. Broadly, they require two AK8 jets with transverse momentum above 300 GeV and mass between 50 and 250 GeV, MET>300 GeV, HT>600 GeV, the usual deltaPhi cut, and the usual event filters.  

There are also 3 validation regions defined: low deltaPhi -- QCD enriched, single photon -- proxy for Z(nn), and a single lepton control region -- W/top enriched. 

For the signal region, and each of the validation regions, a function is defined in `definitions.cc` to specify all of the cuts applied: [signal region function](https://github.com/awhitbeck/boostedHiggsPlusMET/blob/RA2b_V12_v0/src/definitions.cc#L665-L687), [photon validation region function](https://github.com/awhitbeck/boostedHiggsPlusMET/blob/RA2b_V12_v0/src/definitions.cc#L789-L853), [low deltaPhi validation region function](https://github.com/awhitbeck/boostedHiggsPlusMET/blob/RA2b_V12_v0/src/definitions.cc#L749-L770), [single muon validation region function](https://github.com/awhitbeck/boostedHiggsPlusMET/blob/RA2b_V12_v0/src/definitions.cc#L689-L718), [single electron validation region function](https://github.com/awhitbeck/boostedHiggsPlusMET/blob/RA2b_V12_v0/src/definitions.cc#L720-L747).

#### Comparisons of ABCD predictions

To access the consistency between data/MC predicitons, yields from data and MC are compared in each of the ABCD regions.  Scale factors are also derived from these plots.  In region A, the observed yeild in data is compared to the prediction from data.  To reproduce these plots, first create histograms:

see code `ALPHABET.cc` -- [here](https://github.com/awhitbeck/boostedHiggsPlusMET/blob/RA2b_V12_v0/src/ALPHABET.cc) 

Then to produce plots and scale factors, see code `checkScaleFactors.cc` -- [here](https://github.com/awhitbeck/boostedHiggsPlusMET/blob/RA2b_V12_v0/src/checkScaleFactors.cc)

Because photons need to be cleaned from AK8 jets, there is a dedicated piece of code to create histograms for checking ABCD yields in the photon control region. This is something that needs to be improved to avoid mistakes due to upkeep costs. The code is `ALPHABET_photon.cc` -- [here](https://github.com/awhitbeck/boostedHiggsPlusMET/blob/RA2b_V12_v0/src/ALPHABET_photon.cc)

compile code with:

```bash
make ALPHABET
make ALPHABET_photon
```
#### plots basic distributions after baseline selection

A number of basic distributions after baseline cuts can be plotted with `plotObs_*_baseline.cc`.  This code will produce all of the plots and save the histograms to a root file.  E.g. for the single muon validation region:

```bash
make plotOb_singleMuCR_baseline
plotOb_singleMuCR_baseline
```

#### B-hadron flavor fits

To produce the b-hadron flavor fits, you should first run the `plotObs_*_baseline.cc` code to produce all of the input histograms.  E.g. for the photon control region:

```bash
make plotObs_photon_baseline
plotObs_photon_baseline

make flavorFit
flavorFit photon 0 # lead jet
flavorFit photon 1 # sub-leadjet
``` 

#### Cut flow table

To produce the cut flow table, you should run `cutFlow.cc` ([https://github.com/awhitbeck/boostedHiggsPlusMET/blob/RA2b_V12_v0/src/cutFlow.cc](here)).  This will print a latex-formatted table to the standard output.  To run:

```bash
make cutFlow
cutFlow
```

#### WtaggingEfficiency

To produce histograms for fitting the W(qq) peak in data/MC, you first need to run `WtaggingEfficiency.cc` to get the input histograms for fitting.   Then run `fitWpeak.cc`

```bash
make WtaggingEfficiency
WtaggingEfficiency 1 # single muon events
WtaggingEfficiency 2 # single electron events
make fitWpeak
fitWpeak
```