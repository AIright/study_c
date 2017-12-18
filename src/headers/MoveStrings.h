//
// Created by alright on 17.12.17.
//
/* Напишите функцию MoveStrings, которая принимает два вектора строк,
 * source и destination, и дописывает все строки из первого вектора
 * в конец второго. После выполнения функции вектор source должен оказаться пустым.
 * Чтобы очистить содержимое вектора, надо вызвать у него метод clear:
 * vector<string> words = {"hey", "hi"};
 * words.clear();
 * // Теперь вектор words пуст
 * vector<string> source = {"a", "b", "c"};
 * vector<string> destination = {"z"};
 * MoveStrings(source, destination);
 * // source должен оказаться пустым
 * // destination должен содержать строки "z", "a", "b", "c" именно в таком порядке
 * Пояснение
 * В этой задаче на проверку вам надо прислать файл с реализацией
 * функции MoveStrings. Этот файл не должен содержать функцию main.
 * Если в нём будет функция main, вы получите ошибку компиляции.
*/

#ifndef STUDY_C_MOVESTRINGS_H
#define STUDY_C_MOVESTRINGS_H

#include <iostream>
#include <vector>
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
    for (auto s : source) {
        destination.push_back(s);
    }
    source.clear();
}

#endif //STUDY_C_MOVESTRINGS_H
