#include <iostream>

// Класс Fraction представляет дробь (числитель и знаменатель)
class Fraction {
private:
    int numerator_;   // Числитель
    int denominator_; // Знаменатель

public:
    // Конструктор, инициализирует числитель и знаменатель
    Fraction(int numerator, int denominator) {
        numerator_ = numerator;
        denominator_ = denominator;
    }

    // Метод для расчёта "абсолютного значения" дроби (по формуле √(a² + b²))
    int Abs() {
        return std::sqrt(numerator_ * numerator_ + denominator_ * denominator_);
    }

    // Оператор равенства: проверяет равны ли знаменатели
    bool operator==(Fraction other) {
        return denominator_ == other.denominator_;
    }

    // Оператор неравенства: противоположен оператору равенства
    bool operator!=(Fraction other) {
        return !(*this == other);
    }

    // Оператор "больше": сравнивает дроби по их "абсолютному значению"
    bool operator>(Fraction other) {
        return Abs() > other.Abs();
    }

    // Оператор "меньше": обратное оператору "больше"
    bool operator<(Fraction other) {
        return other > *this;
    }

    // Оператор "больше или равно"
    bool operator>=(Fraction other) {
        return !(*this < other);
    }

    // Оператор "меньше или равно"
    bool operator<=(Fraction other) {
        return !(*this > other);
    }
};

int main() {
    // Создаём два объекта класса Fraction
    Fraction f1(4, 3);  // Дробь 4/3
    Fraction f2(6, 11); // Дробь 6/11

    // Сравниваем дроби с использованием перегруженных операторов
    std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
    std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
    std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
    std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
    std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
    std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

    return 0;
}