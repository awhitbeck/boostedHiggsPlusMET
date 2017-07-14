#include "computeKappa.C"

void kappaDistribution(
			/*
                       double corrTT_A=0.6,      double corrErrTT_A=0.25 ,
                       double corrTT_B=0.74,       double corrErrTT_B=0.14 ,
                       double corrTT_C=0.53,      double corrErrTT_C=0.08 ,
                       double corrTT_D=0.48,      double corrErrTT_D=0.031 ,
                       double corrWJets_A=0.6,    double corrErrWJets_A=0.25 ,
                       double corrWJets_B=0.74,    double corrErrWJets_B=0.14 ,
                       double corrWJets_C=0.53,    double corrErrWJets_C=0.08 ,
                       double corrWJets_D=0.48,    double corrErrWJets_D=0.031 ,
                       double corrZJets_A=0.51,   double corrErrZJets_A=0.18 ,
                       double corrZJets_B=1.2,   double corrErrZJets_B=0.18 ,
                       double corrZJets_C=0.36,   double corrErrZJets_C=0.021 ,
                       double corrZJets_D=0.41,   double corrErrZJets_D=0.0094 ,
                       double corrQCD_A=0.85,     double corrErrQCD_A=0.12 ,
                       double corrQCD_B=1.2,     double corrErrQCD_B=0.16 ,
                       double corrQCD_C=0.93,     double corrErrQCD_C=0.1 ,
                       double corrQCD_D=0.71,     double corrErrQCD_D=0.027,
                       bool doubletag = true
                       */
			double corrTT_A=0.58,      double corrErrTT_A=0.12 , //signal          
                       double corrTT_B=0.58,       double corrErrTT_B=0.049 ,//sideband       
                       double corrTT_C=0.53,      double corrErrTT_C=0.08 ,//antitag          
                       double corrTT_D=0.48,      double corrErrTT_D=0.031 ,//antitag sideband
                       double corrWJets_A=0.58,    double corrErrWJets_A=0.12 ,               
                       double corrWJets_B=0.58,    double corrErrWJets_B=0.049 ,              
                       double corrWJets_C=0.53,    double corrErrWJets_C=0.08 ,               
                       double corrWJets_D=0.48,    double corrErrWJets_D=0.031 ,              
                       double corrZJets_A=0.79,   double corrErrZJets_A=0.14 ,                
                       double corrZJets_B=0.91,   double corrErrZJets_B=0.06 ,                
                       double corrZJets_C=0.49,   double corrErrZJets_C=0.046 ,               
                       double corrZJets_D=0.6,   double corrErrZJets_D=0.02 ,                 
                       double corrQCD_A=1.1,     double corrErrQCD_A=0.33 ,                   
                       double corrQCD_B=0.88,     double corrErrQCD_B=0.04 ,                  
                       double corrQCD_C=0.93,     double corrErrQCD_C=0.1 ,                   
                       double corrQCD_D=0.71,     double corrErrQCD_D=0.027,                  
                       bool doubletag = false                                                                                                                                                         
                       ){

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    TH1F* kappaDistNV = new TH1F("kappaDistNV","kappaDistNV",3,290.,890.);
    vector<double> tempKappaNV = computeKappa(1.0,1.0,1.0,1.0,
                                              1.0,1.0,1.0,1.0,
                                              1.0,1.0,1.0,1.0,
                                              1.0,1.0,1.0,1.0,
                                              doubletag
                                              );

    kappaDistNV->SetBinContent(1,tempKappaNV[0]);
    kappaDistNV->SetBinError(1,tempKappaNV[3]);
    kappaDistNV->SetBinContent(2,tempKappaNV[1]);
    kappaDistNV->SetBinError(2,tempKappaNV[4]);
    kappaDistNV->SetBinContent(3,tempKappaNV[2]);
    kappaDistNV->SetBinError(3,tempKappaNV[5]);
    

    TH2F* kappaDist = new TH2F("kappaDist","kappaDist",3,300.,900.,100,0.,3.);
    TH2F* kappaDistPC = new TH2F("kappaDistPC","kappaDistPC",3,320.,920.,100,0.,3.);
    TH2F* kappaDistFC = new TH2F("kappaDistFC","kappaDistFC",3,340.,940.,100,0.,3.);
    TH2F* kappaDistFAC = new TH2F("kappaDistFAC","kappaDistFAC",3,360.,960.,100,0.,3.);

    if(doubletag){
	//MET systematics For TTBar, W and Z
	/*
	corrErrTT_A=sqrt((corrErrTT_A*corrErrTT_A)+(corrTT_A*0.8 * corrTT_A*0.8));
	corrErrTT_B=sqrt((corrErrTT_B*corrErrTT_B)+(corrTT_B*0.8 * corrTT_B*0.8));
	corrErrTT_C=sqrt((corrErrTT_C*corrErrTT_C)+(corrTT_C*0.8 * corrTT_C*0.8));
	corrErrTT_D=sqrt((corrErrTT_D*corrErrTT_D)+(corrTT_D*0.8 * corrTT_D*0.8));
	corrErrWJets_A=sqrt((corrErrWJets_A*corrErrWJets_A)+(corrWJets_A*0.8 * corrWJets_A*0.8));
	corrErrWJets_B=sqrt((corrErrWJets_B*corrErrWJets_B)+(corrWJets_B*0.8 * corrWJets_B*0.8));
	corrErrWJets_C=sqrt((corrErrWJets_C*corrErrWJets_C)+(corrWJets_C*0.8 * corrWJets_C*0.8));
	corrErrWJets_D=sqrt((corrErrWJets_D*corrErrWJets_D)+(corrWJets_D*0.8 * corrWJets_D*0.8));
	corrErrZJets_A=sqrt((corrErrZJets_A*corrErrZJets_A)+(corrZJets_A*0.6 * corrZJets_A*0.6));
	corrErrZJets_B=sqrt((corrErrZJets_B*corrErrZJets_B)+(corrZJets_B*0.6 * corrZJets_B*0.6));
	corrErrZJets_C=sqrt((corrErrZJets_C*corrErrZJets_C)+(corrZJets_C*0.6 * corrZJets_C*0.6));
	corrErrZJets_D=sqrt((corrErrZJets_D*corrErrZJets_D)+(corrZJets_D*0.6 * corrZJets_D*0.6));
	*/
    }
    vector<double> tempKappa,tempKappaPC,tempKappaFC,tempKappaFAC;
    TRandom rand;

    for( int i = 0 ; i < 1000 ; i++ ){

        if( i  % 100 == 0 ) 
            cout << "toy: " << i << endl;

        tempKappa = computeKappa(rand.Gaus(corrTT_A,corrErrTT_A),
                                 rand.Gaus(corrTT_B,corrErrTT_B),
                                 rand.Gaus(corrTT_C,corrErrTT_C),
                                 rand.Gaus(corrTT_D,corrErrTT_D),
                                 rand.Gaus(corrWJets_A,corrErrWJets_A),
                                 rand.Gaus(corrWJets_B,corrErrWJets_B),
                                 rand.Gaus(corrWJets_C,corrErrWJets_C),
                                 rand.Gaus(corrWJets_D,corrErrWJets_D),
                                 rand.Gaus(corrZJets_A,corrErrZJets_A),
                                 rand.Gaus(corrZJets_B,corrErrZJets_B),
                                 rand.Gaus(corrZJets_C,corrErrZJets_C),
                                 rand.Gaus(corrZJets_D,corrErrZJets_D),
                                 rand.Gaus(corrQCD_A,corrErrQCD_A),
                                 rand.Gaus(corrQCD_B,corrErrQCD_B),
                                 rand.Gaus(corrQCD_C,corrErrQCD_C),
                                 rand.Gaus(corrQCD_D,corrErrQCD_D),
                                 doubletag
                                 );

        //cout << "tempKappa size: " << tempKappa.size() << endl;
        assert(tempKappa.size()==6);
        kappaDist->Fill(400.,tempKappa[0]);
        kappaDist->Fill(600.,tempKappa[1]);
        kappaDist->Fill(800.,tempKappa[2]);

        double TTdoubletag = rand.Gaus(0.,1.);
        double TTantitag = rand.Gaus(0.,1.);
        double WJetsdoubletag = rand.Gaus(0.,1.);
        double WJetsantitag = rand.Gaus(0.,1.);
        double ZJetsdoubletag = rand.Gaus(0.,1.);
        double ZJetsantitag = rand.Gaus(0.,1.);
        double QCDdoubletag = rand.Gaus(0.,1.);
        double QCDantitag = rand.Gaus(0.,1.);
        
        tempKappaPC = computeKappa(TTdoubletag*corrErrTT_A+corrTT_A,
                                   TTdoubletag*corrErrTT_B+corrTT_B,
                                   TTantitag*corrErrTT_C+corrTT_C,
                                   TTantitag*corrErrTT_D+corrTT_D,
                                   WJetsdoubletag*corrErrWJets_A+corrWJets_A,
                                   WJetsdoubletag*corrErrWJets_B+corrWJets_B,
                                   WJetsantitag*corrErrWJets_C+corrWJets_C,
                                   WJetsantitag*corrErrWJets_D+corrWJets_D,
                                   ZJetsdoubletag*corrErrZJets_A+corrZJets_A,
                                   ZJetsdoubletag*corrErrZJets_B+corrZJets_B,
                                   ZJetsantitag*corrErrZJets_C+corrZJets_C,
                                   ZJetsantitag*corrErrZJets_D+corrZJets_D,
                                   QCDdoubletag*corrErrQCD_A+corrQCD_A,
                                   QCDdoubletag*corrErrQCD_B+corrQCD_B,
                                   QCDantitag*corrErrQCD_C+corrQCD_C,
                                   QCDantitag*corrErrQCD_D+corrQCD_D,
                                   true);

        //cout << "tempKappaPC size: " << tempKappaPC.size() << endl;
        assert(tempKappaPC.size()==6);
        kappaDistPC->Fill(400.,tempKappaPC[0]);
        kappaDistPC->Fill(600.,tempKappaPC[1]);
        kappaDistPC->Fill(800.,tempKappaPC[2]);

        tempKappaFC = computeKappa(TTdoubletag*corrErrTT_A+corrTT_A,
                                   TTdoubletag*corrErrTT_B+corrTT_B,
                                   TTdoubletag*corrErrTT_C+corrTT_C,
                                   TTdoubletag*corrErrTT_D+corrTT_D,
                                   WJetsdoubletag*corrErrWJets_A+corrWJets_A,
                                   WJetsdoubletag*corrErrWJets_B+corrWJets_B,
                                   WJetsdoubletag*corrErrWJets_C+corrWJets_C,
                                   WJetsdoubletag*corrErrWJets_D+corrWJets_D,
                                   ZJetsdoubletag*corrErrZJets_A+corrZJets_A,
                                   ZJetsdoubletag*corrErrZJets_B+corrZJets_B,
                                   ZJetsdoubletag*corrErrZJets_C+corrZJets_C,
                                   ZJetsdoubletag*corrErrZJets_D+corrZJets_D,
                                   QCDdoubletag*corrErrQCD_A+corrQCD_A,
                                   QCDdoubletag*corrErrQCD_B+corrQCD_B,
                                   QCDdoubletag*corrErrQCD_C+corrQCD_C,
                                   QCDdoubletag*corrErrQCD_D+corrQCD_D,
                                   doubletag
                                   );

        //cout << "tempKappaFC size: " << tempKappaFC.size() << endl;
        assert(tempKappaFC.size()==6);
        kappaDistFC->Fill(400.,tempKappaFC[0]);
        kappaDistFC->Fill(600.,tempKappaFC[1]);
        kappaDistFC->Fill(800.,tempKappaFC[2]);

        tempKappaFAC = computeKappa(TTdoubletag*corrErrTT_A+corrTT_A,
                                    TTdoubletag*corrErrTT_B+corrTT_B,
                                    -TTdoubletag*corrErrTT_C+corrTT_C,
                                    -TTdoubletag*corrErrTT_D+corrTT_D,
                                    WJetsdoubletag*corrErrWJets_A+corrWJets_A,
                                    WJetsdoubletag*corrErrWJets_B+corrWJets_B,
                                    -WJetsdoubletag*corrErrWJets_C+corrWJets_C,
                                    -WJetsdoubletag*corrErrWJets_D+corrWJets_D,
                                    ZJetsdoubletag*corrErrZJets_A+corrZJets_A,
                                    ZJetsdoubletag*corrErrZJets_B+corrZJets_B,
                                    -ZJetsdoubletag*corrErrZJets_C+corrZJets_C,
                                    -ZJetsdoubletag*corrErrZJets_D+corrZJets_D,
                                    QCDdoubletag*corrErrQCD_A+corrQCD_A,
                                    QCDdoubletag*corrErrQCD_B+corrQCD_B,
                                    -QCDdoubletag*corrErrQCD_C+corrQCD_C,
                                    -QCDdoubletag*corrErrQCD_D+corrQCD_D,
                                    doubletag
                                    );

        //cout << "tempKappaFAC size: " << tempKappaFAC.size() << endl;
        assert(tempKappaFAC.size()==6);
        kappaDistFAC->Fill(400.,tempKappaFAC[0]);
        kappaDistFAC->Fill(600.,tempKappaFAC[1]);
        kappaDistFAC->Fill(800.,tempKappaFAC[2]);

    } 
    
    //kappaDist->Draw("colz");
    TProfile* prof = kappaDist->ProfileX("prof",1,-1,"S");
    prof->SetMarkerStyle(8);
    prof->GetYaxis()->SetRangeUser(0.,2.);
    prof->GetYaxis()->SetTitle("#kappa");
    prof->GetXaxis()->SetTitle("MET [GeV]");

    TProfile* profPC = kappaDistPC->ProfileX("profPC",1,-1,"S");
    profPC->SetMarkerStyle(8);
    profPC->SetMarkerColor(2);
    profPC->SetLineColor(2);
    profPC->GetYaxis()->SetRangeUser(0.,2.);
    profPC->GetYaxis()->SetTitle("#kappa");
    profPC->GetXaxis()->SetTitle("MET [GeV]");

    TProfile* profFC = kappaDistFC->ProfileX("profFC",1,-1,"S");
    profFC->SetMarkerStyle(8);
    profFC->SetMarkerColor(4);
    profFC->SetLineColor(4);
    profFC->GetYaxis()->SetRangeUser(0.,2.);
    profFC->GetYaxis()->SetTitle("#kappa");
    profFC->GetXaxis()->SetTitle("MET [GeV]");

    TProfile* profFAC = kappaDistFAC->ProfileX("profFAC",1,-1,"S");
    profFAC->SetMarkerStyle(8);
    profFAC->SetMarkerColor(kMagenta);
    profFAC->SetLineColor(kMagenta);
    profFAC->GetYaxis()->SetRangeUser(0.,2.);
    profFAC->GetYaxis()->SetTitle("#kappa");
    profFAC->GetXaxis()->SetTitle("MET [GeV]");

    kappaDistNV->SetMarkerStyle(4);    

    prof->Draw();
    profPC->Draw("SAME");
    profFC->Draw("SAME");
    profFAC->Draw("SAME");
    kappaDistNV->Draw("SAME");


    cout << "kappa(300<MET<500): " << prof->GetBinContent(1) << " +/- " << prof->GetBinError(1) << endl;
    cout << "kappa(500<MET<700): " << prof->GetBinContent(2) << " +/- " << prof->GetBinError(2) << endl;
    cout << "kappa(700<MET<inf): " << prof->GetBinContent(3) << " +/- " << prof->GetBinError(3) << endl;
    QuantilekappaDist=(TH1D*)kappaDist->QuantilesX(0.5, "METBinKappa");
    QuantilekappaDistSigma=(TH1D*)kappaDist->QuantilesX(0.5+0.34, "METBinKappaSigma");
    cout<<"kappa(300<MET<500): Quantiles "<<QuantilekappaDist->GetBinContent(1)<<" +/- "<< QuantilekappaDistSigma->GetBinContent(1)-QuantilekappaDist->GetBinContent(1)<<endl;
    cout<<"kappa(500<MET<700): Quantiles "<<QuantilekappaDist->GetBinContent(2)<<" +/- "<< QuantilekappaDistSigma->GetBinContent(2)-QuantilekappaDist->GetBinContent(2)<<endl;
    cout<<"kappa(700<MET): Quantiles "<<QuantilekappaDist->GetBinContent(3)<<" +/- "<< QuantilekappaDistSigma->GetBinContent(3)-QuantilekappaDist->GetBinContent(3)<<endl;
    cout << "kappaPC(300<MET<500): " << profPC->GetBinContent(1) << " +/- " << profPC->GetBinError(1) << endl;
    cout << "kappaPC(500<MET<700): " << profPC->GetBinContent(2) << " +/- " << profPC->GetBinError(2) << endl;
    cout << "kappaPC(700<MET<inf): " << profPC->GetBinContent(3) << " +/- " << profPC->GetBinError(3) << endl;

    cout << "kappaFC(300<MET<500): " << profFC->GetBinContent(1) << " +/- " << profFC->GetBinError(1) << endl;
    cout << "kappaFC(500<MET<700): " << profFC->GetBinContent(2) << " +/- " << profFC->GetBinError(2) << endl;
    cout << "kappaFC(700<MET<inf): " << profFC->GetBinContent(3) << " +/- " << profFC->GetBinError(3) << endl;

    cout << "kappaFAC(300<MET<500): " << profFAC->GetBinContent(1) << " +/- " << profFAC->GetBinError(1) << endl;
    cout << "kappaFAC(500<MET<700): " << profFAC->GetBinContent(2) << " +/- " << profFAC->GetBinError(2) << endl;
    cout << "kappaFAC(700<MET<inf): " << profFAC->GetBinContent(3) << " +/- " << profFAC->GetBinError(3) << endl;

}
