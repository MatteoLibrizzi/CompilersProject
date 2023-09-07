parser: lex.yy.c parser.tab.c setDate.c utils.c output.c customerListOperations.c namesListOperations.c transactionListOperations.c
	gcc $^ -o parser

parser.tab.c: parser.y
	bison -d $^

lex.yy.c: scanner.fl
	flex $^

clean:
	rm parser
	rm lex.yy.c
	rm parser.tab.*