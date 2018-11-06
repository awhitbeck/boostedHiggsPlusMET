from PyPDF2 import PdfFileMerger
import os

#dir_path = os.path.dirname(os.path.realpath(__file__))
dir_path = "/uscms_data/d3/kxlpp1/SUSY/SUSY_OCT2018/CMSSW_10_1_7/src/boostedHiggsPlusMET/plots_baseline_noVBF/plotObs_baseline_plots"

def list_files(directory, extension):
    return (f for f in os.listdir(directory) if f.endswith('.' + extension))

pdfs = list_files(dir_path, "pdf")
merger = PdfFileMerger()

for pdf in pdfs:
    merger.append(open(pdf, 'rb'))
with open('baseline_noVBF_noSBSR.pdf', 'wb') as fout:
    merger.write(fout)


#path = "/Users/Kamal/Desktop/PANDA/signal_VBF/"
