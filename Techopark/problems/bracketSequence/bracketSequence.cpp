/*
 Дан фрагмент последовательности скобок, состоящей из символов (){}[]. Требуется определить,
 возможно ли продолжить фрагмент в обе стороны, получив корректную последовательность. Длина исходной последовательности ≤ 800000.
 Строка, содержащая символы (){}[] и, возможно, перевод строки.
 Если возможно - вывести минимальную корректную последовательность, иначе - напечатать "IMPOSSIBLE".
 */

#include <iostream>

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
    _size++;
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

char getInverseBracket(char ch) {
    switch (ch) {
        case ')':
            return '(';
        case ']':
            return '[';
        case '}':
            return '{';
        case '(':
            return ')';
        case '[':
            return ']';
        case '{':
            return '}';
        default:
            return -1;
    }
}

bool isPossible(std::string seq, std::string &result) {
    Stack<char> stack;
    Stack<char> left;
    bool isPossible = true;

    for (size_t i = 0; seq[i] != '\0'; i++) {
        if (seq[i] == '(' || seq[i] == '[' || seq[i] == '{')
            stack.push(seq[i]);

        if (seq[i] == ')' || seq[i] == ']' || seq[i] == '}') {
            if (stack.top() == getInverseBracket(seq[i]))
                stack.pop();
            else if (stack.empty())
                left.push(getInverseBracket(seq[i]));
            else {
                isPossible = false;
                break;
            }
        }
    }

    if (isPossible) {
        while (!left.empty()) {
            result += left.top();
            left.pop();
        }
        
        result += seq;
        
        while (!stack.empty()) {
            result += getInverseBracket(stack.top());
            stack.pop();
        }
    }
    return isPossible;
}

int main() {
    std::string inputSequence;
    std::string result;
    std::cin >> inputSequence;

    std::cout << (isPossible(inputSequence, result) ? result : "IMPOSSIBLE");

    return 0;
}
