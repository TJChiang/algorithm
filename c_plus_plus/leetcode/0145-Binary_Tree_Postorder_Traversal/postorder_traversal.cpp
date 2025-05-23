#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution1 {
    public:
        void traversal(TreeNode* cur, vector<int>& vec) {
            if (cur == NULL) return;
            traversal(cur->left, vec);
            traversal(cur->right, vec);
            vec.push_back(cur->val);
        }
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> result;
            traversal(root, result);
            return result;
        }
};

class Solution2 {
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> result;
            stack<TreeNode*> st;

            if (root == NULL) return result;
            st.push(root);
            while (!st.empty()) {
                TreeNode* node = st.top();
                st.pop();
                result.push_back(node->val);
                if (node->left) st.push(node->left);
                if (node->right) st.push(node->right);
            }

            reverse(result.begin(), result.end());
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

    // result = sol1.postorderTraversal(root);
    result = sol2.postorderTraversal(root);

    for (auto it = result.begin(); it != result.end(); it++) {
        cout << *it << "  ";
    }
    cout << endl;

    return 0;
}
