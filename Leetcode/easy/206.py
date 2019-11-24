# Reverse Linked List

# Reverse a singly linked list.

# Example:

# Input: 1->2->3->4->5->NULL
# Output: 5->4->3->2->1->NULL


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None:
            return None

        if head.next is None:
            return head
        
        cur, tmp = head, head.next
        head.next = None
        cur, tmp = tmp, tmp.next

        while tmp is not None:
            cur.next = head
            head = cur
            cur, tmp = tmp, tmp.next
        
        if cur is not None:
            cur.next = head
            head = cur
            cur = None

        return head


a = ListNode(1)
b = ListNode(2)
c = ListNode(3)
d = ListNode(4)

a.next = b
b.next = c
c.next = d

s = Solution()
res = s.reverseList(a)

while res is not None:
    print(res.val)
    res = res.next
