//Alex Lundin
//AML140830@utdallas.edu
//SE 3377.501 - CC++ in  UNIX
#ifndef PROGRAM2_H
#define  PROGRAM2_H

#include <tclap/CmdLine.h>
#include <tclap/SwitchArg.h>
#include <tclap/UnlabeledValueArg.h>
#include <tclap/ValueArg.h>
#include <tclap/Arg.h>

#include <map>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string> 
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
extern std::map <int, std::string> myMap;
using namespace std;
void parseCmdLine(int, char **);
void doWork();
enum myEnums {INFILE,OUTFILE,UFLAG,LFLAG};
#endif // PROGRAM2_H

