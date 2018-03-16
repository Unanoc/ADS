void CoctailSort(int a[], int n){
    int left = 0;
    int right = n;

    while (left <= right){

        for (int i = left; i < right - 1; i++){
            if (a[i] > a[i+1])
                swap(a[i],a[i+1]);
        }

        right--;

        for (int i = right; i >= left + 1; i-- ){
            if (a[i] < a[i-1])
                swap(a[i], a[i-1]);
        }

        left++;
    }
}