# Add Two Numbers

# You are given two non-empty linked lists representing two non-negative integers. 
# The digits are stored in reverse order and each of their nodes contain a single digit. 
# Add the two numbers and return it as a linked list.
# You may assume the two numbers do not contain any leading zero, except the number 0 itself.

# Example:

# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8
# Explanation: 342 + 465 = 807.

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
