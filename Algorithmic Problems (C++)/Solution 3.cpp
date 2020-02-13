#include <iostream>
#include <map>
#include <unistd.h>
#include <cstdio>

using namespace std;

int main() {
    int tmp = 0;
    char* line = new char[15000000];
    read(0, line, 150000000);
    int index = 0;

    int wiersz = 0;
    int podm = 0;

    while (line[index] > 32) {
        wiersz = (wiersz << 3) + (wiersz << 1) + line[index] - 48;
        index++;
    }
    index++;
    while (line[index] > 32) {
        podm = (podm << 3) + (podm << 1) + line[index] - 48;
        index++;
    }
    index++;
    bool neg;

    int** tab = new int* [wiersz + 1];
    for (int i = 0; i < wiersz + 1; i++)
        tab[i] = new int[wiersz + 1];

    for (int i = 1; i < wiersz + 1; ++i) {
        for (int j = 1; j < wiersz + 1; ++j) {
            neg = false;
            if (line[index] == 10) {
                index++;
            }
            while (line[index] > 32) {


                if (line[index] == '-') {
                    neg = true;
                    index++;
                    tmp = (tmp << 3) + (tmp << 1) + line[index] - 48;
                }
                else
                    tmp = (tmp << 3) + (tmp << 1) + line[index] - 48;
                index++;

            }

            if (neg == true) {
                tmp = ~tmp + 1;
            }
            index++;

            tab[i][j] = tmp + tab[i - 1][j] + tab[i][j - 1] - tab[i - 1][j - 1];
            tmp = 0;
        }
    }

    int** bob = new int* [podm];
    for (int i = 0; i < podm; i++)
        bob[i] = new int[4];

    for (int l = 0; l < podm; ++l) {
        for (int i = 0; i < 4; ++i) {

            while (line[index] > 32) {

                tmp = (tmp << 3) + (tmp << 1) + line[index] - 48;
                index++;
            }
            index++;
            bob[l][i] = tmp;
            tmp = 0;
        }
    }

    int abstr = 0;
    int totalSum = 0;
    int sum = 0;
    map<int, int> map;
    for (int i = 0; i < podm; i++) {
        sum =
            tab[bob[i][2] + 1][bob[i][3] + 1] +
            tab[bob[i][0]][bob[i][1]] -
            tab[bob[i][0]][bob[i][3] + 1] -
            tab[bob[i][2] + 1][bob[i][1]];
        totalSum += sum;
        map[sum]++;
    }

    int result = 0;
    int tmp2 = 0;

    for (std::map<int, int>::iterator it = map.begin(); it != map.end(); ++it) {
        if (it->second == tmp2)
            result++;
        else if (it->second > tmp2) {
            result = 1;
            tmp2 = it->second;
        }
    }
    printf("%i %i %i", map.size(), result, totalSum / podm);

}