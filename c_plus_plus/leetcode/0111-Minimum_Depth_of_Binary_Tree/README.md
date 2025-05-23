# 111. Minimum Depth of Binary Tree

###### tags: `binary tree`
<br>

[LeetCode](https://leetcode.com/problems/minimum-depth-of-binary-tree/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0111.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%B0%8F%E6%B7%B1%E5%BA%A6.md)

有一個二元樹 `root` ，回傳最小深度。

二元樹的`最大深度`是根節點到最遠節點，最長路徑上的節點數。

**範例 1**

```
      3
    /   \
   9     20
        / \
       15  7
```

```
Input: root = [3,9,20,null,null,15,7]
Output: 2
```

**範例 2**

```
   2
    \
     3
      \
       4
        \
         5
          \
           6
```

```
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
```

**限制邊界**
- 二元樹的節點數 [0, 100000]
- -1000 <= Node.val <= 1000

## 思路

- 葉子節點：沒有子節點的節點稱為葉子節點 (leaf)
- 深度：根節點經由最簡單路徑，到該節點的 `路徑數` 或是 `節點數` (從 0 開始 / 從 1 開始)
- 高度：該節點經由最長簡單路徑，到葉子節點的 `路徑數` 或是 `節點數` (從 0 開始 / 從 1 開始)
- 二元樹的深度：根節點 (root) 經由最簡單路徑，到最近葉子節點的 `路徑數` 或是 `節點數` ，等於二元樹的高度

### 遞迴

1. 確定輸入與輸出值：

    ```go
    func getDepth(node *TreeNode)
    ```

2. 設定終止條件：

    ```go
    if node == nil {
        return 0
    }
    ```

3. 單層邏輯：

    如果左子節點為空，右子節點不為空，則回傳右子節點深度 + 1；反之，如果左子節點不回空，右子節點為空，則回傳左子節點深度 + 1。

    若兩者皆不為空，則取左右子節點深度的最小值 + 1。

    +1 目的為包含當前節點

    ```go
    leftDepth, rightDepth := getDepth(node.Left), getDepth(node.Right)
    if node.Left == nil &&  node.Right != nil {
        return rightDepth + 1
    }
    if node.Left != nil &&  node.Right == nil {
        return leftDepth + 1
    }
    return min(leftDepth, rightDepth) + 1
    ```

經過整理後：

```go
func minDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }

    leftDepth, rightDepth := getDepth(root.Left), getDepth(root.Right)
    if root.Left == nil && root.Right != nil {
        return rightDepth + 1
    }
    if root.Left != nil && root.Right == nil {
        return leftDepth + 1
    }
    return 1 + min(leftDepth, rightDepth)
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```

### 迭代

層序遍歷，用 queue 儲存每一層節點進行遍歷，
雖然 queue 可能會一直存入節點，但有先記錄該層的節點數 `size := len(queue)` ，加上從 queue 的最前面 pop 出節點，
因此只會遍歷該層的節點

每一層邏輯：
1. 先 pop 出 queue 最前面的 node
2. **如果為葉子節點，表示找到最小深度，回傳其深度**
3. 如果非葉子節點，則將存在的子節點存入 queue 中

**Note: 每一層開始前會先 `result++` ，表示已經進入下一層了**

```go
func minDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }

    queue := make([]*TreeNode, 0)
    queue = append(queue, root)

    result := 0

    for len(queue) > 1 {
        size := len(queue)
        result++
        for i := 0; i < size; i++ {
            node := queue[0]
            queue = queue[1:]
            if node.Left == nil && node.Right == nil {
                return result
            }
            if node.Left != nil {
                queue = append(queue, node.Left)
            }
            if node.Right != nil {
                queue = append(queue, node.Right)
            }
        }
    }

    return result
}
```
