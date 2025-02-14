//
// Created by admin on 30.01.2025.
//

#include "greeting_library.h"

#include <iostream>

Greeter::Greeter(std::string greet) : greet (greet) {}

std::string Greeter::get_greet() const {
    return greet;
}

void Greeter::print_info() const {
    std::cout << "Здравствуйте, " << greet;
}

