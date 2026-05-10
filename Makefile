COMPILER_FLAG = -Wall

run: TestProbability.out ProbabilityCalculator.out
	./TestProbability.out
	./ProbabilityCalculator.out

ProbabilityCalculator.out: Main.cc Probability.o FileUtil.o
	g++ ${COMPILER_FLAG} Main.cc Probability.o FileUtil.o -o ProbabilityCalculator.out

TestProbability.out: TestProbability.cc
	g++ -g ${COMPILER_FLAG} -o TestProbability.out TestProbability.cc -pthread -lgtest

Probability.o: Probability.h Probability.cc
	g++ ${COMPILER_FLAG} -c Probability.cc

FileUtil.o: FileUtil.h FileUtil.cc
	g++ ${COMPILER_FLAG} -c FileUtil.cc

clean:
	rm -f *.out
	rm -f *.o
