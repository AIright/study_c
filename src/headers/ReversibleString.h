//
// Created by Aleksey.Emelyanov on 26.12.2017.
//
/* Реализуйте класс ReversibleString, хранящий строку и поддерживающий методы
 * Reverse для переворота строки и ToString для получения строки.
 * int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}
 * Вывод
 * evil
 * live
 * ""
 */

#ifndef STUDY_C_REVERSIBLESTRING_H
#define STUDY_C_REVERSIBLESTRING_H

#include <iostream>
#include <string>
#include <algorithm>

using  namespace std;

class ReversibleString {
private:
    string data;

public:
    ReversibleString() {
        data = "";
    }
    ReversibleString(const string& base) {
        data = base;
    }

    void Reverse() {
        reverse(data.begin(), data.end());
    }

    string ToString() const {
        return data;
    }
};

#endif //STUDY_C_REVERSIBLESTRING_H
