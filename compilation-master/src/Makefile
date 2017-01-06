+LEX=lex
YACC=bison
CFLAGS=-Wall -g
CC=gcc
TSTGEN=test/test_gen/*

all:parse

testgen:
	for file in $(TSTGEN) ; do\
		echo "=================================================";\
		echo"";\
		echo "Génération de $$file";\
		echo"";\
		./parse $$file ;\
		echo"";\
	echo "=================================================";\
	done


parse:grammar.c scanner.c sym.o hash_table.o
	$(CC) $(CFLAGS) -o $@ $^

hash_table.o: sym.o hash_table.c
	$(CC) $(CFLAGS) -c $^ -o  hash_table.o

sym.o: sym.c
	$(CC) $(CFLAGS) -c $^ -o  sym.o


grammar.c:grammar.y
	$(YACC) -d -o $@ -g $^

%.c:%.l
	$(LEX) -o $@ $^

clean:
	rm -f grammar.c scanner.c grammar.h *.o *~ parse grammar.dot
