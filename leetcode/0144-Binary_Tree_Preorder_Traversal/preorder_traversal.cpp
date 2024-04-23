#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 遞迴
class Solution1 {
    public:
        void traversal(TreeNode* cur, vector<int>& vec) {
            if (cur == NULL) return;
            vec.push_back(cur->val);
            traversal(cur->left, vec);
            traversal(cur->right, vec);
        }
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> result;
            traversal(root, result);
            return result;
        }
};

// 迭代
class Solution2 {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            stack<TreeNode*> st;
            vector<int> result;

            if (root == NULL) return result;
            st.push(root);
            while (!st.empty()) {
                TreeNode* node = st.top();
                st.pop();
                result.push_back(node->val);
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
            }

            return result;
        }
};

int main(int argc, char* argv[])
{
    Solution1 sol1;
    Solution2 sol2;
    vector<int> result;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // result = sol1.preorderTraversal(root);
    result = sol2.preorderTraversal(root);

    for (auto it = result.begin(); it != result.end(); it++) {
        cout << *it << "  ";
    }
    cout << endl;

    return 0;
}