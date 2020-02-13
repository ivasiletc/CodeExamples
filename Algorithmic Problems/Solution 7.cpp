#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <unistd.h>
#include <stdio.h>

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
int main() {
    int size = getNum();
    int start = getNum();
    bool ok = false;
    //--------------------------------------


    int** tab = new int* [size];
    for (int i = 0; i < size; i++)
        tab[i] = new int[size];

    for (int c = 0; c < size; c++) {
        for (int i = 0; i < size; i++) {
            tab[c][i] = getNum();
            if (tab[c][i] == 0)
                ok = true;
        }
        if (!ok) {
            printf("ERROR %d", c);
            return 0;
        }
        ok = false;
    }

    //--------------------------------------
    std::map<int, int> map;
    std::map<int, int> tmp;
    vector<int> res;
    //---------
    int left = start;
    int right = start;
    int countL = 0;
    int countR = 0;
    //---------
    //--------------------------------------
        //Шаг первый
    while (tab[0][left] != 0) {
        left--;
        countL++;
        if (left < 0)
            left = size - 1;
    }
    while (tab[0][right] != 0) {
        right++;
        countR++;
        if (right == size)
            right = 0;
    }

    map[left] = countL;
    if (map.find(right) == map.end() || countL > countR) {
        map[right] = countR;
        //cout <<"В мапу вставлено значение: " << map[right]<<endl;
    }
    // cout <<"В мапу вставлено значение: " << map[left]<< endl;
 //--------------------------------------
    int suma;
    int first;
    int second;
    for (int i = 0; i < size; i++) {
        for (std::map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            first = it->first;
            second = it->second;
            //cout << "Dyrka: " << first << ", rasstojanije: " << second << endl;
            suma = 0;
            while (tab[i][first] != 0) {
                first++;
                suma++;
                if (first == size)
                    first = 0;
            }
            if (tmp.find(first) == tmp.end() || tmp[first] > (suma + second)) {
                tmp[first] = suma + second;
                //cout << "90"<< endl ;
            }
            first = it->first;
            suma = 0;
            while (tab[i][first] != 0) {
                first--;
                suma++;
                if (first < 0)
                    first = size - 1;
            }
            if (tmp.find(first) == tmp.end() || tmp[first] > (suma + second)) {
                tmp[first] = suma + second;
                //cout << "102"<< endl;
            }
        }
        //cout << map.size() << " " << tmp.size() << endl;
        map.clear();
        map.insert(tmp.begin(), tmp.end());
        tmp.clear();
    }
    //-----------------------------------------------
        //Финальная проверка
    bool isOk = false;
    for (std::map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
        first = it->first;
        second = it->second;
        //cout << "Dyrka: " << first << ", rasstojanije: " << second << endl;
        isOk = false;
        suma = 0;
        //---------------
        while (first != start) {
            if (tab[0][first] == 0) {
                //cout << " 0 ";
                isOk = true;
                break;
            }
            else {
                //cout << " 1 ";
                suma++;
            }
            first--;
            if (first < 0)
                first = size - 1;
        }
        //cout << endl;
        if (!isOk) {
            //cout << "Suma: " << suma << " tmp " << second << endl;
            res.push_back(suma + second);
        }
        first = it->first;
        suma = 0;
        isOk = false;
        //---------------
        while (first != start) {
            if (tab[0][first] == 0) {
                isOk = true;
                break;
            }
            else {
                //cout << " 1 " ;
                suma++;
            }
            first++;
            if (first == size)
                first = 0;
        }
        //cout << endl;
        if (!isOk) {
            //cout << "Suma: " << suma << " tmp " << second << endl;
            res.push_back(suma + second);
        }
    }
    //------------------------------------------------
    //    for(int i; i < res.size(); i++){
    //        cout << res[i] << " ";
    //    }
    //------------------------------------------------
    if (res.size() == 0)
        printf("ERROR %d", size - 1);
    else if (tab[0][start] == 1)
        printf("%d", *min_element(res.begin(), res.end()) + 1);
    else
        printf("%d", *min_element(res.begin(), res.end()));

    return 0;
}
/*
* Przyklad1:
* Wejscie:
5 0
0 1 1 1 0
1 1 0 1 1
1 0 1 0 0
1 1 1 1 0
1 1 0 0 1
* Wyjscie:
* 8
* Przyklad 2:
* Wejscie:
10 9
0 1 0 1 1 1 1 0 1 1
0 1 1 1 0 0 0 0 0 0
1 1 1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 0 1 1 0
1 1 0 1 0 0 0 0 1 1
0 1 0 1 1 1 1 1 1 1
0 1 0 1 1 1 1 1 0 0
1 1 1 1 1 1 0 1 0 1
1 0 0 1 1 1 0 0 0 1
* Wyjscie:
* ERROR 3
* Przyklad3
* Wejscie:
20 10
0 1 1 0 1 1 1 1 1 1 1 1 1 0 1 1 0 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1
1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 0 0 0 1 1
1 1 1 1 1 0 1 1 0 0 1 1 0 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0 1 1 1 1 1 0 0 1 1 0 1 1
1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 0 0 1 1
1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 0 1 1 1 1 1 1 1 1 1 0 1 1 0 0
0 0 1 1 1 0 1 1 1 1 1 1 1 1 0 1 1 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 0
0 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0 1 1 1 1 1 0 1 0 1 1 1 1
1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1
0 0 1 1 1 1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
1 1 0 1 1 1 1 1 1 1 0 0 0 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 0 1 0 1 1 1 0 0 0 1 0 1
1 1 1 1 1 1 0 1 0 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 0 1 0 1 1 0 0 1
1 1 1 0 1 1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
* Wyjscie:
* 57
*/