package tjchiang.leetcode.L1061_Lexicographically_Smallest_Equivalent_String;

import tjchiang.algorithm.UnionFind;

public class Solution {
    public String solve(String s1, String s2, String baseStr) {
        UnionFind uf = new UnionFind(26);
        for (int i = 0; i < s1.length(); i++) {
            int x = s1.charAt(i) - 'a';
            int y = s2.charAt(i) - 'a';
            uf.union(x, y);
        }

        StringBuilder result = new StringBuilder();
        for (char c : baseStr.toCharArray()) {
            int root = uf.find(c - 'a');
            result.append((char) (root + 'a'));
        }
        return result.toString();
    }
}
