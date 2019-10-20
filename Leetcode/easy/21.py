# Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

# Example:

# Input: 1->2->4, 1->3->4
# Output: 1->1->2->3->4->4


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def mergeTwoLists(l1, l2):
    if l1 is None or l2 is None:
        return l1 or l2

    root = None
    if l1.val <= l2.val:
        root = l1
        l1 = l1.next
    else:
        root = l2
        l2 = l2.next

    tmp = root

    while l1 and l2:
        if l1.val <= l2.val:
            tmp.next = l1
            l1 = l1.next
        else:
            tmp.next = l2
            l2 = l2.next
        tmp = tmp.next
    
    while l1:
        tmp.next = l1
        l1 = l1.next
        tmp = tmp.next
    while l2:
        tmp.next = l2
        l2 = l2.next
        tmp = tmp.next

    return root