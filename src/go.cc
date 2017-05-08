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
  //cout << "fillHtaggingVars" << endl;
  fillHtaggingVars<heppyTree> taggingVars(ntuple,histoTag,"weight");
  //cout << "vector stuff" << endl;
  //cout << "signalRegion" << endl;
  signalRegion SRanalysis(ntuple,histoTag);//,"SR",addProcessor);

  selectHiggsTag<heppyTree> cut1Higgs(ntuple,1,1,"1Higgs");
  fillHtaggingVars<heppyTree> taggingVars1Higgs(ntuple,"1Higgs_"+histoTag,"weight");
  signalRegion analysis1Higgs(ntuple,"1Higgs_"+histoTag);//,"SR",addProcessor);

  selectHiggsTag<heppyTree> cut2Higgs(ntuple,2,10,"2Higgs");
  fillHtaggingVars<heppyTree> taggingVars2Higgs(ntuple,"2Higgs_"+histoTag,"weight");
  signalRegion analysis2Higgs(ntuple,"2Higgs_"+histoTag);//,"SR",addProcessor);

  
  
  cout << "starting loop" << endl;
  for( int iEvt = 0 ; iEvt < ntuple->fChain->GetEntries() ; iEvt++ ){
    ntuple->fChain->GetEntry(iEvt);
    if( iEvt%1000 == 0 ) cout << "iEvt: " << iEvt << endl;
    //cout << "iEvt: " << iEvt << endl;
    SRanalysis.analyze() ;
    taggingVars.process() ;
    if( cut1Higgs.process() ){
      //cout << "pass 1 Higgs" << endl;
      analysis1Higgs.analyze();
      taggingVars1Higgs.process();
    }
    if( cut2Higgs.process() ){
      //cout << "pass 2 or more Higgs" << endl;
      analysis2Higgs.analyze();
      taggingVars2Higgs.process();
    }
  }

  TFile* outputFile = new TFile("signalRegionValidation_"+fileTag+".root","RECREATE");
  SRanalysis.postProcess();
  taggingVars.postProcess();

  cut1Higgs.histo->Write();
  taggingVars1Higgs.postProcess();
  analysis1Higgs.postProcess();

  cut2Higgs.histo->Write();
  taggingVars2Higgs.postProcess();
  analysis2Higgs.postProcess();

  outputFile->Close();

}
