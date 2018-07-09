//Alex Lundin
//AML140830@utdallas.edu
//SE 3377.501 - CC++ in  UNIX

#include "program2.h"
using namespace std;

char* fileRead (std::string);
char* caseConvert (char*,std::string, std::string);
void fileWrite (std::string, char*);

void DoWork(){

	std:: cout << "In do work";

	string inputFile = myMap.at(INFILE);
	string outputFile = myMap.at(OUTFILE);
	string upperFlag = myMap.at(UFLAG);
	string lowerFlag = myMap.at(LFLAG);
	char* charPointer = fileRead(inputFile);
	char* convertedPointer = caseConvert (charPointer, upperFlag, lowerFlag);
	fileWrite(outputFile, convertedPointer);
	

}


char* fileRead (std::string inputFileName){
	
	char * inputFileNameCString = new char [inputFileName.length()+1];
	std::strcpy (inputFileNameCString, inputFileName.c_str());	
	
	
	FILE* pFile = fopen(inputFileNameCString, "r");
	if (pFile!=NULL)
	{
		// Determine file size
		fseek(pFile, 0, SEEK_END);
		size_t size = ftell(pFile);

		char* charPointer = new char[size];

		rewind(pFile);
		fread(charPointer, sizeof(char), size, pFile);
		fclose (pFile);
		return charPointer;
		
	}else
	{ 
		std::cerr << "\nerror: Unable to open input file for reading." << std::endl; 
			exit(0);
	}	
	
	
}

char* caseConvert (char* cPointer, std::string uflag, std::string lflag){
	

	int shifter = 32;

	
	// loop through pointer array
	for (int a = 0; a < sizeof(cPointer); a = a + 1){
		cout << (cPointer[a]) << endl;
		int asciiCode = (int)(cPointer[a]);
		if	((asciiCode >= 65) && (asciiCode <= 90)  && (lflag == "true")){
			asciiCode += shifter;
		}
		if	( (asciiCode >= 97) && (asciiCode <= 122)  && (uflag == "true")){
			asciiCode -= shifter;
		}
		char character = (char)asciiCode;
		cPointer[a] = character;
	}
	
	cout << std::string(cPointer) << endl;
	return cPointer;
}

void fileWrite (std::string outputFileName, char* cPointer){
	
	char * outputFileNameCString = new char [outputFileName.length()+1];
	std::strcpy (outputFileNameCString, outputFileName.c_str());

	
    ofstream stream;


    stream.open(outputFileNameCString);
    if( !stream ){
		std::cerr << "\nerror: Unable to open output file for writing." << std::endl; 
			exit(0);		
	}else{
    stream << cPointer << endl;
	}
	
	return;
}