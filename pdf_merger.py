from PyPDF2 import PdfFileReader, PdfFileWriter, PdfFileMerger
import PyPDF2
import os

## Good tutorial on this at: https://automatetheboringstuff.com/chapter13/

#path = "/Users/Kamal/Desktop/PANDA/signal_VBF/"
path = "/uscms_data/d3/kxlpp1/SUSY/SUSY_OCT2018/CMSSW_10_1_7/src/boostedHiggsPlusMET/plots/plotObs_baseline_plots/"
os.chdir(path)

pdf_files = []
for filename in os.listdir('.'):
    if filename.endswith('.pdf'):
        pdf_files.append(filename)
pdf_files.sort(key=str.lower)

merger = PdfFileMerger()
for files in pdf_files:
    #merger.append(path+files)
    merger.append(PdfFileReader(files), 'rb')
if os.path.exists(path+'merged_baseline.pdf'):
    print 'same file name already exist so did not create a new one'
    merger.write(path+'merged_baseline.pdf')
#merger.write('merged_all_v1.pdf')
merger.close()


