import pytest

from lexicographically_string import LexicographicallyString


class TestLexicographicallyString:

    @pytest.mark.parametrize("s1, s2, baseStr, expected", [
        ("parker", "morris", "parser", "makkek"),
        ("hello", "world", "hold", "hdld"),
        ("leetcode", "programs", "sourcecode", "aauaaaaada")
    ])
    def test_smallest_equivalent_string(self, s1, s2, baseStr, expected):
        target: LexicographicallyString = LexicographicallyString()
        assert target.solve(s1, s2, baseStr) == expected
