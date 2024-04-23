# 28.Implement strStr()

###### tags: `String`、`KMP`
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

### 暴力解法
```cpp
class Solution {
    public:
        int strStr(string haystack, string needle) {
            int n = haystack.size();
            int m = needle.size();

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i + j > n)
                        break;
                    if (haystack[j + i] != needle[j])
                        break;

                    if (j == m - 1) return i;
                }
            }

            return -1;
        }
};
```

- 時間複雜度：O(n x m)
- 空間複雜度：O(1)

## KMP

KMP 是由 Knuth、Morris 和 Pratt 三位學者發明，以三者名字首個字母命名。

主要使用在字串匹配，其思想是**當字串不匹配時，可以知道一部份已匹配的內容，利用這個資訊避免從頭再進行配對**。

KMP 的前綴表是避免重新匹配的關鍵。

### 前綴表
前綴表(prefix table) 主要作用為**紀錄子字串中，每個位置的相同前後綴數量**，當出現主字串與子字串不匹配時，子字串從對應位置開始重新配對。

### 建構前綴表 (next 陣列)

主要有三個步驟：
1. 初始化
2. 處理前後綴不同的情況
3. 處理前後綴相同的情況

#### 1. 初始化

設定兩個指標 `i` 和 `j`，分別指向後綴尾端、前綴尾端。
> 從 -1 開始賦值只是常見的實現方式，也可以不從 -1 開始。

next[i] 為子字串 `i` 位置(含)之前最長相等的前後綴長度，也就是 `j`，所以 next[0] = j。

而 `j` 設為 -1 作為初始值：
```cpp
int j = -1;
next[0] = j
```

#### 2. 處理前後綴不同的情況
將前綴尾端與後綴尾端進行比較，由於 `j` 初始值為 -1 ，因此 s[i] 與 s[j + 1] 進行比較：
```cpp
for (int i = 1; i < s.size(); i++)
```

next[j] 紀錄 j (含)之前的子字串相同前後綴的長度。

如果 s[i] 與 s[j + 1] 不同，表示前後綴尾端不相同，要向前回退

找 j + 1 前一個元素在 next 陣列裡的值，也就是 next[j]：
```cpp
// 前後綴不同
while (j >= 0 && s[i] != s[j + 1]) {
    // 向前回退
    j = next[j];
}
```

#### 3. 處理前後綴相同的情況
如果 s[i] 與 s[j + 1] 相同，要同時向後移動 i 和 j ，表示找到相同的前後綴，同時 next[i] 紀錄相同前後綴的長度：
```cpp
// 相同前後綴
if (s[i] == s[j + 1]) {
    j++;
}
next[i] = j;
```

最後前綴表 next 陣列如下：
```cpp
void getNext(int* next, const string& s) {
    int = -1;
    next[0] = j;

    for (int i = 1; i < s.size(); i++) {
        while (j >= 0 && s[i] != s[j + 1]) {
            j = next[j];
        }
        if (s[i] == s[j + 1]) {
            j++;
        }
        next[i] = j;
    }
}
```

### 使用 next 陣列做判斷
- `s` 表示主字串，`i` 表示主字串起始位置
- `t` 表示子字串，`j` 表示子字串起始位置

**由於 next 陣列裡的紀錄起始位置為 -1**，這裡 `j` 的起始值依然是 -1。

`i` 從0開始，遍歷主字串：
```cpp
for (int i = 0; i < s.size(); i++)
```

若 s[i] 與 t[j + 1] 不同，`j` 從 next 陣列尋找下一個配對位置：
```cpp
while (j >= 0 && s[i] != t[j + 1]) {
    j = next[j];
}
```

若 s[i] 與 t[j + 1] 相同，`i` 與 `j` 同時向後移動：
```cpp
if (s[i] == t[j + 1]) {
    j++;
}
```

如果 `j` 指向子字串 `t` 的尾端，表示**主字串 `s` 出現子字串 `t`**。

也就是說子字串出現在主字串的第一個位置是主字串當前位置減去子字串長度：
```cpp
if (j == (t.size() - 1)) {
    return i - t.size() + 1;
}
```

整段程式：
```cpp
int j = -1;
for (int i = 0; i < s.size(); i++) {
    while (j >= 0 && s[i] != t[j + 1]) {
        j = next[j];
    }

    if (s[i] == t[j + 1]) {
        j++;
    }

    if (j == (t.size() - 1)) {
        return i - t.size() + 1;
    }
}
```

### KMP 解法
```cpp
class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = -1;
        next[0] = j;

        for (int i = 1; i < s.size(); i++) {
            while (j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }

            if (s[i] == s[j + 1]) {
                j++;
            }

            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }

        int next[needle.size()];
        getNext(next, needle);
        int j = -1;
        for (int i = 0; i < haystack.size(); i++) {
            while(j >= 0 && haystack[i] != needle[j + 1]) {
                j = next[j];
            }

            if (haystack[i] == needle[j + 1]) {
                j++;
            }

            if (j == (needle.size() - 1)) {
                return i - needle.size() + 1;
            }
        }

        return -1;
    }
};
```

### KMP 解法 - 2
```cpp
class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = j;

        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }

            if (s[i] == s[j]) {
                j++;
            }

            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }

        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }

            if (haystack[i] == needle[j]) {
                j++;
            }

            if (j == needle.size()) {
                return i - needle.size() + 1;
            }
        }

        return -1;
    }
};
```

- 時間複雜度：O(m + n)
