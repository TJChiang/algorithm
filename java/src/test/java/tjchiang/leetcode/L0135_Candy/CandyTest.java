package tjchiang.leetcode.L0135_Candy;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

class CandyTest {

    static Stream<Arguments> provideRatingsAndExpect() {
        return Stream.of(
                Arguments.of(
                        new int[]{1, 0, 2},
                        5
                ),
                Arguments.of(
                        new int[]{1, 2, 2},
                        4
                ),
                Arguments.of(
                        new int[]{1, 3, 2, 2, 1},
                        7
                ),
                Arguments.of(
                        new int[]{1, 2, 3, 4, 5},
                        15
                ),
                Arguments.of(
                        new int[]{5, 4, 3, 2, 1},
                        15
                )
        );
    }

    @ParameterizedTest
    @MethodSource("provideRatingsAndExpect")
    void pass(int[] ratings, int expected) {
        Candy target = new Candy();
        int actual = target.candy(ratings);
        Assertions.assertEquals(expected, actual);
    }
}