void merge(int arr[], int left, int middle, int right){

    int sizeOfLeftPart = middle-left+1;
    int sizeOfRightPart = right-middle;
    int leftPart[sizeOfLeftPart];
    int rightPart[sizeOfRightPart];

    for (int i = 0; i < sizeOfLeftPart; i++)
        leftPart[i] = arr[left + i];
    for (int i = 0; i < sizeOfRightPart; i++)
        rightPart[i] = arr[middle + 1 + i];

    int i = 0, j = 0, k = left;
    while(i < sizeOfLeftPart && j < sizeOfRightPart){
        if (leftPart[i] <= rightPart[j]){
            arr[k] = leftPart[i];
            i++;
        }else{
            arr[k] = rightPart[j];
            j++;
        }
        k++;
    }

    while (i < sizeOfLeftPart){
        arr[k] = leftPart[i];
        i++;
        k++;
    }

    while (j < sizeOfRightPart){
        arr[k] = rightPart[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int l, int r){
    if (l < r){

        int middle = l+(r-l)/2;

        mergeSort(arr, l, middle);
        mergeSort(arr, middle+1, r);

        merge(arr, l, middle, r);
    }
}