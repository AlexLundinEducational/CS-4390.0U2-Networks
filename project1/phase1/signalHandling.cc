//Alex Lundin
//AML140830@utdallas.edu
//Project 1
//CS-4390.0U2-Networks in  UNIX

#include "project1.h"


using namespace std;

void open_log();
void close_log();
void close_pid();
void signalRegister();
void printMapData ();
void signal_HUP_Handler( int signum );
void signal_INT_Handler( int signum );
void signal_TERM_Handler( int signum );


// this is the SIGHUP handler for program5
// signum is the signal received, and this function decides what to do, depending on the signal
void signal_HUP_Handler( int signum ) {
	
   std::string verboseFlag = "";

	// SIGHUP
	// re-read config file and store values in map
	// open log will decide to append to the log file or create a new one based on the map
	if	( signum == 1 ){
		close_log();
		// reReadConfigFile();
		
		verboseFlag = myMap.find(VERBOSE)->second;
		
		if	(verboseFlag == "true"){
			printf("\nInterrupt signal SIGHUP received.");
			printf("\nClosing log.");
			printf("\nRe-reading configuration file to map.");
			// used during development to check if data made it to the map by printing to the log
			// printMapData();
			printf("\nHandling log re-open process...");
		}
			
		open_log();
	}
   

	return;
}


// this is the SIGINT handler for program5
// signum is the signal received, and this function decides what to do, depending on the signal and verbosity level
void signal_INT_Handler( int signum ) {
	
	std::string verboseFlag = "";
	verboseFlag = myMap.find(VERBOSE)->second;

   
	// terminate on SIGINT
	if	( signum == 2 ){
		if	(verboseFlag == "true"){
			printf("\nInterrupt signal SIGINT received.");
			printf("\nGracefully exiting program.");
			// write to log that pid file is deleted
			printf("\nPid file deleted.");
			// write to log that pid file is deleted
			printf("\nLog file closing.");
		}		

		// cleanup and close files
		close_pid();

		close_log();

		// terminate program  
		exit(signum);  

	}	   
	
	return;
}


// this is the SIGTERM handler for program5
// signum is the signal received, and this function decides what to do, depending on the signal and verbosity level
void signal_TERM_Handler( int signum ) {
	
	std::string verboseFlag = "";
	verboseFlag = myMap.find(VERBOSE)->second;

   
	// terminate on SIGTERM
	if	( signum == 15 ){
		if	(verboseFlag == "true"){
			printf("\nInterrupt signal SIGTERM received.");
			printf("\nGracefully exiting program.");
			// write to log that pid file is deleted
			printf("\nPid file deleted.");
			// write to log that pid file is deleted
			printf("\nLog file closing.");
			
		}		
	
		// cleanup and close files
		close_pid();
		close_log();

		
		// terminate program  
		exit(signum);  

	}	   
	
	return;

}

// registers each value to the correct handler
void signalRegister(){
	
	// register signal SIGINT and signal handler  
	signal(SIGINT, signal_INT_Handler); 	
	signal(SIGTERM, signal_TERM_Handler); 	
	signal(SIGHUP, signal_HUP_Handler); 	
	
}