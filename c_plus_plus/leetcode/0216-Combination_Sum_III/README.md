# 216. Combination Sum III

###### tags: `回溯`、`back tracking`

[LeetCode](https://leetcode.com/problems/combination-sum-iii/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0216.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CIII.md)

找出所有 k 個數的組合，並且組合中的所有數字之和為 n ，組合中只允許 1 ~ 9 的正整數，每種組合中不存在重複的數字。

說明：
- 所有數字都是 1 - 9 的正整數
- 不能包含重複的組合

**範例 1**
```
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
```

**範例 2**
```
Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
```

**範例 3**
```
Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9],
the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1,
there are no valid combination.
```

**限制邊界**
- 2 <= k <= 9
- 1 <= <= 60

## 思路

### 回溯法重點
1. 遞迴函式參數
    - 全域總集合 result
    - 全域子集合 path
    - n
    - k
    - sum: 子集合數字總和 (可省略，用 n - i 做判斷)
    - startIndex: 目前起始數字
2. 終止條件
    - 子集合已達指定長度 k
    - 子集合長度為 k ，其中數字總和又剛好為 n ，則 result 儲存當前結果
3. 單層搜尋邏輯
    - 起始數字為 startIndex
    - 迴圈數字最大到 9
    - sum 往上加，子集合新增目前數字，執行判斷，若回溯則 sum - 1，子集合內容數減 1
    - ```
       for () {
         處理節點
         遞迴
         回溯，撤銷處理結果
       }
      ```

### 優化
當子集合總和 sum 超過 n ，後續的處理就沒有意義了，直接回溯，與 [077的回溯優化](../0077-Combinations/README.md#優化) 一樣，
當前數字 i <= 9 - (k - len(path)) + 1 ，大於此數的單層邏輯沒有意義

### Solution 1

```go
package _216_Combination_Sum_III

var (
    path []int
    result [][]int
)

func combinationSum3(k int, n int) [][]int {
    result, path := make([][]int, 0), make([]int, 0, k)
    backtracking(k, n, 0, 1)
    return result
}

func backtracking(k int, n int, sum int, startIndex int) {
    // 優化
    if sum > n {
        return
    }
    if len(path) == k {
        if sum == n {
            tmp := make([]int, k)
            copy(tmp, path)
            result = append(result, tmp)
        }
        return
    }

	// 優化
    for i := startIndex; i <= 9 - (k - len(path)) + 1; i++ {
        sum += i
        path = append(path, i)
        backtracking(k, n, sum, i + 1)
        sum -= i
        path = path[:len(path) - 1]
    }
}
```

- 時間複雜度： O(n * 2^n)
- 空間複雜度： O(n)
