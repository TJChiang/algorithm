# LeetCode-exercise

> tags: `String`、`Array`、`Binary Search`、`雙指針`、`區間`、`模擬`、`滑動窗口`、`Map`

## Problem
- [0001.Two Sum](leetcode/0001-Two_Sum/README.md)
- [0007.Reverse Integer](leetcode/0007-Reverse_Integer/README.md)
- [0024.Swap Nodes in Pairs](leetcode/0024-Swap_Nodes_in_Pairs/README.md)
- [0027.Remove Element](leetcode/0027-Remove_Element/README.md)
- [0028.Implement strStr](leetcode/0028-Implement_strStr/README.md)
- [0059.Spiral Matrix II](leetcode/0059-Spiral_Matrix_II/README.md)
- [0094.Binary Tree Inorder Traversal](leetcode/0094-Binary_Tree_Inorder_Traversal/README.md)
- [0101.Symmetric Tree](leetcode/0101-Symmetric_Tree/README.md)
- [0102.Binary Tree Level Order Traversal](leetcode/0102-Binary_Tree_Level_Order_Traversal/README.md)
- [0104.Maximum Depth of Binary Tree](leetcode/0104-Maximum_Depth_of_Binary_Tree/README.md)
- [0111.Minimum Depth of Binary Tree](leetcode/0111-Minimum_Depth_of_Binary_Tree/README.md)
- [0144.Binary Tree Preorder Traversal](leetcode/0144-Binary_Tree_Preorder_Traversal/README.md)
- [0145.Binary Tree Postorder Traversal](leetcode/0145-Binary_Tree_Postorder_Traversal/README.md)
- [0150.Evaluate Reverse Polish Notation](leetcode/0150-Evaluate_Reverse_Polish_Notation/README.md)
- [0151.Reverse Words in a String](leetcode/0151-Reverse_Words_in_a_String/README.md)
- [0209.Minimum Subarray Sum](leetcode/0209-Minimum_Subarray_Sum/README.md)
- [0225.Implement Stack using Queue](leetcode/0225-Implement_Stack_using_Queues/README.md)
- [0226.Invert Binary Tree](leetcode/0226-Invert_Binary_Tree/README.md)
- [0232.Implement Queue using Stack](leetcode/0232-Implement_Queue_using_Stacks/README.md)
- [0239.Sliding Window Maximum](leetcode/0239-Sliding_Window_Maximum/README.md)
- [0344.Reverse String](leetcode/0344-Reverse_String/README.md)
- [0347.Top K Frequent Elements](leetcode/0347-Top_K_Frequent_Elements/README.md)
- [0541.Reverse String II](leetcode/0541-Reverse_String_II/README.md)
- [0704.Binary Search](leetcode/0704-Binary_Search/README.md)
- [0977.Squares of a Sorted Array](leetcode/0977-Squares_of_a_Sorted_Array/README.md)

## Python

### Docker 執行環境

1. 進入 container 執行 python

```bash
docker compose run --rm -it python bash
```

2. 建立虛擬環境

```bash
python3 -m venv .venv
```

3. 啟動虛擬環境

```bash
source .venv/bin/activate
```

4. pip 安裝 packages

```bash
pip install ...
pip install -r requirements.txt
```

5. 關閉 venv

```bash
deactivate
```

### Docker 開發環境

`cmd + shift + P` 輸入 `Dev Containers: Open Folder in Container...` ，選擇 python

### TroubleShooting

#### Exclude volumes

- [type: tmpfs](https://stackoverflow.com/a/71911280)
- [simpler way](https://stackoverflow.com/a/37898591)
