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

#include <map>
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
extern std::map <int, std::string> myMap;
using namespace std;
void parseCmdLine(int, char **);
void doWork();
void printMapData();
enum myEnums {CONFIGFILE,DFLAG, LOGFILE, NUMVERSIONS, VERBOSE, PASSWORD, WATCHDIR};
#endif // PROGRAM5_H

