package insertion

func sort(arr []int) {
	for i := 0; i < len(arr); i++ {
		j := 0

		for arr[j] < arr[i] {
			j++
		}

		temp := arr[i]
		for k := i; k > j; k-- {
			arr[k] = arr[k-1]
		}
		arr[j] = temp
	}
}
