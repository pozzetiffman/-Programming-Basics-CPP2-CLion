//
// Created by admin on 1.11.2024.
//
#include <iostream>
#include <ostream>
#include "Isosceles_triangle.h"
#include "../../checkingForErrors/checking_for_errors.h"

Isosceles_triangle:: Isosceles_triangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C)
        : Triangle(side_a, side_b, side_c, corner_A, corner_B, corner_C) {
    this->name = "Равнобедренный треугольник"; // Изменяем имя фигуры
    // Специфическая проверка для равнобедренного треугольника
    if (a != c || A != C) {
        throw checking_for_errors("стороны a и c равны, углы A и C равны");
    }
}
//Ошибка в равнобедренном треугольнике стороны a и c, а также углы A и C должны быть равны
void Isosceles_triangle::print_info() const {
    Triangle::print_info();
}

