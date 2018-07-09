//Alex Lundin
//AML140830@utdallas.edu
//SE 3377.501 - CC++ in  UNIX

#include "program5.h"

using namespace rude;
using namespace std;

void readConfigFile ();
void fillMapWithConfigFile (bool Verbose, std::string LogFile, std::string Password, int NumVersions, std::string WatchDir);
void reReadConfigFile ();
void reFilMap (bool Verbose, std::string LogFile, int NumVersions);

// wrapper method for this file
// sends arguments to the parser
// from there the parser will call fill map
// fil map alerts the user of the status of each value before storing to the map


void parseConfigFile (){
	
	readConfigFile();

	return;
}



// this method reads the config file
// first, it finds the name of the config file from the map
// then it reads all data from the file
// next, it handles any invalid data
// during validation, readConfigFile alerts user to any invalid data
// then readConfigFile calls fillMap, only if data is valid

void readConfigFile (){
		std::string configFilePath = myMap.find(CONFIGFILE)->second;
		
		
		// Create config object
		//
		Config config;		
		
		// load config with the path from the map, which must be a c style string
		// 
		config.load(configFilePath.c_str());
		
		// read information
		
		// read section from config file
		config.setSection("Parameters");
		
		// read values from ID's
		bool Verbose = config.getBoolValue("Verbose");
		std::string LogFile = config.getStringValue("LogFile");
		std::string Password = config.getStringValue("Password");
		int NumVersions = config.getIntValue("NumVersions");
		std::string WatchDir = config.getStringValue("WatchDir");
		
	
		fillMapWithConfigFile (Verbose, LogFile, Password, NumVersions, WatchDir);
		

		return;		
}



// this method accepts the values parsed from the parser
// then this method determines what to place in the map 
// Verbose will be a boolean true or false
// LogFile will be string name of a log file
// Password will be string of a password
// NumVersions will be integer representation of number of versions to keep
// WatchDir will be string of directory to watch
void fillMapWithConfigFile (bool Verbose, std::string LogFile, std::string Password, int NumVersions, std::string WatchDir){
	
	std::string TrueString = "true";
	std::string FalseString = "false";
	
	// add the verbose flag to the map in the form of a boolean value
	// alert user of the status of the daemon flag before storing the boolean representation
		if ( Verbose )
	{
		myMap.insert(pair<int,string>(VERBOSE, TrueString ));		  
	}
		else{
		myMap.insert(pair<int,string>(VERBOSE, FalseString ));				
			
		}
		
	// add the log file path to the map, as a string
	myMap.insert(pair<int,string>(LOGFILE, LogFile));   


	// convert the int to String
	std::string NumVersionsString;
	std::stringstream out;
	out << NumVersions;
	NumVersionsString = out.str();
	
	// add the number of version to the map, as a string
	myMap.insert(pair<int,string>(NUMVERSIONS, NumVersionsString));   	
	
	
	// add the password to the map, as a string
	myMap.insert(pair<int,string>(PASSWORD, Password)); 
  
	// add the watch directory to the map, as a string
	myMap.insert(pair<int,string>(WATCHDIR, WatchDir));	
 
		
}



// this method re reads the config file
// there are only two values allowed to be reconfigured during run time

void reReadConfigFile (){
		std::string configFilePath = myMap.find(CONFIGFILE)->second;
		

		// Create config object
		//
		Config config;		
		
		// load config with the path from the map, which must be a c style string
		// 
		config.load(configFilePath.c_str());
		
		// read information
		
		// read section from config file
		config.setSection("Parameters");
		
		// read values from ID's
		bool Verbose = config.getBoolValue("Verbose");
		std::string LogFile = config.getStringValue("LogFile");
		int NumVersions = config.getIntValue("NumVersions");

		
		reFilMap (Verbose, LogFile, NumVersions);
		
		printf("\nReread config file complete.");
		if	(Verbose == true){
			printf("\nVerbose level true.");
			
		}else{
			printf("\nVerbose level false.");
		}
		
		
		return;		


	
}


void reFilMap (bool Verbose, std::string LogFile, int NumVersions){
	
	std::string TrueString = "true";
	std::string FalseString = "false";
	
	// attempt to find the pair	
	std::map<int,string>::iterator VerbosePair = myMap.find(VERBOSE); 

	// add the verbose flag to the map in the form of a boolean value
	if ( Verbose ){
		// make sure the pair is in the map, before attempting to insert the new value
		if (VerbosePair != myMap.end()){
			VerbosePair->second = TrueString;	
		}
	}
	else{
		// make sure the pair is in the map, before attempting to insert the new value
		if (VerbosePair != myMap.end()){
			VerbosePair->second = FalseString;	
		}			
			
	}
	
	// attempt to find the pair	
	std::map<int,string>::iterator LogPair = myMap.find(LOGFILE);
	
	// make sure the pair is in the map, before attempting to insert the new value
	// add the log file path to the map, as a string
	if (LogPair != myMap.end()){
		LogPair->second = LogFile;	
	}			
 


	// convert the int to String
	std::string NumVersionsString;
	std::stringstream out;
	out << NumVersions;
	NumVersionsString = out.str();
	
	// attempt to find the pair
	std::map<int,string>::iterator NumPair = myMap.find(NUMVERSIONS);
	
	// make sure the pair is in the map, before attempting to insert the new value
	// add the number of version to the map, as a string
	if (NumPair != myMap.end()){
		NumPair->second = NumVersionsString;	
	}	
	
	
	

}