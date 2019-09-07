#include <iostream>

class Queue {
public:
    Queue(int initialCapacity = 4);
    Queue(const Queue& other);
    ~Queue();

    void pushBack(int item);
    int popFront();
    //TODO if _front == _back then resize (to free a buffer from useless data)

private:
    int *_data = nullptr;
    int _capacity;
    int _front;
    int _back;
};

Queue::Queue(int initialCapacity) :
        _capacity(initialCapacity),
        _data(new int [_capacity]),
        _front(-1),
        _back(-1)
{}

Queue::Queue(const Queue &other) {
    _capacity = other._capacity;
    _front = other._front;
    _back = other._back;
    if (_data != nullptr) {
        free(_data);
    }
    _data = new int [_capacity];
    std::copy(other._data, other._data + _capacity, _data);
}

Queue::~Queue() {
    delete [] _data;
}

void Queue::pushBack(int item) {
    if (_capacity == _back + 1) {
        auto *tmp = new int [_capacity * 2];
        std::copy(_data + _front, _data + _capacity, tmp);
        _back = _capacity - _front - 1;
        _front = 0;
        _capacity *= 2;
        delete [] _data;
        _data = tmp;
    }
    if (_back < 0 || _back < _capacity - 1) {
        if (_front < 0)
            _front++;
        _data[++_back] = item;
    }
}

int Queue::popFront() {
    if (_front < 0) {
        return -1;
    }
    if (_front <= _back) {
        if (_front == _back)
            return _data[_front++];
        return _data[_front++];
    }
    else
        return -1;
}

bool queueAction(Queue &q, int mode, int value) {
    switch (mode) {
        case 2:
            return q.popFront() == value;

        case 3:
            q.pushBack(value);
            return true;

        default:
            return false;
    }
}

int main() {
    Queue q;

    size_t n;
    std::cin >> n;

    bool isSuccess = true;
    for (size_t i = 0; i < n; ++i) {
        int mode, value;
        std::cin >> mode >> value;

        if (!queueAction(q, mode, value)) {
            isSuccess = false;
            break;
        }
    }
    std::cout << (isSuccess ? "YES" : "NO");

    return 0;
}
