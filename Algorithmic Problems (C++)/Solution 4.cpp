#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

//To run on windows uncomment this line:
//#define getchar_unlocked getchar

using namespace std;

int getNum() 
{
    int i = 0;
    bool negative = false;
    int c = getchar_unlocked();

    if (c == '-') 
    { 
        negative = true;
        c = getchar_unlocked();
    }

    while (c >= 48 && c <= 57) 
    { 
        i = (i << 3) + (i << 1) + c - 48;
        c = getchar_unlocked();
    }

    if (!negative)
    {
        return i; 
    }
    else
    {
        return -i; 
    }
}

struct Place 
{
    int owner = -1;
    vector <int> neighbours;
};

int main() {
    int n = getNum();

    int  cityInd[n];
    for (int i = 0; i < n; i++)cityInd[i] = -1;

    int tmp1 = getNum();
    int tmp2 = getNum();
    Place placesA[n];
    Place placesB[n];

    while (tmp1 != -1 && tmp2 != -1) 
    {
        placesA[tmp1].neighbours.push_back(tmp2);
        placesA[tmp2].neighbours.push_back(tmp1);
        placesB[tmp1].neighbours.push_back(tmp2);
        placesB[tmp2].neighbours.push_back(tmp1);
        tmp1 = getNum();
        tmp2 = getNum();
    }

    int k = getNum();
    int tmp3;
    for (int i = 0; i < k; i++) 
    {
        tmp3 = getNum();
        placesA[tmp3].owner = i;
        placesB[tmp3].owner = i;
        cityInd[tmp3] = i;
    }

    bool isOk = false;
    map<int, map<int, int> > mapA;
    map<int, map<int, int> > mapB;
    
    int minIndex, maxIndex, maxValue;
    bool statA, statB;
    
    while (!isOk) 
    {
        mapA.clear();
        mapB.clear();
        isOk = true;

        for (int i = 0; i < n; i++) 
        {
            if (cityInd[i] == -1) 
            {
                isOk = false;
                if (placesA[i].neighbours.size() == 0) 
                {
                    cityInd[i] = i;
                }
                
                if (placesB[i].neighbours.size() == 0) 
                {
                    cityInd[i] = i;
                }
                
                for (int c = 0; c < placesA[i].neighbours.size(); c++) 
                {
                    if (placesA[placesA[i].neighbours[c]].owner != -1) 
                    {
                        mapA[i][placesA[placesA[i].neighbours[c]].owner]++;
                    }
                }
                
                for (int c = 0; c < placesB[i].neighbours.size(); c++) 
                {
                    if (placesB[placesB[i].neighbours[c]].owner != -1) 
                    {
                        mapB[i][placesB[placesB[i].neighbours[c]].owner]++;
                    }
                }
            }
        }

        //Option A
        for (std::map<int, std::map<int, int> >::iterator it = mapA.begin(); it != mapA.end(); it++) 
        {
            maxValue = 9999999;
            maxIndex = -1;
            for (std::map<int, int>::iterator it1 = it->second.begin(); it1 != it->second.end(); it1++) 
            {

                if (it1->second < maxValue) 
                {
                    maxValue = it1->second;
                    maxIndex = it1->first;
                    placesA[it->first].owner = it1->first;
                    cityInd[it->first] = it->first;
                }
                else if (it1->second == maxValue) 
                {
                    if (it1->first > maxIndex) 
                    {
                        placesA[it->first].owner = it1->first;
                        cityInd[it->first] = it->first;
                        maxIndex = it1->first;
                    }
                }
            }
        }
        
        //Option B
        for (std::map<int, std::map<int, int> >::iterator it = mapB.begin(); it != mapB.end(); it++) 
        {
            maxValue = 1;
            minIndex = 9999999;
            for (std::map<int, int>::iterator it1 = it->second.begin(); it1 != it->second.end(); it1++) 
            {
                if (it1->second > maxValue) 
                {
                    maxValue = it1->second;
                    minIndex = it1->first;
                    placesB[it->first].owner = it1->first;
                    cityInd[it->first] = it->first;
                }
                else if (it1->second == maxValue) 
                {
                    if (it1->first < minIndex) 
                    {
                        placesB[it->first].owner = it1->first;
                        cityInd[it->first] = it->first;
                        minIndex = it1->first;
                    }
                }
            }
        }
    }
    
    map<int, int> resultA;
    map<int, int> resultB;
    
    for (int i = 0; i < n; i++) 
    {
        resultA[placesA[i].owner]++;
        resultB[placesB[i].owner]++;
    }
    
    for (int i = 0; i < k; i++) 
    {
        cout << resultA[i] << " " << resultB[i] << endl;
    }

    return 0;
}
