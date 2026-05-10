#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits>
#include <ctype.h>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "Probability.h"
#include "FileUtil.h"
#include "Test.h"

using std::cout;
using std::cin;
using std::toupper;
const int DISPLAY_W = 35;
const int DISPLAY_NUM = 3;

void ClearStream() {
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
char ToUpper(char letter) {
  return char(toupper(letter));
}
std::string PrintCentered(std::string text, int spaces) {
  spaces-=text.length();
  int left_padding = spaces/2;
  int right_padding = spaces-left_padding;
  std::ostringstream oss;
  oss << std::left << std::setw(left_padding) << text << std::left << std::setw(right_padding);
  return oss.str();
}
std::string PrintCentered(int int_text, int spaces) {
  std::string text = std::to_string(int_text);
  spaces -= (text.length());
  int left_padding = spaces/2;
  int right_padding = spaces - left_padding;
  std::ostringstream oss;
  oss <<std::left << std::setw(left_padding) << "" << text << std::left << std::setw(right_padding) <<"";
  return oss.str();
}
std::string PrintCentered(double int_text, int spaces) {
  std::string text = std::to_string(int_text);
  //cout << "text: "<<text<<"| int_text: "<<int_text;
  spaces -= (text.length());
  int left_padding = spaces/2;
  int right_padding = spaces - left_padding;
  std::ostringstream oss;
  oss <<std::left << std::setw(left_padding) << "" << text << std::left << std::setw(right_padding) <<"";
  return oss.str();
}
void PromptYN(char &answer) {
  while (
    !(cin >> answer) || 
    (ToUpper(answer) != 'Y' && ToUpper(answer) != 'N')
  ) {
    cout << "Enter Y or N\n";
    ClearStream();
  }
}
void PrintResult(int& num_options_per_questions, int& num_questions, int& num_correct_answers, int cutoff) {
  //Probability::BinomialCoefficient(num_questions, num_options_per_questions);
  //Probability Calculator;
  TestInfo TestObj = Probability::CreateTest(num_correct_answers, num_options_per_questions, num_questions);
  std::vector<double> res = Probability::CalculateTestResults(TestObj);
  double prob = Probability::CutoffProbability(cutoff, res);
  cout << " |———————————————————————————————————————|\n";
  cout << std::left << std::setw(DISPLAY_W) << " | Options Per Question  " << "| " << PrintCentered(num_options_per_questions, DISPLAY_NUM) << " |\n";
  cout << std::left << std::setw(DISPLAY_W) << " | Correct Answer Per Questions  " << "| " << PrintCentered(num_correct_answers, DISPLAY_NUM) << " |\n";
  cout << std::left << std::setw(DISPLAY_W) << " | Total Questions  " << "| " << PrintCentered(num_questions, DISPLAY_NUM) << " |\n";

  cout << std::left << std::setw(DISPLAY_W) << " | Cutoff  " << "| " << PrintCentered(cutoff, DISPLAY_NUM) << " |\n";
  cout << " |———————————————————————————————————————|\n";
  cout << std::left << std::setw(DISPLAY_W-3) << " | Probability" << PrintCentered(prob, DISPLAY_NUM) << " |\n";
  cout << " |———————————————————————————————————————|\n";
}
void PromptChar(char &ans, std::vector<char> valid_inputs) {
  int start_size = valid_inputs.size();
  for (int i = 0; i < start_size; i++) {
    char curr = valid_inputs.at(i);
    if (std::isupper(curr)) {
      valid_inputs.push_back(std::tolower(curr));
    } else {
      valid_inputs.push_back(std::toupper(curr));
    }
  }
  while (!(cin>>ans) || std::find(std::begin(valid_inputs), std::end(valid_inputs), ans) == std::end(valid_inputs)) {
    cout << "Invalid Input:\n";
    ClearStream();
  }
}
bool CompareCaseInsensitively(int a, int b) {
  if (std::toupper(a) == std::toupper(b))
    return true;
  return false;
}
int main(int argc, char* argv[]) {
  int num_options_per_questions;
  int num_questions;
  int num_correct_answers;
  int cutoff;
  char mode = '\0';
  std::string file_name;
  std::fstream file;
  std::string test_name;
  cout << "Would you like to [C]alculate or [R]ead a file?: \n";
  PromptChar(mode, {'C', 'R'});
  if (CompareCaseInsensitively(mode, 'c')) {
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

    cout << "Enter the cutoff (At least how many correct)\n";
    while (!(cin >> cutoff) || cutoff <= 0) {
      cout << "Invalid cutoff. Must be a nonnegative whole number:\n";
      ClearStream();
    }
    // Calculate result
    PrintResult(num_options_per_questions, num_questions, num_correct_answers, cutoff);

    char should_save;
    char should_overwrite = '\0';
    bool file_alr_exist = true;

    cout << "Would you like to save? ([Y]es [N]o):\n";
    PromptYN(should_save);

    // Conditions
    // we want to save
    // we have duplicate save file and do not want to delete
    if (CompareCaseInsensitively(should_save, 'y')) {
      while (file_alr_exist && (!should_overwrite || ToUpper(should_overwrite) == 'N')) {
        cout << "Enter a filename:\n";
        cin >> file_name;
        // does file exist? Ask to overwrite
        file_alr_exist = FileUtil::DoesFileExist(file_name);
        if (file_alr_exist) {
          cout << "" << file_name << " already exists. Do you want to overwrite? ([Y]es [N]o):\n";
          PromptYN(should_overwrite);
        }
        if ((CompareCaseInsensitively(should_save, 'y') && CompareCaseInsensitively(should_overwrite, 'y')) || (!file_alr_exist && should_save)) {
          FileUtil::ForceOpenFile(file, file_name);
          file << num_options_per_questions <<"\n";
          file << num_questions << "\n";
          file << num_correct_answers << "\n";
          file << cutoff << "\n";
          file.close();
        }

      }
    }
  } else if (CompareCaseInsensitively(mode, 'r')) {
    //ask filename
    cout << "Enter a filename:\n";
    cin >> file_name;

    if (!FileUtil::DoesFileExist(file_name)) {
      std::cerr << "This file does not exist.";
      return 1;
    } else {
      FileUtil::ReadFile(file, file_name);
      std::string str_num_options_per_questions;
      std::string str_num_questions;
      std::string str_num_correct_answers;
      std::string str_cutoff;
      std::getline(file, str_num_options_per_questions, '\n');
      std::getline(file, str_num_questions, '\n');
      std::getline(file, str_num_correct_answers, '\n');
      std::getline(file, str_cutoff, '\n');
      //cout<<"str_num_options_per_questions: " << str_num_options_per_questions<<"\n";
      //cout<<"str_num_questions: " << str_num_questions<<"\n";
      //cout<<"str_num_correct_answers: " << str_num_correct_answers<<"\n";
      try {
        num_options_per_questions = std::stoi(str_num_options_per_questions);
        num_questions = std::stoi(str_num_questions);
        num_correct_answers = std::stoi(str_num_correct_answers);
        str_cutoff = std::stoi(str_cutoff);
      } catch (...) {
        std::cerr << "Unreadable file.";
        return 1;
      }
      PrintResult(num_options_per_questions, num_questions, num_correct_answers, cutoff);
    }
  }

  return 0;
}