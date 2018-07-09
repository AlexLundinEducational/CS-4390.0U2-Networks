/*
 * CS3377
 * myproject.c - use results from flex output
 * Dr. Perkins
 */

#include <stdio.h>             /* needed for printf() */
#include "myproject.h"         /* needed for ENUM */


/* 
 * Manually insert prototype and extern declarations for the
 * stuff in the flex output file.
 */
int yylex(void);
extern char *yytext;


/* Just call the lexical scanner until we reach EOF */

int main()
{
  int token;
  
  token = yylex();

  while(token != 0)
    {
      printf("The Token has the integer value %d\n", token);
      printf("\tThis token corresponds to: ");

      switch(token)
	{
	case HASH:
	  printf("HASH\n");
	  break;
	case COMMA:
	  printf("COMMA\n");
	  break;
	case DASH:
	  printf("DASH\n");
	  break;
	case SR:
	  printf("SR\n");
	  break;
	case JR:
	  printf("JR\n");
	  break;
	case INTEGER:
	  printf("INTEGER\n");
	  printf("\tThe integer string was: %s\n", yytext);
	  break;
	default:
	  printf("UNKNOWN\n");
	}

      token = yylex();
    }
  
  printf("Done\n");
  return 0;
}
