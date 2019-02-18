package leetcode

// Дана последовательность 0 и 1, найти макс последовательность 1,
// если можно выкинуть один 0

func maxBinSeq(arr []int) int {
	var max, counterLast, counterCurrent int
	var isLastZero bool

	for _, x := range arr {
		if x == 0 && !isLastZero {
			if max < (counterCurrent + counterLast) {
				max = counterCurrent + counterLast
			}
			counterLast = counterCurrent
			counterCurrent = 0
			isLastZero = true
		} else if x == 0 && isLastZero {
			counterCurrent, counterLast = 0, 0
		} else {
			counterCurrent++
			isLastZero = false
		}
	}

	if max < (counterCurrent + counterLast) {
		max = counterCurrent + counterLast
	}

	return max
}
