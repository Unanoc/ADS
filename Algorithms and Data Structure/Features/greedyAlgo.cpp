#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
};

double get_max_knapsack_value(int capacity, std::vector <Item> items) {
    std::sort(items.begin(), items.end(), [](const Item &l, const Item &r) {
        return static_cast <std::int64_t>(l.weight * r.weight) <
               static_cast <std::int64_t>(r.weight * l.value);
    });

    double value = 0.0;

    for (auto &item:items) {
        if (capacity > item.weight) {
            capacity -= item.weight;
            value += item.value;
        } else {
            value += item.value * (static_cast <double>(capacity) / item.weight);
            break;
        }
    }

    return value;
}


int main() {
    int number_of_items;
    int knapsack_capacity;
    std::cin >> number_of_items >> knapsack_capacity;
    std::vector <Item> items(number_of_items);
    
    for (int i = 0; i < number_of_items; ++i) {
        std::cin >> items[i].weight >> items[i].value;
    }

    double max_knapsack_value = get_max_knapsack_value(knapsack_capacity, std::move(items));
    std::cout << max_knapsack_value << std:: endl;

    return 0;
}
