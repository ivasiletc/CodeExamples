#include <unistd.h>
#include <cstdio>

using namespace std;

int main()
{
    int previousNumber = 0, currentNumber = 0;
    int tmpLength = 1, currentLength = 1, maxLength = 1;
    long long currentSum = 0, maxSum = 0;
    bool isIncreased = true;

    char* input = new char[100000000];
    read(0, input, 100000000);
    int i = 0;

    //get values from input
    while (input[i] >= 48 && input[i] <= 57)
    {
        currentNumber = (currentNumber << 3) + (currentNumber << 1) + input[i] - 48;
        i++;
    }
    i++;
    currentSum += currentNumber;
    previousNumber = currentNumber;
    currentNumber = 0;

    //get values from input
    while (input[i] != '\0') {
        while (input[i] >= 48 && input[i] <= 57)
        {
            currentNumber = (currentNumber << 3) + (currentNumber << 1) + input[i] - 48;
            i++;
        }
        i++;

        //Main part
        if (currentNumber > previousNumber)
        {
            if (isIncreased) {
                currentLength++;
                currentSum += currentNumber;
            }
            else {
                isIncreased = true;
                if (currentLength > maxLength)
                {
                    maxLength = currentLength;
                    maxSum = currentSum;
                }
                currentLength = 1 + tmpLength;
                currentSum = previousNumber * tmpLength + currentNumber;
            }
            tmpLength = 1;
        }
        else if (currentNumber < previousNumber)
        {
            if (!isIncreased)
            {
                currentLength++;
                currentSum += currentNumber;
            }
            else
            {
                isIncreased = false;
                if (currentLength > maxLength)
                {
                    maxLength = currentLength;
                    maxSum = currentSum;
                }
                currentLength = 1 + tmpLength;
                currentSum = previousNumber * tmpLength + currentNumber;
            }
            tmpLength = 1;
        }
        else
        {
            currentLength++;
            tmpLength++;
            currentSum += currentNumber;
        }
        previousNumber = currentNumber;
        currentNumber = 0;
    }
    if (currentLength > maxLength)
    {
        maxLength = currentLength;
        maxSum = currentSum;
    }
    printf("%i %lli", maxLength, maxSum);
}
