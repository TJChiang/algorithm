from collections import defaultdict
from typing import List

class GroupAnagrams:

    # Time Complexity: O(N * KlogK) where N is the number of strings and K is the maximum length of a string
    # Space Complexity: O(N * K)
    def solve_brutal(self, strs: List[str]) -> List[List[str]]:
        result: List[List[str]] = []

        for s in strs:
            is_append = False
            for i in range(0, len(result)):
                first_str = result[i][0]
                if self.isAnagram(first_str, s):
                    result[i].append(s)
                    is_append = True
                    break

            if is_append is False:
                result.append([s])

        return result

    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        char_map = {}
        for c in s:
            char_map[c] = char_map.get(c, 0) + 1

        for c in t:
            if c not in char_map or char_map[c] == 0:
                return False
            char_map[c] -= 1

        return True

    # Time Complexity: O(N * KlogK) where N is the number of strings and K is the maximum length of a string
    # Space Complexity: O(N * K)
    def solve_sorted(self, strs: List[str]) -> List[List[str]]:
        ans = defaultdict(list)

        for s in strs:
            key = "".join(sorted(s))
            ans[key].append(s)

        return list(ans.values())