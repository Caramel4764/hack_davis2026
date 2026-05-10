#include "Probability.h"
#include "Test.h"
#include <stdexcept>

// Private Methods

double Probability::OneAnswerScoreProbability(size_t score, TestInfo &test) {
  // Impossible to get higher score than # of questions
  if (score > test.num_questions)
    return 0;

  double probability = 1;

  // Probability of getting {score} correct
  for (size_t i = 0; i < score; i++) {
    probability *= test.CorrectChance();
  }
  // Probability of getting {# of questions - score} incorrect
  for (size_t i = score; i < test.num_questions; i++) {
    probability *= test.IncorrectChance();
  }

  probability *= BinomialCoefficient(test.num_questions, score);

  return probability;
}

// Unimplemented, ran out of time :(
double Probability::TwoAnswerScoreProbability(size_t score, TestInfo &test) {
  if (score > test.num_questions * 2)
    return 0;

  double total_prob = 1;
  double cur_prob = 1;
  (void)cur_prob;

  // TODO: Code Here

  return total_prob;
}

// Public Methods

unsigned long long Probability::BinomialCoefficient(int n, int k) {
  double coefficient = 1;

  // Minimize number of iterations
  int iter = (n - k < k) ? n - k : k;

  for (int i = 0; i < iter; i++) {
    coefficient *= double(n - i) / double(i + 1);
  }

  return (unsigned long long)coefficient;
}

TestInfo Probability::CreateTest(size_t num_correct, size_t num_options, size_t num_questions) {
  if (!num_options)
    throw std::invalid_argument("Number of options must be non-zero");

  TestInfo test;
  test.num_correct = num_correct;
  test.num_options = num_options;
  test.num_questions = num_questions;

  return test;
}

std::vector<double> Probability::CalculateTestResults(TestInfo &test) {
  std::vector<double> probabilities;

  // Test with one correct answer per question
  if (test.num_correct == 1) {
    for (size_t i = 0; i <= test.num_questions; i++) {
      probabilities.push_back(OneAnswerScoreProbability(i, test));
    }
  }
  // Test with two correct answers per question
  else if (test.num_correct == 2) {
    for (size_t i = 0; i <= test.num_questions; i++) {
      probabilities.push_back(OneAnswerScoreProbability(i, test));
    }
  }

  return probabilities;
}

double Probability::CutoffProbability(int cutoff, std::vector<double> probabilities) {
  double total_probability = 0;

  for (int i = cutoff; i < int(probabilities.size()); i++) {
    total_probability += probabilities[i];
  }

  return total_probability;
}
