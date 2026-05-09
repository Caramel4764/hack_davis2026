#ifndef PROBABILITY_H
#define PROBABILITY_H
class Probability {
  private:
    /** Takes vector of tests
    *
    */
    double BasicTest();
  public:
    Probability();
    /** Calculates the cutoff based on vectore result
    */
    double CutoffProbability();
    /** Calculate likelyhood to guess at least X problems
    *
    */
    double BasicTest();
    /** 
    */
    double ComplexTest();
};

#endif