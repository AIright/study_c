//
// Created by alright on 11.01.18.
//

#ifndef STUDY_C_RATIONAL_H
#define STUDY_C_RATIONAL_H


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

/* REAL CODE
 * #include <iostream>

using namespace std;

// один из способов вычисления наибольшего общего делителя (НОД) — рекурсивный:
// вместо цикла функция будет вызывать себя же, но с другими аргументами
int GreatestCommonDivisor(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return GreatestCommonDivisor(b, a % b);
  }
}

class Rational {
public:
  Rational() {  // дробь по умолчанию — 0/1
    numerator = 0;
    denominator = 1;
  }
  Rational(int new_numerator, int new_denominator) {
    const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
    // сократим дробь, разделив числитель и знаменатель на их НОД
    numerator = new_numerator / gcd;
    denominator = new_denominator / gcd;
    // знаменатель должен быть положительным
    if (denominator < 0) {
      denominator = -denominator;
      numerator = -numerator;
    }
  }

  int Numerator() const {
    return numerator;
  }

  int Denominator() const {
    return denominator;
  }

private:
  int numerator;
  int denominator;
};

// поскольку дроби сокращены, достаточно сравнить числители и знаменатели
bool operator == (const Rational& lhs, const Rational& rhs) {
  return lhs.Numerator() == rhs.Numerator() &&
      lhs.Denominator() == rhs.Denominator();
}

// используем обычную формулу сложения дробей, основанную на приведении слагаемых к общему знаменателю
Rational operator + (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

// вычитание реализуем аналогично сложению
// дублирования кода можно было избежать, определив для класса Rational операцию унарного минуса: тогда разность lhs и rhs можно было бы вычислить           как lhs + (-rhs)
Rational operator - (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Numerator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

// деление равносильно умножению на обратную («перевёрнутую») дробь
Rational operator / (const Rational& lhs, const Rational& rhs) {
  return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

istream& operator >> (istream& is, Rational& r) {
  int n, d;
  char c;
  is >> n >> c >> d;
  if (is && c == '/') {
    r = Rational(n, d);
  }
  return is;
}

ostream& operator << (ostream& os, const Rational& r) {
  return os << r.Numerator() << '/' << r.Denominator();
}

// чтобы сравнить lhs с rhs, сравним их разность с нулём, что равносильно сравнению с нулём числителя
bool operator < (const Rational& lhs, const Rational& rhs) {
  return (lhs - rhs).Numerator() < 0;
}

 */
#endif //STUDY_C_RATIONAL_H
