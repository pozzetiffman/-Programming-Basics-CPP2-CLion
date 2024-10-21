#include <iostream>
#include <string>
using namespace std;

// Базовый класс для фигур
class Figure {
protected:
    string name; // Имя фигуры
public:
    // Конструктор, который инициализирует имя фигуры
    Figure(string f_name) : name(f_name) {}

    // Виртуальный метод для вывода информации о фигуре (может быть переопределен в дочерних классах)
    virtual void print_info() const {
        cout << name << ":" << endl;
    }
};

// Базовый класс для треугольников
class Triangle : public Figure {
protected:
    // Поля для хранения длины сторон и углов треугольника
    int a{}, b{}, c{};
    int A{}, B{}, C{};
public:
    // Конструктор, который инициализирует стороны и углы треугольника, а также имя
    Triangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C)
        : Figure("Треугольник"), a(side_a), b(side_b), c(side_c), A(corner_A), B(corner_B), C(corner_C) {}

    // Переопределенный метод для вывода информации о треугольнике
    void print_info() const override {
        Figure::print_info();
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c
             << "\nУглы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

// Базовый класс для четырёхугольников
class The_quadrilateral : public Figure {
protected:
    // Поля для хранения длины сторон и углов четырёхугольника
    int a{}, b{}, c{}, d{};
    int A{}, B{}, C{}, D{};
public:
    // Конструктор, который инициализирует стороны и углы четырёхугольника, а также имя
    The_quadrilateral(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
        : Figure("Четырёхугольник"), a(side_a), b(side_b), c(side_c), d(side_d), A(corner_A), B(corner_B), C(corner_C), D(corner_D) {}

    // Переопределенный метод для вывода информации о четырёхугольнике
    void print_info() const override {
        Figure::print_info();
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d
             << "\nУглы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};

// Прямоугольный треугольник (наследник от Triangle)
class A_right_angled_riangle : public Triangle {
public:
    // Конструктор, который инициализирует стороны и углы прямоугольного треугольника
    A_right_angled_riangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C)
        : Triangle(side_a, side_b, side_c, corner_A, corner_B, corner_C) {
        this->name = "Прямоугольный треугольник"; // Изменяем имя фигуры
    }

    // Переопределение метода вывода
    void print_info() const override {
        Triangle::print_info(); // Вызов родительского метода
    }
};

// Равнобедренный треугольник (наследник от Triangle)
class Isosceles_triangle : public Triangle {
public:
    // Конструктор, который инициализирует стороны и углы равнобедренного треугольника
    Isosceles_triangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C)
        : Triangle(side_a, side_b, side_c, corner_A, corner_B, corner_C) {
        this->name = "Равнобедренный треугольник"; // Изменяем имя фигуры
    }

    // Переопределение метода вывода
    void print_info() const override {
        Triangle::print_info(); // Вызов родительского метода
    }
};

// Равносторонний треугольник (наследник от Triangle)
class An_equilateral_triangle : public Triangle {
public:
    // Конструктор, который инициализирует стороны и углы равностороннего треугольника
    An_equilateral_triangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C)
        : Triangle(side_a, side_b, side_c, corner_A, corner_B, corner_C) {
        this->name = "Равносторонний треугольник"; // Изменяем имя фигуры
    }

    // Переопределение метода вывода
    void print_info() const override {
        Triangle::print_info(); // Вызов родительского метода
    }
};

// Прямоугольник (наследник от The_quadrilateral)
class Rectangle : public The_quadrilateral {
public:
    // Конструктор, который инициализирует стороны и углы прямоугольника
    Rectangle(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
        : The_quadrilateral(side_a, side_b, side_c, side_d, corner_A, corner_B, corner_C, corner_D) {
        this->name = "Прямоугольник"; // Изменяем имя фигуры
    }

    // Переопределение метода вывода
    void print_info() const override {
        Figure::print_info();
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d
             << "\nУглы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};

// Квадрат (наследник от The_quadrilateral)
class Square : public The_quadrilateral {
public:
    // Конструктор, который инициализирует стороны и углы квадрата
    Square(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
        : The_quadrilateral(side_a, side_b, side_c, side_d, corner_A, corner_B, corner_C, corner_D) {
        this->name = "Квадрат"; // Изменяем имя фигуры
    }

    // Переопределение метода вывода
    void print_info() const override {
        Figure::print_info();
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d
             << "\nУглы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};

// Параллелограмм (наследник от The_quadrilateral)
class Parallelogram : public The_quadrilateral {
public:
    // Конструктор, который инициализирует стороны и углы параллелограмма
    Parallelogram(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
        : The_quadrilateral(side_a, side_b, side_c, side_d, corner_A, corner_B, corner_C, corner_D) {
        this->name = "Параллелограмм"; // Изменяем имя фигуры
    }

    // Переопределение метода вывода
    void print_info() const override {
        Figure::print_info();
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d
             << "\nУглы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};

// Ромб (наследник от The_quadrilateral)
class Rhomb : public The_quadrilateral {
public:
    // Конструктор, который инициализирует стороны и углы ромба
    Rhomb(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
        : The_quadrilateral(side_a, side_b, side_c, side_d, corner_A, corner_B, corner_C, corner_D) {
        this->name = "Ромб"; // Изменяем имя фигуры
    }

    // Переопределение метода вывода
    void print_info() const override {
        Figure::print_info();
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d
             << "\nУглы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};

int main() {
    // Массив указателей на объекты фигур
    Figure* figure[] = {
        new Triangle {10, 20, 30, 50, 60, 70},
        new A_right_angled_riangle {10, 20, 30, 50, 60, 90},
        new Isosceles_triangle {10, 20, 10, 50, 60, 50},
        new An_equilateral_triangle {30, 30, 30, 60, 60, 60},
        new Rectangle {10, 20, 10, 20, 90, 90, 90, 90},
        new Square {20, 20, 20, 20, 90, 90, 90, 90},
        new Parallelogram {20, 30, 20, 30, 30, 40, 30, 40},
        new Rhomb {30, 30, 30, 30, 30, 40, 30, 40}
    };

    // Цикл для вывода информации о каждой фигуре
    for (int i = 0; i < sizeof(figure) / sizeof(figure[0]); i++) {
        figure[i]->print_info();
    }

    return 0;
}