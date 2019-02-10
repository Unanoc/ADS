package quick

func sort(arr []int) {
	if 0 < len(arr) {
		pivot := partition(arr)
		sort(arr[:pivot])
		sort(arr[pivot+1:])
	}
}

func partition(arr []int) int {
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
