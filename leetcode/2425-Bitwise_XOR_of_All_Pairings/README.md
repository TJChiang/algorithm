# 2425. Bitwise XOR of All Pairings

###### tags: `array`、`bit manipulation`、`brainteaser`
<br>

[LeetCode](https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/)

Problem Context

**範例 1**
```
Input: nums1 = [2,1,3], nums2 = [10,2,5,0]
Output: 13
Explanation:
A possible nums3 array is [8,0,7,2,11,3,4,1,9,1,6,3].
The bitwise XOR of all these numbers is 13, so we return 13.
```

**範例 2**
```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 0
Explanation:
All possible pairs of bitwise XORs are nums1[0] ^ nums2[0], nums1[0] ^ nums2[1], nums1[1] ^ nums2[0],
and nums1[1] ^ nums2[1].
Thus, one possible nums3 array is [2,5,1,6].
2 ^ 5 ^ 1 ^ 6 = 0, so we return 0.
```

**限制邊界**
- 1 <= nums1.length, nums2.length <= 10<sup>5</sup>
- 0 <= nums1[i], nums2[j] <= 10<sup>9</sup>

## 思路

### Hash map

- 時間複雜度： O(n + m)
  - n: nums1 長度
  - m: nums2 長度
- 空間複雜度： O(n + m)
  - n: nums1 長度
  - m: nums2 長度

### Bit Manipulation

- 時間複雜度： O(n + m)
    - n: nums1 長度
    - m: nums2 長度
- 空間複雜度： O(1)
