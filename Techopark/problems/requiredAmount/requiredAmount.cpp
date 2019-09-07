/*
 Даны два строго возрастающих массива целых чисел A[0..n) и B[0..m) и число k.
 Найти количество таких пар индексов (i, j), что A[i] + B[j] = k. Время работы O(n + m). n, m ≤ 100000.
 Указание. Обходите массив B от конца к началу.
*/

#include <iostream>

int *createSequence(int size) {
    int *sequence = new int [size];
    for (int i = 0; i < size; ++i) {
        std::cin >> sequence[i];
    }
    return sequence;
}

int countRequiredAmount(int *first, int f_len, int *second, int s_len, int req_sum) {
    int counter = 0;
    int i = 0; //for first
    int j = s_len - 1; //for second

    while (j >= 0) {
        if ( (second[j] + first[i]) == req_sum) {
            counter++;
            j--;
        }
        else {

            if ( (second[j] + first[i]) > req_sum ) {
                if ( (second[j] + first[i - 1]) < req_sum && i > 0) {
                    j--;
                    continue;
                }

                if ( (i-1) < 0) j--;
                else i--;
            }

            if ( (second[j] + first[i]) < req_sum ) {
                if ( (second[j] + first[i + 1]) > req_sum && i < f_len - 1) {
                    j--;
                    continue;
                }

                if ( (i+1) == f_len) j--;
                else i++;
            }
        }
    }

    return counter;
}

int main() {
    int lengthFirst;
    std::cin >> lengthFirst;
    int *first = createSequence(lengthFirst);

    int lengthSecond;
    std::cin >> lengthSecond;
    int *second = createSequence(lengthSecond);

    int requiredSum;
    std::cin >> requiredSum;

    std::cout << countRequiredAmount(first, lengthFirst, second, lengthSecond, requiredSum);
    
    delete [] first;
    delete [] second;
    return 0;
}
