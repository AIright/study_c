//
// Created by alright on 20.12.17.
//

#ifndef STUDY_C_BUILDMAPVALUESSET_H
#define STUDY_C_BUILDMAPVALUESSET_H

#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> output_set;
    for (const auto& g : m) {
        output_set.insert(g.second);
    }
    return output_set;
}



#endif //STUDY_C_BUILDMAPVALUESSET_H
