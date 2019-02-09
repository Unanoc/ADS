/*
 Дан массив натуральных чисел A[0..n), n не превосходит 10^8. Так же задан размер некоторого окна
 (последовательно расположенных элементов массива) в этом массиве k, k<=n. Требуется для каждого
 положения окна (от 0 и до n-k) вывести значение максимума в окне.
 Скорость работы O(n log n), память O(n).
 Формат входных данных. Вначале вводится n - количество элементов массива. Затем вводится n строк
 со значением каждого элемента. Затем вводится k  - размер окна.
 Формат выходных данных. Разделенные пробелом значения максимумов для каждого положения окна.
 */

#include <iostream>
#include <cassert>

#define GROWTH_SIZE 2
#define INIT_BUFFER_SIZE 4


struct digit {
    int value;
    int index;

    digit() : value(-1), index(-1) {}
};

class digitCompare {
public:
    bool operator()(const digit &l, const digit &r) {
        return l.value <= r.value;
    }
};


template <class T, class Comparator>
class Heap {
public:
    Heap(Comparator cmp, int initialBuffer = INIT_BUFFER_SIZE);
    Heap(T *arr, int length, Comparator cmp);
    ~Heap();

    T extractMax();
    void add(T& value);

    bool isEmpty() const { return _size == 0; }
    const T& getMax() const;

private:
    T *_data = nullptr;
    int _bufferSize;
    int _size;

    Comparator cmp;

    void _buildHeap();

    void expand();
    void reduce();

    void _siftUp(int index);
    void _siftDown(int index);

    int _getParent(int index) const;
    int _getLeftChild(int index) const;
    int _getRightChild(int index) const;

};


template<class T, class Comparator>
Heap<T, Comparator>::Heap(Comparator cmp, int initialBuffer) :
        cmp(cmp),
        _bufferSize(initialBuffer),
        _data(new T [initialBuffer]),
        _size(0)
{}


template<class T, class Comparator>
Heap<T, Comparator>::Heap(T *arr, int length, Comparator cmp) :
        _bufferSize(length),
        _data(arr),
        _size(length),
        cmp(cmp)
{ _buildHeap(); }


template<class T, class Comparator>
Heap<T, Comparator>::~Heap() {
    delete [] _data;
}


template<class T, class Comparator>
int Heap<T, Comparator>::_getParent(int index) const {
    assert(index > 0);
    return (index - 1) / 2;
}


template<class T, class Comparator>
int Heap<T, Comparator>::_getLeftChild(int index) const {
    return 2 * index + 1;
}


template<class T, class Comparator>
int Heap<T, Comparator>::_getRightChild(int index) const {
    return 2 * index + 2;
}


template<class T, class Comparator>
void Heap<T, Comparator>::expand() {
    auto tmp = new T [_bufferSize * GROWTH_SIZE];
    std::copy(_data, _data + _bufferSize, tmp);
    _bufferSize *= GROWTH_SIZE;
    delete [] _data;
    _data = tmp;
}

template<class T, class Comparator>
void Heap<T, Comparator>::reduce() {
    auto tmp = new T [_bufferSize / GROWTH_SIZE];
    std::copy(_data, _data + _size, tmp);
    _bufferSize /= GROWTH_SIZE;
    delete [] _data;
    _data = tmp;
}


template<class T, class Comparator>
void Heap<T, Comparator>::_siftUp(int index) {
    while (index) {
        int parent = _getParent(index);
        if (cmp(_data[index], _data[parent]))
            return;

        std::swap(_data[index], _data[parent]);
        index = parent;
    }
}


template<class T, class Comparator>
void Heap<T, Comparator>::_siftDown(int index) {
    int left = _getLeftChild(index);
    int right = _getRightChild(index);

    int largest = index;

    // Ищем большего сына, если такой есть.
    if (left < _size && cmp(_data[largest], _data[left]))
        largest = left;
    if (right < _size && cmp(_data[largest], _data[right]))
        largest = right;

    // Если больший сын есть, то проталкиваем корень в него.
    if (largest != index) {
        std::swap(_data[index], _data[largest]);
        _siftDown(largest);
    }
}


template<class T, class Comparator>
void Heap<T, Comparator>::_buildHeap() {
    for (int i = _size / 2 - 1; i >= 0; --i)
        _siftDown(i);
}


template<class T, class Comparator>
const T &Heap<T, Comparator>::getMax() const {
    assert(!isEmpty());
    return _data[0];
}


template<class T, class Comparator>
void Heap<T, Comparator>::add(T& value) {
    if (_size == _bufferSize)
        expand();

    _data[_size] = value;
    _siftUp(_size++);
}


template<class T, class Comparator>
T Heap<T, Comparator>::extractMax() {
    assert(!isEmpty());

    if (_size < _bufferSize / 2)
        reduce();

    T max = _data[0];
    _data[0] = _data[_size - 1];
    _size--;

    if (!isEmpty())
        _siftDown(0);
    return max;
}


template<class T, class Comparator>
T *findSlideMax(T *input, int n, int windowSize, Comparator cmp) {
    int resultSize = n - windowSize + 1;
    auto result = new T [resultSize];

    auto tmp = new T [windowSize];
    std::copy(input, input + windowSize, tmp);
    Heap<T, Comparator> heap(tmp, windowSize, cmp);

    int windowBegin = 0;
    digit max;

    for (int i = 0; i < resultSize; ++i) {

        if (cmp(max, heap.getMax())) {
            max = heap.getMax();
        }

        if (max.index >= windowBegin) {
            result[i] = max;
        }

        if (max.index < windowBegin) {
            while (heap.getMax().index < windowBegin) {
                heap.extractMax();
            }
            max = heap.getMax();
            result[i] = max;
        }

        windowBegin++;
        heap.add(input[windowSize + i]);
    }

    return result;
}


int main() {
    int n = 0;
    std::cin >> n;
    if (n > 100000)
        return 0;

    auto input = new digit [n];
    for (int i = 0; i < n; ++i) {
        std::cin >> input[i].value;
        input[i].index = i;
    }

    int windowSize = 0;
    std::cin >> windowSize;
    if (windowSize < 1)
        return 0;

    digit *output = findSlideMax(input, n, windowSize, digitCompare());

    for (int i = 0; i < n - windowSize + 1; ++i) {
        std::cout << output[i].value << " ";
    }

    delete [] input;
    delete [] output;

    return 0;
}
