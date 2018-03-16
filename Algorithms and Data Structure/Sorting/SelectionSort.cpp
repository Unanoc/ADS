void SelectionSort(int arr[], int size){
    int temp, minIndex;

    for (int i = 0; i < size; i++){
        minIndex = i;

        for (int j = i + 1; j < size; j++){
            if (arr[j] < arr[i])
                minIndex = j;
        }
        if (minIndex != i){
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
