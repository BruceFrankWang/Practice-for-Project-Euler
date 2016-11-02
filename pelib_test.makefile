pelib_test : pelib_test.o pelib.o
	cc -g -std=c11 -o pelib_test pelib_test.o pelib.o

pelib_test.o : pelib_test.c pelib.h pelib.c
	cc -g -std=c11 -c pelib_test.c

pelib.o : pelib.h pelib.c
	cc -g -std=c11 -c pelib.c

.PHONY : clean
clean :
	-rm pelib_test.o pelib.o

.PHONY : cleanall
cleanall :
	-rm pelib pelib_test.o pelib.o