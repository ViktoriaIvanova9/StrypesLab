#include <stdio.h>

unsigned sumArrayDigits(const int *arr, size_t n)
{
    unsigned sum = 0;
    int currentNum;

    for (int i = 0; i < n; ++i)
    {
        currentNum = arr[i];
        while (currentNum)
        {
            sum += (currentNum % 10);
            currentNum /= 10;
        }
    }
    
    return sum;
}

int main()
{
    int arr[] = {12, 34, 5, 70};

    printf("Sum of digits: %d\n", sumArrayDigits(arr, 4));
    return 0;
}