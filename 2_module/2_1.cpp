/*
 Дано число N ≤ 10^4 и последовательность целых чисел из [-2^31..2^31] длиной N.
 Требуется построить бинарное дерево, заданное наивным порядком вставки. Т.е.,
 при добавлении очередного числа K в дерево с корнем root, если root→Key ≤ K,
 то узел K добавляется в правое поддерево root; иначе в левое поддерево root.
 Выведите элементы в порядке in-order (слева направо).

Рекурсия запрещена.
*/

#include <iostream>
#include <vector>
#include <stack>

template <typename T>
class BinaryTree {
public:
    BinaryTree() = default;
    ~BinaryTree();

    void add(T item);
    std::vector<T> get_in_order_passing() const;

private:
    struct Entry {
        explicit Entry(T value) : value(value) {}

        T value;
        Entry *left = nullptr;
        Entry *right = nullptr;
    };

    std::vector<Entry *> _get_nodes_in_order_passing() const;

    Entry *root = nullptr;
};

template<typename T>
BinaryTree<T>::~BinaryTree() {
    std::vector<Entry *> entries_in_order = _get_nodes_in_order_passing();
    for (Entry* entry : entries_in_order) {
        delete entry;
    }
}

template<typename T>
void BinaryTree<T>::add(T item) {
    if (root == nullptr) {
        root = new Entry(item);
    }
    else {
        Entry *currentEntry = root;
        while (true) {
            if (currentEntry->value <= item) {
                if (currentEntry->right == nullptr) {
                    currentEntry->right = new Entry(item);
                    break;
                }
                else {
                    currentEntry = currentEntry->right;
                }
            }
            else {
                if (currentEntry->left == nullptr) {
                    currentEntry->left = new Entry(item);
                    break;
                }
                else {
                    currentEntry = currentEntry->left;
                }
            }
        }
    }
}

template<typename T>
std::vector<T> BinaryTree<T>::get_in_order_passing() const {
    std::vector<T> result;

    std::vector<Entry *> nodes = _get_nodes_in_order_passing();
    for (Entry * node : nodes) {
        result.push_back(node->value);
    }

    return result;
}

template<typename T>
std::vector<typename BinaryTree<T>::Entry *> BinaryTree<T>::_get_nodes_in_order_passing() const {
    std::vector<Entry *> result;
    std::stack<Entry *> stack;

    Entry *currentEntry = root;

    while (!stack.empty() || currentEntry != nullptr) {
        if (currentEntry != nullptr) {
            stack.push(currentEntry);
            currentEntry = currentEntry->left;
        }
        else {
            currentEntry = stack.top();
            stack.pop();
            result.push_back(currentEntry);
            currentEntry = currentEntry->right;
        }
    }

    return result;
}


int main() {
    size_t count;
    std::cin >> count;

    BinaryTree<int> tree;
    for (size_t i = 0; i < count; ++i) {
        int element;
        std::cin >> element;
        tree.add(element);
    }

    std::vector<int> result = tree.get_in_order_passing();
    for (int it: result) {
        std::cout << it << ' ';
    }

    return 0;
}
