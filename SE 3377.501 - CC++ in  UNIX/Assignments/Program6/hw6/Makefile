#Alex Lundin
#AML140830@utdallas.edu
#SE 3377.501 - CC++ in  UNIX

# see the *** tags for easy swap outs to paths
# the sections below use the paths for the make file variables

# I chose to use the lib and include from the scratch disk

# ***
# hard coded paths of libraries
# I pointed my install paths to ~, so the libraries unpacked to ~/lib for every install
LDFLAGS = -L /scratch/perkins/lib

# these are the names of the library files to link with
# the complier will look in the library directory for any files specified here
LDLIBS =  -lcdk -lcurses

# During each install, the software placed a include folder in the ~ directory for each package
# So I pointed my include directory to ~/include
# which had my cryptopp, rude and tclap ready to go

# ***
# hard coded path for include directory
# I chose to use the scratch disk again
IDIR = /scratch/perkins/include/


#
# Flags for the C++ implicit rules
CXX = g++
CXXFLAGS = -c
CPPFLAGS = -Wall -g

# include flags, each must begin with a -I
INC=-I$(IDIR)


#
# PROJECTNAME is a descriptive name used for the backup target
# This should not contain spaces or special characters
PROJECTNAME = aml140830.hw6

EXECFILE = hw6

## actually define the names of the OBJS files
## OBJS = CDKmatrix.o BinaryFileHeader.o BinaryFileRecord.o
OBJS = CDKmatrix.o
## use wild cards to define what types of files SRCS are
SRCS = $(wildcard *.cc)


all: $(EXECFILE)

clean:
	rm -f $(OBJS) $(EXECFILE) *~ \#*
	
# rule for creating objects from SRCS files, use the include flag and paths from above	
$(OBJS): $(SRCS)
	$(CXX) $^ $(INC) $(CXXFLAGS) $(SRCS)
	
# rule for creating executable, use libaray flags from above
$(EXECFILE):	$(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)

# backup creates two tarballs
# the first, is a backup with a complex file name for logging purposes
# the unique names on backup logs allow multiple versions
# the second, is a backup with a simple file name
# the simple ones are for homework submissions
# to make the TA's life easy
# always remove any existing homework submission before saving that second copy
backup:
	@make clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell basename "`pwd`"))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
	@$(eval SUBMISSION := ~/backups/$(PROJECTNAME).tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME) 2> /dev/null
	@chmod 777 $(MKBKUPNAME)
	@echo Writing homework submission file to: $(SUBMISSION)
	@rm -f $(SUBMISSION)
	@-tar zcfv $(SUBMISSION) ../$(CURDIRNAME) 2> /dev/null
	@chmod 777 $(SUBMISSION)
	@echo
	@echo Done!
