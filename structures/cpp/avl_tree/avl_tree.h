//
// Created by nature on 2024/4/25.
//

#ifndef AVL_TREE_H
#define AVL_TREE_H
#include "avl_tree_node.h"

namespace structures {

class AvlTree {
private:
    AvlTreeNode* root;
    int _size;
public:
    AvlTree();
    explicit AvlTree(int val);
    ~AvlTree();

    void clear();
    void insert(int val);
    void erase(int val);
    bool empty();
    int size();
    int find(int val);

    void show_result();
};

} // structures

#endif //AVL_TREE_H
