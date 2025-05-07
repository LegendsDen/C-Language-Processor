CC = g++
LEX = flex
YACC = bison
CFLAGS = -std=c++11

all: a9_220101096

a9_220101096: A9_220101096.tab.c lex.yy.c A9_220101096_translator.cpp
	$(CC) $(CFLAGS) A9_220101096.tab.c lex.yy.c A9_220101096_translator.cpp -o a9_220101096 -lfl

A9_220101096.tab.c: A9_220101096.y
	$(YACC) -d A9_220101096.y -o A9_220101096.tab.c

lex.yy.c: A9_220101096.l
	$(LEX) A9_220101096.l

clean:
	rm -f a9_220101096 A9_220101096.tab.c lex.yy.c A9_220101096.tab.h

test: a9_220101096
	./a9_220101096 < test_input.mc > output.asm
	cat output.asm

.PHONY: all clean test