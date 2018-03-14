/*
 Реализовать очередь с динамическим зацикленным буфером.

 Обрабатывать команды push back и pop front.

 Формат ввода
 В первой строке количество команд n. n ≤ 1000000.

 Каждая команда задаётся как 2 целых числа: a b.

 a = 2 - pop front
 a = 3 - push back

 Если дана команда pop front, то число b - ожидаемое значение.
 Если команда pop front вызвана для пустой структуры данных, то ожидается “-1”.

 Формат вывода
 Требуется напечатать YES - если все ожидаемые значения совпали. Иначе,
 если хотя бы одно ожидание не оправдалось, то напечатать NO.
*/


#include <iostream>

#define GROWTH_SIZE 2
#define INIT_CAPACITY 4


template <class T>
class Queue {
public:
    Queue(int initialCapacity = INIT_CAPACITY);
    ~Queue();

    void Enqueue(T& item);
    T Dequeue();
    
private:
    T *_data = nullptr;
    int _capacity;
    int _size;
    int _head;
    int _tail;

    void expand();
    void reduce();
};


template <class T>
Queue<T>::Queue(int initialCapacity) :
        _capacity(initialCapacity),
        _size(0),
        _data(new T [_capacity]),
        _head(-1),
        _tail(-1)
{}


template <class T>
Queue<T>::~Queue() {
    delete [] _data;
}


template <class T>
void Queue<T>::Enqueue(T& item) {
    if (_size == _capacity) expand();

    if (_tail == _capacity - 1) {
        _tail = 0;
        _data[_tail] = item;
        if (_size == 0) _head = _tail;
        _size++;
        return;
    }

    if (_tail < _capacity - 1) {
        _data[++_tail] = item;
        if (_size == 0) _head = _tail;
        _size++;
    }
}


template <class T>
T Queue<T>::Dequeue() {
    if (_size == 0) {
        _head = _tail = -1;
        return -1;
    }

    if (_size < (_capacity / GROWTH_SIZE) && _size > INIT_CAPACITY / 2) reduce();


    if (_head < _capacity - 1) {
        _size--;
        return _data[_head++];
    }
    else {
        if (_head == _tail) {
            _size--;
            return _data[_head];
        }

        T tmp = _data[_head];
        _head = 0;
        _size--;
        return tmp;
    }
}


template<class T>
void Queue<T>::expand() {
    auto tmp = new T [_capacity * GROWTH_SIZE];

    if (_head < _tail) {
        std::copy(_data, _data + _capacity, tmp);
        _capacity *= GROWTH_SIZE;
        delete [] _data;
        _data = tmp;
    }
    else {
        std::copy(_data + _head, _data + _capacity, tmp);
        std::copy(_data, _data + (_tail + 1), tmp + (_capacity - _head) );
        _head = 0;
        _tail = _size - 1;
        _capacity *= GROWTH_SIZE;
        delete [] _data;
        _data = tmp;
    }
}


template<class T>
void Queue<T>::reduce() {
    auto tmp = new T [_capacity / GROWTH_SIZE];

    if (_head < _tail) {
        std::copy(_data + _head, _data + _head + _size, tmp);
        _head = 0;
        _tail = _size - 1;
        _capacity /= GROWTH_SIZE;
        delete [] _data;
        _data = tmp;
    }
    else {
        std::copy(_data + _head, _data + _capacity, tmp);
        std::copy(_data, _data + _tail + 1, tmp + (_capacity - _head));
        _head = 0;
        _tail = _size - 1;
        _capacity /= GROWTH_SIZE;
        delete [] _data;
        _data = tmp;
    }
}


template <class T>
bool queueAction(Queue<int> &q, int mode, T value) {
    switch (mode) {
        case 2:
            return q.Dequeue() == value;

        case 3:
            q.Enqueue(value);
            return true;

        default:
            return false;
    }
}


int main() {
    Queue<int> q;

    int n;
    std::cin >> n;

    bool isSuccess = true;
    for (int i = 0; i < n; ++i) {
        int operation = 0;
        int value = 0;
        std::cin >> operation >> value;

        if (!queueAction(q, operation, value)) {
            isSuccess = false;
            break;
        }
    }

    std::cout << (isSuccess ? "YES" : "NO");

    return 0;
}

