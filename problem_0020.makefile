pe0020 : problem_0020.o bignumber.o
	cc -std=c11 -o problem_0020 problem_0020.o bignumber.o

problem_0020.o : problem_0020.c bignumber.h bignumber.c
	cc -std=c11 -c problem_0020.c

bignumber.o : bignumber.h bignumber.c
	cc -std=c11 -c bignumber.c

.PHONY : clean
clean :
	-rm problem_0020.o bignumber.o

.PHONY : cleanall
cleanall :
	-rm problem_0020 problem_0020.o bignumber.o