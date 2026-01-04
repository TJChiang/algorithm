#include <vector>
#include <iostream>
#include "binary_tree/tree_node.h"
#include "binary_tree/binary_tree.h"

using namespace std;

class Solution {
public:
    int getHeight(structures::TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int left = getHeight(node->left);
        if (left == -1) return -1;
        int right = getHeight(node->right);
        if (right == -1) return -1;

        return abs(left - right) > 1 ? -1 : 1 + max(left, right);
    }
    bool isBalanced(structures::TreeNode* root) {
        return getHeight(root) != -1;
    }
};

int main()
{
    Solution sol;
    vector<structures::BinaryTree> questions = {
            structures::BinaryTree(vector<int> {3, 9, 20, INT_NULL_, INT_NULL_, 15, 7}),
            structures::BinaryTree(vector<int> {1, 2, 2, 3, 3, INT_NULL_, INT_NULL_, 4, 4}),
            structures::BinaryTree(vector<int> {}),
    };

    for (auto question : questions) {
        string result = sol.isBalanced(question.get_root()) ? "true" : "false";
        cout << result << endl;
    }

    return 0;
}
