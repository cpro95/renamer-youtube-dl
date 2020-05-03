#include <iostream>
#include <string>

// #include "CLI/CLI.hpp"
#include "lib/myStringLib.hpp"
#include "spdlog/spdlog.h"
#include "tabulate/table.hpp"

void make_table(tabulate::Table& table, std::vector<std::string>& vMovieFiles) {
  spdlog::info("Make Table...");
  for (auto val : vMovieFiles) {
    table.add_row({val});
  }
  // table[0][0].format().width(100);
  spdlog::info("Make Table...Done");
}

// void print_vector(std::vector<std::string>& vMovieFiles) {
//     spdlog::info("Make Table...");
//     for (auto val : vMovieFiles) {
//       std::cout << val << "\n";
//     }
// }
/*
 *
 *
 *
 main function
 *
 *
 *
 */
int main(int argc, char** argv) {
  // CLI::App app;

  // app.add_option("-d", db_filename, "DB File what you want to open")
  // ->required();
  // app.add_flag("-a", search_all, "Search All Data!");
  // CLI11_PARSE(app, argc, argv);

  spdlog::info("youtube-dl name fix it");
  // myStringLib::myStringLib();

  tabulate::Table table;
  std::vector<std::string> vMovieFiles;

  spdlog::info("Loading files...");
  vMovieFiles = myStringLib::loadFiles(".");
  if (vMovieFiles.size() == 0) {
    spdlog::info("Loading files...Failed : No Files");
    exit(1);
  }
  spdlog::info("Loading files...Done");

  spdlog::info("Sorting files...");
  sort(vMovieFiles.begin(), vMovieFiles.end(), myStringLib::sortOp);
  spdlog::info("Sorting files...Done");

  make_table(table, vMovieFiles);
  table.print(std::cout);
  std::cout << "\n";
  // print_vector(vMovieFiles);

  char c;
  std::cout << "Fix file names? (y/n) ";
  std::cin >> c;
  if (c == 'y' || c == 'Y') {
    spdlog::info("rename it");
    for (auto val : vMovieFiles) {
      // NOT alreadyRenamed!!!
      if (!myStringLib::alreadyRenamed(val)) {
        int ret =
            myStringLib::renameFiles(val, myStringLib::substrHyphen(val) +
                                              myStringLib::getExtension(val));
        if (ret == 0)
          spdlog::info("{} is renamed successful!", val);
        else
          spdlog::info("{} has error when renaming", val);
      }
    }
  } else {
    spdlog::info("not rename it");
    exit(1);
  }
}