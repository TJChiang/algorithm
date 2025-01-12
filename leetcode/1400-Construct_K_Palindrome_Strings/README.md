# 1400. Construct K Palindrome Strings

###### tags: `string`、`hash table`、`greedy`、`counting`
<br>

[LeetCode](https://leetcode.com/problems/construct-k-palindrome-strings/description/)

Problem Context

...

...

**範例 1**
```
Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
```

**範例 2**
```
Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.
```

**範例 3**
```
Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.
```

**限制邊界**
- 1 <= s.length <= 10<sup>5</sup>
- s consists of lowercase English letters.
- 1 <= k <= 10<sup>5</sup>

## 思路

### Count Odd Frequencies

- 時間複雜度： O(n)
- 空間複雜度： O(1)

### Bit Manipulation

- 時間複雜度： O(n)
- 空間複雜度： O(1)
