%{
#include <cstdio>
#include <iostream>
using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
 
void yyerror(const char *s);
%}

// Bison fundamentally works by asking flex to get the next token, which it
// returns as an object of type "yystype".  But tokens could be of any
// arbitrary data type!  So we deal with that in Bison by defining a C union
// holding each of the types of tokens that Flex could return, and have Bison
// use that union instead of "int" for the definition of "yystype":
%union {
	
	char *name;
	char *id;
	char *nameInitial;
	char *roman;
	char *sr;
	char *jr;
	char *eol;
	int ival;
	char *comma;
	char *dash;
	char *hash;
}

// define the constant-string tokens:
%token SNAZZLE TYPE
%token END

// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:

%token <name> NAMETOKEN
%token <id> IDENTIFIERTOKEN
%token <nameInitial> NAME_INITIAL_TOKEN
%token <roman> ROMANTOKEN
%token <sr> SRTOKEN
%token <jr> JRTOKEN
%token <eol> EOLTOKEN
%token <ival> INTTOKEN
%token <comma> COMMATOKEN
%token <dash> DASHTOKEN
%token <hash> HASHTOKEN

%%
// this is the actual grammar that bison will parse, but for right now it's just
// something silly to echo to the screen what bison gets from flex.  We'll
// make a real one shortly:
snazzle:
	snazzle NAMETOKEN { cout << "bison found a name: " << $2 << endl; }
	| snazzle IDENTIFIERTOKEN { cout << "bison found an id: " << $2 << endl; }
	| snazzle NAME_INITIAL_TOKEN { cout << "bison found an name initial: " << $2 << endl; }
	| snazzle ROMANTOKEN { cout << "bison found an roman numeral: " << $2 << endl; }
	| snazzle SRTOKEN { cout << "bison found an sr: " << $2 << endl; }
	| snazzle JRTOKEN { cout << "bison found an jr: " << $2 << endl; }
	| snazzle EOLTOKEN { cout << "bison found a end of line: " << $2 << endl; }
	| snazzle INTTOKEN { cout << "bison found an int: " << $2 << endl; }
	| snazzle COMMATOKEN { cout << "bison found a comma: " << $2 << endl; }
	| snazzle DASHTOKEN{ cout << "bison found a dash: " << $2 << endl; }
	| snazzle HASHTOKEN{ cout << "bison found a hash: " << $2 << endl; }
	| NAMETOKEN { cout << "bison found a name: " << $1 << endl; }
	| IDENTIFIERTOKEN { cout << "bison found an id: " << $1 << endl; }
	| NAME_INITIAL_TOKEN { cout << "bison found an name initial: " << $1 << endl; }
	| ROMANTOKEN { cout << "bison found an roman numeral: " << $1 << endl; }
	| SRTOKEN { cout << "bison found an sr: " << $1 << endl; }
	| JRTOKEN { cout << "bison found an jr: " << $1 << endl; }
	| EOLTOKEN { cout << "bison found a end of line: " << $1 << endl; }
	| INTTOKEN { cout << "bison found an int: " << $1 << endl; }
	| COMMATOKEN { cout << "bison found a comma: " << $1 << endl; }
	| DASHTOKEN { cout << "bison found a dash: " << $1 << endl; }
	| HASHTOKEN { cout << "bison found a hash: " << $1 << endl; }
	;
%%

int main(int, char**) {
	// open a file handle to a particular file:
	FILE *myfile = fopen("input.txt", "r");
	// make sure it's valid:
	if (!myfile) {
		cout << "I can't open input.txt!" << endl;
		return -1;
	}
	// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;

	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	
}

void yyerror(const char *s) {
	cout << "EEK, parse error!  Message: " << s << endl;
	// might as well halt now:
	exit(-1);
}