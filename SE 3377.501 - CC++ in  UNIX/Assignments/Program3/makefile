#Alex Lundin
#AML140830@utdallas.edi
#SE 3377.501 CC+ in UNIX
#makefile
#rule for hw3 target
hw3: hw3.o file1.cc
	g++ file1.cc -o hw3.o
#rule for hw3 object file
hw3.o: file1.cc
	g++ -c file1.cc
	
# Project name.  This is used in building the file name for the backup target
PROJECTNAME = Program3
clean:
	rm -f $(OBJS) $(EXECFILE) *.P *~ \#* *.o

# Backup Target
backup:	clean
	@mkdir -p ./tball; chmod 700 ./tball
	@$(eval CURDIRNAME := $(shell basename `pwd`))
	@$(eval MKBKUPNAME := ./tball/$(PROJECTNAME).tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME)  ../$(CURDIRNAME) 
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!