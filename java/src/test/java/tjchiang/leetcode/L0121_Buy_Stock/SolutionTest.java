package tjchiang.leetcode.L0121_Buy_Stock;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

class SolutionTest {

    static Stream<Arguments> provideInputsAndExpected() {
        return Stream.of(
                Arguments.of(new int[]{7, 1, 5, 3, 6, 4}, 5),
                Arguments.of(new int[]{7, 6, 4, 3, 1}, 0),
                Arguments.of(new int[]{2, 1}, 0),
                Arguments.of(new int[]{2}, 0),
                Arguments.of(new int[]{2, 4}, 2),
                Arguments.of(new int[]{2, 4, 1}, 2)
        );
    }

    @ParameterizedTest
    @MethodSource("provideInputsAndExpected")
    void pass(int[] prices, int expected) {
        Solution solution = new Solution();
        int actual = solution.solve(prices);
        Assertions.assertEquals(expected, actual);
    }
}