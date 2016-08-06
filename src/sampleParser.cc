#ifndef SAMPLEPARSER
#define SAMPLEPARSER

#include "TString.h"
#include "TChain.h"
#include "TFile.h"
#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

typedef TString fileName;
typedef TString sampleKey;

typedef map<fileName,sampleKey> fileMap;
// this is used to map the input file to a set of
// sample names.  This mapping should be specified
// in a separate text files where the file and 
// sample are comma separated and each pair is on 
// a separate line.

typedef map<sampleKey , vector<fileName>* > sampleMap;
// this is used to map the sample to a list of input 
// file names.  It is effectively the inverse of fileMap
// which really a many-to-one mapping.  

// parse text files to build many-to-one mapping
// between files and sample key 
fileMap parseInputs( TString inputFileList ){

  string line;
  ifstream inputFile(inputFileList);
  fileMap m;

  if( inputFile.is_open() ){
    while( getline( inputFile , line ) ){

      // ---------------------
      // tokenize each line with
      // ' ' as a delimator
      // ---------------------
      istringstream iss(line);
      vector<string> tokens;
      copy(istream_iterator<string>(iss),
	   istream_iterator<string>(),
	   back_inserter(tokens));
      
      if( tokens.size() != 3 ){
	std::cout << "sampleparser::parseInputs() -- problem with mapping syntax in " << inputFileList << std::endl;
	return m ;
      }else{
	m[tokens[0]]=tokens[1];
      }
      
    }// end loop over lines in file
  }// end check for is_open()
  
  return m;

}

// parse x-sections from input file
typedef map<sampleKey , double> xsecMap;
xsecMap parseXsec( TString inputFileList ){

  string line;
  ifstream inputFile(inputFileList);
  xsecMap m;

  if( inputFile.is_open() ){
    while( getline( inputFile , line ) ){

      // ---------------------
      // tokenize each line with
      // ' ' as a delimator
      // ---------------------
      istringstream iss(line);
      vector<string> tokens;
      copy(istream_iterator<string>(iss),
	   istream_iterator<string>(),
	   back_inserter(tokens));
      
      if( tokens.size() != 3 ){
	cout << "sampleparser::parseInputs() -- problem with mapping syntax in " << inputFileList << endl;
	return m ;
      }else{
	m[tokens[1]]=stod(tokens[2]);
      }
      
    }// end loop over lines in file
  }// end check for is_open()
  
  return m;

}

// invert fileMap.  A one-to-many map is returned
// where the key is the sample and the value is a
// vector of file names. 
sampleMap invertFileMap( fileMap fmap ){
  sampleMap smap;
  for( fileMap::iterator iFile=fmap.begin() ; iFile!=fmap.end() ; ++iFile ){
    if( smap.find(iFile->second) == smap.end() )
      smap[iFile->second] = new vector<fileName>() ;
    smap[iFile->second]->push_back( iFile->first );
  }

  return smap;
}

sampleMap reduceMap(fileMap fmap_, TString substr){
  sampleMap smap;
  for( fileMap::iterator iFile=fmap_.begin() ; iFile!=fmap_.end() ; ++iFile ){
    if( iFile->first.SubString(substr.Data()) == "" ) continue;
    if( smap.find(iFile->second) == smap.end() )
      smap[iFile->second] = new vector<fileName>() ;
    smap[iFile->second]->push_back( iFile->first );
  }
  return smap;
}

// build a chain from all files in map_
TChain* buildChain(fileMap map_, TString substr, TString treeName){

  TChain* t = new TChain(treeName);
  char temp[200];

  for( fileMap::iterator it = map_.begin() ; it != map_.end() ; ++it ){
    if( it->first.SubString(substr.Data()) == "" ) continue;
    sprintf( temp , "root://cmsxrootd.fnal.gov//%s", it->first.Data() );
    //cout << temp << endl;
    t->Add( temp );
  }// end loop over files

  return t ;

}

// build a chain from all files in inputFileList that contain substr
TChain* buildChain(TString inputFileList, TString substr, TString treeName){

  fileMap m = parseInputs(inputFileList);
  return buildChain(m,substr,treeName);

}

// build a chain from a sampleMap
TChain* buildChain(vector<fileName> *fileVec, TString treeName){

  TChain* t = new TChain(treeName);
  char temp[500];

  for( vector<fileName>::iterator it = fileVec->begin() ; it != fileVec->end() ; ++it ){
    sprintf( temp , "root://cmsxrootd.fnal.gov//%s", it->Data() );
    cout << temp << endl;
    t->Add( temp );
  }// end loop over files

  cout << "check" << endl;

  return t ;

}

#endif
