# 347. Top K Frequent Elements

###### tags: `queue`
<br>

[LeetCode](https://leetcode.com/problems/top-k-frequent-elements/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0347.%E5%89%8DK%E4%B8%AA%E9%AB%98%E9%A2%91%E5%85%83%E7%B4%A0.md)

給定一個整數陣列 `nums` 和整數 `k` ，回傳出現頻率前 `k` 高的元素。
可以回傳任何排序的答案。

**範例 1**

```
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
```

**範例 2**

```
Input: nums = [1], k = 1
Output: [1]
```

**限制邊界**

- 1 <= nums.length <= 10<sup>5</sup>
- -10<sup>4</sup> <= nums[i] <= 10<sup>4</sup>
- `k` 的範圍 `[1, 陣列中唯一元素的數量]`
- 保證答案都是唯一值

**時間複雜度必須優於 `O(nlogn)` ， n 為陣列長度**

## 解題思路

## 解法

```cpp
class Solution {
public:
    class myComparison {
        public:
            bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
                return lhs.second > rhs.second;
            }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]++];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison> pri_que;

        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) {
                pri_que.pop();
            }

            vector<int> result(k);
            for (int i = k - 1; i >= 0; i--) {
                result[i] = pri_que.top().first;
                pri_que.pop();
            }
            return result;
        }
    }
};
```
