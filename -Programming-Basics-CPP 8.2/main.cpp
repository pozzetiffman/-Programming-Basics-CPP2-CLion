#include <iostream>
#include <stdexcept>
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
#include "checkingForErrors/checking_for_errors.h"  // Подключаем собственный класс исключения

int main() {
    const int size = 9;  // Количество фигур в массиве
    Figure* figures[size] = {};  // Инициализация массива указателей

        try {
            figures[0] = new The_quadrilateral(10, 20, 30, 40, 90, 90, 90, 90);
        } catch (const checking_for_errors& e) {
            std::cerr << "Ошибка создания четырехугольника: " << e.what() << std::endl;
        }

        try {
             figures[1] = new Triangle(10, 20, 30, 50, 60, 70);
        } catch (const checking_for_errors& e) {
             std::cerr <<"Ошибка создания Треугольника: "<< e.what() << std::endl;
        }

        try {
            figures[2] = new A_right_angled_riangle(3, 4, 5, 30, 60, 100);  // Здесь может возникнуть исключение! чтобы убрать исключение corner_C = 90
        } catch (const checking_for_errors& e) {
            std::cerr << "Ошибка создания Прямоуголього треугольника: " << e.what() << std::endl;
        }

        try {
            figures[3] = new Isosceles_triangle(10, 20, 10, 50, 80, 50);
        } catch (const checking_for_errors& e) {
            std::cerr << "Ошибка создания Равнобедренного треугольника:" << e.what() << std::endl;
        }

        try {
            figures[4] = new An_equilateral_triangle(60, 60, 60, 60, 60, 60);
        } catch (const checking_for_errors& e) {
            std::cerr << "Ошибка создания Равностороннего треугольника: " << e.what() << std::endl;
        }

        try {
            figures[5] = new Rectangle(10, 20, 10, 20, 90, 90, 90, 90);
        } catch (const checking_for_errors& e) {
            std::cerr << "Ошибка создания Прямоугольника: " << e.what() << std::endl;
        }

        try {
            figures[6] = new Square(90, 90, 90, 90, 90, 90, 90, 90);
        } catch (const checking_for_errors& e) {
            std::cerr << "Ошибка создания Квадрата: " << e.what() << std::endl;
        }

        try {
            figures[7] = new Parallelogram(20, 30, 20, 30, 60, 120, 60, 150);// Здесь может возникнуть исключение! чтобы убрать исключение corner_C = 120
        } catch (const checking_for_errors& e) {
            std::cerr << "Ошибка создания Параллелограмма: " << e.what() << std::endl;
        }

        try {
            figures[8] = new Rhomb(30, 30, 30, 30, 90, 90, 90, 90);
        } catch (const checking_for_errors& e) {
            std::cerr << "Ошибка создания Ромба: " << e.what() << std::endl;
        }



        // Вывод информации о каждой фигуре
        for (int i = 0; i < size; ++i) {
            if (figures[i]) {
                figures[i]->print_info();
            }
        }

    // Освобождение памяти для всех созданных объектов
    for (int i = 0; i < size; ++i) {
        delete figures[i];
    }

    return 0;
}