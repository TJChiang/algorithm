#ifndef TREE_NODE_H
#define TREE_NODE_H

#define INT_NULL_ INT_MIN

namespace structures {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        explicit TreeNode(int const x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int const x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
        ~TreeNode()
        {
            delete left;
            delete right;
        }
    };
}

#endif
