#include <iostream>
#include <vector>
#include "../../structures/binary_tree/binary_tree.h"
#include "../../structures/binary_tree/tree_node.h"

class Solution {
public:
    int countNodes(structures::TreeNode* root) {
        if (root == nullptr) return 0;
        int leftNum = countNodes(root->left);   // 左
        int rightNum = countNodes(root->right); // 右
        return leftNum + rightNum + 1;  // 中
    }
};

int main()
{
    Solution sol;
    structures::BinaryTree binary_tree(std::vector<int> {1,2,3,4,5,6});
    const int result = sol.countNodes(binary_tree.get_root());

    std::cout << result << std::endl;
    return 0;
}
