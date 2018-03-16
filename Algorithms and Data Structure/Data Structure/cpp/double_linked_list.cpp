#include <iostream>

template <class T>
struct node {
    node(T data) : data(data), next(nullptr), prev(nullptr) {}
    T data;
    node<T>* next;
    node<T>* prev;
};

template <class T>
class List {
public:
    List();
    List(const List<T>& list);
    ~List();

    void push_back(T data);
    void push_front(T data);
    T pop_back();
    T pop_front();

    T insert(T data, int pos);
    int find(T data);
    void clear();
    void display();

    List<T>& operator=(const List<T>& list);

private:
    node<T>* head;
    node<T>* tail;
    int size;
};

template <class T>
List<T>::List() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template <class T>
List<T>::List(const List<T>& list) {
    size = 0;
    head = nullptr;
    tail = nullptr;
    node<T>* tmp = list.head;

    while (tmp) {
        push_back(tmp->data);
        tmp = tmp->next;
    }

}

template <class T>
List<T>::~List() {
    clear();
}

template <class T>
void List<T>::push_back(T data) {
    insert(data, size);
}

template <class T>
void List<T>::push_front(T data){
    insert(data, 0);
}

template <class T>
T List<T>::pop_back() {
    if (tail == nullptr) {
        return -1;
    }

    if (tail == head) {
        delete tail;
        head = tail = nullptr;
        size--;
        return 0;
    }

    tail = tail->prev;
    delete tail->next ;
    tail->next= nullptr;
    size--;

    return 0;
}

template <class T>
T List<T>::pop_front() {
    if (head == nullptr) {
        return -1;
    }

    if (head == tail) {
        delete head;
        head = tail = NULL;
        size--;
        return 0;
    }

    head = head->next;
    delete head->prev;
    head->prev = nullptr;
    size--;

    return 0;
}

template <class T>
T List<T>::insert(T data, int pos) {
    if (pos > size)
        return -1;

    if (head == nullptr) {
        head = new node<T>(data);
        tail = head;
        size++;
        return 0;
    }

    if (pos == size) {
        auto elem = new node<T>(data);
        elem->prev = tail;
        tail->next = elem;
        tail = elem;
        size++;
        return 0;
    }

    if (pos == 0) {
        auto elem = new node<T>(data);
        elem->next = head;
        head->prev = elem;
        head = elem;
        size++;
        return 0;
    }

    node<T>* tmp = head;

    for (; pos > 0; --pos)
        tmp = tmp->next;

    auto elem = new node<T>(data);
    elem->prev = tmp->prev;
    elem->next = tmp;
    tmp->prev->next = elem;
    tmp->prev = elem;
    size++;
}

template <class T>
int List<T>::find(T data) {
    node<T>* tmp = head;
    int index = 0;

    while (tmp) {
        if (tmp->data == data) {
            return index;
        }
        tmp = tmp->next;
        index++;
    }

    return -1;
}

template <class T>
void List<T>::clear() {
    while (head != nullptr) {
        pop_back();
    }
}

template <class T>
void List<T>::display() {
    node<T>* tmp = head;
    while (tmp) {
        std::cout << tmp->data;
        tmp = tmp->next;
    }
}

template <class T>
List<T>& List<T>::operator=(const List<T>& list) {
    clear();

    node<T>* tmp = list.head;

    while (tmp) {
        push_back(tmp->data);
        tmp = tmp->next;
    }
    return *this;
}
