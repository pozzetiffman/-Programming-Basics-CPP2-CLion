//
// Created by admin on 1.11.2024.
//

#ifndef THE_QUADRILATERAL_H
#define THE_QUADRILATERAL_H


#include "../figure/Figure.h"



class The_quadrilateral : public Figure {
protected:
    // Поля для хранения длины сторон и углов прямоугольника
    int a{}, b{}, c{}, d{};
    int A{}, B{}, C{}, D{};

public:
    The_quadrilateral(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D);
    void print_info() const override;

};

#endif //THE_QUADRILATERAL_H
