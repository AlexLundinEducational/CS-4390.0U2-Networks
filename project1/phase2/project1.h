//Alex Lundin
//AML140830@utdallas.edu
//Project 1
//CS-4390.0U2-Networks in  UNIX
#ifndef PROGRAM1_H
#define  PROGRAM1_H

#include <sys/stat.h>
#include <sys/file.h>
#include <errno.h>
#include <map>
#include <iostream>
#include <csignal>
#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string> 
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
extern std::map <int, std::string> myMap;
using namespace std;
void processControl();
void signalRegister();
void fillMapWithConfigurationFileWrapper();
void parseConfigFile();
void printMapData();
enum myEnums {CONFIGFILE,DFLAG, LOGFILE, NUMVERSIONS, VERBOSE, PASSWORD, WATCHDIR};
#endif // PROGRAM1_H

