//
//  TestRes.c
//  
//
//  Created by Rishi Patel on 6/9/17.
//
//

#include <stdio.h>

void TestRes(){
    TH1F*hUnsmear=new TH1F("hUnsmear", "", 100, 60, 100);
    TRandom3 rand;
    for(int i=0; i<1000; ++i){
        hUnsmear->Fill(rand.Gaus(80,7.23026));
    }
    hUnsmear->Draw();
    TH1F*hsmear=new TH1F("hsmear", "", 100, 60, 100);
    for(int i=1; i<=100; ++i){
        float MassPoint=hUnsmear->GetBinLowEdge(i);
        for(int j=1; j<hUnsmear->GetBinContent(i); ++j){
        float smearMass=MassPoint+(MassPoint-rand.Gaus(MassPoint,10.));
            hsmear->Fill(smearMass);
            std::cout<<"Mass Point"<<MassPoint<<" Smeared "<<smearMass<<std::endl;
        }
    }
    hsmear->Fit("gaus");
    hsmear->Draw("same");
    
}
