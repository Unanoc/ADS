# Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

# Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

class Solution:
    def remove_duplicates(self, nums):
        if len(nums) == 0:
            return 0
        
        last = 0
        for i in range(1, len(nums)-1):
            if nums[i] != nums[i-1]:
                last += 1
                nums[last] = nums[i]

        return last+1


arr = [1,1,1,1,2,2,3,3,4]
print(remove_duplicates(arr), arr)