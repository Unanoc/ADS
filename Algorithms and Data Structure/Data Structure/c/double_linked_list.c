#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


struct List {
      int data;
      struct List *next;
};

void list_init(struct List *v) {
    memset(v, 0, sizeof(*v));
}

static struct List *element_alloc(int data) {
    struct List *element = calloc(1, sizeof(struct List));

    if (element == NULL) {
        printf("%s\n", "Error" );
        return NULL;
    }

    element->data = data;

    return element;
}

struct List *find_tail(struct List *head) {
    if (head == NULL) {
        return head;
    }

    while (head->next) {
        head = head->next;
    }

    return head;
}

struct List *list_push(struct List *head, int data) {
    struct List *tail = find_tail(head);
    struct List *new_element = element_alloc(data);

    if (tail != NULL) {
        tail->next = new_element;
    }

    tail = new_element;

    return tail;
}

struct List *list_remove(struct List *head, unsigned int index) {
    if (head == NULL)
        return NULL;

    struct List *element = head;
    struct List *previous = NULL;

    while (index && index--) {
        previous = element;
        element = element->next;

        if (element == NULL)
            return head;
    }

    previous->next = element->next;
    free(element);
}
