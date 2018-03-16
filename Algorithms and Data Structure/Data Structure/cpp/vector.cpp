#include <iostream>

#define CAPACITY_MIN 4
#define CAPACITY_INCREASE 2

template <class T>
class Vector {

public:
    Vector();
    Vector(unsigned int capacity);
    Vector(const Vector<T>& v);
    ~Vector();

    T push_back(const T& v);
    T pop_back();
    unsigned int size();
    void empty();

    void update_arr();

    T& operator[](unsigned int index);
    Vector<T>& operator=(const Vector<T>& v);

private:
    unsigned int _size;
    unsigned int _capacity;
    T* arr;
};

template <class T>
Vector<T>::Vector() {
    _capacity = 0;
    _size = 0;
    arr = 0;
}

template <class T>
Vector<T>::Vector(unsigned int capacity) {
    _capacity = capacity;
    _size = 0;
    arr = new T[capacity];
}

template <class T>
Vector<T>::Vector(const Vector<T>& v)
{
    _size = v._size;
    _capacity = v._capacity;
    arr = new T[_size];
    std::copy(v.arr, v.arr + _size, arr);
}

template <class T>
Vector<T>::~Vector() {
    delete[] arr;
}

template <class T>
void Vector<T>::update_arr() {
    T* arr_new = new T[_capacity];
    std::copy(arr, arr + _size, arr_new);
    delete[] arr;
    arr = arr_new;
}

template <class T>
unsigned int Vector<T>::size() {
    return _size;
}

template <class T>
T Vector<T>::push_back(const T& v) {

    if (_capacity == 0) {
        _capacity = CAPACITY_MIN;
        arr = new T[_capacity];
    } else {
        if (_capacity == _size) {
            _capacity *= CAPACITY_INCREASE;
            update_arr();
        }
    }

    arr[_size++] = v;
    return arr[_size - 1];
}

template <class T>
T Vector<T>::pop_back() {

    if (_size == 0) {
        return -1;
    } else {
        if ((_capacity > CAPACITY_MIN) && (_capacity/2 > _size)) {
            _capacity /= 2;
            update_arr();
        }

        _size--;
        if (_size == 0)
            return 0;
        return arr[_size - 1];
    }
}

template <class T>
void Vector<T>::empty() {
    while(_size) {
        pop_back();
    }
}

template<class T>
T& Vector<T>::operator[](unsigned int index) {
    return arr[index];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v) {
    delete[] arr;
    *this = Vector(v);
    return *this;
}
