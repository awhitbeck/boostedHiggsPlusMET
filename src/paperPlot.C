



void paperPlot(){

    gROOT->ProcessLine(".L ~/tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    TString plotLabel = "J1M_leadJetTightMass";
    TString signalLabel = "T5HH1800";
    vector<TString> backgroundLabels={"QCD","Other","SnglT","WJets","ZJets","TT"};
    vector<int> backgroundColors={kGray,kRed+1,kOrange,kBlue,kGreen+1,kCyan};
    vector<TString> backgroundLegendLabel={"QCD","Other","Single-top","W+Jets","Z+Jets","t#bar{t}"};
    vector<TH1F*> backgroundHistos;
    TFile* inputFile = new TFile("NminusOne.root");
    
    TLegend* leg = new TLegend(0.2,0.8,0.8,0.9);
    leg->SetFillColor(0);
    leg->SetBorderSize(0);
    
    THStack* stack = new THStack("stack","stack");

    for( int i = 0 ; i < backgroundLabels.size() ; i++ ){
        backgroundHistos.push_back((TH1F*) inputFile->Get(plotLabel+"_"+backgroundLabels[i]));
        backgroundHistos.back()->SetFillColor(backgroundColors[i]);
        backgroundHistos.back()->SetLineColor(1);
        backgroundHistos.back()->SetLineWidth(2);
        leg->AddEntry(backgroundHistos.back(),backgroundLegendLabel[i],"lf");
        stack->Add(backgroundHistos.back());
    }

    TH1F* data = (TH1F*) inputFile->Get(plotLabel+"_data");
    data->SetMarkerStyle(8);
    data->SetMarkerColor(1);
    
    TH1F* signal = (TH1F*) inputFile->Get(plotLabel+"_"+signalLabel);
    signal->Add((TH1F*)inputFile->Get(plotLabel+"_sum"));
    signal->SetLineColor(kRed);
    signal->SetLineWidth(2);

    leg->AddEntry(signal,"T5HH(1800)","l");
    leg->AddEntry(data,"data","p");

    TCanvas* can = new TCanvas("can","can",800,800);
    signal->Draw("hist");
    stack->Draw("hist,SAME");
    data->Draw("e1,SAME");

    leg->Draw();

    can->SaveAs("Nminus_"+plotLabel+"_signalStack.png");

    for( int i = 0 ; i < backgroundHistos.size() ; i++ ){
        delete backgroundHistos[i];
    }
    delete can;
    delete leg;
    delete stack;
    delete inputFile;
}
