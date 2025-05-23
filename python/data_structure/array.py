class Array:
    def __init__(self, capacity: int = 0):
        if capacity < 0:
            raise ValueError("capacity must be non-negative")
        self._capacity = capacity
        self._size = 0
        self._data = [None] * capacity

    def __getitem__(self, index: int) -> object:
        if (self._isIndexValid(index)):
            raise IndexError("Index out of range")
        return self._data[index]

    def __setitem__(self, index: int, value: object):
        if (self._isIndexValid(index)):
            raise IndexError("Index out of range")
        self._data[index] = value

    def __len__(self) -> int:
        return self._size

    def __iter__(self):
        for item in self._data:
            yield item

    def _isIndexValid(self, index: int) -> bool:
        return 0 <= index < self._size

    def _resize(self) -> None:
        self._capacity *= 2
        new_data = [None] * self._capacity
        for i in range(self.size()):
            new_data[i] = self._data[i]
        self._data = new_data

    def capacity(self) -> int:
        return self._capacity

    def size(self) -> int:
        return self._size

    def is_empty(self) -> bool:
        return self._size == 0

    def get(self, index: int, default: object = None) -> object:
        if not self._isIndexValid(index):
            return default
        return self._data[index]

    def indexOf(self, value: object) -> int:
        for i in range(self.size()):
            if self._data[i] == value:
                return i
        return -1

    def remove(self, index: int) -> object:
        """Remove the element at the specified index and return it."""
        if not self._isIndexValid(index):
            return None

        for i in range(self.size()):
            if i == index:
                target = self._data[i]
                self._data[i] = None
                while i + 1 < self.size():
                    self._data[i] = self._data[i + 1]
                    i += 1
                self._size -= 1
                return target
        return None

    def delete(self, value: object) -> None:
        """Remove the first occurrence of the specified value."""
        for i in range(self.size()):
            if self._data[i] == value:
                self._data[i] = None
                while i + 1 < self.size():
                    self._data[i] = self._data[i + 1]
                    i += 1
                self._size -= 1
                return

    def append(self, value: object) -> None:
        if self._size == self._capacity:
            self._resize()
        self._data[self._size] = value
        self._size += 1

    def insert(self, index: int, value: object) -> None:
        if index < 0 or index > self.size():
            return

        if self._size == self._capacity:
            self._resize()

        for i in range(self.size(), index, -1):
            self._data[i] = self._data[i - 1]
        self._data[index] = value
        self._size += 1

    def print_all(self) -> None:
        for item in self._data:
            print(item)
