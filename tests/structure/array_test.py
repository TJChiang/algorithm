import pytest
from structures.python.array import Array

class TestArray:
    @pytest.mark.parametrize("capacity, size, is_empty", [
        (0, 0, True),
        (100, 0, True),
    ])
    def test_initialized_array(self, capacity, size, is_empty):
        array: Array = Array(capacity)
        assert array.capacity() == capacity
        assert array.size() == size
        assert array.is_empty() == is_empty

    def test_initialized_array_with_invalid_args(self):
        with pytest.raises(ValueError):
            array: Array = Array(-1)
