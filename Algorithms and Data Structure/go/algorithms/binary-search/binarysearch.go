package binary

func search(sortedArray []int, x int) int {
	begin, end := 0, len(sortedArray)-1

	for begin <= end {
		middle := begin + (end-begin)/2

		if sortedArray[middle] == x {
			return middle
		}

		if sortedArray[middle] < x {
			begin = middle + 1
		} else {
			end = middle - 1
		}
	}
	return -1
}
