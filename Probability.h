#ifndef PROBABILITY_H
#define PROBABILITY_H

#include "Test.h"
#include <vector>


class Probability {
 private:
  // DESCRIPTION
  double ExactScoreProbability(Test test);

 public:
  // DESCRIPTION
  Test CreateTest(size_t num_options, size_t num_correct, size_t num_questions);

  // DESCRIPTION
  vector<double> CalculateTestResults(Test test);

  // DESCRIPTION
  double CutoffProbability(int cutoff, vector<double> probabilities);
};

#endif
