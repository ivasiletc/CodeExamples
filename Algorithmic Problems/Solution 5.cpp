#include <iostream>
#include <cstdio>
#include "unistd.h"

using namespace std;


long long miasta = 0, paliwo = 0, maxpal = 0, tmp;

struct Miasto {
    int stpal, droga;
};

int main() {
    //---------------------Cчитывание--------------------
    char* line = new char[100000000];
    // fgets(line, 100000000, stdin);
    read(0, line, 100000000);

    int iter = 0;

    while (*line >= 48) {
        miasta = (miasta << 3) + (miasta << 1) + *line - '0';
        line++;
    }
    line++;

    //---------------------Массив------------------------
    Miasto m[miasta];
    //---------------------Инициализация массива---------

    //---------------------Алгоритм-----------------------
    int index;

    int i = 0;
    //        for(; i < miasta; i++){
    //        paliwo = paliwo + m[i].stpal - m[i].droga;
    //        if (paliwo < maxpal) {
    //            maxpal = paliwo;
    //            index = i + 1;
    //        }
    //        if (index >= miasta) {
    //            index = 0;
    //        }

    for (; i < miasta; ++i) {
        while (*line >= 48) {
            m[i].stpal = (m[i].stpal << 3) + (m[i].stpal << 1) + *line - '0';
            line++;
        }
        line++;
        while (*line >= 48) {
            m[i].droga = (m[i].droga << 3) + (m[i].droga << 1) + *line - '0';
            line++;
        }
        line++;

        paliwo = paliwo + m[i].stpal - m[i].droga;
        if (paliwo < maxpal) {
            maxpal = paliwo;
            index = i + 1;
        }
    }

    if (index >= miasta) {
        index = 0;
    }

    maxpal = 0;
    paliwo = 0;
    i = index;
    while (true) {

        paliwo = paliwo + m[i].stpal - m[i].droga;

        if (paliwo > maxpal) {
            maxpal = paliwo;
        }
        i++;
        if (i >= miasta) {
            i = 0;
        }
        if (i == index) {
            break;
        }
    }

    //    }

    printf("%i %lli", index, maxpal);

}