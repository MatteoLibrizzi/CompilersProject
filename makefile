
tokens: out
	./out < input.txt
out: lex.yy.c parser.tab.c symbolTable.c utils.c
	gcc $^ -o out

parser.tab.c: parser.y
	bison -d $^

lex.yy.c: scanner.fl
	flex $^

clean:
	rm out
	rm lex.yy.c
	rm parser.tab.*