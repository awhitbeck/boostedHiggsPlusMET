CC=g++
CFLAGS=
LIBS=`root-config --cflags --glibs` -L $(ROOTSYS)/lib -I$(ROOTSYS)/include
ROOFITLIBS=-lRooFit -lHtml -lMinuit -lRooFitCore
INCLUDES=-I$(CMSSW_BASE)/src/AnalysisTools/src/ -I$(CMSSW_BASE)/src/ -I$(CMSSW_BASE)/src/Analysis/btag/
EXECS=flavorFit plotObs_photon_baseline plotObs_singleEleCR_baseline plotObs_photon_doubleHiggsTag plotObs_photon_antitag plotObs_lowDPhi_baseline plotObs_lowDPhi_antitag plotObs_lowDPhi_doubleHiggsTag plotObs_singleHiggsTag plotObs_doubleHiggsTag plotObs_antitag plotObs_baseline plotObs_singleMuCR_antitag plotObs_singleMuCR_singleHiggsTag plotObs_singleMuCR_doubleHiggsTag plotObs_singleMuCR_baseline baselineSkim singleMuCRSkim datacardInputs datacardInputs_MET_BTag1_DeltaPhi12 cutFlow_HIggsinoOnly frankSynch cutFlow NminusOne J1BB_NminusOne J2BB_NminusOne J1M_NminusOne J2M_NminusOne J1Pt_NminusOne J2Pt_NminusOne ALPHABET ALPHABET_photon plotObs_fastFullComp analyzeALPHABET analyzeRpassFail testBTagSF
$(EXECS):RA2bTree.cc definitions.cc skimSamples.cc plotterUtils.cc
flavorFit:flavorFit.cc
baselineSkim:sampleParser.cc selectBaseline.cc baselineSkim.cc
datacardInputs:datacardInputs.cc
datacardInputs_MET:datacardInputs_MET.cc
datacardInputs_MET_BTags1_DeltaPhi12:datacardInputs_MET_BTags1_DeltaPhi12.cc
singleMuCRSkim:singleMuCRSkim.cc sampleParser.cc selectBaseline.cc 
plotObs_photon_doubleHiggsTag: plotObs_photon_doubleHiggsTag.cc
plotObs_photon_antitag: plotObs_photon_antitag.cc
plotObs_singleEleCR_baseline:plotObs_singleEleCR_baseline.cc
plotObs_singleMuCR_singleHiggsTag:plotObs_singleMuCR_singleHiggsTag.cc
plotObs_singleMuCR_baseline:plotObs_singleMuCR_baseline.cc
plotObs_singleMuCR_antitag:plotObs_singleMuCR_antitag.cc
plotObs_baseline:plotObs_baseline.cc
plotObs_antitag:plotObs_antitag.cc
plotObs_photon_baseline:plotObs_photon_baseline.cc
plotObs_lowDPhi_baseline:plotObs_lowDPhi_baseline.cc
plotObs_lowDPhi_antitag:plotObs_lowDPhi_antitag.cc
plotObs_lowDPhi_doubleHiggsTag:plotObs_lowDPhi_doubleHiggsTag.cc
plotObs_singleMuCR_doubleHiggsTag:plotObs_singleMuCR_doubleHiggsTag.cc
plotObs_doubleHiggsTag:plotObs_doubleHiggsTag.cc
plotObs_singleHiggsTag:
FulltoyValidation:FulltoyValidation.cc
FulltoyValidation_ALPHABET:FulltoyValidation_ALPHABET.cc
plotHiggsPt_TChiHH:plotHiggsPt_TChiHH.cc
plotObs_doubleHiggsTag_HiggsinoOnly:plotObs_doubleHiggsTag_HiggsinoOnly.cc RA2bTree.cc skimSamplesHiggsinoOnly.cc
cutFlow_HiggsinoOnly:cutFlow_HiggsinoOnly.cc RA2bTree.cc skimSamplesHiggsinoOnly.cc
cutFlow:cutFlow.cc RA2bTree.cc skimSamples.cc
frankSynch:frankSynch.cc RA2bTree.cc skimSamples.cc
NminusOne:NminusOne.cc RA2bTree.cc skimSamples.cc
J1Pt_NminusOne:J1Pt_NminusOne.cc RA2bTree.cc skimSamples.cc
J2Pt_NminusOne:J2Pt_NminusOne.cc RA2bTree.cc skimSamples.cc
J1M_NminusOne:J1M_NminusOne.cc RA2bTree.cc skimSamples.cc
J2M_NminusOne:J2M_NminusOne.cc RA2bTree.cc skimSamples.cc
J1BB_NminusOne:J1BB_NminusOne.cc RA2bTree.cc skimSamples.cc
J2BB_NminusOne:J2BB_NminusOne.cc RA2bTree.cc skimSamples.cc
ALPHABET:ALPHABET.cc
ALPHABET_photon:ALPHABET_photon.cc
analyzeALPHABET:analyzeALPHABET.cc
analyzeRpassFail:analyzeRpassFail.cc
plotObs_fastFullComp:plotObs_fastFullComp.cc fastFullSamples.cc
testBTagSF:testBTagSF.cc

all:$(EXECS) FulltoyValidation plotHiggsPt_TChiHH

testBTagSF:
	$(CC) -g $(CFLAGS) $(LIBS) $(INCLUDES) testBTagSF.cc -o ../bin/$@
flavorFit:
	$(CC) -g $(CFLAGS) $(LIBS) $(ROOFITLIBS) $(INCLUDES) flavorFit.cc -o ../bin/$@
plotObs_fastFullComp:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_fastFullComp.cc -o ../bin/$@
ALPHABET:
	$(CC) -g $(CFLAGS) $(LIBS) $(INCLUDES) ALPHABET.cc -o ../bin/$@
ALPHABET_photon:
	$(CC) -g $(CFLAGS) $(LIBS) $(INCLUDES) ALPHABET_photon.cc -o ../bin/$@
analyzeALPHABET:
	$(CC) -g $(CFLAGS) $(LIBS) $(INCLUDES) analyzeALPHABET.cc -o ../bin/$@
analyzeRpassFail:
	$(CC) -g $(CFLAGS) $(LIBS) $(INCLUDES) analyzeRpassFail.cc -o ../bin/$@
cutFlow_HiggsinoOnly:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) cutFlow_HiggsinoOnly.cc -o ../bin/$@
cutFlow:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) cutFlow.cc -o ../bin/$@
frankSynch:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) frankSynch.cc -o ../bin/$@
NminusOne:
	$(CC) -g $(CFLAGS) $(LIBS) $(INCLUDES) NminusOne.cc -o ../bin/$@
J1Pt_NminusOne:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) J1Pt_NminusOne.cc -o ../bin/$@
J2Pt_NminusOne:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) J2Pt_NminusOne.cc -o ../bin/$@
J1M_NminusOne:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) J1M_NminusOne.cc -o ../bin/$@
J2M_NminusOne:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) J2M_NminusOne.cc -o ../bin/$@
J1BB_NminusOne:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) J1BB_NminusOne.cc -o ../bin/$@
J2BB_NminusOne:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) J2BB_NminusOne.cc -o ../bin/$@
plotObs_photon_baseline:
	$(CC) -g $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_photon_baseline.cc -o ../bin/$@
plotObs_lowDPhi_baseline:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_lowDPhi_baseline.cc -o ../bin/$@
plotObs_lowDPhi_doubleHiggsTag:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_lowDPhi_doubleHiggsTag.cc -o ../bin/$@
plotObs_lowDPhi_antitag:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_lowDPhi_antitag.cc -o ../bin/$@
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
plotObs_singleMuCR_doubleHiggsTag:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_singleMuCR_doubleHiggsTag.cc -o ../bin/$@	
plotObs_singleMuCR_baseline:
	$(CC) -g $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_singleMuCR_baseline.cc -o ../bin/$@	
plotObs_singleMuCR_antitag:
	$(CC) -g $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_singleMuCR_antitag.cc -o ../bin/$@
plotObs_singleMuCR_singleHiggsTag:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_singleMuCR_singleHiggsTag.cc -o ../bin/$@
baselineSkim:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) baselineSkim.cc -o ../bin/$@
singleMuCRSkim:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) singleMuCRSkim.cc -o ../bin/$@
datacardInputs:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) datacardInputs.cc -o ../bin/$@

datacardInputs_MET:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) datacardInputs_MET.cc -o ../bin/$@

datacardInputs_MET_BTags1_DeltaPhi12:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) datacardInputs_MET_BTags1_DeltaPhi12.cc -o ../bin/$@

FulltoyValidation_ALPHABET:
	$(CC) -g $(CFLAGS) $(LIBS) $(ROOFITLIBS) $(INCLUDES) FulltoyValidation_ALPHABET.cc -o ../bin/$@
FulltoyValidation:
	$(CC) $(CFLAGS) $(LIBS) $(ROOFITLIBS) $(INCLUDES) FulltoyValidation.cc -o ../bin/$@

plotHiggsPt_TChiHH:
	$(CC) $(CFLAGS) $(LIBS) $(ROOFITLIBS) $(INCLUDES) plotHiggsPt_TChiHH.cc -o ../bin/$@
plotObs_doubleHiggsTag_HiggsinoOnly:
	$(CC) $(CFLAGS) $(LIBS) $(ROOFITLIBS) $(INCLUDES) plotObs_doubleHiggsTag_HiggsinoOnly.cc -o ../bin/$@
clean : 
	rm $(EXECS) 
