#ifndef TEST_H
#define TEST_H

#include <exception>

struct Test {
  size_t num_options;
  size_t num_correct;
  size_t num_questions;

  double CorrectChance(int guessed = 0, int correct = 0) {
    return double(num_correct - correct) / double(num_options - guessed);
  }

  double IncorrectChance(int guessed = 0, int correct = 0) {
    return 1 - (double(num_correct - correct) / double(num_options - guessed));
  }
};

#endif
