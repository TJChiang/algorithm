import pytest

from candy import Candy


class TestCandy:

    @pytest.mark.parametrize("ratings, expected", [
        ([1, 0, 2], 5),
        ([1, 2, 2], 4),
        ([1, 3, 2, 2, 1], 7),
        ([1, 2, 3, 4, 5], 15),
        ([5, 4, 3, 2, 1], 15),
        ([1, 2, 87, 87, 87, 2, 1], 13)
    ])
    def test_solve(self, ratings, expected):
        target: Candy = Candy()
        assert target.solve(ratings) == expected
