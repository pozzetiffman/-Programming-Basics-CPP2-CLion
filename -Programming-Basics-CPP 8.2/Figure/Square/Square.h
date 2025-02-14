//
// Created by admin on 1.11.2024.
//

#ifndef SQUARE_H
#define SQUARE_H


#include "../The_quadrilateral/The_quadrilateral.h"



class Square : public The_quadrilateral{
    public:
    Square(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D);
    void print_info() const override;
};



#endif //SQUARE_H
