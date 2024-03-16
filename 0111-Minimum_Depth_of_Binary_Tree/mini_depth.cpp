#include <iostream>
#include <queue>
#include "../structures/binary_tree.h"
#include "../structures/tree_node.h"

using namespace std;

class Solution {
public:
    // 後序
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        const int left_depth = minDepth(root->left);
        const int right_depth = minDepth(root->right);
        if (root->left != nullptr && root->right == nullptr) return left_depth + 1;
        if (root->left == nullptr && root->right != nullptr) return right_depth + 1;
        return min(left_depth, right_depth) + 1;
    }

    int minDepthIteration(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int depth = 0;

        while (!que.empty())
        {
            const int length = que.size();
            depth++;
            for (int i = 0; i < length; i++)
            {
                const TreeNode* node = que.front();
                que.pop();
                if (node->left == nullptr && node->right == nullptr) return depth;
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }
        }
        return depth;
    }
};

int main(int argc, char* argv[])
{
    BinaryTree bt1({3,9,20,INT_NULL_,INT_NULL_,15,7});
    BinaryTree bt2({2,INT_NULL_,3,INT_NULL_,4,INT_NULL_,5,INT_NULL_,6});
    Solution sol;

    cout << "Result1: " << sol.minDepth(bt1.get_root()) << endl;
    cout << "Result2: " << sol.minDepthIteration(bt2.get_root()) << endl;

    return 0;
}
