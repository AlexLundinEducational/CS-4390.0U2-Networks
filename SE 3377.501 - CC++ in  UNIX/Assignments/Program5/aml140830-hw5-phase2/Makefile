#Alex Lundin
#AML140830@utdallas.edu
#SE 3377.501 - CC++ in  UNIX

#
# Flags for the C++ implicit rules
CXX = g++
CXXFLAGS = -c
CPPFLAGS = -Wall

# include flags, each must begin with a -I
INC=-I$(IDIR)

# hard coded path for include directory
# use home value, assuming all include packages and librarys live in the root directory
# swap $(HOME) for any other file paths and the make file will take care of the rest

IDIR = $(HOME)/include

# hard coded paths of libraries
LDFLAGS = -L$(HOME)/library
#LDLIBS = -lcryptopp -lrudeconfig


#
# PROJECTNAME is a descriptive name used for the backup target
# This should not contain spaces or special characters
PROJECTNAME = CS3377.aml140830.hw5.Phase2

EXECFILE = parse

## actually define the names of the OBJS files
OBJS = parsecmdline.o program5.o
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
	##$(CXX) -static -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)
	$(CXX) -static -o $@ $(OBJS) $(LDFLAGS)

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
