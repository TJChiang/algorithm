from typing import List


class LongestConsecutiveSequence:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0 or len(nums) > 10**5:
            return 0

        # Use a set to store unique numbers for O(1) look-up time
        nums_set = set(nums)
        res = 0

        for num in nums_set:
            # Only start counting if 'num' is the start of a sequence
            # num - 1 not in nums_set means 'num' is the smallest number in the sequence
            if num - 1 not in nums_set:
                # Start counting the length of the sequence from 'num'
                length = 1

                # Continue to check for the next consecutive numbers
                while num + length in nums_set:
                    length += 1

                # Update the result with the maximum length found
                res = max(res, length)

        return res
