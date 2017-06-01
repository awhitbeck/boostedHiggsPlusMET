#include <fstream>
#include <cassert>
#include <iostream>
#include "TChain.h"
#include "TTree.h"
#include "TString.h"
#include "RA2bTree.cc"
#include "algorithm"

using namespace std;

int main( int argc, char** argv ){

    TString fileTag="";
    int MAX_EVENTS(99999999);
    if( argc == 2 )
        fileTag = argv[1];
    else if( argc > 2 ){
        fileTag = argv[1];
        MAX_EVENTS = atoi(argv[2]);
    }else{
        cout << "need to provide a tag for sample and (optionally) MAX_EVENTS" << endl;
        return 1;
    }   

    cout << " - - - - - - - - - " << endl;
    cout << "fileTag: " << fileTag << endl;
    cout << "MAX_EVENTS: " << MAX_EVENTS << endl;
    cout << " - - - - - - - - - " << endl;
        
    TChain* t = new TChain("TreeMaker2/PreSelection");
    TString temp;
    std::ifstream infile("RA2b.txt");
    std::string line;
    while (std::getline(infile, line)){
        temp = line;
        if( temp.Contains(fileTag) ){
            //cout << "root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Run2ProductionV12/"<< temp << endl;
            t->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Run2ProductionV12/"+temp);
        }
    }

    assert(t->GetEntries());

    RA2bTree ntuple(t);
    TTree* cloned = t->CloneTree(0);
    int numEvents = ntuple.fChain->GetEntries();
    cout << "numEvents: " << numEvents << endl;

    for( int i = 0 ; i < min(MAX_EVENTS,numEvents) ; i++ ){
        ntuple.GetEntry(i);

        if( i % 100000 == 0 ) cout << "i: " << i << " / " << numEvents << endl;
        if( ntuple.METclean > 100. && ntuple.HTclean > 400. &&
            ntuple.Photons->size()==1 && ntuple.Photons->at(0).Pt()>100. &&
            ntuple.Photons_fullID->size() == 1 && ntuple.Photons_fullID->at(0) == 1 ) 
        cloned->Fill();
    }
    
    TFile* outputFile = new TFile(fileTag+".root","RECREATE");
    cloned->Write();
    outputFile->Close();

}
