#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits>
#include <ctype.h>

#include "Probability.h"
#include "FileUtil.h"

using std::cout;
using std::cin;
using std::toupper;

void ClearStream() {
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
char ToUpper(char letter) {
  return char(toupper(letter));
}
int main(int argc, char* argv[]) {
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

  char should_save;
  cout << "Would you like to save? ([Y]es [N]o):\n";
  while (!(cin >> should_save) || (ToUpper(should_save) != 'Y' && ToUpper(should_save) != 'N')) {
    cout << "Enter Y or N\n";
    //cout << "Test: "<<should_save<<": "<< ToUpper(should_save)<< "Equals: "<<(ToUpper(should_save)=='Y');
  }
  if (ToUpper(should_save) == 'Y') {
    std::string file_name;
    cout << "Enter a filename:\n";
    cin >> file_name;
    // does file exist? Ask to overwrite
    char should_overwrite;
    if (FileUtil::DoesFileExist(file_name)) {
      cout << "" << file_name << " already exists. Do you want to overwrite? ([Y]es [N]o):\n";
      while (!(cin >> should_overwrite)) {
        if (ToUpper(should_overwrite) == 'Y') {
          //overwrite
        }
      }
    }
    // save to file
  }
  return 0;
}