# 左旋轉字串

###### tags: `String`
<br>

[LeetCode](https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/)
[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%89%91%E6%8C%87Offer58-II.%E5%B7%A6%E6%97%8B%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.md)

字串的左旋轉操作是把字串 `s` 前面的 `k` 個字元轉移到字串尾端。

請定義一個函數實現字串左旋轉操作的功能。

**範例 1**
```
Input: s = "abcdefg", k = 2
Output: "cdefgab"
```

**範例 2**
```
Input: s = "lrloseumgh", k = 6
Output: "umghlrlose"
```

**邊界限制**
- 1 <= k < s.length <= 10000

## 思路
e.g. s = "abcdefg", k = 2
1. 反轉前 k 個字串 => ba|cdefg
2. 反轉 k 到為端的字串 => ba|gfedc
3. 反轉整個字串 => cdefg|ab

```cpp
class Solution {
    public:
        string reverseLeftWords(string s, int k) {
            if (k < 1 || k > s.size() || s.size() > 10000) return "";

            // 反轉前 k 個字串 => ba|cdefg
            reverse(s.begin(), s.begin() + k);

            // 反轉 k 之後的字串 => ba|gfedc
            reverse(s.begin() + k, s.end());

            // 反轉全部字串 => cdefg|ab
            reverse(s.begin(), s.end());

            return s;
        }
};
```