# Makefile for micro C lexer

all: a6it a6nit

a6it: a6it_220101096.l
	flex -o a6it_220101096.yy.c a6it_220101096.l
	gcc -o a6it a6it_220101096.yy.c -lfl

a6nit: a6nit_220101096.l
	flex -o a6nit_220101096.yy.c a6nit_220101096.l
	gcc -o a6nit a6nit_220101096.yy.c -lfl

clean:
	rm -f a6it a6nit *.yy.c *.txt

test: all
	./a6it test.nc
	mv tokens.txt a6it_tokens.txt
	mv symbol_table.txt a6it_symbol_table.txt
	./a6nit test.nc
	mv tokens.txt a6nit_tokens.txt
	mv symbol_table.txt a6nit_symbol_table.txt