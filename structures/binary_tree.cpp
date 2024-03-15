#include <iostream>
#include <vector>
#include <queue>
#include "binary_tree.h"
#include "tree_node.h"

BinaryTree::BinaryTree(std::vector<int> input) {
    if (input.empty()) {
        return;
    }

    std::queue<TreeNode*> queue;
    root = new TreeNode(input[0]);
    size++;
    queue.push(root);

    int i = 1;
    while (i < input.size()) {
        TreeNode* node = queue.front();
        queue.pop();
        if (i < input.size() && input[i] != INT_NULL_) {
            node->left = new TreeNode(input[i]);
            queue.push(node->left);
            size++;
        }
        i++;

        if (i < input.size() && input[i] != INT_NULL_) {
            node->right = new TreeNode(input[i]);
            queue.push(node->right);
            size++;
        }
        i++;
    }
}

BinaryTree::~BinaryTree() = default;

void BinaryTree::inorder_traversal(TreeNode* cur, std::vector<int>& vec) {
    if (cur == nullptr) return;
    inorder_traversal(cur->left, vec);
    vec.push_back(cur->val);
    inorder_traversal(cur->right, vec);
}

void BinaryTree::preorder_traversal(TreeNode* cur, std::vector<int>& vec) {
    if (cur == nullptr) return;
    vec.push_back(cur->val);
    preorder_traversal(cur->left, vec);
    preorder_traversal(cur->right, vec);
}

void BinaryTree::postorder_traversal(TreeNode* cur, std::vector<int>& vec) {
    if (cur == nullptr) return;
    postorder_traversal(cur->left, vec);
    postorder_traversal(cur->right, vec);
    vec.push_back(cur->val);
}

void BinaryTree::show_result(const std::vector<int>& result) {
    for (int const it : result) {
        std::cout << it << " ";
    }
}

std::vector<int> BinaryTree::get_inorder_result() {
    TreeNode* p = root;
    std::vector<int> result;
    inorder_traversal(p, result);

    return result;
}

std::vector<int> BinaryTree::get_preorder_result() {
    TreeNode* p = root;
    std::vector<int> result;
    preorder_traversal(p, result);

    return result;
}

std::vector<int> BinaryTree::get_postorder_result() {
    TreeNode* p = root;
    std::vector<int> result;
    postorder_traversal(p, result);

    return result;
}
