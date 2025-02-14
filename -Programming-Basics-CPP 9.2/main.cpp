#include <iostream>
#include <cmath> // Для std::sqrt

// Класс Fraction представляет дробь
class Fraction {
private:
    int numerator_;   // Числитель
    int denominator_; // Знаменатель

    // НОД для сокращения дробей
    int GCD(int a, int b) {return b == 0 ? a : GCD(b, a % b);}

    // Сокращение дроби
    void Reduce() {
        int gcd = GCD(std::abs(numerator_), std::abs(denominator_));
        numerator_ /= gcd;
        denominator_ /= gcd;
        if (denominator_ < 0) { // Знаменатель всегда положительный
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
    }
public:
    // Конструктор
    Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Знаменатель не может быть равен нулю!");
        }
        numerator_ = numerator;
        denominator_ = denominator;
        Reduce();
    }

    // Метод для расчёта модуля дроби
    double Abs() const { return static_cast<double> (std::abs(numerator_)) / (std::abs(denominator_));}

    // Операторы сравнения
    bool operator==(Fraction other) { return denominator_ == other.denominator_; }
    bool operator!=(Fraction other) { return !(*this == other); }
    bool operator>(Fraction other) { return Abs() > other.Abs(); }
    bool operator<(Fraction other) { return other > *this; }
    bool operator>=(Fraction other) { return !(*this < other); }
    bool operator<=(Fraction other) { return !(*this > other); }

    // Операторы сложения и вычитания
    Fraction operator+(Fraction other) {
        int new_numerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
        int new_denominator = denominator_ * other.denominator_;
        return {new_numerator, new_denominator};
    }
    Fraction operator-(Fraction other) {
        int new_numerator = numerator_ * other.denominator_ - other.numerator_ * denominator_;
        int new_denominator = denominator_ * other.denominator_;
        return {new_numerator, new_denominator};
    }

    // Операторы умножения и деления
    Fraction operator*(Fraction other) {
        int new_numerator = numerator_ * other.numerator_;
        int new_denominator = denominator_ * other.denominator_;
        return {new_numerator, new_denominator};
    }
    Fraction operator/(Fraction other) {
        if (other.numerator_ == 0) {
            throw std::invalid_argument("Деление на дробь с числителем равным нулю невозможно!");
        }
        int new_numerator = numerator_ * other.denominator_;
        int new_denominator = denominator_ * other.numerator_;
        return {new_numerator, new_denominator};
    }

    // Префиксный инкремент
    Fraction& operator++() {
        numerator_ += denominator_;
        return *this; // Возвращаем изменённый объект
    }
    // Постфиксный инкремент
    Fraction operator++(int) {
        Fraction temp = *this; // Сохраняем текущее состояние
        numerator_ += denominator_;
        return temp; // Возвращаем старое состояние
    }
    // Префиксный декремент
    Fraction& operator--() {
        numerator_ -= denominator_;
        return *this;
    }
    // Постфиксный декремент
    Fraction operator--(int) {
        Fraction temp = *this; // Сохраняем текущее состояние
        numerator_ -= denominator_;
        return temp; // Возвращаем старое состояние
    }

    // Вывод дроби
    void Print () { std::cout << numerator_ << "/" << denominator_ << std::endl;}
};

int main() {
    try {
        // Ввод данных для двух дробей
        int a{}, b{}, c{}, d{};
        std::cout << "Введите числитель дроби 1: ";
        std::cin >> a;
        std::cout << "Введите знаменатель дроби 1: ";
        std::cin >> b;
        if (b == 0) throw std::invalid_argument("Знаменатель не может быть равен нулю!");

        std::cout << "Введите числитель дроби 2: ";
        std::cin >> c;
        std::cout << "Введите знаменатель дроби 2: ";
        std::cin >> d;
        if (d == 0) throw std::invalid_argument("Знаменатель не может быть равен нулю!");

        // Создание объектов дробей
        Fraction f1(a, b);
        Fraction f2(c, d);

        // Операции над дробями
        Fraction sum_f_f = f1 + f2;
        Fraction sub_f_f = f1 - f2;
        Fraction mult_f_f = f1 * f2;
        Fraction div_f_f = f1 / f2;

        // Вывод результатов
        std::cout << "3/4 + 4/5 = "; sum_f_f.Print();
        std::cout << "3/4 - 4/5 = "; sub_f_f.Print();
        std::cout << "3/4 * 4/5 = "; mult_f_f.Print();
        std::cout << "3/4 / 4/5 = "; div_f_f.Print();

        // Демонстрация инкремента/декремента
        Fraction product = (++f1) * f2; // f1 становится 7/4
        std::cout << "++3/4 * 4/5 = "; product.Print();
        std::cout << "Значение дроби 1 = "; f1.Print();

        Fraction product2 = (f1--) * f2; // f1 вернётся к 3/4 после умножения
        std::cout << "7/4-- * 4/5 = "; product2.Print();
        std::cout << "Значение дроби 1 = "; f1.Print();


    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}