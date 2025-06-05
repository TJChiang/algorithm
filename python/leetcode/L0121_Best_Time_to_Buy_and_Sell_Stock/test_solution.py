import pytest

from solution import Solution


class TestSolution:
    @pytest.mark.parametrize("prices, expected", [
        ([7, 1, 5, 3, 6, 4], 5),
        ([7, 6, 4, 3, 1], 0),
        ([2, 1], 0),
        ([1, 2], 1),
        ([3, 2, 6, 5, 0, 3], 4),
        ([1, 2, 3, 4, 5], 4),
        ([5, 4, 3, 2, 1], 0),
        ([10 ** 4] * (10 ** 5), 0),  # Maximum constraints
        ([0] * (10 ** 5), 0),  # Minimum price constraints
    ])
    def test_solve(self, prices, expected):
        target: Solution = Solution()
        assert target.solve(prices) == expected
