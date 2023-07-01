#include <stdio.h>

unsigned sumDigitsNum(int number)
{
    unsigned sumDigits = 0;
    while (number)
    {
        sumDigits += number % 10;
        number /= 10;
    }

    return sumDigits;
}

unsigned sumArrayDigits(const int *arr, size_t n)
{
    unsigned sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += sumDigitsNum(*(arr + i));
    }

    return sum;
}

int main()
{
    int arr[] = {12, 34, 5, 70};

    unsigned sumOfDigits;
    sumOfDigits = sumArrayDigits(arr, 4);

    printf("%d\n", sumOfDigits);

    return 0;
}