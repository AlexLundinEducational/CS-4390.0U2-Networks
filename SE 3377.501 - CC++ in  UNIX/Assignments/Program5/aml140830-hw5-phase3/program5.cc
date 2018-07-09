//Alex Lundin
//AML140830@utdallas.edu
//SE 3377.501 - CC++ in  UNIX

#include "program5.h"

void parseCmdLine (int, char **);
void parseConfig ();
int main(int argc, char * argv[]);
std::map <int, std::string> myMap;

// main method for program 5
// distributes the work to the other methods

int main (int argc, char * argv[]){

    parseCmdLine(argc, argv);
	parseConfig();
	printMapData();
	return(0);
}
