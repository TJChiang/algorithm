from collections import defaultdict


# Time: O(L1 + L2) where L1 is the length of s1, and L2 is the length of s2
# Space: O(1) - since the frequency maps will have at most 26 characters
class CheckInclusion:

    def solve(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        freq1 = defaultdict(int)
        freq2 = defaultdict(int)

        for i in range(len(s1)):
            freq1[s1[i]] += 1
            freq2[s2[i]] += 1

        if freq1 == freq2:
            return True

        left = 0
        for right in range(len(s1), len(s2)):
            freq2[s2[right]] += 1
            freq2[s2[left]] -= 1

            if freq2[s2[left]] == 0:
                del freq2[s2[left]]

            left += 1

            if freq1 == freq2:
                return True

        return False
