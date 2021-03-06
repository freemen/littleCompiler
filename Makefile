objects = main.o lexical.o symbolTable.o errorHandle.o token.o grammar.o reduce.o

compiler: $(objects)
	cc -o compiler $(objects)

$(objects) : public.h symbolTable.h
lexical.o: lexical.h
grammar.o: grammar.h reduce.h
reduce.o: reduce.h grammar.h

.PHONY : clean
clean :
	-del compiler.exe $(objects)