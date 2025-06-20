from typing import List


# Time Complexity: O(log n)
# Space Complexity: O(1)
class Search:
    def solve_origin(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            if target > nums[right] or target < nums[left]:
                return -1

            if target == nums[right]:
                return right
            if target == nums[left]:
                return left

            if target < nums[right]:
                right -= 1
            if target > nums[left]:
                left += 1

        return -1

    def solve(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            # mid is calculated to avoid overflow
            mid = left + (right - left) // 2
            if target == nums[mid]:
                return mid
            elif target > nums[mid]:
                left = mid + 1
            else:
                right = mid - 1

        return -1
