//
// Created by alright on 28/11/18.
//

#ifndef STUDY_C_WEIGHTOFBLOCKS_H
#define STUDY_C_WEIGHTOFBLOCKS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <string>
using namespace std;


uint64_t weight_of_blocks() {
    uint32_t W = 0;
    uint32_t H = 0;
    uint32_t D = 0;
    uint32_t N = 0;
    uint32_t R = 0;
    uint64_t weight = 0;

    cin >> N >> R;
    for (int i=0; i<N; i++) {
        cin >> W >> H >> D;
        weight += (W * H * D * R);
    }

    return weight;
}

#endif //STUDY_C_WEIGHTOFBLOCKS_H
