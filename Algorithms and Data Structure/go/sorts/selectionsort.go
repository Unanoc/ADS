package sorts

// SelectionSort uses the selection sort algorithm to sort an integer slice.
func SelectionSort(arr []int) {
	for i := 0; i < len(arr); i++ {
		min := i
		for j := i; j < len(arr); j++ {
			if arr[j] < arr[min] {
				min = j
			}
		}
		arr[i], arr[min] = arr[min], arr[i]
	}
}
