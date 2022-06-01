compiler: lex.yy.c parser.tab.o main.cc
		g++ -g -w -o compiler parser.tab.o lex.yy.c main.cc -std=c++14
parser.tab.o: parser.tab.cc
		g++ -g -w -c parser.tab.cc -std=c++14
parser.tab.cc: parser.yy
		bison parser.yy
lex.yy.c: lexer.flex parser.tab.cc
		flex lexer.flex
run:./compiler test_classes/D1.java
	./compiler test_classes/D1.java
tree: 
	dot -Tpdf tree.dot -otree.pdf
tac:
	dot -Tpdf tac.dot -o tac.pdf
clean:
		rm -f parser.tab.* lex.yy.c* compiler stack.hh tree.dot tree.pdf
		# rm -R compiler.dSYM						