#define CATCH_CONFIG_MAIN
#include <string>

#include "../src/lib/myStringLib.hpp"
#include "catch.hpp"
#include "spdlog/spdlog.h"

TEST_CASE("myStringLib") {
  SECTION("getFileName") {
    spdlog::info("getFileName : test.m4a");
    REQUIRE(myStringLib::getFileName(std::string{"test.m4a"})
                .compare(std::string{"test"}) == 0);
  }

  SECTION("getExtension") {
    spdlog::info("getExtension : test.m4a");
    REQUIRE(myStringLib::getExtension(std::string{"test.m4a"})
                .compare(std::string{".m4a"}) == 0);
  }

  SECTION("substrHyphen") {
    spdlog::info("givenData : test-12345678901.m4a");
    std::string givenData{"test-12345678901.m4a"};
    spdlog::info("{}", myStringLib::substrHyphen(givenData));
    REQUIRE(myStringLib::substrHyphen(givenData).compare(std::string{"test"}) ==
            0);
  }

  SECTION("alreadyRenamed") {
    REQUIRE(
        !myStringLib::alreadyRenamed(std::string{"test-12345678901.m4a"}));
    REQUIRE(myStringLib::alreadyRenamed(std::string{"test.m4a"}));
  }
}
