# Generate Parentheses

# Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

# For example, given n = 3, a solution set is:

# [
#   "((()))",
#   "(()())",
#   "(())()",
#   "()(())",
#   "()()()"
# ]

from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        answer = []
        def backtrack(s, l_count, r_count):
            if n*2 == len(s):
                answer.append(s)
                return
            
            if l_count < n:
                backtrack(s+"(", l_count+1, r_count)
            
            if r_count < l_count:
                backtrack(s+")", l_count, r_count+1)

        backtrack("", 0, 0)
        return answer




s = Solution()
s.generateParenthesis(100)