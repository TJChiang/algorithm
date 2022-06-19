# Reverse Words in a String

###### tags:
<br>

[LeetCode](https://leetcode.com/problems/reverse-words-in-a-string/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.md)

有一個字串 `s`，反轉字串中的單字順序。

**範例 1**
```
Input: s = "the sky is blue"
Output: "blue is sky the"
```

**範例 2**
```
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```

**範例 3**
```
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
```

**邊界限制**
- 1 <= s.length <= 10<sup>4</sup>
- `s` contains English letters (upper-case and lower-case), digits, and spaces `' '`.
- There is **at least one** word in `s`


## 思路

透過觀察，可以發現先將字串全部反轉，在逐一將單字反轉即可。

e.g. `the sky is blue` -> `eulb si yks eht` -> `blue is sky the`

要完成題目的條件要做三件事：
1. 移除多餘空格
2. 反轉字串
3. 找出單字區間

### 1. 移除多餘空格
可以使用雙指針來完成
- 快指針：指向要複製的資料位址
- 慢指針：指向下次要插入的位址
```cpp
void removeExtraSpaces(string& s) {
    int slow = 0, fast = 0;

    // 移除字串前面的空格
    while (s.size() > 0 && fast < s.size() && s[fast] == ' ') {
        fast++;
    }

    for (; fast < s.size(); fast++) {
        if (
            fast - 1 > 0
            && s[fast - 1] == s[fast]
            && s[fast] == ' '
        ) {
            continue;
        }

        s[slow++] = s[fast];
    }

    // 移除尾端的空格
    if (slow - 1 > 0 && s[slow - 1] == ' ')
        s.resize(slow - 1);
    else
        s.resize(slow);
}
```

### 2. 反轉字串
根據 [0344-Reverse_String](../0344-Reverse_String/README.md) 與 [0541-Reverse_String_II](../0541-Reverse_String_II/README.md)，我們可以寫出反轉字串的函式
```cpp
string reverse(string& s, int begin, int end) {
    for (int i = begin, j = end; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
}
```

### 3. 找出單字區間
當移除多餘空格後，單字的開頭會在空格之後，而單字的結尾會在空格之前或是字串的尾端。
```cpp
for (int i = 0; i <= s.size(); i++) {
    // 當有空格或到達字串尾端時，反轉單字
    if (s[i] == ' ' || i == s.size()) {
        reverseString(s, start, i - 1);

        // 當前為空格，表示下一個 index 為單字開頭
        start = i + 1;
    }
}
```

### 此題解法
```cpp
class Solution {
    public:
        // 反轉字串
        void reverseString(string& s, int begin, int end) {
            for (int i = begin, j = end; i < j; i++, j--) {
                swap(s[i], s[j]);
            }
        }

        void removeExtraSpaces(string& s) {
            int slow = 0, fast = 0;

            // 移除字串前端的空格
            while (s.size() > 0 && fast < s.size() && s[fast] == ' ') {
                fast++;
            }

            // 移除單字中的空格
            for (; fast < s.size(); fast++) {
                // 移除單字中額外的空格
                if (
                    fast - 1 > 0
                    && s[fast - 1] == ' '
                    && s[fast] == ' '
                ) {
                    continue;
                }

                // 複製資料
                s[slow++] = s[fast];
            }

            // 移除字串尾端的空格
            if (slow - 1 > 0 && s[slow - 1] == ' ')
                s.resize(slow - 1);
            else
                s.resize(slow);
        }

        string reverseWords(string s) {
            // 移除多餘空格
            removeExtraSpaces(s);

            // 字串全部反轉
            reverseString(s, 0, s.size() - 1);

            // 單字起始位址
            int start = 0;

            // 反轉單字
            for (int i = 0; i <= s.size(); i++) {
                // 當有空格或到達字串尾端時，反轉單字
                if (s[i] == ' ' || i == s.size()) {
                    reverseString(s, start, i - 1);

                    // 當前為空格，表示下一個 index 為單字開頭
                    start = i + 1;
                }
            }

            return s;
        }
};
```