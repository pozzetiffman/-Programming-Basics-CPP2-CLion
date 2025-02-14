//
// Created by admin on 1.11.2024.
//

#include "Rhomb.h"
#include "../../checkingForErrors/checking_for_errors.h"

Rhomb::Rhomb(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
        : The_quadrilateral(side_a, side_b, side_c, side_d, corner_A, corner_B, corner_C, corner_D) {
    this->name = "Ромб"; // Изменяем имя фигуры
    if ((a != b || a != c || a != d) || (A != C && B != D)) {
        throw checking_for_errors ("все стороны равны, углы A,C и B,D попарно равны");
    }
}
void Rhomb::print_info() const {
    The_quadrilateral::print_info();
}


