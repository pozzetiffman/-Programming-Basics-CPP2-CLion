#include <iostream>

#include "Figure/figure/Figure.h"
#include "Figure/Triangle/Triangle.h"
#include "Figure/The_quadrilateral/The_quadrilateral.h"
#include "Figure/A_right_angled_riangle/A_right_angled_riangle.h"
#include "Figure/Isosceles_triangle/Isosceles_triangle.h"
#include "Figure/An_equilateral_triangle/An_equilateral_triangle.h"
#include "Figure/Rectangle/Rectangle.h"
#include "Figure/Square/Square.h"
#include "Figure/Parallelogram/Parallelogram.h"
#include "Figure/Rhomb/Rhomb.h"


int main() {

   Figure* figure[] = {
      new The_quadrilateral(10,20,30,40,50,60,70,80),
      new Triangle {10, 20, 30, 50, 60, 70},

      new A_right_angled_riangle {10, 20, 30, 50, 60, 90},
      new Isosceles_triangle {10, 20, 10, 50, 60, 50},
      new An_equilateral_triangle {30, 30, 30, 60, 60, 60},

      new Rectangle {10, 20, 10, 20, 90, 90, 90, 90},
      new Square {20, 20, 20, 20, 90, 90, 90, 90},
      new Parallelogram {20, 30, 20, 30, 30, 40, 30, 40},
      new Rhomb {30, 30, 30, 30, 30, 40, 30, 40}

   };

   for (int i = 0; i < sizeof(figure) / sizeof(figure[0]); i++) {
      figure[i]->print_info();
   }

   delete *figure;


}
