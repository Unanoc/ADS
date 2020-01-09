# Count and Say

# The count-and-say sequence is the sequence of integers with the first five terms as following:

# 1.     1
# 2.     11
# 3.     21
# 4.     1211
# 5.     111221
# 1 is read off as "one 1" or 11.
# 11 is read off as "two 1s" or 21.
# 21 is read off as "one 2, then one 1" or 1211.

# Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

# Note: Each term of the sequence of integers will be represented as a string.

class Solution:
    def countAndSay(self, n: int) -> str:
        saying = "1"

        for i in range(n-1):
            count = 1
            temp_saying = ""
            for k in range(1, len(saying)):
                if saying[k] == saying[k-1]:
                    count += 1
                else:
                    temp_saying = "{}{}{}".format(temp_saying, count, saying[k-1])
                    count = 1

            saying = "{}{}{}".format(temp_saying, count, saying[-1])

        return saying

s = Solution()
print(s.countAndSay(10))