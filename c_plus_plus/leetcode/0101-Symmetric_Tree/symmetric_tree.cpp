#include <iostream>
#include "../../structures/binary_tree/tree_node.h"
#include "../../structures/binary_tree/binary_tree.h"

using namespace std;

class Solution {
private:
    bool compare(structures::TreeNode const* left, structures::TreeNode const* right) {
        if (left == nullptr && right != nullptr) return false;
        else if (left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right == nullptr) return true;
        else if (left->val != right->val) return false;

        return compare(left->right, right->left) && compare(left->left, right->right);
    }
public:
    bool isSymmetric(structures::TreeNode const* root) {
        if (root == nullptr) return true;
        return compare(root->left, root->right);
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    structures::BinaryTree ex1(vector<int> {1,2,2,3,4,4,3});
    bool const result1 = sol.isSymmetric(ex1.get_root());
    structures::BinaryTree ex2(vector<int> {1,2,2, INT_NULL_,3,INT_NULL_,3});
    bool const result2 = sol.isSymmetric(ex2.get_root());

    cout << "result1: ";
    if (result1) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    cout << "result2: ";
    if (result2) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
