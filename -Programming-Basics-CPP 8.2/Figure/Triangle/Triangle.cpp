//
// Created by admin on 1.11.2024.
//


#include <iostream>
#include <ostream>
#include "Triangle.h"
#include "../../checkingForErrors/checking_for_errors.h"


Triangle::Triangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C)
    : Figure("Треугольник"), a(side_a), b(side_b), c(side_c), A(corner_A), B(corner_B), C(corner_C) {
    if ((A+B+C) != 180) {
        throw checking_for_errors ("стороны и углы произвольные, количество сторон равно 3, сумма углов должна быть равна 180");
    }
}
void Triangle::print_info() const  {
    std::cout << "Фигура создана без ошибок!\n";
    Figure::print_info();
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c
         << "\nУглы: A=" << A << " B=" << B << " C=" << C << "\n\n";


}
