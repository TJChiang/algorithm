# 77. Combinations

###### tags: `回溯`、`back tracking`
<br>

[LeetCode](https://leetcode.com/problems/combinations/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0077.%E7%BB%84%E5%90%88.md)

給定兩個整數 `n` 和 `k` ，回傳 1 到 `n` 中所有可能的 `k` 個數的組合。

答案允許任意排序

**範例 1**
```
Input: n = 4, k = 2
Output: [[1,2], [1,3], [1,4], [2,3], [2,4], [3,4]]
Explanation: 4 個數字，每兩個一組，共有 6 種組合。
組合表示相同數字但不同排序視為同一組，例如：[1,2] 和 [2,1] 視為向同組合
```

**範例 2**
```
Input: n = 1, k = 1
Output: [[1]]
```

**限制邊界**
- 1 <= n <= 20
- 1 <= k <= n

## 思路

以範例 1 作為說明的參數，可以觀察到當以下情況

第一個數字為 1 ，第二個數字只有 2, 3, 4 可形成組合；
接下來第一個數字為 2 ， 第二個數字只能是 3, 4，接著以此類推...
因此，需要設定一個起始值，防止重複組合出現。

### 回溯法重點

1. 遞迴函式返回值與參數
    - 設定結果參數
    - 設定單一集合參數
    - 設定起始值
2. 終止條件
   - 若完成單一集合，則將集合放進結果參數
   - 完成後，該層邏輯終止
3. 單層搜尋邏輯
   - 目的為完成每個子集合，並將完成的子集合放進結果參數
   - ```
       for () {
         處理節點
         遞迴
         回溯，撤銷處理結果
       }
     ```
     
### 優化

相同組合、不限排序都視為同一組，因此我們要去除重複的組合

1. 子集合已存在的元素個數： len(path)
2. 子集合還需要幾個元素： k - len(path)
3. 所有可用元素中還剩下個數： n - i
4. 所有剩餘可用元素 >= 子集合所需元素數 
5. 起始位置： i <= n - (k - len(path)) + 1

### Solution 1

```go
package _077_Combinations

// 結果集合
var res [][]int

// 子集合
var path []int

func combine(n int, k int) [][]int {
   res, path = make([][]int, 0), make([]int, 0, k)
   backtracking(n, k, 1)
   return res
}

// startIndex 起始值
func backtracking(n int, k int, startIndex int) {
	// 設定終止條件
   if len(path) == k {
      tmp := make([]int, k)
      copy(tmp, path)
      res = append(res, tmp)
      return
   }
   for i := startIndex; i <= n; i++ {
      // 剪枝
      if i > n-(k-len(path))+1 {
        break
      }
	  
      path = append(path, i)
      backtracking(n, k, i+1)
      path = path[:len(path)-1]
   }
}
```

- 時間複雜度： O(n * 2^n)
- 空間複雜度： O(n)
