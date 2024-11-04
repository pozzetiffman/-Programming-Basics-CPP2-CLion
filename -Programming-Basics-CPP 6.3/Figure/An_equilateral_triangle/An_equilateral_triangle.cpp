//
// Created by admin on 1.11.2024.
//

#include "An_equilateral_triangle.h"

An_equilateral_triangle :: An_equilateral_triangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C)
        : Triangle(side_a, side_b, side_c, corner_A, corner_B, corner_C) {
    this->name = "Равносторонний треугольник"; // Изменяем имя фигуры
}
void An_equilateral_triangle::print_info() const {
    Triangle::print_info();
}
