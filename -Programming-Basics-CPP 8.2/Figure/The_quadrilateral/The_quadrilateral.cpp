//
// Created by admin on 1.11.2024.
//

#include <iostream>
#include <ostream>
#include "The_quadrilateral.h"
#include "../../checkingForErrors/checking_for_errors.h"



// Базовый класс для четырёхугольников
The_quadrilateral::The_quadrilateral (int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
       : Figure("Четырёхугольник"), a(side_a), b(side_b), c(side_c), d(side_d), A(corner_A), B(corner_B), C(corner_C), D(corner_D) {
    if ((A+B+C+D) != 360) {
        throw checking_for_errors ("стороны и углы произвольные, количество сторон равно 4, сумма углов должна быть равна 360");
    }
}
    // Переопределенный метод для вывода информации о четырёхугольнике
    void The_quadrilateral::print_info() const {
        std::cout << "Фигура создана без ошибок!\n";
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d
             << "\nУглы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
