#include <vector>
#include <iostream>
#include <cstdlib>
#include "../../structures/tree_node.h"
#include "../../structures/binary_tree.h"

using namespace std;

class Solution {
public:
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int left = getHeight(node->left);
        if (left == -1) return -1;
        int right = getHeight(node->right);
        if (right == -1) return -1;

        return abs(left - right) > 1 ? -1 : 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};

int main()
{
    Solution sol;
    vector<BinaryTree> questions = {
            BinaryTree(vector<int> {3, 9, 20, INT_NULL_, INT_NULL_, 15, 7}),
            BinaryTree(vector<int> {1, 2, 2, 3, 3, INT_NULL_, INT_NULL_, 4, 4}),
            BinaryTree(vector<int> {}),
    };

    for (auto question : questions) {
        string result = sol.isBalanced(question.get_root()) ? "true" : "false";
        cout << result << endl;
    }

    return 0;
}
