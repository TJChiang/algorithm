# 3042. Count Prefix and Suffix Pairs I

###### tags: `string` 、 `trie` 、 `string matching` 、 `rolling hash` 、 `hash function`
<br>

[LeetCode](https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/)

Problem Context

...

...

**範例 1**
```
Input: words = ["a","aba","ababa","aa"]
Output: 4
Explanation: In this example, the counted index pairs are:
i = 0 and j = 1 because isPrefixAndSuffix("a", "aba") is true.
i = 0 and j = 2 because isPrefixAndSuffix("a", "ababa") is true.
i = 0 and j = 3 because isPrefixAndSuffix("a", "aa") is true.
i = 1 and j = 2 because isPrefixAndSuffix("aba", "ababa") is true.
Therefore, the answer is 4.
```

**範例 2**
```
Input: words = ["pa","papa","ma","mama"]
Output: 2
Explanation: In this example, the counted index pairs are:
i = 0 and j = 1 because isPrefixAndSuffix("pa", "papa") is true.
i = 2 and j = 3 because isPrefixAndSuffix("ma", "mama") is true.
Therefore, the answer is 2.  
```

**範例 3**
```
Input: words = ["abab","ab"]
Output: 0
Explanation: In this example, the only valid index pair is i = 0 and j = 1, and isPrefixAndSuffix("abab", "ab") is false.
Therefore, the answer is 0. 
```

**限制邊界**
- 1 <= words.length <= 50
- 1 <= words[i].length <= 10
- words[i] consists only of lowercase English letters.

## 思路

### Brute Force

- 時間複雜度： O(n<sup>2</sup> x m)
  - 外部迴圈: n
  - 內部迴圈: n - i - 1
  - 內部字串比對: `find()` & `rfind()` 最差為 O(m)，m 為字串的長度
- 空間複雜度： O(1)

### Dual Trie

- 時間複雜度： O(n<sup>2</sup> x m)
  - 雙迴圈: O(n<sup>2</sup>)
  - 插入節點、查詢節點: O(m) 
- 空間複雜度： O(n x m)
  - n: 字串數量
  - m: 每個字串產生的 m 節點 (node)
