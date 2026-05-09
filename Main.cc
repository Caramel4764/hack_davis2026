#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits>
#include <ctype.h>
#include <fstream>

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
  char should_overwrite;
  cout << "Would you like to save? ([Y]es [N]o):\n";
  while (
    !(cin >> should_save) || 
    (ToUpper(should_save) != 'Y' && ToUpper(should_save) != 'N') ||
    (should_overwrite && should_overwrite == false)
  ) {
    cout << "Enter Y or N\n";
  }
  while (ToUpper(should_save) == 'Y' && ToUpper(should_overwrite == 'N'))
    if (ToUpper(should_save) == 'Y') {
      std::string file_name;
      std::fstream file;
      cout << "Enter a filename:\n";
      cin >> file_name;
      // does file exist? Ask to overwrite
      if (FileUtil::DoesFileExist(file_name)) {
        cout << "" << file_name << " already exists. Do you want to overwrite? ([Y]es [N]o):\n";
        while (!(cin >> should_overwrite)) {
          cout << "Enter Y or N"\n;
        }
        if (ToUpper(should_overwrite) == 'Y') {
          //overwrite
          FileUtil::OpenFile(file_name);
        }
      }
      file<<"Content goes here\n";
      file.close();
      // save to file
    }
  return 0;
}