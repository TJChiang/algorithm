//
// Created by nature on 2024/4/26.
//

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "binary_tree/tree_node.h"
#define INT_NULL_ INT_MIN

namespace structures {

class BinarySearchTree {
    TreeNode* root;
    TreeNode* _insert(TreeNode* node, int val);
    TreeNode* _remove(TreeNode* node, int val);
    TreeNode* _find_min_node(TreeNode* node);
    void _clear(TreeNode* node);
public:
    BinarySearchTree();
    explicit BinarySearchTree(int val);
    ~BinarySearchTree() {
        clear();
    };

    void insert(int val);
    void remove(int val);
    TreeNode* find(int val);
    int max_value();
    int min_value();
    void clear();
    bool empty();
};

} // structures

#endif //BINARY_SEARCH_TREE_H
