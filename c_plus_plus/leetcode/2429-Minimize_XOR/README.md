# 2429. Minimize XOR

###### tags: `greedy`、`bit manipulation`、`again`

[LeetCode](https://leetcode.com/problems/minimize-xor/description/)

Problem Context

**範例 1**
```
Input: num1 = 3, num2 = 5
Output: 3
Explanation:
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.
```

**範例 2**
```
Input: num1 = 1, num2 = 12
Output: 3
Explanation:
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.
```

**限制邊界**
- 1 <= num1, num2 <= 10<sup>9</sup>

## 思路

### From Optimal to Valid

- 時間複雜度： O(log n)
- 空間複雜度： O(1)

### Build Answer

- 時間複雜度： O(1)
- 空間複雜度： O(1)
