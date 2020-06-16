#include <string>
#include <dirent.h>

#include "spdlog/spdlog.h"

namespace myStringLib
{

	// lib test function
	void myStringLib(void)
	{
		spdlog::info("myStringLib Init...");
	}

	bool sortOp(std::string i, std::string j)
	{
		return (i < j);
	}

	bool sortOpReverse(std::string i, std::string j)
	{
		return (i > j);
	}

	// loadFiles
	// get files with name m4a, mp4, avi at the given current path
	std::vector<std::string> loadFiles(const char *path)
	{
		std::vector<std::string> vMovieFiles;

		DIR *dirFile = opendir(path);
		if (dirFile)
		{
			struct dirent *hFile;
			while ((hFile = readdir(dirFile)) != NULL)
			{
				if (!strcmp(hFile->d_name, "."))
					continue;
				if (!strcmp(hFile->d_name, ".."))
					continue;

				if (hFile->d_name[0] == '.')
					continue;

				if (strstr(hFile->d_name, ".m4a") || strstr(hFile->d_name, ".mp4") ||
					strstr(hFile->d_name, ".avi"))
				{
					std::string str(hFile->d_name);
					vMovieFiles.push_back(str);
				}
			}
		}
		closedir(dirFile);

		return vMovieFiles;
	}

	// getFileName
	// get the name of file without extension
	std::string getFileName(std::string str)
	{
		unsigned found = str.find_last_of(".");
		return str.substr(0, found);
	}

	// alreadyRenamed
	// check if there is "-", return true or false
	bool alreadyRenamed(std::string str)
	{
		std::string testData = myStringLib::getFileName(str);
		if (testData.length() < 13)
			return true;
		if (testData.substr(testData.length() - 13 + 1, 1)
				.compare(std::string{"-"}) == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	// substrHyphen
	// remove Hyphen return remains
	std::string substrHyphen(std::string str)
	{
		std::string testData = myStringLib::getFileName(str);
		if (testData.length() < 13)
			return testData;
		else
			return testData.substr(0, testData.length() - 12);
	}

	// getExtension
	// get the ext of file
	std::string getExtension(std::string str)
	{
		unsigned found = str.find_last_of(".");
		return str.substr(found);
	}

	// renameFiles
	// wrapper of cpp version of c std rename library
	int renameFiles(std::string oldname, std::string newname)
	{
		int result = rename(oldname.c_str(), newname.c_str());

		if (result != 0)
		{
			perror("Error renaming file");
			return 1;
		}
		else
			return 0;
	}

} // namespace myStringLib