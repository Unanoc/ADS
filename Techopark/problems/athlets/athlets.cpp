/*
 В город N приехал цирк с командой атлетов. Они хотят удивить горожан города N — выстроить из своих тел
 башню максимальной высоты. Башня — это цепочка атлетов, первый стоит на земле, второй стоит у него на плечах,
 третий стоит на плечах у второго и т.д. Каждый атлет характеризуется силой si (kg) и массой mi (kg).
 Сила — это максимальная масса, которую атлет способен держать у себя на плечах. К сожалению ни один из атлетов
 не умеет программировать, так как всю жизнь они занимались физической подготовкой, и у них не было времени на изучение
 языков программирования. Помогите им, напишите программу, которая определит максимальную высоту башни, которую они могут составить.
 Известно, что если атлет тяжелее, то он и сильнее: если mi>mj, то si > sj. Атлеты равной массы могут иметь различную силу.

 Вход содержит только пары целых чисел — массу и силу атлетов. Число атлетов 1 ≤ n ≤ 100000.
 Масса и сила являются положительными целыми числами меньше, чем 2000000.

 Выход должен содержать натуральное число — максимальную высоту башни.
 */


#include <iostream>

struct athlet {
    size_t mass;
    size_t power;
};

athlet findNextAthlet(athlet *athlets, size_t size, unsigned int currWeight) {
    athlet athletForTower = {2000000, 2000000};
    size_t indexOfAthlet = 0;
    bool athletWasFound = false;

    for (size_t i = 0; i < size; ++i) {
        if (athlets[i].power >= currWeight && athlets[i].mass < athletForTower.mass && athlets[i].power < athletForTower.power) {
            athletWasFound = true;
            indexOfAthlet = i;
            athletForTower = athlets[i];
        }
    }

    if (athletWasFound)
        athlets[indexOfAthlet] = {0, 0};
    return athletWasFound ? athletForTower : athlet{0, 0};
}


int maxHeight(athlet *athlets, size_t size) {
    unsigned int currentWeight = 0;
    int sizeOfTower = 0;

    for (;;) {
        athlet validAthlet = findNextAthlet(athlets, size, currentWeight);
        if (validAthlet.power != 0 && validAthlet.mass != 0) {
            currentWeight += validAthlet.mass;
            sizeOfTower++;
        } else
            break;
    }

    return sizeOfTower;
}


int main() {
    auto athlets = new athlet[100000];
    size_t countOfAthlets = 0;
    while (std::cin >> athlets[countOfAthlets].mass) {
        std::cin >> athlets[countOfAthlets].power;
        if (athlets[countOfAthlets].power <= 0 || athlets[countOfAthlets].mass <= 0)
            exit(1);
        countOfAthlets++;
    }

    std::cout << maxHeight(athlets, countOfAthlets);
    delete [] athlets;
    return 0;
}
