run: ProbabilityCalculator.out
	./ProbabilityCalculator.out

ProbabilityCalculator.out: main.cc Probability.h Probability.o
	g++ -Wall -Werror main.cc Probability.cc -o ProbabilityCalculator.out

Probability.o: Probability.h Probability.cc
	g++ -Wall -Werror -c Probability.cc

clean:
	rm -f Probability.out
	rm -f *.o
