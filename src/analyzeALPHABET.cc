#include "TVirtualFitter.h"
#include "TF1.h"
#include "TFile.h"
#include "TString.h"
#include "TCanvas.h"
#include "TH1F.h"
#include <vector>
#include <iostream>
#include "TLegend.h"
#include "TROOT.h"

using namespace std;

int main(int argc, char** argv){

    gROOT->SetBatch(true);
    gROOT->ProcessLine(".L ~/tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    TFile* inputFile = new TFile("ALPHABEThistos.root","read");
    
    TString samples[5] = {"TT","WJets","ZJets","QCD","sum"};

    TCanvas* can_doubletag = new TCanvas("can_doubleTag","can_doubletag",1500,300);
    can_doubletag->Divide(5,1);
    
    TCanvas* can_antitag = new TCanvas("can_antiTag","can_antitag",1500,300);
    can_antitag->Divide(5,1);

    TCanvas* can_rpf = new TCanvas("can_rpf","can_rpf",1500,300);
    can_rpf->Divide(5,1);
    
    TCanvas* can_closure = new TCanvas("can_closure","can_closure",500,500);
    //can_closure->Divide(5,1);

    vector<TF1*> func;//TF1("func","[0]+[1]*x",50.,200.)
    vector<TLegend*> leg;
    vector<TH1F*> res;
    vector<TH1F*> est;
    vector<TH1F*> SRdouble;
    vector<TH1F*> SBdouble;
    vector<TH1F*> SRanti;
    vector<TH1F*> SBanti;
    vector<TH1F*> ratioSR;
    vector<TH1F*> ratioSB;

    for( int bin  = 300 ; bin <= 500 ; bin+=100){

        TString b = "";
        b+=bin;

        for( int i = 0 ; i < 5 ; i++ ){
            TString s = samples[i];
            func.push_back(new TF1("func_"+b+"_"+s,"[0]+[1]*x",50.,200.));
            cout << "mJ_doubletagSR_"+b+"_"+s << endl;
            ratioSR.push_back(new TH1F(*((TH1F*)inputFile->Get("mJ_doubletagSR_"+b+"_"+s))));
            ratioSR.back()->SetNameTitle("ratioSR_"+b+"_"+s,"ratioSR_"+b+"_"+s);
            ratioSR.back()->Divide((TH1F*)inputFile->Get("mJ_antitagSR_"+b+"_"+s));
            ratioSR.back()->SetMarkerStyle(8);
        
            ratioSB.push_back(new TH1F(*(TH1F*)inputFile->Get("mJ_doubletagSB_"+b+"_"+s)));
            ratioSB.back()->SetNameTitle("ratioSB_"+b+"_"+s,"ratioSB_"+b+"_"+s);
            ratioSB.back()->Divide((TH1F*)inputFile->Get("mJ_antitagSB_"+b+"_"+s));
            ratioSB.back()->SetMarkerStyle(4);

            ratioSB.back()->Fit("func_"+b+"_"+s,"R");
            //TVirtualFitter* fitter = TVirtualFitter.GetFitter();;
            res.push_back(new TH1F(*ratioSB.back()));
            res.back()->SetNameTitle("res_"+b+"_"+s,"res_"+b+"_"+s);
            (TVirtualFitter::GetFitter())->GetConfidenceIntervals(res.back(),.68);

            ratioSR.back()->GetYaxis()->SetTitle("R_{p/f}");
            ratioSR.back()->GetXaxis()->SetTitle("m_{J} [GeV]");
            ratioSR.back()->GetYaxis()->SetRangeUser(0.,0.25);

            can_rpf->cd()   ;
            can_rpf->cd(i+1);
            ratioSR.back()->Draw();
            ratioSB.back()->Draw("SAME");
        
            leg.push_back(new TLegend(0.6,0.75,0.9,0.9,s));
            leg.back()->SetBorderSize(0);
            leg.back()->SetFillColor(0);
            leg.back()->Draw();

            can_doubletag->cd();
            can_doubletag->cd(i+1);
            SRdouble.push_back(new TH1F(*(TH1F*)inputFile->Get("mJ_doubletagSR_"+b+"_"+s)));
            SRdouble.back()->SetNameTitle("SRdouble_"+b+"_"+s,"SRdouble_"+b+"_"+s);
            SRdouble.back()->SetMarkerStyle(8)        ;
            SBdouble.push_back(new TH1F(*(TH1F*)inputFile->Get("mJ_doubletagSB_"+b+"_"+s)));
            SBdouble.back()->SetNameTitle("SBdouble_"+b+"_"+s,"SBdouble_"+b+"_"+s);
            SBdouble.back()->SetMarkerStyle(8);
            SBdouble.back()->Draw();
            SRdouble.back()->Draw("SAME");

            can_antitag->cd();
            can_antitag->cd(i+1);
            SRanti.push_back(new TH1F(*(TH1F*)inputFile->Get("mJ_antitagSR_"+b+"_"+s)));
            SRanti.back()->SetNameTitle("SRanti_"+b+"_"+s,"SRanti_"+b+"_"+s);
            SRanti.back()->SetMarkerStyle(8);
            SBanti.push_back(new TH1F(*(TH1F*)inputFile->Get("mJ_antitagSB_"+b+"_"+s)));
            SBanti.back()->SetNameTitle("SBanti_"+b+"_"+s,"SBanti_"+b+"_"+s);
            SBanti.back()->SetMarkerStyle(8);
            SBanti.back()->Draw();
            SRanti.back()->Draw("SAME");

            can_closure->cd();
            can_closure->cd(i+1);
            est.push_back(new TH1F("estimate_"+b+"_"+s,"estimate_"+b+"_"+s,SRanti.back()->GetNbinsX(),SRanti.back()->GetBinLowEdge(1),SRanti.back()->GetBinLowEdge(SRanti.back()->GetNbinsX())+SRanti.back()->GetBinWidth(SRanti.back()->GetNbinsX())));
            est.back()->SetMarkerColor(2);
            est.back()->SetMarkerStyle(4);
            est.back()->SetLineStyle(2);
            est.back()->SetLineColor(2);
            
            for( int x = 1 ; x <= SRanti.back()->GetNbinsX() ; x++ ){
                int lowMETbin = (res.size()-1)%5;
                est.back()->SetBinContent(x+1,SRanti.back()->GetBinContent(x+1)*res[lowMETbin]->GetBinContent(x+1));
                est.back()->SetBinError(x+1,SRanti.back()->GetBinContent(x+1)*res[lowMETbin]->GetBinError(x+1));
            }

            SRdouble.back()->Draw();
            est.back()->Draw("SAME");
            //leg.back()->Draw();
        }
        can_rpf->SaveAs("../plots/ALPHABET/ALPHABETrpf_MET"+b+".png");
        can_closure->SaveAs("../plots/ALPHABET/ALPHABETclosure_MET"+b+".png");   
        can_antitag->SaveAs("../plots/ALPHABET/ALPHABET_antitag_MET"+b+".png");  
        can_doubletag->SaveAs("../plots/ALPHABET/ALPHABET_doubletag_MET"+b+".png");  
    }
    return 0;
}
