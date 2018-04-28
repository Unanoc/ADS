/*
 Дано число N и N строк. Каждая строка содержит команду добавления или удаления натуральных чисел,
 а также запрос на получение k-ой порядковой статистики. Команда добавления числа A задается положительным
 числом A, команда удаления числа A задается отрицательным числом “-A”. Запрос на получение k-ой порядковой
 статистики задается числом k. Требуемая скорость выполнения запроса - O(log n).
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

template <class T>
class AVLTree {
public:
    AVLTree() = default;
    ~AVLTree();

    void add(const T& value);
    void del(const T& value);
    T get_stat_k(int k) const;

private:
    struct Node {
        T value;
        int height;
        int size;
        Node *left;
        Node *right;

        explicit Node(const T& value) : value(value), height(1), size(1), left(nullptr), right(nullptr) {}
    };

    int _getHeight(Node *tree) const;
    int _balanceFactor(Node *tree) const;
    void _fixHeight(Node *tree);
    void _fixSize(Node *tree);

    Node *_rightRotate(Node *p); /* small left rotation */
    Node *_leftRotate(Node *q); /* small right rotation */
    Node *_balanceNode(Node *tree); /* big right/left rotation */

    Node *_add(Node *tree, const T& value);
    Node *_del(Node *tree, const T& value);
    Node *_findAndDelMin(Node *tree, Node *&parent);

    std::vector<Node *> _get_nodes_in_order_passing() const;

    Node *root = nullptr;
};

template<class T>
AVLTree<T>::~AVLTree() {
    std::vector<Node *> nodes_in_order = _get_nodes_in_order_passing();
    for (Node* entry : nodes_in_order) {
        delete entry;
    }
}

template<class T>
void AVLTree<T>::add(const T& value) {
    root = _add(root, value);
}

template<class T>
void AVLTree<T>::del(const T& value) {
    root = _del(root, value);
}

template<class T>
T AVLTree<T>::get_stat_k(int k) const {
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
int AVLTree<T>::_getHeight(AVLTree<T>::Node *tree) const {
    return tree ? tree->height : 0;
}

template<class T>
int AVLTree<T>::_balanceFactor(AVLTree<T>::Node *tree) const {
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
typename AVLTree<T>::Node *AVLTree<T>::_add(Node *tree, const T& value) {
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
typename AVLTree<T>::Node *AVLTree<T>::_del(Node *tree, const T& value) {
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
            else {
                Node *minNode = nullptr;
                Node *minNodeRight = _findAndDelMin(rightChild, minNode);
                minNode->right = minNodeRight;
                minNode->left = leftChild;
                return _balanceNode(minNode);
            }
        }
    }

    return _balanceNode(tree);
}

template<class T>
typename AVLTree<T>::Node *AVLTree<T>::_findAndDelMin(AVLTree<T>::Node *tree, AVLTree<T>::Node *&parent) {
    if (!tree->left) {
        parent = tree;
        return tree->right;
    }

    tree->left = _findAndDelMin(tree->left, parent);
    return _balanceNode(tree);
}

template<typename T>
std::vector<typename AVLTree<T>::Node *> AVLTree<T>::_get_nodes_in_order_passing() const {
    std::vector<Node *> result;
    std::stack<Node *> stack;

    Node *currentEntry = root;

    while (!stack.empty() || currentEntry != nullptr) {
        if (currentEntry != nullptr) {
            stack.push(currentEntry);
            currentEntry = currentEntry->left;
        }
        else {
            currentEntry = stack.top();
            stack.pop();
            result.push_back(currentEntry);
            currentEntry = currentEntry->right;
        }
    }

    return result;
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
