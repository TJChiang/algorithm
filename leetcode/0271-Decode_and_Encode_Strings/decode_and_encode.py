from typing import List


class DecodeAndEncode:

    # {length}#{string}
    def encode(self, strs: List[str]) -> str:
        if not strs:
            return ""

        res = ""
        for s in strs:
            res += str(len(s)) + "#" + s

        return res

    def decode(self, s: str) -> List[str]:
        if not s:
            return []

        res = []
        i = 0

        while i < len(s):
            j = i

            # Find the delimiter '#'
            while s[j] != "#":
                j += 1

            # Get the length of the string
            length = int(s[i:j])

            # After the delimiter '#', i is the first index of the string
            i = j + 1

            # j is the end index of the string
            j = i + length

            # Extract the string
            res.append(s[i:j])

            # Move i to the next segment
            i = j

        return res
