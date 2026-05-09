#ifndef PROBABILITY_H
#define PROBABILITY_H

#include "Test.h"
#include <vector>


class Probability {
 private:
  // DESCRIPTION
  double OneAnswerScoreProbability(size_t score, Test &test);

 public:
  // DESCRIPTION
  Test CreateTest(size_t num_options, size_t num_correct, size_t num_questions);

  // DESCRIPTION
  std::vector<double> CalculateTestResults(Test &test);

  // DESCRIPTION
  double CutoffProbability(int cutoff, std::vector<double> probabilities);
};

#endif
