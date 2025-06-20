from typing import List

import pytest

from search import Search


class TestSearch:

    @pytest.mark.parametrize(
        "nums, input_target, expected",
        [
            ([1, 2, 3, 4, 5], 3, 2),
            ([1, 2, 3, 4, 5], 6, -1),
            ([1, 2, 3, 4, 5], 1, 0),
            ([1, 2, 3, 4, 5], 5, 4),
            ([1], 1, 0),
            ([1], 2, -1),
            ([], 1, -1)
        ]
    )
    def test_solve_origin(self, nums: List[int], input_target, expected: int):
        target = Search()
        assert target.solve_origin(nums, input_target) == expected

    @pytest.mark.parametrize(
        "nums, input_target, expected",
        [
            ([1, 2, 3, 4, 5], 3, 2),
            ([1, 2, 3, 4, 5], 6, -1),
            ([1, 2, 3, 4, 5], 1, 0),
            ([1, 2, 3, 4, 5], 5, 4),
            ([1], 1, 0),
            ([1], 2, -1),
            ([], 1, -1)
        ]
    )
    def test_solve(self, nums: List[int], input_target, expected: int):
        target = Search()
        assert target.solve(nums, input_target) == expected
