all:	
	bison -d scanner.y
	flex scanner.l
	g++ scanner.tab.c lex.yy.c -lfl -o scanner