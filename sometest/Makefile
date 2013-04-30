objects = testmain.o hello.o

testmain: $(objects)
	cc -o testmain testmain.o hello.o

testmain.o: hello.h
hello.o: hello.h

.PHONY : clean
clean :
	-del testmain.exe $(objects)