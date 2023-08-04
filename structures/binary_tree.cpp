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

void BinaryTree::show_inorder() {
    std::vector<int> result = get_inorder_result();

    for (auto it : result) {
        std::cout << it << " ";
    }
}

std::vector<int> BinaryTree::get_inorder_result() {
    TreeNode* p = root;
    std::vector<int> result;
    inorder_traversal(p, result);

    return result;
}
