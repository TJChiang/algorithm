#include <iostream>
#include <vector>
#include <queue>
#include "../structures/binary_tree.h"
#include "../structures/tree_node.h"

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        const int left_max = maxDepth(root->left);
        const int right_max = maxDepth(root->right);

        return max(left_max, right_max) + 1;
    }

    int maxDepthIteration(TreeNode* root) {
        if (root == nullptr) return 0;
        int result = 0;
        queue<TreeNode*> node_queue;
        node_queue.push(root);

        while (!node_queue.empty()) {
            const int length = node_queue.size();
            result++;
            for (int i = 0; i < length; i++) {
                TreeNode* cur = node_queue.front();
                node_queue.pop();
                if (cur->left != nullptr) node_queue.push(cur->left);
                if (cur->right != nullptr) node_queue.push(cur->right);
            }
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
    BinaryTree bt1(vector<int>{3,9,20,INT_NULL_,INT_NULL_,15,7});
    BinaryTree bt2(vector<int>{1,INT_NULL_,2});
    Solution sol;
    cout << "Result1: " << sol.maxDepth(bt1.get_root()) << endl;
    cout << "Result2: " << sol.maxDepth(bt2.get_root()) << endl;

    return 0;
}
