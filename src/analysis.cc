#include "heppyTree.cc"
#include "analyzer.cc"
#include "signalRegion.cc"
#include "skim.cc"
#include "fillHisto.cc"

#include "TString.h"
#include "TChain.h"
#include "TFile.h"

#include <cstdio>
#include <string>
#include <iostream>

#include "helpers.h"

using namespace std;

int main(int argc, char** argv){

  // this code is setup specifically for analyzing one input file at a time.  The output histonames
  // are based on the sample key, from the fmap (see helper.h for details)
  TString fileTag = argv[1];
  fileMap fmap = parseInputs("inputFiles.txt");
  sampleMap rmap = reduceMap(fmap,fileTag);
  if( rmap.size() != 1 ){
    cout << "either no samples found or too many samples found..." << endl;
    return 1;
  }

  TString sampleTag = rmap.begin()->first;
  TChain* t = buildChain(rmap.begin()->second,"tree");
  heppyTree *ntuple = new heppyTree(t);

  signalRegion SR(ntuple,sampleTag);

  for( int i = 0 ; i < t->GetEntries() ; i++ ){
    t->GetEntry(i);
    if( i % 10000 == 0 ) 
      cout << "event: " << i << endl;
    SR.analyze();
  }

  cout << "save tree" << endl;
  TFile* outFile = new TFile("fullAnalysis_"+fileTag+".root","RECREATE");
  SR.postProcess();
  outFile->Close();
  
}
