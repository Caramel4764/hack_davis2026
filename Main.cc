#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits>
#include <ctype.h>
#include <fstream>
#include <iomanip>

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
/*std::string PrintCentered(std::string text, int spaces) {
  spaces-=text.length();
  int left_padding = spaces/2;
  int right_padding = spaces-left_padding;
  std::ostringstream oss;
  oss << std::left << std::setw(left_padding) << text << std::left << std::setw(right_padding);
  return oss.str();
}*/
std::string PrintCentered(int int_text, int spaces) {
  std::string text = std::to_string(int_text);
  spaces -= (text.length());
  int left_padding = spaces/2;
  int right_padding = spaces - left_padding;
  std::ostringstream oss;
  oss <<std::left << std::setw(left_padding) << "" << text << std::left << std::setw(right_padding) <<"";
  return oss.str();
}
int main(int argc, char* argv[]) {
  int num_options_per_questions;
  int num_questions;
  int num_correct_answers;
  int display_w = 35;
  int display_num = 3;

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

  // Calculate result

  char should_save;
  char should_overwrite = '\0';
  bool file_alr_exist = true;

  cout << " |———————————————————————————————————————|\n";
  cout << std::left << std::setw(display_w) << " | Options Per Question  " << "| " << PrintCentered(num_options_per_questions, display_num) << " |\n";
  cout << std::left << std::setw(display_w) << " | Total Questions  " << "| " << PrintCentered(155, display_num) << " |\n"; //num_questions
  cout << std::left << std::setw(display_w) << " | Correct Answer Per Questions  " << "| " << PrintCentered(10, display_num) << " |\n"; //num_correct_answers
  cout << " |———————————————————————————————————————|\n";
  cout << std::left << std::setw(display_w) << " | Probability  " << " |\n";
  cout << " |———————————————————————————————————————|\n";

  cout << "Would you like to save? ([Y]es [N]o):\n";
  while (
    !(cin >> should_save) || 
    (ToUpper(should_save) != 'Y' && ToUpper(should_save) != 'N')
  ) {
    cout << "Enter Y or N\n";
  }

  // Conditions
  // we want to save
  // we have duplicate save file and do not want to delete
  if (ToUpper(should_save) == 'Y') {
    //cout<<"File already exists: " << file_alr_exist << "\n!should_overwrite: "<<!should_overwrite << "\nToUpper(should_overwrite == 'Y')): " << (ToUpper(should_overwrite) == 'Y');
    while (file_alr_exist && (!should_overwrite || ToUpper(should_overwrite) == 'N')) {
      std::string file_name;
      std::fstream file;
      cout << "Enter a filename:\n";
      //cout << "file_alr_exist: "<<file_alr_exist;
      cin >> file_name;
      // does file exist? Ask to overwrite
      file_alr_exist = FileUtil::DoesFileExist(file_name);
      if (file_alr_exist) {
        cout << "" << file_name << " already exists. Do you want to overwrite? ([Y]es [N]o):\n";
        while (!(cin >> should_overwrite)) {
          cout << "Enter Y or N\n";
        }
        if (ToUpper(should_overwrite) == 'Y') {
          //overwrite
          FileUtil::OpenFile(file, file_name);
        }
      }
      FileUtil::OpenFile(file, file_name);
      file << "Content goes here\n";
      file.close();
    }
  }

  return 0;
}