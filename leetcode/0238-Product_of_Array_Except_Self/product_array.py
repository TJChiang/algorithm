from typing import List


class ProductArray:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # Constraints
        n = len(nums)
        if n < 2 or n > 10**5:
            return []

        # Initialize the result array with 1s
        res = [1] * n

        left = 1
        for i in range(0, n):
            # Calculate the product of all elements to the left of index i
            res[i] *= left
            # Update left to include the current element
            left *= nums[i]

        right = 1
        for i in range(n - 1, -1, -1):
            # Calculate the product of all elements to the right of index i
            res[i] *= right
            # Update right to include the current element
            right *= nums[i]

        return res
