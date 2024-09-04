//
// Created by nature on 2024/4/26.
//
// https://www.geeksforgeeks.org/deletion-in-binary-search-tree/
// https://hackmd.io/@Aquamay/H1nxBOLcO/https%3A%2F%2Fhackmd.io%2F%40Aquamay%2Fry-S8q2i_
// https://www.geeksforgeeks.org/introduction-to-binary-search-tree-data-structure-and-algorithm-tutorials/#1-searching-a-node-in-bst
// https://gist.github.com/mfaletti/4ea837b6ba48e2c95afd4f32af1612c4

#include "binary_search_tree.h"
#include "binary_tree/tree_node.h"

#include <vector>

namespace structures {
    BinarySearchTree::BinarySearchTree() {
        root = nullptr;
    }

    BinarySearchTree::BinarySearchTree(int const val) {
        root = new TreeNode(val);
    }

    void BinarySearchTree::_insert(TreeNode *node, int const val) {
        if (val < node->val) {
            if (node->left != nullptr)
                _insert(node->left, val);
            else
                node->left = new TreeNode(val);
        } else {
            if (node->right != nullptr)
                _insert(node->right, val);
            else
                node->right = new TreeNode(val);
        }
    }

    void BinarySearchTree::insert(int const val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return;
        }

        _insert(root, val);
    }

    TreeNode* BinarySearchTree::_find_min_node(TreeNode *node) {
        if (node == nullptr) return node;
        if (node->left == nullptr) return node;

        return _find_min_node(node->left);
    }

    void BinarySearchTree::_remove(TreeNode *node, int val) {
        if (node == nullptr) return;

        TreeNode* cur = node;

        // 持續往右搜尋
        if (val > node->val) {
            _remove(node->right, val);
            return;
        }
        // 持續往左搜尋
        if (val < node->val) {
            _remove(node->left, val);
            return;
        }

        // 找到指定的值
        // 如果是子節點，直接刪除即可
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
            return;
        }
        // 只有左節點
        if (node->right == nullptr) {
            const TreeNode* temp = node;
            node = node->left;
            delete temp;
            return;
        }

        // 只有右節點
        if (node->left == nullptr) {
            const TreeNode* temp = node;
            node = node->right;
            delete temp;
            return;
        }

        // 左右節點都有
        const TreeNode* temp = _find_min_node(node->right);
        node->val = temp->val;
     }

    void BinarySearchTree::remove(int val) {
        _remove(root, val);
    }

    TreeNode *BinarySearchTree::_find(TreeNode *node, int val) {
        TreeNode* cur = node;
        while (cur != nullptr) {
            if (cur->val == val) return cur;
            if (val > cur->val) cur = cur->right;
            else cur = cur->left;
        }

        return nullptr;
    }

    TreeNode *BinarySearchTree::find(int const val) {
        return _find(root, val);
    }

    int BinarySearchTree::max_value() {
        if (root == nullptr) return NULL;

        const TreeNode* cur = root;
        while (cur->right != nullptr) {
            cur = cur->right;
        }

        return cur->val;
    }

    int BinarySearchTree::min_value() {
        if (root == nullptr) return NULL;

        const TreeNode* cur = root;
        while (cur->left != nullptr) {
            cur = cur->left;
        }

        return cur->val;
    }

    void BinarySearchTree::clear() {
        std::vector<TreeNode*> stack;

        if (root != nullptr) stack.push_back(root);

        while (!stack.empty()) {
            const TreeNode* node = stack.back();
            stack.pop_back();

            if (node->left) stack.push_back(node->left);
            if (node->right) stack.push_back(node->right);

            delete node;
        }

        root = nullptr;
    }

    bool BinarySearchTree::empty() {
        return root == nullptr;
    }
} // structures
