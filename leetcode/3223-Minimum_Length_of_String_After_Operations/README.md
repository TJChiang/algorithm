# 3223. Minimum Length of String After Operations

###### tags: `hash table`、`string`
<br>

[LeetCode](https://leetcode.com/problems/minimum-length-of-string-after-operations/description/)

Problem Context

**範例 1**
```
Input: s = "abaacbcbb"
Output: 5
Explanation:
We do the following operations:
Choose index 2, then remove the characters at indices 0 and 3. The resulting string is s = "bacbcbb".
And then, choose index 3, then remove the characters at indices 0 and 5. The resulting string is s = "acbcb".
```

**範例 2**
```
Input: s = "aa"
Output: 2
Explanation:
We cannot perform any operations, so we return the length of the original string.
```

**限制邊界**
- 1 <= s.length <= 2 * 10<sup>5</sup>
- s consists only of lowercase English letters.

## 思路

### Character Frequency Counting

- 時間複雜度： O(n)
- 空間複雜度： O(26) => O(1)
