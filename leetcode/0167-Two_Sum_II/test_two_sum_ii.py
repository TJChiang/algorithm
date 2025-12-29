import pytest

from two_sum_ii import TwoSumII

class TestTwoSumII:
    @pytest.mark.parametrize("numbers, target_value, expected", [
        ([2, 7, 11, 15], 9, [1, 2]),
        ([1, 2, 3, 4, 4, 9, 56, 90], 8, [4, 5]),
        ([2, 3, 4], 6, [1, 3]),
        ([-1, 0], -1, [1, 2])
    ])
    def test_solve(self, numbers, target_value, expected):
        target: TwoSumII = TwoSumII()
        assert target.solve(numbers, target_value) == expected
