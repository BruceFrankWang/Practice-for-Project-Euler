bnt : bignumber_test.o bignumber.o
	cc -g -std=c11 -o bnt bignumber_test.o bignumber.o

bignumber_test.o : bignumber_test.c bignumber.h bignumber.c
	cc -g -std=c11 -c bignumber_test.c

bignumber.o : bignumber.h bignumber.c
	cc -g -std=c11 -c bignumber.c

.PHONY : clean
clean :
	-rm bignumber_test.o bignumber.o

.PHONY : cleanall
cleanall :
	-rm bnt bignumber_test.o bignumber.o