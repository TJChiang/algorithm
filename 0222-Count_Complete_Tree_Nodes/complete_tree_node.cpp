#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int const _INT_NULL_ = INT_MIN;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {};
};

class BinaryTree
{
private:
    TreeNode* root;
    int size = 0;

    void inorder_traversal(TreeNode* cur, std::vector<int>& vec)
    {
        if (cur == NULL) return;
        inorder_traversal(cur->left, vec);
        vec.push_back(cur->val);
        inorder_traversal(cur->right, vec);
    }
public:
    BinaryTree(std::vector<int> input)
    {
        if (input.size() == 0) {
            return;
        }

        std::queue<TreeNode*> queue;
        root = new TreeNode(input[0]);
        size++;
        queue.push(root);

        int i = 1;
        while (i < input.size()) {
            TreeNode* node = queue.front();
            queue.pop();
            if (i < input.size() && input[i] != _INT_NULL_) {
                node->left = new TreeNode(input[i]);
                queue.push(node->left);
                size++;
            }
            i++;

            if (i < input.size() && input[i] != _INT_NULL_) {
                node->right = new TreeNode(input[i]);
                queue.push(node->right);
                size++;
            }
            i++;
        }
    }
    ~BinaryTree() {}

    TreeNode* get_root()
    {
        TreeNode* p = root;
        return p;
    }

    void show_inorder()
    {
        std::vector<int> result = get_inorder_result();

        for (auto it : result) {
            std::cout << it << " ";
        }

        return;
    }

    std::vector<int> get_inorder_result()
    {
        TreeNode* p = root;
        std::vector<int> result;
        inorder_traversal(p, result);

        return result;
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int leftNum = countNodes(root->left);   // 左
        int rightNum = countNodes(root->right); // 右
        return leftNum + rightNum + 1;  // 中
    }
};

int main()
{
    Solution sol;
    BinaryTree binary_tree(vector<int> {1,2,3,4,5,6});
    int result = sol.countNodes(binary_tree.get_root());

    cout << result << endl;
    return 0;
}