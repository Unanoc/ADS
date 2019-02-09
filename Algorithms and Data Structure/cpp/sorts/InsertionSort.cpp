void InsertionSort(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		int j = 0;

		while (arr[j] < arr[i])
			j++;

		int temp = arr[i];
		
		for (int k = i; k > j; k--) {
			arr[k] = arr[k-1];
		}
		arr[j] = temp;
	}
}
