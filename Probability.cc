#include "Probability.h"
#include "Test.h"
#include <stdexcept>

// Private Methods

double Probability::ExactScoreProbability(size_t score, Test &test) {
  double total_prob = 0;
  size_t cur_score = 0;

  size_t index = 0;
  double cur_prob = 0;
  while (cur_score < score && index < test.num_questions) {
    cur_prob *= test.CorrectChance();

    (void)index;
    (void)total_prob;
  }

  return total_prob;
}

// Public Methods

Test Probability::CreateTest(size_t num_options, size_t num_correct, size_t num_questions) {
  if (!num_options)
    throw std::invalid_argument("Number of options must be non-zero");

  Test test;
  test.num_options = num_options;
  test.num_correct = num_correct;
  test.num_questions = num_questions;

  return test;
}

std::vector<double> Probability::CalculateTestResults(Test &test) {
  // double correct_chance = CorrectChance(num_options, num_correct);

  return std::vector<double>();
}

double Probability::CutoffProbability(int cutoff, std::vector<double> probabilities) {
  double total_probability = 0;

  for (int i = cutoff; i < int(probabilities.size()); i++) {
    total_probability += probabilities[i];
  }

  return total_probability;
}