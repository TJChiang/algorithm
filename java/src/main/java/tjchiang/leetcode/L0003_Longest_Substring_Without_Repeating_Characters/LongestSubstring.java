package tjchiang.leetcode.L0003_Longest_Substring_Without_Repeating_Characters;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class LongestSubstring {

    /**
     * Time complexity: O(n)
     * </br>
     * Space complexity: O(1)
     */
    public int solveBySet(String s) {
        int result = 0;
        int left = 0;
        Set<Character> charSet = new HashSet<>();

        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            while (charSet.contains(c)) {
                charSet.remove(s.charAt(left));
                left++;
            }

            charSet.add(c);
            result = Math.max(result, right - left + 1);
        }

        return result;
    }

    /**
     * Time complexity: O(n)
     * </br>
     * Space complexity: O(1)
     */
    public int solveByLastIndex(String s) {
        int result = 0;
        int left = 0;
        Map<Character, Integer> lastIndex = new HashMap<>();

        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            if (lastIndex.containsKey(c) && lastIndex.get(c) >= left) {
                left = lastIndex.get(c);
                left++;
            }

            lastIndex.put(c, right);
            result = Math.max(result, right - left + 1);
        }

        return result;
    }
}
