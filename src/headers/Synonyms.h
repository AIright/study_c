//
// Created by alright on 20.12.17.
//

#ifndef STUDY_C_SYNONYMS_H
#define STUDY_C_SYNONYMS_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int Synonyms_main() {
    int tries;
    string first, second, third;
    map<string, int> words;
    cin >> tries;
    set<set<string>> pairs;
    for (int i = 0; i < tries; i++) {
        cin >> first;
        if (first == "ADD") {
            cin >> second >> third;
            if (!pairs.count({second, third})) {
                pairs.insert({second, third});
                words[second]++;
                words[third]++;
            }
        } else if (first == "COUNT") {
            cin >> second;
            cout << words[second] << endl;
        } else if (first == "CHECK") {
            cin >> second >> third;
            if (pairs.count({second, third})) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
};

/* Real solution:
int main() {
  int q;
  cin >> q;

  map<string, set<string>> synonyms;

  for (int i = 0; i < q; ++i) {
    string operation_code;
    cin >> operation_code;

    if (operation_code == "ADD") {

      string first_word, second_word;
      cin >> first_word >> second_word;

      // второе слово добавляем в список синонимов первого...
      synonyms[first_word].insert(second_word);
      // и наоборот
      synonyms[second_word].insert(first_word);

    } else if (operation_code == "COUNT") {

      string word;
      cin >> word;
      cout << synonyms[word].size() << endl;

    } else if (operation_code == "CHECK") {

      string first_word, second_word;
      cin >> first_word >> second_word;

      // ищём второе слово во множестве синонимов первого
      // (можно было сделать и наоборот)
      if (synonyms[first_word].count(second_word) == 1) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }

    }
  }

  return 0;
}
*/


#endif //STUDY_C_SYNONYMS_H
