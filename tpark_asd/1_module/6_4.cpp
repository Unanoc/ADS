/*
 Даны неотрицательные целые числа n,k и массив целых чисел из [0..10^9] размера n. Требуется найти k-ю порядковую
 статистику. т.е. напечатать число, которое бы стояло на позиции с индексом k (0..n-1) в отсортированном массиве.
 Напишите нерекурсивный алгоритм.
 Требования к дополнительной памяти: O(n). Требуемое среднее время работы: O(n).
 Функцию Partition следует реализовывать методом прохода двумя итераторами в одном направлении.
 Описание для случая прохода от начала массива к концу:
 Выбирается опорный элемент. Опорный элемент меняется с последним элементом массива.
 Во время работы Partition в начале массива содержатся элементы, не бОльшие опорного. Затем располагаются
 элементы, строго бОльшие опорного. В конце массива лежат нерассмотренные элементы. Последним элементом лежит
 опорный. Итератор (индекс) i указывает на начало группы элементов, строго бОльших опорного.
 Итератор j больше i, итератор j указывает на первый нерассмотренный элемент.
 Шаг алгоритма. Рассматривается элемент, на который указывает j. Если он больше опорного, то сдвигаем j.
 Если он не больше опорного, то меняем a[i] и a[j] местами, сдвигаем i и сдвигаем j.
 В конце работы алгоритма меняем опорный и элемент, на который указывает итератор i.

 Реализуйте стратегию выбора опорного элемента “случайный элемент”. Функцию Partition реализуйте методом прохода
 двумя итераторами от конца массива к началу.
 */

#include <iostream>
#include <ctime>


int partition(int *arr, int left, int right) {
    srand(static_cast<unsigned int>(time(nullptr)));
    int pivot = left + rand() % (right - left);
    std::swap(arr[pivot], arr[left]);
    pivot = left;


    int i = right - 1, j = right - 1;

    while (j > pivot) {
        if (arr[j] <= arr[pivot])
            j--;
        else {
            std::swap(arr[i], arr[j]);
            i--;
            j--;
        }
    }
    std::swap(arr[pivot], arr[i]);
    pivot = i;

    return pivot;
}


int findElement(int *arr, int length, int k) {
    int pivot = 0;
    int left = 0;
    int right = length;

    while (left < right) {
        pivot = partition(arr, left, right);

        if (pivot == k) {
            break;
        }
        else {
            if (pivot < k)
                left = pivot + 1;
            else
                right = pivot;
        }
    }
    return arr[pivot];
}


int main() {
    int length = 0;
    int k = 0;
    std::cin >> length >> k;

    if (k >= length || k < 0)
        return 0;

    auto arr = new int [length];
    for (int i = 0; i < length; ++i) {
        std::cin >> arr[i];
    }

    std::cout << findElement(arr, length, k);
    delete [] arr;
    return 0;
}
