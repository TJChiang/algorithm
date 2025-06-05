class Solution:
    def solve(self, s1: str, s2: str, baseStr: str) -> str:
        parent: dict = {}

        def find(x):
            if x != parent.setdefault(x, x):
                parent[x] = find(parent[x]) # Optimize: path compression
            return parent[x]

        for x, y in zip(s1, s2):
            parentX = find(x)
            parentY = find(y)
            if parentX == parentY:
                continue
            if parentX > parentY:
                parent[parentX] = parentY # Optimize: union by rank => keep the smaller one as parent
            else:
                parent[parentY] = parentX

        return ''.join(find(c) for c in baseStr)
