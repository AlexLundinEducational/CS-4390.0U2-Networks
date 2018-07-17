//Alex Lundin
//AML140830@utdallas.edu
//Project 1
//CS-4390.0U2-Networks in  UNIX

#include "project1.h"


void processControl();
void signalRegister();
void fillMapWithConfigurationFileWrapper();
void parseConfigFile();
void printMapData();

int main(int argc, char * argv[]);
std::map <int, std::string> myMap;

// main method for project1
// distributes the work to the other methods

int main (int argc, char * argv[]){
	printf("\nNetwork started.");
	signalRegister ();
	fillMapWithConfigurationFileWrapper();
	parseConfigFile();
	printMapData();
	//processControl();
	return(0);
}
