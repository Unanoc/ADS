#  Longest Palindromic Substring

# Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

# Example 1:

# Input: "babad"
# Output: "bab"
# Note: "aba" is also a valid answer.
# Example 2:

# Input: "cbbd"
# Output: "bb"

class Solution:
    def longestPalindrome(self, s: str) -> str:
        longest_palindorm = ""

        for i in range(len(s)):
            for j in range(len(s), i, -1):
                if len(longest_palindrom) >= j-i:
                    break
                elif s[i:j] == s[i:j][::-1]:
                    longest_palindorm = s[i:j]
                    break
        
        return longest_palindorm