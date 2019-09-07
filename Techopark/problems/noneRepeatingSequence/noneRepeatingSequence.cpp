/*
 Даны две упорядоченные целочисленные последовательности. Вывести третью последовательность, в которой
 есть неповторяющиеся числа из первых последовательностей.
*/

#include <iostream>

void init(int *sequence, int size) {
    for (int i = 0; i < size; ++i)
        std::cin >> sequence[i];
}

int newSequence(const int *first, const int *second, int *result, int f_size, int s_size) {
    int counter = 0;
    int i = 0, j = 0;

    while (i < f_size && j < s_size) {

        if (first[i] > second[j]) {
            result[counter++] = second[j++];
        }

        if (second[j] >= first[i]) {

            if (second[j] == first[i]) {
                i++;
                j++;
            }

            else {
                result[counter++] = first[i++];
            }
        }
    }

    if (i == f_size) {

        for (int iter = j; iter < s_size; ++iter)
            result[counter++] = second[iter];
    }

    if (j == s_size) {

        for (int iter = i; iter < f_size; ++iter)
            result[counter++] = first[iter];
    }

    return counter;
}

int main() {
    int firstSize, secondSize;

    std::cout << "Введите количество элементов первой последовательности: " << std::endl;
    std::cin >> firstSize;
    int *firstSequence = new int [firstSize];
    std::cout << "Введите первую последовательность" << std::endl;
    init(firstSequence, firstSize);

    std::cout << "Введите количество элементов второй последовательности: " << std::endl;
    std::cin >> secondSize;
    int *secondSequence = new int [secondSize];
    std::cout << "Введите вторую последовательность" << std::endl;
    init(secondSequence, secondSize);

    int *resultSequence = new int [firstSize];
    int size_of_result_sequence = newSequence(firstSequence, secondSequence, resultSequence, firstSize, secondSize);

    for (int i = 0; i < size_of_result_sequence; ++i) {
        std::cout << resultSequence[i] << " ";
    }

    delete [] firstSequence;
    delete [] secondSequence;
    delete [] resultSequence;

    return 0;
}
