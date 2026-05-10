COMPILER_FLAG = -Wall -Werror

run: ProbabilityCalculator.out
	./ProbabilityCalculator.out 3 2 1 Y

ProbabilityCalculator.out: Main.cc Probability.o FileUtil.o
	g++ ${COMPILER_FLAG} Main.cc Probability.o FileUtil.o -o ProbabilityCalculator.out

Probability.o: Probability.h Probability.cc
	g++ ${COMPILER_FLAG} -c Probability.cc

FileUtil.o: FileUtil.h FileUtil.cc
	g++ ${COMPILER_FLAG} -c FileUtil.cc

clean:
	rm -f Probability.out
	rm -f *.o