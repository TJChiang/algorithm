package tjchiang.leetcode.L1061_Lexicographically_Smallest_Equivalent_String;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

class SolutionTest {

    static Stream<Arguments> provideInputsAndExpected() {
        return Stream.of(
                Arguments.of(
                        "should be \"makkek\"",
                        "parker",
                        "morris",
                        "parser",
                        "makkek"
                ),
                Arguments.of(
                        "should be \"hdld\"",
                        "hello",
                        "world",
                        "hold",
                        "hdld"
                ),
                Arguments.of(
                        "should be \"aauaaaaada\"",
                        "leetcode",
                        "programs",
                        "sourcecode",
                        "aauaaaaada"
                )
        );
    }

    @ParameterizedTest(name = "{0}")
    @MethodSource("provideInputsAndExpected")
    void pass(String description, String s1, String s2, String baseStr, String expected) {
        Solution target = new Solution();
        String actual = target.solve(s1, s2, baseStr);
        Assertions.assertEquals(expected, actual);
    }
}