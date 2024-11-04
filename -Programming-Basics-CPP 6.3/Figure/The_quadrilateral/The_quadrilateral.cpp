//
// Created by admin on 1.11.2024.
//

#include "The_quadrilateral.h"
#include <iostream>

// Базовый класс для четырёхугольников
The_quadrilateral::The_quadrilateral (int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
       : Figure("Четырёхугольник"), a(side_a), b(side_b), c(side_c), d(side_d), A(corner_A), B(corner_B), C(corner_C), D(corner_D) {}



    // Переопределенный метод для вывода информации о четырёхугольнике
    void The_quadrilateral::print_info() const {
        Figure::print_info() ;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d
             << "\nУглы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
