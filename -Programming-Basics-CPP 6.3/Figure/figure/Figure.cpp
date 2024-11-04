//
// Created by admin on 1.11.2024.
//

#include "Figure.h"
#include <iostream>



Figure::Figure (std::string f_name) : name(f_name) {}

void  Figure::print_info () const{
    std::cout << name << ":" << std::endl;
}


