//
// Created by admin on 1.11.2024.
//

#include <ostream>
#include "A_right_angled_riangle.h"
#include "../../checkingForErrors/checking_for_errors.h"

A_right_angled_riangle :: A_right_angled_riangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C)
        : Triangle(side_a, side_b, side_c, corner_A, corner_B, corner_C) {
    this->name = "Прямоугольный треугольник"; // Изменяем имя фигуры
    if (C != 90) {
        throw checking_for_errors("(угол C всегда равен 90)");
        }
    }
void A_right_angled_riangle::print_info() const {
    Triangle::print_info();
}
