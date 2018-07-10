//Alex Lundin
//AML140830@utdallas.edu
//Project 1
//CS-4390.0U2-Networks in  UNIX

#include "project1.h"

using namespace std;

void readConfigFile ();
void fillMapWithConfigFile (bool Verbose, std::string LogFile, std::string WatchDir);
void reReadConfigFile ();
void reFilMap (bool Verbose, std::string LogFile);

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
		
		
		std::ifstream input(configFilePath.c_str());


		
		std::string delimiter = "=";
		for( std::string line; getline( input, line ); )
		{
			
			std::string token = line.substr(0, line.find(delimiter)); // token is key for map	
			std::string value = line.substr((1 + token.length()), line.length()); // value is data for map	
			
			printf("\nToken is: ");
			printf(token.c_str());
			
			printf("\nValue is: ");
			printf(value.c_str());
			
			printf("\n");
		}
		
		
		// read values from ID's
		//bool Verbose = config.getBoolValue("Verbose");
		//std::string LogFile = config.getStringValue("LogFile");
		//std::string WatchDir = config.getStringValue("WatchDir");
		
	
		//fillMapWithConfigFile (Verbose, LogFile, WatchDir);
		

		

		return;		
}



// this method accepts the values parsed from the parser
// then this method determines what to place in the map 
// Verbose will be a boolean true or false
// LogFile will be string name of a log file
// Password will be string of a password
// NumVersions will be integer representation of number of versions to keep
// WatchDir will be string of directory to watch
void fillMapWithConfigFile (bool Verbose, std::string LogFile, std::string WatchDir){
	
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



 
  
	// add the watch directory to the map, as a string
	myMap.insert(pair<int,string>(WATCHDIR, WatchDir));	
 
		
}



// this method re reads the config file
// there are only two values allowed to be reconfigured during run time

void reReadConfigFile (){

		
		readConfigFile();
		printf("\nReread config file complete.");

		
		return;		


	
}

