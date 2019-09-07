/*Даны два массива неповторяющихся целых чисел, упорядоченные по возрастанию. A[0..n-1] и B[0..m-1].
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
#include <cassert>
#include <vector>

void initialize(std::vector<int>& arr) {
    for (int &i : arr) {
        assert(std::cin >> i);
    }
}

int BinarySearch(std::vector<int>& arr, int l, int r, int x) {
    while (l <= r) {

        int mid = l + (r - l) / 2;

        if (x == arr[mid])
            return mid;

        if (x < arr[mid]) r = mid - 1;
        else l = mid + 1;
    }

    return -1;
}

void intersection(std::vector<int>& arrA, std::vector<int>& arrB, std::vector<int>& result) {
    int lastFound = -1;
    for (int i = 0; i < arrB.size(); ++i) {
        if (arrB[i] == arrA[lastFound + 1]) {
            lastFound = i;
            result.push_back(arrB[i]);
        }
        else {
            int bin = BinarySearch(arrA, lastFound, arrA.size()-1, arrB[i]);
            if (bin != -1) {
                result.push_back(arrB[i]);
                lastFound = bin;
            }
        }
    }
}

int main() {

    unsigned long sizeA, sizeB;

    assert(std::cin >> sizeA);
    assert(std::cin >> sizeB);
    assert(sizeA > sizeB);

    std::vector<int> arrA(sizeA);
    std::vector<int> arrB(sizeB);
    std::vector<int> result;

    initialize(arrA);
    initialize(arrB);

    intersection(arrA, arrB, result);

    for (int &it : result) {
        std::cout << it << " ";
    }
    return 0;
}
