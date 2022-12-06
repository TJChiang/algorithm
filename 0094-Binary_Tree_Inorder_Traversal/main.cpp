#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        void traversal(TreeNode* cur, vector<int>& vec) {
            if (cur == NULL) return;
            traversal(cur->left, vec);
            vec.push_back(cur->val);
            traversal(cur->right, vec);
        }
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            traversal(root, result);
            return result;
        }
};

int main(int argc, char* argv[])
{
    Solution sol;
    vector<int> result;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    result = sol.inorderTraversal(root);

    for (auto it = result.begin(); it != result.end(); it++) {
        cout << *it << "  ";
    }
    cout << endl;

    return 0;
}
