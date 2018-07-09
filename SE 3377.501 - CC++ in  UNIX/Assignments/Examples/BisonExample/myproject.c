/*
 * CS3377
 * myproject.c - use results from bison output
 * Dr. Perkins
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

int yyparse (void);

/* Just call the parser.  It will call the scanner automatically when it needs
 * another token.
*/

int main()
{

  printf("About to call the parser.\n");

  switch (yyparse())
    {
    case 0:
      printf("\nParse Successful!\n");
      break;
    case 1:
      printf("Parse Failed!\n");
      break;
    case 2:
      printf("Out of Memory\n");
      break;
    default:	
      printf("Unknown result from yyparse()\n");
      break;
    }

  printf("Finished with the parser.\n");
  return 0;
}
