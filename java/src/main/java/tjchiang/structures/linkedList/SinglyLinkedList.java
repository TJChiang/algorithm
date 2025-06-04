package tjchiang.structures.linkedList;

import java.util.List;

public class SinglyLinkedList {

    private Node head = null;
    private Node tail = null;
    private int size = 0;

    public SinglyLinkedList() {
    }

    public SinglyLinkedList(Node head) {
        this.add(head);
    }

    public SinglyLinkedList(List<Integer> values) {
        for (int value : values) {
            this.add(value);
        }
    }

    public Node getHead() {
        return this.head;
    }

    public Node getTail() {
        return this.tail;
    }

    public int size() {
        return this.size;
    }

    public Node find(int value) {
        if (this.head == null) return null;

        Node curr = this.head;
        while (curr != null) {
            if (curr.val == value) return curr;
            curr = curr.next;
        }

        return null;
    }

    public Node at(int index) {
        if (index < 0 || this.head == null) return null;

        Node curr = this.head;
        int count = 0;
        while (curr != null) {
            if (count == index) return curr;
            curr = curr.next;
            count++;
        }

        return null;
    }

    public void add(int value) {
        Node newNode = new Node(value);
        if (this.head == null) {
            this.head = newNode;
            this.tail = newNode;
            this.size++;
            return;
        }
        this.size++;
        this.tail.next = newNode;
        this.tail = this.tail.next;
    }

    public void add(Node node) {
        if (node == null) {
            throw new IllegalArgumentException("Node cannot be null");
        }
        if (this.head == null) {
            this.head = node;
            this.tail = node;
            this.size = 1;
        } else {
            this.tail.next = node;
        }

        while (this.tail.next != null) {
            this.tail = this.tail.next;
            this.size++;
        }
    }

    public void insert(int value, int index) {
        if (index < 0) {
            throw new IndexOutOfBoundsException("Index cannot be negative");
        }

        Node newNode = new Node(value);
        if (index == 0) {
            newNode.next = this.head;
            this.head = newNode;
            if (this.tail == null) this.tail = newNode;
            this.size++;
            return;
        }

        Node curr = this.head;
        int count = 0;
        while (curr != null && count < index - 1) {
            curr = curr.next;
            count++;
        }

        if (curr == null) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }

        this.size++;
        newNode.next = curr.next;
        curr.next = newNode;
        if (newNode.next == null) this.tail = newNode;
    }

    public void insert(Node node, int index) {
        if (node == null) {
            throw new IllegalArgumentException("Node cannot be null");
        }
        if (index < 0) {
            throw new IndexOutOfBoundsException("Index cannot be negative");
        }

        if (index == 0) {
            Node temp = node;
            this.size++;
            while (temp.next != null) {
                temp = temp.next;
                this.size++;
            }
            temp.next = this.head;
            this.head = node;
            if (this.tail == null) this.tail = temp;
            return;
        }

        Node curr = this.head;
        int count = 0;
        while (curr != null && count < index - 1) {
            curr = curr.next;
            count++;
        }

        if (curr == null) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }

        Node temp = node;
        this.size++;
        while (temp.next != null) {
            temp = temp.next;
            this.size++;
        }
        temp.next = curr.next;
        curr.next = node;
        if (temp.next == null) this.tail = temp;
    }

    public void remove(int value) {
        if (this.head == null) return;

        if (this.head.val == value) {
            this.head = this.head.next;
            if (this.head == null) this.tail = null;
            this.size--;
            return;
        }

        Node curr = this.head;
        while (curr.next != null) {
            if (curr.next.val == value) {
                curr.next = curr.next.next;
                if (curr.next == null) this.tail = curr;
                this.size--;
                return;
            }
            curr = curr.next;
        }
    }

    public void removeAll(int value) {
        while (this.head != null && this.head.val == value) {
            this.head = this.head.next;
            this.size--;
        }
        if (this.head == null) {
            this.tail = null;
            return;
        }

        Node curr = this.head;
        while (curr.next != null) {
            if (curr.next.val != value) {
                curr = curr.next;
                continue;
            }

            curr.next = curr.next.next;
            if (curr.next == null) this.tail = curr;
            this.size--;
        }
    }

    public void clear() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }
}
