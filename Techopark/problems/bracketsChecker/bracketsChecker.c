/* Написать программу, которая в качестве аргумента командной строки принимает имя текстового фай-
ла, содержащего строку символов, в которой записано выражение со скобками трёх типов: [ ], { }, ( ).
Необходимо определить, правильно ли расставлены скобки (не учитывая остальные символы) и напе-
чатать на стандартный выходной поток результат.
При реализации алгоритма необходимо использовать стек. Например, в выражении [()]{} скобки рас-
ставлены правильно, а в выражениях ][ и [({)]} неправильно. */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define SUCCESS "Скобки расставлены правильно!"
#define FAIL "Скобки расставлены неправильно!"

struct Stack {
      struct Elem *top;
};

struct Elem {
      char data;
      struct Elem *next;
      struct Elem *prev;
};

struct Stack* stack_init(struct Stack *s) {
    memset(s, 0, sizeof(*s));
}

static struct Elem *element_alloc(char data) {
    struct Elem *element = calloc(1, sizeof(struct Elem));

    if (element == NULL) {
        printf("%s\n", "Error" );
        return NULL;
    }

    element->data = data;

    return element;
}

struct Elem *stack_push(struct Stack *s, char data) {
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

struct Stack *stack_empty(struct Stack *s) {
    if (s->top == NULL)
        return NULL;

    while (s->top) {
        stack_pop(s);
    }
}

int stack_get_top(struct Stack *s) {
    if (s->top == NULL)
        return -1;

    return (int)s->top->data;
}

int isBracket(char smbl) {
    if ((smbl == '(') || ((int)smbl == '{') || ((int)smbl == '['))
        return 1;

    if (((int)smbl == ')') || ((int)smbl == '}') || ((int)smbl == ']'))
        return 2;

    return 0; //not bracket
}

void check_file (FILE * file, struct Stack *a, int *isCorrect) {
    char ch;

    while ((ch = fgetc(file)) != EOF) {
          if (isBracket(ch) == 1) {
              stack_push(a, ch);
          }

          if (isBracket(ch) == 2) {

              if ((stack_get_top(a) + 1 == ch) || (stack_get_top(a) + 2 == ch)) {
                  stack_pop(a);
              } else {
                  *isCorrect = 1;
                  break;
              }
          }

      }
}


int main(int argc, char* argv[]) {

    struct Stack a;
    stack_init(&a);

    FILE *file = fopen(argv[1], "r+");
    int isCorrect = 0;

    if (file == NULL)
        printf("%s\n", "Error opening file");
    else {

        check_file(file, &a, &isCorrect);

        if ((stack_get_top(&a) == -1) && (isCorrect == 0)) // is stack empty?
            printf("%s\n", SUCCESS);
        else
            printf("%s\n", FAIL);
    }

    stack_empty(&a);
    fclose(file);

    return 0;
}
