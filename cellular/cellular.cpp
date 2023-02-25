#include "cellular.hpp"
#include "cellular.hpp"

namespace ca {

  namespace {
  }

  State make_initial_state(size_t size)
  {
    auto state = ca::State(size, ca::EMPTY);
    state[size / 2] = ca::FILLED;

    return state;
  }

  State next(State state, Rule rule) {
    auto out = State(state.size(), EMPTY);

    static const auto filled = [](auto&& c) { return c == FILLED; };

    for (auto i = 1u; i < out.size() - 1; ++i) {
      const auto rule_bit = (filled(state[i - 1]) ? 4 : 0) + (filled(state[i]) ? 2 : 0) + (filled(state[i + 1]) ? 1 : 0);
      out[i] = rule >> rule_bit & 0x1 ? FILLED : EMPTY;
    }

    return out;
  }

}
