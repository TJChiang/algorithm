#include <iostream>
#include <stack>
#include <queue>
#include "binary_tree/tree_node.h"

using namespace std;

class Solution {
public:
    structures::TreeNode* invertTreeRecursion(structures::TreeNode* root) {
        if (root == nullptr) return root;
        swap(root->left, root->right);
        invertTreeRecursion(root->left);
        invertTreeRecursion(root->right);
        return root;
    }

    structures::TreeNode* invertTreeInteration(structures::TreeNode* root) {
        if (root == nullptr) return root;
        stack<structures::TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            structures::TreeNode* node = st.top();
            st.pop();
            swap(node->left, node->right);
            if (node->right != nullptr) st.push(node->right);
            if (node->left != nullptr) st.push(node->left);
        }

        return root;
    }
};

int main()
{
    structures::TreeNode* root = new structures::TreeNode(
        4,
        new structures::TreeNode(2, new structures::TreeNode(1), new structures::TreeNode(3)),
        new structures::TreeNode(7, new structures::TreeNode(6), new structures::TreeNode(9))
    );
    Solution* sol = new Solution();
    structures::TreeNode* result = sol->invertTreeRecursion(root);
    // structures::TreeNode* result = sol->invertTreeInteration(root);

    queue<structures::TreeNode*> que;
    que.push(result);

    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            structures::TreeNode* node = que.front();
            que.pop();
            cout << node->val << " ";
            if (node->left != nullptr) que.push(node->left);
            if (node->right != nullptr) que.push(node->right);
        }
    }

    return 0;
}
