#include <stdio.h>
#include <fstream>


#ifndef FILE_UTIL_H
#define FILE_UTIL_H

class FileUtil {
  // checks if a file exists
  private:
  public:
    static bool DoesFileExist(std::string filename);
};

#endif