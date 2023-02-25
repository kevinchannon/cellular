﻿// cellular.cpp : Defines the entry point for the application.
//

#include "cellular.hpp"

#include <iostream>

constexpr auto iterations = size_t{ 20 };
constexpr auto size = size_t{ 21 };
constexpr auto rule = ca::Rule{ 30 };

int main()
{
	auto state = ca::make_initial_state(size);

	std::cout << state << std::endl;

	for (auto i = 0u; i < size; ++i) {
		state = ca::next(std::move(state), rule);
		std::cout << state << std::endl;
	}

	return 0;
}