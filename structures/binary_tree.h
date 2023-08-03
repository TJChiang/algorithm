#ifndef structure_binary_tree_
#define structure_binary_tree_

#include <vector>
#include "tree_node.h"

class BinaryTree
{
private:
    TreeNode* root;
    int size = 0;
    void inorder_traversal(TreeNode* cur, std::vector<int>& vec);
public:
    explicit BinaryTree(std::vector<int> input);
    ~BinaryTree();
    TreeNode* get_root();
    void show_inorder();
    std::vector<int> get_inorder_result();
};

#endif