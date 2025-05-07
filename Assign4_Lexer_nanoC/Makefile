all: Lexical_Analyzer

Lexical_Analyzer: Lexical_Analyzer.l
	flex Lexical_Analyzer.l
	gcc lex.yy.c -o Lexical_Analyzer -lfl

clean:
	rm -f Lexical_Analyzer lex.yy.c tokens.txt symbol_table.make'txt
