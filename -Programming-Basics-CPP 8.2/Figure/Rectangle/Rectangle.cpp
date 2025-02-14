//
// Created by admin on 1.11.2024.
//

#include "Rectangle.h"
#include "../../checkingForErrors/checking_for_errors.h"

Rectangle::Rectangle(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
: The_quadrilateral(side_a, side_b, side_c, side_d, corner_A, corner_B, corner_C, corner_D) {
    this->name = "Прямоугольник"; // Изменяем имя фигуры
    if ((a != c || b != d) || A+B+C+D != 360){
        throw checking_for_errors ("стороны a,c и b,d попарно равны, все углы равны 90");
    }
}
void Rectangle::print_info() const {
    The_quadrilateral::print_info();
}


