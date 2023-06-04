#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTreeRecursion(TreeNode* root) {
        if (root == NULL) return root;
        swap(root->left, root->right);
        invertTreeRecursion(root->left);
        invertTreeRecursion(root->right);
        return root;
    }

    TreeNode* invertTreeInteration(TreeNode* root) {
        if (root == NULL) return root;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            swap(node->left, node->right);
            if (node->right != NULL) st.push(node->right);
            if (node->left != NULL) st.push(node->left);
        }

        return root;
    }
};

int main()
{
    TreeNode* root = new TreeNode(
        4,
        new TreeNode(2, new TreeNode(1), new TreeNode(3)),
        new TreeNode(7, new TreeNode(6), new TreeNode(9))
    );
    Solution* sol = new Solution();
    TreeNode* result = sol->invertTreeRecursion(root);
    // TreeNode* result = sol->invertTreeInteration(root);

    queue<TreeNode*> que;
    que.push(result);

    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            cout << node->val << " ";
            if (node->left != NULL) que.push(node->left);
            if (node->right != NULL) que.push(node->right);
        }
    }

    return 0;
}