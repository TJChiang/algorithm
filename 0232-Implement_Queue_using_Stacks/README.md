# 232. Implement Queue using Stacks

###### tags: `Queue`、`Stack`
<br>

[LeetCode](https://leetcode.com/problems/implement-queue-using-stacks/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.md)

使用 `堆疊` 實現佇列。

實現 `MyQueue` 類別：
- `void push(int x)` 從佇列最後方加入 x 元素
- `int pop()` 移除佇列最前方的元素並回傳該值
- `int peel()` 回傳佇列最前方元素值
- `boolean empty()` 如果佇列為空，回傳 `true`；否則，回傳 `false`

**Notes:**
- **必須只**堆疊的標準函式，`push to top`、`peek/pop from top`、`size` 以及 `is empty`。
- 如果使用的程式語言不支援原生堆疊，可以在不違反上點的情況下，使用 `list` 或 `deque` 模擬堆疊。


**範例 1**
```
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
```

**限制邊界**
- 1 <= x <= 9
- At most `100` calls will be made to `push`, `pop`, `peek`, and `empty`.
- All the calls to `pop` and `peek` are valid.

## 思路
堆疊的特性為`後進先出 (LIFO)`，而佇列的特性為`先進先出(FIFO)`，因此我們需要兩個堆疊，分別代表輸入及輸出。
- 輸入：將資料暫存起來。
- 輸出：當需要取得資料時，將輸入的資料依序放進輸出的堆疊。

透過兩個FILO就可以達到佇列的效果，對整體來說，就是FIFO。

## 解法
```cpp
class MyQueue {
public:
    stack<int> input;
    stack<int> output;

    MyQueue() {}

    void push(int x) {
        input.push(x);
    }

    int pop() {
        int result = this->peek();
        output.pop();
        return result;
    }

    int peek() {
        // output 為空時，將 input 的數據轉到 output
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};

```
