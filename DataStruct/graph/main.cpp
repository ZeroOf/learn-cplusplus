
#include <iostream>
#include "Node.hpp"
#include "Graph.hpp"

int main() {
    std::cout << "Graph practice" << std::endl;
    Node<int> node1, node2;
    node1.value_ = 1;
    node1.pNext_ = &node2;
    node2.value_ = 2;
    node2.pNext_ = nullptr;
}