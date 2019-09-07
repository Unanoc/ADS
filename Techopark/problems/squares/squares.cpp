/*
 Вывести квадраты натуральных чисел от 1 до n, используя только O(n) операций
 сложения и вычитания (умножением пользоваться нельзя). n ≤ 1000.

 Пример ввода и вывода:
 5
 1 4 9 16 25
*/

#include <iostream>

void squares(int input) {
    for (int i = 1; i <= input; ++i) {
        int squareValue = 0;
        for (int j = 1; j <= i; ++j) {
            squareValue += i;
        }
        std::cout << squareValue << std::endl;
    }
}

#include <iostream>

int main() {
    int inputNumber;
    std::cin >> inputNumber;

    if (inputNumber < 1 or inputNumber > 1000)
        exit(1);
    else
        squares(inputNumber);
    return 0;
}