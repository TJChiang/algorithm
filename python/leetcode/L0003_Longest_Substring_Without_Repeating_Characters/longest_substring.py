class LongestSubstring:

    # Time: O(n)
    # Space: O(1)
    def solve_by_set(self, s: str) -> int:
        result = 0
        left = 0
        char_set = set()

        for right in range(len(s)):
            while s[right] in char_set:
                char_set.remove(s[left])
                left += 1

            char_set.add(s[right])
            result = max(result, right - left + 1)

        return result

    # Time: O(n)
    # Space: O(1)
    def solve_by_last_index(self, s: str) -> int:
        result = 0
        left = 0
        last_index = {}

        for right, c in enumerate(s):
            if c in last_index and last_index[c] >= left:
                left = last_index[c]
                left += 1

            result = max(result, right - left + 1)
            last_index[c] = right

        return result
