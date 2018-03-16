#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


struct Vector {
  size_t size;
  size_t capacity;
  int *arr;
};

void vector_init(struct Vector *v) {
    memset(v, 0, sizeof(*v));
}

void vector_expand(struct Vector *v, int n) {
    if (v->capacity >= v->size + n) {
        return;
    }

    if (v->capacity == 0) {
        v->capacity = 4;
    } else {
        v->capacity *= 2;
    }

    v->arr = realloc(v->arr, sizeof(int) * v->capacity);
    if (v->arr == NULL){
        printf("%s\n", "Error: array is NULL." );
    }
}

void vector_push_back(struct Vector *v, int element) {
    vector_expand(v, 1);
    v->arr[v->size++] = element;
}

void vector_pop_back(struct Vector *v) {
    if (v->size == 0) {
        printf("%s", "Vector id empty.");
        return;
    } else {
        if ((v->capacity > 10) && (v->size < v->capacity / 2)) {
            v->capacity /= 2;
            v->arr = realloc(v->arr, sizeof(int) * v->capacity);
        }
        v->size--;
    }
}
