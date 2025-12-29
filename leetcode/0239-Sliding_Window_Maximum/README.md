# 239. Sliding Window Maximum

##### tags: `Queue`
<br>

[LeetCode](https://leetcode.com/problems/sliding-window-maximum/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC.md)

有一個整數陣列 `nums` ，有一個大小為 `k` 的滑動窗口從陣列最左邊移動到陣列最右邊。
你只能看到在滑動窗口內的 `k` 個數字。
滑動窗口一次只能向右移動一位。

**範例 1**
```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

**範例 2**
```
Input: nums = [1], k = 1
Output: [1]
```

**邊界限制**
- 1 <= nums.length <= 10<sup>5</sup>
- -10<sup>4</sup> <= nums[i] <= 10<sup>4</sup>
- 1 <= k <= nums.length


## 思路

暴力解法是 O(n x k) ，但 LeetCode 會出現 「Time Limit Exceeded」。

可以使用佇列，隨著窗口的移動，佇列也一進一出，每次移動之後，佇列出現最大值。

如何隨著窗口一進一出，同時輸出最大值？

**只需要維護可能是窗口的最大值，並讓佇列中的元素由大到小排序即可**。
此類型的佇列為**單調佇列**，即為單調遞增或遞減的佇列。

![239.滑动窗口最大值](https://code-thinking.cdn.bcebos.com/gifs/239.滑动窗口最大值.gif)

- 放入：欲放入的值 `等於` 佇列入口的值，則把入口值彈出，直到放入的值 `小於等於` 佇列入口的值為止。
- 移出：如果欲移除的值 `等於` 佇列出口的值，才彈出該元素。

![239.滑动窗口最大值-2](https://code-thinking.cdn.bcebos.com/gifs/239.滑动窗口最大值-2.gif)

### 此題解法

先用 deque (C++ 預設佇列容器)實現單調佇列，再解決滑動窗口最大值的問題。

```cpp
class Solution {
private:
    class MyQueue {
        public:
            deque<int> que;
            void pop(int value) {
                if (!que.empty() && value == que.front()) {
                    que.pop_front();
                }
            }
            void push(int value) {
                while (!que.empty() && value > que.front()) {
                    que.pop_back();
                }
                que.push_back(value);
            }
            int front() {
                return que.front();
            }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }

        return result;
    }
};
```
