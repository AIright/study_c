//
// Created by alright on 27.12.17.
//
/* Дана структура LectureTitle:
 * struct LectureTitle {
 * string specialization;
 * string course;
 * string week;
 * };
 * Допишите конструктор и структуры Specialization, Course, Week так,
 * чтобы объект LectureTitle можно было создать с помощью кода
 * LectureTitle title(
 * Specialization("C++"),
 * Course("White belt"),
 * Week("4th")
 * );
 * но нельзя было с помощью следующих фрагментов кода:
 * LectureTitle title("C++", "White belt", "4th");
 * LectureTitle title = {"C++", "White belt", "4th"};
 * LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};
 * LectureTitle title(
 * Course("White belt"),
 * Specialization("C++"),
 * Week("4th")
 * );
 * LectureTitle title(
 * Specialization("C++"),
 * Week("4th"),
 * Course("White belt")
 * );
 */

#ifndef STUDY_C_LECTURETITLE_H
#define STUDY_C_LECTURETITLE_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Specialization {
    string value;
    explicit Specialization(string& new_value) {
        value = new_value;
    }
};

struct Course {
    string value;
    explicit Course(string& new_value) {
        value = new_value;
    }
};

struct Week {
    string value;
    explicit Week(string& new_value) {
        value = new_value;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle(Specialization& specialization1, Course& course1, Week& week1) {
        specialization = specialization1.value;
        course = course1.value;
        week = week1.value;
    }
};


#endif //STUDY_C_LECTURETITLE_H
