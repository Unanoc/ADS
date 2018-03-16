#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


struct Stack {
      struct Elem *top;
};

struct Elem {
      int data;
      struct Elem *next;
      struct Elem *prev;
};

void stack_init(struct Stack *s) {
    memset(s, 0, sizeof(*s));
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

struct Elem *stack_push(struct Stack *s, int data) {
    struct Elem *element = element_alloc(data);

    if (s->top == NULL) {
        s->top = element;
        s->top->next = s->top->prev = NULL;
        return s->top;
    }

    s->top->next = element;
    element->prev = s->top;
    s->top = element;

    return s->top;
}

struct Elem *stack_pop(struct Stack *s) {
    if (s->top == NULL)
        return NULL;

	
   if (s->top->prev == NULL) {
        free(s->top);
        s->top = NULL;
        return NULL;
    }

    struct Elem *element = s->top->prev;
    free(s->top);
    s->top = element;
    s->top->next = NULL;

    return s->top;
}

int stack_get_top(struct Stack *s) {
    if (s->top == NULL)
        return NULL;

    return s->top->data;
}
