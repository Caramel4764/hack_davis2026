run: Probability.out
	./Probability

Probability.out: Probability.h Probability.o
	g++ -Wall -Werror Probability.cc -o Probability.out

Probability.o: Probability.h Probability.cc
	g++ -Wall -Werror -c Probability.cc

clean:
	rm -f Probability.out
	rm -f *.o
