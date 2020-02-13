#include <iostream>
#include <cstdio>
#include "unistd.h"

using namespace std;

struct City
{
    int gasStation
    int distance;
};

int main() {
    char* line = new char[100000000];
    read(0, line, 100000000);

    long long citiesNumber = 0, fuel = 0, maxFuel = 0, tmp;
    int iter = 0;

    while (*line >= 48)
    {
        citiesNumber = (citiesNumber << 3) + (citiesNumber << 1) + *line - '0';
        line++;
    }
    line++;

    City cities[citiesNumber];

    int index;
    int i = 0;

    for (; i < citiesNumber; ++i)
    {
        while (*line >= 48)
        {
            cities[i].gasStation = (cities[i].gasStation << 3) + (cities[i].gasStation << 1) + *line - '0';
            line++;
        }
        line++;

        while (*line >= 48)
        {
            cities[i].distance = (cities[i].distance << 3) + (cities[i].distance << 1) + *line - '0';
            line++;
        }
        line++;

        fuel = fuel + cities[i].gasStation - cities[i].distance;
        if (fuel < maxFuel)
        {
            maxFuel = fuel;
            index = i + 1;
        }
    }

    if (index >= citiesNumber)
    {
        index = 0;
    }

    maxFuel = 0;
    fuel = 0;
    i = index;

    while (true)
    {
        fuel = fuel + cities[i].gasStation - cities[i].distance;

        if (fuel > maxFuel)
        {
            maxFuel = fuel;
        }
        i++;

        if (i >= citiesNumber)
        {
            i = 0;
        }

        if (i == index)
        {
            break;
        }
    }

    printf("%i %lli", index, maxFuel);
}