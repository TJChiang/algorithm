package tjchiang.structures.linkedList;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Tag;
import org.junit.jupiter.api.Test;

import java.util.List;

@Tag("linkedList")
class SinglyLinkedListTest {

    @Test
    void testEmptyList() {
        SinglyLinkedList target = new SinglyLinkedList();
        Assertions.assertNull(target.getHead());
        Assertions.assertNull(target.getTail());
        Assertions.assertEquals(0, target.size());
    }

    @Test
    void testFromSingleNode() {
        Node node = new Node(1);
        SinglyLinkedList target = new SinglyLinkedList(node);
        Assertions.assertEquals(node, target.getHead());
        Assertions.assertEquals(node, target.getTail());
        Assertions.assertEquals(1, target.size());
    }

    @Test
    void testFromMultipleNodes() {
        Node thirdNode = new Node(3);
        Node secondNode = new Node(2, thirdNode);
        Node firstNode = new Node(1, secondNode);
        SinglyLinkedList target = new SinglyLinkedList(firstNode);
        Assertions.assertEquals(firstNode, target.getHead());
        Assertions.assertEquals(thirdNode, target.getTail());
        Assertions.assertEquals(3, target.size());
    }

    @Test
    void testFromList() {
        List<Integer> values = List.of(1, 2, 3);
        SinglyLinkedList target = new SinglyLinkedList(values);
        Assertions.assertEquals(1, target.getHead().val);
        Assertions.assertEquals(3, target.getTail().val);
        Assertions.assertEquals(values.size(), target.size());
    }

    @Test
    void testFindElement() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        Node actual = target.find(2);
        Assertions.assertNotNull(actual);
        Assertions.assertEquals(2, actual.val);
    }

    @Test
    void testElementNotFound() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        Node notFoundNode = target.find(4);
        Assertions.assertNull(notFoundNode);
    }

    @Test
    void testEmptyListFindElement() {
        SinglyLinkedList target = new SinglyLinkedList();
        Node actual = target.find(1);
        Assertions.assertNull(actual);
    }

    @Test
    void testAtIndex() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        Node actual = target.at(1);
        Assertions.assertNotNull(actual);
        Assertions.assertEquals(2, actual.val);
    }

    @Test
    void testEmptyListAtIndex() {
        SinglyLinkedList target = new SinglyLinkedList();
        Node actual = target.at(0);
        Assertions.assertNull(actual);
    }

    @Test
    void testAtOutOfBoundIndex() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        Node actual = target.at(5);
        Assertions.assertNull(actual);
    }

    @Test
    void testAtNegativeIndex() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        Node actual = target.at(-1);
        Assertions.assertNull(actual);
    }

    @Test
    void testEmptyListAddElement() {
        SinglyLinkedList target = new SinglyLinkedList();
        target.add(1);
        Assertions.assertNotNull(target.getHead());
        Assertions.assertEquals(1, target.getHead().val);
        Assertions.assertEquals(target.getHead(), target.getTail());
        Assertions.assertEquals(1, target.size());
    }

    @Test
    void testAddMultipleElements() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        target.add(888);
        target.add(666);

        Assertions.assertEquals(1, target.getHead().val);
        Assertions.assertEquals(666, target.getTail().val);
        Assertions.assertEquals(5, target.size());

        Node existNode = target.at(3);
        Assertions.assertNotNull(existNode);
        Assertions.assertEquals(888, existNode.val);
    }

    @Test
    void testAddNullNode() {
        Assertions.assertThrows(IllegalArgumentException.class, () -> {
            SinglyLinkedList target = new SinglyLinkedList();
            target.add(null);
        });
    }

    @Test
    void testEmptyListAddNode() {
        SinglyLinkedList target = new SinglyLinkedList();
        Node node = new Node(1);
        target.add(node);
        Assertions.assertNotNull(target.getHead());
        Assertions.assertEquals(1, target.getHead().val);
        Assertions.assertEquals(target.getHead(), target.getTail());
        Assertions.assertEquals(1, target.size());
    }

    @Test
    void testAddMultipleNodes() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        Node firstNode = new Node(888);
        target.add(firstNode);
        Node secondNode = new Node(666);
        target.add(secondNode);

        Assertions.assertEquals(1, target.getHead().val);
        Assertions.assertEquals(666, target.getTail().val);
        Assertions.assertEquals(secondNode, target.getTail());
        Assertions.assertEquals(5, target.size());

        Node existNode = target.at(3);
        Assertions.assertNotNull(existNode);
        Assertions.assertEquals(888, existNode.val);
        Assertions.assertEquals(firstNode, existNode);
    }

    @Test
    void testInsertValueToNegativeIndex() {
        Assertions.assertThrows(IndexOutOfBoundsException.class, () -> {
            SinglyLinkedList target = new SinglyLinkedList();
            target.insert(1, -1);
        });
    }

    @Test
    void testInsertValueToInvalidIndex() {
        Assertions.assertThrows(IndexOutOfBoundsException.class, () -> {
            SinglyLinkedList target = new SinglyLinkedList(List.of(1));
            target.insert(1, 2);
        });
    }

    @Test
    void testInsertValueAtFirstToEmptyList() {
        SinglyLinkedList target = new SinglyLinkedList();
        target.insert(123, 0);
        Assertions.assertEquals(123, target.getHead().val);
        Assertions.assertEquals(123, target.getTail().val);
        Assertions.assertEquals(1, target.size());
    }

    @Test
    void testInsertValueAtFirstToList() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        target.insert(123, 0);
        Assertions.assertEquals(123, target.getHead().val);
        Assertions.assertEquals(3, target.getTail().val);
        Assertions.assertEquals(4, target.size());
    }

    @Test
    void testInsertValueToList() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        target.insert(123, 2);
        Assertions.assertEquals(1, target.getHead().val);
        Assertions.assertEquals(3, target.getTail().val);
        Assertions.assertEquals(123, target.at(2).val);
        Assertions.assertEquals(4, target.size());
    }

    @Test
    void testInsertValueAtLastToList() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        target.insert(123, 3);
        Assertions.assertEquals(1, target.getHead().val);
        Assertions.assertEquals(123, target.getTail().val);
        Assertions.assertEquals(4, target.size());
    }

    @Test
    void testInsertNullToList() {
        Assertions.assertThrows(IllegalArgumentException.class, () -> {
            SinglyLinkedList target = new SinglyLinkedList();
            target.insert(null, 1);
        });
    }

    @Test
    void testInsertNodeToNegativeIndex() {
        Assertions.assertThrows(IndexOutOfBoundsException.class, () -> {
            SinglyLinkedList target = new SinglyLinkedList();
            target.insert(new Node(1), -1);
        });
    }

    @Test
    void testInsertNodeToInvalidIndex() {
        Assertions.assertThrows(IndexOutOfBoundsException.class, () -> {
            SinglyLinkedList target = new SinglyLinkedList(List.of(1));
            target.insert(new Node(2), 2);
        });
    }

    @Test
    void testInsertSingleNodeAtFirstToEmptyList() {
        SinglyLinkedList target = new SinglyLinkedList();
        Node node = new Node(1);
        target.insert(node, 0);
        Assertions.assertEquals(1, target.getHead().val);
        Assertions.assertEquals(1, target.getTail().val);
        Assertions.assertEquals(1, target.size());
    }

    @Test
    void testInsertMultipleNodeAtFirstToEmptyList() {
        SinglyLinkedList target = new SinglyLinkedList();
        Node node3 = new Node(3);
        Node node2 = new Node(2, node3);
        Node node1 = new Node(1, node2);
        target.insert(node1, 0);
        Assertions.assertEquals(node1, target.getHead());
        Assertions.assertEquals(1, target.getHead().val);
        Assertions.assertEquals(node3, target.getTail());
        Assertions.assertEquals(3, target.getTail().val);
        Assertions.assertEquals(3, target.size());
    }

    @Test
    void testInsertSingleNodeAtFirstToList() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        Node node = new Node(0);
        target.insert(node, 0);
        Assertions.assertEquals(node, target.getHead());
        Assertions.assertEquals(0, target.getHead().val);
        Assertions.assertEquals(3, target.getTail().val);
        Assertions.assertEquals(4, target.size());
    }

    @Test
    void testInsertMultipleNodeAtFirstToList() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        Node node3 = new Node(789);
        Node node2 = new Node(456, node3);
        Node node1 = new Node(123, node2);
        target.insert(node1, 0);
        Assertions.assertEquals(node1, target.getHead());
        Assertions.assertEquals(123, target.getHead().val);
        Assertions.assertEquals(3, target.getTail().val);
        Assertions.assertEquals(6, target.size());
    }

    @Test
    void testInsertSingleNodeToList() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        Node node = new Node(4);
        target.insert(node, 2);
        Assertions.assertEquals(1, target.getHead().val);
        Assertions.assertEquals(3, target.getTail().val);
        Assertions.assertEquals(4, target.at(2).val);
        Assertions.assertEquals(4, target.size());
    }

    @Test
    void testInsertMultipleNodeToList() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        Node node3 = new Node(789);
        Node node2 = new Node(456, node3);
        Node node1 = new Node(123, node2);
        target.insert(node1, 2);
        Assertions.assertEquals(1, target.getHead().val);
        Assertions.assertEquals(3, target.getTail().val);
        Assertions.assertEquals(123, target.at(2).val);
        Assertions.assertEquals(456, target.at(3).val);
        Assertions.assertEquals(789, target.at(4).val);
        Assertions.assertEquals(6, target.size());
    }

    @Test
    void testInsertSingleNodeAtLastToList() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        Node node = new Node(4);
        target.insert(node, 3);
        Assertions.assertEquals(1, target.getHead().val);
        Assertions.assertEquals(4, target.getTail().val);
        Assertions.assertEquals(node, target.getTail());
        Assertions.assertEquals(4, target.size());
    }

    @Test
    void testInsertMultipleNodeAtLastToList() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        Node node3 = new Node(789);
        Node node2 = new Node(456, node3);
        Node node1 = new Node(123, node2);
        target.insert(node1, 3);
        Assertions.assertEquals(1, target.getHead().val);
        Assertions.assertEquals(123, target.at(3).val);
        Assertions.assertEquals(456, target.at(4).val);
        Assertions.assertEquals(789, target.getTail().val);
        Assertions.assertEquals(node3, target.getTail());
        Assertions.assertEquals(6, target.size());
    }

    @Test
    void testRemoveFromEmptyList() {
        SinglyLinkedList target = new SinglyLinkedList();
        Assertions.assertEquals(0, target.size());
        target.remove(123);
        Assertions.assertNull(target.getHead());
        Assertions.assertNull(target.getTail());
        Assertions.assertEquals(0, target.size());
    }

    @Test
    void testRemoveSingleElementFromOnlyOneList() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1));
        Assertions.assertEquals(1, target.size());
        target.remove(1);
        Assertions.assertNull(target.getHead());
        Assertions.assertNull(target.getTail());
        Assertions.assertEquals(0, target.size());
    }

    @Test
    void testRemoveSingleHeadElement() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        Assertions.assertEquals(3, target.size());
        target.remove(1);
        Assertions.assertEquals(2, target.getHead().val);
        Assertions.assertEquals(3, target.getTail().val);
        Assertions.assertEquals(2, target.size());
    }

    @Test
    void testRemoveSingleTailElement() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        Assertions.assertEquals(3, target.size());
        target.remove(3);
        Assertions.assertEquals(1, target.getHead().val);
        Assertions.assertEquals(2, target.getTail().val);
        Assertions.assertEquals(2, target.size());
    }

    @Test
    void testRemoveNotFoundElement() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        target.remove(4);
        Assertions.assertEquals(1, target.getHead().val);
        Assertions.assertEquals(3, target.getTail().val);
        Assertions.assertEquals(3, target.size());
    }

    @Test
    void testRemoveFirstElement() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3, 4, 2, 8));
        Assertions.assertEquals(6, target.size());
        target.remove(2);
        Assertions.assertEquals(1, target.getHead().val);
        Assertions.assertEquals(8, target.getTail().val);
        Assertions.assertEquals(3, target.at(1).val);
        Assertions.assertEquals(2, target.at(3).val);
        Assertions.assertEquals(5, target.size());
    }

    @Test
    void testRemoveAllElement() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 1, 1, 2, 3, 1, 4, 1));
        Assertions.assertEquals(1, target.getHead().val);
        Assertions.assertEquals(1, target.getTail().val);
        Assertions.assertEquals(8, target.size());
        target.removeAll(1);
        Assertions.assertEquals(2, target.getHead().val);
        Assertions.assertEquals(3, target.at(1).val);
        Assertions.assertEquals(4, target.getTail().val);
        Assertions.assertEquals(3, target.size());
    }

    @Test
    void testRemoveAllElementToEmptyList() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 1, 1));
        Assertions.assertEquals(1, target.getHead().val);
        Assertions.assertEquals(1, target.getTail().val);
        Assertions.assertEquals(3, target.size());
        target.removeAll(1);
        Assertions.assertNull(target.getHead());
        Assertions.assertNull(target.getTail());
        Assertions.assertEquals(0, target.size());
    }

    @Test
    void testClearList() {
        SinglyLinkedList target = new SinglyLinkedList(List.of(1, 2, 3));
        Assertions.assertEquals(3, target.size());
        target.clear();
        Assertions.assertNull(target.getHead());
        Assertions.assertNull(target.getTail());
        Assertions.assertEquals(0, target.size());
    }
}