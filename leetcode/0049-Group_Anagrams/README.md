# 49. Group Anagrams

###### tags: `array`

[LeetCode](https://leetcode.com/problems/group-anagrams/description/)

Given an array of strings `strs`, group the anagrams together. You can return the answer in any order.

**範例 1**
```
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Explanation:
- There is no string in strs that can be rearranged to form "bat".
- The string "nat" and "tan" are anagrams as they can be rearranged to form each other.
- The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
```

**範例 2**
```
Input: strs = [""]
Output: [[""]]
```

**範例 3**
```
Input: strs = ["a"]
Output: [["a"]]
```

**限制邊界**
- 1 <= strs.length <= 10<sup>4</sup>
- 0 <= strs[i].length <= 100
- `strs[i]` consists of lowercase English letters.
