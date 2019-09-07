/*
 Реализовать функцию getline()
*/
#include <iostream>

#define INCREASE 2

char *resize(const char *str, unsigned size, unsigned new_size) {
    char *new_str = new char [new_size];
    unsigned min_size = size < new_size ? size : new_size;

    for (int i = 0; i < min_size; ++i){
        new_str[i] = str[i];
    }
    delete [] str;
    return new_str;
}

char *getline() {
    unsigned counter = 0, size = 4;
    char *str = new char[size];
    char input_char;

    while (true) {
        scanf("%c", &input_char);
        if (input_char == '\n') break;
        if (counter == size - 1) {
            str = resize(str, size, size*INCREASE);
            size *= INCREASE;
            str[counter++] = input_char;
        }
        else str[counter++] = input_char;
    }

    if (counter >= size - 1) {
        str = resize(str, size, size*INCREASE);
        str[counter] = '\0';
    } else str[counter] = '\0';
    return  str;
}

