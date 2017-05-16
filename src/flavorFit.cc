// ROOT libraries
#include "TFile.h"
#include "TROOT.h"
#include "TH1F.h"
#include "THStack.h"
#include "RooRealVar.h"
#include "RooDataHist.h"
#include "RooHistPdf.h"
#include "RooAddPdf.h"
#include "RooPlot.h"
#include "TCanvas.h"

// STL libraries
#include <iostream>

using namespace RooFit;
using namespace std;

int main( int argc , char** argv ){

     ///////////////////////////////////////////////////////////
     // - - - - - - - - - options - - - - - - - - - -         //
     //     argument 1 - region (photon, singleMuCR, lowDPhi) //
     //     argument 2 - jet (0: leadJet, 1: subleadJet)      //
     // - - - - - - - - - - - - - - - - - - - - - - -         //
     ///////////////////////////////////////////////////////////

    assert( argc == 3 );
    int jetNum = atoi(argv[2]);
    TString region = "";
    region += argv[1];

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    //enum jets {kLead,kSublead,kNumJets};
    TString jetLabel[2] = {"J1pt","J2pt"};
   
    TFile* inputFile = new TFile("plotObs_"+region+"_baseline.root");
    TH1F *MC0b,*MC1b,*MC2b,*data;
    MC0b = (TH1F*) inputFile->Get(jetLabel[jetNum]+"_BBtag_"+region+"_NbHad0_sum");
    MC1b = (TH1F*) inputFile->Get(jetLabel[jetNum]+"_BBtag_"+region+"_NbHad1_sum");
    MC2b = (TH1F*) inputFile->Get(jetLabel[jetNum]+"_BBtag_"+region+"_NbHad2_sum");
    data = (TH1F*) inputFile->Get(jetLabel[jetNum]+"_BBtag_"+region+"_NbHad0_data");

    cout << " - - - - - - - - - - - - - - - " << endl;
    cout << " before fits:" << endl;
    cout << " - - - - - - - - - - - - - - - " << endl;
    cout << " 0b frac: " << MC0b->Integral()/(MC0b->Integral()+MC1b->Integral()+MC2b->Integral()) << endl;
    cout << " 1b frac: " << MC1b->Integral()/(MC0b->Integral()+MC1b->Integral()+MC2b->Integral()) << endl;
    cout << " 2b frac: " << MC2b->Integral()/(MC0b->Integral()+MC1b->Integral()+MC2b->Integral()) << endl;
    cout << " - - - - - - - - - - - - - - - " << endl;

    MC0b->Scale(1./MC0b->Integral());
    MC1b->Scale(1./MC1b->Integral());
    MC2b->Scale(1./MC2b->Integral());

    MC0b->SetFillColor(kBlue);
    MC0b->SetFillStyle(1);
    MC1b->SetFillColor(kCyan);
    MC1b->SetFillStyle(1);
    MC2b->SetFillColor(kMagenta);
    MC2b->SetFillStyle(1);

    RooRealVar* bbDisc = new RooRealVar("bbDisc","bb-disc",0.,-1.,1.);

    RooDataHist* MC0b_rdh = new RooDataHist("MC0b_rdh","MC0b_rdh",RooArgList(*bbDisc),MC0b);
    RooDataHist* MC1b_rdh = new RooDataHist("MC1b_rdh","MC1b_rdh",RooArgList(*bbDisc),MC1b);
    RooDataHist* MC2b_rdh = new RooDataHist("MC2b_rdh","MC2b_rdh",RooArgList(*bbDisc),MC2b);
    RooDataHist* data_rdh = new RooDataHist("data_rdh","data_rdh",RooArgList(*bbDisc),data);

    RooHistPdf* MC0b_rhp = new RooHistPdf("MC0b_rhp","MC0b_rhp",RooArgSet(*bbDisc),*MC0b_rdh);
    RooHistPdf* MC1b_rhp = new RooHistPdf("MC1b_rhp","MC0b_rhp",RooArgSet(*bbDisc),*MC1b_rdh);
    RooHistPdf* MC2b_rhp = new RooHistPdf("MC2b_rhp","MC0b_rhp",RooArgSet(*bbDisc),*MC2b_rdh);
    RooHistPdf* data_rhp = new RooHistPdf("data_rhp","MC0b_rhp",RooArgSet(*bbDisc),*data_rdh);
    
    RooRealVar* N0b = new RooRealVar("N0b","N0b",1.,0.,1000000.);
    RooRealVar* N1b = new RooRealVar("N1b","N1b",1.,0.,1000000.);
    RooRealVar* N2b = new RooRealVar("N2b","N2b",1.,0.,1000000.);

    RooAddPdf* model = new RooAddPdf("model","model",RooArgList(*MC0b_rhp,*MC1b_rhp,*MC2b_rhp),RooArgList(*N0b,*N1b,*N2b));

    model->fitTo(*data_rdh);

    cout << " - - - - - - - - - - - - - - - " << endl;
    cout << " after fits:" << endl;
    cout << " - - - - - - - - - - - - - - - " << endl;
    cout << " 0b frac: " << N0b->getVal()/(N0b->getVal()+N1b->getVal()+N2b->getVal()) << endl;
    cout << " 1b frac: " << N1b->getVal()/(N0b->getVal()+N1b->getVal()+N2b->getVal()) << endl;
    cout << " 2b frac: " << N2b->getVal()/(N0b->getVal()+N1b->getVal()+N2b->getVal()) << endl;
    cout << " - - - - - - - - - - - - - - - " << endl;

    TCanvas* can = new TCanvas("can","can",500,500);

    THStack* stack = new THStack("stack","stack");
    MC0b->Scale(N0b->getVal());
    stack->Add(MC0b);
    MC1b->Scale(N1b->getVal());
    stack->Add(MC1b);
    MC2b->Scale(N2b->getVal());
    stack->Add(MC2b);

    stack->Draw("hist");
    data->SetMarkerStyle(8);
    data->Draw("SAME,e1");
    can->SaveAs("flavorFit_"+region+"_"+jetLabel[jetNum]+".png");

}
