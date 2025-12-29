import pytest

from character_replacement import CharacterReplacement


class TestCharacterReplacement:

    @pytest.mark.parametrize("s, k, expected", [
        ("ABAB", 2, 4),
        ("AABABBA", 1, 4),
        ("AABABBA", 2, 5),
        ("A", 0, 1),
        ("", 0, 0),
        ("AABBA", 1, 3),
        ("AAABBB", 2, 5)
    ])
    def test_solve(self, s, k, expected):
        target: CharacterReplacement = CharacterReplacement()
        assert target.solve(s, k) == expected
