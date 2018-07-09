//Alex Lundin
//AML140830@utdallas.edu
//SE 3357.501 - C++ in UNIX
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
void proc1(){
FILE *stream;
freopen( "stderr.log" , "a" , stderr);
std::cerr << "Inside proc1() as stderr\n";
stream = freopen("CON", "a" , stderr);
}
