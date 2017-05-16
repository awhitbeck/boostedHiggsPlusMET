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

#include "ALPHABET.h"

using namespace std;
using namespace alphabet;

int main(int argc, char** argv){

    gROOT->SetBatch(true);
    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    TFile* inputFile = new TFile("ALPHABEThistos_singleMu.root","read");
    
    TString samples[6] = {"data","TT","WJets","ZJets","QCD","sum"};

    TCanvas* can_doubletag = new TCanvas("can_doubleTag","can_doubletag",1500,300);
    can_doubletag->Divide(6,1);
    
    TCanvas* can_singletag = new TCanvas("can_singletag","can_singletag",1500,300);
    can_singletag->Divide(6,1);

    TCanvas* can_antitag = new TCanvas("can_antiTag","can_antitag",1500,300);
    can_antitag->Divide(6,1);

    TCanvas* can_rpf_double = new TCanvas("can_rpf_double","can_rpf_double",1500,300);
    can_rpf_double->Divide(6,1);

    TCanvas* can_rpf_single = new TCanvas("can_rpf_single","can_rpf_single",1500,300);
    can_rpf_single->Divide(6,1);
    
    TCanvas* can_closure = new TCanvas("can_closure","can_closure",500,500);
    can_closure->Divide(6,1);

    vector<TF1*> funcDouble;//TF1("func","[0]+[1]*x",50.,200.)
    vector<TF1*> funcSingle;//TF1("func","[0]+[1]*x",50.,200.)
    vector<TLegend*> leg;
    vector<TH1F*> resDouble;
    vector<TH1F*> estDouble;
    vector<TH1F*> resSingle;
    vector<TH1F*> estSingle;
    vector<TH1F*> SRdouble;
    vector<TH1F*> SBdouble;
    vector<TH1F*> SRanti;
    vector<TH1F*> SBanti;
    vector<TH1F*> SRsingle;
    vector<TH1F*> SBsingle;
    vector<TH1F*> ratioSRdouble;
    vector<TH1F*> ratioSBdouble;
    vector<TH1F*> ratioSRsingle;
    vector<TH1F*> ratioSBsingle;

    for( int bin  = int(lowestMET) ; bin <= lowestMET+binWidth*(numMETbins-1) ; bin+=binWidth){

        TString b = "";
        b+=bin;

        for( int i = 0 ; i < 6 ; i++ ){
            TString s = samples[i];

            //////////////////////////////////////////////////////////////////////////////////////////////////
            // - - - - - - - - - - - - - - Draw Rp/f for anti-tag -> double-tag - - - - - - - - - - - - - - //
            //////////////////////////////////////////////////////////////////////////////////////////////////
            funcDouble.push_back(new TF1("funcDouble_"+b+"_"+s,"[0]+[1]*x",50.,250.));
            //cout << "mJ_doubletagSR_"+b+"_"+s << endl;
            ratioSRdouble.push_back(new TH1F(*((TH1F*)inputFile->Get("mJ_doubletagSR_"+b+"_"+s))));
            ratioSRdouble.back()->SetNameTitle("ratioSRdouble_"+b+"_"+s,"ratioSRdouble_"+b+"_"+s);
            ratioSRdouble.back()->Divide((TH1F*)inputFile->Get("mJ_antitagSR_"+b+"_"+s));
            ratioSRdouble.back()->SetMarkerStyle(8);
        
            ratioSBdouble.push_back(new TH1F(*(TH1F*)inputFile->Get("mJ_doubletagSB_"+b+"_"+s)));
            ratioSBdouble.back()->SetNameTitle("ratioSBdouble_"+b+"_"+s,"ratioSBdouble_"+b+"_"+s);
            ratioSBdouble.back()->Divide((TH1F*)inputFile->Get("mJ_antitagSB_"+b+"_"+s));
            ratioSBdouble.back()->SetMarkerStyle(4);

            ratioSBdouble.back()->Fit("funcDouble_"+b+"_"+s,"R");
            //TVirtualFitter* fitter = TVirtualFitter.GetFitter();;
            resDouble.push_back(new TH1F(*ratioSBdouble.back()));
            resDouble.back()->SetNameTitle("resDouble_"+b+"_"+s,"resDouble_"+b+"_"+s);
            (TVirtualFitter::GetFitter())->GetConfidenceIntervals(resDouble.back(),.68);

            ratioSRdouble.back()->GetYaxis()->SetTitle("R_{p/f}");
            ratioSRdouble.back()->GetXaxis()->SetTitle("m_{J} [GeV]");
            ratioSRdouble.back()->GetYaxis()->SetRangeUser(0.,0.25);

            can_rpf_double->cd();
            can_rpf_double->cd(i+1);
            ratioSRdouble.back()->Draw();
            ratioSBdouble.back()->Draw("SAME");
        
            leg.push_back(new TLegend(0.6,0.75,0.9,0.9,s));
            leg.back()->SetBorderSize(0);
            leg.back()->SetFillColor(0);
            leg.back()->Draw();

            //////////////////////////////////////////////////////////////////////////////////////////////////
            // - - - - - - - - - - - - - - Draw Rp/f for anti-tag -> single-tag - - - - - - - - - - - - - - //
            //////////////////////////////////////////////////////////////////////////////////////////////////
            funcSingle.push_back(new TF1("funcSingle_"+b+"_"+s,"[0]+[1]*x",50.,250.));
            //cout << "mJ_singletagSR_"+b+"_"+s << endl;
            ratioSRsingle.push_back(new TH1F(*((TH1F*)inputFile->Get("mJ_tagSR_"+b+"_"+s))));
            ratioSRsingle.back()->SetNameTitle("ratioSRsingle_"+b+"_"+s,"ratioSRsingle_"+b+"_"+s);
            ratioSRsingle.back()->Divide((TH1F*)inputFile->Get("mJ_antitagSR_"+b+"_"+s));
            ratioSRsingle.back()->SetMarkerStyle(8);
        
            ratioSBsingle.push_back(new TH1F(*(TH1F*)inputFile->Get("mJ_tagSB_"+b+"_"+s)));
            ratioSBsingle.back()->SetNameTitle("ratioSBsingle_"+b+"_"+s,"ratioSBsingle_"+b+"_"+s);
            ratioSBsingle.back()->Divide((TH1F*)inputFile->Get("mJ_antitagSB_"+b+"_"+s));
            ratioSBsingle.back()->SetMarkerStyle(4);

            ratioSBsingle.back()->Fit("funcSingle_"+b+"_"+s,"R");
            //TVirtualFitter* fitter = TVirtualFitter.GetFitter();;
            resSingle.push_back(new TH1F(*ratioSBsingle.back()));
            resSingle.back()->SetNameTitle("resSingle_"+b+"_"+s,"resSingle_"+b+"_"+s);
            (TVirtualFitter::GetFitter())->GetConfidenceIntervals(resSingle.back(),.68);

            ratioSRsingle.back()->GetYaxis()->SetTitle("R_{p/f}");
            ratioSRsingle.back()->GetXaxis()->SetTitle("m_{J} [GeV]");
            ratioSRsingle.back()->GetYaxis()->SetRangeUser(0.,0.5);

            can_rpf_single->cd()   ;
            can_rpf_single->cd(i+1);
            ratioSRsingle.back()->Draw();
            ratioSBsingle.back()->Draw("SAME");
        
            leg.back()->Draw();

            //////////////////////////////////////////////////////////////////////////////////////////////////
            // - - - - - - - - - - - - - - - Draw mJ distributions double-tag - - - - - - - - - - - - - - - //
            //////////////////////////////////////////////////////////////////////////////////////////////////
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
            
            ////////////////////////////////////////////////////////////////////////////////////////////////
            // - - - - - - - - - - - - - - - Draw mJ distributions anti-tag - - - - - - - - - - - - - - - //
            ////////////////////////////////////////////////////////////////////////////////////////////////
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

            ////////////////////////////////////////////////////////////////////////////////////////////////
            // - - - - - - - - - - - - - - - Draw mJ distributions single-tag - - - - - - - - - - - - - - //
            ////////////////////////////////////////////////////////////////////////////////////////////////
            can_singletag->cd();
            can_singletag->cd(i+1);
            SRsingle.push_back(new TH1F(*(TH1F*)inputFile->Get("mJ_tagSR_"+b+"_"+s)));
            SRsingle.back()->SetNameTitle("SRsingle_"+b+"_"+s,"SRsingle_"+b+"_"+s);
            SRsingle.back()->SetMarkerStyle(8);
            SBsingle.push_back(new TH1F(*(TH1F*)inputFile->Get("mJ_tagSB_"+b+"_"+s)));
            SBsingle.back()->SetNameTitle("SBsingle_"+b+"_"+s,"SBsingle_"+b+"_"+s);
            SBsingle.back()->SetMarkerStyle(8);
            SBsingle.back()->Draw();
            SRsingle.back()->Draw("SAME");

            ////////////////////////////////////////////////////////////////////////////////////
            // - - - - - - - - - - - - - - - Draw closure plots - - - - - - - - - - - - - - - //
            ////////////////////////////////////////////////////////////////////////////////////
            can_closure->cd();
            can_closure->cd(i+1);
            estDouble.push_back(new TH1F("estimate_double_"+b+"_"+s,"estimate_double_"+b+"_"+s,SRanti.back()->GetNbinsX(),SRanti.back()->GetBinLowEdge(1),SRanti.back()->GetBinLowEdge(SRanti.back()->GetNbinsX())+SRanti.back()->GetBinWidth(SRanti.back()->GetNbinsX())));
            estDouble.back()->SetMarkerColor(2);
            estDouble.back()->SetMarkerStyle(4);
            estDouble.back()->SetLineStyle(2);
            estDouble.back()->SetLineColor(2);

            const int lowMETbin = (resDouble.size()-1)%6;
            
            cout << "MET: " << b << " sample: " << s << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - " << endl;
            double total = 0.;
            double totalCR = 0.;
            double totalCorrErr = 0.;
            double totalUncorrErr = 0.;

            cout << resDouble[lowMETbin]->GetName() << " " << resDouble[lowMETbin]->GetTitle() << endl;

            for( int x = 1 ; x <= SRanti.back()->GetNbinsX() ; x++ ){
                estDouble.back()->SetBinContent(x,SRanti.back()->GetBinContent(x)*resDouble[lowMETbin]->GetBinContent(x));
                double RpfError = 0. ;//SRanti.back()->GetBinContent(x)*resDouble[lowMETbin]->GetBinError(x); 
                double antitagStatError = SRanti.back()->GetBinError(x)*funcDouble[lowMETbin]->Eval(SRanti.back()->GetBinCenter(x)); //resDouble[lowMETbin]->GetBinContent(x);
                estDouble.back()->SetBinError(x,sqrt(RpfError*RpfError+antitagStatError*antitagStatError));
                cout << "CR yield: " << SRanti.back()->GetBinContent(x) << " +/- " << SRanti.back()->GetBinError(x) << endl;
                cout << "Rp/f: " << funcDouble.back()->Eval(SRanti.back()->GetBinCenter(x)) << " +/- " << 0. << endl;
                cout << "estimate: " << estDouble.back()->GetBinContent(x) << " +/- " << estDouble.back()->GetBinError(x) << endl;
                total+=estDouble.back()->GetBinContent(x);
                totalCR+=SRanti.back()->GetBinContent(x);
                totalCorrErr+=antitagStatError*antitagStatError;
                totalUncorrErr+=RpfError;
            }

            cout << "total: " << total << " +/- " << sqrt(totalCorrErr) + totalUncorrErr << endl;
            cout << "average Rp/f: " << total/totalCR << endl;
            cout << "total CR: " << totalCR << endl;

            SRdouble.back()->Draw();
            estDouble.back()->Draw("SAME");
            //leg.back()->Draw();
        }
        can_rpf_single->SaveAs("../plots/ALPHABET/ALPHABETrpf_singleMu_single_MET"+b+".png");
        can_rpf_double->SaveAs("../plots/ALPHABET/ALPHABETrpf_singleMu_double_MET"+b+".png");
        can_closure->SaveAs("../plots/ALPHABET/ALPHABETclosure_singleMu_MET"+b+".png");   
        can_antitag->SaveAs("../plots/ALPHABET/ALPHABET_singleMu_antitag_MET"+b+".png");  
        can_singletag->SaveAs("../plots/ALPHABET/ALPHABET_singleMu_singletag_MET"+b+".png");  
        can_doubletag->SaveAs("../plots/ALPHABET/ALPHABET_singleMu_doubletag_MET"+b+".png");  
    }
    return 0;
}
