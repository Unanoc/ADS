package tasks

// SymDiff gets 2 ordered slices by asc, then return slice with uniq elements.
func SymDiff(a []int, b []int) []int {
	indexA := 0
	indexB := 0

	result := make([]int, 0)

	for indexA < len(a) && indexB < len(b) {
		if a[indexA] == b[indexB] {
			indexA++
			indexB++
			continue
		}

		if a[indexA] < b[indexB] {
			result = append(result, a[indexA])
			indexA++
			continue
		}

		if a[indexA] > b[indexB] {
			result = append(result, b[indexB])
			indexB++
			continue
		}
	}

	if indexA < len(a) {
		for i := indexA; i < len(a); i++ {
			result = append(result, a[i])
		}
	} else {
		for i := indexB; i < len(b); i++ {
			result = append(result, b[i])
		}
	}

	return result
}
