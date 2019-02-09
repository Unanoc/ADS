package bubble

func sort(arr []int) {
	sorted := false
	for !sorted {
		sorted = true
		for i := range arr[:len(arr)-1] {
			if arr[i] > arr[i+1] {
				arr[i], arr[i+1] = arr[i+1], arr[i]
				sorted = false
			}
		}
	}
}
