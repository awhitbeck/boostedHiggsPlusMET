import sys
import collections
class singleBin:

	def __init__( self , name, tag, binLabels, index ):

		self._name = name;
		self._tag  = tag;
		self._index  = index;
		self._binLabels = binLabels;
		self._rates = [];
		self._allLines = [];

		# print "bin tag = ", tag, index

	def setRates( self, rates, normalize = False ):

		self._observed = float(sum(rates));
		
		# print self._index, self._observed, rates

		self._rates = [];
		if normalize: 
			if self._observed > 0: 
				self._rates = [x / self._observed for x in rates];
			else : self._rates = [1.]*len(rates);
		else: self._rates = rates;

	def writeRates( self ):

		#############################
		# yield part of the datacard
		line = "#the tag = %s \n" % (self._tag);
		self._allLines.append(line);
		
		line = "imax 1 #number of channels \n";
		self._allLines.append(line);
		line = "jmax %i #number of backgrounds \n" % (len(self._binLabels)-1);
		self._allLines.append(line);
		self._allLines.append("kmax * nuissance \n");
		self._allLines.append("shapes * * FAKE \n");
		self._allLines.append("------------ \n");

		line = "bin Bin"+self._name+"\n";
		self._allLines.append(line);
		
		line = "observation "+str(self._observed)+"\n";
		self._allLines.append(line);

		line = "bin ";
		for i in range(len(self._binLabels)): line += "Bin"+self._name + " ";
		line += "\n";
		self._allLines.append(line);

		line = "process ";
		for i in range(len(self._binLabels)): line += self._binLabels[i] + " ";
		line += "\n";
		self._allLines.append(line);

		line = "process ";
		for i in range(len(self._binLabels)): line += str(i) + " ";
		line += "\n";
		self._allLines.append(line);

		line = "rate ";
		zeroProxy = 0.000001;
		for rate in self._rates: 
			if rate < 0.000001: line += str(zeroProxy) + " ";
			else: line += "%.4f " %round(rate,4);
		line += "\n";
		self._allLines.append(line);

		self._allLines.append("------------ \n");

	def addSystematic(self,sysname,systype,bins,val):
		#print sysname
		# print "length rates = ",len(self._rates)
		#print bins,val
		line = "";
		line += sysname + " " + systype + " ";
		#bin=0;
		for i in range(len(self._binLabels)):
			#print len(self._binLabels)
			if self._binLabels[i] in bins:
				#print self._binLabels[i]
				if self._rates[i] < 0.000001 and systype == 'lnU': line += str(val*1) + " ";
				else: 
					if(val>-99.):
						line += str(val) + " ";
					else: 
						line += " - ";
			else: line += "- ";
		line += "\n";
		self._allLines.append(line);

	def addCorrelSystematic(self,sysname,systype,bins,val1, val2):
                #print sysname
                # print "length rates = ",len(self._rates)
                line = "";
                line += sysname + " " + systype + " ";
                bin=0;
                for i in range(len(self._binLabels)):
                        #print len(self._binLabels)
                        if self._binLabels[i] in bins:
                                #print self._binLabels[i]
                                if self._rates[i] < 0.000001 and systype == 'lnU': line += str(val*1) + " ";
                                else:
					if val1>-99. and val2>-99.:
                                        	if(bin==0):
                                                	line += str(val1) + " ";
						if(bin==1):
							line += str(val2) + " ";
                                        else:
                                                line += " - ";
					bin+=1
                        else: line += "- ";
                line += "\n";
                self._allLines.append(line);

	def addCorrelSystematicAsym(self,sysname,systype,bins,val1up, val1dn, val2up,val2dn):
                #print sysname
                # print "length rates = ",len(self._rates)
                line = "";
                line += sysname + " " + systype + " ";
                bin=0;
                for i in range(len(self._binLabels)):
                        #print len(self._binLabels)
                        if self._binLabels[i] in bins:
                                #print self._binLabels[i]
				if val1up>-99. and val2up>-99.:
                                	if(bin==0):line += str(val1dn) + "/" + str(val1up);
					if(bin==1):line += str(val2dn) + "/" +str(val2up);
                                else:
                                     line += " - ";
				bin+=1
                        else: line += " - ";
                line += "\n";
                self._allLines.append(line);
        def addGammaCorrelSystematic(self,sysname,systype,bins,valCS,val1,val2):
                #print sysname
                # print "length rates = ",len(self._rates)
                #print bins,val
                line = "";
                line += sysname + " " + systype + " "+ "%d " %int(valCS);
                bin=0;
                for i in range(len(self._binLabels)):
                        #print len(self._binLabels)
                        if self._binLabels[i] in bins:
                                #print self._binLabels[i]
                                if(val1>-99. and val2>-99):
                                        if(bin==0 ):line += " %0.4f " %round(val1,4);
                                        if(bin==1 ):line += " %0.4f " %round(val2,4);
                                else:
                                        line += " - ";
                                bin+=1
                        else: line += "- ";
                line += "\n";
                self._allLines.append(line);
        def addGammaSystematic(self,sysname,systype,bins,valCS,val):
                #print sysname
                # print "length rates = ",len(self._rates)
                #print bins,val
                line = "";
                line += sysname + " " + systype + " "+ "%d " %int(valCS);
                bin=0;
                for i in range(len(self._binLabels)):
                        #print len(self._binLabels)
                        if self._binLabels[i] in bins:
                                #print self._binLabels[i]
                                if(val>-99.):
                                        if(bin==0 or bin==1):
                                                if valCS>0:line += " %g " %val ;
                                                else: line+= " %0.4f " %(round(val,4));
                                else:
                                        line += " - ";
                                bin+=1
                        else: line += "- ";
                line += "\n";
                self._allLines.append(line);	
        #def addRateParam(self,sysname,systype,bins,valCS,val):
        def addGausParam(self,sysname,systype,mean,sigma):
                line = "";
		#print "Bin"+self._name	
                line += sysname + " " + systype +" "+ "%g  %g" %(mean, sigma);
                line += "\n";
		#print line 
                self._allLines.append(line);	
        def addRateParam(self,sysname,systype,bkgprocess,initval,minval,maxval):
                line = "";
		#print "Bin"+self._name	
                line += sysname + " " + systype + " "+"Bin"+self._name+" "+bkgprocess+" "+ "%g [%2.2f,%2.2f]" %(initval,minval,maxval);
                line += "\n";
		#print line 
                self._allLines.append(line);	
        def addRateParamFormula(self,sysname,systype,bkgprocess,varnames):
                line = "";
		#print "Bin"+self._name
		formula="((@0*@1/@2)*@3)"	
                line += sysname + " " + systype + " "+"Bin"+self._name+" "+bkgprocess+" "+ "%s %s " %(formula,varnames);
                line += "\n";
		print line 
                self._allLines.append(line);	
		
	def addAsymSystematic(self,sysname,systype,bins,valup, valdown ):
		line = "";
		line += sysname + " " + systype + " ";
		bin=0;
		for i in range(len(self._binLabels)): 
			if self._binLabels[i] in bins:
				#print self._binLabels[i]
				if self._rates[i] < 0.000001 and systype == 'lnU': line += str(val*1) + " ";
				else: 
					if(valdown>-99. and valup>-99.):
						if not valdown>0.0:valdown=0.01
						if not valup>0.0:valup=0.01
						line += str(valdown) + "/" +str(valup)+" ";
					else: line += " - ";
			else: line += " - ";
		line += "\n";
		self._allLines.append(line);

	def writeCard( self, odir ):
		
		ofile = open(odir+'/card_'+self._name+'.txt','w');
		for line in self._allLines: ofile.write(line);
		ofile.close();
