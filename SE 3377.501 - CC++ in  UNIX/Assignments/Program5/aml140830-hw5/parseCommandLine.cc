//Alex Lundin
//AML140830@utdallas.edu
//SE 3377.501 - CC++ in  UNIX

#include "program5.h"
using namespace std;
void parserForCommandLine (int argc, char * argv []);
void fillMapWithCommandLine (std::string configFilePath, bool daemonInput);


// wrapper method for this file
// sends arguments to the parserForCommandLine
// from there the parserForCommandLine will call fillMapWithCommandLine
// fil map alerts the user of the status of each value before storing to the map


void parseCommandLine (int argc, char * argv []){
	
	
	printf("\nParsing command line...");

	parserForCommandLine(argc, argv);
  
  return;
}



// this method monitors the command line
// the values found here are passed to the fillMapWithCommandLine method
// fill map will handle decisions about the values that are passed in

void parserForCommandLine (int argc, char * argv []){
	    try {  

		// Define the command line object, and insert a message
		// that describes the program. The "Command description message" 
		// is printed last in the help text. The second argument is the 
		// delimiter (usually space) and the last one is the version number. 
		// The CmdLine object parses the argv array based on the Arg objects
		// that it contains. 
		TCLAP::CmdLine cmd("cd3377dirmond Directory Monitor Daemon", ' ', "0.0");


		// Define a switch and add it to the command line.
		// the -d flag is optional
		TCLAP::SwitchArg daemonSwitchArg("d","daemon","Run in daemon mode (forks to run as a daemon).", cmd, false);

		
		// Define a unlabeled value argument and add it to the command line.
		// the config file name arg is optional
		
		TCLAP::UnlabeledValueArg<std::string>  configFileArg("configFile", "The name of the configuration file. Defaults to cs 3377dirmond.conf", false, 
		"cs3377dirmond.conf",
		"config filename", false);		
	
		// Add the argument configFileArg to the CmdLine object. The CmdLine object
		// uses this Arg to parse the command line.
		cmd.add( configFileArg );
		
		//Parse the argv array.
		cmd.parse( argc, argv );

		// Get the value parsed by each arg. 
		std::string configFilePath = configFileArg.getValue();
		bool daemonInput = "false";
		
		daemonInput = daemonSwitchArg.getValue();

		
		fillMapWithCommandLine ( configFilePath, daemonInput);
		
      
      } 
      catch (TCLAP::ArgException &e)  // catch any exceptions
	{ 
		std::cerr << "\nerror: " << e.error() << " for arg " << e.argId() << std::endl; 
			return;
	}
}



// this method accepts the values parsed from the parserForCommandLine
// then this method determines what to place in the map 
// the CONFIGFILE will be the string passed in from the command line, or the default value stored in the argument 
// the DFLAG will be a boolean true if the -d flag exists, or a boolean false otherwise

void fillMapWithCommandLine (std::string configFilePath, bool daemonInput){
	
		
	std::string TrueString = "true";
	std::string FalseString = "false";
	
		
	// add the config file path to the map, as a string
	myMap.insert(pair<int,string>(CONFIGFILE, configFilePath));    
	
	
	
	// add the daemon input flag to the map in the form of a boolean value
		if ( daemonInput )
	{
		myMap.insert(pair<int,string>(DFLAG, TrueString ));		  
	}
		else{
		myMap.insert(pair<int,string>(DFLAG, FalseString ));				
			
		}
	  



	
}