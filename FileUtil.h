#include <stdio.h>
#include <fstream.h>


#ifndef FILE_UTIL_H
#define FILE_UTIL_H

class FileUtil() {
  // checks if a file exists
  static bool DoesFileExist(std::string filename) {
    std::fstream fs;
    fs.open(filename);
    if (fs.is_open()) {
      fs.close();
      return false;
    }
    return true;
  }
}

#endif