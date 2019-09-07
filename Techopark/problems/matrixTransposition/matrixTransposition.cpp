#include <iostream>

int **create_matrix(unsigned rows, unsigned cols) {
    auto array_of_pointers = new int *[rows];
    array_of_pointers[0] = new int [rows*cols];

    for (unsigned i = 1; i != rows; ++i)
        array_of_pointers[i] = array_of_pointers[i - 1] + cols;

    return array_of_pointers;
}

void free_matrix(int **matrix, size_t rows, size_t cols) {
    delete [] matrix[0];
    delete [] matrix;
}

int ** transpose(int ** matrix, unsigned rows, unsigned cols) {
    auto transposed_matrix = create_matrix(rows, cols);

    for (unsigned j = 0; j != cols; ++j) {
        for (unsigned i = 0; i != rows; ++i) {
            transposed_matrix[j][i] = matrix[i][j];
        }
    }
    return transposed_matrix;
}

