#include "heppyTree.cc"
#include "analyzer.cc"
#include "selectBaseline.cc"
#include "TString.h"
#include "TChain.h"
#include "TFile.h"

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv){

  TChain* t = new TChain("tree");
  char inputFile[200];
  sprintf(inputFile,"%s/%s",argv[1],argv[3]);
  t->Add(inputFile);
  float weight = atof(argv[4]); // currently this is just the xsection

  heppyTree *ntuple = new heppyTree(t);
  int numEvents = t->GetEntries();
  weight/=numEvents;

  selectBaseline<heppyTree> *selectBase = new selectBaseline<heppyTree>(ntuple,"test");

  TTree* outputTree = ntuple->fChain->CloneTree(0);
  outputTree->Branch("weight",&weight,"weight/F");

  for( int i = 0 ; i < numEvents ; i++ ){
    if( i%10000 == 0 ) std::cout << "Event " << i << "/" << numEvents << endl;
    t->GetEntry(i);

    if( selectBase->process() )
      outputTree->Fill();
  }

  char outputFileName[200];
  sprintf(outputFileName,"%s/%s",argv[2],argv[3]);
  TFile* outputFile = new TFile(outputFileName,"RECREATE");
  cout << "save tree" << endl;
  selectBase->histo->Write("baselineYields");
  outputTree->Write();
  outputFile->Close();

  delete ntuple;
  delete selectBase;

}  
