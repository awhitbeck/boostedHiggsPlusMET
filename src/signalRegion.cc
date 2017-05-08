#include "heppyTree.cc"
#include "analyzer.cc"
#include "selectBaseline.cc"
#include "fillHisto.cc"
#include "fillRA2bVars.cc"

#include "TString.h"
#include "TChain.h"
#include "TFile.h"

#include <cstdio>
#include <string>
#include <iostream>

using namespace std; 

/* 
   analyzer for plotting distributions in the full phase space of the
   signal region ...
*/

typedef fillHisto<heppyTree> histo;

class signalRegion : public analyzer<heppyTree> {

public :

  heppyTree* ntuple;
  selectBaseline<heppyTree> *selectBase;
  fillRA2bVars<heppyTree> *ra2bvars;
  TString sampleTag, regionTag;

  signalRegion( heppyTree* ntuple_ , TString sampleTag_ , TString regionTag_ = "SR" , 
		vector<processor<heppyTree>* > *addSelectors = 0 )
    : analyzer<heppyTree>(ntuple_,1){
    ntuple = ntuple_ ; 
    sampleTag = sampleTag_;
    regionTag = regionTag_;

    ra2bvars = new fillRA2bVars<heppyTree>(ntuple,"SR_"+sampleTag,"weight");

    if( addSelectors && addSelectors->size()>0){
      for( unsigned int s=0 ; s < addSelectors->size() ; s++ ){
	addProcessor(addSelectors->at(s));
      }
    }
    
    addProcessor(ra2bvars);

  };

  ~signalRegion(){
    
  };

  void analyze(){
    
    for( unsigned int iProc = 0 ; iProc < processorList->size() ; iProc++){
      //cout << "proc: " << iProc << " " << processorList->at(iProc)->moduleName << endl;
      if( ! processorList->at(iProc)->process() ) break;
    }

  };

  void postProcess(){
    ra2bvars->histoMHT->Write();
    ra2bvars->histoHT->Write();
    ra2bvars->histoNJets->Write();
    ra2bvars->histoDeltaPhi1->Write();
    ra2bvars->histoDeltaPhi2->Write();
    ra2bvars->histoDeltaPhi3->Write();
    ra2bvars->histoDeltaPhi4->Write();
  };

};
