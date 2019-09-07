/*
 Дано выражение в инфиксной записи. Вычислить его, используя перевод выражения в постфиксную запись. 
 Выражение не содержит отрицительных чисел. Количество операций ≤ 100.
 Строка, состоящая их символов “0123456789-+*()\"
 Гарантируется, что входное выражение корректно, нет деления на 0, вычислимо в целых числах. Деление целочисленное.
*/

#include <iostream>
#include <set>


template <class T>
struct node {
    node(T data) : data(data), prev(nullptr), next(nullptr) {}
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
    int pop();
    T top();

    unsigned size();
    bool isEmpty();

private:
    void _create(T data);
    int _remove();

    node<T> *_top;
    unsigned _size;
};

template <class T>
Stack<T>::Stack() : _top(nullptr), _size(0) {}

template <class T>
Stack<T>::Stack(T data) {
    _create(data);
}

template<class T>
Stack<T>::~Stack() {
    while (_top != nullptr)
        _remove();
}

template<class T>
void Stack<T>::push(T data) {
    _create(data);
}

template<class T>
int Stack<T>::pop() {
    return _remove();
}

template<class T>
T Stack<T>::top() {
    if (isEmpty())
        return -1;
    return _top->data;
}

template<class T>
unsigned Stack<T>::size() {
    return _size;
}

template <class T>
void Stack<T>::_create(T data) {
    if (_top == nullptr) {
        _top = new node<T>(data);
        _size++;
    }
    else {
        auto tmp = new node<T>(data);
        _top->next = tmp;
        tmp->prev = _top;
        _top = tmp;
        _size++;
    }
}

template<class T>
int Stack<T>::_remove() {
    if (_top == nullptr)
        return -1;

    if (_top->prev == nullptr) {
        delete [] _top;
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

template <class T>
bool Stack<T>::isEmpty() {return (_top == nullptr); }

int isOperator(char input_char) {
    std::set<char> operators = {'+', '-', '/', '*', '(', ')'};
    auto search = operators.find(input_char);
    if (search!= operators.end())
        return 1;
    else
        return 0;
}

void popOperatorPriority(Stack<int> &Nums, Stack<char> &operators) {
    int B = Nums.top();
    Nums.pop();
    int A = Nums.top();
    Nums.pop();

    switch (operators.top()) {
        case '+': Nums.push(A + B);
            break;
        case '-': Nums.push(A - B);
            break;
        case '*': Nums.push(A * B);
            break;
        case '/': Nums.push(A / B);
            break;
        default:
            break;
    }
    operators.pop();
}

int getResult(std::string &input) {
    Stack<int> Nums;
    Stack<char> Operators;
    std::string newInput = "(" + input + ")";
    std::string temp;

    for (int i = 0; i < newInput.size(); ++i) {
        //adding an operator
        if (isOperator(newInput[i])) {

            if (newInput[i] == '-' || newInput[i] == '+') {
                if (Operators.top() != '(') {
                    popOperatorPriority(Nums, Operators);
                    Operators.push(newInput[i]);
                }
            }

            if (newInput[i] == '*' || newInput[i] == '/') {
                if (Operators.top() !='(')
                    Operators.push(newInput[i]);
            }

            if (newInput[i] == '(' || Operators.top() == NULL || (Operators.top() == '(') && (newInput[i] != ')') )
                Operators.push(newInput[i]);

            if (Operators.top() == '(' && newInput[i] == ')') {
                Operators.pop();
                continue;
            }

            if (newInput[i] == ')') {
                while (Operators.top() != '(')
                    popOperatorPriority(Nums, Operators);
                Operators.pop(); //pop '('
            }
        }
        //adding a number
        else {
            while (!isOperator(newInput[i])) {
                if (newInput[i] == '\0')
                    break;
                temp += newInput[i];
                ++i;
            }
            Nums.push(std::stoi(temp));
            temp.clear();
            --i;
        }
    }

    int result =  Nums.top();
    Nums.pop();
    return result;
}

int main() {
    std::cout << "Input an expression: " << std::endl;
    std::string expression;
    std::cin >> expression;

    std::cout << getResult(expression);
    return 0;
}
