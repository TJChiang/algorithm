import pytest

from solution import Solution


class TestSolution:

    @pytest.mark.parametrize("s1, s2, baseStr, expected", [
        ("parker", "morris", "parser", "makkek"),
        ("hello", "world", "hold", "hdld"),
        ("leetcode", "programs", "sourcecode", "aauaaaaada")
    ])
    def test_smallest_equivalent_string(self, s1, s2, baseStr, expected):
        target: Solution = Solution()
        assert target.solve(s1, s2, baseStr) == expected
