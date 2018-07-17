#Alex Lundin
#AML140830@utdallas.edu
#CS-4390.0U2-Networks

# see the *** tags for easy swap outs to paths
# the sections below use the paths for the make file variables


#
# Flags for the C++ implicit rules
CC = gcc
CPPFLAGS =
CFLAGS =

#
# PROJECTNAME is a descriptive name used for the backup target
# This should not contain spaces or special characters
PROJECTNAME = writerReader

EXECFILES = reader writer

## actually define the names of the OBJS files
OBJS = reader.o writer.o
## project1.o printMapData.o processControl.o signalHandling.o inotifyFunctions.o
## use wild cards to define what types of files SRCS are
SRCS = $(wildcard *.c)


all: $(EXECFILES)

clean:
	rm -f $(OBJS) $(EXECFILE) *~ \#*
	
# rule for creating objects from all SRCS files
# use the CPPFLAGS CFLAGS from above
$(OBJS): $(SRCS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<
	
# rule for creating standalone executables from each object file
$(EXECFILES):	$(OBJS)
	$(CC) -o $@ $<

run:
	@echo start reader in background
	@./reader &
	@echo start writer in background
	@./writer &

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
