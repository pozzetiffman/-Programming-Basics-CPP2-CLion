//
// Created by admin on 1.11.2024.
//

#include "Isosceles_triangle.h"

Isosceles_triangle:: Isosceles_triangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C)
        : Triangle(side_a, side_b, side_c, corner_A, corner_B, corner_C) {
    this->name = "Равнобедренный треугольник"; // Изменяем имя фигуры
}

void Isosceles_triangle::print_info() const {
    Triangle::print_info();
}

