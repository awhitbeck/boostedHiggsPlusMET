#include "TChain.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TString.h"
#include "TLine.h"
#include "CMS_lumi.cc"

#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char** argv){

  int eraIndex = 0;
  if( argc > 1 )
    eraIndex = atoi(argv[1]);

  TString dir = "../plots/noisyForwardJets/";

  TChain* t = new TChain("tree");
  enum eras {k2016,k2017,k2018,k2016_LDP,k2017_LDP,k2018_LDP,kNumEras};
  vector<TString> era_labels={"era2016","era2017","era2018","era2016_LDP","era2017_LDP","era2018_LDP"};
  eras era = eras(eraIndex);

  if( era == k2016 ){
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_signal/tree_MET_re2016B.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_signal/tree_MET_re2016C.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_signal/tree_MET_re2016D.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_signal/tree_MET_re2016E.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_signal/tree_MET_re2016F.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_signal/tree_MET_re2016H2.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_signal/tree_MET_re2016H3.root");
  }
  if( era == k2016_LDP ){
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_LDP/tree_MET_2016B.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_LDP/tree_MET_2016C.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_LDP/tree_MET_2016D.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_LDP/tree_MET_2016E.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_LDP/tree_MET_2016F.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_LDP/tree_MET_2016H.root");
  }

  if( era == k2017 ){
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_signal/tree_MET_2017B.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_signal/tree_MET_2017C.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_signal/tree_MET_2017D.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_signal/tree_MET_2017E.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_signal/tree_MET_2017F.root");
  }
  if( era == k2017_LDP ){
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_LDP/tree_MET_2017B.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_LDP/tree_MET_2017C.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_LDP/tree_MET_2017D.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_LDP/tree_MET_2017E.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_LDP/tree_MET_2017F.root");
  }

  if( era == k2018 ){
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_signal/tree_MET_2018A1.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_signal/tree_MET_2018A2.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_signal/tree_MET_2018A3.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_signal/tree_MET_2018B1.root");
  }
  if( era == k2018_LDP ){
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_LDP/tree_MET_2018A1.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_LDP/tree_MET_2018A2.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_LDP/tree_MET_2018A3.root");
    t->Add("/Users/whitbeck/CMSanalysis/RA2bSkims2016/tree_LDP/tree_MET_2018B1.root");
  }

  cout << "entries: " << t->GetEntries() << endl;

  gROOT->SetBatch(true);
  gROOT->ProcessLine(".L ~/tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");
  TCanvas* can = new TCanvas("can","can",700,500);
  can->SetRightMargin(0.2);
  can->SetTopMargin(0.075);
  can->SetLogz();

  t->SetAlias("METfilters","globalTightHalo2016Filter==1 && HBHENoiseFilter==1 && HBHEIsoNoiseFilter==1 && eeBadScFilter==1 && EcalDeadCellTriggerPrimitiveFilter==1 && BadChargedCandidateFilter && BadPFMuonFilter && NVtx > 0");
  if( era == k2016 || era == k2016_LDP )
    t->SetAlias("SignalTrigger","TriggerPass[42]==1 || TriggerPass[43]==1 || TriggerPass[44]==1 || TriggerPass[45]==1 || TriggerPass[46]==1 || TriggerPass[47]==1 || TriggerPass[48]==1 || TriggerPass[49]==1");
  if( era == k2017 || era == k2018 || era == k2017_LDP || era == k2018_LDP )
    t->SetAlias("SignalTrigger","TriggerPass[108]==1 || TriggerPass[110]==1 || TriggerPass[114]==1 || TriggerPass[116]==1 || TriggerPass[118]==1 || TriggerPass[122]==1 || TriggerPass[124]==1 || TriggerPass[126]==1 || TriggerPass[129]==1 || TriggerPass[131]==1 || TriggerPass[133]==1 || TriggerPass[134]==1");



  TLine* l = new TLine(.9,.5,.1,3.0);
  l->SetLineColor(2);
  l->SetLineWidth(4);
  l->Draw();

  writeExtraText = true;
  extraText="Preliminary";
  if( era == k2016 )
    lumi_13TeV = "36.9 fb^{-1}";
  else if( era == k2017 )
    lumi_13TeV = "4X.X fb^{-1}";
  else if( era == k2018 )
    lumi_13TeV = "XX.X fb^{-1}";
  cout << "Drawing: dphi_jetEta" << endl;
  TH2F* dphi_jetEta = new TH2F("dphi_jetEta",";#eta_{j1};#Delta#Phi_{1}",100,-5.,5.,100,0.,3.2);
  t->Draw("DeltaPhi1:Jets[0].Eta()>>dphi_jetEta","SignalTrigger==1&&METfilters==1","colz");
  dphi_jetEta->Draw("colz");
  CMS_lumi( can , 4 , 0 );
  can->Update();
  can->RedrawAxis();
  can->GetFrame()->Draw();
  can->SaveAs(dir+"dphi_jetEta"+era_labels[era]+".png");

  cout << "Drawing: dphi_htOverht5" << endl;
  TH2F* dphi_htOverht5 = new TH2F("dphi_htOverht5",";HT/HT5;#Delta#Phi_{1}",100,0.,1.,100,0.,3.2);
  t->Draw("DeltaPhi1:HT/HT5>>dphi_htOverht5","SignalTrigger==1&&METfilters==1","colz");
  dphi_htOverht5->Draw("colz");
  //l->Draw();
  CMS_lumi( can , 4 , 0 );
  can->Update();
  can->RedrawAxis();
  can->GetFrame()->Draw();
  can->SaveAs(dir+"dphi_htOverht5"+era_labels[era]+".png");

  cout << "Drawing: dphi_ht5Overht" << endl;
  TH2F* dphi_ht5Overht = new TH2F("dphi_ht5Overht",";HT5/HT;#Delta#Phi_{1}",100,1.,4.,100,0.,3.2);
  t->Draw("DeltaPhi1:HT5/HT>>dphi_ht5Overht","SignalTrigger==1&&METfilters==1","colz");
  dphi_ht5Overht->Draw("colz");
  CMS_lumi( can , 4 , 0 );
  can->Update();
  can->RedrawAxis();
  can->GetFrame()->Draw();
  can->SaveAs(dir+"dphi_ht5Overht"+era_labels[era]+".png");

  cout << "Drawing: dphi_jetEta_htOverht5_0p5" << endl;
  TH2F* dphi_jetEta_htOverht5_0p5 = new TH2F("dphi_jetEta_htOverht5_0p5",";#eta_{j1};#Delta#Phi_{1}",100,-5.,5.,100,0.,3.2);
  t->Draw("DeltaPhi1:Jets[0].Eta()>>dphi_jetEta_htOverht5_0p5","SignalTrigger==1&&METfilters==1&&HT/HT5>0.5","colz");
  dphi_jetEta_htOverht5_0p5->Draw("colz");
  CMS_lumi( can , 4 , 0 );
  can->Update();
  can->RedrawAxis();
  can->GetFrame()->Draw();
  can->SaveAs(dir+"dphi_jetEta_htOverht5_0p5"+era_labels[era]+".png");

  cout << "Drawing: dphi_jetEta_htOverht5_0p6" << endl;
  TH2F* dphi_jetEta_htOverht5_0p6 = new TH2F("dphi_jetEta_htOverht5_0p6",";#eta_{j1};#Delta#Phi_{1}",100,-5.,5.,100,0.,3.2);
  t->Draw("DeltaPhi1:Jets[0].Eta()>>dphi_jetEta_htOverht5_0p6","SignalTrigger==1&&METfilters==1&&HT/HT5>0.6","colz");
  dphi_jetEta_htOverht5_0p6->Draw("colz");
  CMS_lumi( can , 4 , 0 );
  can->Update();
  can->RedrawAxis();
  can->GetFrame()->Draw();
  can->SaveAs(dir+"dphi_jetEta_htOverht5_0p6"+era_labels[era]+".png");

  cout << "Drawing: dphi_jetEta_htOverht5_line" << endl;
  TH2F* dphi_jetEta_htOverht5_line = new TH2F("dphi_jetEta_htOverht5_line",";#eta_{j1};#Delta#Phi_{1}",100,-5.,5.,100,0.,3.2);
  t->Draw("DeltaPhi1:Jets[0].Eta()>>dphi_jetEta_htOverht5_line","SignalTrigger==1&&METfilters==1&&(DeltaPhi1>(3.0+2.5/8-25/8*HT/HT5))","colz");
  dphi_jetEta_htOverht5_line->Draw("colz");
  CMS_lumi( can , 4 , 0 );
  can->Update();
  can->RedrawAxis();
  can->GetFrame()->Draw();
  can->SaveAs(dir+"dphi_jetEta_htOverht5_line"+era_labels[era]+".png");

  cout << "Drawing: htOverht5_forwardJetNeutHadFrac" << endl;
  TH2F* htOverht5_forwardJetNeutHadFrac = new TH2F("htOverht5_forwardJetNeutHadFrac",";Jet Neut. Had. Frac.;HT/HT5",100,0.,1.,100,0.5,1.);
  t->Draw("HT/HT5:Jets_neutralHadronEnergyFraction[0]>>htOverht5_forwardJetNeutHadFrac","SignalTrigger==1&&METfilters==1&&fabs(Jets[0].Eta())>3.0","colz");
  htOverht5_forwardJetNeutHadFrac->Draw("colz");
  CMS_lumi( can , 4 , 0 );
  can->Update();
  can->RedrawAxis();
  can->GetFrame()->Draw();
  can->SaveAs(dir+"htOverht5_forwardJetNeutHadFrac_"+era_labels[era]+".png");

  cout << "Drawing: htOverht5_forwardJetNeutEmFrac" << endl;
  TH2F* htOverht5_forwardJetNeutEmFrac = new TH2F("htOverht5_forwardJetNeutEmFrac",";Jet Neut. Had. Frac.;HT/HT5",100,0.,1.,100,0.5,1.);
  t->Draw("HT/HT5:Jets_neutralEmEnergyFraction[0]>>htOverht5_forwardJetNeutEmFrac","SignalTrigger==1&&METfilters==1&&fabs(Jets[0].Eta())>3.0","colz");
  htOverht5_forwardJetNeutEmFrac->Draw("colz");
  CMS_lumi( can , 4 , 0 );
  can->Update();
  can->RedrawAxis();
  can->GetFrame()->Draw();
  can->SaveAs(dir+"htOverht5_forwardJetNeutEmFrac_"+era_labels[era]+".png");
}
