//Alex Lundin
//AML140830@utdallas.edu
//SE 3377.501 - CC++ in  UNIX

#include "program5.h"

void parseCommandLine(int, char **);
void parseConfigFile();
void processControl();
void signalRegister();


int main(int argc, char * argv[]);
std::map <int, std::string> myMap;

// main method for program 5
// distributes the work to the other methods

int main (int argc, char * argv[]){
	signalRegister ();
    parseCommandLine(argc, argv);
	parseConfigFile();
	processControl();
	return(0);
}
