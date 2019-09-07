/*
Составить программу разложения положительного целого числа на простые сомножители и единицу. 

Программа считывает входные данные со стандартного ввода, и печатает результат в стандартный вывод. 

Верными входными данными считается только ровно одно положительное число, не превосходящее 2^63 - 1, возможно с предшествующими или последующими пробельными символами. 

Хотя единица не входит в каноническое разложение, но в ответе первым элементом всегда необходимо выводить единицу. 
Считать, что разложение самой единицы состоит только из единицы. 

Процедура разложения числа должна быть оформлена в виде отдельной функции, которой на вход подается целое число. 
Функция должна возвращать указатель на массив целых чисел, содержащий разложение введенного числа на простые сомножители. 
Последний элемент этого массива должен быть нулевым. 

Программа должна уметь обрабатывать ошибки - такие как неверные входные данные(не число, отрицательное число), ошибки выделения памяти и т.п.
В случае возникновения ошибки нужно вывести сообщение "[error]" (без кавычек) и завершать выполнение программы. 

ВАЖНО! Программа в любом случае должна возвращать 0. Не пишите return -1, exit(1) и т.п. Даже если обнаружилась какая-то ошибка, все равно необходимо вернуть 0! (и напечатать [error] в stdout).
*/


#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>

#define STD_ERROR_MSG "[error]"

unsigned long long *factorization(unsigned long long input) {
    unsigned long long size_of_buffer = (input / 2) + 2;
    unsigned long long *result = (unsigned long long*)malloc(sizeof(unsigned long long) * size_of_buffer);

    if (result == NULL) {
        printf(STD_ERROR_MSG);
        return NULL;
    }

    unsigned long long index = 1;
    result[0] = 1;

    for (unsigned long long i = 2; i * i <= input; ++i) {
        while (input % i == 0) {
            input /= i;
            result[index++] = i;
        }
    }

    if (input > 1)
        result[index++] = input;
    result[index] = 0;

    return result;
}


int main() {
    long long input = 0;

    if (scanf(" %lld", &input) < 1) {
        printf(STD_ERROR_MSG);
        return 0;
    }
    int c;
    while((c = getchar()) != '\n' && c != EOF) {
        if (c != ' ') {
            printf(STD_ERROR_MSG);
            return 0;
        }
    }

    if (input <= 0) {
        printf(STD_ERROR_MSG);
        return 0;
    }

    unsigned long long *result = factorization((unsigned long long) input);

    if (result == NULL)
        return 0;

    for (int i = 0; result[i] != 0; ++i) {
        printf("%lld ", result[i]);
    }

    free(result);
    return 0;
}
