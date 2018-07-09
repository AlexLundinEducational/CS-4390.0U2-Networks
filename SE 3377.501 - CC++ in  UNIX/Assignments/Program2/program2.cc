//Alex Lundin
//AML140830@utdallas.edu
//SE 3377.501 - CC++ in  UNIX

#include "program2.h"

void parseCmdLine (int, char **);
void DoWork ();
int main(int argc, char * argv[]);
std::map <int, std::string> myMap;
int main (int argc, char * argv[]){

    parseCmdLine(argc, argv);
	DoWork();
	return(0);
}
