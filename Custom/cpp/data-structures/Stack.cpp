#include <iostream>
#include <stack>

template <class T>
struct node {
    node(T data) : data(data), prev(NULL), next(NULL) {}
    T data;
    node<T>* next;
    node<T>* prev;
};

template <class T>
class Stack {

public:
    Stack();
    Stack(T data);
    ~Stack();

    void push(T data);
    void pop();
    T top();

    int size();
    bool empty();

    int create(T data);
    int remove();

private:
    node<T>* _top;
    int _size;
};

template <class T>
Stack<T>::Stack() {
    _size = 0;
    _top = nullptr;
}

template <class T>
Stack<T>::Stack(T data) {
    create(data);
}

template <class T>
Stack<T>::~Stack() {
    while (_top != nullptr)
        remove();
}

template <class T>
void Stack<T>::push(T data) {
    create(data);
}

template <class T>
void Stack<T>::pop() {
    remove();
}

template <class T>
T Stack<T>::top() {
    if (empty())
        return -1;
    return _top->data;
}

template <class T>
int Stack<T>::size() {
    return this->_size;
}

template <class T>
bool Stack<T>::empty() {return (_top == nullptr); }

template <class T>
int Stack<T>::create(T data) {
    if (_top == nullptr) {
        _top = new node<T>(data);
        _size++;
        return 0;
    }

    auto tmp = new node<T>(data);
    _top->next = tmp;
    tmp->prev = _top;
    _top = tmp;
    _size++;

    return  0;
}

template <class T>
int Stack<T>::remove() {
    if (_top == nullptr)
        return -1;

    if (_top->prev == nullptr) {
        delete _top;
        _top = nullptr;
        _size--;
        return 0;
    }

    _top = _top->prev;
    delete _top->next;
    _top->next = nullptr;
    _size--;

    return 0;
}
