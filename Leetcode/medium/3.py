# Longest Substring Without Repeating Characters

# Given a string, find the length of the longest substring without repeating characters.

# Example 1:

# Input: "abcabcbb"
# Output: 3 
# Explanation: The answer is "abc", with the length of 3. 
# Example 2:

# Input: "bbbbb"
# Output: 1
# Explanation: The answer is "b", with the length of 1.
# Example 3:

# Input: "pwwkew"
# Output: 3
# Explanation: The answer is "wke", with the length of 3. 
#              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution:
    def lengthOfLongestSubstring(self, s):
        max_len = 0

        for i in range(len(s)):
            uniqs = {}
            for j in range(len(s)-i):
                if s[i + j] not in uniqs:
                    uniqs[s[i + j]] = True
                    if max_len < j+1:
                        max_len = j+1
                    print(uniqs)
                else:
                    if max_len < j:
                        max_len = j
                    break

        return max_len

s = Solution()

print(s.lengthOfLongestSubstring(" "))
print(s.lengthOfLongestSubstring("abcdabcbb"))