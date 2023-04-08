#define CONFIG_CATCH_MAIN

#include "catch_amalgamated.hpp"

#include "args.h"
#include "argsException.h"

TEST_CASE("Args Constructor Test", "[Args]") {
    SECTION("Valid Schema and Arguments") {
        std::string schema = "l,b*,i#";
        std::vector<std::string> args = { "-l", "-b", "true", "-i", "42" };

        Args myArgs(schema, args);

        REQUIRE(myArgs.has('l') == true);
        REQUIRE(myArgs.getBoolean('l') == true);
        REQUIRE(myArgs.has('b') == true);
        REQUIRE(myArgs.getString('b') == "true");
        REQUIRE(myArgs.has('i') == true);
        REQUIRE(myArgs.getInt('i') == 42);
    }

    //SECTION("Invalid Argument Schema") {
    //    std::string schema = "a,,c#"; // Invalid schema with empty argument name
    //    std::vector<std::string> args = { "-a", "-b", "value", "-c", "123" };

    //    REQUIRE_THROWS_AS(Args myArgs(schema, args), ArgsException);
    //}

    //SECTION("Invalid Argument Character") {
    //    std::string schema = "a,b*,c#";
    //    std::vector<std::string> args = { "-a", "-b", "value", "-c", "123" };
    //    args.push_back("-d"); // Invalid argument character

    //    REQUIRE_THROWS_AS(Args myArgs(schema, args), ArgsException);
    //}

    // Add more test cases as needed for other scenarios
}