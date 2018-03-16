#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


struct Queue {
      struct Elem *head;
      struct Elem *tail;
};

struct Elem {
    int data;
    struct Elem *next;
    struct Elem *prev;
};

void queue_init(struct Queue *q) {
    memset(q, 0, sizeof(*q));
}

static struct Elem *element_alloc(int data) {
    struct Elem *element = calloc(1, sizeof(struct Elem));

    if (element == NULL) {
        printf("%s\n", "Error" );
        return NULL;
    }

    element->data = data;

    return element;
}

void queue_push(struct Queue *q, int data) {
    struct Elem *element = element_alloc(data);

    if (q->tail != NULL) {
        element->next = q->tail;
        q->tail->prev = element;
    } else {
        q->head = element;
    }

    q->tail = element;
}

int queue_pop(struct Queue *q) {
    if (q->head == NULL)
        return NULL;

    struct Elem *element = q->head->prev;

    free(q->head);
    q->head = element;

}
