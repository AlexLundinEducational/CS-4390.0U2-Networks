#Alex Lundin
#AML140830@utdallas.edu
#SE 3377.501 - CC++ in  UNIX

# see the *** tags for easy swap outs to paths
# the sections below use the paths for the make file variables

# I chose to install all my source code packages into the ~/libs directory
# this means all the installation steps handled the folder strucutre, and I tailored my make file around it
# During each install, the software created a /lib and a /include

# ***
# hard coded paths of libraries
# I pointed my install paths to ~/libs, so the libraries unpacked to ~/libs/lib for every install
LDFLAGS = -L$(HOME)/libs/lib 

# these are the names of the library files to link with
# the complier will look in the library directory for any files specified here
# examples, ~/libs/lib/libcryptopp.so and ~/libs/lib/librudeconfig.so
LDLIBS = -lcryptopp -lrudeconfig

# During each install, the software placed a include folder in the ~/libs directory for each package
# So I pointed my include directory to ~/libs/include
# which had my cryptopp, rude and tclap ready to go

# ***
# hard coded path for include directory
# I chose 
# use home value, assuming all include packages and librarys live in the root directory
# swap $(HOME) for any other file paths and the make file will take care of the rest
IDIR = $(HOME)/libs/include


#
# Flags for the C++ implicit rules
CXX = g++
CXXFLAGS = -c
CPPFLAGS = -Wall

# include flags, each must begin with a -I
INC=-I$(IDIR)


#
# PROJECTNAME is a descriptive name used for the backup target
# This should not contain spaces or special characters
PROJECTNAME = CS3377.aml140830.hw5.Phase3

EXECFILE = parse

## actually define the names of the OBJS files
OBJS = parsecmdline.o program5.o parseconfig.o printmapdata.o
## use wild cards to define what types of files SRCS are
SRCS = $(wildcard *.cc)


all: $(EXECFILE)

clean:
	rm -f $(OBJS) $(EXECFILE) y.tab.h *~ \#*
	
# rule for creating objects from SRCS files, use the include flag and paths from above	
$(OBJS): $(SRCS)
	$(CXX) $^ $(INC) $(CXXFLAGS) $(SRCS)
	
# rule for creating executable, use libaray flags from above
$(EXECFILE):	$(OBJS)
	$(CXX) -static -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)

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
