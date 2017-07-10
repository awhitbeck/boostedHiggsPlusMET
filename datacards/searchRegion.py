import sys
import re
import collections
from singleBin import *

class searchRegion:

	def __init__( self ,name, binLabels, singleBinTags ) :

		self._regionName = name;
		self._binLabels = binLabels;
		self._singleBinTags = singleBinTags;

		self._nBins = len(singleBinTags);
		self._singleBins = [];
		for i in range(self._nBins):
			# print i, self._binLabels[i]
			self._singleBins.append( singleBin(self._regionName + str(i), self._singleBinTags[i], self._binLabels[i], i ) );

		# print "nbins = ", self._nBins;

	def fillRates(self, rateinputs, normalize=False):

		# if len(histograms) != len(self._binLabels): 
		# 	raise Exception("There is a mismatch in histogram input")

		for i in range(self._nBins):
			self._singleBins[i].setRates( rateinputs[i], normalize );
			if len(rateinputs[i]) != len(self._binLabels[i]):
				print  len(rateinputs[i]),len(self._binLabels[i])
				raise Exception("There is a mismatch in this bin of this signal region between rates and n contributions");
	def addSystematicsLine(self,systype,channel,hist):
		for i in range(self._nBins):
			 self._singleBins[i].addSystematic( hist.GetXaxis().GetBinLabel(i+1), systype, channel, hist.GetBinContent(i+1) );

	def addSystematicsLineAsymShape(self,systype,channel,histup,histdown):
		for i in range(self._nBins):
			 self._singleBins[i].addAsymSystematic( histup.GetXaxis().GetBinLabel(i+1), systype, channel, histup.GetBinContent(i+1),histdown.GetBinContent(i+1) );

        def addCorrelSystematicLine(self,systype,channel,hist1,hist2):
                for i in range(self._nBins):
                                self._singleBins[i].addCorrelSystematic( hist1.GetXaxis().GetBinLabel(i+1), systype, channel, hist1.GetBinContent(i+1),hist2.GetBinContent(i+1) );		
        def addCorrelAsymSystematicLine(self,systype,channel,hist1up,hist1dn,hist2up,hist2dn):
                for i in range(self._nBins):
				self._singleBins[i].addCorrelSystematicAsym( hist1up.GetXaxis().GetBinLabel(i+1), systype, channel, hist1up.GetBinContent(i+1),hist1dn.GetBinContent(i+1),hist2up.GetBinContent(i+1),hist2dn.GetBinContent(i+1) );
        def addGammaSystematic(self,channel,valCS,val1):
                for i in range(self._nBins):
					#for j in range(len(channel)):
					sysname=val1.GetXaxis().GetBinLabel(i+1)
                                        self._singleBins[i].addGammaSystematic( valCS.GetXaxis().GetBinLabel(i+1),'gmN', channel, valCS.GetBinContent(i+1),val1.GetBinContent(i+1));
        def addCorrelGammaSystematic(self,channel,valCS,val1,val2):
                for i in range(self._nBins):
					#for j in range(len(channel)):
					sysname=val1.GetXaxis().GetBinLabel(i+1)+"_StatUnc"
                                        self._singleBins[i].addGammaCorrelSystematic( val1.GetXaxis().GetBinLabel(i+1),'gmN', channel, valCS.GetBinContent(i+1),val1.GetBinContent(i+1),val2.GetBinContent(i+1) );
				
	def addABCDFormula(self,sysname,systype,channel,initval,minval,maxval,index=None,varnames=""):
		for i in range(self._nBins):
			#print varnames
			if index == None:self._singleBins[i].addRateParamFormula(sysname,systype,channel,varnames)
                        if index==self._singleBins[i]._index:
                                self._singleBins[i].addRateParamFormula(sysname,systype,channel,varnames)
	def addABCDSystematic(self,sysname,systype,channel,initval,minval,maxval,index=None):
		for i in range(self._nBins):				
			if index == None:self._singleBins[i].addRateParam(sysname,systype,channel,initval,minval,maxval)
			if index==self._singleBins[i]._index: 
				self._singleBins[i].addRateParam(sysname,systype,channel,initval,minval,maxval)
	def addGausSystematic(self,sysname,systype,mean, sigma,index=None):
		 for i in range(self._nBins):
		 	if index == None:self._singleBins[i].addGausParam(sysname,systype,mean,sigma)
			if index==self._singleBins[i]._index:self._singleBins[i].addGausParam(sysname,systype,mean,sigma)
	def addSingleSystematic(self,sysname,systype,channel,val,identifier='',index=None):
		
		#print "Looking for ",identifier;

		for i in range(self._nBins): 
			#if identifier in self._singleBins[i]._tag:
			if re.search(identifier, self._singleBins[i]._tag) or identifier == '':
				#print "Found! ",self._singleBins[i]._tag;
				if index == None or index == self._singleBins[i]._index:
					#print identifier, " in ", self._singleBins[i]._tag;				
					if isinstance(val,collections.Iterable): 
						self._singleBins[i].addSystematic( sysname, systype, channel, val[i] );
					else: 
						self._singleBins[i].addSystematic( sysname, systype, channel, val );

	def addAsymSystematic(self,sysname,systype,channel,valup,valdown,identifier='',index=None):
			#print "Looking for ",identifier;
			for i in range(self._nBins):
				#if identifier in self._singleBins[i]._tag:
				if re.search(identifier, self._singleBins[i]._tag) or identifier == '':
					#print "Found! ",self._singleBins[i]._tag;
					if index == None or index == self._singleBins[i]._index:
						if isinstance(valup,collections.Iterable) and isinstance(valdown,collections.Iterable):
							self._singleBins[i].addAsymSystematic( sysname, systype, channel, valup[i],valdown[i] );
						else: 
							self._singleBins[i].addAsymSystematic( sysname, systype, channel, valup,valdown );

	def addCorrelSystematic(self,sysname,systype,channel,val1,val2,identifier='',index=None):	
			for i in range(self._nBins):
					#if identifier in self._singleBins[i]._tag:
					if re.search(identifier, self._singleBins[i]._tag) or identifier == '':
							#print "Found! ",self._singleBins[i]._tag;
							if index == None or index == self._singleBins[i]._index:
											self._singleBins[i].addCorrelSystematic( sysname, systype, channel, val1,val2 );
	def addCorrelSystematicAsym(self,sysname,systype,channel,val1up, val1down, val2up, val2down, identifier='',index=None):
			for i in range(self._nBins):
                                        #if identifier in self._singleBins[i]._tag:
                                        if re.search(identifier, self._singleBins[i]._tag) or identifier == '':
                                                        #print "Found! ",self._singleBins[i]._tag;
                                                        if index == None or index == self._singleBins[i]._index:
                                                		if isinstance(val1up,collections.Iterable) and isinstance(val1down,collections.Iterable):
                                                                         self._singleBins[i].addCorrelSystematicAsym( sysname, systype, channel, val1up[i],val1down[i],val2up[i], val2down[i] );
								else:
                                                                         self._singleBins[i].addCorrelSystematicAsym( sysname, systype, channel, val1up,val1down,val2up, val2down );
	def addSystematicFromList(self,sysname,systype,channel,inputlist):

		if len(inputlist) != self._nBins: print "There is a problem mistaching in searchRegion:addSystematicFromList!! %s %d" %(sysname, len(inputlist));
		for i in range(self._nBins): 
			if(inputlist[i]>-99):self._singleBins[i].addSystematic( sysname, systype, channel, 1+inputlist[i] );
			else: self._singleBins[i].addSystematic( sysname, systype, channel, 1 );
	def addAsymSystematicFromList(self,sysname,systype,channel,inputListUp,inputListDn):

		if len(inputListUp) != self._nBins: print "There is a problem mistaching in searchRegion:addSystematicFromList!! %s %d %d" %(sysname, len(inputListUp), len(inputListDn));
		for i in range(self._nBins): 
			
			#print inputListUp[i]
			#if(inputlistUp[i]>-99 and inputlistDn[i]>-99):
			self._singleBins[i].addAsymSystematic( sysname, systype, channel, 1+inputListUp[i], 1-inputListDn[i] );

		
	def setObservedManually(self,listObs):
		for i in range(self._nBins):
			self._singleBins[i]._observed = listObs[i];

	def writeRates(self):
		for i in range(self._nBins):
			self._singleBins[i].writeRates();

	def writeCards(self, odir):
		for i in range(self._nBins):
		# for i in range(4,18):
			# if i!=3 and i!=2: self._singleBins[i].writeCard( odir ); 
			self._singleBins[i].writeCard( odir ); 

	def GetNbins(self):
		return self._nBins;
