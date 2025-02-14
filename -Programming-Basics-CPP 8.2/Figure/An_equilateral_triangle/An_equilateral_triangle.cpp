//
// Created by admin on 1.11.2024.
//

#include <ostream>
#include "An_equilateral_triangle.h"
#include "../../checkingForErrors/checking_for_errors.h"

An_equilateral_triangle :: An_equilateral_triangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C)
        : Triangle(side_a, side_b, side_c, corner_A, corner_B, corner_C) {
    this->name = "Равносторонний треугольник"; // Изменяем имя фигуры
    if ((a != b || b != c) || (A != 60 || B != 60 || C != 60)) {
        throw checking_for_errors("(все стороны должны быть равны, все углы должны быть равны 60");
    }
}
void An_equilateral_triangle::print_info() const {
    Triangle::print_info();
}
