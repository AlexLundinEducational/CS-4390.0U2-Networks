//Alex Lundin
//AML140830@utdallas.edu
//SE 3377.501 - CC++ in  UNIX

// Development Tool
// Used to print map to screen
#include "program5.h"
using namespace std;

void printMapData (){
	
	std::string configFilePath = myMap.find(CONFIGFILE)->second;
	std::string daemonFlag = myMap.find(DFLAG)->second;
	std::string logFilePath = myMap.find(LOGFILE)->second;
	std::string numVersions = myMap.find(NUMVERSIONS)->second;
	std::string verboseFlag = myMap.find(VERBOSE)->second;
	std::string password = myMap.find(PASSWORD)->second;
	std::string watchDirectoryPath = myMap.find(WATCHDIR)->second;
	
	cout << std::endl;
	cout << "MAP---" << std::endl;
	
	cout << "Config file path: " << configFilePath << std::endl;
	cout << "Log file path: " << logFilePath << std::endl;
	cout << "Watch directory path: " << watchDirectoryPath << std::endl;
	cout << "Daemon flag is set to: " << daemonFlag << std::endl;
	cout << "Verbose flag is set to: " << verboseFlag << std::endl;
	cout << "Number of versions to keep: " << numVersions << std::endl;
	cout << "Password is: " << password << std::endl;
	
	cout << "MAP---" << std::endl;
}