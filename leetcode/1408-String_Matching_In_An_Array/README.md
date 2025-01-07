# 1408. String Matching in an Array

###### tags: `string` 、 `array` 、 `string matching` 、 `KMP`
<br>

[LeetCode](https://leetcode.com/problems/string-matching-in-an-array/)

[KMP 演算法](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0028.%E5%AE%9E%E7%8E%B0strStr.md)

LPS: Longest Prefix Suffix

Problem Context

...

...

**範例 1**
```
Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
```

**範例 2**
```
Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
```

**範例 3**
```
Input: words = ["blue","green","bu"]
Output: []
Explanation: No string of words is substring of another string.
```

**限制邊界**
- 1 <= words.length <= 100
- 1 <= words[i].length <= 30
- words[i] contains only lowercase English letters.
- All the strings of words are unique.

## 思路

### Brute Force

- 時間複雜度： O(m<sup>2</sup> x n<sup>2</sup>)
- 空間複雜度： O(m x n)

### KMP

- 時間複雜度： O(m x n<sup>2</sup>)
  - m => compute LPS array
  - n<sup>2</sup> => words loop and look up LPS array 
- 空間複雜度： O(m x n)
