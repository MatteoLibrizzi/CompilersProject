
tokens: out
	./out < input.txt
out: lex.yy.c
	gcc lex.yy.c -o out

lex.yy.c: scanner.fl
	flex $^

clean:
	rm out
	rm lex.yy.c