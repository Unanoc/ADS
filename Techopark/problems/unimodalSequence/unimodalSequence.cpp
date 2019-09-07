/*
 Дан массив целых чисел А[0..n-1]. Известно, что на интервале [0, m] значения массива строго возрастают,
 а на интервале [m, n-1] строго убывают. Найти m за O(log m). 2 ≤ n ≤ 10000.
*/

#include <iostream>

int *createSequence(int size) {
    auto seq = new int [size];
    for (int i = 0; i < size; ++i) std::cin >> seq[i];
    return seq;
}

int BinarySearch(const int *arr, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if ( (arr[mid] > arr[mid + 1]) && (arr[mid] > arr[mid - 1]))
            return mid;
        if (arr[mid] > arr[mid - 1])
            left = mid + 1;
        if (arr[mid] < arr[mid + 1])
            right = mid - 1;
    }
    return -1;
}

int findTheTop(int *sequence, int size) {
    int powerOfTwo = 1;
    while ( (powerOfTwo < size) && (sequence[powerOfTwo] > sequence[powerOfTwo - 1]) )
        powerOfTwo *= 2;
    int left = powerOfTwo / 2;

    if(powerOfTwo > size) powerOfTwo = size - 1;

    return BinarySearch(sequence, left, powerOfTwo);
}

int main() {
    int sequenceSize;
    std::cin >> sequenceSize;

    int *sequence = createSequence(sequenceSize);
    std::cout << findTheTop(sequence, sequenceSize);
    delete [] sequence;

    return 0;
}
