import pytest

from .climbing_stairs import ClimbingStairs


class TestClimbingStairs:

    @pytest.mark.parametrize("n, expected", [
        (1,1),
        (2, 2),
        (3, 3),
        (4, 5),
        (5, 8),
        (6, 13),
        (7, 21),
        (8, 34),
        (9, 55),
        (10, 89),
        (30, 1346269)
    ])
    def test_solve_iterative(self, n, expected):
        target: ClimbingStairs = ClimbingStairs()
        assert target.solve_iterative(n) == expected

    @pytest.mark.parametrize("n, expected", [
        (1,1),
        (2, 2),
        (3, 3),
        (4, 5),
        (5, 8),
        (6, 13),
        (7, 21),
        (8, 34),
        (9, 55),
        (10, 89),
        (30, 1346269)
    ])
    def test_solve_recursive(self, n, expected):
        target: ClimbingStairs = ClimbingStairs()
        assert target.solve_recursive(n) == expected
