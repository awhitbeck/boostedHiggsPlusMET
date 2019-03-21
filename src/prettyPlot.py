from sys import argv
import ROOT as r
r.gROOT.SetBatch(True)

r.gROOT.ProcessLine(".L ~/tdrstyle.C")
r.gROOT.ProcessLine("setTDRStyle()")

plot_dir="plotObs_baseline_plots"
input_file_name = "plotObs_ZSBNoVBF_baseline.root"
output_file_name = "ZSBNoVBF_baselineInputs.root"

input_file = r.TFile(input_file_name,"READ")    

def plot(plot_var = "photonIsoChrgLowSieie_EB_photonLoose" ):

    samples=[["QCD_200to300",
              "QCD_300to500",
              "QCD_500to700",
              "QCD_700to1000",
              "QCD_1000to1500",
              "QCD_1500to2000",
              "QCD_2000toInf"],
             ["ST_s-channel",
              "ST_t-channel_antitop",
              "ST_t-channel_top",
              "ST_tW_antitop",
              "ST_tW_antitop"],
             # "Other_WWTo1L1Nu2Q",
             # "Other_WWTo2L2Nu",
             # "Other_WWZ",
             # "Other_WZTo1L1Nu2Q",
             # "Other_WZTo1L3Nu",
             # "Other_WZZ",
             # "Other_ZZTo2L2Q",
             # "Other_ZZTo2Q2Nu",
             # "Other_ZZZ",
             # "Other_TTTT",
             # "Other_TTWJetsToLNu",
             # "Other_TTWJetsToQQ",
             # "Other_TTGJets",
             # "Other_TTZToLLNuNu",
             # "Other_TTZToQQ",
             # "Other_ST_s",
             # "Other_ST_t_antitop",
             # "Other_ST_t_top",
             # "Other_ST_tW_antitop",
             # "Other_ST_tW_top",
             ["ZJets_100to200",
              "ZJets_200to400",
              "ZJets_400to600",
              "ZJets_600to800",
              "ZJets_800to1200",
              "ZJets_1200to2500",
              "ZJets_2500toInf"],
             ["WJets_100to200",
              "WJets_200to400",
              "WJets_400to600",
              "WJets_600to800",
              "WJets_800to1200",
              "WJets_1200to2500",
              "WJets_2500toInf"],
             ["TT_600to800",
              "TT_800to1200",
              "TT_1200to2500",
              "TT_2500toInf"]
             ]

    data_samples=["MET_2016B",
              "MET_2016C",
              "MET_2016D",
              "MET_2016E",
              "MET_2016F",
              "MET_2016G",
              "MET_2016H"]

    samples_labels = ["QCD","Single top","ZJets","WJets","TT"]
    samples_fill_color = [r.kGray,r.kOrange,r.kGreen,r.kBlue,r.kRed]
    samples_line_color = [1,1,1,1,1]
    
    samples_histo=[]
    
    sum = None
    stack = r.THStack("stack","stack")
    
    for i,sample_names in enumerate(samples) :   
        for j,sample_name in enumerate(sample_names): 
            if len(samples_histo) <= i : 
                samples_histo.append(input_file.Get(plot_var+"_"+sample_name))
                if samples_histo[-1]==None :
                    print "looking for:",plot_var+"_"+sample_name
                    print input_file.ls(plot_var+"_"+sample_name)
                    #input_file.ls()
                    assert(samples_histo[-1]!=None)
                elif samples_histo[-1].Integral() < 0.0001 :
                    print "oops.",plot_var+"_"+sample_name,"is empty"
                samples_histo[-1].SetLineColor(samples_line_color[i])
                samples_histo[-1].SetFillColor(samples_fill_color[i])
                samples_histo[-1].SetName(plot_var+"_"+samples_labels[i])
            else : 
                samples_histo[-1].Add(input_file.Get(plot_var+"_"+sample_name))
            
    data_histo=[]
    for i,s in enumerate(data_samples):
        if i == 0 : 
            data_histo.append(input_file.Get(plot_var+"_"+s))
            data_histo[-1].SetMarkerStyle(8)
            data_histo[-1].SetName(plot_var+"_Data")
            if data_histo[-1]==None :
                print "looking for:",plot_var+"_"+sample_name
                #input_file.ls(plot_var+"*")
                #input_file.ls("*"+sample_name)
                assert(data_histo[-1]!=None)
        else : 
            data_histo[-1].Add(input_file.Get(plot_var+"_"+s))

    for i,h in enumerate(samples_histo) : 
        stack.Add(h)
        if i == 0 : 
            sum = r.TH1F(h)
            sum.SetName(plot_var+"_sum")
        else : 
            sum.Add(h)

    can = r.TCanvas("can","can",500,500)
    topPad = r.TPad("topPad","topPad",0.,0.4,.99,.99);
    botPad = r.TPad("botPad","botPad",0.,0.01,.99,.39);
    botPad.SetBottomMargin(0.35);
    botPad.SetTopMargin(0.02);
    topPad.SetTopMargin(0.06);
    topPad.SetBottomMargin(0.01);
    topPad.Draw();
    botPad.Draw();
    topPad.cd();
    
    stack.Draw("histo")    
    data_histo[0].Draw("SAME,p")

    stack.SetMaximum(1.3*max(sum.GetMaximum(),data_histo[0].GetMaximum()))
    stack.SetMinimum(0.1)

    stack.GetYaxis().SetTitle("Events")
    stack.GetYaxis().SetLabelFont(43);
    stack.GetYaxis().SetLabelSize(24);
    stack.GetYaxis().SetTitleFont(43);
    stack.GetYaxis().SetTitleSize(24);
    stack.GetYaxis().SetTitleOffset(1.5);

    stack.GetXaxis().SetLabelFont(43);
    stack.GetXaxis().SetLabelSize(24);
    stack.GetXaxis().SetTitleFont(43);
    stack.GetXaxis().SetTitleSize(24);
    stack.GetXaxis().SetTitleOffset(1.7);

    CMStext = r.TText(.17,.95,"CMS")
    CMStext.SetNDC()
    CMStext.SetTextFont(61)
    CMStext.SetTextSize(0.08)
    CMStext.Draw()
    
    SIMtext = r.TText(.28,.95,"preliminary")
    SIMtext.SetNDC()
    SIMtext.SetTextFont(52)
    SIMtext.SetTextSize(0.08)
    SIMtext.Draw()
    
    LUMItext = r.TText(.65,.95,"13 TeV (41.5/fb)")
    LUMItext.SetNDC()
    LUMItext.SetTextFont(51)
    LUMItext.SetTextSize(0.08)
    LUMItext.Draw()

    botPad.cd()
    ratio = r.TH1F(data_histo[0])
    ratio.SetMarkerStyle(8)
    ratio.SetName(plot_var+"_ratio")
    ratio.Divide(sum)
    ratio.GetYaxis().SetRangeUser(0,2)
    ratio.GetYaxis().SetTitle("Obs/Exp")
    ratio.GetXaxis().SetTitle(data_histo[0].GetTitle())
    ratio.GetYaxis().SetLabelFont(43);
    ratio.GetYaxis().SetLabelSize(24);
    ratio.GetYaxis().SetTitleFont(43);
    ratio.GetYaxis().SetTitleSize(24);
    ratio.GetYaxis().SetNdivisions(505);
    ratio.GetYaxis().SetTitleOffset(1.5);

    ratio.GetXaxis().SetLabelFont(43);
    ratio.GetXaxis().SetLabelSize(24);
    ratio.GetXaxis().SetTitleFont(43);
    ratio.GetXaxis().SetTitleSize(24);
    ratio.GetXaxis().SetTitleOffset(2.8);

    ratio.Draw()

    can.SaveAs("../plots/"+plot_dir+"/"+plot_var+".png")
    topPad.SetLogy()
    can.SaveAs("../plots/"+plot_dir+"/"+plot_var+"_LogY.png")

    output_file.cd()
    for h in samples_histo :
        r.TH1F(h).Write()
    data_histo[0].Write()

output_file = r.TFile(output_file_name,"RECREATE")
    
vars = []
list = input_file.GetListOfKeys()
next = r.TIter(list);
key = next()
while(key != None ) :
    obj = key.ReadObj();
    if obj.InheritsFrom("TH1") :
        name = r.TString(obj.GetName())
        if name.Contains("_QCD_300to500") : 
            #print name
            #print "integral:",obj.Integral()
            vars.append(name.ReplaceAll("_QCD_300to500","").Data())
    else :
        print obj.Print()
    key = next()

print vars
for var in vars : 
    plot(var)

    
output_file.Close()
input_file.Close()
