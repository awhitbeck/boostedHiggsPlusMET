#include "RA2bTree.cc"
#include "analyzer.cc"
#include "selectBaseline.cc"
#include "TString.h"
#include "TChain.h"
#include "TFile.h"
#include "sampleParser.cc"

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

// inputs should be:
//      name of input file
//      name of output directory
int main(int argc, char** argv){

  fileMap fmap = parseInputs("../data/RA2bInputs.txt");
  sampleMap smap = invertFileMap(fmap);
  xsecMap xsmap = parseXsec("../data/RA2bInputs.txt");

  TChain* t = new TChain("TreeMaker2/PreSelection");
  char inputFile[200];
  sprintf(inputFile,"%s/%s","root://cmseos.fnal.gov/",argv[1]);
  t->Add(inputFile);

  RA2bTree *ntuple = new RA2bTree(t);
  int numEvents = t->GetEntries();

  selectBaseline<RA2bTree> *selectBase = new selectBaseline<RA2bTree>(ntuple,"singleMuon",1,1,0,0);

  TTree* outputTree = ntuple->fChain->CloneTree(0);

  for( int i = 0 ; i < numEvents ; i++ ){
    if( i%10000 == 0 ) std::cout << "Event " << i << "/" << numEvents << endl;
    t->GetEntry(i);

    if( selectBase->process() )
      outputTree->Fill();
  }

  // for output file name
  int pos = find(smap[fmap[argv[1]]]->begin(), 
		 smap[fmap[argv[1]]]->end(),
		 argv[1])-smap[fmap[argv[1]]]->begin();

  char outputFileName[200];
  sprintf(outputFileName,"singleMuCR_%s_%i.root",fmap[argv[1]].Data(),pos);
    std::cout << "outputFile: " << outputFileName << std::endl;
  TFile* outputFile = new TFile(outputFileName,"RECREATE");
  cout << "save tree" << endl;
  selectBase->histo->Write("singleMuCRYields");
  outputTree->Write();
  outputFile->Close();

  delete ntuple;
  delete selectBase;

  std::cout << "done..." << std::endl;
}  
