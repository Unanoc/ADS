# Integer to Roman

# Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

# Symbol       Value
# I             1
# V             5
# X             10
# L             50
# C             100
# D             500
# M             1000
# For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

# Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

# I can be placed before V (5) and X (10) to make 4 and 9. 
# X can be placed before L (50) and C (100) to make 40 and 90. 
# C can be placed before D (500) and M (1000) to make 400 and 900.
# Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

# Example 1:

# Input: 3
# Output: "III"
# Example 2:

# Input: 4
# Output: "IV"
# Example 3:

# Input: 9
# Output: "IX"
# Example 4:

# Input: 58
# Output: "LVIII"
# Explanation: L = 50, V = 5, III = 3.
# Example 5:

# Input: 1994
# Output: "MCMXCIV"
# Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


class Solution:
    mapRomanInt = {
        1: 'I',
        5: 'V',
        10: 'X',
        50: 'L',
        100: 'C',
        500: 'D',
        1000: 'M',
    }

    mapRomanIntReversed = {
        1000: 'M',
        500: 'D',
        100: 'C',
        50: 'L',
        10: 'X',
        5: 'V',
        1: 'I',
    }

    def intToRoman(self, num: int) -> str:
        if num < 1 or num > 3999:
            return False
        
        decade = 0
        result = ""

        while num != 0:
            x = num % 10
            num = num // 10

            result = "{}{}".format(self.get_roman_from_int(x, decade), result) if x != 0 else result
            decade += 1
        
        return result
    
    def get_roman_from_int(self, x: int, decade: int) -> str:
        if x == 9 or x == 4:
            for k, v in self.mapRomanInt.items():
                if x*(10**decade) < k:
                    return self.mapRomanInt[k-x*(10**decade)] + self.mapRomanInt[k]

        result = ""
        num = x*(10**decade)
        for k, v in self.mapRomanIntReversed.items():
            if num == 0:
                break

            while k <= num:
                result += self.mapRomanInt[k]
                num -= k
        return result








s = Solution()
print(s.intToRoman(1998))