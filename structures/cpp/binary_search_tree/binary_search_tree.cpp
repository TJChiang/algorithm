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

    TreeNode* BinarySearchTree::_insert(TreeNode* root, int const val) {
        if (root == nullptr) return new TreeNode(val);

        if (val < root->val)
            root->left = _insert(root->left, val);
        else if (val > root->val)
            root->right = _insert(root->right, val);

        // no duplicate value, so return root when val is equal to root->val
        return root;
    }

    void BinarySearchTree::insert(int val) {
        root = _insert(root, val);
    }

    TreeNode* BinarySearchTree::_find_min_node(TreeNode *node) {
        if (node == nullptr) return node;
        while (node->left != nullptr) {
            node = node->left;
        }

        return node;
    }

    TreeNode* BinarySearchTree::_remove(TreeNode *node, int val) {
        if (node == nullptr) return nullptr;

        if (node->val == val) {
            // 找到指定的值
            // 如果是子節點，直接刪除即可
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // 只有左節點
            else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            // 只有右節點
            else if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            // 左右節點都有
            else {
                TreeNode* minNode = _find_min_node(node->right);
                minNode->left = node->left;
                TreeNode* temp = node;
                node = node->right;
                delete temp;
                return node;
            }
        }

        if (val < node->val) node->left = _remove(node->left, val);
        if (val > node->val) node->right = _remove(node->right, val);

        return node;
    }

    void BinarySearchTree::remove(int val) {
        root = _remove(root, val);
    }

    TreeNode *BinarySearchTree::find(int const val) const
    {
        TreeNode* cur = root;
        while (cur != nullptr) {
            if (cur->val == val) return cur;
            if (val > cur->val) cur = cur->right;
            else cur = cur->left;
        }

        return nullptr;
    }

    int BinarySearchTree::max_value() const
    {
        if (root == nullptr) return INT_NULL_;

        const TreeNode* cur = root;
        while (cur->right != nullptr) {
            cur = cur->right;
        }

        return cur->val;
    }

    int BinarySearchTree::min_value() const
    {
        if (root == nullptr) return INT_NULL_;

        const TreeNode* cur = root;
        while (cur->left != nullptr) {
            cur = cur->left;
        }

        return cur->val;
    }

    void BinarySearchTree::_clear(const TreeNode* node) {
        if (node == nullptr) return;

        if (node->left != nullptr) _clear(node->left);
        if (node->right != nullptr) _clear(node->right);
        delete node;
        node = nullptr;
    }

    void BinarySearchTree::clear() const
    {
        _clear(root);
    }

    bool BinarySearchTree::empty() const
    {
        return root == nullptr;
    }
} // structures
