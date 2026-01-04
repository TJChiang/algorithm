// https://leetcode.com/problems/merge-two-binary-trees/description/
// You are given two binary trees root1 and root2.
// Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
// You need to merge the two trees into a new binary tree.
// The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node.
// Otherwise, the NOT null node will be used as the node of the new tree.
#include <iostream>
#include <vector>
#include "binary_tree/tree_node.h"
#include "binary_tree/binary_tree.h"

class Solution {
public:
    structures::TreeNode* mergeTreesRecursion(structures::TreeNode* root1, structures::TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        // 前序
        root1->val += root2->val;
        root1->left = mergeTreesRecursion(root1->left, root2->left);
        root1->right = mergeTreesRecursion(root1->right, root2->right);
        return root1;
    }
};

int main() {
    structures::BinaryTree root1(std::vector<int> {1,3,2,5});
    structures::BinaryTree root2(std::vector<int> {2,1,3,INT_NULL_,4,INT_NULL_,7});
    Solution sol;
    structures::BinaryTree result(sol.mergeTreesRecursion(root1.get_root(), root2.get_root()));
    structures::BinaryTree::show_result(result.get_levelorder_result());
    std::cout << std::endl;
    return 0;
}
