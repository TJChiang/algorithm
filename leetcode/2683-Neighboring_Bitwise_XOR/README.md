# 2683. Neighboring Bitwise XOR

###### tags: `array`、`bit manipulation`

[LeetCode](https://leetcode.com/problems/neighboring-bitwise-xor/description/)

Problem Context


**範例 1**
```
Input: derived = [1,1,0]
Output: true
Explanation: A valid original array that gives derived is [0,1,0].
derived[0] = original[0] ⊕ original[1] = 0 ⊕ 1 = 1 
derived[1] = original[1] ⊕ original[2] = 1 ⊕ 0 = 1
derived[2] = original[2] ⊕ original[0] = 0 ⊕ 0 = 0
```

**範例 2**
```
Input: derived = [1,1]
Output: true
Explanation: A valid original array that gives derived is [0,1].
derived[0] = original[0] ⊕ original[1] = 1
derived[1] = original[1] ⊕ original[0] = 1
```

**範例 3**
```
Input: derived = [1,0]
Output: false
Explanation: There is no valid original array that gives derived.
```

**限制邊界**
- n == derived.length
- 1 <= n <= 10<sup>5</sup>
- The values in derived are either 0's or 1's

## 思路

### cumulative xor

- 時間複雜度： O(n)
- 空間複雜度： O(1)
