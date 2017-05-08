#include "sampleParser.cc"
#include "TChain.h"

int main( int argc, char** argv){

  fileMap fmap = parseInputs("../data/heppyInputs.txt") ; 
  sampleMap smap = invertFileMap(fmap) ; 

  for( sampleMap::iterator it = smap.begin() ; it!=smap.end() ; ++it){

    if( it->first == "HTMHT" || it->first == "JetHT" ) continue;
    TChain* t = buildChain(it->second,"tree");
    cout << it->first << " : " << t->GetEntries() << endl;
  }

}
