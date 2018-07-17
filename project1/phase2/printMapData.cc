//Alex Lundin
//AML140830@utdallas.edu
//Project 1
//CS-4390.0U2-Networks in  UNIX

// Development Tool
// Used to print map to screen
#include "project1.h"
using namespace std;

void printMapData (){
	
	std::string configFilePath = myMap.find(CONFIGFILE)->second;
	std::string verboseFlag = myMap.find(VERBOSE)->second;
	std::string logFilePath = myMap.find(LOGFILE)->second;
	std::string watchDirectoryPath = myMap.find(WATCHDIR)->second;
	std::string daemonFlag = myMap.find(DFLAG)->second;
	
	cout << std::endl;
	cout << "MAP---" << std::endl;
	
	cout << "Config file path: " << configFilePath << std::endl;
	cout << "Verbose flag is set to: " << verboseFlag << std::endl;
	cout << "Log file path: " << logFilePath << std::endl;
	cout << "Watch directory path: " << watchDirectoryPath << std::endl;
	cout << "Daemon flag is set to: " << daemonFlag << std::endl;
	
	cout << "MAP---" << std::endl;
}