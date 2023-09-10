# Run with multiple input files:
# for FILE in resources/*; do printf "Input File: %s\n\n" $FILE; ./parser < $FILE; printf "\n----------\n"; done
parser: lex.yy.c parser.tab.c src/setDate.c src/utils.c src/output.c src/customer.c src/transactions.c
	gcc $^ -o parser

parser.tab.c: parser.y
	bison -d $^

lex.yy.c: scanner.fl
	flex $^

clean:
	rm parser
	rm lex.yy.c
	rm parser.tab.*