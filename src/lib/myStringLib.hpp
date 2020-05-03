#include <string>

namespace myStringLib {

// lib test function
void myStringLib(void);

bool sortOp(std::string i, std::string j);

bool sortOpReverse(std::string i, std::string j);

// loadFiles
// get files with name m4a, mp4, avi at the given current path
std::vector<std::string> loadFiles(const char *path);

// getFileName
// get the name of file without extension
std::string getFileName(std::string str);

// alreadyRenamed
// check if there is "-", return true or false
bool alreadyRenamed(std::string str);

// substrHyphen
// remove Hyphen return remains
std::string substrHyphen(std::string str);

// getExtension
// get the ext of file
std::string getExtension(std::string str);

// renameFiles
// wrapper of cpp version of c std rename library
int renameFiles(std::string oldname, std::string newname);

}  // namespace myStringLib