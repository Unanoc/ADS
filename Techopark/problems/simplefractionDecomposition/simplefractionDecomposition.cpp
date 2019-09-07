/* Вывести разложение натурального числа n на простые множители.
 * Простые множители должны быть упорядочены по возрастанию и разделены пробелами. 2 ≤ n ≤ 106.
 */

#include <iostream>

void fraction(int input) {
    bool isChanged = false;
    for (int i = 2; i < 10; ++i) {
        if (input % i == 0) {
            input /= i;
            std::cout << i << " ";
            isChanged = true;
            break;
        }
    }
    if (isChanged) {
            fraction(input);
        return;
    }
    if (input > 1)
        std::cout << input;
}

int main() {
    int inputNumber;
    std::cin >> inputNumber;

    if (inputNumber < 2 or inputNumber > 106)
        exit(1);
    else
        fraction(inputNumber);

    return 0;
}