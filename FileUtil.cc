#include <string>
#include <fstream>
#include <iostream>
#include "FileUtil.h"

bool FileUtil::DoesFileExist(std::string filename) {
  std::fstream fs;
  fs.open(filename);
  if (fs.is_open()) {
    fs.close();
    return true;
  }
  return false;
}

bool FileUtil::OpenFile(std::fstream& file, std::string filename) {
  file.open(filename);
  if (!file) {
    std::cerr << "Error: cannot open "<<filename;
    return false;
  }
  return true;
}
