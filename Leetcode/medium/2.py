# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def get_int_from_string(self, l):
        num_in_str = ""
        while l:
            num_in_str += str(l.val)
            l = l.next
        
        return int(num_in_str[::-1])

    def create_list_from_int(self, num):
        pointer_on_last, head= None, None

        for digit in str(num)[::-1]:
            if pointer_on_last is None:
                node = ListNode(int(digit))
                pointer_on_last = node
                head = node
            else:
                node = ListNode(int(digit))
                pointer_on_last.next = node
                pointer_on_last = pointer_on_last.next
        return head

    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        first = self.get_int_from_string(l1)
        second = self.get_int_from_string(l2)

        return self.create_list_from_int(first+second)
