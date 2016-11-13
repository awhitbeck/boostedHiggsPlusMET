from os import walk
from optparse import OptionParser

parser = OptionParser()
parser.add_option("-d", "--dir", dest="dir",
                  help="target directory for markdown")

(options, args) = parser.parse_args()

fileList = []
for (dirpath, dirnames, filenames) in walk(options.dir):
    fileList.extend(filenames)
    break

outputFile = open(options.dir+"/README.md","w")

outputFile.write("|image|description|\n")
outputFile.write("| --- | --- |\n")
for f in fileList:
    if f[-4:]!=".png": continue
    outputFile.write("| [{0}]({0})![{0}]({0}) |  |".format(f))

outputFile.close()    
