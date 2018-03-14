/*
 Даны два массива неповторяющихся целых чисел, упорядоченные по возрастанию. A[0..n-1] и B[0..m-1].
 n » m. Найдите их пересечение. Требуемое время работы: O(m * log k), где k - позиция элементта B[m-1]
 в массиве A.. В процессе поиска очередного элемента B[i] в массиве A пользуйтесь результатом
 поиска элемента B[i-1]. n, k ≤ 10000.

 Ввод
 5
 3
 1 2 3 4 5
 1 3 5
 Вывод
 1 3 5
*/


#include <iostream>


void initialize(int *arr, int size) {
    for (int i = 0; i < size; ++i)
        std::cin >> arr[i];
}


int binary_search(const int *arr, int l, int r, int x) {
    while (l <= r) {

        int mid = l + (r - l) / 2;

        if (x == arr[mid])
            return mid;

        if (x < arr[mid]) r = mid - 1;
        else l = mid + 1;
    }

    return -1;
}


size_t intersection(int *arr_first, int first_size, int *arr_second, int second_size, int *res) {

    size_t count = 0;
    int power_of_two_value = 1;

    for (int i = 0; i < second_size; ++i) {


        while ((power_of_two_value < first_size) && (arr_second[i] >= arr_first[power_of_two_value]))
                power_of_two_value *= 2;

        int left = power_of_two_value / 2;

        if (power_of_two_value > first_size - 1)
            power_of_two_value = first_size - 1;

        int search_result = binary_search(arr_first, left, power_of_two_value, arr_second[i]);

        if (search_result > -1) {
            res[count++] = arr_second[i];
            if (search_result > 0)
                power_of_two_value = search_result;
        }

    }

    return count;
}

int main() {
    int first_size = 0;
    int second_size = 0;

    std::cin >> first_size >> second_size;

    if (first_size < 0 || second_size < 0)
        return 0;

    if (first_size <= second_size || first_size > 10000)
        return 0;


    auto first_array = new int [first_size];
    auto second_array = new int [second_size];
    auto result_array = new int [second_size];

    initialize(first_array, first_size);
    initialize(second_array, second_size);

    size_t size_of_result = intersection(first_array, first_size, second_array, second_size, result_array);

    for (size_t i = 0; i < size_of_result; ++i)
        std::cout << result_array[i] << " ";

    delete [] first_array;
    delete [] second_array;
    delete [] result_array;

    return 0;
}
