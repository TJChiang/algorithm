# 28.Implement strStr()

###### tags: `String`
<br>

[LeetCode](https://leetcode.com/problems/implement-strstr/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0028.%E5%AE%9E%E7%8E%B0strStr.md)

有兩個字串分別為 `needle` 和 `haystack` ，在 `haystack` 找出 `needle` 字串出現的第一個位址。如果不存在則為傳 `-1`。

**說明：如果 `needle` 是空字串，要回傳什麼？在面試時是一個好問題。以本題來說， `needle` 為空字串時，應該回傳 `0`。**與 C 的 `strstr()`及 Java 的 `indexOf()` 定義一樣。

**範例 1**
```
Input: haystack = "hello", needle = "ll"
Output: 2
```

**範例 2**
```
Input: haystack = "aaaaa", needle = "bba"
Output: -1
```

**邊界限制**
- 1 <= haystack.length, needle.length <= 10<sup>4</sup>
- `haystack` and `needle` consist of only lowercase English characters.

## 思路
