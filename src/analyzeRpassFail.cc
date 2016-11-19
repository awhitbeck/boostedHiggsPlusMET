#include "TVirtualFitter.h"
#include "TF1.h"
#include "TFile.h"
#include "TString.h"
#include "TCanvas.h"
#include "TH1F.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <assert.h>
#include "TLegend.h"
#include "TROOT.h"

#include "ALPHABET.h"

using namespace std;
using namespace alphabet;

int main(int argc, char** argv){

    gROOT->SetBatch(true);
    gROOT->ProcessLine(".L ~/tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    ////////////////////////////////////////////////////////////////////////
    // - - - - - - - - - - - - input configuration - - - - - - - - - - -  //
    ////////////////////////////////////////////////////////////////////////
    TString s("sum");
    double yMax(0.2);
    if( argc >= 3 )
        yMax = atof(argv[2]);
    if( argc >= 2 )
        s = argv[1];

    cout << "s: " << s << endl;
    cout << "yMax: " << yMax << endl;
    assert(s=="data" || s=="TT" || s=="WJets" || s=="ZJets" || s=="QCD" || s=="sum");
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    TFile* inputFile = new TFile("ALPHABEThistos.root","read");
    
    TCanvas* can_rpf_double = new TCanvas("can_rpf_double","can_rpf_double",500,500);
    //can_rpf_double->Divide(6,1);

    vector<TH1F*> SRdouble;
    vector<TH1F*> SBdouble;
    vector<TH1F*> SRanti;
    vector<TH1F*> SBanti;
    vector<TH1F*> ratioSRdouble;
    vector<TH1F*> ratioSBdouble;
    vector<TH1F*> ratio;
    vector<double> SRdoubleError,SRdoubleInt;
    vector<double> SBdoubleError,SBdoubleInt;
    vector<double> SRantiError,SRantiInt;
    vector<double> SBantiError,SBantiInt;
    vector<double> Pred,MCexp;
    vector<double> PredError,MCexpError;

    TLegend* leg = new TLegend(0.6,0.75,0.9,0.9);
    leg->SetBorderSize(0);
    leg->SetFillColor(0);
    bool first=true;

    cout << "//////////////////////////////////////////////////" << endl;
    cout << "// - - - - - - - - closure test - - - - - - - - //" << endl;
    cout << "//////////////////////////////////////////////////" << endl;         
    cout << "A = antitag sideband" << endl;
    cout << "B = antitag mass window" << endl;
    cout << "C = double-tag sideband" << endl;
    cout << "D = double-tag mass window (signal region)" << endl;

    bool aggregate=true;

    for( int bin  = int(lowestMET) ; bin <= lowestMET+binWidth*(numMETbins-1) ; bin+=binWidth){

        TString b = "";
        b+=bin;

        SRdouble.push_back(new TH1F(*((TH1F*)inputFile->Get("mJ_doubletagSR_"+b+"_"+s))));
        SRdouble.back()->SetNameTitle("SRdouble_"+b+"_"+s,"SRdouble_"+b+"_"+s);
        SBdouble.push_back(new TH1F(*((TH1F*)inputFile->Get("mJ_doubletagSB_"+b+"_"+s))));
        SBdouble.back()->SetNameTitle("SBdouble_"+b+"_"+s,"SBdouble_"+b+"_"+s);

        SRanti.push_back(new TH1F(*((TH1F*)inputFile->Get("mJ_antitagSR_"+b+"_"+s))));
        SRanti.back()->SetNameTitle("SRanti_"+b+"_"+s,"SRanti_"+b+"_"+s);
        SBanti.push_back(new TH1F(*((TH1F*)inputFile->Get("mJ_antitagSB_"+b+"_"+s))));
        SBanti.back()->SetNameTitle("SBanti_"+b+"_"+s,"SBanti_"+b+"_"+s);

        if( aggregate && SRdouble.size() > 1 ){
            SBdouble[0]->Add(SBdouble.back());
            SBanti[0]->Add(SBanti.back());
            SRdouble[0]->Add(SRdouble.back());
            SRanti[0]->Add(SRanti.back());
        }

        ratioSRdouble.push_back(new TH1F(*((TH1F*)inputFile->Get("mJ_doubletagSR_"+b+"_"+s))));
        ratioSRdouble.back()->SetNameTitle("ratioSRdouble_"+b+"_"+s,"ratioSRdouble_"+b+"_"+s);
        ratioSRdouble.back()->Divide((TH1F*)inputFile->Get("mJ_antitagSR_"+b+"_"+s));
        ratioSRdouble.back()->SetMarkerStyle(8);
        ratioSRdouble.back()->SetMarkerColor((bin/100)%6);
        
        ratioSBdouble.push_back(new TH1F(*(TH1F*)inputFile->Get("mJ_doubletagSB_"+b+"_"+s)));
        ratioSBdouble.back()->SetNameTitle("ratioSBdouble_"+b+"_"+s,"ratioSBdouble_"+b+"_"+s);
        ratioSBdouble.back()->Divide((TH1F*)inputFile->Get("mJ_antitagSB_"+b+"_"+s));
        ratioSBdouble.back()->SetMarkerStyle(4);
        ratioSBdouble.back()->SetMarkerColor((bin/100)%6);

        ratio.push_back(new TH1F(*ratioSRdouble.back()));
        ratio.back()->SetNameTitle("ratio_MET"+b,"ratio_MET"+b);
        ratio.back()->Add(ratioSBdouble.back());

        ratio.back()->GetYaxis()->SetTitle("R_{p/f}");
        ratio.back()->GetXaxis()->SetTitle("m_{J} [GeV]");
        ratio.back()->GetYaxis()->SetRangeUser(0.,yMax);
        ratio.back()->GetYaxis()->SetNdivisions(504);

        SBantiError.push_back(0.);
        SBantiInt.push_back(SBanti.back()->IntegralAndError(1,SBanti.back()->GetNbinsX(),SBantiError.back()));
        SRantiError.push_back(0.);
        SRantiInt.push_back(SRanti.back()->IntegralAndError(1,SRanti.back()->GetNbinsX(),SRantiError.back()));
        SBdoubleError.push_back(0.);
        SBdoubleInt.push_back(SBdouble.back()->IntegralAndError(1,SBdouble.back()->GetNbinsX(),SBdoubleError.back()));
        SRdoubleError.push_back(0.);
        SRdoubleInt.push_back(SRdouble.back()->IntegralAndError(1,SRdouble.back()->GetNbinsX(),SRdoubleError.back()));
        
        // using "B/A" from corresponding MET bin:
        Pred.push_back(SBdoubleInt.back()*(SRantiInt.back()/SBantiInt.back()));
        PredError.push_back(SBdoubleInt.back()*(SRantiInt.back()/SBantiInt.back())*sqrt(SBdoubleError.back()*SBdoubleError.back()/SBdoubleInt.back()/SBdoubleInt.back()+SRantiError.back()*SRantiError.back()/SRantiInt.back()/SRantiInt.back()+SBantiError.back()*SBantiError.back()/SBantiInt.back()/SBantiInt.back()));

        MCexp.push_back(SRdoubleInt.back());
        MCexpError.push_back(SRdoubleError.back());

        ratio.back()->Rebin(2);

        if(first){
            first=false;
            ratio.back()->Draw();
        }else
            ratio.back()->Draw("SAME");

        leg->AddEntry(ratio.back(),"MET_"+b,"p");
    }

    if( aggregate ){
        ratioSBdouble[0]->SetMarkerColor(1);
        ratioSRdouble[0]->SetMarkerColor(1);
        ratioSBdouble[0] = new TH1F(*ratioSBdouble[0]);
        ratioSRdouble[0] = new TH1F(*ratioSRdouble[0]);
 

        ratio[0] = new TH1F(*ratioSRdouble[0]);
        ratio[0]->SetNameTitle("ratio_MET_all","ratio_MET_all");
        ratio[0]->Add(ratioSBdouble[0]);

        ratio[0]->GetYaxis()->SetTitle("R_{p/f}");
        ratio[0]->GetXaxis()->SetTitle("m_{J} [GeV]");
        ratio[0]->GetYaxis()->SetRangeUser(0.,yMax);
        ratio[0]->GetYaxis()->SetNdivisions(505);

        ratio[0]->Draw();

        can_rpf_double->SaveAs("../plots/ALPHABET/ALPHABET_"+TString(s)+"_rpf_double_intMET.png");
        can_rpf_double->SaveAs("../plots/ALPHABET/ALPHABET_"+TString(s)+"_rpf_double_intMET.eps");
        can_rpf_double->SaveAs("../plots/ALPHABET/ALPHABET_"+TString(s)+"_rpf_double_intMET.pdf");
        return 0;
    }
    
    leg->Draw();

    can_rpf_double->SaveAs("../plots/ALPHABET/ALPHABET_"+TString(s)+"_rpf_double_allMET.png");
    can_rpf_double->SaveAs("../plots/ALPHABET/ALPHABET_"+TString(s)+"_rpf_double_allMET.eps");
    can_rpf_double->SaveAs("../plots/ALPHABET/ALPHABET_"+TString(s)+"_rpf_double_allMET.pdf");

    cout << " & A & B & C & D & Pred. & MC Exp \\\\ \\hline \\hline" << endl;
    for( int i = 0 ; i < numMETbins ; i++ ){
        cout << "MET " << lowestMET+i*binWidth ;
        cout << " & " << std::setprecision(4) << SBantiInt[i] << " $\\pm$ " << std::setprecision(2) << SBantiError[i] ;
        cout << " & " << std::setprecision(4) << SRantiInt[i] << " $\\pm$ " << std::setprecision(2) << SRantiError[i] ;
        cout << " & " << std::setprecision(4) << SBdoubleInt[i] << " $\\pm$ " << std::setprecision(2) << SBdoubleError[i] ;
        cout << " & " << std::setprecision(4) << SRdoubleInt[i] << " $\\pm$ " << std::setprecision(2) << SRdoubleError[i] ;
        cout << " & " << std::setprecision(4) << Pred[i] << " $\\pm$ " << std::setprecision(2) << PredError[i] ;
        cout << " & " << std::setprecision(4) << MCexp[i] << " $\\pm$ " << std::setprecision(2) << MCexpError[i] << " \\\\ \\hline" << endl;
    }
    
    return 0;
}
