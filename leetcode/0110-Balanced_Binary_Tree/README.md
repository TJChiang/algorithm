# 110. Balanced Binary Tree

###### tags: `binary tree`、`二元樹`
<br>

[LeetCode](https://leetcode.com/problems/balanced-binary-tree/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0110.%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91.md)

檢查給定的二元樹是否為一個高度平衡的二元樹。

平衡二元樹：每個節點的兩個子樹深度相差不超過 1。

**範例 1**

![110_1](balance_1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: true
```

**範例 2**

![110_2](balance_2.jpg)

```
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
```

**範例 3**

```
Input: root = []
Output: true
```

**限制邊界**
- The number of nodes in the tree is in the range [0, 5000].
- -10<sup>4</sup> <= Node.val <= 10<sup>4</sup>

## 思路

- 葉子節點：沒有子節點的節點稱為葉子節點 (leaf)
- 深度：根節點經由最簡單路徑，到該節點的 `路徑數` 或是 `節點數` (從 0 開始 / 從 1 開始)
- 高度：該節點經由最長簡單路徑，到葉子節點的 `路徑數` 或是 `節點數` (從 0 開始 / 從 1 開始)
- 二元樹的深度：根節點 (root) 經由最簡單路徑，到最近葉子節點的 `路徑數` 或是 `節點數` ，等於二元樹的高度

我們可以使用前序遍歷 (中左右) ，方便找出樹的高度。

### 遞歸

1. 確認函式參數

取得節點高度，若左右子節點高度相差超過 1 則回傳 -1

```c++
int getHeight(TreeNode* node)
```

2. 確認終止條件

遇到空節點則回傳 0 ，表示當前節點為根節點的樹高度為 0

```c++
if (node == nullptr) {
    return 0;
}
```

3. 確認單層邏輯

```c++
// 左
int leftHeight = getHeight(node->left);
if (leftHeight == -1) return -1;

// 右
int rightHeight = getHeight(node->right);
if (rightHeight == -1) return -1;

// 中
if (abs(leftHeight - rightHeight) > 1) {
    return -1;
}

// 當前節點最大高度
return 1 + max(leftHeight, rightHeight);
```

### Solution 1

```c++
class Solution {
public:
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int left = getHeight(node->left);
        if (left == -1) return -1;
        int right = getHeight(node->right);
        if (right == -1) return -1;

        return abs(left - right) > 1 ? -1 : 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};
```
