# 1769. Minimum Number of Operations to Move All Balls to Each Box

###### tags: `array` 、 `string` 、 `prefix sum`
<br>

[LeetCode](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/)

Problem Context

...

...

**範例 1**
```
Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.
```

**範例 2**
```
Input: boxes = "001011"
Output: [11,8,5,4,3,4]
```

**限制邊界**

- n == boxes.length
- 1 <= n <= 2000
- boxes[i] is either '0' or '1'.

## 思路

### Brute Force

- 時間複雜度： O(n<sup>2</sup>)
- 空間複雜度： O(1)

### Sum of Left and Right Moves

- 時間複雜度： O(n)
- 空間複雜度： O(1)
