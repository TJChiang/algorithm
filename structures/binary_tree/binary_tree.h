#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <vector>
#include "tree_node.h"

namespace structures {
    class BinaryTree
    {
    private:
        TreeNode* root;
        int size = 0;
        void inorder_traversal(TreeNode* cur, std::vector<int>& vec);
        void preorder_traversal(TreeNode* cur, std::vector<int>& vec);
        void postorder_traversal(TreeNode* cur, std::vector<int>& vec);
        void levelorder_traversal(TreeNode* cur, std::vector<int>& vec);
    public:
        explicit BinaryTree(std::vector<int> input);
        explicit BinaryTree(TreeNode* root);
        ~BinaryTree();
        TreeNode* get_root() {
            return root;
        };
        static void show_result(const std::vector<int>& result);
        std::vector<int> get_inorder_result();
        std::vector<int> get_preorder_result();
        std::vector<int> get_postorder_result();
        std::vector<int> get_levelorder_result();
    };
}

#endif
