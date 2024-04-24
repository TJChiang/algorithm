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

BinaryTree::BinaryTree(TreeNode* root) {
    this->root = root;
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

void BinaryTree::levelorder_traversal(TreeNode* cur, std::vector<int>& vec) {
    std::queue<TreeNode*> que;
    if (cur != nullptr) que.push(cur);

    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            // 為了顯示 null 值
            if (node == nullptr) {
                vec.push_back(INT_NULL_);
                continue;
            } else {
                vec.push_back(node->val);
            }
            if (node->left == nullptr && node->right == nullptr) continue;
            que.push(node->left);
            que.push(node->right);
        }
    }
}

void BinaryTree::show_result(const std::vector<int>& result) {
    for (int const it : result) {
        if (it == INT_NULL_) {
            std::cout << "null ";
        } else {
            std::cout << it << " ";
        }
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

std::vector<int> BinaryTree::get_levelorder_result() {
    TreeNode* p = root;
    std::vector<int> result;
    levelorder_traversal(p, result);

    return result;
}
