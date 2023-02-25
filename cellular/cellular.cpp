#include "cellular.hpp"
#include "cellular.hpp"

namespace ca {

  namespace {
    [[nodiscard]] auto filled(Cell c) noexcept { return c == FILLED; }
  }

  State make_initial_state(size_t size)
  {
    auto state = ca::State(size, ca::EMPTY);
    state[size / 2] = ca::FILLED;

    return state;
  }

  State next(State state, Rule rule) {
    static auto parent_state = State{};
    parent_state = state;

    const auto rule_bit_0 = (filled(parent_state[0]) ? 2 : 0) + (filled(parent_state[1]) ? 1 : 0);
    state[0] = ((rule >> rule_bit_0) & 0x1) ? FILLED : EMPTY;

    for (auto i = 1u; i < state.size() - 1; ++i) {
      const auto rule_bit = (filled(parent_state[i - 1]) ? 4 : 0) + (filled(parent_state[i]) ? 2 : 0) + (filled(parent_state[i + 1]) ? 1 : 0);
      state[i] = ((rule >> rule_bit) & 0x1) ? FILLED : EMPTY;
    }

    const auto rule_bit_n = (filled(parent_state[parent_state.size() - 2]) ? 4 : 0) + (filled(parent_state[parent_state.size() - 1]) ? 2 : 0);
    state[state.size() - 1] = ((rule >> rule_bit_n) & 0x1) ? FILLED : EMPTY;

    return state;
  }

}
