from typing import List

class TwoSumII:
    def solve(self, numbers: List[int], target: int) -> List[int]:
        start: int = 0
        end: int = len(numbers) - 1
        while start < end:
            result = numbers[start] + numbers[end]
            if result == target:
                return [start + 1, end + 1]
            if result < target:
                start += 1
            else:
                end -= 1

        return [-1, -1]
