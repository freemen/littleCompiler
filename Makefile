objects = main.o lexical.o symbolTable.o errorHandle.o token.o

compiler: $(objects)
	cc -o compiler $(objects)

$(objects) : public.h 
lexical.o: lexical.h
symbolTable.o: symbolTable.h

.PHONY : clean
clean :
	-del compiler.exe $(objects)