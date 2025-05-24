package tjchiang.leetcode.L0167_Two_Sum_II;

/**
 * <a href="https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/">leetcode</a>
 */
public class TwoSumII {
    public int[] solve(int[] numbers, int target) {
        int start = 0;
        int end = numbers.length - 1;

        while (start < end) {
            int sum = numbers[start] + numbers[end];

            if (sum == target) return new int[]{start + 1, end + 1};
            if (sum < target) start++;
            else end--;
        }
        return new int[]{};
    }
}
