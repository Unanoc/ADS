/*
 Реализуйте структуру данных типа “множество строк” на основе динамической хеш-таблицы
 с открытой адресацией. Хранимые строки непустые и состоят из строчных латинских букв.
 Хеш-функция строки должна быть реализована с помощью вычисления значения многочлена методом Горнера.
 Начальный размер таблицы должен быть равным 8-ми. Перехеширование выполняйте при добавлении элементов в случае,
 когда коэффициент заполнения таблицы достигает 3/4.
 Структура данных должна поддерживать операции добавления строки в множество, удаления
 строки из множества и проверки принадлежности данной строки множеству.

 Для разрешения коллизий используйте двойное хеширование.

 Формат входных данных
    Каждая строка входных данных задает одну операцию над множеством.
    Запись операции состоит из типа операции и следующей за ним через пробел строки,
    над которой проводится операция.
    Тип операции  – один из трех символов:
        +  означает добавление данной строки в множество;
        -  означает удаление  строки из множества;
        ?  означает проверку принадлежности данной строки множеству.
    При добавлении элемента в множество НЕ ГАРАНТИРУЕТСЯ, что он отсутствует в этом множестве.
    При удалении элемента из множества НЕ ГАРАНТИРУЕТСЯ, что он присутствует в этом множестве.
 Формат выходных данных
 Программа должна вывести для каждой операции одну из двух строк OK или FAIL, в зависимости от того,
 встречается ли данное слово в нашем множестве.

*/

#include <iostream>
#include <vector>

const std::string NIL = "NIL";
const std::string DEL = "DEL";

const int INIT_SIZE = 8;
const int HASH_CONST_1 = 307;
const int HASH_CONST_2 = 401;



template <class T>
struct Hasher {
    Hasher() {};
    int operator() (T str, int size, bool type);
};

template <class T>
int Hasher<T>::operator()(T str, int size, bool type) {
    int hash = 0;
    for (int i = 0; i < str.size(); ++i) {
        hash = (2 * (hash * (type ? HASH_CONST_1 : HASH_CONST_2) + str[i]) + 1) % size;
    }
    return hash;
}



template <class T, class H = Hasher<T>>
class HashTable {
public:
    HashTable();
    ~HashTable();
    bool add(T data);
    bool del(T data);
    bool has(T data);

private:
    T *_arr;
    H _hasher;
    int elements_count;
    int _size;

    void _expand();
};

template <class T, class H>
HashTable<T, H>::HashTable() {
    elements_count = 0;
    _size = INIT_SIZE;
    _arr = new T[_size];
    for (int i = 0; i < _size; ++i) {
        _arr[i] = NIL;
    }
}

template <class T, class H>
HashTable<T, H>::~HashTable() {
    delete[] _arr;
}

template <class T, class H>
bool HashTable<T, H>::add(T data) {
    if (elements_count >= _size * 3 / 4)
        _expand();

    bool is_found = false;
    int index = -1;

    int first_hash = _hasher(data, _size, 0);
    int second_hash = _hasher(data, _size, 1);
    for (int i = 0; i < _size; ++i) {
        int hash = (first_hash + (i * second_hash)) % _size;

        if (_arr[hash] == data) {
            return false;
        }

        if (_arr[hash] == NIL || _arr[hash] == DEL) {
            index = hash;
            is_found = true;

            if (_arr[hash] == NIL) {
                break;
            }
        }

    }

    if (is_found) {
        _arr[index] = data;
        elements_count++;
    }

    return is_found;
}

template <class T, class H>
bool HashTable<T, H>::del(T data) {
    int first_hash = _hasher(data, _size, 0);
    int second_hash = _hasher(data, _size, 1);

    for (int i = 0; i < _size; ++i) {
        int hash = (first_hash + (i * second_hash)) % _size;

        if (_arr[hash] == NIL) {
            return false;
        }

        if (_arr[hash] == data) {
            _arr[hash] = DEL;
            elements_count--;
            return true;
        }
    }

    return false;
}

template <class T, class H>
bool HashTable<T, H>::has(T data) {
    int first_hash = _hasher(data, _size, 0);
    int second_hash = _hasher(data, _size, 1);

    for (int i = 0; i < _size; ++i) {
        int hash = (first_hash + (i * second_hash)) % _size;

        if (_arr[hash] == NIL) {
            return false;
        }

        if (_arr[hash] == data) {
            return true;
        }
    }

    return false;
}

template <class T, class H>
void HashTable<T, H>::_expand() {
    T *tmp = _arr;
    _arr = new T[_size *= 2];
    elements_count = 0;

    for (int i = 0; i < _size; ++i) {
        _arr[i] = NIL;
    }

    for (int i = 0; i < _size / 2; ++i) {
        if (tmp[i] != DEL && tmp[i] != NIL) {
            add(tmp[i]);
            elements_count++;
        }
    }

    delete [] tmp;
}

int main() {
    Hasher<std::string> hasher;
    HashTable<std::string> table;

    std::string operation, input_string;

    while (std::cin >> operation && std::cin >> input_string) {
        bool is_success = false;
        switch (operation[0]) {
            case '+':
                is_success = table.add(input_string);
                break;
            case '-':
                is_success = table.del(input_string);
                break;
            case '?':
                is_success = table.has(input_string);
                break;
            default:
                break;
        }
        std::cout << (is_success ? "OK" : "FAIL") << std::endl;
    }

    return 0;
}
