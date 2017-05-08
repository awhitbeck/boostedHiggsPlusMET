import os

inputFile = open("skimInputs.txt","r")

for line in inputFile : 
    
    #strip \n from line
    line = line[:-1]

    #split up workds
    words = line.split()
    fileName = words[0]
    xsec = words[1]
    fileTag = words[2]
    histoTag = words[3]

    #run
    print fileTag
    os.system("./go.exe {0} {1} {2}".format(fileName,fileTag,histoTag))
