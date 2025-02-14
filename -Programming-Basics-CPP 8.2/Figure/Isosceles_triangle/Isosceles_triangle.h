//
// Created by admin on 1.11.2024.
//

#ifndef ISOSCELES_TRIANGLE_H
#define ISOSCELES_TRIANGLE_H
#include "../Triangle/Triangle.h"



class Isosceles_triangle:public Triangle{
public:
   Isosceles_triangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C);
   void print_info() const override;
};



#endif //ISOSCELES_TRIANGLE_H
