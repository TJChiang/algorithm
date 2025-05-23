# 替換空格

###### tags: `String`、`雙指針`
<br>

[LeetCode](https://leetcode.cn/problems/ti-huan-kong-ge-lcof/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%89%91%E6%8C%87Offer05.%E6%9B%BF%E6%8D%A2%E7%A9%BA%E6%A0%BC.md)

實現一個函數，把字串 `s` 中的每個空格替換成 `%20`。

**範例 1**
```
Input: s = "We are happy."
Output: "We%20are%20happy."
```

## 思路

可以使用額外空間將內容複製，並將空格換成 `%20`。

若希望空間複雜度為 O(1)，必須執行：
1. 空間擴展
2. 紀錄空格與轉換位址

以此題為例，由於需要紀錄空格位址與實際插入的位址，我們可以使用 `雙指針法`，並從尾端開始插入。
- 快指針：指向原本字串的值。起始位址為原本字串尾端
- 慢指針：指向目前字串應插入的位址。起始位址為擴展後的字串尾端

從前端插入的話，會需要將元素往後移，時間複雜度會變為 O(n<sup>2</sup>)。

```cpp

```

- 時間複雜度：O(n)
- 空間複雜度：O(1)

## 額外題目
- [27.Remove Element](https://leetcode.com/problems/remove-element/)
- [15.3Sum](https://leetcode.com/problems/3sum/)
- [18.4Sum](https://leetcode.com/problems/4sum/)
- [206.Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)
- [142.Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)
- [344.Reverse String](https://leetcode.com/problems/reverse-string/)
