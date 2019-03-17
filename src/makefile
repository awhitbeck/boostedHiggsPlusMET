CC=`root-config --cxx --cflags`
CFLAGS=`root-config --cflags`
LIBS=`root-config --glibs`
ROOFITLIBS=
INCLUDES=
EXECS=fitWpeak flavorFit plotObs_photon_baseline plotObs_singleEleCR_baseline plotObs_lowDPhi_baseline plotObs_singleHiggsTag plotObs_doubleHiggsTag plotObs_antitag plotObs_baseline plotObs_singleMuCR_baseline frankSynch cutFlow NminusOne ALPHABET ALPHABET_photon plotHiggsPt_TChiHH datacardInputs photonSkim WtaggingEfficiency.cc plotWtagDist.cc unblindSignalRegion.cc
$(EXECS):RA2bTree.cc skimSamples.cc plotterUtils.cc
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
plotWtagDist:plotWtagDist.cc
unblindSignalRegion:unblindSignalRegion.cc

all:$(EXECS) 

unblindSignalRegion:
	$(CC) $(CFLAGS)  $(ROOFITLIBS)  unblindSignalRegion.cc -o ../bin/$@ $(LIBS) $(INCLUDES)	
plotWtagDist:
	$(CC) $(CFLAGS)  $(ROOFITLIBS)  plotWtagDist.cc -o ../bin/$@ $(LIBS) $(INCLUDES)	
fitWpeak:
	$(CC) $(CFLAGS)  $(ROOFITLIBS)  fitWpeak.cc -o ../bin/$@ $(LIBS) $(INCLUDES)	
WtaggingEfficiency:
	$(CC) $(CFLAGS)  $(ROOFITLIBS)  WtaggingEfficiency.cc -o ../bin/$@ $(LIBS) $(INCLUDES)
photonSkim:
	$(CC) $(CFLAGS)  $(ROOFITLIBS)  photonSkim.cc -o ../bin/$@ $(LIBS) $(INCLUDES)
flavorFit:
	$(CC) $(CFLAGS)  $(ROOFITLIBS)  flavorFit.cc -o ../bin/$@ $(LIBS) $(INCLUDES)
plotObs_fastFullComp:
	$(CC) $(CFLAGS)   plotObs_fastFullComp.cc -o ../bin/$@ $(LIBS) $(INCLUDES)
ALPHABET:
	$(CC) $(CFLAGS)   ALPHABET.cc -o ../bin/$@ $(LIBS) $(INCLUDES)
ALPHABET_photon:
	$(CC) $(CFLAGS)   ALPHABET_photon.cc -o ../bin/$@ $(LIBS) $(INCLUDES)
cutFlow:
	$(CC) $(CFLAGS)   cutFlow.cc -o ../bin/$@ $(LIBS) $(INCLUDES)
frankSynch:
	$(CC) $(CFLAGS)   frankSynch.cc -o ../bin/$@ $(LIBS) $(INCLUDES)
NminusOne:
	$(CC) $(CFLAGS)   NminusOne.cc -o ../bin/$@ $(LIBS) $(INCLUDES)
plotObs_photon_baseline:
	$(CC) $(CFLAGS)   plotObs_photon_baseline.cc -o ../bin/$@ $(LIBS) $(INCLUDES)
plotObs_lowDPhi_baseline:
	$(CC) $(CFLAGS)   plotObs_lowDPhi_baseline.cc -o ../bin/$@ $(LIBS) $(INCLUDES)
plotObs_singleHiggsTag:
	$(CC) $(CFLAGS)   plotObs_singleHiggsTag.cc -o ../bin/$@ $(LIBS) $(INCLUDES)
plotObs_doubleHiggsTag:
	$(CC) $(CFLAGS)   plotObs_doubleHiggsTag.cc -o ../bin/$@ $(LIBS) $(INCLUDES)
plotObs_antitag:
	$(CC) $(CFLAGS)   plotObs_antitag.cc -o ../bin/$@ $(LIBS) $(INCLUDES)
plotObs_baseline:
	$(CC) $(CFLAGS)   plotObs_baseline.cc -o ../bin/$@ $(LIBS) $(INCLUDES)
plot2D:
	$(CC) $(CFLAGS)   plot2D.cc -o ../bin/$@ $(LIBS) $(INCLUDES)
plotObs_singleEleCR_baseline:
	$(CC) $(CFLAGS)   plotObs_singleEleCR_baseline.cc -o ../bin/$@ $(LIBS) $(INCLUDES)	
plotObs_singleMuCR_baseline:
	$(CC) $(CFLAGS)   plotObs_singleMuCR_baseline.cc -o ../bin/$@ $(LIBS) $(INCLUDES)	
plotHiggsPt_TChiHH:
	$(CC) $(CFLAGS)  $(ROOFITLIBS)  plotHiggsPt_TChiHH.cc -o ../bin/$@ $(LIBS) $(INCLUDES)
datacardInputs:
	$(CC) $(CFLAGS)  $(ROOFITLIBS)  datacardInputs.cc -o ../bin/$@ $(LIBS) $(INCLUDES)
clean : 
	rm ../bin/*
