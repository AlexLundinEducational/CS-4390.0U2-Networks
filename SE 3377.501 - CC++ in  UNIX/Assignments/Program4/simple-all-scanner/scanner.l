%{
#include <iostream>
#include "scanner.tab.h"
using namespace std;
#define YY_DECL extern "C" int yylex()
%}
%%
    /* match everything except newline */
.   ECHO;
    /* match newline */
\n  ECHO;
%%