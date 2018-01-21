//
// Created by alright on 16/01/2018.
//

#ifndef STUDY_C_FINALTASK_H
#define STUDY_C_FINALTASK_H

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
using namespace std;

class Date {
public:
    Date () { // Default constructor
        year = 0;
        month = 1;
        day = 1;
    };
    Date(const int& y, const int& m, const int& d) {// Constructor
        if (y < 0 || y > 9999) { //Check year
            throw invalid_argument("Year value is invalid: " + to_string(y));
        } else if (m < 1 || m > 12) { //Check month
            throw invalid_argument("Month value is invalid: " + to_string(m));
        } else if (d < 1 || d > 31) { // Check day
            throw invalid_argument("Day value is invalid: " + to_string(d));
        } else {
            year = y;
            month = m;
            day = d;
        }
    }

    int GetYear() const {
        return year;
    };

    int GetMonth() const {
        return month;
    };

    int GetDay() const {
        return day;
    };

    friend ostream& operator<<(ostream& stream, const Date& date) {
        stream << setfill('0');
        return stream << setw(4) << date.GetYear() << '-'
                      << setw(2) << date.GetMonth() << '-'
                      << setw(2) << date.GetDay();
    };

    friend stringstream& operator>>(stringstream& stream, Date& date) {
        int y, m, d; // Parameters
        vector<string> all; // vector of params
        set<char> params_check = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-'}; // vector of allowed chars
        string full, one; // full date string and buffer string for parameter
        stream >> full; // Read date string
        int pos_word = 0; // Character position in parameter
        int pos = 0; // Character position in date string
        int word = 0; // Number of parameter (0 - y, 1- m, 2 - d)
        for (auto& c:full) {
            pos ++;           //  Increment pos first for compatible with full.size()
            if (c == '-' && pos_word == 0 && word == 0) { // If year < 0 ('-' at the start of the date string)
                throw invalid_argument("Wrong date format: " + full);
            } else if ((c != '-') || (c == '-' && pos_word == 0)) {
                // Increment if '-' not at the start of the date string or '-' in the start of the param)
                if (params_check.count(c)) { //Check the char
                    one += c;
                    pos_word ++;
                } else {
                    throw invalid_argument("Wrong date format: " + full);
                }
            } else if (c == '-' && pos_word != 0 && word != 2) { // If '-' is not in the start of the parameter
                pos_word = 0;    // Position to 0
                all.push_back(one); // Add to params vector
                one.erase(one.begin(), one.end()); // Clear param buffer
                word ++; // Increase number of param
            } else { // Something goes wrong
                throw invalid_argument("Wrong date format: " + full);
            }
            if (pos == full.size()) { // If c is the last character then add last param to vector
                all.push_back(one);
            }
        }
        if (all.size() != 3) { // If less than 3 params was given
            throw invalid_argument("Wrong date format: " + full);
        }
        // Convert string params to int
        try {
            y = stoi(all[0]);
            m = stoi(all[1]);
            d = stoi(all[2]);
            if (y > 9999) {
                throw invalid_argument("Wrong date format: " + full);
            }
        } catch (exception& e) {
            throw invalid_argument("Wrong date format: " + full);
        }
        date = Date(y, m, d);
        return stream;
    };

    friend bool operator<(const Date& lhs, const Date& rhs){
        if (lhs.GetYear() < rhs.GetYear()) {
            return true;
        } else if (lhs.GetYear() == rhs.GetYear()) {
            if (lhs.GetMonth() < rhs.GetMonth()) {
                return true;
            } else if (lhs.GetMonth() == rhs.GetMonth()) {
                if (lhs.GetDay() < rhs.GetDay()) {
                    return true;
                }
            }
        }
        return false;
    };

private:
    int year;
    int month;
    int day;
};

class Database {
public:
    void AddEvent(const Date& date, const string& event){
        events[date].insert(event);
    };
    bool DeleteEvent(const Date& date, const string& event){
        if (!events.count(date) || !events.at(date).count(event)) {
            return false;
        } else {
            events.at(date).erase(event);
            return true;
        }
    };
    int  DeleteDate(const Date& date) {
        if (!events.count(date)) {
            return 0;
        } else {
            int buf = events.at(date).size();
            events.at(date).clear();
            return buf;
        }
    };

    void Find(const Date& date) const {
        if (!events.count(date)) {

        } else {
            for (const auto& item : events.at(date)) {
                cout << item << endl;
            }
        }
    };

    void Print() const {
        for (const auto& date : events) {
            for (const auto& e : date.second) {
                cout << date.first << " " << e << endl;
            }
        }
    };

private:
    map<Date, set<string>> events;
};
/* REAL SOLUTION
 * class Date {
public:
  // конструктор выбрасывает исключение, если его аргументы некорректны
  Date(int new_year, int new_month, int new_day) {
    year = new_year;
    if (new_month > 12 || new_month < 1) {
      throw logic_error("Month value is invalid: " + to_string(new_month));
    }
    month = new_month;
    if (new_day > 31 || new_day < 1) {
      throw logic_error("Day value is invalid: " + to_string(new_day));
    }
    day = new_day;
  }

  int GetYear() const {
    return year;
  }
  int GetMonth() const {
    return month;
  }
  int GetDay() const {
    return day;
  }

private:
  int year;
  int month;
  int day;
};

// определить сравнение для дат необходимо для использования их в качестве ключей словаря
bool operator<(const Date& lhs, const Date& rhs) {
  // воспользуемся тем фактом, что векторы уже можно сравнивать на <:
  // создадим вектор из года, месяца и дня для каждой даты и сравним их
  return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
      vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

// даты будут по умолчанию выводиться в нужном формате
ostream& operator<<(ostream& stream, const Date& date) {
  stream << setw(4) << setfill('0') << date.GetYear() <<
      "-" << setw(2) << setfill('0') << date.GetMonth() <<
      "-" << setw(2) << setfill('0') << date.GetDay();
  return stream;
}

class Database {
public:
  void AddEvent(const Date& date, const string& event) {
    storage[date].insert(event);
  }

  bool DeleteEvent(const Date& date, const string& event) {
    if (storage.count(date) > 0 && storage[date].count(event) > 0) {
      storage[date].erase(event);
      return true;
    }
    return false;
  }

  int DeleteDate(const Date& date) {
    if (storage.count(date) == 0) {
      return 0;
    } else {
      const int event_count = storage[date].size();
      storage.erase(date);
      return event_count;
    }
  }

  set<string> Find(const Date& date) const {
    if (storage.count(date) > 0) {
      return storage.at(date);
    } else {
      return {};
    }
  }

  void Print() const {
    for (const auto& item : storage) {
      for (const string& event : item.second) {
        cout << item.first << " " << event << endl;
      }
    }
  }

private:
  map<Date, set<string>> storage;
};

Date ParseDate(const string& date) {
  stringstream date_stream(date);

  int year;
  date_stream >> year;

  if (date_stream.peek() != '-') {
    throw logic_error("Wrong date format: " + date);
  }
  date_stream.ignore();

  int month;
  date_stream >> month;

  if (date_stream.peek() != '-') {
    throw logic_error("Wrong date format: " + date);
  }
  date_stream.ignore();

  int day;
  date_stream >> day;

  if (!date_stream.eof()) {
    throw logic_error("Wrong date format: " + date);
  }

  return Date(year, month, day);
}
 */

#endif //STUDY_C_FINALTASK_H
