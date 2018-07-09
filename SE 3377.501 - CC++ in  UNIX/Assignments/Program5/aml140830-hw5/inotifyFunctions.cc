//Alex Lundin
//AML140830@utdallas.edu
//SE 3377.501 - CC++ in  UNIX

#include "program5.h"

using namespace rude;
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )

const char * file_path = "/home/013/a/am/aml140830/testdir";
void check_Number_of_Versions (std::string fileName);
void event_handler (int i, int length, char buffer[] );
void copy_To_Versions_With_Date_Stamp (std::string fileName);



void initiateWatchAndReadBlock() 
{
  int length, i;
  int fd;
  int wd;
  char buffer[BUF_LEN];

  fd = inotify_init();

  if ( fd < 0 ) {
    perror( "inotify_init" );
  }

  wd = inotify_add_watch(fd,
			 file_path,
			 IN_ALL_EVENTS);

  while(1)
  {
	  length = read( fd, buffer, BUF_LEN );

	  if ( length < 0 ) {
		  perror( "read" );
	  }
      i = 0;
	  event_handler(i, length, buffer);
  }

  ( void ) inotify_rm_watch( fd, wd );
  ( void ) close( fd );
 
}




void event_handler (int i, int length, char buffer[] ){
	
	  while ( i < length ) {
		  struct inotify_event *event = ( struct inotify_event * ) &buffer[ i ];

		  if ( event->len ) {
			  if ( event->mask & IN_CREATE ) {
				  if ( event->mask & IN_ISDIR ) {
					  printf( "\nThe directory %s was created.\n", event->name );
				  }
				  else {
					  printf( "\nThe file %s was created.\n", event->name );
					  copy_To_Versions_With_Date_Stamp (event->name);
				  }
			  }
			  else if ( event->mask & IN_DELETE ) {
				  if ( event->mask & IN_ISDIR ) {
					  printf( "\nThe directory %s was deleted.\n", event->name );
				  }
				  else {
					  printf( "\nThe file %s was deleted.\n", event->name );
				  }
			  }
			  else if ( event->mask & IN_MODIFY ) {
				  if ( event->mask & IN_ISDIR ) {
					  printf( "\nThe directory %s was modified.\n", event->name );
				  }
				  else {
					  printf( "\nThe file %s was modified.\n", event->name );
					  copy_To_Versions_With_Date_Stamp (event->name);
				  }
			  }
		  }
		  i += EVENT_SIZE + event->len;
	  }	
	
	
}




void copy_To_Versions_With_Date_Stamp (std::string fileName){

	std::string configFilePath = myMap.find(CONFIGFILE)->second;
	std::string daemonFlag = myMap.find(DFLAG)->second;
	std::string logFilePath = myMap.find(LOGFILE)->second;
	std::string numVersions = myMap.find(NUMVERSIONS)->second;
	std::string verboseFlag = myMap.find(VERBOSE)->second;
	std::string password = myMap.find(PASSWORD)->second;
	std::string watchDirectoryPath = myMap.find(WATCHDIR)->second;
	
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	std::string cwdStrng = std::string(cwd);


	// use bash shell command to manage version directory
	// create string for entire command to send to system
	//std::string commandFull = "./versionManager.sh " + watchDirectoryPath + "/.versions " + fileName + " 1";
	//printf(commandFull.c_str());
	
	
	// issue the full manage command
	//const char *commandCall = commandFull.c_str();
	//system(commandCall);
	
	// command to copy file to .versions subfolder
	// first create timeStamp string
	time_t t = time(NULL);
	struct tm *tm = localtime(&t);
	char timeStamp[20];
	strftime(timeStamp, sizeof(timeStamp), "%Y.%m.%d-%T", tm);
	
	// set current directory
	chdir(watchDirectoryPath.c_str());
	
	// create string for entire command to send to system
	std::string commandStart = "cp ";
	std::string commandFull = commandStart + fileName + " ./.versions/" +  fileName + "." + timeStamp;

	
	// issue the full copy command
	const char *commandCall = commandFull.c_str();
	const int dir_err = system(commandCall);
	if (-1 == dir_err)
	{
		printf("\nError saving date stamped copy");
		exit(1);
	}else{
		printf("\nDate stamped copy created of ");
		printf(fileName.c_str());
	}
	
	// set current directory to original
	chdir(cwd);	
}


