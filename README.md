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

Before submitting any batch jobs, be sure to retar your working area and copy it into the <code>src/</code> directory.

<pre>
bash makeTar.sh        
</pre>

NEEDS UPDATING -- ALSO NEEDS CODE TO STREAMLINE BATCH SUBMISSION

Example:
<pre>
---
</pre>

#### Things to run

- MC plots of signal region -- minus data: `plotObs_baseline.cc`, `plotObs_doubleHiggsTag.cc`, `plotObs_antitag.cc`

- MC plots of top/W enriched control region (with data): `plotObs_singleMuCR_baseline.cc`, 

#### Region descriptions/definitions

Baseline selections are defined for the signal region and for each of the validation regions. Broadly, they require two AK8 jets with transverse momentum above ... 

#### Comparisons of ABCD predictions

To access the consistency between data/MC predicitons, yields from data and MC are compared in each of the ABCD regions.  Scale factors are also derived from these plots.  In region A, the observed yeild in data is compared to the prediction from data.  To reproduce these plots, first create histograms:

see code `ALPHABET.cc` -- [here](https://github.com/awhitbeck/boostedHiggsPlusMET/blob/RA2b_V12_v0/src/ALPHABET.cc) 

Then to produce plots and scale factors, see code `checkScaleFactors.cc` -- [here](https://github.com/awhitbeck/boostedHiggsPlusMET/blob/RA2b_V12_v0/src/checkScaleFactors.cc)

