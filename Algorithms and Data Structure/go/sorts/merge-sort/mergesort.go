package merge

func sort(arr []int) {
	if 0 < len(arr) {
		middle := len(arr) / 2
		sort(arr[:middle])
		sort(arr[middle:])

		merge(arr, middle)
	}
}

func merge(arr []int, middle int) {
	leftPart := arr[:middle]
	rightPart := arr[middle:]

	var i int
	var j int
	var k int

	for i < len(leftPart) && j < len(rightPart) {
		if leftPart[i] < rightPart[j] {
			arr[k] = leftPart[i]
			i++
		} else {
			arr[k] = rightPart[j]
			j++
		}
		k++
	}

	for i < len(leftPart) {
		arr[k] = leftPart[i]
		i++
		k++
	}

	for j < len(rightPart) {
		arr[k] = rightPart[i]
		j++
		k++
	}
}
