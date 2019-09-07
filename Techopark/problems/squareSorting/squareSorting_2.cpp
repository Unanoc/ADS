/* На вход поступает упорядоченная по возрастанию последовательность.
 * Нужно отсортировать квадраты членов последовательности
 * за O(n)
 *
 * Ввод        | Вывод
 * 5           | 0 1 4 9 16
 * -3 -1 0 2 4 |
*/
#include <iostream>
#include <vector>
#include <cmath>

int findPositive(std::vector<int> &seq) {
    for (int i = 0; i < seq.size(); ++i) {
        if (seq[i] >= 0)
            return i;
    }
    return -1;
}

std::vector<int> squareSort(std::vector<int> &seq) {
    int first_positive_index = findPositive(seq);
    std::vector<int> result;

    if (first_positive_index == -1) {
        for (int i = 0; i < seq.size(); ++i)
            result.push_back(static_cast<int>(pow(seq[seq.size() - 1 - i], 2)));
        return result;
    }
    else {
        int negative_index = first_positive_index - 1;
        int positive_index = first_positive_index;

        while (negative_index >= 0 && positive_index < seq.size()) {
            if (pow(seq[negative_index], 2) > pow(seq[positive_index], 2)) {
                result.push_back(static_cast<int &&>(pow(seq[positive_index], 2)));
                result.push_back(static_cast<int &&>(pow(seq[negative_index], 2)));
                negative_index--;
                positive_index++;
            }
            else {
                result.push_back(static_cast<int &&>(pow(seq[negative_index], 2)));
                result.push_back(static_cast<int &&>(pow(seq[positive_index], 2)));
                negative_index--;
                positive_index++;
            }

        }

        if (negative_index < 0) {
            for (int i = positive_index; i < seq.size(); ++i)
                result.push_back(seq[i]);
        }

        if (positive_index >= seq.size()) {
            for (int i = negative_index; i >= 0; --i)
                result.push_back(seq[i]);
        }
        return result;
    }
}

int main() {
    std::cout << "Вводите упорядоченную по возрастанию последовательность целых чисел через пробел или enter:" << std::endl;
    std::vector<int> sequence;
    int inputValue;

    while (std::cin >> inputValue)
        sequence.push_back(inputValue);

    auto result = squareSort(sequence);
    for (int i = 0; i < sequence.size(); ++i)
        std::cout << result[i] << " ";

    return 0;
}
