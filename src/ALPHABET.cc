#include "TString.h"
#include "TChain.h"
#include "TH1F.h"
#include "TROOT.h"
#include "THStack.h"
#include "TPad.h"

#include <vector>
#include <map>
#include <iostream>

#include "plotterUtils.cc"
#include "skimSamples.cc"
#include "definitions.cc"
#include "RA2bTree.cc"
#include "ALPHABET.h"

using namespace std;
using namespace alphabet;

int main(int argc, char** argv){

  gROOT->ProcessLine(".L ~/tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");
  
  skimSamples skims;
  skimSamples skimsMu("root://cmseos.fnal.gov//store/user/awhitbe1/RA2bSkims_V10_v0/singleMuCR");
  typedef plot<RA2bTree> plot;

  vector<vector<plot> > plots;

  for( int i = 0 ; i < numMETbins ; i++ ) {
    TString tag="_";
    tag+=lowestMET+i*binWidth;
    vector<plot> plotsTemp;
    plotsTemp.push_back(plot(*fillLeadingJetMass<RA2bTree>,"mJ_tagSR"+tag,"m_{J} [GeV]",30,50.,200.));
    plotsTemp.push_back(plot(*fillLeadingJetMass<RA2bTree>,"mJ_tagSB"+tag,"m_{J} [GeV]",30,50.,200.));
    
    plotsTemp.push_back(plot(*fillLeadingJetMass<RA2bTree>,"mJ_antitagSR"+tag,"m_{J} [GeV]",30,50.,200.));
    plotsTemp.push_back(plot(*fillLeadingJetMass<RA2bTree>,"mJ_antitagSB"+tag,"m_{J} [GeV]",30,50.,200.));
    
    plotsTemp.push_back(plot(*fillLeadingJetMass<RA2bTree>,"mJ_doubletagSR"+tag,"m_{J} [GeV]",30,50.,200.));
    plotsTemp.push_back(plot(*fillLeadingJetMass<RA2bTree>,"mJ_doubletagSB"+tag,"m_{J} [GeV]",30,50.,200.));

    plots.push_back(plotsTemp);
  }

  // background MC samples - 0 lepton regions
  for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

    RA2bTree* ntuple = skims.ntuples[iSample];

    for( int iBin = 0 ; iBin < numMETbins ; iBin++){
      for( int iPlot = 0 ; iPlot < plots[iBin].size() ; iPlot++){
	plots[iBin][iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
	plots[iBin][iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
      }
    }

    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
        ntuple->GetEntry(iEvt);
        if( iEvt % 100000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;
        //if( iEvt > 100000 ) break;
        if(! baselineCut(ntuple) ) continue;
        //if( ntuple->BTags<1 || ntuple->DeltaPhi1<0.5 || ntuple->DeltaPhi2<0.5 || ntuple->DeltaPhi3<0.3 || ntuple->DeltaPhi4<0.3) continue;

        int bin = -1;
        for( int iBin = 0 ; iBin < numMETbins ; iBin++ ){
            if( ntuple->MET > lowestMET ){
                if( ntuple->MET > numMETbins*(binWidth-1)+lowestMET )
                    bin = numMETbins-1;
                else
                    bin = int((ntuple->MET-lowestMET)/binWidth);
            }
        }
        //cout << "MET bin: " << bin << endl;
        if( bin < 0 ) continue;
      
        if( doubleTaggingLooseCut(ntuple) ){
            double jetMass = fillLeadingJetMass(ntuple);
            if( jetMass > 85 && jetMass < 135 ){
                plots[bin][4].fill(ntuple);
            }else if( jetMass > 50 && jetMass < 200){
                plots[bin][5].fill(ntuple);
            }
        }else{
            //if( ntuple->BTags<1 || ntuple->DeltaPhi1<0.5 || ntuple->DeltaPhi2<0.5 || ntuple->DeltaPhi3<0.3 || ntuple->DeltaPhi4<0.3) continue;
            if( singleHiggsTagLooseCut(ntuple) ){
                double jetMass = fillLeadingJetMass(ntuple);
                if( jetMass > 85 && jetMass < 135 ){ 
                    plots[bin][0].fill(ntuple);
                }else if( jetMass > 50 && jetMass < 200){
                    plots[bin][1].fill(ntuple);
                }
            }
            if( antiTaggingLooseCut(ntuple) ){
                double jetMass = fillLeadingJetMass(ntuple);
                if( jetMass > 85 && jetMass < 135 ){
                    plots[bin][2].fill(ntuple);
                }else if( jetMass > 50 && jetMass < 200){
                    plots[bin][3].fill(ntuple);
                }
            }
        }
    }
  }


  // data 
  RA2bTree* ntuple = skims.dataNtuple;
  
  for( int iBin = 0 ; iBin < numMETbins ; iBin++){
      for( int iPlot = 0 ; iPlot < plots[iBin].size() ; iPlot++){
          plots[iBin][iPlot].addDataNtuple(ntuple,"data");
      }
  }

  int numEvents = ntuple->fChain->GetEntries();
  ntupleBranchStatus<RA2bTree>(ntuple);
  for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 100000 == 0 ) cout << "data: " << iEvt << "/" << numEvents << endl;
      //if( iEvt > 100000 ) break;
      if(! baselineCut(ntuple) ) continue;
      //if( ntuple->BTags<1 || ntuple->DeltaPhi1<0.5 || ntuple->DeltaPhi2<0.5 || ntuple->DeltaPhi3<0.3 || ntuple->DeltaPhi4<0.3) continue;
      
      int bin = -1;
      for( int iBin = 0 ; iBin < numMETbins ; iBin++ ){
          if( ntuple->MET > lowestMET ){
              if( ntuple->MET > lowestMET+binWidth*(numMETbins-1) )
                  bin = numMETbins-1;
              else
                  bin = int((ntuple->MET-lowestMET)/binWidth);
          }
      }
      //cout << "MET bin: " << bin << endl;
      if( bin < 0 ) continue;
      
      if( doubleTaggingLooseCut(ntuple) ){
          double jetMass = fillLeadingJetMass(ntuple);
          if( jetMass > 85 && jetMass < 135 ){
              plots[bin][4].fillData(ntuple);
          }else if( jetMass > 50 && jetMass < 200){
              plots[bin][5].fillData(ntuple);
          }
      }else{
          //if( ntuple->BTags<1 || ntuple->DeltaPhi1<0.5 || ntuple->DeltaPhi2<0.5 || ntuple->DeltaPhi3<0.3 || ntuple->DeltaPhi4<0.3) continue;
          if( singleHiggsTagLooseCut(ntuple) ){
              double jetMass = fillLeadingJetMass(ntuple);
              if( jetMass > 85 && jetMass < 135 ){ 
                  plots[bin][0].fillData(ntuple);
              }else if( jetMass > 50 && jetMass < 200){
                  plots[bin][1].fillData(ntuple);
              }
          }
          if( antiTaggingLooseCut(ntuple) ){
              double jetMass = fillLeadingJetMass(ntuple);
              if( jetMass > 85 && jetMass < 135 ){
                  plots[bin][2].fillData(ntuple);
              }else if( jetMass > 50 && jetMass < 200){
                  plots[bin][3].fillData(ntuple);
              }
          }
      }
  }

  

  TFile* outputFile = new TFile("ALPHABEThistos.root","RECREATE");
  for( int iBin = 0 ; iBin < numMETbins; iBin++){
      for( int iPlot = 0 ; iPlot < plots[iBin].size() ; iPlot++){
          outputFile->cd();
          plots[iBin][iPlot].Write();
          plots[iBin][iPlot].buildSum();
          plots[iBin][iPlot].sum->Write();
      }
  }
  outputFile->Close();

}
