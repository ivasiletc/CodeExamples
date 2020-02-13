#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

//#define getchar_unlocked getchar

using namespace std;

int getNum() { int i = 0; bool negative = false; int c = getchar_unlocked(); if (c == '-') { negative = true; c = getchar_unlocked(); } while (c >= 48 && c <= 57) { i = (i << 3) + (i << 1) + c - 48; c = getchar_unlocked(); } if (!negative)return i; else return -i; }

struct Place {
    int owner = -1;
    vector <int> neighbours;
};

int main() {
    //----------------------------------
    int n = getNum();
    //----------------------------------
    int  cityInd[n];
    for (int i = 0; i < n; i++)cityInd[i] = -1;
    //----------------------------------
    int tmp1 = getNum();
    int tmp2 = getNum();
    Place placesA[n];
    Place placesB[n];
    //----------------------------------
    while (tmp1 != -1 && tmp2 != -1) {
        placesA[tmp1].neighbours.push_back(tmp2);
        placesA[tmp2].neighbours.push_back(tmp1);
        placesB[tmp1].neighbours.push_back(tmp2);
        placesB[tmp2].neighbours.push_back(tmp1);
        tmp1 = getNum();
        tmp2 = getNum();
    }
    //----------------------------------
    int k = getNum();
    int tmp3;
    for (int i = 0; i < k; i++) {
        tmp3 = getNum();
        placesA[tmp3].owner = i;
        placesB[tmp3].owner = i;
        cityInd[tmp3] = i;
    }
    //----------------------------------
        // cout << "---------------------------"<< endl;
    bool isOk = false;
    map<int, map<int, int> > mapA;
    map<int, map<int, int> > mapB;
    int maxInd;
    int minInd;
    int maxVal;
    bool statA;
    bool statB;
    while (isOk == false) {
        mapA.clear();
        mapB.clear();
        isOk = true;
        //----------------------------------
        for (int i = 0; i < n; i++) {
            if (cityInd[i] == -1) {
                isOk = false;
                if (placesA[i].neighbours.size() == 0) {
                    cityInd[i] = i;
                }
                if (placesB[i].neighbours.size() == 0) {
                    cityInd[i] = i;
                }
                for (int c = 0; c < placesA[i].neighbours.size(); c++) {
                    if (placesA[placesA[i].neighbours[c]].owner != -1) {
                        mapA[i][placesA[placesA[i].neighbours[c]].owner]++;
                    }
                }
                for (int c = 0; c < placesB[i].neighbours.size(); c++) {
                    if (placesB[placesB[i].neighbours[c]].owner != -1) {
                        mapB[i][placesB[placesB[i].neighbours[c]].owner]++;
                    }
                }
            }
        }


        //----------------------------------
        //---------Wariant_A----------------
        for (std::map<int, std::map<int, int> >::iterator it = mapA.begin(); it != mapA.end(); it++) {
            maxVal = 9999999;
            maxInd = -1;
            for (std::map<int, int>::iterator it1 = it->second.begin(); it1 != it->second.end(); it1++) {

                if (it1->second < maxVal) {
                    maxVal = it1->second;
                    maxInd = it1->first;
                    placesA[it->first].owner = it1->first;
                    cityInd[it->first] = it->first;
                }
                else if (it1->second == maxVal) {
                    if (it1->first > maxInd) {
                        placesA[it->first].owner = it1->first;
                        cityInd[it->first] = it->first;
                        maxInd = it1->first;
                    }
                }
            }
        }
        //--------Wariant_B--------------------
        for (std::map<int, std::map<int, int> >::iterator it = mapB.begin(); it != mapB.end(); it++) {
            maxVal = 1;
            minInd = 9999999;
            for (std::map<int, int>::iterator it1 = it->second.begin(); it1 != it->second.end(); it1++) {
                if (it1->second > maxVal) {
                    maxVal = it1->second;
                    minInd = it1->first;
                    placesB[it->first].owner = it1->first;
                    cityInd[it->first] = it->first;
                }
                else if (it1->second == maxVal) {
                    if (it1->first < minInd) {
                        placesB[it->first].owner = it1->first;
                        cityInd[it->first] = it->first;
                        minInd = it1->first;
                    }
                }
            }
        }

        //----------------------------------

    }
    map<int, int> resultA;
    map<int, int> resultB;
    for (int i = 0; i < n; i++) {
        resultA[placesA[i].owner]++;
        resultB[placesB[i].owner]++;
    }
    for (int i = 0; i < k; i++) {
        cout << resultA[i] << " " << resultB[i] << endl;
    }

    return 0;
}

/*
 * PRZYKLAD 1

wejscie:

3
0 1
1 2
0 2
-1 -1
2
0
1

3
0 1
1 2
0 2
-1 -1
3
0
1
2

wyjscie:

1 2
2 1

PRZYKLAD 2

wejscie:

6
1 0
2 1
3 0
3 1
3 2
4 2
4 3
5 0
5 2
-1 -1
3
0
1
5

wyjscie:
1 3
2 2
3 1

PRZYKLAD 3

wejscie:

20
3 0
5 1
6 1
7 4
7 5
8 4
10 3
10 9
11 5
11 8
12 4
12 5
12 6
12 10
13 1
13 3
13 5
14 1
14 6
14 7
15 12
15 13
15 14
16 4
16 8
16 9
16 13
17 0
17 2
17 5
17 7
17 15
18 5
18 7
19 3
19 4
19 7
19 10
19 13
19 14
-1 -1
10
3
2
19
5
15
14
4
8
17
11
wyjscie:
1 5
1 1
2 2
2 4
2 1
3 2
2 2
3 1
3 1
1 1
 * */
