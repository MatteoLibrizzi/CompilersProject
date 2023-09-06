
tokens: out
	./out < input.txt
out: lex.yy.c parser.tab.c symbolTable.c utils.c output.c customerListOperations.c namesListOperations.c transactionListOperations.c
	gcc -D DEBUG $^ -o out

parser.tab.c: parser.y
	bison -d $^

lex.yy.c: scanner.fl
	flex $^

clean:
	rm out
	rm lex.yy.c
	rm parser.tab.*