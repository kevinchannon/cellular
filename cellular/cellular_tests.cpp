#include "cellular.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/generators/catch_generators_all.hpp>

#include <format>

TEST_CASE("next() executes rule") {
  SECTION("Rule 0 makes everything empty") {

    const auto a = GENERATE(ca::EMPTY, ca::FILLED);
    const auto b = GENERATE(ca::EMPTY, ca::FILLED);
    const auto c = GENERATE(ca::EMPTY, ca::FILLED);

    SECTION(std::string{ a, b, c }) {
      REQUIRE(ca::State{ ca::EMPTY, ca::EMPTY, ca::EMPTY } == ca::next({ a, b, c }, 0));
    }
  }

  SECTION("Cell has the value defined by the rule and its parents") {
    const auto [a, x] = GENERATE(table<ca::Cell, uint8_t>({
      {ca::EMPTY,  0b000},
      {ca::FILLED, 0b100}
      }));

    const auto [b, y] = GENERATE(table<ca::Cell, uint8_t>({
      {ca::EMPTY,  0b000},
      {ca::FILLED, 0b010}
      }));

    const auto [c, z] = GENERATE(table<ca::Cell, uint8_t>({
      {ca::EMPTY,  0b000},
      {ca::FILLED, 0b001}
      }));

    const auto rule = GENERATE(range(0, 256));

    SECTION(std::format("Rule: {}, parent {}{}{}", rule, a, b, c)) {
      const auto result = ca::next({ a, b, c }, ca::Rule(rule));
      const auto expected = (rule >> (x | y | z)) & 0x1 ? ca::FILLED : ca::EMPTY;

      REQUIRE(expected == result[1]);
    }
  }
}
