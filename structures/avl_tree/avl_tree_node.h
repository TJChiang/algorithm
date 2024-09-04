//
// Created by nature on 2024/4/25.
//

#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H

namespace structures {

class AvlTreeNode {
public:
    AvlTreeNode* left;
    AvlTreeNode* right;

    int height;
    int val;

    AvlTreeNode();
    explicit  AvlTreeNode(int val);
    AvlTreeNode(int val, AvlTreeNode* left, AvlTreeNode* right);
};

} // structures

#endif //AVL_TREE_NODE_H
