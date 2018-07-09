/*
 * CS3377
 * scan.l - example flex file
 * Dr. Perkins
 *
 * https://www.youtube.com/watch?v=dK2qBbDn5W0
 *
 *  "Two all beef patties, special sauce, lettuce, cheese, pickles, onions, on a Sesame Seed Bun."
 */

%option noyywrap
%option nounput
%option noinput

%{
#include <stdlib.h>
#include "y.tab.h"
%}

%%

[ \t\r]+		{ /* eat up whitespace */ }
[\n]			{ return NEWLINE; }
[0-9]+			{ yylval.value = atoi (yytext); return INTEGER; }
"All Beef Patties"	{ return MEAT; }
"Special Sauce"		{ return SAUCE; }
"Lettuce"		{ return LETTUCE; }
"Cheese"		{ return CHEESE; }
"Pickles"		{ return PICKLES; }
"Onions"		{ return ONIONS; }
"Sesame Seed Bun"	{ return BUN; }

%%

/* 
 * This section is empty on purpose.
 *    DO NOT PUT YOUR main() routine here.
 *    
 * Put your main routine in a separate file.
 */
