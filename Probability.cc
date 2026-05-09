#include "Probability.h"
#include "Test.h"

// Private Methods

double Probability::ExactScoreProbability(Test test) {
  // Code Here
}

// Public Methods

Test Probability::CreateTest(size_t num_options, size_t num_correct, size_t num_questions); {
  // Code Here
}

vector<double> Probability::CalculateTestResults(Test test) {
  // double correct_chance = CorrectChance(num_options, num_correct);

  // Code Here
}

double Probability::CutoffProbability(int cutoff, vector<double> probabilities) {
  double total_probability = 0;

  for (int i = cutoff; i < probabilities.size(); i++) {
    total_probability += probabilities[i];
  }

  return total_probability;
}