#Alex Lundin
#AML140830@utdallas.edu
#SE 3377.501 - CC++ in  UNIX
#!/bin/bash
echo Setting TEMPDIR environment variable to /scratch
echo Compiling file1.cc
g++ -c file1.cc
echo Compiling file2.cc
g++ -c file2.cc
echo Linking files to create executable hw1
g++ file1.o file2.o -o hw1
echo Done
exit 0
