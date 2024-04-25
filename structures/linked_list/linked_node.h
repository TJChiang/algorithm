//
// Created by nature on 2024/4/17.
//

#ifndef LINKED_NODE_H
#define LINKED_NODE_H

namespace structures {

struct LinkedNode{
    int val;
    LinkedNode* next;
    LinkedNode() : val(0), next(nullptr) {};
    explicit LinkedNode(const int x) : val(x), next(nullptr) {};
    LinkedNode(const int x, LinkedNode* next) : val(x), next(next) {};
};

} // structures

#endif //LINKED_NODE_H
