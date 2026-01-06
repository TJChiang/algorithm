from typing import List


class TwoSum:
    def solve_by_hash_map(self, nums: List[int], target: int) -> List[int]:
        num_map = {}
        for i, num in enumerate(nums):
            # Calculate the complement, which when added to the current number equals the target
            complement = target - num

            # Check if the complement exists in the map
            if complement in num_map:
                return [num_map[complement], i]

            # key: current number, value: current index
            num_map[num] = i
        return []