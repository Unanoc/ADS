package leetcode

import (
	"strings"
	"unicode"
)

func validPalindrom(input string) bool {
	modifiedString := strings.ToUpper(input)

	arr := []rune(modifiedString)
	left, right := 0, len(arr)-1

	for left <= right {
		if !unicode.IsLetter(arr[left]) && !unicode.IsDigit(arr[left]) {
			left++
			continue
		}
		if !unicode.IsLetter(arr[right]) && !unicode.IsDigit(arr[right]) {
			right--
			continue
		}

		if arr[left] != arr[right] {
			return false
		}
		left++
		right--
	}

	return true
}
