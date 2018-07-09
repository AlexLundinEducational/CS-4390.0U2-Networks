//Alex Lundin
//AML140830@utdallas.edu
//SE 3357.501 - C++ in UNIX
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
void proc1();
int main(int argc, char *argv[]);
int main(int argc, char *argv[]){
  FILE *stream;
  freopen( "stdout.log", "a", stdout );
  cout << "argc was:" << argc << endl;

  // print loop for array
  for (int a = 0; a < argc; a = a + 1){
    cout << (argv[a]) << endl;
  }

  cout << "Done!" << endl;
  stream = freopen("CON", "a", stdout);
  proc1();
  return 0;
}
