
void computeScaleFactor(TH1F* hdata,TH1F* hmc){
    double yieldmc,yeilddata,errmc,errdata;

    //cout << "hdata: " << hdata << endl;
    //cout << "hmc: " << hmc << endl;

    yieldmc = hmc->IntegralAndError(1,40,errmc) ; 
    yielddata = hdata->IntegralAndError(1,40,errdata) ;
    if( yielddata == 0. )
        cout << " 0. +/- " <<  sqrt(errmc*errmc+1.67*1.67);
    else 
        cout << yielddata/yieldmc << " +/- " << sqrt(errmc*errmc/yieldmc/yieldmc+errdata*errdata/yielddata/yielddata)*yielddata/yieldmc;
}


void checkScaleFactors(TString tag = "_singleMu", bool doubletag = true, TString baseDir="./"){

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    TFile* f = new TFile(baseDir+"ALPHABEThistos"+tag+".root","READ");
    TH1F* hdata,*hmc;

    TString tagString;
    if(doubletag)
        tagString = "doubletag" ;
    else 
        tagString = "tag" ;

    TH1F* doubletagSRdata = new TH1F(tagString+"SRdata",tagString+"SRdata",4,100,900);
    doubletagSRdata->SetLineColor(1);
    doubletagSRdata->SetLineWidth(3);
    doubletagSRdata->SetMarkerColor(1);
    doubletagSRdata->SetMarkerStyle(8);
    doubletagSRdata->GetXaxis()->SetTitle("MET [GeV]");
    doubletagSRdata->GetYaxis()->SetTitle("Events");
    //doubletagSRdata->GetXaxis()->SetRangeUser(301,900);
    TH1F* doubletagSBdata = new TH1F(*doubletagSRdata);
    doubletagSBdata->SetNameTitle(tagString+"SBdata",tagString+"SBdata");
    TH1F* antitagSRdata = new TH1F(*doubletagSRdata);
    antitagSRdata->SetNameTitle("antitagSRdata","antitagSRdata");
    TH1F* antitagSBdata = new TH1F(*doubletagSRdata);
    antitagSBdata->SetNameTitle("antitagSBdata","antitagSBdata");

    TH1F* doubletagSRmc = new TH1F(tagString+"SRmc",tagString+"SRmc",4,100,900);
    doubletagSRmc->SetLineColor(2);
    doubletagSRmc->SetLineWidth(3);
    doubletagSRmc->SetFillColor(2);
    doubletagSRmc->SetFillStyle(3490);
    doubletagSRmc->GetXaxis()->SetTitle("MET [GeV]");
    doubletagSRmc->GetYaxis()->SetTitle("Events");
    //doubletagSRmc->GetXaxis()->SetRangeUser(301,900);
    TH1F* doubletagSBmc = new TH1F(*doubletagSRmc);
    doubletagSBmc->SetNameTitle(tagString+"SBmc",tagString+"SBmc");
    TH1F* antitagSRmc = new TH1F(*doubletagSRmc);
    antitagSRmc->SetNameTitle("antitagSRmc","antitagSRmc");
    TH1F* antitagSBmc = new TH1F(*doubletagSRmc);
    antitagSBmc->SetNameTitle("antitagSBmc","antitagSBmc");

    TH1F* prediction = new TH1F(*doubletagSRdata);
    prediction->SetNameTitle("prediction","prediction");
    prediction->SetMarkerColor(4);
    prediction->SetLineColor(4);

    cout << "\\begin{tabular}{|c|c|}" << endl;

    // ---------------------------------------------
    cout << "\\multicolumn{2}{c}{100 $<$ MET $<$ 300} \\\\ \\hline" << endl;
    hdata = (TH1F*) f->Get("mJ_"+tagString+"SR_100_data");
    hmc = (TH1F*) f->Get("mJ_"+tagString+"SR_100_sum");
    cout << std::setprecision(2) << "$\\alpha_{}$ & ";
    computeScaleFactor(hdata,hmc);
    doubletagSRdata->SetBinContent(1,hdata->Integral(1,3));
    doubletagSRmc->SetBinContent(1,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_"+tagString+"SB_100_data");
    hmc = (TH1F*) f->Get("mJ_"+tagString+"SB_100_sum");
    cout << "$\\beta_{}$ &";
    computeScaleFactor(hdata,hmc);
    doubletagSBdata->SetBinContent(1,hdata->Integral(1,3));
    doubletagSBmc->SetBinContent(1,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_antitagSR_100_data");
    hmc = (TH1F*) f->Get("mJ_antitagSR_100_sum");
    cout << "$\\gamma_{}$ & ";
    computeScaleFactor(hdata,hmc);
    antitagSRdata->SetBinContent(1,hdata->Integral(1,3));
    antitagSRmc->SetBinContent(1,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_antitagSB_100_data");
    hmc = (TH1F*) f->Get("mJ_antitagSB_100_sum");
    cout << "$\\delta_{}$ & ";
    computeScaleFactor(hdata,hmc);
    antitagSBdata->SetBinContent(1,hdata->Integral(1,3));
    antitagSBmc->SetBinContent(1,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    // ---------------------------------------------
    cout << "\\multicolumn{2}{c}{300 $<$ MET $<$ 500} \\\\ \\hline" << endl;
    hdata = (TH1F*) f->Get("mJ_"+tagString+"SR_300_data");
    hmc = (TH1F*) f->Get("mJ_"+tagString+"SR_300_sum");
    cout << "$\\alpha_{}$ & ";
    computeScaleFactor(hdata,hmc);
    doubletagSRdata->SetBinContent(2,hdata->Integral(1,3));
    doubletagSRmc->SetBinContent(2,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_"+tagString+"SB_300_data");
    hmc = (TH1F*) f->Get("mJ_"+tagString+"SB_300_sum");
    cout << "$\\beta_{}$ & ";
    computeScaleFactor(hdata,hmc);
    doubletagSBdata->SetBinContent(2,hdata->Integral(1,3));
    doubletagSBmc->SetBinContent(2,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_antitagSR_300_data");
    hmc = (TH1F*) f->Get("mJ_antitagSR_300_sum");
    cout << "$\\gamma_{}$ & ";
    computeScaleFactor(hdata,hmc);
    antitagSRdata->SetBinContent(2,hdata->Integral(1,3));
    antitagSRmc->SetBinContent(2,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_antitagSB_300_data");
    hmc = (TH1F*) f->Get("mJ_antitagSB_300_sum");
    cout << "$\\delta_{}$ & ";
    computeScaleFactor(hdata,hmc);
    antitagSBdata->SetBinContent(2,hdata->Integral(1,3));
    antitagSBmc->SetBinContent(2,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;
    
    // ---------------------------------------------
    cout << "\\multicolumn{2}{c}{500 $<$ MET $<$ 700} \\\\ \\hline" << endl;
    hdata = (TH1F*) f->Get("mJ_"+tagString+"SR_500_data");
    hmc = (TH1F*) f->Get("mJ_"+tagString+"SR_500_sum");
    cout << "$\\alpha_{}$ & ";
    computeScaleFactor(hdata,hmc);
    doubletagSRdata->SetBinContent(3,hdata->Integral(1,3));
    doubletagSRmc->SetBinContent(3,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_"+tagString+"SB_500_data");
    hmc = (TH1F*) f->Get("mJ_"+tagString+"SB_500_sum");
    cout << "$\\beta_{}$ & ";
    computeScaleFactor(hdata,hmc);
    doubletagSBdata->SetBinContent(3,hdata->Integral(1,3));
    doubletagSBmc->SetBinContent(3,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_antitagSR_500_data");
    hmc = (TH1F*) f->Get("mJ_antitagSR_500_sum");
    cout << "$\\gamma_{}$ & ";
    computeScaleFactor(hdata,hmc);
    antitagSRdata->SetBinContent(3,hdata->Integral(1,3));
    antitagSRmc->SetBinContent(3,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_antitagSB_500_data");
    hmc = (TH1F*) f->Get("mJ_antitagSB_500_sum");
    cout << "$\\delta_{}$ & ";
    computeScaleFactor(hdata,hmc);
    antitagSBdata->SetBinContent(3,hdata->Integral(1,3));
    antitagSBmc->SetBinContent(3,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    // ---------------------------------------------
    cout << "\\multicolumn{2}{c}{MET $>$ 700} \\\\ \\hline" << endl;
    hdata = (TH1F*) f->Get("mJ_"+tagString+"SR_700_data");
    hmc = (TH1F*) f->Get("mJ_"+tagString+"SR_700_sum");
    cout << "$\\alpha_{}$ & ";
    computeScaleFactor(hdata,hmc);
    doubletagSRdata->SetBinContent(4,hdata->Integral(1,3));
    doubletagSRmc->SetBinContent(4,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_"+tagString+"SB_700_data");
    hmc = (TH1F*) f->Get("mJ_"+tagString+"SB_700_sum");
    cout << "$\\beta_{}$ & ";
    computeScaleFactor(hdata,hmc);
    doubletagSBdata->SetBinContent(4,hdata->Integral(1,3));
    doubletagSBmc->SetBinContent(4,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_antitagSR_700_data");
    hmc = (TH1F*) f->Get("mJ_antitagSR_700_sum");
    cout << "$\\gamma_{}$ & ";
    computeScaleFactor(hdata,hmc);
    antitagSRdata->SetBinContent(4,hdata->Integral(1,3));
    antitagSRmc->SetBinContent(4,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;

    hdata = (TH1F*) f->Get("mJ_antitagSB_700_data");
    hmc = (TH1F*) f->Get("mJ_antitagSB_700_sum");
    cout << "$\\delta_{}$ & ";
    computeScaleFactor(hdata,hmc);
    antitagSBdata->SetBinContent(4,hdata->Integral(1,3));
    antitagSBmc->SetBinContent(4,hmc->Integral(1,3));
    cout << " \\\\ \\hline" << endl;
    // ---------------------------------------------
    cout << "\\multicolumn{2}{c}{All MET} \\\\ \\hline" << endl;
    cout << "$\\alpha_{}$ & ";
    computeScaleFactor(doubletagSRdata,doubletagSRmc);
    cout << " \\\\ \\hline" << endl;

    cout << "$\\beta_{}$ & ";
    computeScaleFactor(doubletagSBdata,doubletagSBmc);
    cout << " \\\\ \\hline" << endl;

    cout << "$\\gamma_{}$ & ";
    computeScaleFactor(antitagSRdata,antitagSRmc);
    cout << " \\\\ \\hline" << endl;
    
    cout << "$\\delta_{}$ & ";
    computeScaleFactor(antitagSBdata,antitagSBmc);
    cout << " \\\\ \\hline" << endl;
    cout << "\\end{tabular}" << endl;
    // ---------------------------------------------
    // ---------------------------------------------
    for( int i = 1 ; i <= doubletagSRmc->GetNbinsX() ; i++ ){        
        if( antitagSBdata->GetBinContent(i) > 0. ) 
            prediction->SetBinContent(i,doubletagSBdata->GetBinContent(i)/antitagSBdata->GetBinContent(i)*antitagSRdata->GetBinContent(i));
        else 
            prediction->SetBinContent(i,0.);
    }    
    // ---------------------------------------------

    TCanvas* can = new TCanvas("can","can",800,800);
    can->Divide(2,2);
    can->cd(1);
    gStyle->SetErrorX(0.5);
    doubletagSRdata->GetYaxis()->SetRangeUser(0.,max(doubletagSRdata->GetMaximum(),max(doubletagSRmc->GetMaximum(),prediction->GetMaximum()))*1.3);
    doubletagSRdata->Draw("p,e1");
    doubletagSRmc->Draw("e2,SAME");
    prediction->Draw("SAME,p,e1");
    can->cd(2);
    doubletagSBdata->GetYaxis()->SetRangeUser(0.,max(doubletagSBdata->GetMaximum(),doubletagSBmc->GetMaximum())*1.3);
    doubletagSBdata->Draw("p,e1");
    doubletagSBmc->Draw("e2,SAME");
    can->cd(3);
    antitagSRdata->GetYaxis()->SetRangeUser(0.,max(antitagSRdata->GetMaximum(),antitagSRmc->GetMaximum())*1.3);
    antitagSRdata->Draw("p,e1");
    antitagSRmc->Draw("e2,SAME");
    can->cd(4);
    antitagSBdata->GetYaxis()->SetRangeUser(0.,max(antitagSBdata->GetMaximum(),antitagSBmc->GetMaximum())*1.3);
    antitagSBdata->Draw("p,e1");
    antitagSBmc->Draw("e2,SAME");

    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors"+tag+".png");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors"+tag+".eps");
    can->SaveAs("../plots/ABCDscaleFactors/ABCDscaleFactors"+tag+".pdf");

}
