public class CustomArray {
    private final int[] data;
    private int size;

    public CustomArray(int capacity) {
        this.data = new int[capacity];
        this.size = 0;
    }

    public CustomArray(int[] initialData) {
        this.data = new int[initialData.length];
        System.arraycopy(initialData, 0, this.data, 0, initialData.length);
        this.size = initialData.length;
    }

    /**
     * Adds a value to the end of the array.
     *
     * @param value the value to add
     * @throws IndexOutOfBoundsException if the array is full
     */
    public void push(int value) {
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
    public void insert(int index, int value) {
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
    public void update(int index, int value) {
        checkIfIndexValid(index);

        this.data[index] = value;
    }

    /**
     * Get the value at the specified index.
     *
     * @param index the index to get the value at
     * @throws IndexOutOfBoundsException if the index is out of bounds
     */
    public int get(int index) {
        checkIfIndexValid(index);
        return this.data[index];
    }

    public int indexOf(int value) {
        for (int i = 0; i < this.size; ++i) {
            if (this.data[i] == value) {
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

    public void printAll() {
        System.out.print("[");
        for (int i = 0; i < size; ++i) {
            System.out.print(data[i]);
            if (i < size - 1) {
                System.out.print(", ");
            }
        }
        System.out.print("]");
        System.out.println();
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
