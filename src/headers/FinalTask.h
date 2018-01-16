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
    Date() {
        year = 0;
        month = 1;
        day = 1;
    }

    Date(const int& y, const int& m, const int& d) {
        year = y;
        month = m;
        day = d;
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
        int y, m, d;
        stream >> y;
        if (stream.peek() != '-') {
            throw invalid_argument("Wrong date format: " + stream.str());
        }
        stream.ignore(1);
        stream >> m;
        if (stream.peek() != '-') {
            throw invalid_argument("Wrong date format: " + stream.str());
        }
        stream.ignore(1);
        stream >> d;
        if (stream.peek() != ' ' && !stream.peek()) {
            throw invalid_argument("Wrong date format: " + stream.str());
        }
        if (m < 1 || m > 12) {
            throw invalid_argument("Month value is invalid: " + to_string(m));
        }
        if (d < 1 || d > 31) {
            throw invalid_argument("Day value is invalid: " + to_string(d));
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
        if (!events.at(date).count(event)) {
            return false;
        } else {
            set<string>::iterator it;
            it = events.at(date).find(event);
            events.at(date).erase(it);
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


#endif //STUDY_C_FINALTASK_H
