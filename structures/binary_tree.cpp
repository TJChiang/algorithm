#include <iostream>
#include <vector>
#include <queue>
#include "tree_node.h"

class binary_tree
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
    binary_tree(std::vector<int> input)
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
    ~binary_tree() {}

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
