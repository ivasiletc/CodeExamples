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

    int row = 0;
    int subMatrix = 0;

    while (line[index] > 32) 
    {
        row = (row << 3) + (row << 1) + line[index] - 48;
        index++;
    }
    index++;
    while (line[index] > 32) 
    {
        subMatrix = (subMatrix << 3) + (subMatrix << 1) + line[index] - 48;
        index++;
    }
    index++;
    bool isNegative;

    int** matrix = new int* [row + 1];
    for (int i = 0; i < row + 1; i++)
    {
        matrix[i] = new int[row + 1];
    }
    
    for (int i = 1; i < row + 1; ++i) 
    {
        for (int j = 1; j < row + 1; ++j) 
        {
            isNegative = false;
            if (line[index] == 10) 
            {
                index++;
            }
            while (line[index] > 32) 
            {
                if (line[index] == '-') 
                {
                    isNegative = true;
                    index++;
                    tmp = (tmp << 3) + (tmp << 1) + line[index] - 48;
                }
                else
                {
                    tmp = (tmp << 3) + (tmp << 1) + line[index] - 48;
                }
                index++;

            }

            if (isNegative == true) 
            {
                tmp = ~tmp + 1;
            }
            index++;

            matrix[i][j] = tmp + matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
            tmp = 0;
        }
    }

    //Helper matrix to save sum of values, to increase the speed on final part of algorhytm
    int** bob = new int* [subMatrix];
    for (int i = 0; i < subMatrix; i++)
    {
        bob[i] = new int[4];
    }
    
    for (int l = 0; l < subMatrix; ++l) 
    {
        for (int i = 0; i < 4; ++i) 
        {

            while (line[index] > 32) 
            {

                tmp = (tmp << 3) + (tmp << 1) + line[index] - 48;
                index++;
            }
            index++;
            bob[l][i] = tmp;
            tmp = 0;
        }
    }

    int totalSum = 0;
    int sum = 0;
    map<int, int> map;
    for (int i = 0; i < subMatrix; i++) 
    {
        sum =
            matrix[bob[i][2] + 1][bob[i][3] + 1] +
            matrix[bob[i][0]][bob[i][1]]         -
            matrix[bob[i][0]][bob[i][3] + 1]     -
            matrix[bob[i][2] + 1][bob[i][1]];
        totalSum += sum;
        map[sum]++;
    }

    int result = 0;
    tmp = 0;

    for (std::map<int, int>::iterator it = map.begin(); it != map.end(); ++it) 
    {
        if (it->second == tmp)
        {
            result++;
        }
        else if (it->second > tmp) 
        {
            result = 1;
            tmp = it->second;
        }
    }
    printf("%i %i %i", map.size(), result, totalSum / subMatrix);

}