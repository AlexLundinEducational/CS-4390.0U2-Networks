/*
 * Popen() example
 *
 * Author: Perkins
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
  FILE *output_from_command;
  char tmpbuffer[BUFFER_SIZE];
  char *line_p;

  // This is a C++ style string object that contains
  // the shell command.
  string shellcmd = "/bin/ps";

  // Print it to the screen for good measure
  cout << endl;
  cout << "\tShellcmd to execute is: " << shellcmd << endl;
  cout << endl;
  
  // Now... Execute the shell command.  The output
  // from the command is returned as file stream.
  // Remember... popen wants a C style string... not a 
  // c++ String Object.
  output_from_command = popen(shellcmd.c_str(), "r");

  // make sure it opened else error out
  if (!output_from_command)
    return -1;

  // Now... treat the output from the command as if it
  // were an open file.  Just read from the file and 
  // display to screen.
  
  cout << endl;
  cout << "\tThe call to ps returned:" << endl << endl;

  // Read at most BUFFER_SIZE bytes from file and store in 
  // tmpbuffer.  Returns NULL on EOF.
  line_p = fgets(tmpbuffer, BUFFER_SIZE, output_from_command);

  while(line_p != NULL)
    {
      printf("\t%s", line_p);
      line_p = fgets(tmpbuffer, BUFFER_SIZE, output_from_command);
    }
 
  // make sure we close what we open.
  pclose(output_from_command);

  cout << endl;
  cout << endl;

  return 0;
}