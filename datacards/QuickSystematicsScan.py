import sys
import os
mGluinos=[750, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2100]
os.makedirs("%s" %sys.argv[1])	
bkgProcess=sys.argv[2]
bkgUnc=sys.argv[3]
for g in mGluinos:
	os.system("python buildCards.py --mGo %d " %g)
	os.makedirs("%s/SignalT5HH%d" %(sys.argv[1],g))	
	for i in range (0,3):
		f=open("SignalT5HH%d/card_signal%d.txt" %(g,i), 'r');
		f.seek(0)
		fout=open("%s/SignalT5HH%d/card_signal%d.txt" %(sys.argv[1],g,i), 'w')
		linecount=0;
		for line in f:
			if "------------" in line and linecount>6: 
				fout.write("%s" %line)
				if "QCD" in bkgProcess: fout.write("QCDUnc_%d lnN - %s - - - \n" %(i,bkgUnc))
				if "Z" in bkgProcess: fout.write("ZUnc_%d lnN - - %s - - \n" %(i,bkgUnc))
				if "W" in bkgProcess: fout.write("WUnc_%d lnN - - - %s - \n" %(i,bkgUnc))
				if "Top" in bkgProcess: fout.write("TopUnc_%d lnN - - - - %s  \n" %(i,bkgUnc))
				#print line
			else:
				linecount=linecount+1
				fout.write("%s" %line)
		f=open("SignalT5HH%d/card_signal1H%d.txt" %(g,i), 'r');
		f.seek(0)
		fout=open("%s/SignalT5HH%d/card_signal1H%d.txt" %(sys.argv[1],g,i), 'w')
		for line in f:
			if "------------" in line: 
				fout.write("%s" %line)
				#if "QCD" in bkgProcess: fout.write("QCDUnc lnN - %s - - - \n" %bkgUnc)
				#if "Z" in bkgProcess: fout.write("ZUnc lnN - - %s - - \n" %bkgUnc)
				#if "W" in bkgProcess: fout.write("WUnc lnN - - - %s - \n" %bkgUnc)
				#if "Top" in bkgProcess: fout.write("TopUnc lnN - - - - %s  \n" %bkgUnc)
				#print line
				'''
				fout.write("QCDUnc lnN - %s - - - \n" %bkgUnc)
				fout.write("ZUnc lnN - - %s - - \n" %bkgUnc)
				fout.write("WUnc lnN - - - %s - \n" %bkgUnc)
				fout.write("TopUnc lnN - - - - %s  \n" %bkgUnc)
				'''
				fout.write("QCDUnc lnN - 1.5 - - - \n")
				fout.write("ZUnc lnN - - 1.15  - - \n")
				fout.write("WUnc lnN - - -1.15  - \n")
				fout.write("TopUnc lnN - - - - 1.15  \n")
			else:
				fout.write("%s" %line)

	os.system("cp SignalT5HH%d/card_antitagRegion*.txt %s/SignalT5HH%d/" %(g,sys.argv[1],g))
	os.system("cp SignalT5HH%d/card_sideband*.txt %s/SignalT5HH%d/" %(g,sys.argv[1],g))
	
