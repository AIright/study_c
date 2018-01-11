#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        int div = 0;
        if (numerator <= 0 && denominator <= 0) {
            // если числетель и знаменатель отрицательные, то дробь положительная
            // избавляемся от отрицательности
            numerator *= -1;
            denominator *= -1;
            p = numerator;
            q = denominator;
        } else if (numerator < 0) {
            // если числитель отрицательный, то запоминаем его знак и
            // избавляемся от отрицательности для вычисления НОД
            p = numerator;
            q = denominator;
            numerator *= -1;
        } else if (denominator < 0) {
            // если знаменатель отрицательный, то переносим его знак в числитель и
            // избавляемся от отрицательности для вычисления НОД
            p = numerator * -1;
            denominator *= -1;
            q = denominator;
        } else {
            // если оба положительные
            p = numerator;
            q = denominator;
        }
        // ищем наибольший общий делитель
        while (numerator > 0 && denominator > 0) {
            // возьмём большее из чисел и заменим его остатком от деления на второе
            // действительно, если a и b делятся на x, то a - b и b делятся на x
            // тогда и a % b и b делятся на x, так что можно a заменить на a % b
            if (numerator > denominator) {
                numerator %= denominator;
            } else {
                denominator %= numerator;
            }
        }
        // если одно из чисел оказалось равно нулю, значит, на последней итерации
        // большее число разделилось на меньшее
        div =  numerator + denominator;
        p /= div;
        q /= div;
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

    void SetNew(int& numerator, int& denominator) {
        int div = 0;
        if (numerator <= 0 && denominator <= 0) {
            // если числетель и знаменатель отрицательные, то дробь положительная
            // избавляемся от отрицательности
            numerator *= -1;
            denominator *= -1;
            p = numerator;
            q = denominator;
        } else if (numerator < 0) {
            // если числитель отрицательный, то запоминаем его знак и
            // избавляемся от отрицательности для вычисления НОД
            p = numerator;
            q = denominator;
            numerator *= -1;
        } else if (denominator < 0) {
            // если знаменатель отрицательный, то переносим его знак в числитель и
            // избавляемся от отрицательности для вычисления НОД
            p = numerator * -1;
            denominator *= -1;
            q = denominator;
        } else {
            // если оба положительные
            p = numerator;
            q = denominator;
        }
        // ищем наибольший общий делитель
        while (numerator > 0 && denominator > 0) {
            // возьмём большее из чисел и заменим его остатком от деления на второе
            // действительно, если a и b делятся на x, то a - b и b делятся на x
            // тогда и a % b и b делятся на x, так что можно a заменить на a % b
            if (numerator > denominator) {
                numerator %= denominator;
            } else {
                denominator %= numerator;
            }
        }
        // если одно из чисел оказалось равно нулю, значит, на последней итерации
        // большее число разделилось на меньшее
        div =  numerator + denominator;
        p /= div;
        q /= div;
    }

private:
    int p;
    int q;
};

// Реализуйте для класса Rational операторы ==, + и -
bool operator==(const Rational& r1, const Rational& r2) {
    return (r1.Numerator() == r2.Numerator() && r1.Denominator() == r2.Denominator());
}

bool operator<(const Rational& r1, const Rational& r2) {
    return (r1.Numerator() * r2.Denominator() < r2.Numerator() * r1.Denominator());
}

Rational operator+(const Rational& r1, const Rational& r2) {
    return     {r1.Numerator() * r2.Denominator() + r2.Numerator() * r1.Denominator(),
                r1.Denominator() * r2.Denominator()};
}

Rational operator-(const Rational& r1, const Rational& r2) {
    return {r1.Numerator() * r2.Denominator() - r2.Numerator() * r1.Denominator(),
            r1.Denominator() * r2.Denominator()};
}

Rational operator*(const Rational& r1, const Rational& r2) {
    return {r1.Numerator() * r2.Numerator(),
            r1.Denominator() * r2.Denominator()};
}

Rational operator/(const Rational& r1, const Rational& r2) {
    return {r1.Numerator() * r2.Denominator(),
            r1.Denominator() * r2.Numerator()};
}

istream& operator>>(istream& stream, Rational& r1) {
    int p = 0;
    int q = 0;
    stream >> p;
    stream.ignore(1);
    stream >> q;
    if (p == 0 && q == 0) {
        return stream;
    }
    r1.SetNew(p, q);
    return stream;
}

ostream& operator<<(ostream& stream, const Rational& r1) {
    stream << r1.Numerator() << "/" << r1.Denominator();
    return stream;
}

int main() {

    return 0;
}

