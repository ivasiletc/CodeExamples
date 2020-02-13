#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int getNum() {
    int i = 0;
    int c = getchar_unlocked();
    while (c >= 48 && c <= 57) {
        i = (i << 3) + (i << 1) + c - 48;
        c = getchar_unlocked();
    }
    return i;
}
//--------------------------------
//QuickSort
void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
//--------------------------------
int main() {
    int n = getNum();
    int m = getNum();
    int k = getNum();
    //--------------------------------
    int max;
    //--------------------------------
    int** arrays = new int* [n];
    for (int i = 0; i < n; i++) {
        int tmp = getNum();
        arrays[i] = new int[tmp + 1];
        for (int c = 1; c < tmp + 1; c++) {
            arrays[i][0] = tmp;
            arrays[i][c] = getNum();
        }
        quickSort(arrays[i], 1, tmp - 1);
    }
    //--------------------------------
    int* todo = new int[k * 2];
    for (int i = 0; i < k * 2; i++) {
        todo[i] = getNum();
    }
    vector<int> vec;
    int iter = 0;
    int suma;
    //--------------------------------
    for (int i = 0; i < k; ++i) {
        suma = 0;
        for (int i1 = 0; i1 < vec.size(); i1++)
            suma += vec[i1];

        if (suma % 2 == 0) {
            for (int j = 1; j < arrays[todo[iter]][0] + 1; j++) {
                if (vec.size() < m || arrays[todo[iter]][j] <= max) {
                    vec.push_back(arrays[todo[iter]][j]);
                    sort(vec.begin(), vec.end());
                    if (vec.size() > m) {
                        vec.resize(m);
                        max = vec[m - 1];
                    }
                    else {
                        max = vec[vec.size() - 1];
                    }
                }
                else if (arrays[todo[iter]][j] > max) {
                    break;
                }
            }

            iter += 2;
        }
        else {
            iter++;
            for (int j = 1; j < arrays[todo[iter]][0] + 1; j++) {
                if (vec.size() < m || arrays[todo[iter]][j] <= max) {
                    vec.push_back(arrays[todo[iter]][j]);
                    sort(vec.begin(), vec.end());
                    if (vec.size() > m) {
                        vec.resize(m);
                        max = vec[m - 1];
                    }
                    else {
                        max = vec[vec.size() - 1];
                    }
                }
                else if (arrays[todo[iter]][j] > max) {
                    break;
                }
            }
            iter++;
        }

        //-----------------------
    }
    suma = 0;
    std::map<int, int>map;
    for (int l = 0; l < m; ++l) {
        suma += vec[l];
        map[vec[l]]++;
    }

    cout << suma << " " << map.size();
}


/*
 *PRZYKLAD 1

wejscie:

3 5 4
1 1
5 0 8 5 8 9
5 1 0 3 1 2
0 1
1 0
0 2
2 1

wyjscie:

8 3

KOMENTARZ DO ROZWIAZANIA
Zgodnie z danymi wejsciowymi zachodzi
x(0)={1}
x(1)={0,8,5,8,9}
x{2}={1,0,3,1,2}
Dalej, rozwazane 4 krotne zlozenie operatora sumy alternatywnej z obcieciem na zbiorze pustym, gdzie m=5, ma postac:
krok nr 1: [{},x{0},x{1},5]=|{}+x{0},5|={1}
krok nr 2: [{1},x{1},x{0},5]=|{1}+x{0},5|={1,1}
krok nr 3: [{1,1},x{0},x{2},5|=|{1,1}+x{0},5|={1,1,1}
krok nr 4: [{1,1,1},x{2},x{1},5|=|{1,1,1}+x{1},5|=|{0,1,1,1,5,8,8,9},5|={0,1,1,1,5}
Stad suma elementow multizbioru bedacego rezultatem rozwazanego zlozenia jest rowna 8,
a sam multizbior sklada sie z elementow o trzech roznych wartosciach.
Zatem odpowiedz stanowi dwojka liczb 8 oraz 3.

PRZYKLAD 2

wejscie:
6 10 10
7 9 9 7 3 9 3 1
4 6 8 5 2
7 8 6 9 6 7 3 1
4 1 9 0 3
9 9 8 8 8 6 4 3 3 6
4 1 9 5 6
1 3
1 4
1 4
0 4
5 4
3 4
1 5
4 1
4 5
5 4

wyjscie:

22 3



PRZYKLAD 3

wejscie:

12 20 20
20 1 8 4 5 8 7 3 8 3 1 4 1 2 9 3 9 3 8 4 6
4 2 2 7 2
16 0 1 9 1 8 7 4 1 7 7 5 9 9 5 2 1
20 7 6 4 0 8 1 3 9 8 1 8 7 3 6 6 9 5 9 6 6
15 7 4 2 7 9 6 7 6 3 9 8 3 5 8 0
12 1 4 9 1 9 8 9 5 0 6 7 9
12 5 2 1 6 7 2 9 4 9 4 5 9
7 3 7 9 6 9 8 8
9 8 1 7 9 9 4 8 7 5
10 6 1 2 0 2 0 2 1 0 7
3 5 1 8
1 0
1 11
7 1
2 5
8 6
11 0
9 9
7 9
4 1
0 3
5 10
9 7
6 10
9 3
8 9
5 1
2 10
8 8
7 2
9 1
6 4
wyjscie:

0 1

*/