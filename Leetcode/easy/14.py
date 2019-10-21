# Write a function to find the longest common prefix string amongst an array of strings.

# If there is no common prefix, return an empty string "".

# Example 1:

# Input: ["flower","flow","flight"]
# Output: "fl"
# Example 2:

# Input: ["dog","racecar","car"]
# Output: ""
# Explanation: There is no common prefix among the input strings.

class Solution:
    def longestCommonPrefix(self, strs):
        index = 0
        prefix = ""

        while True:
            try:
                current_letter = strs[0][index]

                for word in strs:
                    if current_letter != word[index]:
                        return prefix
                index += 1
                prefix += current_letter
            except IndexError:
                return prefix
