//
// Created by admin on 30.01.2025.
//

#include "leave_lib.h"

#include <iostream>
#include <ostream>

Leaver::Leaver(std::string leave) : leave (leave) {
}
std::string Leaver::get_Leave() {
    return leave;
}
void Leaver::print_info() {
    std::cout << "До свидания, " << get_Leave() << std::endl;
}

