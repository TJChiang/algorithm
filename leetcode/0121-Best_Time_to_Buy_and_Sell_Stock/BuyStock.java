/**
 * <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock/">121.
 * Best Time to Buy and Sell Stock</a>
 */
public class BuyStock {
    public int solve(int[] prices) {
        if (prices.length < 1 || prices.length > 100_000)
            return -1;

        int result = 0;
        int minBuyPrice = Integer.MAX_VALUE;

        for (int price : prices) {
            if (price < 0 || price > 10_000)
                return -1;
            minBuyPrice = Math.min(minBuyPrice, price);
            result = Math.max(result, price - minBuyPrice);
        }

        return result;
    }
}
