#include "myStringLib.hpp"

#include <dirent.h>

#include "spdlog/spdlog.h"

void myStringLib::myStringLib(void) { spdlog::info("myStringLib Init..."); }

bool myStringLib::sortOp(std::string i, std::string j) { return (i < j); }

bool myStringLib::sortOpReverse(std::string i, std::string j) {
  return (i > j);
}

std::vector<std::string> myStringLib::loadFiles(const char *path) {
  std::vector<std::string> vMovieFiles;

  DIR *dirFile = opendir(path);
  if (dirFile) {
    struct dirent *hFile;
    while ((hFile = readdir(dirFile)) != NULL) {
      if (!strcmp(hFile->d_name, ".")) continue;
      if (!strcmp(hFile->d_name, "..")) continue;

      if (hFile->d_name[0] == '.') continue;

      if (strstr(hFile->d_name, ".m4a") || strstr(hFile->d_name, ".mp4") ||
          strstr(hFile->d_name, ".avi")) {
        std::string str(hFile->d_name);
        vMovieFiles.push_back(str);
      }
    }
  }
  closedir(dirFile);

  return vMovieFiles;
}

std::string myStringLib::getExtension(std::string str) {
  unsigned found = str.find_last_of(".");
  return str.substr(found);
}

std::string myStringLib::getFileName(std::string str) {
  unsigned found = str.find_last_of(".");
  return str.substr(0, found);
}

bool myStringLib::alreadyRenamed(std::string str) {
  std::string testData = myStringLib::getFileName(str);
  if (testData.length() < 15) return true;
  if (testData.substr(testData.length() - 15 + 1, 1)
          .compare(std::string{"-"}) == 0) {
    return false;
  } else {
    return true;
  }
}

std::string myStringLib::substrHyphen(std::string str) {
  std::string testData = myStringLib::getFileName(str);
  if (testData.length() < 15)
    return testData;
  else
    return testData.substr(0, testData.length() - 14);
}

int myStringLib::renameFiles(std::string oldname, std::string newname) {
  int result = rename(oldname.c_str(), newname.c_str());

  if (result != 0) {
    perror("Error renaming file");
    return 1;
  } else
    return 0;
}
