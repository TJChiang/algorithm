from typing import List


class Solution:
    def solve(self, prices: List[int]) -> int:
        if len(prices) < 1 or len(prices) > 10 ** 5:
            return -1

        result: int = 0
        minPrice: int = 10 ** 5 + 1  # Constraints: 0 <= prices[i] <= 10**4

        for price in prices:
            minPrice = min(minPrice, price)
            result = max(result, price - minPrice)

        return result
