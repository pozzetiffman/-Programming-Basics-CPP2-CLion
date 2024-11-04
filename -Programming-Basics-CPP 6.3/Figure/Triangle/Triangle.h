//
// Created by admin on 1.11.2024.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "../figure/Figure.h"

class Triangle : public  Figure {
private:
    // Поля для хранения длины сторон и углов треугольника
    int a{}, b{}, c{};
    int A{}, B{}, C{};
public:
    Triangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C);
    void print_info() const override;
};

#endif //TRIANGLE_H
