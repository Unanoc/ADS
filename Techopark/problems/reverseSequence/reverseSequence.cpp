/*
 Дан массив целых чисел A[0..n).
 Не используя других массивов переставить элементы
 массива A в обратном порядке за O(n). n ≤ 10000.
 */

#include <iostream>
#include <vector>

void reverseArray(std::vector<int> &arr) {
    for (int i = 0; i < arr.size()/2; ++i) {
        int temp = arr[i];
        arr[i] = arr[arr.size() - 1 - i];
        arr[arr.size() - 1 - i] = temp;
    }
}

int main() {
    unsigned long arraySize;
    std::cin >> arraySize;

    std::vector<int> array(arraySize);
    for (int &i : array)
        std::cin >> i;

    reverseArray(array);

    for (int i : array)
        std::cout << i;
    return 0;
}