package tjchiang.structures.linkedList;

public class SinglyLinkedList {

    private Node head = null;
    private Node tail = null;

    public SinglyLinkedList() {
    }

    public SinglyLinkedList(Node head) {
        this.head = head;
        this.tail = head;
        if (head != null) {
            while (this.tail.next != null)
                this.tail = this.tail.next;
        }
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
            return;
        }
        this.tail.next = newNode;
        this.tail = this.tail.next;
    }

    public void add(Node node) {
        if (node == null) return;
        if (this.head == null) {
            this.head = node;
            this.tail = node;
            return;
        }
        this.tail.next = node;
        this.tail = this.tail.next;
    }

    public void insert(int value, int index) {
        if (index < 0) return;

        Node newNode = new Node(value);
        if (index == 0) {
            newNode.next = this.head;
            this.head = newNode;
            if (this.tail == null) this.tail = newNode;
            return;
        }

        Node curr = this.head;
        int count = 0;
        while (curr != null && count < index - 1) {
            curr = curr.next;
            count++;
        }

        if (curr == null) return;

        newNode.next = curr.next;
        curr.next = newNode;
        if (newNode.next == null) this.tail = newNode;
    }

    public void insert(Node node, int index) {
        if (node == null || index < 0) return;

        if (index == 0) {
            node.next = this.head;
            this.head = node;
            if (this.tail == null) this.tail = node;
            return;
        }

        Node curr = this.head;
        int count = 0;
        while (curr != null && count < index - 1) {
            curr = curr.next;
            count++;
        }

        if (curr == null) return;

        node.next = curr.next;
        curr.next = node;
        if (node.next == null) this.tail = node;
    }

    public void remove(int value) {
        if (this.head == null) return;

        if (this.head.val == value) {
            this.head = this.head.next;
            if (this.head == null) this.tail = null;
            return;
        }

        Node curr = this.head;
        while (curr.next != null) {
            if (curr.next.val == value) {
                curr.next = curr.next.next;
                if (curr.next == null) this.tail = curr;
                return;
            }
            curr = curr.next;
        }
    }

    public void removeAll(int value) {
        while (this.head != null && this.head.val == value) {
            this.head = this.head.next;
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
        }
    }

    public void clear() {
        this.head = null;
        this.tail = null;
    }
}
