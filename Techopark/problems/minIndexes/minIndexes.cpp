/*
 Дан отсортированный массив целых чисел A[0..n-1] и массив целых чисел B[1..m-1]. Для каждого элемента
 массива B[i] найдите минимальынй индекс k минимального элемента массива А, равного или превосходящего B[i]: A[k] >= B[i].
 Если такого элемента нет, выведете n. Время рабоботы поиска k для каждого элемента B[i]: O(log(k)).
 n, m < 10000
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
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (x <= arr[mid] && x > arr[mid - 1])
            return mid;
        if (x > arr[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right + 1; //we have to return first_size
}

int *getMinIndexes(int *first, int *second, int f_size, int s_size) {
    auto result = new int [s_size];
    int resultIndex = 0;
    for (int i = 0; i < s_size; ++i) {

        int powerOfTwoValue = 1;
        while((powerOfTwoValue < f_size) && (second[i] > first[powerOfTwoValue]))
            powerOfTwoValue *= 2;

        int left = powerOfTwoValue / 2;

        if(powerOfTwoValue > (f_size-1))
            powerOfTwoValue = (f_size-1);

        result[resultIndex++] = BinarySearch(first, second[i], left, powerOfTwoValue);
    }
    return result;
}

int main() {
    int length_first,
        length_second;
    std::cin >> length_first >> length_second;

    assert(length_first < 10000 && length_first > 0);
    assert(length_second < 10000 && length_second > 0);

    auto first = new int [length_first];
    auto second = new int [length_second];
    init(length_first, first);
    init(length_second, second);

    auto indexes = getMinIndexes(first, second, length_first, length_second);
    showArray(first, length_first);
    showArray(second, length_second);
    showArray(indexes, length_second);

    delete[] first;
    delete[] second;
    delete[] indexes;

    return 0;
}
