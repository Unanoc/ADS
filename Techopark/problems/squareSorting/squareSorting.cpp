/* На вход поступает упорядоченная по возрастанию последовательность.
 * Нужно отсортировать квадраты членов последовательности
 * за O(n)
 *
 * Ввод        | Вывод
 * 5           | 0 1 4 9 16
 * -3 -1 0 2 4 |
*/

#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include <stack>

void divide(std::vector<int>& positive, std::stack<int> &negative) {
    unsigned long size = negative.size();
    for (int i = 0; i < size; ++i) {
        if (negative.top() >= 0) {
            int top = negative.top();
            positive.push_back(top);
            negative.pop();
        } else break;
    }
}

void squareSort(std::vector<int>& positive, std::stack<int> &negative) {
    divide(positive, negative);
    while (!positive.empty() && !negative.empty()) {
        if (pow(positive[positive.size() - 1], 2) > pow(negative.top(), 2)) {
            std::cout << " " << pow(negative.top(), 2);
            negative.pop();
        }
        else {
            std::cout << " " << pow(positive[positive.size() - 1], 2);
            positive.pop_back();
        }
    }

    if (positive.empty() && !negative.empty()) {
        while (!negative.empty()){
            std::cout << " " << pow(negative.top(), 2);
            negative.pop();
        }
    }

    if (negative.empty() && !positive.empty()) {
        while (!positive.empty()) {
            std::cout << " " << pow(positive[positive.size() - 1], 2);
            positive.pop_back();
        }
    }
}

int main() {
    int countSequence;
    assert(std::cin >> countSequence);

    std::vector<int> positiveNums;
    std::stack<int> negativeNums;

    int input;
    for (int i = 0; i < countSequence; ++i) {
        assert(std::cin >> input);
        negativeNums.push(input);
    }

    squareSort(positiveNums, negativeNums);

    return 0;
}
