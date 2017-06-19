
vector<double> computeKappa(double corrTT_A=1.0,      
                            double corrTT_B=1.0,       
                            double corrTT_C=1.0,      
                            double corrTT_D=1.0,      
                            double corrWJets_A=1.0,    
                            double corrWJets_B=1.0,    
                            double corrWJets_C=1.0,    
                            double corrWJets_D=1.0,    
                            double corrZJets_A=1.0,   
                            double corrZJets_B=1.0,   
                            double corrZJets_C=1.0,   
                            double corrZJets_D=1.0,   
                            double corrQCD_A=1.0,     
                            double corrQCD_B=1.0,     
                            double corrQCD_C=1.0,     
                            double corrQCD_D=1.0,      
                            bool doubletag = true,
                            bool verbose = false
                            ){

    //TFile* f = new TFile("ALPHABEThistos_newSBdef.root","READ");
    //TFile* f = new TFile("~/eos/boostedHiggsPlusMET/ae9d4e104fd7627f36dec4c410c4b591f7ae4036/ALPHABEThistos.root","READ");
    TFile* f = new TFile("/uscms_data/d2/rgp230/BoostedHPush/NewCommit/NewBugFixes/CMSSW_7_4_2/src/boostedHiggsPlusMET/src/ALPHABEThistosSynch.root","READ");

    ////////////////////////////////////////////////////////////
    // - - - - - - - - - data/MC corrections - - - - - - - -  //
    ////////////////////////////////////////////////////////////
    //static const int numMETbins = 4;
    //int METbins[numMETbins+1] = {100,300,500,700,999999999};
    static const int numMETbins = 3;

    TString tagString;
    if( doubletag ) 
        tagString = "doubletag";
    else
        tagString = "tag";

    int METbins[numMETbins+1] = {300,500,700,999999999};
    vector<double> kappa(numMETbins*2);
    for( int i = 0 ; i < numMETbins ; i++ ){
        if( verbose ){
            cout << " - - - - - - - - - - - - - - - - - - - - - - - " << endl;
            cout << METbins[i] << " < MET < " << METbins[i+1] << endl;
            cout << " - - - - - - - - - - - - - - - - - - - - - - - " << endl;
        }
        TH1F *hA,*hB,*hC,*hD;
        double A,B,C,D;
        double Aerr,Berr,Cerr,Derr;
        TString histoName="mJ_"+tagString+"SR_"; histoName+=METbins[i]; histoName+="_TT";
        hA = (TH1F*) f->Get(histoName);
        hA->Scale(corrTT_A);
        histoName="mJ_"+tagString+"SR_"; histoName+=METbins[i]; histoName+="_WJets";
        hA->Add((TH1F*) f->Get(histoName),corrWJets_A);
        histoName="mJ_"+tagString+"SR_"; histoName+=METbins[i]; histoName+="_QCD";
        hA->Add((TH1F*) f->Get(histoName),corrQCD_A);
        histoName="mJ_"+tagString+"SR_"; histoName+=METbins[i]; histoName+="_ZJets";
        hA->Add((TH1F*) f->Get(histoName),corrZJets_A);
        histoName="mJ_"+tagString+"SR_"; histoName+=METbins[i]; histoName+="_Other";
        hA->Add((TH1F*) f->Get(histoName),1.0);
        histoName="mJ_"+tagString+"SR_"; histoName+=METbins[i]; histoName+="_SnglT";
        hA->Add((TH1F*) f->Get(histoName),1.0);
        A = hA->IntegralAndError(1,40,Aerr);
        histoName="mJ_"+tagString+"SB_"; histoName+=METbins[i]; histoName+="_TT";
        hB = (TH1F*) f->Get(histoName);
        hB->Scale(corrTT_B);
        histoName="mJ_"+tagString+"SB_"; histoName+=METbins[i]; histoName+="_WJets";
        hB->Add((TH1F*) f->Get(histoName),corrWJets_B);
        histoName="mJ_"+tagString+"SB_"; histoName+=METbins[i]; histoName+="_ZJets";
        hB->Add((TH1F*) f->Get(histoName),corrZJets_B);
        histoName="mJ_"+tagString+"SB_"; histoName+=METbins[i]; histoName+="_QCD";
        hB->Add((TH1F*) f->Get(histoName),corrQCD_B);
        histoName="mJ_"+tagString+"SB_"; histoName+=METbins[i]; histoName+="_Other";
        hB->Add((TH1F*) f->Get(histoName),1.0);
        histoName="mJ_"+tagString+"SB_"; histoName+=METbins[i]; histoName+="_SnglT";
        hB->Add((TH1F*) f->Get(histoName),1.0);
        B = hB->IntegralAndError(1,40,Berr);
        histoName="mJ_antitagSR_"; histoName+=METbins[i]; histoName+="_TT";
        hC = (TH1F*) f->Get(histoName);
        hC->Scale(corrTT_C);
        histoName="mJ_antitagSR_"; histoName+=METbins[i]; histoName+="_WJets";
        hC->Add((TH1F*) f->Get(histoName),corrWJets_C);
        histoName="mJ_antitagSR_"; histoName+=METbins[i]; histoName+="_ZJets";
        hC->Add((TH1F*) f->Get(histoName),corrZJets_C);
        histoName="mJ_antitagSR_"; histoName+=METbins[i]; histoName+="_QCD";
        hC->Add((TH1F*) f->Get(histoName),corrQCD_C);
        histoName="mJ_antitagSR_"; histoName+=METbins[i]; histoName+="_Other";
        hC->Add((TH1F*) f->Get(histoName),1.0);
        histoName="mJ_antitagSR_"; histoName+=METbins[i]; histoName+="_SnglT";
        hC->Add((TH1F*) f->Get(histoName),1.0);
        C = hC->IntegralAndError(1,40,Cerr);
        histoName="mJ_antitagSB_"; histoName+=METbins[i]; histoName+="_TT";
        hD = (TH1F*) f->Get(histoName);
        hD->Scale(corrTT_D);
        histoName="mJ_antitagSB_"; histoName+=METbins[i]; histoName+="_WJets";
        hD->Add((TH1F*) f->Get(histoName),corrWJets_D);
        histoName="mJ_antitagSB_"; histoName+=METbins[i]; histoName+="_ZJets";
        hD->Add((TH1F*) f->Get(histoName),corrZJets_D);
        histoName="mJ_antitagSB_"; histoName+=METbins[i]; histoName+="_QCD";
        hD->Add((TH1F*) f->Get(histoName),corrQCD_D);
        histoName="mJ_antitagSB_"; histoName+=METbins[i]; histoName+="_Other";
        hD->Add((TH1F*) f->Get(histoName),1.0);
        histoName="mJ_antitagSB_"; histoName+=METbins[i]; histoName+="_SnglT";
        hD->Add((TH1F*) f->Get(histoName),1.0);
        D = hD->IntegralAndError(1,40,Derr);
        kappa[i] = C*B/D/A ;
        kappa[numMETbins+i]=sqrt(Berr*Berr/B/B+Cerr*Cerr/C/C+Derr*Derr/D/D+Aerr*Aerr/A/A)*C*B/D/A ;
        if( verbose ){
            cout << "B: " << B << " +/- " << Berr << endl;
            cout << "C: " << C << " +/- " << Cerr << endl;
            cout << "D: " << D << " +/- " << Derr << endl;
            cout << "Prediction: " << C*B/D << " +/- " << sqrt(Berr*Berr/B/B+Cerr*Cerr/C/C+Derr*Derr/D/D)*C*B/D << endl;
            cout << "A: " << A << " +/- " << Aerr << endl;
            cout << "kappa: " << kappa[i] << " +/- " << sqrt(Berr*Berr/B/B+Cerr*Cerr/C/C+Derr*Derr/D/D+Aerr*Aerr/A/A)*C*B/D/A << endl;
        }    
    }// end loop over MET bins
    f->Close();
    return kappa;
}
