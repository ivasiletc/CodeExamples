#include <unistd.h>
#include <cstdio>

using namespace std;

int main() {
    long long pred = 0;
    int teku = 0, dlS = 1, dlTeku = 1, dlMax = 1;
    long long sumTeku = 0, sumMax = 0;
    bool czyRos = true;

    char* line = new char[100000000];
    // fgets(line, 100000000, stdin);
    read(0, line, 100000000);
    int i = 0;

    while (line[i] >= 48 && line[i] <= 57) {
        teku = (teku << 3) + (teku << 1) + line[i] - 48;
        i++;
    }
    i++;
    sumTeku += teku;
    pred = teku;
    teku = 0;

    while (line[i] != '\0') {
        while (line[i] >= 48 && line[i] <= 57) {
            teku = (teku << 3) + (teku << 1) + line[i] - 48;
            i++;
        }
        i++;

        //-------------Алгоритм---------------
        if (teku > pred) {
            if (czyRos) {
                dlTeku++;
                sumTeku += teku;
            }
            else {
                czyRos = true;
                if (dlTeku > dlMax) {
                    dlMax = dlTeku;
                    sumMax = sumTeku;
                }
                dlTeku = 1 + dlS;
                sumTeku = pred * dlS + teku;
            }
            dlS = 1;
        }
        else if (teku < pred) {
            if (!czyRos) {
                dlTeku++;
                sumTeku += teku;
            }
            else {
                czyRos = false;
                if (dlTeku > dlMax) {
                    dlMax = dlTeku;
                    sumMax = sumTeku;
                }
                dlTeku = 1 + dlS;
                sumTeku = pred * dlS + teku;
            }
            dlS = 1;
        }
        else {
            dlTeku++;
            dlS++;
            sumTeku += teku;
        }
        pred = teku;
        teku = 0;
    }
    if (dlTeku > dlMax) {
        dlMax = dlTeku;
        sumMax = sumTeku;
    }
    printf("%i %lli", dlMax, sumMax);
}