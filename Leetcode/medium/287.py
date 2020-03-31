# Find the Duplicate Number

# Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
# prove that at least one duplicate number must exist. Assume that there is only one duplicate number, 
# find the duplicate one.

# Example 1:

# Input: [1,3,4,2,2]
# Output: 2
# Example 2:

# Input: [3,1,3,4,2]
# Output: 3
# Note:

# You must not modify the array (assume the array is read only).
# You must use only constant, O(1) extra space.
# Your runtime complexity should be less than O(n2).
# There is only one duplicate number in the array, but it could be repeated more than once.


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # Find the intersection point of the two runners.
        tortoise = nums[0]
        hare = nums[0]
        
        while True:
            tortoise = nums[tortoise]
            hare = nums[nums[hare]]
            
            if tortoise == hare:
                break
            # Почему не можем сразу вернуть это число? Потому что эта часть кода
            # находит только опорную точку (в связном списке этот алгоритм доказывает существование цикла).
            # В этой части кода два поинтера могли встретиться на одной и той же ноде у рандомного числа, неодбязательно
            # у того, у которого есть повторения
                

        # Find the "entrance" to the cycle.

        # А этот второй цикл нужен для того, чтобы найти "вход" в цикл, он как раз и является тем повторяющимся элементом, 
        # который создает цикл
        ptr1 = nums[0]
        ptr2 = tortoise
        
        while ptr1 != ptr2:
            ptr1 = nums[ptr1]
            ptr2 = nums[ptr2]
        
        return ptr1