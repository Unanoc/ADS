/*
 Дано число N и N строк. Каждая строка содержит команду добавления или удаления натуральных чисел,
 а также запрос на получение k-ой порядковой статистики. Команда добавления числа A задается положительным
 числом A, команда удаления числа A задается отрицательным числом “-A”. Запрос на получение k-ой порядковой
 статистики задается числом k. Требуемая скорость выполнения запроса - O(log n).
 */
#include <iostream>
#include <cassert>

template <class T>
class AVLTree {
public:
    AVLTree() = default;
    ~AVLTree();

    void add(T value);
    void del(T value);
    T get_stat_k(int k);

private:
    struct Node {
        T value;
        int height;
        int size;
        Node *left;
        Node *right;

        explicit Node(T value) : value(value), height(1), size(1), left(nullptr), right(nullptr) {}
    };

    int _getHeight(Node *tree);
    int _balanceFactor(Node *tree);
    void _fixHeight(Node *tree);
    void _fixSize(Node *tree);
    Node *_findMin(Node *tree);

    Node *_rightRotate(Node *p); /* small left rotation */
    Node *_leftRotate(Node *q); /* small right rotation */
    Node *_balanceNode(Node *tree); /* big right/left rotation */

    Node *_add(Node *tree, T value);
    Node *_del(Node *tree, T value);
    Node *_delMin(Node *tree);

    Node *root = nullptr;
};

template<class T>
AVLTree<T>::~AVLTree() {
    while (root != nullptr) {
        del(root->value);
    }
}

template<class T>
void AVLTree<T>::add(T value) {
    root = _add(root, value);
}

template<class T>
void AVLTree<T>::del(T value) {
    root = _del(root, value);
}

template<class T>
T AVLTree<T>::get_stat_k(int k) {
    Node *currentNode = root;

    while (currentNode && k >= 0) {
        int leftNodeSize = currentNode->left ? currentNode->left->size : 0;
        if (leftNodeSize == k) {
            return currentNode->value;
        }

        currentNode = leftNodeSize > k ? currentNode->left : currentNode->right;

        if (leftNodeSize < k) {
            k -= leftNodeSize + 1;
        }
    }

    throw std::exception(); /* k'th order statistics was not found */
}

template<class T>
int AVLTree<T>::_getHeight(AVLTree<T>::Node *tree) {
    return tree ? tree->height : 0;
}

template<class T>
int AVLTree<T>::_balanceFactor(AVLTree<T>::Node *tree) {
    return _getHeight(tree->right) - _getHeight(tree->left);
}

template<class T>
void AVLTree<T>::_fixHeight(AVLTree<T>::Node *tree) {
    int hl = _getHeight(tree->left);
    int hr = _getHeight(tree->right);
    tree->height = (hl > hr ? hl : hr) + 1;
}

template<class T>
void AVLTree<T>::_fixSize(AVLTree::Node *tree) {
    tree->size = 1;
    if (tree->left) {
        tree->size += tree->left->size;
    }
    if (tree->right) {
        tree->size += tree->right->size;
    }
}

template<class T>
typename AVLTree<T>::Node *AVLTree<T>::_findMin(AVLTree<T>::Node *tree) {
    return tree->left ? _findMin(tree->left) : tree;
}

template<class T>
typename AVLTree<T>::Node *AVLTree<T>::_rightRotate(AVLTree<T> ::Node *p) {
    Node *q = p->left;
    p->left = q->right;
    q ->right = p;
    _fixHeight(p);
    _fixHeight(q);
    _fixSize(p);
    _fixSize(q);
    return q;
}

template<class T>
typename AVLTree<T>::Node *AVLTree<T>::_leftRotate(AVLTree<T>::Node *q) {
    Node *p = q->right;
    q->right = p->left;
    p->left = q;
    _fixHeight(q);
    _fixHeight(p);
    _fixSize(q);
    _fixSize(p);
    return p;
}

template<class T>
typename AVLTree<T>::Node *AVLTree<T>::_balanceNode(AVLTree<T>::Node *tree) {
    _fixSize(tree);
    _fixHeight(tree);

    if (_balanceFactor(tree) == 2) { /* tree.right - tree.left = 2 */
        if (_balanceFactor(tree->right) < 0) { /* tree.right.right < tree.right.left */
            tree->right = _rightRotate(tree->right);
        }
        return _leftRotate(tree);
    }

    if (_balanceFactor(tree) == -2) {
        if (_balanceFactor(tree->left) > 0) {
            tree->left = _leftRotate(tree->left);
        }
        return _rightRotate(tree);
    }

    return tree; /* tree does not need in balance */
}

template<class T>
typename AVLTree<T>::Node *AVLTree<T>::_add(Node *tree, T value) {
    if (tree == nullptr) {
        return new Node(value);
    }

    if (value < tree->value) {
        tree->left = _add(tree->left, value);
    }
    else {
        tree->right = _add(tree->right, value);
    }

    return _balanceNode(tree);
}

template<class T>
typename AVLTree<T>::Node *AVLTree<T>::_del(Node *tree, T value) {
    if (!tree) {
        return nullptr;
    }

    if (value < tree->value) {
        tree->left = _del(tree->left, value);
    }
    else {
        if (value > tree->value) {
            tree->right = _del(tree->right, value);
        }
        else { /* value == tree.value */
            Node *leftChild = tree->left;
            Node *rightChild = tree->right;
            delete tree;

            if (!rightChild) { /* if rightChild == empty */
                return leftChild;
            }

            Node *minNode = _findMin(rightChild);
            minNode->right = _delMin(rightChild);
            minNode->left = leftChild;
            return _balanceNode(minNode);
        }
    }

    return _balanceNode(tree);
}

template<class T>
typename AVLTree<T>::Node *AVLTree<T>::_delMin(AVLTree<T>::Node *tree) {
    if (!tree->left) {
        return tree->right;
    }
    tree->left = _delMin(tree->left);
    return _balanceNode(tree);
}


int main() {
    int count = 0;
    std::cin >> count;

    AVLTree<int> avlTree;
    for (int i = 0; i < count; ++i) {
        int value = 0;
        int k_stat = 0;

        std::cin >> value >> k_stat;
        assert(k_stat >= 0);
        if (value < 0) {
            avlTree.del(-value);
        }
        else {
            avlTree.add(value);
        }

        std::cout << avlTree.get_stat_k(k_stat) << std::endl;
    }

    return 0;
}
