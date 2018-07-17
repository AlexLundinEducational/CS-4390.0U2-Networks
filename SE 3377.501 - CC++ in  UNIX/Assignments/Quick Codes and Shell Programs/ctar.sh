#Alex Lundin
#AML140830@utdallas.edu
#SE 3377.501 - CC++ in  UNIX
#!/bin/bash
#this line creates a tarbar from your a folder, called folder-name, in your current directory
#you need to specifcy the tarball name with "my.tar.gz"
#you need to specify the folder in your current directory with "folder-name"
#don't put a full path on the folder-name
#make sure the folder called folder-name is visible from the current directory
tar -zxvf my.tar.gz folder-name
# untar
# this line untars the "my.tar.gz" that is in the current directory
tar -xvzf my.tar.gz