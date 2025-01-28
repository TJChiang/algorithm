# 2661. First Completely Painted Row or Column

###### tags: `array`、`hash table`、`martix`

[LeetCode](https://leetcode.com/problems/first-completely-painted-row-or-column/description/)

Problem Context

**範例 1**
```
Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
```

**範例 2**
```
Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
Output: 3
Explanation: The second column becomes fully painted at arr[3].
```

**限制邊界**
- m == mat.length
- n = mat[i].length
- arr.length == m * n
- 1 <= m, n <= 10<sup>5</sup>
- 1 <= m * n <= 10<sup>5</sup>
- 1 <= arr[i], mat[r][c] <= m * n
- All the integers of arr are **unique**.
- All the integers of mat are **unique**.

## 思路

### Brute Force

- 時間複雜度： O(m x n)
- 空間複雜度： O(m x n)
