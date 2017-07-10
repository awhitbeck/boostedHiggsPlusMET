from ROOT import *
from math import sqrt
from math import pow
GammaSFValidation=[0.8,0.97, 0.55,0.64]
GammaSFErrValidation=[0.18,0.077, 0.054, 0.024]

LeptonSFValidation=[0.6,0.57, 0.53,0.44]
LeptonSFErrValidation=[0.14,0.047, 0.081, 0.028]

LowDphiSFValidation=[0.77,0.83, 0.81,0.66]
LowDphiSFErrValidation=[0.11,0.039, 0.082, 0.023]

RPF_gammaSR=GammaSFValidation[0]/GammaSFValidation[2]
RPF_gammaSB=GammaSFValidation[1]/GammaSFValidation[3]
RPF_gammaSRErr=(pow(GammaSFErrValidation[0]/GammaSFValidation[0],1)+pow(GammaSFErrValidation[2]/GammaSFValidation[2],1))*RPF_gammaSR
RPF_gammaSBErr=(pow(GammaSFErrValidation[1]/GammaSFValidation[1],1)+pow(GammaSFErrValidation[3]/GammaSFValidation[3],1))*RPF_gammaSB
RPF_leptonSR=LeptonSFValidation[0]/LeptonSFValidation[2]
RPF_leptonSB=LeptonSFValidation[1]/LeptonSFValidation[3]
RPF_leptonSRErr=(pow(LeptonSFErrValidation[0]/LeptonSFValidation[0],1)+pow(LeptonSFErrValidation[2]/LeptonSFValidation[2],1))*RPF_leptonSR
RPF_leptonSBErr=(pow(LeptonSFErrValidation[1]/LeptonSFValidation[1],1)+pow(LeptonSFErrValidation[3]/LeptonSFValidation[3],1))*RPF_leptonSB

RPF_lowDphiSR=LowDphiSFValidation[0]/LowDphiSFValidation[2]
RPF_lowDphiSB=LowDphiSFValidation[1]/LowDphiSFValidation[3]
RPF_lowDphiSRErr=(pow(LowDphiSFErrValidation[0]/LowDphiSFValidation[0],1)+pow(LowDphiSFErrValidation[2]/LowDphiSFValidation[2],1))*RPF_lowDphiSR
RPF_lowDphiSBErr=(pow(LowDphiSFErrValidation[1]/LowDphiSFValidation[1],1)+pow(LowDphiSFErrValidation[3]/LowDphiSFValidation[3],1))*RPF_lowDphiSB

print "Low Delta Phi VR SR R_{p/f} %.2f +/- %.2f SB R_{p/f} %.2f +/- %.2f" %(RPF_lowDphiSR, RPF_lowDphiSRErr,RPF_lowDphiSB,RPF_lowDphiSBErr)
print "Lepton VR SR R_{p/f} %.2f +/- %.2f SB R_{p/f} %.2f +/- %.2f" %(RPF_leptonSR, RPF_leptonSRErr,RPF_leptonSB,RPF_leptonSBErr)
print "Gamma VR SR R_{p/f} %.2f +/- %.2f SB R_{p/f} %.2f +/- %.2f" %(RPF_gammaSR, RPF_gammaSRErr,RPF_gammaSB,RPF_gammaSBErr)


kappaQCD=RPF_lowDphiSR/RPF_lowDphiSB;
kappaSL=RPF_leptonSR/RPF_leptonSB;
kappaGamma=RPF_gammaSR/RPF_gammaSB;
kappaQCDErr=sqrt(pow(RPF_lowDphiSRErr/RPF_lowDphiSR,2)+pow(RPF_lowDphiSBErr/RPF_lowDphiSB,2))*kappaQCD
kappaSLErr=sqrt(pow(RPF_leptonSRErr/RPF_leptonSR,2)+pow(RPF_leptonSBErr/RPF_leptonSB,2))*kappaSL
kappaGammaErr=sqrt(pow(RPF_gammaSRErr/RPF_gammaSR,2)+pow(RPF_gammaSBErr/RPF_gammaSB,2))*kappaGamma
print "Kappa QCD %.2f +/- %.2f " %( kappaQCD, kappaQCDErr)
print "Kappa W+Top %.2f +/- %.2f " %( kappaSL, kappaSLErr)
print "Kappa Z %.2f +/- %.2f " %( kappaGamma, kappaGammaErr)

