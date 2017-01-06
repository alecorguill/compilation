+LEX=lex
YACC=bison
CFLAGS=-Wall -g
CC=gcc

all:parse

parse:grammar.c scanner.c def.o sym.o hash_table.o
	$(CC) $(CFLAGS) -o $@ $^

def.o: def.c
	$(CC) $(CFLAGS) -c $^ -o  def.o

hash_table.o: variable.o hash_table.c
	$(CC) $(CFLAGS) -c $^ -o  hash_table.o

sym.o: sym.c
	$(CC) $(CFLAGS) -c $^ -o  sym.o


grammar.c:grammar.y
	$(YACC) -d -o $@ -g $^

%.c:%.l
	$(LEX) -o $@ $^

clean:
	rm -f grammar.c grammar.dot scanner.c grammar.h *.o *~ parse
