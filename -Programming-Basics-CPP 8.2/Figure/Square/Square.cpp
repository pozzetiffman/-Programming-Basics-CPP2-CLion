//
// Created by admin on 1.11.2024.
//
#include <ostream>
#include "Square.h"
#include "../../checkingForErrors/checking_for_errors.h"

Square::Square(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
        : The_quadrilateral(side_a, side_b, side_c, side_d, corner_A, corner_B, corner_C, corner_D) {
    this->name = "Квадрат"; // Изменяем имя фигуры
    if (A+B+C+D != 360) {
        throw checking_for_errors ("стороны и углы произвольные, количество сторон равно 4, сумма углов должна быть равна 360");
    }
}

void Square::print_info() const {
    The_quadrilateral::print_info();
}

