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
            // ���� ��������� � ����������� �������������, �� ����� �������������
            // ����������� �� ���������������
            numerator *= -1;
            denominator *= -1;
            p = numerator;
            q = denominator;
        } else if (numerator < 0) {
            // ���� ��������� �������������, �� ���������� ��� ���� �
            // ����������� �� ��������������� ��� ���������� ���
            p = numerator;
            q = denominator;
            numerator *= -1;
        } else if (denominator < 0) {
            // ���� ����������� �������������, �� ��������� ��� ���� � ��������� �
            // ����������� �� ��������������� ��� ���������� ���
            p = numerator * -1;
            denominator *= -1;
            q = denominator;
        } else {
            // ���� ��� �������������
            p = numerator;
            q = denominator;
        }
        // ���� ���������� ����� ��������
        while (numerator > 0 && denominator > 0) {
            // ������ ������� �� ����� � ������� ��� �������� �� ������� �� ������
            // �������������, ���� a � b ������� �� x, �� a - b � b ������� �� x
            // ����� � a % b � b ������� �� x, ��� ��� ����� a �������� �� a % b
            if (numerator > denominator) {
                numerator %= denominator;
            } else {
                denominator %= numerator;
            }
        }
        // ���� ���� �� ����� ��������� ����� ����, ������, �� ��������� ��������
        // ������� ����� ����������� �� �������
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
            // ���� ��������� � ����������� �������������, �� ����� �������������
            // ����������� �� ���������������
            numerator *= -1;
            denominator *= -1;
            p = numerator;
            q = denominator;
        } else if (numerator < 0) {
            // ���� ��������� �������������, �� ���������� ��� ���� �
            // ����������� �� ��������������� ��� ���������� ���
            p = numerator;
            q = denominator;
            numerator *= -1;
        } else if (denominator < 0) {
            // ���� ����������� �������������, �� ��������� ��� ���� � ��������� �
            // ����������� �� ��������������� ��� ���������� ���
            p = numerator * -1;
            denominator *= -1;
            q = denominator;
        } else {
            // ���� ��� �������������
            p = numerator;
            q = denominator;
        }
        // ���� ���������� ����� ��������
        while (numerator > 0 && denominator > 0) {
            // ������ ������� �� ����� � ������� ��� �������� �� ������� �� ������
            // �������������, ���� a � b ������� �� x, �� a - b � b ������� �� x
            // ����� � a % b � b ������� �� x, ��� ��� ����� a �������� �� a % b
            if (numerator > denominator) {
                numerator %= denominator;
            } else {
                denominator %= numerator;
            }
        }
        // ���� ���� �� ����� ��������� ����� ����, ������, �� ��������� ��������
        // ������� ����� ����������� �� �������
        div =  numerator + denominator;
        p /= div;
        q /= div;
    }

private:
    int p;
    int q;
};

// ���������� ��� ������ Rational ��������� ==, + � -
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

