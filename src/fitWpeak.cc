// ROOT libraries
#include "CMS_lumi.cc"
#include "TFile.h"
#include "TROOT.h"
#include "TH1F.h"
#include "THStack.h"
#include "RooRealVar.h"
#include "RooDataHist.h"
#include "RooHistPdf.h"
#include "RooAddPdf.h"
#include "RooPlot.h"
#include "RooGaussian.h"
#include "RooBernstein.h"
#include "TCanvas.h"

// STL libraries
#include <iostream>
#include <cassert>

using namespace RooFit;
using namespace std;

int main( int argc , char** argv ){

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    assert(argc>1);
    bool fitData = atoi(argv[1]);

    TFile* inputFile = new TFile("WtaggingEff_singleMuCR.root");
    TH1F *tagMC, *noTagMC, *data;
    tagMC = (TH1F*) inputFile->Get("J1M_WtaggingEff_tag_TT");
    tagMC->SetFillColor(kMagenta);
    noTagMC = (TH1F*) inputFile->Get("J1M_WtaggingEff_noTag_sum");
    noTagMC->SetFillColor(kTeal);
    if( fitData ){
        data = (TH1F*) inputFile->Get("J1M_WtaggingEff_noTag_data");
        data->SetNameTitle("data","data");
    }else{
        data = (TH1F*) inputFile->Get("J1M_WtaggingEff_noTag_sum");
        data->SetNameTitle("data","data");
        data->Add((TH1F*)inputFile->Get("J1M_WtaggingEff_tag_sum"));
    }

    RooRealVar* jetMass = new RooRealVar("jetMass","m_{J} [GeV]",100.,40.,140.);

    RooDataHist* tagMC_rdh = new RooDataHist("tagMC_rdh","tagMC_rdh",RooArgList(*jetMass),tagMC);
    RooDataHist* noTagMC_rdh = new RooDataHist("noTagMC_rdh","noTagMC_rdh",RooArgList(*jetMass),noTagMC);
    RooDataHist* data_rdh = new RooDataHist("data_rdh","data_rdh",RooArgList(*jetMass),data);

    data->Rebin(2);
    tagMC->Rebin(2);
    noTagMC->Rebin(2);
    RooDataHist* data2_rdh = new RooDataHist("data_rdh","data_rdh",RooArgList(*jetMass),data);
  
    RooHistPdf* tagMC_rhp = new RooHistPdf("tagMC_rhp","tagMC_rhp",RooArgSet(*jetMass),*tagMC_rdh);
    RooHistPdf* noTagMC_rhp = new RooHistPdf("noTagMC_rhp","noTagMC_rhp",RooArgSet(*jetMass),*noTagMC_rdh);
        
    RooRealVar* sigNorm = new RooRealVar("sigFrac","sigFrac",100.,0.,10000000.);
    RooRealVar* bkgNorm = new RooRealVar("bkgFrac","bkdFrac",100.,0.,10000000.);
    
    RooRealVar* p1 = new RooRealVar("p1","p1",0.5,0.0,1.0);
    RooRealVar* p2 = new RooRealVar("p2","p2",0.5,0.0,1.0);
    RooRealVar* p3 = new RooRealVar("p3","p3",0.5,0.0,1.0);
    RooRealVar* p4 = new RooRealVar("p4","p4",0.5,0.0,1.0);
    RooBernstein* poly = new RooBernstein("poly","poly",*jetMass,RooArgList(*p1,*p2,*p3,*p4));

    RooRealVar* mean = new RooRealVar("mean","mean",80.,60.,100.);
    RooRealVar* sigma = new RooRealVar("sigma","sigma",8.,0.,20.);
    RooGaussian* gauss = new RooGaussian("gauss","gauss",*jetMass,*mean,*sigma);

    RooAddPdf* model = new RooAddPdf("model","model",RooArgList(*gauss,*poly),RooArgList(*sigNorm,*bkgNorm));

    model->fitTo(*data_rdh);

    TCanvas* can = new TCanvas("can","can",500,500);

    RooPlot* plot = jetMass->frame();
    data2_rdh->plotOn(plot);
    model->plotOn(plot,RooFit::Components("poly"),RooFit::LineStyle(kDashed));
    model->plotOn(plot);
    
    THStack* stack = new THStack("stack","stack");
    double MCint = noTagMC->Integral() + tagMC->Integral();
    noTagMC->Scale(data->Integral()/MCint);
    tagMC->Scale(data->Integral()/MCint);
    stack->Add(noTagMC);
    stack->Add(tagMC);
    stack->Draw("histo");
    plot->Draw("SAME");

    stack->GetXaxis()->SetTitle("m_{J} [GeV]");
    stack->GetYaxis()->SetTitle("Events");
    stack->GetYaxis()->SetRangeUser(0.,data->GetMaximum()*1.5);
    
    writeExtraText=true;
    extraText="Preliminary";
    lumi_13TeV="35.9 fb^{-1}";
    CMS_lumi(can,4,0);
    can->Update();
    can->RedrawAxis();
    can->GetFrame()->Draw();

    if( fitData )
        can->SaveAs("fitWpeak_data.png");
    else 
        can->SaveAs("fitWpeak_MC.png");
}
        
