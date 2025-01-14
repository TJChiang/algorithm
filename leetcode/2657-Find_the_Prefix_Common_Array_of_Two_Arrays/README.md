# 2657. Find the Prefix Common Array of Two Arrays

###### tags: `array`、`hash table`、`bit manipulation`
<br>

[LeetCode](https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/)

Problem Context

**範例 1**
```
Input: A = [1,3,2,4], B = [3,1,2,4]
Output: [0,2,3,4]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.
```

**範例 2**
```
Input: A = [2,3,1], B = [3,1,2]
Output: [0,1,3]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: only 3 is common in A and B, so C[1] = 1.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
```

**限制邊界**
- 1 <= A.length == B.length == n <= 50
- 1 <= A[i], B[i] <= n
- It is guaranteed that A and B are both a permutation of n integers.

## 思路

### Frequency Counting

- 時間複雜度： O(n)
- 空間複雜度： O(n)

### Bitmasking

- 時間複雜度： O(n)
- 空間複雜度： O(1)
