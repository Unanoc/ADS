int Partition(vector<int> &arr, int from, int to) {

    int wall = from;

    for (int i = from; i < to; i++) {
        if (arr[i] <= arr[to]) {
            swap(arr[i],arr[wall]);
            wall++;
        }
    }

    swap(arr[to], arr[wall]);
    return wall;
}

void QuickSort(vector<int> &arr, int left, int right) {

    if (left < right){
        int wall = Partition(arr, left, right);
        QuickSort(arr, left, wall - 1);
        QuickSort(arr, wall + 1, right);
    }
}
