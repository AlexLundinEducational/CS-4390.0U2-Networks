#Alex Lundin
#AML140830@utdallas.edu
#CS-4390.0U2-Networks
#!/bin/bash
echo You can issue any of these commands straight from the Unix command line
echo scripts are a efficient way to do the same set of steps when developing.
echo
echo setting file permissions for the current directory to read, write, execute.
chmod -R 777 .
echo Compiling reader.c to standalone executable file
cc -o reader reader.c
echo Compiling writer.c to standalone executable file
cc -o writer writer.c
echo This line would link files to create executable readerWriter
echo there is no need for linking multiple object files in this example.
echo Compiling completed...
#cc reader.o writer.o -o readerWriter
echo Done compiling
echo start reader in background
./reader &
echo start writer in background
./writer &
echo
echo these are all the processes I have running....
ps -ef | grep aml140830
exit 0
