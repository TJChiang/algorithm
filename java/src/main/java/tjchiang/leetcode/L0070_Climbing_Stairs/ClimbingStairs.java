package tjchiang.leetcode.L0070_Climbing_Stairs;

/**
 * <a href="https://leetcode.com/problems/climbing-stairs/">70.Climbing Stairs</a>
 */
public class ClimbingStairs {
    public int solveOrigin(int n) {
        if (n < 1 || n > 45) return 0;

        // dp[i] means the number of ways to reach the i-th step
        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            // There are two ways to reach the i-th step:
            // 1. From the (i-1)-th step by taking 1 step
            // 2. From the (i-2)-th step by taking 2 steps
            // So the number of ways to reach the i-th step is the sum of the ways to reach the (i-1)-th and (i-2)-th steps
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    public int solveIterative(int n) {
        if (n < 1 || n > 45) return 0;

        if (n == 1 || n == 2) return n;

        int beforePrev = 1; // dp[i-1]
        int prev = 2; // dp[i-2]
        int curr = 0;

        for (int i = 3; i <= n; i++) {
            curr = beforePrev + prev; // dp[i] = dp[i-1] + dp[i-2]
            beforePrev = prev; // Move to the next step
            prev = curr; // Update the previous step
        }
        return curr;
    }

    public int solveRecursive(int n) {
        if (n < 1 || n > 45) return 0;

        if (n == 1 || n == 2) return n;

        // Recursive case: the number of ways to reach the n-th step is the sum of the ways to reach the (n-1)-th and (n-2)-th steps
        return solveRecursive(n - 1) + solveRecursive(n - 2);
    }
}
