# 102. Binary Tree Level Order Traversal

###### tags: `binary tree`、`level order traverse`
<br>

[LeetCode](https://leetcode.com/problems/binary-tree-level-order-traversal/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.md#102%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86)

給定一個 `root` 二元樹，按照層序遍歷回傳結點值。

(例如從左到右，一層接著一層)

**範例 1**
```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```

**範例 2**
```
Input: root = [1]
Output: [[1]]
```

**範例 3**
```
Input: root = []
Output: []
```

**限制邊界**
- 二元樹節點數介於 [0, 2000]
- 1000 <= Node.val <= 1000

## 思路

層序遍歷是根據階層，從左到右依序輸出，需要使用 Queue 實現先進先出的方式。

這種方式就是廣度優先遍歷。

### Solution 1

層序遍歷

每次造訪時，就把 queue 裡的值依序放入 result 。之後，再把下一層的節點，從左到右放入 queue，這樣 queue 裡面就只有該層的值，直到 queue 為空為止。

```CPP
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            vector<int> temp;
            int size = que.size();
            // que.size() 會不斷變化，所以要用 size
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(temp);
        }

        return result;
    }
}
```

### Solution 2

遞歸法

先處理左邊的值再處理右邊的值。第一次造訪該層時(result.size() == depth)，要先建立一個空 vector 以便填入後續的值。每層處理完之後，depth + 1 再處理下一層，直到節點為 NULL 為止。

終止條件： cur == NULL

```CPP
class Solution {
public:
    void order(TreeNode* cur, vector<vector<int>>& result, int depth)
    {
        if (cur == NULL) return;
        if (result.size() == depth) result.push_back(vector<int>());
        result[depth].push_back(cur->val);
        order(cur->left, result, depth + 1);
        order(cur->right, result, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int depth = 0;
        order(root, result, depth);
        return result;
    }
}
```
