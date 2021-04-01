
#ifndef CPP_PRACTICE_NODE_HPP
#define CPP_PRACTICE_NODE_HPP


template <typename T>
struct Node {
    Node() = default;

    explicit Node(T value) : value_(value) {}

    Node(T value, Node *pNext) : value_(value), pNext_(pNext) {}

    T value_;
    Node* pNext_;
};

#endif //CPP_PRACTICE_NODE_HPP
