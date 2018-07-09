#Alex Lundin
#AML140830@utdallas.edu
#SE 3357.501 - C++ in UNIX#Alex Lundin
#!/bin/bash
rm stdout.log
rm stderr.log
echo Running 'hw1' with 0 arguments
echo "        stdout appended to stdout.log"
echo "        stderr appended to stderr.log"
./hw1
echo Running 'hw1' with 1 arguments
echo "        stdout appended to stdout.log"
echo "        stderr appended to stderr.log"
./hw1 abc
echo Running 'hw1' with 5 arguments
echo "        stdout appended to stdout.log"
echo "        stderr appended to stderr.log"
./hw1 a b c d e
exit 0
