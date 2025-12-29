from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val: int = val
        self.next: Optional[ListNode] = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head
        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        return prev

class SolutionRecursively:
    def reverse(self, prev: Optional[ListNode], curr: Optional[ListNode]) -> Optional[ListNode]:
        if curr is None:
            return prev

        next: Optional[ListNode] = curr.next
        curr.next = prev

        return self.reverse(curr, next)

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self.reverse(None, head)

    def reverseListRecursively(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        p = self.reverseListRecursively(head.next)
        head.next.next = head
        head.next = None
        return p
