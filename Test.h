#ifndef TEST_H
#define TEST_H

#include <exception>

struct Test {
  size_t num_options;
  size_t num_correct;
  size_t num_questions;

  double CorrectChance() {
    return num_options ? double(correct_options) / double(num_options) : -1;
  }
}

#endif
