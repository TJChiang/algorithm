from typing import List

class ContainsDuplicate:
    # Time Complexity: O(n)
    # Space Complexity: O(n)
    def solve_by_hash_set(self, nums: List[int]) -> bool:
        return len(nums) != len(set(nums))

    # Time Complexity: O(n log n)
    # Space Complexity: O(n)
    def solve_by_sorting(self, nums: List[int]) -> bool:
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                return True
        return False