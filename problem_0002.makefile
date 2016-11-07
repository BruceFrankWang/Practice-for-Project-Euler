problem_0002 : problem_0002.o pelib.o
	cc -std=c11 -o problem_0002 problem_0002.o pelib.o

problem_0002.o : problem_0002.c pelib.h pelib.c
	cc -std=c11 -c problem_0002.c

pelib.o : pelib.h pelib.c
	cc -std=c11 -c pelib.c

.PHONY : clean
clean :
	-rm problem_0002.o pelib.o

.PHONY : cleanall
cleanall :
	-rm problem_0002 problem_0002.o pelib.o