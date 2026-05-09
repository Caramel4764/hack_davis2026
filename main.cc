#include <stdio.h>
#include "Probability.h"

int main(int argc, char* argv[]) {
  if (argc != 5) {
    // test name, options per question, correct, number of questions
    std::cout << "Useage: " << argv[0] << " <Options per Question> <Correct per Question> <Number of Questions> <Test Name>";
    return 1;
  }
  return 0;
}