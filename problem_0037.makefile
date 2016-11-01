pe0037 : problem_0037.o bignumber.o
	cc -std=c11 -o problem_0037 problem_0037.o bignumber.o

problem_0037.o : problem_0037.c bignumber.h bignumber.c
	cc -std=c11 -c problem_0037.c

bignumber.o : bignumber.h bignumber.c
	cc -std=c11 -c bignumber.c

.PHONY : clean
clean :
	-rm problem_0037.o bignumber.o

.PHONY : cleanall
cleanall :
	-rm problem_0037 problem_0037.o bignumber.o