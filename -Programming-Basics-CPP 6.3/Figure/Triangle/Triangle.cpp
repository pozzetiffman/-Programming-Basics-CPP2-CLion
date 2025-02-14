//
// Created by admin on 1.11.2024.
//

#include "Triangle.h"
#include <iostream>



Triangle::Triangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C)
    : Figure("Треугольник"), a(side_a), b(side_b), c(side_c), A(corner_A), B(corner_B), C(corner_C) {
}

void Triangle::print_info() const  {

    Figure::print_info();
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c
         << "\nУглы: A=" << A << " B=" << B << " C=" << C << "\n\n";


}
