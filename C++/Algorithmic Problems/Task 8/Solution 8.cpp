#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int getNum()
{
    int i = 0;
    int c = getchar_unlocked();

    while (c >= 48 && c <= 57)
    {
        i = (i << 3) + (i << 1) + c - 48;
        c = getchar_unlocked();
    }

    return i;
}

void quickSort(int arr[], int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    if (left < j)
    {
        quickSort(arr, left, j);
    }

    if (i < right)
    {
        quickSort(arr, i, right);
    }
}

int main()
{
    int n = getNum();
    int m = getNum();
    int k = getNum();

    int max;

    int** arrays = new int* [n];
    for (int i = 0; i < n; i++)
    {
        int tmp = getNum();
        arrays[i] = new int[tmp + 1];
        for (int c = 1; c < tmp + 1; c++)
        {
            arrays[i][0] = tmp;
            arrays[i][c] = getNum();
        }
        quickSort(arrays[i], 1, tmp - 1);
    }

    int* todo = new int[k * 2];
    for (int i = 0; i < k * 2; i++)
    {
        todo[i] = getNum();
    }
    vector<int> vec;
    int iter = 0;
    int suma;

    for (int i = 0; i < k; ++i)
    {
        suma = 0;
        for (int i1 = 0; i1 < vec.size(); i1++)
        {
            suma += vec[i1];
        }

        if (suma % 2 == 0)
        {
            for (int j = 1; j < arrays[todo[iter]][0] + 1; j++)
            {
                if (vec.size() < m || arrays[todo[iter]][j] <= max)
                {
                    vec.push_back(arrays[todo[iter]][j]);
                    sort(vec.begin(), vec.end());
                    if (vec.size() > m)
                    {
                        vec.resize(m);
                        max = vec[m - 1];
                    }
                    else
                    {
                        max = vec[vec.size() - 1];
                    }
                }
                else if (arrays[todo[iter]][j] > max)
                {
                    break;
                }
            }
            iter += 2;
        }
        else
        {
            iter++;
            for (int j = 1; j < arrays[todo[iter]][0] + 1; j++)
            {
                if (vec.size() < m || arrays[todo[iter]][j] <= max)
                {
                    vec.push_back(arrays[todo[iter]][j]);
                    sort(vec.begin(), vec.end());
                    if (vec.size() > m)
                    {
                        vec.resize(m);
                        max = vec[m - 1];
                    }
                    else
                    {
                        max = vec[vec.size() - 1];
                    }
                }
                else if (arrays[todo[iter]][j] > max)
                {
                    break;
                }
            }
            iter++;
        }
    }

    suma = 0;
    std::map<int, int>map;

    for (int l = 0; l < m; ++l)
    {
        suma += vec[l];
        map[vec[l]]++;
    }

    printf("%d %d", suma, map.size());
}
