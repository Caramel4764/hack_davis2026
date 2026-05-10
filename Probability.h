#ifndef PROBABILITY_H
#define PROBABILITY_H

#include "Test.h"
#include <vector>


class Probability {
 private:
  // DESCRIPTION
  static double OneAnswerScoreProbability(size_t score, TestInfo &test);

  // DESCRIPTION
  static double TwoAnswerScoreProbability(size_t score, TestInfo &test);

 public:
  // DESCRIPTION
  static unsigned long long BinomialCoefficient(int n, int k);

  // DESCRIPTION
  static TestInfo CreateTest(size_t num_correct, size_t num_options, size_t num_questions);

  // DESCRIPTION
  static std::vector<double> CalculateTestResults(TestInfo &test);

  // DESCRIPTION
  static double CutoffProbability(int cutoff, std::vector<double> probabilities);
};

#endif
