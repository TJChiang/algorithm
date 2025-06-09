import pytest

from longest_substring import LongestSubstring


class TestLongestSubString:

    @pytest.mark.parametrize("s, expected", [
        ("abcabcbb", 3),
        ("bbbbb", 1),
        ("pwwkew", 3),
        ("", 0),
        ("a", 1),
        ("au", 2),
        ("dvdf", 3),
        ("abba", 2),
        ("tmmzuxt", 5)
    ])
    def test_solve_by_set(self, s: str, expected: int):
        target: LongestSubstring = LongestSubstring()
        assert target.solve_by_set(s) == expected

    @pytest.mark.parametrize("s, expected", [
        ("abcabcbb", 3),
        ("bbbbb", 1),
        ("pwwkew", 3),
        ("", 0),
        ("a", 1),
        ("au", 2),
        ("dvdf", 3),
        ("abba", 2),
        ("tmmzuxt", 5)
    ])
    def test_solve_by_last_index(self, s: str, expected: int):
        target: LongestSubstring = LongestSubstring()
        assert target.solve_by_last_index(s) == expected
