cmake_minimum_required(VERSION 3.29)
project(_Programming_Basics_CPP_6_3)

set(CMAKE_CXX_STANDARD 20)

add_executable(_Programming_Basics_CPP_6_3 main.cpp
        Figure/A_right_angled_riangle/A_right_angled_riangle.cpp
        Figure/A_right_angled_riangle/A_right_angled_riangle.h
        Figure/An_equilateral_triangle/An_equilateral_triangle.cpp
        Figure/An_equilateral_triangle/An_equilateral_triangle.h
        Figure/figure/Figure.cpp
        Figure/figure/Figure.h
        Figure/Isosceles_triangle/Isosceles_triangle.cpp
        Figure/Isosceles_triangle/Isosceles_triangle.h
        Figure/Parallelogram/Parallelogram.cpp
        Figure/Parallelogram/Parallelogram.h
        Figure/Rectangle/Rectangle.cpp
        Figure/Rectangle/Rectangle.h
        Figure/Rhomb/Rhomb.cpp
        Figure/Rhomb/Rhomb.h
        Figure/Square/Square.cpp
        Figure/Square/Square.h
        Figure/The_quadrilateral/The_quadrilateral.cpp
        Figure/The_quadrilateral/The_quadrilateral.h
        Figure/Triangle/Triangle.cpp
        Figure/Triangle/Triangle.h)
include_directories(${PROJECT_SOURCE_DIR}/Figure)
