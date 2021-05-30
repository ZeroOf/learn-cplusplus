//
// Created by God on 2021/5/25.
//

#include <iostream>
#include <random/RandomGenerator.h>

using namespace std;

int main() {
    std::vector<int> random = RandomGenerator::Generate(10);
    for(auto i : random) {
        cout << i << "\t";
    }
    cout << endl;
}