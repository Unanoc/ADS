/* Дан отсортированный массив различных целых чисел A[0..n-1] и массив целых чисел B[0..m-1].
 Для каждого элемента массива B[i] найдите минимальный индекс элемента массива A[k],
 ближайшего по значению к B[i]. Время работы поиска для каждого элемента B[i]: O(log(k)). n ≤ 110000, m ≤ 1000.
*/

#include <iostream>
#include <cassert>

void init (int length, int *array) {
    for (int i = 0; i < length; ++i) {
        std::cin >> array[i];
    }
}

void showArray(int *arr, int length) {
    std::cout << std::endl;
    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << " ";
    }
}

int BinarySearch (int *arr, int x, int left, int right) {
    int difference = INT32_MAX;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (abs(x - arr[mid]) <= difference) {
            difference = abs(x - arr[mid]);

            if (mid == 0 || mid == right) return mid;

            if ( (abs(x - arr[mid + 1]) >= difference) && (abs(x - arr[mid - 1]) > difference)) return mid;
        }

        if (abs(x - arr[mid + 1]) < difference) left = mid + 1;

        if (abs(x - arr[mid - 1]) <= difference) right = mid - 1;
    }
}

int *twinSearch (int *first, int *second, int f_size, int s_size) {
    auto result = new int [s_size];
    int resultIndex = 0;
    for (int i = 0; i < s_size; ++i) {
        int powerOfTwoValue = 1;

        while( (powerOfTwoValue < f_size) && abs(second[i] - first[powerOfTwoValue]) < abs(second[i] - first[powerOfTwoValue - 1]) )
            powerOfTwoValue *= 2;

        int left = powerOfTwoValue / 2;

        if(powerOfTwoValue > (f_size-1))
            powerOfTwoValue = (f_size-1);

        result[resultIndex++] = BinarySearch(first, second[i], left, powerOfTwoValue);
    }
    return result;
}

int main() {
    int length_first, length_second;

    std::cin >> length_first;
    assert(length_first < 110000 && length_first > 0);
    auto first = new int [length_first];
    init(length_first, first);

    std::cin >> length_second;
    assert(length_second < 1000 && length_second > 0);
    auto second = new int [length_second];
    init(length_second, second);

    auto indexes = twinSearch(first, second, length_first, length_second);
    showArray(first, length_first);
    showArray(second, length_second);
    showArray(indexes, length_second);

    delete[] first;
    delete[] second;
    delete[] indexes;

    return 0;
}
