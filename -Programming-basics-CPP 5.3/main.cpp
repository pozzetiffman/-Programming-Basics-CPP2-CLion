#include <iostream>
#include <string>
using namespace std;

// Базовый класс "Figure", представляющий любую фигуру
class Figure {
protected:
    int sides_count;  // Количество сторон фигуры
    string name;      // Название фигуры
public:
    // Конструктор принимает количество сторон и имя фигуры
    Figure(int sides, string f_name) : sides_count(sides), name(f_name) {}

    // Виртуальный метод для вывода информации о фигуре (может быть переопределён в наследниках)
    virtual void print_info() const {
        cout << name << ":" << endl;
        cout << "Количество сторон " << sides_count << endl;
    }

    // Виртуальный метод проверки правильности фигуры (может быть переопределён в наследниках)
    virtual bool check() {
        return sides_count == 0;  // Для базовой фигуры правильная — это фигура с нулём сторон
    }
};

// Базовый класс для треугольников
class Triangle : public Figure {
protected:
    int a{}, b{}, c{};  // Длины сторон треугольника
    int A{}, B{}, C{};  // Углы треугольника
public:
    // Конструктор треугольника, устанавливающий длины сторон и углы
    Triangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C)
        : Figure(3, "Треугольник"), a(side_a), b(side_b), c(side_c), A(corner_A), B(corner_B), C(corner_C) {}

    // Метод для вывода информации о треугольнике
    void print_info() const override {
        Figure::print_info();  // Вызов базового метода
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\nУглы: A=" << A << " B=" << B << " C=" << C << "\n";
    }

    // Метод для проверки правильности треугольника (сумма углов должна быть 180)
    bool check() override {
        return sides_count == 3 && A + B + C == 180;
    }
};

// Базовый класс для четырёхугольников
class The_quadrilateral : public Figure {
protected:
    int a{}, b{}, c{}, d{};  // Длины сторон четырёхугольника
    int A{}, B{}, C{}, D{};  // Углы четырёхугольника
public:
    // Конструктор четырёхугольника, устанавливающий длины сторон и углы
    The_quadrilateral(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
        : Figure(4, "Четырёхугольник"), a(side_a), b(side_b), c(side_c), d(side_d), A(corner_A), B(corner_B), C(corner_C), D(corner_D) {}

    // Метод для вывода информации о четырёхугольнике
    void print_info() const override {
        Figure::print_info();  // Вызов базового метода
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\nУглы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
    }

    // Метод для проверки правильности четырёхугольника (сумма углов должна быть 360)
    bool check() override {
        return sides_count == 4 && (A + B + C + D) == 360;
    }
};

// Прямоугольный треугольник, наследник от класса Triangle
class A_right_angled_riangle : public Triangle {
public:
    // Конструктор прямоугольного треугольника
    A_right_angled_riangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C)
        : Triangle(side_a, side_b, side_c, corner_A, corner_B, corner_C) {
        this->name = "Прямоугольный треугольник";  // Меняем имя фигуры
    }

    // Метод для проверки правильности прямоугольного треугольника (угол C всегда должен быть 90)
    bool check() override {
        return Triangle::check() && C == 90;
    }
};

// Равнобедренный треугольник, наследник от класса Triangle
class Isosceles_triangle : public Triangle {
public:
    // Конструктор равнобедренного треугольника
    Isosceles_triangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C)
        : Triangle(side_a, side_b, side_c, corner_A, corner_B, corner_C) {
        this->name = "Равнобедренный треугольник";
    }

    // Метод для проверки правильности равнобедренного треугольника (стороны a и c равны, углы A и C равны)
    bool check() override {
        return Triangle::check() && a == c && A == C;
    }
};

// Равносторонний треугольник, наследник от класса Triangle
class An_equilateral_triangle : public Triangle {
public:
    // Конструктор равностороннего треугольника
    An_equilateral_triangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C)
        : Triangle(side_a, side_b, side_c, corner_A, corner_B, corner_C) {
        this->name = "Равносторонний треугольник";
    }

    // Метод для проверки правильности равностороннего треугольника (все стороны равны, все углы по 60)
    bool check() override {
        return Triangle::check() && (a == b && b == c) && (A == 60 && B == 60 && C == 60);
    }
};

// Прямоугольник, наследник от класса The_quadrilateral
class Rectangle : public The_quadrilateral {
public:
    // Конструктор прямоугольника
    Rectangle(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
        : The_quadrilateral(side_a, side_b, side_c, side_d, corner_A, corner_B, corner_C, corner_D) {
        this->name = "Прямоугольник";
    }

    // Метод для проверки правильности прямоугольника (все углы по 90, стороны попарно равны)
    bool check() override {
        return The_quadrilateral::check() && (a == c && b == d) && (A == 90 && B == 90 && C == 90 && D == 90);
    }
};

// Квадрат, наследник от класса The_quadrilateral
class Square : public The_quadrilateral {
public:
    // Конструктор квадрата
    Square(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
        : The_quadrilateral(side_a, side_b, side_c, side_d, corner_A, corner_B, corner_C, corner_D) {
        this->name = "Квадрат";
    }

    // Метод для проверки правильности квадрата (все стороны равны, все углы по 90)
    bool check() override {
        return The_quadrilateral::check() && (a == b && b == c && c == d) && (A == 90 && B == 90 && C == 90 && D == 90);
    }
};

// Параллелограмм, наследник от класса The_quadrilateral
class Parallelogram : public The_quadrilateral {
public:
    // Конструктор параллелограмма
    Parallelogram(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
        : The_quadrilateral(side_a, side_b, side_c, side_d, corner_A, corner_B, corner_C, corner_D) {
        this->name = "Параллелограмм";
    }

    // Метод для проверки правильности параллелограмма (стороны a и c равны, b и d равны, углы A и C равны, B и D равны)
    bool check() override {
        return The_quadrilateral::check() && (a == c && b == d) && (A == C && B == D);
    }
};

// Ромб, наследник от класса The_quadrilateral
class Rhomb : public The_quadrilateral {
public:
    // Конструктор ромба
    Rhomb(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D)
        : The_quadrilateral(side_a, side_b, side_c, side_d, corner_A, corner_B, corner_C, corner_D) {
        this->name = "Ромб";
    }

    // Метод для проверки правильности ромба (все стороны равны, углы A и C равны, углы B и D равны)
    bool check() override {
        return The_quadrilateral::check() && (a == b && b == c && c == d) && (A == C && B == D);
    }
};

int main() {
    // Массив указателей на объекты разных фигур
    Figure* figure[] = {
        new Figure(0, "Фигура"),  // фигура с 0 сторонами
        new Triangle(10, 20, 30, 50, 60, 70),  // треугольник
        new A_right_angled_riangle(10, 20, 30, 50, 60, 90),  // прямоугольный треугольник
        new Isosceles_triangle(10, 20, 10, 50, 60, 50),  // равнобедренный треугольник
        new An_equilateral_triangle(30, 30, 30, 60, 60, 60),  // равносторонний треугольник
        new The_quadrilateral(10, 20, 30, 40, 50, 60, 70, 80),  // четырёхугольник
        new Rectangle(10, 20, 10, 20, 90, 90, 90, 90),  // прямоугольник
        new Square(20, 20, 20, 20, 90, 90, 90, 90),  // квадрат
        new Parallelogram(20, 30, 20, 30, 30, 40, 30, 40),  // параллелограмм
        new Rhomb(30, 30, 30, 30, 30, 40, 30, 40),  // ромб
    };

    // Вывод информации и проверка правильности каждой фигуры
    for (int i = 0; i < sizeof(figure) / sizeof(figure[0]); ++i) {
        figure[i]->print_info();
        cout << (figure[i]->check() ? "Правильная\n" : "Неправильная\n") << endl;
    }

    return 0;
}