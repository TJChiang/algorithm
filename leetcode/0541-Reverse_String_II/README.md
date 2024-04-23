# 541. Reverse String II

###### tags: `String`
<br>

[LeetCode](https://leetcode.com/problems/reverse-string-ii/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.md)

有一個字串 `s` 和一個整數 `k`，從字串開始，每隔 2k 個字的前 k 個字進行反轉。

如果剩下的字數少於 k 個，反轉剩餘的字。

如果剩下的字數少於 2k 但大於或等於 k 個，則反轉前 k 個字，其餘字保持原樣。

**範例 1**
```
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
```

**範例 2**
```
Input: s = "abcd", k = 2
Output: "bacd"
```

**邊界限制**
- 1 <= s.length <= 10<sup>4</sup>
- `s` consists of only lowercase English letters.
- 1 <= k <= 10<sup>4</sup>

## 思路

條件：
1. 每隔 2k 個字的前 k 個字進行反轉
    - for loop 每次移動 2k 個
2. 剩餘字數大於或等於 k 個，則反轉前 k 個字，其餘不變
    - s.length >= i + k
3. 剩餘字數少於 k 個，反轉所有剩餘的字

每次移動 2k 個，再進行反轉判斷。

**當需要固定規律去處理邏輯時，可以使用 for loop ，並注意條件設定。**

```cpp
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2*k) {
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
                continue;
            }

            reverse(s.begin() + i, s.begin() + s.size());
        }

        return s;
    }
};
```

- 時間複雜度：O(n)
- 空見複雜度：O(1)