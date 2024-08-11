from typing import Optional


class ListNode:

    def __init__(self, val=0, next=None):
        self.val, self.next = val, next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        slow, fast = dummy, dummy
        curr = 0
        while fast:
            if curr > n:
                slow = slow.next
            fast = fast.next
            curr += 1
        slow.next = slow.next.next
        return dummy.next