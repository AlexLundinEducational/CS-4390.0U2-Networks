/*
 * CS3377
 * parse.y - example bison file
 * Dr. Perkins
 *
 * https://www.youtube.com/watch?v=dK2qBbDn5W0
 *
 *  "Two all beef patties, special sauce, lettuce, cheese, pickles, onions, on a Sesame Seed Bun."
 */



%{
  #include <stdio.h>
  int yylex(void);
  void yyerror(char *);
%}

%union
{
    int value;
    char *str;
}

%type	<value>	INTEGER
%type	<str>   MEAT
%type	<str>   SAUCE
%type	<str>   LETTUCE
%type	<str>   CHEESE
%type	<str>	PICKLES
%type	<str>	ONIONS
%type	<str>	BUN


%token  MEAT
%token  SAUCE
%token  LETTUCE
%token	CHEESE
%token	PICKLES
%token	ONIONS
%token	BUN
%token  INTEGER
%token	NEWLINE

%start	Several_BigMacs

%%

/*
 * Careful here... the very last entry in the source file should not
 * have a double newline.  An extra blank line indicates that another
 * BigMac Description is starting.
 *
 * This entry follows the pattern in the notes that discusses
 * how to handle an unknown number of items.
 */


Several_BigMacs:
			Several_BigMacs NEWLINE BigMac
		|	BigMac
		;

/*
 * Careful here, each of the parts of the Big Mac  should be on
 * their own line.  Therefore, each part definition below requires that it see a
 * NEWLINE at the end.  The very last line of the input file needs a final
 * new line after the final bun.  Do not follow by
 * an extra new line as tht indicates another starting Big Mac.
 * 
 * Doing things this way allows us to use the 'error' token and skip
 * to the NEWLINE to throw away the line we are working on, but
 * continue with the next line in case it is OK.
 */

BigMac:
		  	Meaty_BigMac 
	|		Vegeterian_BigMac
	|	        error NEWLINE { printf("Bad Big Mac Description... skipping to next line to try to recover\n"); }
	;

Meaty_BigMac:
		BUN NEWLINE INTEGER MEAT NEWLINE SAUCE NEWLINE LETTUCE NEWLINE CHEESE NEWLINE PICKLES NEWLINE ONIONS NEWLINE BUN NEWLINE {fprintf(stderr, "Found a Meaty Big Mac with %d Patties!!!\n", $3); }
	;

Vegeterian_BigMac:
		BUN NEWLINE SAUCE NEWLINE LETTUCE NEWLINE CHEESE NEWLINE PICKLES NEWLINE ONIONS NEWLINE BUN NEWLINE {fprintf(stderr, "Found a Vegeterian Big Mac!!!\n");}
	;


%%

void yyerror(char *s)
{
}


