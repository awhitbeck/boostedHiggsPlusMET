{
   gROOT->Reset();
   gROOT->SetStyle("Plain");
   gStyle->SetPalette(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptFit(1111);
   gStyle->SetOptStat("emri");
   
   const int n = 4;
   const int aa = 0;

   //c1 = new TCanvas("c1","multigraph",0,100,700,600);
   c1 = new TCanvas("c1","c1",800,1000);
 
    TFile* f_1 = new TFile("plotObs_ZSRHPVBF_Loose_Sig.root");
    TFile* f_2 = new TFile("plotObs_ZSRHPVBF_Loose.root");
    //TFile* f_1 = new TFile("plotObs_ZSRHPVBF-Test-RecoMG2.root");
    //TFile* f_2 = new TFile("plotObs_Selection_Nov92018_root/plotObs_ZSRHPVBF.root");
	
  double scaleFactor1 = 1E-4; //Bg1
  double minYaxisRange = 1E-20; // Sets lower range on y-axis.
                                // Max value is set automatically.
   c1->cd();

        //TH1F *h1   = (TH1F*)f_1->Get("GMass2_ZSRHPVBF-Test1_VBFG1000");
        TH1F *h1   = (TH1F*)f_1->Get("ZMT_ZSRHPVBF_Loose_Sig_VBFG1000");
        TH1F *h2   = (TH1F*)f_1->Get("ZMT_ZSRHPVBF_Loose_Sig_VBFG1200");
        TH1F *h3   = (TH1F*)f_1->Get("ZMT_ZSRHPVBF_Loose_Sig_VBFG1400");
        TH1F *h4   = (TH1F*)f_1->Get("ZMT_ZSRHPVBF_Loose_Sig_VBFG1600");
        TH1F *h5   = (TH1F*)f_1->Get("ZMT_ZSRHPVBF_Loose_Sig_VBFG1800");
        TH1F *h6   = (TH1F*)f_1->Get("ZMT_ZSRHPVBF_Loose_Sig_VBFG2000");
        TH1F *h7   = (TH1F*)f_1->Get("ZMT_ZSRHPVBF_Loose_Sig_VBFG2500");
        TH1F *h8   = (TH1F*)f_1->Get("ZMT_ZSRHPVBF_Loose_Sig_VBFG3000");
        TH1F *h9   = (TH1F*)f_1->Get("ZMT_ZSRHPVBF_Loose_Sig_VBFG3500");
        TH1F *h10  = (TH1F*)f_1->Get("ZMT_ZSRHPVBF_Loose_Sig_VBFG4000");
        TH1F *h11  = (TH1F*)f_1->Get("ZMT_ZSRHPVBF_Loose_Sig_VBFG4500");
        TH1F *h12  = (TH1F*)f_2->Get("ZMT_ZSRHPVBF_Loose_sum");
/*
         int nbins1=h11->GetNbinsX();
         double yval1=h11->GetBinContent(nbins1+1);
         double yval11=h11->GetBinContent(h1->GetNbinsX()+1);
        std::cout<<std::endl;
        std::cout<<"Integral for 1000 after all cut + Overflow:: "<<h11->Integral()+yval1<<std::endl;
        std::cout<<"Integral for 1000 after all cut + Overflow2:: "<<h11->Integral()+yval11<<std::endl;
*/
        std::cout<<std::endl;
        std::cout<<"Integral for 1000 after all cut:: "<<h1->Integral()<<std::endl;
        std::cout<<"Integral for 1200 after all cut:: "<<h2->Integral()<<std::endl;
        std::cout<<"Integral for 1400 after all cut:: "<<h3->Integral()<<std::endl;
        std::cout<<"Integral for 1600 after all cut:: "<<h4->Integral()<<std::endl;
        std::cout<<"Integral for 1800 after all cut:: "<<h5->Integral()<<std::endl;
        std::cout<<"Integral for 2000 after all cut:: "<<h6->Integral()<<std::endl;
        std::cout<<"Integral for 2500 after all cut:: "<<h7->Integral()<<std::endl;
        std::cout<<"Integral for 3000 after all cut:: "<<h8->Integral()<<std::endl;
        std::cout<<"Integral for 3500 after all cut:: "<<h9->Integral()<<std::endl;
        std::cout<<"Integral for 4000 after all cut:: "<<h10->Integral()<<std::endl;
        std::cout<<"Integral for 4500 after all cut:: "<<h11->Integral()<<std::endl;
        std::cout<<"Integral for BkgSum after all cut:: "<<h12->Integral()<<std::endl;
        std::cout<<std::endl;
}
