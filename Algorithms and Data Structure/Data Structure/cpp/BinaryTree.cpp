#include <iostream>


struct node {
    int value;
    node *left;
    node *right;
};

void add_element(node *&root, int value) {
    if (root == NULL){
        root = new node;
        root->value = value;
        root->left = root->right = NULL;
        return;
    }

    if (value > root->value)
        add_element(root->right, value );
    else
        add_element(root->left, value);
}

void inverse(node *root) {
    if (root == NULL)
        return;

    inverse(root->left);
    cout << root->value << " ";
    inverse(root->right);
}

void reverse(node *root) {
    if (root == NULL)
        return;

    reverse(root->right);
    cout << root->value << " ";
    reverse(root->left);
}

void search(node *root, int x) {
    if (root == NULL)
        return 0;
    if (x == root->value) {
        return 1;
    }
    
    search(root->left,x);
    search(root->right,x);
}
