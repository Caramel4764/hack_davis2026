#include "FileUtil.h"
#include <string>

bool FileUtil::DoesFileExist(std::string filename) {
  std::fstream fs;
  fs.open(filename);
  if (fs.is_open()) {
    fs.close();
    return true;
  }
  return false;
}