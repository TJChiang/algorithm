package tjchiang.leetcode.L0070_Climbing_Stairs;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

class ClimbingStairsTest {

    static Stream<Arguments> provideInputAndExpect() {
        return Stream.of(
                Arguments.of(1, 1),
                Arguments.of(2, 2),
                Arguments.of(3, 3),
                Arguments.of(4, 5),
                Arguments.of(5, 8),
                Arguments.of(6, 13),
                Arguments.of(7, 21),
                Arguments.of(8, 34),
                Arguments.of(9, 55),
                Arguments.of(10, 89),
                Arguments.of(11, 144),
                Arguments.of(12, 233),
                Arguments.of(13, 377),
                Arguments.of(14, 610),
                Arguments.of(15, 987)
        );
    }

    @ParameterizedTest
    @MethodSource("provideInputAndExpect")
    void solveOrigin(int n, int expected) {
        ClimbingStairs target = new ClimbingStairs();
        int actual = target.solveOrigin(n);
        Assertions.assertEquals(expected, actual);
    }

    @ParameterizedTest
    @MethodSource("provideInputAndExpect")
    void solveIterative(int n, int expected) {
        ClimbingStairs target = new ClimbingStairs();
        int actual = target.solveIterative(n);
        Assertions.assertEquals(expected, actual);
    }

    @ParameterizedTest
    @MethodSource("provideInputAndExpect")
    void solveRecursive(int n, int expected) {
        ClimbingStairs target = new ClimbingStairs();
        int actual = target.solveRecursive(n);
        Assertions.assertEquals(expected, actual);
    }
}