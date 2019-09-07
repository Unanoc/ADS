/*
 Найти, на сколько нулей оканчивается n! = 1 * 2 * 3 * … * n. n ≤ 1000.
*/

#include <iostream>

int countDivFive(int n) {
	int counter = 0;
	if (n >= 5) {
		while ((n % 5) == 0) {
			n /= 5;
			counter++;
		}
	}

	return counter;
}

int countNulls(int n) {
	int counter = 0;
	int temp = 5;

	if (n >= 5) {
		while (temp <= n) {
			counter += countDivFive(temp);
			temp += 5;
		}
	} else
		return 0;

	return counter;
}

int main() {
	int input;
	std::cin >> input;
	std::cout << countNulls(input);
    return 0;
}
