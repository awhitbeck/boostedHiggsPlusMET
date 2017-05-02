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

MC plots of signal region -- minus data: `plotObs_baseline.cc`, `plotObs_doubleHiggsTag.cc`, `plotObs_antitag.cc`

MC plots of top/W enriched control region (with data): `plotObs_singleMuCR_baseline.cc`, 