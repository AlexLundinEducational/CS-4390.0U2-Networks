%option noyywrap
%option nounput
%option noinput

%{
#include <stdlib.h>
#include "y.tab.h"
%}
%%
\n {
	// we have to copy because we can't rely on yytext not changing underneath us:
	yylval.string = strdup(yytext);
	return EOLTOKEN;
}
[-] {
	// we have to copy because we can't rely on yytext not changing underneath us:
	yylval.string = strdup(yytext);
	return DASHTOKEN;
}
[,] {
	// we have to copy because we can't rely on yytext not changing underneath us:
	yylval.string = strdup(yytext);
	return COMMATOKEN;
}

[#] {
	// we have to copy because we can't rely on yytext not changing underneath us:
	yylval.string = strdup(yytext);
	return HASHTOKEN;
}

[a-zA-Z0-9]{1} {
	// we have to copy because we can't rely on yytext not changing underneath us:
	yylval.string = strdup(yytext);
	return IDENTIFIERTOKEN;
}
J+r+. {
	// we have to copy because we can't rely on yytext not changing underneath us:
	yylval.string = strdup(yytext);
	return JRTOKEN;
}
S+r+. {
	// we have to copy because we can't rely on yytext not changing underneath us:
	yylval.string = strdup(yytext);
	return SRTOKEN;
}
M{0,4}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3}) {
	// we have to copy because we can't rely on yytext not changing underneath us:
	yylval.string = strdup(yytext);
	return ROMANTOKEN;
}

[0-9]+ { yylval.number = atoi(yytext); return INTTOKEN; }

[a-zA-Z0-9]{1}+[.]{1} {
	// we have to copy because we can't rely on yytext not changing underneath us:
	yylval.string = strdup(yytext);
	return NAME_INITIAL_TOKEN;
}
[a-zA-Z0-9]{2,} {
	// we have to copy because we can't rely on yytext not changing underneath us:
	yylval.string = strdup(yytext);
	return NAMETOKEN;
}

.                ;
%%
