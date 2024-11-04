//
// Created by admin on 1.11.2024.
//

#ifndef AN_EQUILATERAL_TRIANGLE_H
#define AN_EQUILATERAL_TRIANGLE_H
#include "../Triangle/Triangle.h"



class An_equilateral_triangle : public Triangle {
    public:
    An_equilateral_triangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C);
    void print_info() const override;
};




#endif //AN_EQUILATERAL_TRIANGLE_H
