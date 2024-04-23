# 232. Implement Queue using Stacks

###### tags: `Queue`、`Stack`
<br>

[LeetCode](https://leetcode.com/problems/implement-stack-using-queues/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.md)

使用 `佇列` 實現堆疊。

實現 `MyStack` 類別：
- `void push(int x)` 從堆疊最上方加入 x 元素
- `int pop()` 移除堆疊最上方的元素並回傳該值
- `int peel()` 回傳堆疊最上方元素值
- `boolean empty()` 如果堆疊為空，回傳 `true`；否則，回傳 `false`

**Notes:**
- **必須只**堆疊的標準函式，`push to back`、`peek/pop from front`、`size` 以及 `is empty`。
- 如果使用的程式語言不支援原生堆疊，可以在不違反上點的情況下，使用 `list` 或 `deque` 模擬堆疊。


**範例 1**
```
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
```

**限制邊界**
- 1 <= x <= 9
- At most `100` calls will be made to `push`, `pop`, `peek`, and `empty`.
- All the calls to `pop` and `top` are valid.

## 思路
堆疊的特性為`後進先出 (LIFO)`，而佇列的特性為`先進先出(FIFO)`。

一個作為輸入佇列，一個作為輸出佇列，會發現其實行不通，依然無法改變數據的順序。實際上，只需要一個佇列即可模擬堆疊。

然而，實作上還是需要兩個佇列來完成，一個代表主要數據，另一個用來備份數據。除了最後的元素之外，將主要佇列的數據備份到備用佇列，之後主要佇列彈出指定的數據，再將備用佇列的資料轉移到主要佇列。

## 雙佇列解法
```cpp
class MyQueue {
public:
    queue<int> primary;
    queue<int> backup;

    MyQueue() {}

    void push(int x) {
        primary.push(x);
    }

    int pop() {
        int size = primary.size() - 1;
        while (size--) {
            backup.push(primary.front());
            primary.pop();
        }

        int result = primary.front();
        primary.pop();
        primary = backup;
        while (!backup.empty()) {
            backup.pop();
        }
        return result;
    }

    int top() {
        return primary.back();
    }

    bool empty() {
        return primary.empty();
    }
};
```

## 單佇列解法
新的元素加入佇列後，除了新加入的元素外，其餘元素依序重新 push & pop，確保新加入的元素在佇列最前方。

| input -> output | step 1 | step 2 |
|-- | -- | -- |
| 1 |||
| 2 -> 1 | 1 -> 2 | |
| 3 -> 1 -> 2 | 2 -> 3 -> 1 | 1 -> 2 -> 3 |

```cpp
class MyQueue {
public:
    queue<int> que;

    MyQueue() {}

    void push(int x) {
        que.push(x);

        // 除了新加入的元素外，其餘依序 push & pop ，確保新加入的元素在最前面
        for (int i = 0; i < que.size() - 1; i++) {
            que.push(que.front());
            que.pop();
        }
    }

    int pop() {
        int result = que.front();
        que.pop();
        return result;
    }

    int top() {
        return que.front();
    }

    bool empty() {
        return que.empty();
    }
};
```
