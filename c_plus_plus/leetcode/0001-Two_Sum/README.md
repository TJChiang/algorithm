# 0001. Two Sum

###### tags: `Map`
<br>

[LeetCode](https://leetcode.com/problems/two-sum/)

>   Given an array of integers `nums` and an integer `target`, return *indices of the two numbers such that they add up to `target`*.

>You may assume that each input would have _**exactly one solution**_, and you may not use the *same* element twice.
You can return the answer in any order.

### Example 1:
```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Because nums[0] + nums[1] == 9, we return [0, 1].
```

### Constraints:
-   <code>2 <= nums.length <= 10<sup>3</sup></code>
-   <code>-10<sup>9</sup> <= nums[i] <= 10<sup>9</sup></code>
-   <code>-10<sup>9</sup> <= target <= 10<sup>9</sup></code>
-   **Only one valid answer exists.**

### Solution:
>   利用 **hash_map** 存放 `[ans:num]`，ans 為 key，num為當前遍歷的數字`ans = target - num`。  map 若不存在則存入，若已經存在則為解答。

```cpp
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        if (map.count(nums[i]) > 0)
            return {map[i], i};

        map[target - i] = nums[i];
    }

    return std::vector<int>{};
}
```