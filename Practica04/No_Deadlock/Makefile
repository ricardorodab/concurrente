default: chino

chino: filosofos.c chino.o
	gcc -g -o filosofos.out filosofos.c chino.o

chino.o: chino.c chino.h
	gcc -c chino.c chino.h 

clean:
	rm -f *.o
	rm -f *.out
	rm -f *.h.gch
	rm -rf *.dSYM
	rm *~
