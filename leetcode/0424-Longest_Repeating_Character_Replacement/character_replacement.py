from collections import defaultdict


# Time: O(N) where N is the length of the string s
# Space: O(1) - since the frequency map will have at most 26 characters
class CharacterReplacement:
    def solve(self, s: str, k: int) -> int:
        freqs = defaultdict(int)
        max_count = 0
        result = 0
        left = 0

        for right in range(len(s)):
            freqs[s[right]] += 1
            max_count = max(max_count, freqs[s[right]])
            curr_len = right - left + 1
            # The count of the most frequent character plus k means we can replace all other characters in the current window.
            if curr_len > max_count + k:
                freqs[s[left]] -= 1
                left += 1

            result = max(result, right - left + 1)

        return result
