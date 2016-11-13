CC=g++
CFLAGS=
LIBS=`root-config --cflags --glibs` -L $(ROOTSYS)/lib -I$(ROOTSYS)/include
ROOFITLIBS=-lRooFit -lHtml -lMinuit -lRooFitCore
INCLUDES=-I$(CMSSW_BASE)/src/AnalysisTools/src/ -I$(CMSSW_BASE)/src/
EXECS=plotObs_singleHiggsTag plotObs_doubleHiggsTag plotObs_antitag plotObs_baseline plotObs_singleMuCR_antitag plotObs_singleMuCR_singleHiggsTag plotObs_singleMuCR_baseline baselineSkim singleMuCRSkim datacardInputs_MET datacardInputs_MET_BTag1_DeltaPhi12 cutFlow_HIggsinoOnly ALPHABET plotObs_fastFullComp 
$(EXECS):RA2bTree.cc definitions.cc skimSamples.cc plotterUtils.cc
baselineSkim:sampleParser.cc selectBaseline.cc baselineSkim.cc
datacardInputs_MET:datacardInputs_MET.cc
datacardInputs_MET_BTags1_DeltaPhi12:datacardInputs_MET_BTags1_DeltaPhi12.cc
singleMuCRSkim:singleMuCRSkim.cc sampleParser.cc selectBaseline.cc 
plotObs_singleMuCR_singleHiggsTag:plotObs_singleMuCR_singleHiggsTag.cc
plotObs_singleMuCR_baseline:plotObs_singleMuCR_baseline.cc
plotObs_singleMuCR_antitag:plotObs_singleMuCR_antitag.cc
plotObs_baseline:plotObs_baseline.cc
plotObs_antitag:plotObs_antitag.cc
plotObs_doubleHiggsTag:plotObs_doubleHiggsTag.cc
plotObs_singleHiggsTag:plotObs_singleHiggsTag.cc
FulltoyValidation:FulltoyValidation.cc
FulltoyValidation_ALPHABET:FulltoyValidation_ALPHABET.cc
plotHiggsPt_TChiHH:plotHiggsPt_TChiHH.cc
plotObs_doubleHiggsTag_HiggsinoOnly:plotObs_doubleHiggsTag_HiggsinoOnly.cc RA2bTree.cc skimSamplesHiggsinoOnly.cc
cutFlow_HiggsinoOnly:cutFlow_HiggsinoOnly.cc RA2bTree.cc skimSamplesHiggsinoOnly.cc
ALPHABET:ALPHABET.cc
plotObs_fastFullComp:plotObs_fastFullComp.cc fastFullSamples.cc

all:$(EXECS) FulltoyValidation plotHiggsPt_TChiHH

plotObs_fastFullComp:
	$(CC) -g $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_fastFullComp.cc -o $@
ALPHABET:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) ALPHABET.cc -o $@

cutFlow_HiggsinoOnly:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) cutFlow_HiggsinoOnly.cc -o $@

plotObs_singleHiggsTag:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_singleHiggsTag.cc -o $@
plotObs_doubleHiggsTag:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_doubleHiggsTag.cc -o $@
plotObs_antitag:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_antitag.cc -o $@
plotObs_baseline:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_baseline.cc -o $@
plotObs_singleMuCR_baseline:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_singleMuCR_baseline.cc -o $@	
plotObs_singleMuCR_antitag:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_singleMuCR_antitag.cc -o $@
plotObs_singleMuCR_singleHiggsTag:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_singleMuCR_singleHiggsTag.cc -o $@

baselineSkim:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) baselineSkim.cc -o $@
singleMuCRSkim:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) singleMuCRSkim.cc -o $@

datacardInputs_MET:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) datacardInputs_MET.cc -o $@

datacardInputs_MET_BTags1_DeltaPhi12:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) datacardInputs_MET_BTags1_DeltaPhi12.cc -o $@

FulltoyValidation_ALPHABET:
	$(CC) -g $(CFLAGS) $(LIBS) $(ROOFITLIBS) $(INCLUDES) FulltoyValidation_ALPHABET.cc -o $@
FulltoyValidation:
	$(CC) $(CFLAGS) $(LIBS) $(ROOFITLIBS) $(INCLUDES) FulltoyValidation.cc -o $@

plotHiggsPt_TChiHH:
	$(CC) $(CFLAGS) $(LIBS) $(ROOFITLIBS) $(INCLUDES) plotHiggsPt_TChiHH.cc -o $@
plotObs_doubleHiggsTag_HiggsinoOnly:
	$(CC) $(CFLAGS) $(LIBS) $(ROOFITLIBS) $(INCLUDES) plotObs_doubleHiggsTag_HiggsinoOnly.cc -o $@
clean : 
	rm $(EXECS) 