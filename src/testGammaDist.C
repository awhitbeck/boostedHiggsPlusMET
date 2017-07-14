// Code from http://www.hongliangjie.com/2012/12/19/how-to-generate-gamma-random-variables/
// Parameter b could be theta...
double gsl_ran_gamma(const double a, const double b, TRandom3 &rand){
  if (a < 1){
    double u = rand.Uniform(1);
    return gsl_ran_gamma(1.0 + a, b, rand) * pow (u, 1.0 / a);
  }

  double x, v, u;
  double d = a - 1.0 / 3.0;
  double c = (1.0 / 3.0) / sqrt (d);
  
  while (1) {
    do {
      x = rand.Gaus(0, 1.0);
      v = 1.0 + c * x;
    }
    while (v <= 0);
      
    v = v * v * v;
    u = rand.Uniform(1);

    if (u < 1 - 0.0331 * x * x * x * x) 
      break;

    if (log (u) < 0.5 * x * x + d * (1 - v + log (v)))
      break;
  }
    
  return b * d * v;
}

const int trials=10000;

TGraphAsymmErrors* computeRatio(vector<TH1F*> num,vector<TH1F*> den,TString tag="ratio"){

  TRandom3 rand(1234);
  TH2F* ratio = new TH2F("ratio","ratio",num[0]->GetNbinsX()+1,num[0]->GetBinLowEdge(1),num[0]->GetBinLowEdge(num[0]->GetNbinsX()+1)+num[0]->GetBinWidth(num[0]->GetNbinsX()+1),100,0.,3.);
  TGraphAsymmErrors* graph = new TGraphAsymmErrors();

  for( int iEvt = 0 ; iEvt < trials ; iEvt++ ){  
   for( int b = 1 ; b <= num[0]->GetNbinsX()+1 ; b++ ){
      double num_=0.;
      double den_=0.;
      for( int s = 0 ; s < num.size() ; s++ ){
        if( num[s]->GetBinContent(b) == 0. ) continue;      
        double meanWeight=num[s]->GetBinError(b)*num[s]->GetBinError(b)/num[s]->GetBinContent(b);
        double rawYield=num[s]->GetBinContent(b)*num[s]->GetBinContent(b)/num[s]->GetBinError(b)/num[s]->GetBinError(b);
        cout << "meanWeight: " << meanWeight << endl;
        cout << "meanYield: " << rawYield << endl;
        num_+=gsl_ran_gamma(rawYield-1,meanWeight,rand);
      }
      for( int s = 0 ; s < den.size() ; s++){
         if( den[s]->GetBinContent(b) == 0. ) continue;  
         double meanWeight=den[s]->GetBinError(b)*den[s]->GetBinError(b)/den[s]->GetBinContent(b);
         double rawYield=den[s]->GetBinContent(b)*den[s]->GetBinContent(b)/den[s]->GetBinError(b)/den[s]->GetBinError(b);
         cout << "meanWeight: " << meanWeight << endl;
         cout << "meanYield: " << rawYield << endl;
         den_+=gsl_ran_gamma(rawYield-1,meanWeight,rand);
      }// loop over samples
      ratio->Fill(num[0]->GetBinCenter(b),num_/den_);
    }// loop over bins
  }// loop over i events


  float binWidth=num[0]->GetBinWidth(1);
  TH1F* METBinKappa= (TH1F*) ratio->QuantilesX(0.5, "METBinKappa");  
  TH1F* METBinKappaUncUp= (TH1F*) ratio->QuantilesX(0.5+0.34, "METBinKappaUnc_high");
  TH1F* METBinKappaUncDn= (TH1F*) ratio->QuantilesX(0.5-0.34, "METBinKappaUnc_low");
  for( int b = 1 ; b <= num[0]->GetNbinsX()+1 ; b++ ){  
    float RatioErrorUp=fabs(METBinKappaUncUp->GetBinContent(b)-METBinKappa->GetBinContent(b));
    float RatioErrorDn=METBinKappa->GetBinContent(b)-METBinKappaUncDn->GetBinContent(b);
    graph->SetPoint(b-1, num[0]->GetBinCenter(b), METBinKappa->GetBinContent(b));
    graph->SetPointError(b-1, binWidth/2., binWidth/2., RatioErrorDn,RatioErrorUp);
    //if(b==4) Closure.SetPointError(b-1, binWidth/2.,binWidth/2., RatioErrorDn,RatioErrorUp);
  }
  return graph;
}

void testGammaDist(){
  
  TFile* f = new TFile("~awhitbe1/eos/boostedHiggsPlusMET/ca30b258ba0d17066ce11a50908e1507d3371e17/ALPHABEThistos_photon.root","READ");

  vector<TH1F*> nums,dens;

  TString tag = "antitagSB";
/*
  nums.push_back((TH1F*)f->Get("MET_"+tag+"_Other"));
  nums.push_back((TH1F*)f->Get("MET_"+tag+"_WJets"));
  nums.push_back((TH1F*)f->Get("MET_"+tag+"_SnglT"));
  nums.push_back((TH1F*)f->Get("MET_"+tag+"_TT"));
*/
  nums.push_back((TH1F*)f->Get("MET_"+tag+"_Other"));
  nums.push_back((TH1F*)f->Get("MET_"+tag+"_GJets"));
  nums.push_back((TH1F*)f->Get("MET_"+tag+"_QCD"));

  cout << nums[0] << endl;
  cout << nums[1] << endl;
  cout << nums[2] << endl;
  cout << nums[3] << endl;

  dens.push_back((TH1F*)f->Get("MET_"+tag+"_data"));

  TGraphAsymmErrors* ratio = computeRatio(dens,nums);

  ratio->Draw("Ap");

}
