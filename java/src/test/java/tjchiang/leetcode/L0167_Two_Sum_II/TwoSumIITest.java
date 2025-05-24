package tjchiang.leetcode.L0167_Two_Sum_II;

import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

class TwoSumIITest {

    static Stream<Arguments> provideNumbersTargetValueAndExpect() {
        return Stream.of(
                Arguments.of(
                        "given [2, 7, 11, 15], then [1,2]",
                        new int[]{2, 7, 11, 15},
                        9,
                        new int[]{1, 2}
                ),
                Arguments.of(
                        "given [2, 3, 4], then [1,3]",
                        new int[]{2, 3, 4},
                        6,
                        new int[]{1, 3}
                ),
                Arguments.of(
                        "given [-1, 0], then [1,2]",
                        new int[]{-1, 0},
                        -1,
                        new int[]{1, 2}
                ),
                Arguments.of(
                        "given [-3, 3], then [1,2]",
                        new int[]{-3, 3},
                        0,
                        new int[]{1, 2}
                ),
                Arguments.of(
                        "given [5, 25, 75], then [2,3]",
                        new int[]{5, 25, 75},
                        100,
                        new int[]{2, 3}
                )
        );
    }

    @ParameterizedTest(name = "{0}")
    @MethodSource("provideNumbersTargetValueAndExpect")
    void pass(String description, int[] numbers, int targetValue, int[] expected) {
        TwoSumII target = new TwoSumII();
        int[] actual = target.solve(numbers, targetValue);
        assertArrayEquals(expected, actual);
    }
}
