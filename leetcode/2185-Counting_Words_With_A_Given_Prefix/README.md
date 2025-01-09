# 2185. Counting Words With a Given Prefix

###### tags: `string`、`array`、`string matching`、`trie`
<br>

[LeetCode](https://leetcode.com/problems/counting-words-with-a-given-prefix/)

Problem Context

...

...

**範例 1**
```
Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".
```

**範例 2**
```
Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.
```

**限制邊界**
- 1 <= words.length <= 100
- 1 <= words[i].length, pref.length <= 100
- words[i] and pref consist of lowercase English letters.

## 思路

### BruteForce

- 時間複雜度： O(n x m)
  - n: words 的長度
  - m: 字串匹配的長度
- 空間複雜度： O(1)

### Built-In Methods

> 就是暴力解，只是一個是手刻字串比對函數，一個是用內建的函數

- 時間複雜度： O(n x m)
    - n: words 的長度
    - m: 字串匹配的長度
- 空間複雜度： O(1)

### Trie

Trie 表現較暴力解差，但它的優勢是 **prefix 變動的情況下，會更有效率** (像是現在的 autocomplete)。

- 時間複雜度： O(n x l + m)
  - n: words 的長度
  - l: 字串最大長度
  - m: pref 長度
- 空間複雜度： O(n x l)
  - n: words 的長度
  - l: 字串最大長度
