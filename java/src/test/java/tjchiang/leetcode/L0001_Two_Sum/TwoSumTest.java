package tjchiang.leetcode.L0001_Two_Sum;

import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

class TwoSumTest {

    @ParameterizedTest
    @MethodSource("provideNumsTargetValueAndExpect")
    void pass(int[] nums, int targetValue, int[] expected) {
        TwoSum target = new TwoSum();
        int[] actual = target.solve(nums, targetValue);
        assertArrayEquals(expected, actual);
    }

    static Stream<Arguments> provideNumsTargetValueAndExpect() {
        return Stream.of(
            Arguments.of(
                    new int[]{2, 7, 11, 15},
                    9,
                    new int[]{0, 1}
            ),
            Arguments.of(
                    new int[]{3, 2, 4},
                    6,
                    new int[]{1, 2}
            ),
            Arguments.of(
                    new int[]{3, 3},
                    6,
                    new int[]{0, 1}
            ),
            Arguments.of(
                    new int[]{1, 2, 3},
                    7,
                    new int[]{}
            )
        );
    }
}
