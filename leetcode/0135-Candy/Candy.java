import java.util.Arrays;

/**
 * <a href="https://leetcode.com/problems/candy/description">135. Candy</a>
 */
public class Candy {

    public int candy(int[] ratings) {
        // constraints
        if (isInvalidInput(ratings)) {
            return 0;
        }

        int sum = 0;
        int n = ratings.length;
        int[] candies = new int[n];
        // each child has at least one candy
        Arrays.fill(candies, 1);

        // traverse from the start
        // and the child with a higher rating has more candies than the neighbor child
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // traverse from the end
        for (int i = n - 1; i > 0; --i) {
            if (ratings[i - 1] > ratings[i]) {
                // the child with a higher rating should have at least higher candies than the
                // neighbor child
                candies[i - 1] = Math.max(candies[i - 1], candies[i] + 1);
            }
            sum += candies[i - 1];
        }

        // candies[n - 1] is the last child because sum += candies[i - 1] starts from i
        // = n - 1
        return sum + candies[n - 1];
    }

    private boolean isInvalidInput(int[] ratings) {
        return ratings == null || ratings.length == 0 || ratings.length > 2 * Math.pow(10, 4);
    }
}
