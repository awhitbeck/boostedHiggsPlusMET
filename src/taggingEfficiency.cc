#include "signalRegion.cc"
#include "fillHtaggingVars.cc"
#include "selectHiggsTag.cc"

using namespace std;

int main(int argc, char** argv){

  TString inputFileName = argv[1];
  TString fileTag     = argv[2];
  TString histoTag     = argv[3];
  TChain* t = new TChain("tree");
  t->Add(inputFileName);

  heppyTree* ntuple = new heppyTree(t);
  selectHiggsTag<heppyTree> cut1Higgs(ntuple,1,10,"1Higgs_"+histoTag);
  
  cout << "starting loop" << endl;
  for( int iEvt = 0 ; iEvt < ntuple->fChain->GetEntries() ; iEvt++ ){
    ntuple->fChain->GetEntry(iEvt);
    if( iEvt%1000 == 0 ) cout << "iEvt: " << iEvt << endl;
    //cout << "iEvt: " << iEvt << endl;
    cut1Higgs.process();
  }

  TFile* outputFile = new TFile("taggingEfficiency_"+fileTag+".root","RECREATE");
  cut1Higgs.postProcess();
  outputFile->Close();

}
