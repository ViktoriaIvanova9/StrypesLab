#include <stdio.h>

int sum(int *arr, int n)
{
    int sumNums = 0;

    for (int i = 0; i < n; ++i)
    {
        sumNums += *(arr + i);
    }

    return sumNums;
}

int multiply(int *arr, int n)
{
    int multNums = 1;

    for (int i = 0; i < n; ++i)
    {
        multNums *= *(arr + i);
    }

    return multNums;
}

void arrayEvaluate(int *arr, size_t n, int (*f)(int *, int))
{
    printf("The result of function is: %d\n", f(arr, n));
}

int main()
{
    int arr[] = {1, 2, 4};

    arrayEvaluate(arr, 3, sum);
    arrayEvaluate(arr, 3, multiply);

    return 0;
}