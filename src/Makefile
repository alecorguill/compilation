LEX=lex
YACC=bison
CFLAGS=-Wall
CC=gcc
TEST = test/test_1.txt

all:clean parse

parse:grammar.c scanner.c
	$(CC) $(CFLAGS) -o $@ $^

grammar.c:grammar.y
	$(YACC) -t -d -o $@ --defines=grammar.tab.h $^

%.c:%.l
	$(LEX) -o $@ $^

test:clean parse
	./parse $(TEST)
clean:
	rm -f grammar.c scanner.c *~
