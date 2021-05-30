//
// Created by God on 2021/5/25.
//

#ifndef CPP_PRACTICE_HEAPSORT_H
#define CPP_PRACTICE_HEAPSORT_H

#include <vector>

class HeapSort {
public:
   void Sort(std::vector<int> &numbers);
private:
    void Heapify(std::vector<int>& numbers, size_t top);
};


#endif //CPP_PRACTICE_HEAPSORT_H
