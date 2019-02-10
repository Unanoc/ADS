package quick

// QuickSort uses the quick sort algorithm to sort an integer slice.
func sort(arr []int) {
	left := 0
	right := len(arr)

	if left < right {
		pivot := Partition(arr)
		sort(arr[:pivot])
		sort(arr[pivot+1:])
	}
}

// Partition ...
func Partition(arr []int) int {
	pivot := arr[len(arr)-1]
	i := -1

	for j := 0; j < len(arr)-1; j++ {
		if arr[j] < pivot {
			i++
			arr[i], arr[j] = arr[j], arr[i]
		}
	}
	i++
	arr[i], pivot = pivot, arr[i]
	return i
}
