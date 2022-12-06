# 94. Binary Tree Inorder Traversal

###### tags: `inorder traverse`、`binary tree`、`中序遍歷`
<br>

[LeetCode](https://leetcode.com/problems/binary-tree-inorder-traversal/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%BF%AD%E4%BB%A3%E9%81%8D%E5%8E%86.md)

給定一個二叉樹 `root` ，透過中序遍歷，回傳節點的值

**範例 1**

```
Input: root = [1,null,2,3]
Output: [1,3,2]
```

**範例 2**

```
Input: root = []
Output: []
```

**範例 3**

```
Input: root = [1]
Output: [1]
```

**限制邊界**
- 每個節點的值在 `[0, 100]` 之間
- `-100 <= Node.val <= 100`

## 思路

### Solution 1 - 遞迴

```CPP
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
```
