#include "infix_notation.h"
#include "catch.hpp"
#include <string>


Int EvalString(const std::string &s)
{
    std::istringstream iss(s);
    return InfixNotationExpr(iss);
}

TEST_CASE ("1 + 1")
{
    REQUIRE(EvalString("1 + 1") == 2);
}

TEST_CASE ("Substraction")
{
    REQUIRE(EvalString("8 - 3 - 5") == 0);
    REQUIRE(EvalString("9 - 11 - 3") == -5);
}

TEST_CASE("Mixed operations")
{
    REQUIRE(EvalString("8 * 2 - 6 * 1 + 10") == 20);
    REQUIRE(EvalString("8 / 4 + 2 * 4") == 10);
}

TEST_CASE("Unknow elements in the input")
{
    REQUIRE_THROWS_WITH(EvalString("wodj"), "Bad token in stream");
    REQUIRE_THROWS_WITH(EvalString("3 + 3 sda "), "Bad token in stream");
}

TEST_CASE ("Long expressions")
{
    REQUIRE(EvalString("1 + 1 + 1 + 1 + 1 + 1") == 6);
    REQUIRE(EvalString("2 * 10 + 17 + 15 / 3 + 10") == 52);
    REQUIRE(EvalString("10 / 2 + 2 * 2 * 2 - 1 ") == 12);
}

TEST_CASE("Two numbers in a row")
{
    REQUIRE_THROWS_WITH(EvalString("3 3 + 4 "), "Two numbers in row");
    REQUIRE_THROWS_WITH(EvalString("3 + 3 4 "), "Two numbers in row");
}

TEST_CASE("Two operations in a row")
{
    REQUIRE_THROWS_WITH(EvalString("+ + 4 "), "Two operations in row");
    REQUIRE_THROWS_WITH(EvalString(" 4 + 1 - - 10"), "Two operations in row");
    REQUIRE(EvalString("10 - 6") == 4);
}
