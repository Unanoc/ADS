/*
 Реализовать очередь с помощью двух стеков. Использовать стек, реализованный с помощью динамического буфера.
 Обрабатывать команды push back и pop front.

 Формат ввода

 В первой строке количество команд n. n ≤ 1000000.
 Каждая команда задаётся как 2 целых числа: a b.
 a = 2 - pop front
 a = 3 - push back
 Если дана команда pop front, то число b - ожидаемое значение.
 Если команда pop front вызвана для пустой структуры данных, то ожидается “-1”.
*/

#include <iostream>

#define CAPACITY_MIN 4
#define CAPACITY_INCREASE 2

template <class T>
class Stack {
public:

    Stack();
    Stack(T data);
    ~Stack();

    T push_back(const T& data);
    T pop_back();
    T top();

    int size();
    bool empty();
    void update_stack();

private:
    T* _top;
    int _size;
    int _capacity;
};

template <class T>
Stack<T>::Stack() {
    _size = 0;
    _capacity = 0;
    _top = nullptr;
}

template <class T>
Stack<T>::Stack(T data) {
    push_back(data);
}

template <class T>
Stack<T>::~Stack() {
    delete[] _top;
}

template <class T>
T Stack<T>::push_back(const T& data) {
    if (_capacity == 0) {
        _capacity = CAPACITY_MIN;
        _top = new T[_capacity];
    } else {
        if (_capacity == _size) {
            _capacity *= CAPACITY_INCREASE;
            update_stack();
        }
    }

    _top[_size++] = data;
    return _top[_size - 1];
}

template <class T>
T Stack<T>::pop_back() {

    if (_size == 0) {
        return -1;
    } else {
        if ((_capacity > CAPACITY_MIN) && (_capacity / 2 > _size)) {
            _capacity /= 2;
            update_stack();
        }

        _size--;
        if (_size == 0)
            return _top[_size];
        return _top[_size];
    }
}

template <class T>
T Stack<T>::top() {
    return _top[_size - 1];
}

template <class T>
void Stack<T>::update_stack() {
    auto tmp = new T[_capacity];
    std::copy(_top, _top + _size, tmp);
    delete[] _top;
    _top = tmp;
}

template <class T>
bool Stack<T>::empty() { return _size == 0;}

template <class T>
int Stack<T>::size() { return _size;}




void stack_move(Stack<int>& from, Stack<int>& to) {
    while (!from.empty()) {
        to.push_back(from.top());
        from.pop_back();
    }
}

int queque(Stack<int>& lhs, Stack<int>& rhs, int cmd, int val) {

    if (cmd == 3) {
        stack_move(rhs, lhs);
        return lhs.push_back(val);
    }

    if (cmd == 2) {
        stack_move(lhs, rhs);
        return rhs.pop_back();
    }
}


int main() {
    Stack<int> s1;
    Stack<int> s2;

    int count;
    int command;
    int expect;
    int success = 0;

    std::cout << "Input count of operations: " << std::endl;
    std::cin >> count;

    for (int i = 0; i < count; ++i) {
        std::cin >> command >> expect;

        if (queque(s1, s2, command, expect) == expect)
            success++;
        else
            success--;
    }

    if (success == count)
        std::cout << "YES";
    else
        std::cout << "NO";

    return 0;
}
