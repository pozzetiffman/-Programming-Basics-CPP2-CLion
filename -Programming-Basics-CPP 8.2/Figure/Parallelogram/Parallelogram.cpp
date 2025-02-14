//
// Created by admin on 1.11.2024.
//

#include "Parallelogram.h"
#include "../../checkingForErrors/checking_for_errors.h"

Parallelogram::Parallelogram(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
        : The_quadrilateral(side_a, side_b, side_c, side_d, corner_A, corner_B, corner_C, corner_D) {
    this->name = "Параллелограмм"; // Изменяем имя фигуры
    if ((a != c || b != d) || (A != C || B != D) || A+B+C+D != 360) {
        throw checking_for_errors ("стороны и углы произвольные, количество сторон равно 4, сумма углов должна быть равна 360");
    }
}

void Parallelogram::print_info() const {
    The_quadrilateral::print_info();
}

