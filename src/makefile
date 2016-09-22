CC=g++
CFLAGS=
LIBS=`root-config --cflags --glibs` -L $(ROOTSYS)/lib
INCLUDES=-I$(CMSSW_BASE)/src/AnalysisTools/src/ -I$(CMSSW_BASE)/src/
EXECS=plotObs_singleHiggsTag plotObs_doubleHiggsTag plotObs_antitag plotObs_baseline plotObs_singleMuCR_antitag plotObs_singleMuCR_singleHiggsTag baselineSkim
$(EXECS):RA2bTree.cc definitions.cc skimSamples.cc plotterUtils.cc
baselineSkim:sampleParser.cc selectBaseline.cc 

all:$(EXECS)
plotObs_singleHiggsTag:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_singleHiggsTag.cc -o $@
plotObs_doubleHiggsTag:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_doubleHiggsTag.cc -o $@
plotObs_antitag:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_antitag.cc -o $@
plotObs_baseline:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_baseline.cc -o $@
plotObs_singleMuCR_antitag:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_singleMuCR_antitag.cc -o $@
plotObs_singleMuCR_singleHiggsTag:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_singleMuCR_singleHiggsTag.cc -o $@
baselineSkim:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) baselineSkim.cc -o $@
clean : 
	rm $(EXECS) 