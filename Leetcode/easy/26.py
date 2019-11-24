# Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

# Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

class Solution:
    def removeDuplicates(self, nums) -> int:
        if len(nums) == 0:
            return 0
        
        last_uniq = 0
        for i in range(1, len(nums)):
            if nums[last_uniq] == nums[i]:
                continue
            else:
                last_uniq += 1
                nums[last_uniq] = nums[i]
        return len(nums[:last_uniq+1])

arr = [1,2,3,4]
s = Solution()
print(s.removeDuplicates(arr))