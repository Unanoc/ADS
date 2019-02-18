package leetcode

// Дан смещенный упорядоченный массив, найти элемент.

func BinarySearch(arr []int, x int) int {
	left := 0
	right := len(arr) - 1

	for left <= right {
		mid := left + (right-left)/2
		if x == arr[mid] {
			return mid
		}

		if x > arr[mid] {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	return -1
}

func searchWithOffset(arr []int, x int) int {
	middle := len(arr) / 2
	var beginIndex int

	for i := 0; i < middle; i++ {
		if arr[i] < arr[len(arr)-1-i] {
			beginIndex = i
			break
		}
	}

	if beginIndex == 0 {
		return BinarySearch(arr, x)
	}

	if x >= arr[beginIndex] && x <= arr[len(arr)-1] {
		return beginIndex + BinarySearch(arr[beginIndex:], x)
	}
	return BinarySearch(arr[:beginIndex], x)
}
