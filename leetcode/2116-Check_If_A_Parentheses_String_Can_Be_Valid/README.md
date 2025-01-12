# 2116. Check if a Parentheses String Can Be Valid

###### tags: `string`、`stack`、`greedy`
<br>

[LeetCode](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/)

Problem Context

...

...

**範例 1**
```
Input: s = "))()))", locked = "010100"
Output: true
Explanation: locked[1] == '1' and locked[3] == '1', so we cannot change s[1] or s[3].
We change s[0] and s[4] to '(' while leaving s[2] and s[5] unchanged to make s valid.
```

**範例 2**
```
Input: s = "()()", locked = "0000"
Output: true
Explanation: We do not need to make any changes because s is already valid.
```

**範例 3**
```
Input: s = ")", locked = "0"
Output: false
Explanation: locked permits us to change s[0]. 
Changing s[0] to either '(' or ')' will not make s valid.
```

**限制邊界**
- n == s.length == locked.length
- 1 <= n <= 10<sup>5</sup>
- s[i] is either '(' or ')'.
- locked[i] is either '0' or '1'.

## 思路

### Stack

- 時間複雜度： O(n)
- 空間複雜度： O(n)

### Constant Space

- 時間複雜度： O(n)
- 空間複雜度： O(1)
