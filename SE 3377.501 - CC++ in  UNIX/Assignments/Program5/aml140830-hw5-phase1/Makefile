#
# CS3377
# Alex Lundin

#
# Flags for the C++ implicit rules
CXX = g++
CXXFLAGS = -c
CPPFLAGS = -Wall

# include flags, each must begin with a -I
INC=-I$(IDIR)

# hard coded path for include directory
IDIR = ./include

# hard coded paths of libraries
LDFLAGS = -L./library
#LDLIBS = -lcryptopp -lrudeconfig


#
# PROJECTNAME is a descriptive name used for the backup target
# This should not contain spaces or special characters
PROJECTNAME = CS3377.hw5

EXECFILE = hello

OBJS = helloworld.o
SRCS = $(wildcard *.cc)
# Because we are insane, keep the intermediate files so we can look at
# them If we comment this out (or remove it), the intermediate scan.c
# file is automatically deleted.
#.PRECIOUS: scan.c

all: $(EXECFILE)

clean:
	rm -f $(OBJS) $(EXECFILE) y.tab.h *~ \#*
	
# rule for creating objects from SRCS files, use the include flag and paths from above	
$(OBJS): $(SRCS)
	$(CXX) $^ $(INC) $(CXXFLAGS) $(SRCS)
	
# rule for creating executable, use libaray flags from above
$(EXECFILE):	$(OBJS)
	$(CXX) -static -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)


backup:
	@make clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell basename "`pwd`"))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME) 2> /dev/null
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!
