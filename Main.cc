#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits>

#include "Probability.h"


using std::cout;
using std::cin;

void ClearStream() {
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
int main(int argc, char* argv[]) {
  /*if (argc != 5) {
    // test name, options per question, correct, number of questions
    std::cout << "Useage: " << argv[0] << " <Options per Question> <Correct per Question> <Number of Questions> <Test Name>";
    return 1;
  }*/
  int num_options_per_questions;
  int num_questions;
  int num_correct_answers;

  std::string test_name;

  cout << "Enter the number of options per question:\n";
  while (!(cin >> num_options_per_questions) || num_options_per_questions <= 0) {
    cout << "Invalid number of options. Must be a nonnegative whole number:\n";
    ClearStream();
  }

  cout << "Enter the number of correct answers:\n";
  while (!(cin >> num_correct_answers) || num_correct_answers <= 0 || num_correct_answers > num_options_per_questions) {
    cout << "Invalid number of correct answers. Must be a nonnegative whole number greater than number of options per question:\n";
    ClearStream();
  }

  cout << "Enter the number of questions:\n";
  while (!(cin >> num_questions) || num_questions <= 0) {
    cout << "Invalid number of questions. Must be a nonnegative whole number:\n";
    ClearStream();
  }


  /**
  do {
    cout << "Enter the test name\n";
    cin >> test_name;
  } while (num_correct_answers > 0);
 */
  char should_save = '';
  cout << "Would you like to save? ([Y]es [N]o):\n";
  while (!(cin >> should_save) || should_save != 'Y' || should_save != 'N' || should_save != 'y' || should_save != 'n') {
    cout << "Enter Y or N\n";
  }
  if (should_save == 'Y' || should_save == 'y') {
    std::string file_name;
    cout << "Enter a filename:\n";
    cin >> file_name;
    // does file exist? Ask to overwrite
    // save to file
    //
  }
  return 0;
}