package tjchiang.structures.array;

import org.junit.jupiter.api.Tag;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

import static org.junit.jupiter.api.Assertions.*;

class GenericArrayTest {
    private static final int CAPACITY = 5;

    static Stream<Arguments> provideInvalidIndicesForInsertMethod() {
        return Stream.of(
                Arguments.of("negative index", -1),
                Arguments.of("index greater than size", 2)
        );
    }

    static Stream<Arguments> provideInvalidIndicesForGetterMethod() {
        return Stream.of(
                Arguments.of("negative index", -1),
                Arguments.of("index equals size", 1),
                Arguments.of("index greater than size", 2)
        );
    }

    @Test
    @Tag("GenericArray.capacity")
    void capacity_should_be_array_capacity() {
        int expectedCapacity = CAPACITY;
        GenericArray<Integer> target = new GenericArray<>(expectedCapacity);
        assertEquals(expectedCapacity, target.capacity());
    }

    @Test
    @Tag("GenericArray.size")
    void size_should_be_array_size() {
        GenericArray<String> target = new GenericArray<>(CAPACITY);
        assertEquals(0, target.size());
        target.push("10");
        assertEquals(1, target.size());
    }

    @Test
    @Tag("GenericArray.isEmpty")
    void array_should_be_empty_when_no_value_pushed() {
        GenericArray<Long> target = new GenericArray<>(5);
        assertEquals(0, target.size());
        assertTrue(target.isEmpty());
    }

    @Test
    @Tag("GenericArray.push")
    void should_throw_exception_when_pushing_to_full_array() {
        GenericArray<Integer> target = new GenericArray<>(0);
        assertThrows(
                IndexOutOfBoundsException.class,
                () -> target.push(10)
        );
    }

    @Test
    @Tag("GenericArray.push")
    void array_should_have_value_and_size_increase_after_push() {
        GenericArray<Boolean> target = new GenericArray<>(CAPACITY);
        target.push(true);
        assertEquals(1, target.size());
        assertFalse(target.isEmpty());
    }

    @Test
    @Tag("GenericArray.insert")
    void should_throw_exception_when_inserting_to_full_array() {
        int whateverValue = 10;
        GenericArray<Integer> target = new GenericArray<>(0);
        assertThrows(
                IndexOutOfBoundsException.class,
                () -> target.insert(0, whateverValue)
        );
    }

    @ParameterizedTest(name = "{0}")
    @Tag("GenericArray.insert")
    @MethodSource("provideInvalidIndicesForInsertMethod")
    void should_throw_exception_when_inserting_to_invalid_index(String description, int index) {
        int whateverValue = 10;
        GenericArray<Integer> target = new GenericArray<>(2);
        target.push(whateverValue);
        assertThrows(
                IndexOutOfBoundsException.class,
                () -> target.insert(index, whateverValue)
        );
    }

    @Test
    @Tag("GenericArray.insert")
    void should_insert_value_at_index() {
        GenericArray<Integer> target = new GenericArray<>(CAPACITY);
        target.push(10);
        target.push(20);
        target.insert(1, 15);
        target.insert(target.size(), 25);

        assertEquals(4, target.size());
        assertEquals(10, target.get(0));
        assertEquals(15, target.get(1));
        assertEquals(20, target.get(2));
        assertEquals(25, target.get(3));
    }

    @ParameterizedTest(name = "{0}")
    @Tag("GenericArray.update")
    @MethodSource("provideInvalidIndicesForGetterMethod")
    void should_throw_exception_when_updating_value_from_invalid_index(String description, int index) {
        int whateverValue = 10;
        GenericArray<Integer> target = new GenericArray<>(2);
        target.push(whateverValue);
        assertThrows(
                IndexOutOfBoundsException.class,
                () -> target.update(index, whateverValue)
        );
    }

    @Test
    @Tag("GenericArray.update")
    void should_update_value_at_index() {
        GenericArray<Integer> target = new GenericArray<>(CAPACITY);
        target.push(10);
        target.push(20);
        assertEquals(10, target.get(0));
        assertEquals(20, target.get(1));

        target.update(0, 15);
        target.update(1, 25);
        assertEquals(2, target.size());
        assertEquals(15, target.get(0));
        assertEquals(25, target.get(1));
    }

    @ParameterizedTest(name = "{0}")
    @Tag("GenericArray.get")
    @MethodSource("provideInvalidIndicesForGetterMethod")
    void should_throw_exception_when_getting_value_from_invalid_index(String description, int index) {
        GenericArray<Integer> target = new GenericArray<>(2);
        target.push(10);
        assertThrows(
                IndexOutOfBoundsException.class,
                () -> target.get(index)
        );
    }

    @Test
    @Tag("GenericArray.get")
    void should_get_value_at_index() {
        GenericArray<Integer> target = new GenericArray<>(new Integer[]{10, 20});
        assertEquals(10, target.get(0));
        assertEquals(20, target.get(1));
    }

    @Test
    @Tag("GenericArray.indexOf")
    void should_return_index_of_value() {
        GenericArray<Integer> target = new GenericArray<>(new Integer[]{10, 20, 30});
        assertEquals(-1, target.indexOf(40));
        assertEquals(0, target.indexOf(10));
        assertEquals(1, target.indexOf(20));
        assertEquals(2, target.indexOf(30));
    }

    @ParameterizedTest(name = "{0}")
    @Tag("GenericArray.remove")
    @MethodSource("provideInvalidIndicesForGetterMethod")
    void should_throw_exception_when_removing_value_from_invalid_index(String description, int index) {
        GenericArray<Integer> target = new GenericArray<>(2);
        target.push(10);
        assertThrows(
                IndexOutOfBoundsException.class,
                () -> target.remove(index)
        );
    }

    @Test
    @Tag("GenericArray.remove")
    void should_remove_value_at_index() {
        GenericArray<Integer> target = new GenericArray<>(new Integer[]{10, 20, 30});
        assertEquals(3, target.size());

        target.remove(1);
        assertEquals(2, target.size());
        assertEquals(10, target.get(0));
        assertEquals(30, target.get(1));

        target.remove(0);
        assertEquals(1, target.size());
        assertEquals(30, target.get(0));

        target.remove(0);
        assertEquals(0, target.size());
    }

    @Test
    @Tag("GenericArray.toString")
    void should_print_all_elements_of_array() {
        GenericArray<Boolean> target = new GenericArray<>(new Boolean[]{true, false, true});
        assertEquals("[true, false, true]", target.toString());
    }
}