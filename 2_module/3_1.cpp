/*
 Дано число N < 106 и последовательность пар целых чисел из [-231..231] длиной N.
 Построить декартово дерево из N узлов, характеризующихся парами чисел {Xi, Yi}.
 Каждая пара чисел {Xi, Yi} определяет ключ Xi и приоритет Yi в декартовом дереве.
 Добавление узла в декартово дерево выполняйте второй версией алгоритма, рассказанного на лекции:
 При добавлении узла (x, y) выполняйте спуск по ключу до узла P с меньшим приоритетом.
 Затем разбейте найденное поддерево по ключу x так, чтобы в первом поддереве все ключи меньше x,
 а во втором больше или равны x. Получившиеся два дерева сделайте дочерними для нового узла (x, y).
 Новый узел вставьте на место узла P.

 Построить также наивное дерево поиска по ключам Xi методом из задачи 2.
*/


#include <iostream>
#include <vector>
#include <stack>
#include <queue>

template <typename T>
class BinaryTree {
public:
    BinaryTree() = default;
    ~BinaryTree();

    void add(T value);
    int getHeight() const;

private:
    struct Node {
        explicit Node(T value) : value(value) {}
        T value;
        Node *left = nullptr;
        Node *right = nullptr;
    };

    std::vector<Node *> _get_Nodes_in_order_passing() const;

    Node *root = nullptr;
};

template<typename T>
BinaryTree<T>::~BinaryTree() {
    std::vector<Node *> Nodes = _get_Nodes_in_order_passing();
    for (Node * Node : Nodes) {
        delete [] Node;
    }
}

template<typename T>
void BinaryTree<T>::add(T value) {
    if (root == nullptr) {
        root = new Node(value);
    }
    else {
        Node *currentNode = root;
        while (true) {
            if (currentNode->value <= value) {
                if (currentNode->right == nullptr) {
                    currentNode->right = new Node(value);
                    break;
                }
                else {
                    currentNode = currentNode->right;
                }
            }
            else {
                if (currentNode->left == nullptr) {
                    currentNode->left = new Node(value);
                    break;
                }
                else {
                    currentNode = currentNode->left;
                }
            }
        }
    }
}

template<typename T>
int BinaryTree<T>::getHeight() const {
    if (root == nullptr) {
        return 0;
    }

    int maxHeight = 1;
    std::queue<std::pair<Node *, int >> q;
    q.push(std::make_pair(root, 1));

    while (!q.empty()) {
        std::pair<Node*, int > currentPair = q.front();
        q.pop();
        Node *currentNode = currentPair.first;
        int currentHeight = currentPair.second;

        if (currentHeight > maxHeight) {
            maxHeight = currentHeight;
        }

        if (currentNode->left != nullptr) {
            q.push(std::make_pair(currentNode->left, currentHeight + 1));
        }

        if (currentNode->right != nullptr) {
            q.push(std::make_pair(currentNode->right, currentHeight + 1));
        }
    }

    return maxHeight;
}

template<typename T>
std::vector<typename BinaryTree<T>::Node *> BinaryTree<T>::_get_Nodes_in_order_passing() const {
    std::vector<Node *> result;
    std::stack<Node *> stack;

    Node *currentNode = root;
    while (!stack.empty() || currentNode != nullptr) {
        if (currentNode != nullptr) {
            stack.push(currentNode);
            currentNode = currentNode->left;
        }
        else {
            currentNode = stack.top();
            stack.pop();
            result.push_back(currentNode);
            currentNode = currentNode->right;
        }
    }

    return result;
}



template <typename T, typename K>
class Treap {
public:
    Treap() = default;
    ~Treap();

    void add(T value, K priority);
    int getHeight() const;

private:
    struct Node {
        explicit Node(T value, K priority) : value(value), priority(priority) {}

        T value;
        K priority;
        Node *left = nullptr;
        Node *right = nullptr;
    };

    std::pair<Node *, Node*> _split(Node *tree, T value);
    Node *_merge(Node *leftTree, Node *rightTree);
    std::vector<Node *> _get_Nodes_in_order_passing() const;

    Node *root = nullptr;
};

template<typename T, typename K>
Treap<T, K>::~Treap() {
    std::vector<Node *> entries = _get_Nodes_in_order_passing();
    for (Node * Node : entries) {
        delete [] Node;
    }
}

template<typename T, typename K>
void Treap<T, K>::add(T value, K priority) {
    if (root == nullptr) {
        root = new Node(value, priority);
    }
    else {
        Node *currentNode = root;
        Node *currentNodeParent = nullptr;
        bool isCurrentNodeLeft = false;

        while (true) {
            if (currentNode == nullptr) {
                break;
            }

            if (priority > currentNode->priority) {
                break;
            }

            if (value >= currentNode->value) {
                currentNodeParent = currentNode;
                isCurrentNodeLeft = false;
                currentNode = currentNode->right;
            }
            else {
                currentNodeParent = currentNode;
                isCurrentNodeLeft = true;
                currentNode = currentNode->left;
            }
        }

        auto newNode = new Node(value, priority);
        auto splits = _split(currentNode, value);
        newNode->left = splits.first;
        newNode->right = splits.second;

        if (currentNodeParent) {
            if (isCurrentNodeLeft) {
                currentNodeParent->left = newNode;
            }
            else {
                currentNodeParent->right = newNode;
            }
        }
        else {
            root = newNode;
        }
    }
}

template<typename T, typename K>
int Treap<T, K>::getHeight() const {
    if (root == nullptr) {
        return 0;
    }

    int maxHeight = 1;
    std::queue<std::pair<Node *, int >> q;
    q.push(std::make_pair(root, 1));

    while (!q.empty()) {
        std::pair<Node*, int > currentPair = q.front();
        q.pop();
        Node *currentNode = currentPair.first;
        int currentHeight = currentPair.second;

        if (currentHeight > maxHeight) {
            maxHeight = currentHeight;
        }

        if (currentNode->left != nullptr) {
            q.push(std::make_pair(currentNode->left, currentHeight + 1));
        }

        if (currentNode->right != nullptr) {
            q.push(std::make_pair(currentNode->right, currentHeight + 1));
        }
    }

    return maxHeight;
}

template<typename T, typename K>
std::pair<typename Treap<T, K>::Node *, typename Treap<T, K>::Node *> Treap<T, K>::_split(Treap::Node *tree, T value) {
    if (tree == nullptr) {
        return std::make_pair(nullptr, nullptr);
    }
    else {
        if (tree->value <= value) {
            auto splits = _split(tree->right, value);
            tree->right = splits.first;
            return std::make_pair(tree, splits.second);
        } else {
            auto splits = _split(tree->left, value);
            tree->left = splits.second;
            return std::make_pair(splits.first, tree);
        }
    }
}

template<typename T, typename K>
typename Treap<T, K>::Node *Treap<T, K>::_merge(typename Treap<T, K>::Node *leftTree, typename Treap<T, K>::Node *rightTree) {
    if (leftTree == nullptr || rightTree == nullptr) {
        return leftTree == nullptr ? rightTree : leftTree;
    }
    else {
        if (leftTree->priority > rightTree->priority) {
            leftTree->right = _merge(leftTree->right, rightTree);
            return leftTree;
        }
        else {
            rightTree->left = _merge(leftTree, rightTree->left);
            return rightTree;
        }
    }
}

template<typename T, typename K>
std::vector<typename Treap<T, K>::Node *> Treap<T, K>::_get_Nodes_in_order_passing() const {
    std::vector<Node *> result;
    std::stack<Node *> stack;

    Node *currentNode = root;
    while (!stack.empty() || currentNode != nullptr) {
        if (currentNode != nullptr) {
            stack.push(currentNode);
            currentNode = currentNode->left;
        }
        else {
            currentNode = stack.top();
            stack.pop();
            result.push_back(currentNode);
            currentNode = currentNode->right;
        }
    }

    return result;
}


int main() {
    int elementsCount;
    std::cin >> elementsCount;

    BinaryTree<int> tree;
    Treap<int, int> treap;
    for (int i = 0; i < elementsCount; ++i) {
        int value, priority;
        std::cin >> value;
        std::cin >> priority;
        treap.add(value, priority);
        tree.add(value);
    }

    int differenceOfHeights = tree.getHeight() - treap.getHeight();
    std::cout << differenceOfHeights << std::endl;
    return 0;
}
