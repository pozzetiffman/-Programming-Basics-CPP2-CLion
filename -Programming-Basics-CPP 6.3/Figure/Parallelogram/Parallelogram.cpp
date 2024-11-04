//
// Created by admin on 1.11.2024.
//

#include "Parallelogram.h"

Parallelogram::Parallelogram(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
        : The_quadrilateral(side_a, side_b, side_c, side_d, corner_A, corner_B, corner_C, corner_D) {
    this->name = "Параллелограмм"; // Изменяем имя фигуры
}

void Parallelogram::print_info() const {
    The_quadrilateral::print_info();
}

