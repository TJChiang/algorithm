package tjchiang.leetcode.L0003_Longest_Substring_Without_Repeating_Characters;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

class LongestSubstringTest {

    static Stream<Arguments> provideInputAndExpected() {
        return Stream.of(
                Arguments.of("abcabcbb", 3),
                Arguments.of("bbbbb", 1),
                Arguments.of("pwwkew", 3),
                Arguments.of("", 0),
                Arguments.of("a", 1),
                Arguments.of("dvdf", 3)
        );
    }

    @ParameterizedTest()
    @MethodSource("provideInputAndExpected")
    void passBySet(String s, int expected) {
        LongestSubstring longestSubstring = new LongestSubstring();
        int actual = longestSubstring.solveBySet(s);
        Assertions.assertEquals(expected, actual);
    }

    @ParameterizedTest()
    @MethodSource("provideInputAndExpected")
    void passByLastIndex(String s, int expected) {
        LongestSubstring longestSubstring = new LongestSubstring();
        int actual = longestSubstring.solveByLastIndex(s);
        Assertions.assertEquals(expected, actual);
    }
}