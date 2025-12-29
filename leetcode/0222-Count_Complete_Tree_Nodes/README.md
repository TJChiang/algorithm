# 222. Count Complete Tree Nodes

###### tags: `binary tree`
<br>

[LeetCode](https://leetcode.com/problems/count-complete-tree-nodes/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0222.%E5%AE%8C%E5%85%A8%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%8A%82%E7%82%B9%E4%B8%AA%E6%95%B0.md)

求出二元樹的節點數。

**範例 1**
```
Input: root = [1,2,3,4,5,6]
Output: 6
```

**範例 2**
```
Input: root = []
Output: 0
```

**範例 3**
```
Input: root = [1]
Output: 1
```

**限制邊界**
- The number of nodes in the tree is in the range [0, 5 * 10<sup>4</sup>].
- 0 <= Node.val <= 5 * 10<sup>4</sup>
The tree is guaranteed to be **complete**.

## 思路

### Solution 1


```CPP
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int leftNum = countNodes(root->left);   // 左
        int rightNum = countNodes(root->right); // 右
        return leftNum + rightNum + 1;  // 中
    }
};
```

- 時間複雜度：O(n)
- 空間複雜度：O(log n)
