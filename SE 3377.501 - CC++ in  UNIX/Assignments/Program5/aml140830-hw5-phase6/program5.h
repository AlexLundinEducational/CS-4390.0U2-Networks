//Alex Lundin
//AML140830@utdallas.edu
//SE 3377.501 - CC++ in  UNIX
#ifndef PROGRAM5_H
#define  PROGRAM5_H

#include <tclap/CmdLine.h>
#include <tclap/SwitchArg.h>
#include <tclap/UnlabeledValueArg.h>
#include <tclap/ValueArg.h>
#include <tclap/Arg.h>
#include <rude/config.h>
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
void parseCommandLine(int, char **);
void processControl();
void printMapData();
enum myEnums {CONFIGFILE,DFLAG, LOGFILE, NUMVERSIONS, VERBOSE, PASSWORD, WATCHDIR};
#endif // PROGRAM5_H

