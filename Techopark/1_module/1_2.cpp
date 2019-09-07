/*
 Вычислить площадь выпуклого n-угольника, заданного координатами своих вершин.
 Вначале вводится количество вершин, затем последовательно целочисленные координаты
 всех вершин в порядке обхода против часовой стрелки.
 n < 1000, координаты < 10000.
 Указание. Для вычисления площади n-угольника можно посчитать сумму ориентированных площадей
 трапеций под каждой стороной многоугольника.
*/


#include <iostream>
#include <cassert>

struct top {
    float x;
    float y;

    top() : x(0), y(0) {}
};


float countSquare(top *tops, int size) {
    float result = 0;

    for (int i = 0; i < size; ++i) {
        float midLineOfTrapeze = (tops[i].y + tops[i + 1].y) / 2;
        float deltaX = -(tops[i].x - tops[i + 1].x);
        result += midLineOfTrapeze * deltaX;
    }

    return result;
}


int main() {
    int countOfTops = 0;
    std::cin >> countOfTops;

    assert(countOfTops < 1000);
    assert(countOfTops > 2);

    auto tops = new top[countOfTops + 1];
    std::cin >> tops[0].x >> tops[0].y;
    tops[countOfTops] = tops[0];


    for (int i = 1; i < countOfTops; ++i) {
        assert(std::cin >> tops[i].x);
        assert(std::cin >> tops[i].y);
    }

    std::cout << countSquare(tops, countOfTops);

    delete [] tops;
    return 0;
}
