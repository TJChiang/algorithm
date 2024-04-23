#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 遍歷
class Solution1 {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> result;
            queue<TreeNode*> que;
            if (root != NULL) que.push(root);
            while (!que.empty()) {
                vector<int> temp;
                int size = que.size();
                // que.size() 會不斷變化，所以要用 size
                for (int i = 0; i < size; i++) {
                    TreeNode* node = que.front();
                    que.pop();
                    temp.push_back(node->val);
                    if (node->left) que.push(node->left);
                    if (node->right) que.push(node->right);
                }
                result.push_back(temp);
            }

            return result;
        }
};

// 遞歸
class Solution2 {
    public:
        void order(TreeNode* cur, vector<vector<int>>& result, int depth)
        {
            if (cur == nullptr) return;
            if (result.size() == depth) result.push_back(vector<int>());
            result[depth].push_back(cur->val);
            order(cur->left, result, depth + 1);
            order(cur->right, result, depth + 1);
        }
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> result;
            int depth = 0;
            order(root, result, depth);

            return result;
        }
};

int main(int argc, char* argv[])
{
    Solution1 sol1;
    Solution2 sol2;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result1 = sol1.levelOrder(root);
    vector<vector<int>> result2 = sol1.levelOrder(root);

    for (auto it = result2.begin(); it != result2.end(); it++) {
        for (auto index = (*it).begin(); index != (*it).end(); index++)
            cout << *index << " ";

        cout << endl;
    }

    return 0;
}