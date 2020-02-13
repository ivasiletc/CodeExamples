#include "iostream"
#include "stdio.h"

using namespace std;

int getNum()
{
    int i = 0;
    int c = getchar_unlocked();
    if (c == EOF) 
    {
        return -1;
    }

    while (c >= 48 && c <= 57) 
    {
        i = (i << 3) + (i << 1) + c - 48;
        c = getchar_unlocked();
    }

    return i;
}

struct Element
{
    int value;
    Element* next;
};

Element* POS;

int main() 
{

    int length = 0;
    int count = getNum();

    POS = new Element();

    POS->value = getNum();
    if (POS->value == -1) 
    {
        printf("-1");
        return 0;
    }

    length++;
    Element* last = POS;
    while (true) 
    {
        Element* num = new Element();
        num->value = getNum();

        if (num->value == -1)
        {
            break;
        }

        last->next = num;
        last = num;
        length++;
    }

    last->next = POS;
    Element* tmp;
    for (int i = 0; i < count; ++i)
    {
        if (POS->value % 2 == 0)
        {
            tmp = POS->next;
            POS->next = POS->next->next;
            for (int c = 0; c < tmp->value; ++c)
            {
                POS = POS->next;
            }
            delete tmp;
            length--;
        }
        else 
        {
            tmp = new Element();
            tmp->value = POS->value - 1;
            tmp->next = POS->next;
            POS->next = tmp;
            for (int j = POS->value; j > 0; --j) 
            {
                POS = POS->next;
            }
            length++;
        }
    }

    for (int c = 0; c < length - 1; ++c)
    {
        printf("%i", POS->value);
        printf(" ");
        POS = POS->next;
    }

    printf("%i", POS->value);
}