# 916. Word Subsets

###### tags: `array`、`string`、`hash table`
<br>

[LeetCode](https://leetcode.com/problems/word-subsets/)

Problem Context

...

...

**範例 1**
```
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]
```

**範例 2**
```
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]
```

**限制邊界**
- 1 <= words1.length, words2.length <= 104
- 1 <= words1[i].length, words2[i].length <= 10
- words1[i] and words2[i] consist only of lowercase English letters.
- All the strings of words1 are **unique**.

## 思路

### Character Frequency Counting

- 時間複雜度： O(n + m)
  - n: words1 長度
  - m: words2 長度
- 空間複雜度： O(1)
  - 固定 26 字母
