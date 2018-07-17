//Alex Lundin
//AML140830@utdallas.edu
//Project 1
//CS-4390.0U2-Networks in  UNIX

#include "project1.h"
using namespace std;

void fillMapWithConfigurationFileLocation();

// wrapper method for this file
// fil map and alerts the user of the status of each value before storing to the map


void fillMapWithConfigurationFileWrapper(){
	
	
	printf("\nInitiating map with config file...");

	fillMapWithConfigurationFileLocation();
  
  return;
}




// this method stores the configuration file to the map
void fillMapWithConfigurationFileLocation(){
	
		
	// store value for configuration file location 
	std::string configFilePath = "network.conf";

			
	// add the config file path to the map, as a string
	myMap.insert(pair<int,string>(CONFIGFILE, configFilePath));  
	printf("\nConfiguration file found at:");
	printf("\n");
	printf(configFilePath.c_str());
	
	printf("\n");
}