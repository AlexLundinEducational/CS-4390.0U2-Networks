//Alex Lundin
//AML140830@utdallas.edu
//SE 3377.501 - CC++ in  UNIX

#include "program2.h"
using namespace std;
void parser (int argc, char * argv []);
void fillMap (std::string inputFilePath, std::string outputFilePath, bool upperCaseInput, bool lowerCaseInput);
void parseCmdLine (int argc, char * argv []){
	
	cout << "In parseCmdLine";

	parser(argc, argv);
  
  return;
}


void parser (int argc, char * argv []){
	    try {  

		// Define the command line object, and insert a message
		// that describes the program. The "Command description message" 
		// is printed last in the help text. The second argument is the 
		// delimiter (usually space) and the last one is the version number. 
		// The CmdLine object parses the argv array based on the Arg objects
		// that it contains. 
		TCLAP::CmdLine cmd("Displays useage information and exits", ' ', "0.0");

		// Define a value argument and add it to the command line.
		// A value arg defines a flag and a type of value that it expects,
		// such as "-n Bishop".
		TCLAP::ValueArg<std::string> outputFileArg("o","outfile","<output file name>",true,"homer","output filename");

		// Add the argument outputFileArg to the CmdLine object. The CmdLine object
		// uses this Arg to parse the command line.
		cmd.add( outputFileArg );

		// Define a switch and add it to the command line.
		TCLAP::SwitchArg upperSwitchArg("u","uu","Convert all text to uppercase", cmd, false);

		// Define a switch and add it to the command line.
		TCLAP::SwitchArg lowerSwitchArg("l","lower","Convert all text to lowercase", cmd, false);

		TCLAP::UnlabeledValueArg<string>  inputFileNoLabel( "inputfile", "<input file name>", true ,"string" ,
							  "input filename", false );
		cmd.add( inputFileNoLabel );

		//Parse the argv array.
		cmd.parse( argc, argv );

		// Get the value parsed by each arg. 
		std::string inputFilePath = inputFileNoLabel.getValue();
		std::string outputFilePath = outputFileArg.getValue();
		bool upperCaseInput = "false";
		bool lowerCaseInput = "false";
		
		upperCaseInput = upperSwitchArg.getValue();
		lowerCaseInput = lowerSwitchArg.getValue();
		
		if (upperCaseInput && lowerCaseInput){
		std::cerr << "\nerror: only one case argument allowed -l or -u." << std::endl; 
			return;			
		}		
		
		if (outputFilePath == "null"){
		std::string outputFilePath = "output.txt"; 		
		}	
		
		fillMap (inputFilePath, outputFilePath, upperCaseInput, lowerCaseInput);
		

      
      } 
      catch (TCLAP::ArgException &e)  // catch any exceptions
	{ 
		std::cerr << "\nerror: " << e.error() << " for arg " << e.argId() << std::endl; 
			return;
	}
}




void fillMap (std::string inputFilePath, std::string outputFilePath, bool upperCaseInput, bool lowerCaseInput){
	
	myMap.insert(pair<int,string>(INFILE, inputFilePath));
	myMap.insert(pair<int,string>(OUTFILE, outputFilePath));    
	std::string TrueString = "true";
	std::string FalseString = "false";
	

	
	// Do what you intend. 
		if ( upperCaseInput )
	{
		std::cout << "\nUpper case" << std::endl;
		myMap.insert(pair<int,string>(UFLAG, TrueString ));
		myMap.insert(pair<int,string>(LFLAG, FalseString)); 		  
	}
	  
	// Do what you intend. 
		if ( lowerCaseInput )
	{
		std::cout << "\nLower case " << std::endl;
		myMap.insert(pair<int,string>(UFLAG, FalseString));
		myMap.insert(pair<int,string>(LFLAG, TrueString ));  	
	}


	
}