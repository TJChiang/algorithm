#include <iostream>
#include <vector>
#include "../../structures/tree_node.h"
#include "../../structures/binary_tree.h"

using namespace std;

class Solution {
public:
    void traversal_expend(TreeNode* cur, vector<int> path, vector<string>& result) {
        if (cur->left == nullptr && cur->right == nullptr) {
            string subPath;
            for (int i = 0; i < path.size() - 1; i++) {
                subPath += to_string(path[i]);
                subPath += "->";
            }
            subPath += to_string(subPath[path.size() - 1]);
            result.push_back(subPath);
            return;
        }
        if (cur->left) {
            traversal_expend(cur->left, path, result);
            path.pop_back();
        }
        if (cur->right) {
            traversal_expend(cur->right, path, result);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths_expend(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if (root == nullptr) return result;
        traversal_expend(root, path, result);
        return result;
    }

    void traversal(TreeNode* cur, string path, vector<string>& result) {
        path += to_string(cur->val);
        if (cur->left == nullptr && cur->right == nullptr) {
            result.push_back(path);
            return;
        }
        if (cur->left) traversal(cur->left, path + "->", result);
        if (cur->right) traversal(cur->right, path + "->", result);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        if (root == nullptr) return result;
        traversal(root, path, result);
        return result;
    }
};

int main()
{
    vector<BinaryTree> questions = {
            BinaryTree(vector<int> {1, 2, 3, INT_NULL_, 5}),
            BinaryTree(vector<int> {1}),
    };
    Solution sol;

    for (auto qs : questions) {
        vector<string> result = sol.binaryTreePaths(qs.get_root());
        for (auto res : result) {
            cout << res << ",";
        }
        cout << endl;
    }

    return 0;
}
