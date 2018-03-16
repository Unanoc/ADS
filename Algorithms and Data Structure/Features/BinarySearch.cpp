//recursion
int BinarySearch(int arr[], int l, int r, int x){
    if (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            return BinarySearch(arr, mid + 1, r, x);
        else
            return BinarySearch(arr, l, mid - 1, x);
    }
    return -1;
}

//cicle
int BinarySearch(int arr[], int l, int r, int x){
    while (l <= r){
        int mid = l + (r - l) / 2;
        
        if (arr[mid] == x)
            return mid;
        
        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}