//
// Created by nature on 2024/4/25.
//

#include "avl_tree_node.h"

namespace structures {
    AvlTreeNode::AvlTreeNode() {
        height = 1;
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    AvlTreeNode::AvlTreeNode(int val) {
        this->val = val;
        height = 1;
        left = nullptr;
        right = nullptr;
    }

    AvlTreeNode::AvlTreeNode(int val, AvlTreeNode *left, AvlTreeNode *right) {
        this->val = val;
        this->left = left;
        this->right = right;
        this->height = 1;
    }
} // structures
