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


int main() {

    cout << weight_of_blocks();

    return 0;
};