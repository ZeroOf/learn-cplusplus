//
// Created by God on 2021/5/25.
//

#include "HeapSort.h"

void HeapSort::Heapify(std::vector<int> &numbers, size_t top) {
    size_t left = top * 2 + 1;
    size_t right = top * 2 + 2;
    if (right <= numbers.size() && numbers[top] < numbers[right]) {

    }
}

void HeapSort::Sort(std::vector<int> &numbers) {

}
