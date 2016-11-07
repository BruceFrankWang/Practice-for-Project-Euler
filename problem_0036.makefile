pe0036 : problem_0036.o pelib.o
	cc -std=c11 -o problem_0036 problem_0036.o pelib.o

problem_0036.o : problem_0036.c pelib.h pelib.c
	cc -std=c11 -c problem_0036.c

pelib.o : pelib.h pelib.c
	cc -std=c11 -c pelib.c

.PHONY : clean
clean :
	-rm problem_0036.o pelib.o

.PHONY : cleanall
cleanall :
	-rm problem_0036 problem_0036.o pelib.o