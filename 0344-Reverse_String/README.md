# 344. Reverse String

- [LeetCode](https://leetcode.com/problems/reverse-string/)
- [參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0344.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.md)

寫一個反轉字串的 function，輸入的字串為一個字元陣列 `s`。

**必須**使用空間複雜度為 O(1) 的演算法。

**範例 1**
```
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
```

**範例 2**
```
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
```

**邊界限制**
- 1 <= s.length <= 10<sup>5</sup>
- `s[i]` is a printable ascii character.


## 思路

由於反轉字串是對稱形式，因此可以使用雙指針法，在一個迴圈內完成。

```cpp
class Solution {
    public:
        void reverseString(vector<char>& s) {
            for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
                swap(s[i], s[j]);
            }
        }
};
```

- 時間複雜度： O(n)
- 空間複雜度： O(1)

