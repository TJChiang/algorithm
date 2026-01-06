class IsAnagram:
    # Time: O(n)
    # Space: O(26) -> O(1)
    # this solution also works for unicode characters
    def solve_by_hash_map(self, s: str, t: str) -> bool:
        s_len = len(s)
        t_len = len(t)

        # Contrainsts
        if s_len < 1 or s_len > 10**4 or t_len < 1 or t_len > 10**4:
            return False

        # if lengths are different, they cannot be anagrams
        if s_len != t_len:
            return False

        # hash map to count character frequencies
        char_map = {}

        # count characters in s
        for c in s:
            char_map[c] = char_map.get(c, 0) + 1

        for c in t:
            # if character in t is not in s or its count is zero, return False
            if c not in char_map or char_map[c] == 0:
                return False
            char_map[c] -= 1

        return True

    def solve_for_ascii_codes(self, s: str, t: str) -> bool:
        s_len = len(s)
        t_len = len(t)

        # Contrainsts
        if s_len < 1 or s_len > 10**4 or t_len < 1 or t_len > 10**4:
            return False

        # if lengths are different, they cannot be anagrams
        if s_len != t_len:
            return False

        # array to count character frequencies for 'a' to 'z'
        char_count = [0] * 26

        for c in s:
            char_count[ord(c) - ord('a')] += 1

        for c in t:
            char_count[ord(c) - ord('a')] -= 1
            if char_count[ord(c) - ord('a')] < 0:
                return False

        return True

    # Time: O(n log n)
    # Space: O(1)
    def solve_by_sorting(self, s: str, t: str) -> bool:
        s_len = len(s)
        t_len = len(t)

        # Contrainsts
        if s_len < 1 or s_len > 10**4 or t_len < 1 or t_len > 10**4:
            return False

        # if lengths are different, they cannot be anagrams
        if s_len != t_len:
            return False

        # sort both strings and compare
        return sorted(s) == sorted(t)