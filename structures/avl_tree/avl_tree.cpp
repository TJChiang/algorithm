//
// Created by nature on 2024/4/25.
// https://github.com/KadirEmreOto/AVL-Tree

#include "avl_tree.h"

#include <iostream>
#include <vector>

namespace structures {
    AvlTree::AvlTree() {
        root = nullptr;
        _size = 0;
    }

    AvlTree::AvlTree(int val) {
        root = new AvlTreeNode(val);
        _size = 1;
    }

    AvlTree::~AvlTree() {
        clear();
    }

    void AvlTree::clear() {
        std::vector<AvlTreeNode*> stack;

        if (root != nullptr) stack.push_back(root);

        while (!stack.empty()) {
            const AvlTreeNode* node = stack.back();
            stack.pop_back();

            if (node->left) stack.push_back(node->left);
            if (node->right) stack.push_back(node->right);

            delete node;
        }

        root = nullptr;
        _size = 0;
    }

    bool AvlTree::empty() {
        return root == nullptr;
    }

    int AvlTree::size() {
        return _size;
    }

    void AvlTree::show_result() {
        std::cout << "Hi" << std::endl;
    }

} // structures
