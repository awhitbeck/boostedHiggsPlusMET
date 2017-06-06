CC=g++
CFLAGS=
LIBS=`root-config --cflags --glibs` -L $(ROOTSYS)/lib -I$(ROOTSYS)/include
ROOFITLIBS=-lRooFit -lHtml -lMinuit -lRooFitCore
INCLUDES=-I$(CMSSW_BASE)/src/AnalysisTools/src/ -I$(CMSSW_BASE)/src/ -I$(CMSSW_BASE)/src/Analysis/btag/
EXECS=fitWpeak flavorFit plotObs_photon_baseline plotObs_singleEleCR_baseline plotObs_lowDPhi_baseline plotObs_singleHiggsTag plotObs_doubleHiggsTag plotObs_antitag plotObs_baseline plotObs_singleMuCR_baseline frankSynch cutFlow NminusOne ALPHABET ALPHABET_photon plotHiggsPt_TChiHH datacardInputs photonSkim WtaggingEfficiency.cc
$(EXECS):RA2bTree.cc definitions.cc skimSamples.cc plotterUtils.cc
flavorFit:flavorFit.cc
fitWpeak:fitWpeak.cc
plotObs_singleEleCR_baseline:plotObs_singleEleCR_baseline.cc
plotObs_singleMuCR_baseline:plotObs_singleMuCR_baseline.cc
plotObs_baseline:plotObs_baseline.cc
plotObs_antitag:plotObs_antitag.cc
plotObs_photon_baseline:plotObs_photon_baseline.cc
plotObs_lowDPhi_baseline:plotObs_lowDPhi_baseline.cc
plotObs_doubleHiggsTag:plotObs_doubleHiggsTag.cc
plotObs_singleHiggsTag:
plotHiggsPt_TChiHH:plotHiggsPt_TChiHH.cc
cutFlow:cutFlow.cc RA2bTree.cc skimSamples.cc
frankSynch:frankSynch.cc RA2bTree.cc skimSamples.cc
NminusOne:NminusOne.cc RA2bTree.cc skimSamples.cc
ALPHABET:ALPHABET.cc
ALPHABET_photon:ALPHABET_photon.cc
datacardInputs:datacardInputs.cc
photonSkim:photonSkim.cc
WtaggingEfficiency:WtaggingEfficiency.cc
all:$(EXECS) 

fitWpeak:
	$(CC) -g $(CFLAGS) $(LIBS) $(ROOFITLIBS) $(INCLUDES) fitWpeak.cc -o ../bin/$@	
WtaggingEfficiency:
	$(CC) -g $(CFLAGS) $(LIBS) $(ROOFITLIBS) $(INCLUDES) WtaggingEfficiency.cc -o ../bin/$@
photonSkim:
	$(CC) -g $(CFLAGS) $(LIBS) $(ROOFITLIBS) $(INCLUDES) photonSkim.cc -o ../bin/$@
flavorFit:
	$(CC) -g $(CFLAGS) $(LIBS) $(ROOFITLIBS) $(INCLUDES) flavorFit.cc -o ../bin/$@
plotObs_fastFullComp:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_fastFullComp.cc -o ../bin/$@
ALPHABET:
	$(CC) -g $(CFLAGS) $(LIBS) $(INCLUDES) ALPHABET.cc -o ../bin/$@
ALPHABET_photon:
	$(CC) -g $(CFLAGS) $(LIBS) $(INCLUDES) ALPHABET_photon.cc -o ../bin/$@
cutFlow:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) cutFlow.cc -o ../bin/$@
frankSynch:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) frankSynch.cc -o ../bin/$@
NminusOne:
	$(CC) -g $(CFLAGS) $(LIBS) $(INCLUDES) NminusOne.cc -o ../bin/$@
plotObs_photon_baseline:
	$(CC) -g $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_photon_baseline.cc -o ../bin/$@
plotObs_lowDPhi_baseline:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_lowDPhi_baseline.cc -o ../bin/$@
plotObs_singleHiggsTag:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_singleHiggsTag.cc -o ../bin/$@
plotObs_doubleHiggsTag:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_doubleHiggsTag.cc -o ../bin/$@
plotObs_antitag:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_antitag.cc -o ../bin/$@
plotObs_baseline:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_baseline.cc -o ../bin/$@
plotObs_singleEleCR_baseline:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_singleEleCR_baseline.cc -o ../bin/$@	
plotObs_singleMuCR_baseline:
	$(CC) -g $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_singleMuCR_baseline.cc -o ../bin/$@	
plotHiggsPt_TChiHH:
	$(CC) $(CFLAGS) $(LIBS) $(ROOFITLIBS) $(INCLUDES) plotHiggsPt_TChiHH.cc -o ../bin/$@
datacardInputs:
	$(CC) $(CFLAGS) $(LIBS) $(ROOFITLIBS) $(INCLUDES) datacardInputs.cc -o ../bin/$@
clean : 
	rm ../bin/*