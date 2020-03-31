# Merge k Sorted Lists

# Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

# Example:

# Input:
# [
#   1->4->5,
#   1->3->4,
#   2->6
# ]
# Output: 1->1->2->3->4->4->5->6

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        # Создали указатель результатного списка с первым минимальным элементом
        result = None
        min_value = lists[0].val
        min_index = 0

        for i in range(1, len(lists)):
            if lists[i].val < min_value:
                min_index = i
        result = lists[min_index]
        lists[min_index] = lists[min_index].next

        # Обходим указателями все списки до тех пор пока все указатели в lists не будут смотреть на NULL (None)

        def are_all_ptrs_NULL(lists):
            counter = len(lists)
            for i in lists:
                if i is None:
                    counter -= 1
            return True if counter == 0 else False

        while (are_all_ptrs_NULL(lists)):
            min_value = None
            min_index = 0
            for i in range(len(lists)):
                if lists[i] is None:
                    continue

                if min_value is None:
                    min_value = lists[i].val
                else:
                    if lists[i].val < min_value:
                        min_value = lists[i].val
                        min_index = i

            result.next = lists[min_index]
            result = result.next
            lists[min_index] = lists[min_index].next
        
        result.next = None

        return result

