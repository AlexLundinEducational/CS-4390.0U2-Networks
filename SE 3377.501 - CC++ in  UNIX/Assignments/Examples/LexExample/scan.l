/*
 * CS3377
 * scan.l - example flex file
 * Dr. Perkins
 */

%option noyywrap
%option nounput
%option noinput

%{
  #include <stdlib.h>
  #include "myproject.h"
%}

%%


[ \t\r]+			{ /* eat up whitespace */ }
"#"				{ return HASH; }
","				{ return COMMA; }
"-"				{ return DASH; }
"Sr."				{ return SR; }
"Jr."				{ return JR; }
[0-9]+				{ return INTEGER; }


%%

/* 
 * This section is empty on purpose.
 *    DO NOT PUT YOUR main() routine here.
 *    
 * Put your main routine in a separate file.
 */
