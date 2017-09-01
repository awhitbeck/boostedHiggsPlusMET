#include "CMS_lumi.cc"

void paperPlot(TString plotLabel = "J1M_leadJetTightMass"){

    gROOT->ProcessLine(".L ~/tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    int binFactor=2;
    TString signalLabel = "T5HH1800";
    vector<TString> backgroundLabels={"QCD","Other","SnglT","WJets","ZJets","TT"};
    vector<int> backgroundColors={kGray,kRed+1,kOrange,kBlue,kGreen+1,kCyan};
    vector<TString> backgroundLegendLabel={"QCD","Other","Single-top","W+Jets","Z+Jets","t#bar{t}"};
    vector<TH1F*> backgroundHistos;
    TFile* inputFile = new TFile("NminusOne.root");
    
    TLegend* leg = new TLegend(0.2,0.7,0.9,0.9);
    leg->SetFillColor(0);
    leg->SetBorderSize(0);
    leg->SetNColumns(4);
    leg->SetTextFont(43);
    leg->SetTextSize(30);

    THStack* stack = new THStack("stack","stack");

    for( int i = 0 ; i < backgroundLabels.size() ; i++ ){
        backgroundHistos.push_back((TH1F*) inputFile->Get(plotLabel+"_"+backgroundLabels[i]));
	backgroundHistos.back()->Rebin(binFactor);
        backgroundHistos.back()->SetFillColor(backgroundColors[i]);
        backgroundHistos.back()->SetLineColor(1);
        backgroundHistos.back()->SetLineWidth(2);
        leg->AddEntry(backgroundHistos.back(),backgroundLegendLabel[i],"f");
        stack->Add(backgroundHistos.back());
    }

    TH1F* data = (TH1F*) inputFile->Get(plotLabel+"_data");
    data->Rebin(binFactor);
    data->SetMarkerStyle(8);
    data->SetMarkerColor(1);
    
    TH1F* signal = (TH1F*) inputFile->Get(plotLabel+"_"+signalLabel);
    signal->Rebin(binFactor);
    TH1F* sum = (TH1F*) inputFile->Get(plotLabel+"_sum");
    sum->Rebin(binFactor);
    signal->Add(sum);
    signal->SetLineColor(kRed);
    signal->SetLineWidth(2);
    signal->GetYaxis()->SetRangeUser(0.01,signal->GetMaximum()*2.0);
    signal->GetYaxis()->SetLabelFont(43);
    signal->GetYaxis()->SetLabelSize(30);
    signal->GetYaxis()->SetTitleFont(43);
    signal->GetYaxis()->SetTitleSize(40);
    signal->GetYaxis()->SetTitleOffset(1.0);
    signal->GetYaxis()->SetTitle("Events");
    signal->GetXaxis()->SetLabelFont(43);
    signal->GetXaxis()->SetLabelSize(30);
    signal->GetXaxis()->SetTitleFont(43);
    signal->GetXaxis()->SetTitleSize(40);
    signal->GetXaxis()->SetTitleOffset(1.0);
    signal->GetXaxis()->SetTitle("m_{J} [GeV]");

    leg->AddEntry(signal,"T5HH(1800)","l");
    leg->AddEntry(data,"data","p");

    TCanvas* can = new TCanvas("can","can",800,800);

    TPad* topPad = new TPad("topPad","topPad",0.,0.4,.99,.99);
    TPad* botPad = new TPad("botPad","botPad",0.,0.01,.99,.40);
    botPad->SetBottomMargin(0.25);
    botPad->SetTopMargin(0.);
    topPad->SetTopMargin(0.06);
    topPad->SetBottomMargin(0.);
    topPad->Draw();
    botPad->Draw();
    topPad->cd();

    signal->Draw("hist");
    stack->Draw("hist,SAME");
    data->Draw("e1,SAME");

    leg->Draw();
    topPad->RedrawAxis();

    // CMS/lumi label
    writeExtraText = true;
    extraText="Preliminary";
    lumi_13TeV = "35.9";
    CMS_lumi( can , 4 , 0 );
    can->Update();
    can->RedrawAxis();
    can->GetFrame()->Draw();

    // ratio
    botPad->cd();

    TH1F* ratio = new TH1F(*data);
    ratio->Divide((TH1F*)inputFile->Get(plotLabel+"_sum"));
    ratio->SetMarkerStyle(8);
    ratio->SetMarkerColor(1);
    ratio->SetLineColor(1);
    ratio->GetYaxis()->SetRangeUser(0.,3.);
    ratio->GetYaxis()->SetLabelFont(43);
    ratio->GetYaxis()->SetLabelSize(30);
    ratio->GetYaxis()->SetTitleFont(43);
    ratio->GetYaxis()->SetTitleSize(40);
    ratio->GetYaxis()->SetTitleOffset(1.0);
    ratio->GetYaxis()->SetNdivisions(503);
    ratio->GetYaxis()->SetTitle("Data/MC");
    ratio->GetXaxis()->SetLabelFont(43);
    ratio->GetXaxis()->SetLabelSize(30);
    ratio->GetXaxis()->SetTitleFont(43);
    ratio->GetXaxis()->SetTitleSize(40);
    ratio->GetXaxis()->SetTitleOffset(2.2);
    ratio->GetXaxis()->SetTitle("m_{J} [GeV]");
    ratio->Draw("e1");

    TLine* line = new TLine(50.,1.,250.,1.);
    line->SetLineColor(1);
    line->SetLineWidth(2);
    line->SetLineStyle(2);
    line->Draw();

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
