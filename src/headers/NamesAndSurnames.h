//
// Created by alright on 24.12.17.
//
/* Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.
 * Считайте, что в каждый год может произойти не более одного изменения фамилии и не более одного изменения имени.
 * При этом с течением времени могут открываться всё новые факты из прошлого человека, поэтому года́
 * в последовательных вызовах методов ChangeLastName и ChangeFirstName не обязаны возрастать.
 * Гарантируется, что все имена и фамилии непусты.
 * Строка, возвращаемая методом GetFullName, должна содержать разделённые одним пробелом имя и
 * фамилию человека по состоянию на конец данного года.
 * Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "Incognito".
 * Если к данному году случилось изменение фамилии, но не было ни одного изменения имени,
 * верните "last_name with unknown first name".
 * Если к данному году случилось изменение имени, но не было ни одного изменения фамилии,
 * верните "first_name with unknown last name".
 * Дополните класс из предыдущей задачи «Имена и фамилии — 1» методом GetFullNameWithHistory:
 * В отличие от метода GetFullName, метод GetFullNameWithHistory должен вернуть не только последние имя и фамилию
 * к концу данного года, но ещё и все предыдущие имена и фамилии в обратном хронологическом порядке.
 * Если текущие факты говорят о том, что человек два раза подряд изменил фамилию или имя на одно и то же,
 * второе изменение при формировании истории нужно игнорировать
 * Дополните класс Person из задачи «Имена и фамилии — 2» конструктором, 
 * позволяющим задать имя и фамилию человека при рождении, а также сам год рождения. 
 * Класс не должен иметь конструктора по умолчанию.
 * При получении на вход года, который меньше года рождения:
 * методы GetFullName и GetFullNameWithHistory должны отдавать "No person";
 * методы ChangeFirstName и ChangeLastName должны игнорировать запрос.
 * Кроме того, необходимо объявить константными все методы, которые по сути ими являются.
 */

#ifndef STUDY_C_NAMESANDSURENAMES1_H
#define STUDY_C_NAMESANDSURENAMES1_H

#include <string>
#include <algorithm>
#include <iostream>
#include <locale>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>

using namespace std;



class Person {
private:
    // приватные поля
    // фиксируем изменение имени
    map<int, string> name;
    // список дат изменения имени для итерации
    vector<int> names_years;
    // фиксируем изменение фамилии
    map<int, string> surename;
    // список дат изменения фамилии для итерации
    vector<int> surenames_years;

public:
    Person(const string& init_name, const string& init_surename, const int& init_date) {
        name[init_date] = init_name;
        names_years.push_back(init_date);
        surename[init_date] = init_surename;
        surenames_years.push_back(init_date);
    }

    void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
        if (year > names_years[0]) {
            name[year] = first_name;
            names_years.push_back(year);
            // сортируем вектор дат изменения имени
            sort(names_years.begin(), names_years.end());
        }
    }

    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        if (year > surenames_years[0]) {
            surename[year] = last_name;
            surenames_years.push_back(year);
            // сортируем вектор дат изменения фамилии
            sort(surenames_years.begin(), surenames_years.end());
        }
    }

    string GetFullName(int& year) const {
        // получить имя и фамилию по состоянию на конец года year
        // год меньше минимального
        if (year < names_years[0]) {
            return "No person";
        // год больше максимального
        } else if ((names_years[name.size() - 1] <= year) && (surenames_years[surename.size() - 1] <= year)){
        // выводим изменения в последний год
            return name.at(names_years[name.size() - 1]) + " "
                   + surename.at(surenames_years[surename.size() - 1]);
        // если дата изменения имени меньше минимальной или дат нет
        } else {
            // значит дата year внутри списков дат изменений имени и фамилии
            // итерируем по датам изменений, находим ближайшие, выводим
            int bufs = Iterate(surenames_years, year);
            int bufn = Iterate(names_years, year);
            return name.at(bufn) + " " + surename.at(bufs);
        }
    }

    string GetFullNameWithHistory(int& year) const {
        // получить все имена и фамилии по состоянию на конец года year
        // год меньше минимального
        if (year < surenames_years[0]) {
            return "No person";
        // год больше максимального
        } else if ((names_years[name.size() - 1] <= year) && (surenames_years[surename.size() - 1] <= year)){
            // выводим изменения в последний год
            return name.at(names_years[name.size() - 1]) +
                    IteateHistory(names_years, names_years[names_years.size() - 1], name, 0) +
                    surename.at(surenames_years[surename.size() - 1]) +
                    IteateHistory(surenames_years, surenames_years[surenames_years.size() - 1], surename, 1);
            // если дата изменения имени меньше минимальной или дат нет
        } else {
            // значит дата year внутри списков дат изменений имени и фамилии
            // итерируем по датам изменений, находим ближайшие, выводим
            int bufs = Iterate(surenames_years, year);
            int bufn = Iterate(names_years, year);
            return name.at(bufn) +
                    IteateHistory(names_years, bufn, name, 0) +
                    surename.at(bufs) +
                    IteateHistory(surenames_years, bufs, surename, 1);
        }
    }

private:
    // приватные методы
    // функция итерации по векторам дат и вывода ближайшей к year даты
    int Iterate(const vector<int>& years, const int& year) const {
        int buf = 0;
        for (const auto& i : years) {
            if (i > year) {
                break;
            }
            buf = i;
        }
        return buf;
    }

    // функция итерации с историей
    string IteateHistory(const vector<int>& years, const int& year,
            const map<int, string>& names, const bool& last) const {
        string result = " ";
        vector<string> buf;
        // собираем в порядке изменения все уникальные фамилии
        for (auto& i : names) {
            if (i.first < year) {
                if (buf.empty() || (i.second != buf[buf.size() - 1])) {
                    buf.push_back(i.second);
                }
            } else {
                break;
            }
        }
        // если последнее изменение фамилии равно текущей, то удаляем
        if (!buf.empty() && buf[buf.size() - 1] == names.at(year)) {
            buf.resize(buf.size() - 1);
        }
        // если фамилия менялась, то формируем строку с историей
        if (!buf.empty()) {
            result += "(";
            reverse(buf.begin(), buf.end());
            for (auto& i : buf) {
                if (i == buf[buf.size() - 1]) {
                    result += (i + ") ");
                } else {
                    result += (i + ", ");
                }
            }
        }
        // придется удалять пробел в конце, если функция формирует окончание строки
        if (last) {
            result.resize(result.size() - 1);
            return result;
        }
        return result;
    }

};

/* REAL SOLUTION
#include <algorithm>
#include <map>
#include <vector>

vector<string> FindNamesHistory(const map<int, string>& names_by_year,
                                int year) {
  vector<string> names;
  for (const auto& item : names_by_year) {
    if (item.first <= year && (names.empty() || names.back() != item.second)) {
      names.push_back(item.second);
    }
  }
  return names;
}

string BuildJoinedName(vector<string> names) {
  reverse(begin(names), end(names));
  string joined_name = names[0];
  for (int i = 1; i < names.size(); ++i) {
    if (i == 1) {
      joined_name += " (";
    } else {
      joined_name += ", ";
    }
    joined_name += names[i];
  }
  if (names.size() > 1) {
    joined_name += ")";
  }
  return joined_name;
}

class Person {
public:
  // конструктор
  Person(const string& first_name, const string& last_name,
         int new_birth_year) {
    birth_year = new_birth_year;
    first_names[birth_year] = first_name;
    last_names[birth_year] = last_name;
  }
  void ChangeFirstName(int year, const string& first_name) {
    // игнорируем запись, если год меньше года рождения
    if (year >= birth_year) {
      first_names[year] = first_name;
    }
  }
  void ChangeLastName(int year, const string& last_name) {
    if (year >= birth_year) {
      last_names[year] = last_name;
    }
  }
  string GetFullName(int year) const {
    // обрабатываем случай, когда год меньше года рождения
    if (year < birth_year) {
      return "No person";
    }
    const vector<string> first_names = FindFirstNamesHistory(year);
    const vector<string> last_names = FindLastNamesHistory(year);
    // объединяем имя и фамилию через пробел
    return first_names.back() + " " + last_names.back();
  }
  string GetFullNameWithHistory(int year) const {
    if (year < birth_year) {
      return "No person";
    }
    const string first_name = BuildJoinedName(FindFirstNamesHistory(year));
    const string last_name = BuildJoinedName(FindLastNamesHistory(year));
    return first_name + " " + last_name;
  }
private:
  vector<string> FindFirstNamesHistory(int year) const {
    return FindNamesHistory(first_names, year);
  }
  vector<string> FindLastNamesHistory(int year) const {
    return FindNamesHistory(last_names, year);
  }

  int birth_year;
  map<int, string> first_names;
  map<int, string> last_names;
};
*/


#endif //STUDY_C_NAMESANDSURENAMES1_H
