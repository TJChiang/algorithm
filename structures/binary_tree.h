#ifndef _structure_binary_tree_
#define _structure_binary_tree_

#include <vector>
#include "tree_node.h"

class binary_tree
{
private:
    TreeNode* root;
    int size = 0;
    void inorder_traversal(TreeNode* cur, std::vector<int>& vec);
public:
    binary_tree(std::vector<int> input);
    ~binary_tree();
    void show_inorder();
    std::vector<int> get_inorder_result();
};

#endif