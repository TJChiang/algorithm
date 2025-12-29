import pytest

from check_inclusion import CheckInclusion


class TestCheckInclusion:

    @pytest.mark.parametrize(
        "s1, s2, expected",
        [
            ("ab", "eidbaooo", True),
            ("ab", "eidboaoo", False),
            ("abc", "ccccbbbbaaaa", False),
            ("abc", "bca", True),
            ("bca", "dcba", True),
            ("dca", "dcda", True),
            ("xyz", "zyxwvutsrqponmlkjihgfedcba", True),
            ("a", "a", True),
            ("a", "b", False),
            ("abcde", "edcbaabcde", True),
            ("abcde", "fghij", False)
        ]
    )
    def test_solve(self, s1: str, s2: str, expected: bool):
        target = CheckInclusion()
        assert target.solve(s1, s2) == expected
