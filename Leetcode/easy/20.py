# Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

# An input string is valid if:

# Open brackets must be closed by the same type of brackets.
# Open brackets must be closed in the correct order.
# Note that an empty string is also considered valid.

# Example 1:

# Input: "()"
# Output: true
# Example 2:

# Input: "()[]{}"
# Output: true
# Example 3:

# Input: "(]"
# Output: false
# Example 4:

# Input: "([)]"
# Output: false
# Example 5:

# Input: "{[]}"
# Output: true

def is_opened(s):
    if s == '(' or s == '{' or s == '[':
        return True
    return False


class Solution:
    def isValid(self, s):
        if len(s) == 0:
            return True
        
        stack = list()
        mapping = {'}':'{', ')':'(', ']':'['}

        for i in s:
            if is_opened(i):
                stack.append(i)
            elif len(stack) > 0 and mapping[i] == stack.pop():
                continue
            else:
                return False

        if len(stack) != 0:
            return False

        return True
