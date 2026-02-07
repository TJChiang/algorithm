from turtle import right
from typing import List


class TrappingRainWater:
    # Time complexity: O(n)
    # Space complexity: O(n)
    def prefix_suffix(self, height: List[int]) -> int:
        n = len(height)

        # Check constraints
        if n < 1 or n > 2 * 10 ** 4:
            return 0

        # Calculate the maximum height to the left and right of each position
        # leftMax[i] means the maximum height to the left of position i (including i)
        leftMax = [0] * n
        # rightMax[i] means the maximum height to the right of position i (including i)
        rightMax = [0] * n

        leftMax[0] = height[0]
        for i in range(1, n):
            # the reason we need to compare leftMax[i - 1] and height[i] is that the height at position i can also be the maximum height to the left of position i
            leftMax[i] = max(leftMax[i - 1], height[i])

        rightMax[n - 1] = height[n - 1]
        for i in range(n - 2, -1, -1):
            # the reason we need to compare rightMax[i + 1] and height[i] is that the height at position i can also be the maximum height to the right of position i
            rightMax[i] = max(rightMax[i + 1], height[i])

        result = 0
        for i in range(n):
            # the water trapped at position i is the minimum of the maximum height to the left and right of position i minus the height at position i
            result += max(0, min(leftMax[i], rightMax[i]) - height[i])

        return result

    # Time complexity: O(n)
    # Space complexity: O(1)
    def two_pointer(self, height: List[int]) -> int:
        n = len(height)
        if n < 1 or n > 2 * 10 ** 4:
            return 0

        left = 0
        right = n - 1
        leftMax = 0
        rightMax = 0
        result = 0

        # two pointers approach: we can use two pointers to traverse the height array from both ends towards the center.
        # We can keep track of the maximum height to the left and right of the current position, and calculate the water trapped at each position based on the minimum of the two maximum heights.
        while left < right:
            if height[left] < height[right]:
                if height[left] > leftMax:
                    leftMax = height[left]
                else:
                    result = result + (leftMax - height[left])
                left += 1
            else:

                if height[right] > rightMax:
                    rightMax = height[right]
                else:
                    result = result + (rightMax - height[right])
                right -= 1

        return result