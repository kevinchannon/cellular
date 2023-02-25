#include "cellular.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

TEST_CASE("next() executes rule") {
  SECTION("Rule 0 makes everything empty") {

    const auto a = GENERATE(ca::EMPTY, ca::FILLED);
    const auto b = GENERATE(ca::EMPTY, ca::FILLED);
    const auto c = GENERATE(ca::EMPTY, ca::FILLED);

    const auto state = ca::State{ a, b, c };
    const auto result = ca::next(state, 0);

    SECTION(std::string{ a, b, c }) {
      REQUIRE(ca::State{ ca::EMPTY, ca::EMPTY, ca::EMPTY } == result);
    }
  }
}
