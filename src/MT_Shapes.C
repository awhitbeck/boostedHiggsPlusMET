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
 
    	TFile* f_1 = new TFile("plotObs_ZSidebandnoVBF.root");
        TFile* f_2 = new TFile("plotObs_ZSideband.root");
        TFile* f_3 = new TFile("plotObs_MCSRnoVBF.root");
        TFile* f_4 = new TFile("plotObs_MCSRVBF.root");
        TFile* f_out = new TFile("MT_Shapes_all.root","RECREATE");
	
  double scaleFactor1 = 1E-4; //Bg1
  double minYaxisRange = 1E-20; // Sets lower range on y-axis.
                                // Max value is set automatically.
   c1->cd();

	    TH1F *hist1   = (TH1F*)f_1->Get("ZMT1_ZSidebandnoVBF_sum");
        TH1F *hist2   = (TH1F*)f_2->Get("ZMT1_ZSideband_sum");
        TH1F *hist3   = (TH1F*)f_3->Get("ZMT1_MCSRnoVBF_sum");
        TH1F *hist4   = (TH1F*)f_4->Get("ZMT1_MCSRVBF_sum");

        //hist1->Draw("histL"); 
        //hist1->SetFillColorAlpha(kGreen, 0.35); 
        hist1->SetFillColorAlpha(0, 0.35); 
        hist1->SetLineColor(kBlack);
        hist1->Draw("histC"); 
        hist1->GetXaxis()->SetTitle("Transverse Mass"); 
        hist1->GetXaxis()->SetTitleSize(0.045); 
        hist1->GetXaxis()->CenterTitle(true);          
        //hist1->SetTitle("MT Shapes");          
  
        //hist3->SetFillColorAlpha(kYellow, 0.35); 
        hist3->SetFillColorAlpha(0, 0.35); 
        hist3->SetLineColor(kRed);
        hist3->Draw("histC same"); 
        
        hist2->SetLineColor(kMagenta);
        //hist2->SetFillColorAlpha(kBlue, 0.35); 
        hist2->SetFillColorAlpha(0, 0.35); 
        hist2->Draw("histC same"); 

        hist4->SetLineColor(kCyan);
        //hist2->SetFillColorAlpha(kGray, 0.35); 
        hist4->SetFillColorAlpha(0, 0.35); 
        hist4->Draw("histC same"); 

// Legend
TLegend* l=new TLegend(0.2,0.65,0.65,0.85);
l->SetTextSize(0.045);
l->AddEntry(hist1,"Z SB no VBF cut","l");
l->AddEntry(hist2,"Z SB VBF cut","l");
l->AddEntry(hist3,"MC SR no VBF cut","l");
l->AddEntry(hist4,"MC SR VBF cut","l");
//l->AddEntry(hist4,"MC SR VBF cut","C");

l->Draw();


     f_out->Write();
     c1->Print("MT_Shapes.pdf");
}
