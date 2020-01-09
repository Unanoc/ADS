# Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

# Symbol       Value
# I             1
# V             5
# X             10
# L             50
# C             100
# D             500
# M             1000


class Solution:
    def romanToInt(self, s: str) -> int:
        mapRomanInt = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        
        result = mapRomanInt[s[0]]
        prev = mapRomanInt[s[0]]

        for i in range(1, len(s)):
            if mapRomanInt[s[i]] > prev:
                result += mapRomanInt[s[i]] - 2*prev
            else:
                result += mapRomanInt[s[i]]
            prev = mapRomanInt[s[i]]

        return result
