#include <iostream>
#include <string>
using namespace std;

// Базовый класс для всех фигур
class Figure {
protected:
    int sides_count;  // Количество сторон фигуры
    string name;      // Название фигуры

public:
    // Конструктор, который принимает количество сторон и имя фигуры
    Figure(int sides, string fid_name) : sides_count(sides), name(fid_name) {}

    // Метод для получения количества сторон фигуры
    int get_sides_cout() const {
        return sides_count;
    }

    // Метод для получения имени фигуры
    string get_name() const {
        return name;
    }
};

// Класс для треугольников, наследующий от Figure
class Triangle : public Figure {
public:
    // Конструктор, который вызывает базовый конструктор Figure с фиксированными параметрами
    Triangle() : Figure(3, "Треугольник") {}
};
// Класс для четырёхугольников, наследующий от Figure
class Quadrangle : public Figure {
public:
    // Конструктор, который вызывает базовый конструктор Figure с фиксированными параметрами
    Quadrangle() : Figure(4, "Четырёхугольник") {}
};

int main() {
    // Создание объекта класса Figure с 0 сторонами
    Figure myFigure(0, "Фигура");
    // Создание объекта класса Triangle (Треугольник)
    Triangle myTriangle;
    // Создание объекта класса Quadrangle (Четырёхугольник)
    Quadrangle myQuadrangle;

    // Вывод информации о количестве сторон каждой фигуры
    cout << "Количество сторон: \n";
    cout << myFigure.get_name() << ": " << myFigure.get_sides_cout() << " стороны\n";
    cout << myTriangle.get_name() << ": " << myTriangle.get_sides_cout() << " стороны\n";
    cout << myQuadrangle.get_name() << ": " << myQuadrangle.get_sides_cout() << " стороны\n";

    return 0;
}