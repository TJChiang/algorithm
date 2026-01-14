# 128. Longest Consecutive Sequence

###### tags: `hash table` `union find` `array`

[LeetCode](https://leetcode.com/problems/longest-consecutive-sequence/description/)

Problem Context

Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in `O(n)` time.

**範例 1**
```
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is `[1, 2, 3, 4]`. Therefore its length is 4.
```

**範例 2**
```
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
```

**範例 3**
```
Input: nums = [1,0,1,2]
Output: 3
```

**限制邊界**
- 0 <= nums.length <= 10<sup>5</sup>
- -10<sup>9</sup> <= nums[i] <= 10<sup>9</sup>

## 思路

### Solution

Using a hash set to store the numbers, we can efficiently check for the presence of consecutive numbers. The algorithm iterates through each number in the array and checks if it is the start of a sequence. if `num - 1` is not in the set, then `num` is the start of a sequence.
If it is, we then count how long the consecutive sequence is by checking for `num + 1`, `num + 2`, etc. We keep track of the maximum length found during this process.

- Time Complexity： O(n), where n is the length of `nums`.
- Space Complexity： O(n)
