/*
 В круг выстроено N человек, пронумерованных числами от 1 до N. Будем исключать каждого k-ого до тех пор,
 пока не уцелеет только один человек.
 Например, если N=10, k=3, то сначала умрет 3-й, потом 6-й, затем 9-й, затем 2-й, затем 7-й, потом 1-й,
 потом 8-й, за ним - 5-й, и потом 10-й. Таким образом, уцелеет 4-й.
 Необходимо определить номер уцелевшего.
 N, k ≤ 10000.
 */
#include <iostream>
#include <cassert>
#include <vector>

int countSurvivor(unsigned countPeople, int k) {
    std::vector<int> people(countPeople);
    for (int i = 0; i < countPeople; ++i) people[i] = i + 1;

    unsigned peopleLeft = countPeople;
    int counter = 1;
    while (peopleLeft != 1) {
        for (int &iter : people) {

            if (iter == -1) continue;

            if (counter < k) {
                ++counter;
                continue;
            }

            if (counter == k) {
                if (peopleLeft == 1) return iter;

                iter = -1;
                counter = 1;
                --peopleLeft;
            }

        }
    }
    for (int &iter : people)
        if (iter != -1) return iter;
}

int main() {
    unsigned countPeople;
    int k;
    std::cin >> countPeople >> k;
    assert(countPeople <= 10000 && k <= 10000);

    std::cout << countSurvivor(countPeople, k);
    return 0;
}
