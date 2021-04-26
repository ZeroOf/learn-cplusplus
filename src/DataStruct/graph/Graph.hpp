
#ifndef CPP_PRACTICE_GRAPH_HPP
#define CPP_PRACTICE_GRAPH_HPP

#include <vector>

template<typename T>
struct Graph {
    void AddNode(int key, T value);
    std::vector<Node<T>> nodes_;
};

template<typename T>
void Graph<T>::AddNode(int key, T value) {
    if (key > nodes_.size()) {
        throw std::out_of_range(__func__);
        exit(-1);
    }
    if (key == nodes_.size()) {
        nodes_.template emplace_back(value, nullptr);
        return;
    }
}

#endif //CPP_PRACTICE_GRAPH_HPP
