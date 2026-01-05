public class GenericArray<T> {
    private final T[] data;
    private int size;

    public GenericArray(int capacity) {
        this.data = (T[]) new Object[capacity];
        this.size = 0;
    }

    public GenericArray(T[] objects) {
        this.data = (T[]) new Object[objects.length];
        this.size = objects.length;
        System.arraycopy(objects, 0, this.data, 0, objects.length);
    }

    /**
     * Adds a value to the end of the array.
     *
     * @param value the value to add
     * @throws IndexOutOfBoundsException if the array is full
     */
    public void push(T value) {
        this.insert(this.size, value);
    }

    /**
     * Insert a value at the specified index.
     *
     * @param index the index to insert the value at
     * @param value the value to insert
     * @throws IndexOutOfBoundsException if the index is out of bounds or if the
     *                                   array is full
     */
    public void insert(int index, T value) {
        checkIfArraySizeIsFull();
        if (index < 0 || index > this.size) {
            throw new IndexOutOfBoundsException("Index is out of bounds: " + index);
        }

        for (int i = this.size; i > index; --i) {
            this.data[i] = this.data[i - 1];
        }
        this.data[index] = value;
        ++this.size;
    }

    /**
     * Update the value at the specified index.
     *
     * @param index the index to update the value from
     * @throws IndexOutOfBoundsException if the index is out of bounds
     */
    public void update(int index, T value) {
        checkIfIndexValid(index);

        this.data[index] = value;
    }

    /**
     * Get the value at the specified index.
     *
     * @param index the index to get the value at
     * @throws IndexOutOfBoundsException if the index is out of bounds
     */
    public T get(int index) {
        checkIfIndexValid(index);
        return this.data[index];
    }

    public int indexOf(T value) {
        for (int i = 0; i < this.size; ++i) {
            if (this.data[i].equals(value)) {
                return i;
            }
        }
        return -1;
    }

    public void remove(int index) {
        checkIfIndexValid(index);

        for (int i = index; i < this.size - 1; ++i) {
            this.data[i] = this.data[i + 1];
        }
        --this.size;
    }

    public int capacity() {
        return this.data.length;
    }

    public int size() {
        return this.size;
    }

    public boolean isEmpty() {
        return this.size == 0;
    }

    public String toString() {
        StringBuilder builder = new StringBuilder("[");
        for (int i = 0; i < size; ++i) {
            builder.append(data[i]);
            if (i < size - 1) {
                builder.append(", ");
            }
        }
        builder.append("]");
        return builder.toString();
    }

    private void checkIfIndexValid(int index) {
        if (index < 0 || index >= this.size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + this.size);
        }
    }

    private void checkIfArraySizeIsFull() {
        if (this.size >= this.data.length) {
            throw new IndexOutOfBoundsException("Array is full, cannot add more elements.");
        }
    }
}
