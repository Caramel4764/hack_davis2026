#ifndef PROBABILITY_H
#define PROBABILITY_H

#include "Test.h"
#include <vector>


class Probability {
 private:
  // Calculates the probability of getting a given score on a test with one correct answer per question
  static double OneAnswerScoreProbability(size_t score, TestInfo &test);

  // Unimplemented
  // Calculates the probability of getting a given score on a test with two correct answers per question
  static double TwoAnswerScoreProbability(size_t score, TestInfo &test);

 public:
  // Calculates the Binomial Coefficient n choose k
  static unsigned long long BinomialCoefficient(int n, int k);

  // Creates a TestInfo struct from the infor about a test
  static TestInfo CreateTest(size_t num_correct, size_t num_options, size_t num_questions);

  // Calculates the likelihood of getting all possible scores on a test and stores them in a vector
  static std::vector<double> CalculateTestResults(TestInfo &test);

  // Calculates the likelihood of getting at least a given score given the individual probability of each score
  static double CutoffProbability(int cutoff, std::vector<double> probabilities);
};

#endif
