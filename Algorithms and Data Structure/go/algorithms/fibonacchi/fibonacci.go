package fibonacchi

func getIter(n int) int {
	if n == 0 {
		return 0
	}

	result := 0
	for a, b, i := 1, 1, 1; i < n; a, b, i = b, a+b, i+1 {
		result = b
	}

	return result
}

func getRecurse(n int) int {
	if n == 0 || n == 1 {
		return n
	}

	if n == 2 {
		return 1
	}

	return getRecurse(n-1) + getRecurse(n-2)
}
