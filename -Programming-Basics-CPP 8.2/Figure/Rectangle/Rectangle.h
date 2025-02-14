//
// Created by admin on 1.11.2024.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../The_quadrilateral/The_quadrilateral.h"



class Rectangle : public The_quadrilateral{
    public:
    Rectangle(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D);
    void print_info() const override;
};



#endif //RECTANGLE_H
