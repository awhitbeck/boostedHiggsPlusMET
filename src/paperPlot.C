#include "CMS_lumi.cc"
#include "RooHistError.h"

TGraphAsymmErrors* convert_hist(TH1* hist){
    TGraphAsymmErrors* out_graph = new TGraphAsymmErrors(hist);
    out_graph->SetMarkerStyle(8);
    double x,y,xeh,xel,yeh,yel;
    for( int i = 0 ; i < hist->GetNbinsX() ; i++ ){
        out_graph->GetPoint(i,x,y);
        cout << "x: " << x << " y: " << y ; 
        yel = ( y == 0 ) ? 0. : y - ROOT::Math::gamma_quantile((1 - 0.6827)/2,y,1.); 
        yeh = ROOT::Math::gamma_quantile_c((1 - 0.6827)/2,y+1,1) - y ;
        cout << " yel: " << yel << " yeh: " << yeh << endl;
        out_graph->SetPointError(i,xel,xeh,yel,yeh);
    }
    return out_graph;
}

void paperPlot(TString plotLabel = "J1M_leadJetTightMass"){

    gROOT->ProcessLine(".L ~/tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    int binFactor=2;
    TString signalLabel = "T5HH1700";
    vector<TString> backgroundLabels={"QCD","Other","SnglT","WJets","ZJets","TT"};
    vector<int> backgroundColors={kGray,kRed+1,kOrange,kBlue,kGreen+1,kCyan};
    vector<TString> backgroundLegendLabel={"QCD","Other","Single t","W+Jets","Z+Jets","t#bar{t}"};
    vector<TH1F*> backgroundHistos;
    TFile* inputFile = new TFile("NminusOne.root");
    
    TLegend* leg = new TLegend(0.2,0.7,0.9,0.9);
    leg->SetFillColor(0);
    leg->SetBorderSize(0);
    leg->SetNColumns(4);
    leg->SetTextFont(43);
    leg->SetTextSize(30);

    /* two line version which spans the full width
    TLegend* legsig = new TLegend(0.2,0.5,0.9,0.7);
    legsig->SetTextAlign(33);
    legsig->SetFillColor(0);
    legsig->SetBorderSize(0);
    legsig->SetNColumns(1);
    legsig->SetTextFont(43);
    legsig->SetTextSize(30);
    */

    TLegend* legsig = new TLegend(0.25,0.6,0.9,0.7);
    legsig->SetTextAlign(12);
    legsig->SetFillColor(0);
    legsig->SetBorderSize(0);
    legsig->SetNColumns(1);
    legsig->SetTextFont(43);
    legsig->SetTextSize(30);

    TLegend* legsig2 = new TLegend(0.6,0.3,0.9,0.6);
    legsig2->SetTextAlign(12);
    legsig2->SetFillColor(0);
    legsig2->SetBorderSize(0);
    legsig2->SetNColumns(1);
    legsig2->SetTextFont(43);
    legsig2->SetTextSize(30);

    THStack* stack = new THStack("stack","stack");
    TH1F* sum = (TH1F*) inputFile->Get(plotLabel+"_sum");
    assert(sum!=NULL);
    cout << "sum SR: " << sum->Integral(7,16) << endl;
    double dataDrivenSF = 23.43/sum->Integral(7,16);
    sum->Scale(dataDrivenSF);

    for( int i = 0 ; i < backgroundLabels.size() ; i++ ){
        backgroundHistos.push_back((TH1F*) inputFile->Get(plotLabel+"_"+backgroundLabels[i]));
        assert(backgroundHistos.back()!=NULL);
        backgroundHistos.back()->Scale(dataDrivenSF);
        backgroundHistos.back()->Rebin(binFactor);
        backgroundHistos.back()->SetFillColor(backgroundColors[i]);
        backgroundHistos.back()->SetLineColor(1);
        backgroundHistos.back()->SetLineWidth(2);
        cout << "backgroundLabels[i] SR: " << backgroundHistos.back()->Integral(7,16) << endl;
        leg->AddEntry(backgroundHistos.back(),backgroundLegendLabel[i],"f");
        stack->Add(backgroundHistos.back());
    }

    TH1F* data = (TH1F*) inputFile->Get(plotLabel+"_data");
    assert(data!=NULL);
    data->Rebin(binFactor);
    data->SetMarkerStyle(8);
    data->SetMarkerColor(1);
    cout << "data SR: " << data->Integral(7,16) << endl;

    TH1F* signal = (TH1F*) inputFile->Get(plotLabel+"_"+signalLabel);
    assert(signal!=NULL);
    signal->Rebin(binFactor);

    sum->Rebin(binFactor);
    signal->Add(sum);
    signal->SetLineColor(kRed);
    signal->SetLineWidth(2);
    signal->GetYaxis()->SetRangeUser(0.,signal->GetMaximum()*2.0-3.0);
    signal->GetXaxis()->SetRangeUser(55.1,244.9);
    signal->GetYaxis()->SetLabelFont(43);
    signal->GetYaxis()->SetLabelSize(30);
    signal->GetYaxis()->SetTitleFont(43);
    signal->GetYaxis()->SetTitleSize(40);
    signal->GetYaxis()->SetTitleOffset(1.0);
    signal->GetYaxis()->SetTitle("Events / 10 GeV");
    signal->GetXaxis()->SetLabelFont(43);
    signal->GetXaxis()->SetLabelSize(30);
    signal->GetXaxis()->SetLabelOffset(1.0);
    signal->GetXaxis()->SetTitleFont(43);
    signal->GetXaxis()->SetTitleSize(40);
    signal->GetXaxis()->SetTitleOffset(1.0);
    signal->GetXaxis()->SetTitle("m_{J} [GeV]");

    leg->AddEntry(data,"Data","pe");
    legsig->AddEntry(signal,"pp #rightarrow #tilde{g} #tilde{g}, #tilde{g} #rightarrow q#bar{q} #tilde{#chi}_{2}^{0} , #tilde{#chi}_{2}^{0} #rightarrow H #tilde{#chi}_{1}^{0}","l");
    //legsig->AddEntry(signal,"pp #rightarrow #tilde{g} #tilde{g}","l");
    //legsig->AddEntry(signal,"#tilde{g} #rightarrow q#bar{q} #tilde{#chi}_{2}^{0}","");
    //legsig->AddEntry(signal,"#tilde{#chi}_{2}^{0} #rightarrow H #tilde{#chi}_{1}^{0}","");

    legsig2->AddEntry(signal,"m_{#tilde{g}} = 1800 GeV","");
    legsig2->AddEntry(signal,"m_{#tilde{#chi}_{2}^{0}} = 1750 GeV","");
    legsig2->AddEntry(signal,"m_{#tilde{#chi}_{1}^{0}} = 1 GeV","");

    TCanvas* can = new TCanvas("can","can",800,800);

    TPad* topPad = new TPad("topPad","topPad",0.,0.3,0.99,0.99);
    TPad* botPad = new TPad("botPad","botPad",0.,0.0,0.99,.28);
    botPad->SetBorderMode(0);
    botPad->SetBorderSize(0);
    botPad->SetFrameBorderMode(0);
    botPad->SetFrameBorderSize(0);
    botPad->SetBottomMargin(0.35);
    botPad->SetTopMargin(0.);
    topPad->SetTopMargin(0.06);
    topPad->SetBottomMargin(0.);
    topPad->SetBorderMode(0);
    topPad->SetBorderSize(0);
    botPad->SetFrameBorderMode(0);
    botPad->SetFrameBorderSize(0);
    topPad->Draw();
    botPad->Draw();

    // ratio
    botPad->cd();

    TH1F* ratio = new TH1F(*data);
    ratio->Divide((TH1F*)inputFile->Get(plotLabel+"_sum"));
    ratio->SetMarkerStyle(8);
    ratio->SetMarkerColor(1);
    ratio->SetLineColor(1);
    ratio->GetYaxis()->SetRangeUser(0.,2.99);
    ratio->GetXaxis()->SetRangeUser(55.1,244.9);
    ratio->GetYaxis()->SetLabelFont(43);
    ratio->GetYaxis()->SetLabelSize(30);
    ratio->GetYaxis()->SetTitleFont(43);
    ratio->GetYaxis()->SetTitleSize(40);
    ratio->GetYaxis()->SetTitleOffset(1.0);
    ratio->GetYaxis()->SetNdivisions(503);
    ratio->GetYaxis()->SetTitle("Data / MC");
    ratio->GetXaxis()->SetLabelFont(43);
    ratio->GetXaxis()->SetLabelSize(30);
    ratio->GetXaxis()->SetTitleFont(43);
    ratio->GetXaxis()->SetTitleSize(40);
    ratio->GetXaxis()->SetTitleOffset(2.7);
    ratio->GetXaxis()->SetTitle("m_{J} [GeV]");
    ratio->Draw("e1");

    TLine* line = new TLine(55.,1.,245.,1.);
    line->SetLineColor(1);
    line->SetLineWidth(2);
    line->SetLineStyle(2);
    line->Draw();

    // mass distribution
    topPad->cd();

    signal->Draw("hist");
    stack->Draw("hist,SAME");
    TGraphAsymmErrors* data_gr = convert_hist(data);
    data_gr->Draw("p,e1,SAME");

    leg->Draw();
    legsig->Draw();
    legsig2->Draw();

    TLine* leftSigBoundary = new TLine(85.0,0.01,85.0,13.);//signal->GetMaximum()*0.5);
    leftSigBoundary->SetLineColor(kMagenta);
    leftSigBoundary->SetLineStyle(2);
    leftSigBoundary->SetLineWidth(3);

    TLine* rightSigBoundary = new TLine(135.0,0.01,135.0,13.);//signal->GetMaximum()*0.5);
    rightSigBoundary->SetLineColor(kMagenta);
    rightSigBoundary->SetLineStyle(2);
    rightSigBoundary->SetLineWidth(3);

    leftSigBoundary->Draw();
    rightSigBoundary->Draw();

    topPad->RedrawAxis();

    // CMS/lumi label
    writeExtraText = false;
    extraText="preliminary";
    lumi_13TeV = "35.9 fb^{-1}";
    CMS_lumi( can , 4 , 0 );
    can->Update();
    can->RedrawAxis();

    can->SaveAs("Nminus_"+plotLabel+"_signalStack.png");
    can->SaveAs("Nminus_"+plotLabel+"_signalStack.pdf");
    can->SaveAs("Nminus_"+plotLabel+"_signalStack.eps");

    for( int i = 0 ; i < backgroundHistos.size() ; i++ ){
        delete backgroundHistos[i];
    }
    delete can;
    delete leg;
    delete stack;
    delete inputFile;
}
